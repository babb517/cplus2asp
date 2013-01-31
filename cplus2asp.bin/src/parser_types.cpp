#include <sstream>
#include <string>
#include <list>
#include <utility>

#include "Sort.h"
#include "Variable.h"
#include "utilities.h"
#include "Context.h"
#include "parser_types.h"
#include "Translator.h"
#include "parser.h"

extern std::ostringstream ltsyyossErr;

// Default constructor. Initializes attributes to NULL.
PT_constant_binder_t::PT_constant_binder_t()
{
	constType = Constant::CONST_UNKNOWN;
	domain = NULL;
	attributeOf = NULL;
}

// Destructor. Resets all to NULL.
PT_constant_binder_t::~PT_constant_binder_t()
{
	constType = Constant::CONST_UNKNOWN;
	domain = NULL;
	attributeOf = NULL;
}

/* ParseElement methods. */

size_t ParseElement::extraClauseCount = 0;

// Constructor.
ParseElement::ParseElement(ParseElementType elemType)
{
	this->elemType = elemType;
	parens = false;
	queryTimeStamp = "UNKNOWN";
}

// Destructor.
ParseElement::~ParseElement()
{
	// Intentionally empty.
}

/* SimpleUnaryOperator methods. */

// Constructor.
SimpleUnaryOperator::SimpleUnaryOperator() : ParseElement(PELEM_UOP)
{
	opType = UOP_UNKNOWN;
	postOp = NULL;
}

// Translator method.
std::string SimpleUnaryOperator::translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context)
{
	std::ostringstream ossStrMaker;
	ClauseList localClauses;

	ossStrMaker << translateBeforeParen();

	// Sanity check: is the argument to the operator not NULL?
	if(!postOp) {
		// TODO: Throw warning
		return "";
	}

	// Then, perform different translations based on what the operator is.
	switch(opType)
	{
	case UOP_NOT: // Logical negation (including logical "-").

		// Negation works differently for bare booleans, check for them.
		if(postOp->getType() == PELEM_CONSTLIKE && !postOp->hasAbnormalities()) {

			// some validation, make sure it's boolean
			if (!((ConstantLikeElement*)postOp)->isBoolean()) {
				// Not a boolean constant, but still used in bare "-c" style, this doesn't make sense.
				ltsyystartParseError();
				ltsyyossErr << "Can't use \"-\" or \"not\" to negate non-Boolean constant \""
						<< postOp->fullName()
						<< "\" without specifying which value is being negated. Try something like \""
						<< postOp->fullName() << "=some_value\".";
				ltsyyreportError();
				return "";
			}

			// output the constant with value false
			ossStrMaker << postOp->translate(extraClauses, extraStmts, context.mkValue("false"));
		} else if(postOp->getType() == PELEM_VARLIKE && ((VariableLikeElement*)postOp)->isConstantVariable()) {
			// This variable actually stands for a constant of some kind, treat this as "not constant".
			// Throw up a warning, as using "-V" with V being a constant is not guaranteed to work.
			VariableLikeElement* varPostOp = (VariableLikeElement*)postOp;
			ltsyystartWarning();
			ltsyyossErr << "Using negation on variable \""
					<< varPostOp->fullName()
					<< "\" representing constant type \""
					<< varPostOp->varRef->sortRef->fullName()
					<< "\" is not a good idea, and is almost guaranteed to not work as expected unless you know exactly what you're doing.";
			ltsyyreportWarning();
			ossStrMaker << varPostOp->translate(extraClauses, extraStmts, context.mkValue("false"));
		} else {

			// Just a normal negation.


			// Sanity check, make sure that we're not in the head of a rule before capturing clauses../
			// Make sure we capture the clauses locally...
			if (context.getPos() != Context::POS_HEAD) {
				ossStrMaker << translateOpType(opType)
						<< "(" << postOp->translate(localClauses, extraStmts, context.mkNegated());
				Translator::outputClauses(ossStrMaker, localClauses, true);
				ossStrMaker << ")";
			} else {
				// crap, we are. Just pass em up.
				ossStrMaker << translateOpType(opType)
						<< "(" << postOp->translate(extraClauses, extraStmts, context.mkNegated()) << ")";
			}
		}
		break;


	case UOP_NEGATIVE: // Numeric negative.
	case UOP_ABS: 	// Absolute value.

		ossStrMaker << translateOpType(opType) << postOp->translate(extraClauses, extraStmts, context.mkPos(Context::POS_ARITHEXPR));
		break;

	case UOP_EXOGENOUS: // Exogenous declaration.
	case UOP_INERTIAL: // Inertial declaration.
	case UOP_RIGID: // Rigid declaration.

		// All three "operators" do the same thing, it's just a matter of what name to use.
		if(postOp->getType() == PELEM_CONSTLIKE)
		{
			ossStrMaker << translateOpType(opType)
				<< "(" << postOp->translate(extraClauses, extraStmts, context.mkPos(Context::POS_INTERNAL)) << ")";
		}
		else
		{
			ltsyystartParseError();
			ltsyyossErr << "Declaring \"" << postOp->fullName() << "\" as " << translateOpType(opType) << " is not supported.";
			ltsyyreportError();
		}
		break;
	default:
		// Unknown operator, just do a blind translation.
		ossStrMaker << translateOpType(opType);
		ossStrMaker << postOp->translate(extraClauses, extraStmts, context);
		break;
	}

	ossStrMaker << translateAfterParen();
	return ossStrMaker.str();
}

// Returns true if this or any pre/postOp elements are action constants.
bool SimpleUnaryOperator::hasActions()
{	// True if postOp contains an action.
	bool retVal = false;
	if(postOp)
	{
		retVal = postOp->hasActions();
	}
	return retVal;
}

// Returns true if this or any pre/postOp elements are fluent constants.
bool SimpleUnaryOperator::hasFluents()
{	// True if postOp contains an fluent.
	bool retVal = false;
	if(postOp)
	{
		retVal = postOp->hasFluents();
	}
	return retVal;
}

// Returns true if this or any sub expression is a static abnormality constant.
bool SimpleUnaryOperator::hasStaticAbnormalities()
{
	if (postOp) return postOp->hasStaticAbnormalities();
	else return false;
}

// Returns true if this or any sub expression is a dynamic abnormality constant.
bool SimpleUnaryOperator::hasDynamicAbnormalities()
{
	if (postOp) return postOp->hasDynamicAbnormalities();
	else return false;
}

// Returns true if this or any sub expression is a rigid constant
bool SimpleUnaryOperator::hasRigidElements()
{
	// For our purposes, we also check against the special declarative operators...
	if (postOp) {
		return opType == UOP_EXOGENOUS
			|| opType == UOP_INERTIAL
			|| opType == UOP_RIGID
			|| postOp->hasRigidElements();
	}
	else return false;
}

// Returns true if this or any sub expression is a  non-rigid constant
bool SimpleUnaryOperator::hasNonRigidConstants()
{
	return postOp
			&& !opType == UOP_EXOGENOUS
			&& !opType == UOP_INERTIAL
			&& !opType == UOP_RIGID
			&& postOp->hasNonRigidConstants();
}

// Returns true if this expression corresponds to a single atom.
bool SimpleUnaryOperator::isSingleAtom() {
	// Two cases:
	// the expression is '-p' or 'not p', as this is shorthand for p=false.
	// or this is a declarative law such as exogenous p. where p is a constant.
	// Alternatively, in the event we are working with a declarative law it may be one of UOP_EXOGENOUS, UOP_INERTIAL, UOP_RIGID

	// sanity
	if (!postOp) return false;

	// case 1
	if (opType == UOP_NOT || opType == UOP_EXOGENOUS) {
		return (postOp->getType() == ParseElement::PELEM_CONSTLIKE && ((ConstantLikeElement*)postOp)->constRef->domain->isBooleanSort())
				|| (postOp->getType() == ParseElement::PELEM_VARLIKE && ((VariableLikeElement*)postOp)->varRef->sortRef->isBooleanSort());
	}

	// case 2
	if (opType == UOP_INERTIAL || opType == UOP_RIGID) {
		return (postOp->getType() == ParseElement::PELEM_CONSTLIKE
						|| (postOp->getType() == ParseElement::PELEM_VARLIKE));
	}

	return false;
}

// returns true if this expression contains only "true" and "false" constants
bool SimpleUnaryOperator::isTrivial() {
	return !postOp || postOp->isTrivial();
}

// returns true if this expression contains one or more LUA calls.
bool SimpleUnaryOperator::hasLuaCalls() {
	return postOp && postOp->hasLuaCalls();
}


// Returns an original string representation of this operator and its operand.
std::string SimpleUnaryOperator::fullName()
{
	std::string retVal = "";
	if(postOp)
	{
		// Create a CCalc-compatible representation of the operator first.
		std::string opStr = "";
		switch(opType)
		{
		case UOP_NOT:
			opStr = "not ";
			break;
		case UOP_NEGATIVE:
			opStr = "-";
			break;
		case UOP_ABS:
			opStr = "abs ";
			break;
		case UOP_EXOGENOUS:
			opStr = "exogenous ";
			break;
		case UOP_INERTIAL:
			opStr = "inertial ";
			break;
		case UOP_RIGID:
			opStr = "rigid ";
			break;
		default:
			// Unknown operator, this should never happen
			opStr = " UNKNOWN ";
			break;
		}
		retVal += opStr;
		retVal += postOp->fullName();
	}
	return retVal;
}

std::string SimpleUnaryOperator::translateOpType(UnaryOperatorType op) {
	switch(op)
	{
	case UOP_NOT:
		return "not ";
	case UOP_NEGATIVE:
		return "-";
	case UOP_ABS:
		return "#abs";
	case UOP_EXOGENOUS:
		return "exogenous";
	case UOP_INERTIAL:
		return "inertial";
	case UOP_RIGID:
		return "rigid";
	default:
		return " UNKNOWN ";
	}
}

// Destructor.
SimpleUnaryOperator::~SimpleUnaryOperator()
{
	if(postOp) delete postOp;
}

/* SimpleBinaryOperator methods. */

// Constructor.
SimpleBinaryOperator::SimpleBinaryOperator() : ParseElement(PELEM_BOP)
{
	opType = BOP_UNKNOWN;
	preOp = NULL;
	postOp = NULL;
}



// Translator method.
std::string SimpleBinaryOperator::translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context)
{
	std::ostringstream retVal;
	ClauseList localClauses;

	retVal << translateBeforeParen();

	if (!preOp && !postOp) {
		// TODO: Throw error
		return "";
	} else if(!preOp) {
		// If just preOp is NULL, pretend there's just postOp and translate it.
		retVal << postOp->translate(extraClauses, extraStmts, context);
	} else if(!postOp) {
		// If just postOp is NULL, pretend there's just preOp and translate it.
		retVal << preOp->translate(extraClauses, extraStmts, context);
	}
	else
	{ 	// Then, perform different translations based on what the operator is.
		// Lack of breaks is intentional.
		switch(opType) {
		case BOP_PLUS:
		case BOP_MINUS:
		case BOP_TIMES:
		case BOP_DIVIDE:
		case BOP_MOD:
		case BOP_EQ:
		case BOP_NEQ:
		case BOP_LTHAN:
		case BOP_GTHAN:
		case BOP_LTHAN_EQ:
		case BOP_GTHAN_EQ:
			// arithmetic expressions...
			translateArithExpr(retVal,extraClauses, extraStmts, context);
			break;

		default:
			// Logical operations...
			// If this isn't conjunction, then we want to capture local clauses for each term.
			// otherwise we'll just pass the clauses upward.

			if (opType != BOP_AND && context.getPos() != Context::POS_HEAD) {
				std::string tmp;

				// preOp
				tmp = preOp->translate(localClauses, extraStmts, context);
				if (localClauses.size() > 0) {
					retVal << "(" << tmp;
					Translator::outputClauses(retVal,localClauses,true);
					retVal << ")";
					localClauses.clear();
				} else {
					retVal << tmp;
				}

				// operand
				retVal << translateOpType(opType);

				// postOp
				tmp = postOp->translate(localClauses, extraStmts, context);
				if (localClauses.size() > 0) {
					retVal << "(" << tmp;
					Translator::outputClauses(retVal,localClauses,true);
					retVal << ")";
				} else {
					retVal << tmp;
				}

			} else {
				// not conjunction, just pass the clauses upward.
				retVal << preOp->translate(extraClauses, extraStmts, context)
						<< translateOpType(opType)
						<< postOp->translate(extraClauses, extraStmts, context);
			}
			break;
		}
	}

	retVal << translateAfterParen();
	return retVal.str();
}

// Internal helper to translate method, translates preOp @ postOp, where @ is an arithmetic expression.
std::ostream& SimpleBinaryOperator::translateArithExpr(std::ostream& out, ClauseList& extraClauses, StmtList& extraStmts, Context const& context) {
	ClauseList localClauses;

	if (opType == BOP_EQ
			&& preOp->getType() == PELEM_CONSTLIKE
			&& ( !postOp->hasConstants())) {

		// special case, direct assignment to a constant...
		// just translate the constant with the appropriate value.
		out <<
				preOp->translate(extraClauses, extraStmts,
						context.mkValue(postOp->translate(extraClauses, extraStmts, context.mkPos(Context::POS_TERM))));

	} else if ((opType == BOP_DBL_EQ || opType == BOP_EQ)
			&& (( preOp->getType() == PELEM_CONSTLIKE && !postOp->hasConstants())
					|| (postOp->getType() == PELEM_CONSTLIKE && !preOp->hasConstants()))) {

		// not a direct assignment.
		// one value is involved.
		// here we use only one variable.

		std::string var = getNewVar();
		Context tmpContext = context.mkValue(var);

		// translate the operation
		out << "?[" << var << "]:("
				<< preOp->translate(localClauses, extraStmts, tmpContext)
				<< translateOpType(opType)
				<< postOp->translate(localClauses, extraStmts, tmpContext);

		// append the extra clauses
		Translator::outputClauses(out, localClauses, true);

		out << ")";

	} else if (preOp->getType() == PELEM_CONSTLIKE || postOp->getType() == PELEM_CONSTLIKE) {
		// not a direct assignment.
		// multiple values involved
		// this (p=q) is expessed as ?[X_p,X_q](X_p=X_q & p(X_p) & q(X_q)).

		std::string varPre = getNewVar();
		std::string varPost = getNewVar();

		// translate the operation
		out << "?[" << varPre << ", " << varPost << "]:("
				<< preOp->translate(localClauses, extraStmts, context.mkValue(varPre))
				<< translateOpType(opType)
				<< postOp->translate(localClauses, extraStmts, context.mkValue(varPost));

		// append the extra clauses
		Translator::outputClauses(out, localClauses, true);

		out << ")";

	} else {
		// direct comparison of variables or objects
		// translate as X @ Y
		out
			<< preOp->translate(extraClauses, extraStmts, context.mkPos(Context::POS_ARITHEXPR))
			<< translateOpType(opType)
			<< postOp->translate(extraClauses, extraStmts, context.mkPos(Context::POS_ARITHEXPR));
	}

	return out;
}

// Returns true if this or any pre/postOp elements are action constants.
bool SimpleBinaryOperator::hasActions()
{	// True if preOp or postOp contains an action.
	return (preOp && preOp->hasActions()) || (postOp && postOp->hasActions());
}

// Returns true if this or any pre/postOp elements are fluent constants.
bool SimpleBinaryOperator::hasFluents()
{	// True if preOp or postOp contains a fluent.
	return preOp->hasFluents() || postOp->hasFluents();
}

// Returns true if this or any sub expression is a static abnormality constant.
bool SimpleBinaryOperator::hasStaticAbnormalities()
{
	return (postOp && postOp->hasStaticAbnormalities()) || (preOp && preOp->hasStaticAbnormalities());
}

// Returns true if this or any sub expression is a dynamic abnormality constant.
bool SimpleBinaryOperator::hasDynamicAbnormalities()
{
	return (postOp && postOp->hasDynamicAbnormalities()) || (preOp && preOp->hasDynamicAbnormalities());
}

// Returns true if this or any sub expression is a rigid constant
bool SimpleBinaryOperator::hasRigidElements()
{
	return (postOp && postOp->hasRigidElements()) || (preOp && preOp->hasRigidElements());
}

// Returns true if this or any sub expression is a  non-rigid constant
bool SimpleBinaryOperator::hasNonRigidConstants()
{
	return (postOp && postOp->hasNonRigidConstants()) || (preOp && preOp->hasNonRigidConstants());
}

// Returns true if this expression corresponds to a single atom.
bool SimpleBinaryOperator::isSingleAtom() {
	// The only time when this is true is if one of the children is NULL and the other is a single atom OR if it's of the form c=v.
	return (!preOp && postOp && postOp->isSingleAtom()) || (!postOp && preOp && preOp->isSingleAtom())
			|| (preOp && postOp && opType == BOP_EQ && preOp->getType() == ParseElement::PELEM_CONSTLIKE
					&& !postOp->hasActions() && !postOp->hasFluents());
}

// returns true if this expression contains only "true" and "false" constants
bool SimpleBinaryOperator::isTrivial() {
	return (!preOp || preOp->isTrivial()) && (!postOp || postOp->isTrivial());
}

// returns true if this expression contains one or more LUA calls.
bool SimpleBinaryOperator::hasLuaCalls() {
	return (preOp && preOp->hasLuaCalls()) || (postOp && postOp->hasLuaCalls());
}


// Returns an original string representation of this operator and its operands.
std::string SimpleBinaryOperator::fullName()
{
	std::string retVal = "";
	if(preOp && postOp)
	{
		// Get a string representation of the CCalc operator first.
		std::string opStr = translateOpType(opType);
		retVal += preOp->fullName();
		retVal += opStr;
		retVal += postOp->fullName();
	}
	else if(preOp == NULL)
	{
		retVal += postOp->fullName();
	}
	else if(postOp == NULL)
	{
		retVal += preOp->fullName();
	}
	return retVal;
}

// Destructor.
SimpleBinaryOperator::~SimpleBinaryOperator()
{
	if(preOp)
	{
		delete preOp;
		preOp = NULL;
	}
	if(postOp)
	{
		delete postOp;
		postOp = NULL;
	}
}

// Converts an operatory to a string representation.
std::string SimpleBinaryOperator::translateOpType(BinaryOperatorType op) {
	std::string opStr;
	switch(op)
	{
	case BOP_PLUS:
		opStr = " + ";
		break;
	case BOP_MINUS:
		opStr = " - ";
		break;
	case BOP_TIMES:
		opStr = " * ";
		break;
	case BOP_DIVIDE:
		opStr = " / ";
		break;
	case BOP_MOD:
		opStr = " \\ ";
		break;
	case BOP_AND:
		opStr = " & ";
		break;
	case BOP_OR:
		opStr = " | ";
		break;
	case BOP_EQUIV:
		opStr = " <-> ";
		break;
	case BOP_IMPL:
		opStr = " -> ";
		break;
	case BOP_EQ:
		opStr = " = ";
		break;
	case BOP_NEQ:
		opStr = " != ";
		break;
	case BOP_DBL_EQ:
		opStr = " == ";
		break;
	case BOP_LTHAN:
		opStr = " < ";
		break;
	case BOP_GTHAN:
		opStr = " > ";
		break;
	case BOP_LTHAN_EQ:
		opStr = " <= ";
		break;
	case BOP_GTHAN_EQ:
		opStr = " >= ";
		break;
	default:
		// Unknown, this is a problem...
		opStr = " BAD_OP ";
		break;
	}
	return opStr;
}

/* BigQuantifiers methods. */

// Constructor.
BigQuantifiers::BigQuantifiers() : ParseElement(PELEM_QUANT)
{
	postOp = NULL;
}

// Translator method.
std::string BigQuantifiers::translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context)
{
	std::ostringstream ret;

	// we want to capture all clauses within the quantifiers...
	// these correspond to the clauses created from translating the body (position 0) and the N variables (positions 1..N).
	ClauseList* localClauses = new ClauseList[quants.size()+1];

	int pos = 0;


	Context tmpContext = context.mkPos(Context::POS_TERM);

	ret << translateBeforeParen();

	// First, create a wrapping quantifier statement for each quantifier.
	std::list<std::pair<enum QuantifierType, ParseElement*>* >::iterator lIter;


	for(lIter = quants.begin(); lIter != quants.end(); ++lIter)
	{

		switch((*lIter)->first)
		{
		case QUANT_CONJ:
			ret << "![";
			if((*lIter)->second)
				ret << (*lIter)->second->translate(localClauses[pos], extraStmts, tmpContext);
			ret << "]:(";
			break;
		case QUANT_DISJ:
			ret << "?[";
			if((*lIter)->second)
				ret << (*lIter)->second->translate(localClauses[pos], extraStmts, tmpContext);
			ret << "]:(";
			break;
		default:
			// Unknown, just open a parenthesis.
			ret << "(";
			break;
		}
		// Instead of having a bunch of linked lists lying around, we'll just push on a marker string for every nested quantifier.
	}

	// Next, translate whatever subformula was in the big quantifiers.
	if(postOp)
		ret << postOp->translate(localClauses[0], extraStmts, context);

	// account for extra clauses
	Translator::outputClauses(ret, localClauses[0], true);

	// Finally, close the quantifier statements' open parentheses and handle the local clauses...
	for(size_t i = quants.size(); i > 0; i--) {
		Translator::outputClauses(ret,localClauses[i], true);
		ret << ")";
	}

	ret << translateAfterParen();

	// deallocate the memory we used.
	delete[] localClauses;

	return ret.str();
}

// Returns true if this or any pre/postOp elements are action constants.
bool BigQuantifiers::hasActions()
{	// True if postOp contains an action.
	bool retVal = false;
	if(postOp)
	{
		retVal = postOp->hasActions();
	}
	return retVal;
}

// Returns true if this or any pre/postOp elements are fluent constants.
bool BigQuantifiers::hasFluents()
{	// True if postOp contains an fluent.
	bool retVal = false;
	if(postOp)
	{
		retVal = postOp->hasFluents();
	}
	return retVal;
}

// Returns true if this or any sub expression is a static abnormality constant.
bool BigQuantifiers::hasStaticAbnormalities()
{
	return (postOp && postOp->hasStaticAbnormalities());
}

// Returns true if this or any sub expression is a dynamic abnormality constant.
bool BigQuantifiers::hasDynamicAbnormalities()
{
	return (postOp && postOp->hasDynamicAbnormalities());
}

// Returns true if this or any sub expression is a rigid constant
bool BigQuantifiers::hasRigidElements()
{
	return (postOp && postOp->hasRigidElements());
}

// Returns true if this or any sub expression is a  non-rigid constant
bool BigQuantifiers::hasNonRigidConstants()
{
	return (postOp && postOp->hasNonRigidConstants());
}

// Returns true if this expression corresponds to a single atom.
bool BigQuantifiers::isSingleAtom() {
	// This is always false
	return false;
}

// returns true if this expression contains only "true" and "false" constants
bool BigQuantifiers::isTrivial() {
	return postOp || postOp->isTrivial();
}

// returns true if this expression contains one or more LUA calls.
bool BigQuantifiers::hasLuaCalls() {
	return postOp && postOp->hasLuaCalls();
}


// Returns an original string representation of the quantifiers and what's getting quantified.
std::string BigQuantifiers::fullName()
{
	std::string retVal = "";
	if(postOp && !quants.empty())
	{
		retVal += "[ ";
		std::list<std::pair<enum QuantifierType, ParseElement*>* >::iterator lIter;
		for(lIter = quants.begin(); lIter != quants.end(); ++lIter)
		{
			if((*lIter) && (*lIter)->second)
			{
				switch((*lIter)->first)
				{
				case QUANT_CONJ:
					retVal += "/\\ ";
					break;
				case QUANT_DISJ:
					retVal += "\\/ ";
					break;
				default:
					break;
				}
				retVal += (*lIter)->second->fullName();
			}
		}
		retVal += " | ";
		retVal += postOp->fullName();
		retVal += " ]";
	}
	return retVal;
}

// Destructor.
BigQuantifiers::~BigQuantifiers()
{
	for(std::list<std::pair<enum QuantifierType, ParseElement*>* >::iterator lIter = quants.begin(); lIter != quants.end(); ++lIter)
	{
		if((*lIter)->second)
		{
			delete (*lIter)->second;
		}
		delete (*lIter);
	}
	quants.clear();
	if(postOp)
	{
		delete postOp;
		postOp = NULL;
	}
}

/* BaseLikeElement methods. */

// Constructor.
BaseLikeElement::BaseLikeElement(ParseElementType elemType) : ParseElement(elemType)
{
	baseName = "";
}

// Translator method.
std::string BaseLikeElement::translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context)
{
	std::string retVal = "";
	retVal += translateBeforeParen();
	retVal += Translator::sanitizeObjectName(baseName);
	retVal += this->translateParams(extraClauses, extraStmts, context);
	retVal += translateAfterParen();
	return retVal;
}

// Translator helper method for params.
std::string BaseLikeElement::translateParams(ClauseList& extraClauses, StmtList& extraStmts, Context const& context)
{
	std::string retVal = "";
	Context newContext = context.mkPos(Context::POS_TERM);
	if(!params.empty())
	{
		retVal += "(";
		for(std::vector<ParseElement*>::iterator vIter = params.begin(); vIter != params.end(); ++vIter)
		{	
			if(vIter != params.begin())
			{
				retVal += ",";
			}
			if(*vIter)
			{
				retVal += (*vIter)->translate(extraClauses, extraStmts, newContext);
			}
		}
		retVal += ")";
	}
	return retVal;
}

// Returns true if this or any pre/postOp elements are action constants.
bool BaseLikeElement::hasActions()
{	// The base "x-like" element is never an action.
	return false;
}

// Returns true if this or any pre/postOp elements are fluent constants.
bool BaseLikeElement::hasFluents()
{	// The base "x-like" element is never a fluent.
	return false;
}

// Returns true if this or any sub expression is a static abnormality constant.
bool BaseLikeElement::hasStaticAbnormalities()
{
	return false;
}

// Returns true if this or any sub expression is a dynamic abnormality constant.
bool BaseLikeElement::hasDynamicAbnormalities()
{
	return false;
}

// Returns true if this or any sub expression is a rigid constant
bool BaseLikeElement::hasRigidElements()
{
	return false;
}

// Returns true if this or any sub expression is a  non-rigid constant
bool BaseLikeElement::hasNonRigidConstants()
{
	return false;
}

// Returns true if this expression corresponds to a single atom.
bool BaseLikeElement::isSingleAtom() {
	// This is always false
	return false;
}

// returns true if this expression contains only "true" and "false" constants
bool BaseLikeElement::isTrivial() {
	return true;
}

// returns true if this expression contains one or more LUA calls.
bool BaseLikeElement::hasLuaCalls() {
	return false;
}

// Outputs the original full name of the element, including parameters.
std::string BaseLikeElement::fullName()
{
	std::string retVal = this->baseName;
	if(!params.empty())
	{
		retVal += "(";
	}
	for(std::vector<ParseElement*>::iterator vIter = params.begin(); vIter != params.end(); ++vIter)
	{
		if(*vIter)
		{
			if(vIter != params.begin())
			{
				retVal += ",";
			}
			retVal += (*vIter)->fullName();
		}
	}
	if(!params.empty())
	{
		retVal += ")";
	}
	return retVal;
}

// Destructor.
BaseLikeElement::~BaseLikeElement()
{
	for(std::vector<ParseElement*>::iterator vIter = params.begin(); vIter != params.end(); ++vIter)
	{
		if(*vIter)
		{
			delete *vIter;
		}
	}
	params.clear();
}

/* ConstantLikeElement methods. */

// Constructor.
ConstantLikeElement::ConstantLikeElement() : BaseLikeElement(PELEM_CONSTLIKE)
{
	constRef = NULL;
}

// Translator method.
std::string ConstantLikeElement::translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context)
{
	std::ostringstream ret;
	// This tries it's best to output a wrapped atom (i.e. h(eql(<name>(<args>),<value>),<timestep>)).
	// If, for one reason or another, the constant's type isn't available, it'll wing it producing a bare atom <name>(<args>).
	switch (context.getPos()) {
	case Context::POS_INTERNAL:
			// Used for internal sorts and whatnot, just return the bare name.
			return (constRef ? constRef->transName : Translator::sanitizeConstantName(baseName))
				+ translateParams(extraClauses, extraStmts, context);
			break;
	case Context::POS_HEAD:
	case Context::POS_BODY:
	case Context::POS_QUERY:
		translateAsConstant(ret, extraClauses, extraStmts, context);
		break;
	case Context::POS_TERM:
	case Context::POS_ARITHEXPR:
		translateAsVariable(ret, extraClauses, extraStmts, context);
		break;
	}

	return ret.str();
}

// Translator helper
std::ostream& ConstantLikeElement::translateAsConstant(std::ostream& out, ClauseList& extraClauses, StmtList& extraStmts, Context const& context) {
	// We are in a logical formula, translate it as an atom
	out <<	translateBeforeParen()
				<< translatePrefix()
				<< (constRef ? constRef->transName : Translator::sanitizeConstantName(baseName))
				<< translateParams(extraClauses, extraStmts, context)
				<< translatePostfix(context)
				<< translateAfterParen();
	return out;
}

// Translator helper
std::ostream& ConstantLikeElement::translateAsVariable(std::ostream& out, ClauseList& extraClauses, StmtList& extraStmts, Context const& context) {
	// We are in a term or arithmetic expression, translate it as a temporary variable.
	if (constRef && !Constant::isAbnormalityType(constRef->constType))
	{
		// The variable that holds the intermediate value.
		std::string var = "X_Value_" + utils::to_string(++ParseElement::extraClauseCount);

		// add the appropriate extra clause
		extraClauses.push_back(translate(extraClauses, extraStmts, context.mkValue(var)));

		// TODO: Should this encompass equivalence / equality?
		if (context.getPos() == Context::POS_ARITHEXPR
				&& constRef->domain
				&& constRef->domain->fullName().find("*") != std::string::npos)
		{
			// ensure that the value isn't 'none'.
			extraClauses.push_back(var + " != none");
		}

		// return the variable name
		out << translateBeforeParen() + var + translateAfterParen();
	} else if (!constRef) {
		ltsyystartParseError();
		ltsyyossErr << "An error occurred while translating the constant " + this->fullName() + ". The constant doesn't appear to be properly declared.";
		ltsyyreportError();
	} else {
		// This should never happen, as the syntax to trigger this is prohibited in the parser.
		ltsyystartParseError();
		ltsyyossErr << "An error occurred while translating an abnormality constant " + constRef->name + ". The constant appears to be used as a function.";
		ltsyyreportError();
	}

	return out;
}


// Returns true if this or any pre/postOp elements are action constants.
bool ConstantLikeElement::hasActions()
{	// A Constant-like has an action if it is linked with an actual
	// constant and that constant is any action type.

	return (this->constRef && Constant::isActionType(this->constRef->constType))
		// Special check: even if constRef is NULL, if this element looks
		// like the reserved "contribution" element, then assume it's an action.
		|| (this->baseName == "contribution" && this->params.size() == 2);

}

// Returns true if this or any pre/postOp elements are fluent constants.
bool ConstantLikeElement::hasFluents()
{	// A Constant-like has a fluent if it is linked with an actual
	// constant and that constant is any fluent type.
	return this->constRef && Constant::isFluentType(this->constRef->constType);
}

// Returns true if this or any sub expression is a static abnormality constant.
bool ConstantLikeElement::hasStaticAbnormalities()
{
	return this->constRef && this->constRef->constType == Constant::CONST_STATICAB;
}

// Returns true if this or any sub expression is a dynamic abnormality constant.
bool ConstantLikeElement::hasDynamicAbnormalities()
{
	return this->constRef && this->constRef->constType == Constant::CONST_DYNAMICAB;
}

// Returns true if this or any sub expression is a rigid constant
bool ConstantLikeElement::hasRigidElements()
{
	return !this->constRef || this->constRef->constType == Constant::CONST_RIGID;
}

// Returns true if this or any sub expression is a  non-rigid constant
bool ConstantLikeElement::hasNonRigidConstants()
{
	return this->constRef && this->constRef->constType != Constant::CONST_RIGID;
}

// Returns true if this expression corresponds to a single atom.
bool ConstantLikeElement::isSingleAtom() {
	// This is true if the constant is boolean
	return this->constRef && this->constRef->domain->name == "boolean";
}

// returns true if this expression contains only "true" and "false" constants
bool ConstantLikeElement::isTrivial() {
	// "true" and "false" are actually object like elements, so nothing here
	// satisfies the condition.
	return false;
}

// returns true if this expression contains one or more LUA calls.
bool ConstantLikeElement::hasLuaCalls() {
	// LUA calls are treated as object elements.
	return false;
}



// Destructor.
ConstantLikeElement::~ConstantLikeElement()
{
	constRef = NULL;
}

/* ObjectLikeElement methods. */

// Constructor.
ObjectLikeElement::ObjectLikeElement() : BaseLikeElement(PELEM_OBJLIKE)
{
	objRef = NULL;
}

// Translator method.
std::string ObjectLikeElement::translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context)
{
	std::string retVal = "";
	retVal += translateBeforeParen();

	if(objRef)
	{	// Use the canonical translated object name if it's available.
		if(objRef->isLua) retVal += "#spatom{@";//need to make f2lp pass this through to ASP
		retVal += objRef->transName;
		if(objRef->isLua) {
				if (context.getPos() != Context::POS_ARITHEXPR
						&& context.getPos() != Context::POS_TERM)
					retVal += " == 1";
				retVal += "}";
		}
	}
	else
	{	// Otherwise, just wing it with this instance's base name.
		retVal += Translator::sanitizeObjectName(baseName);
	}

	retVal += this->translateParams(extraClauses, extraStmts, context);

	retVal += translateAfterParen();
	return retVal;
}

// Returns true if this or any pre/postOp elements are action constants.
bool ObjectLikeElement::hasActions()
{	// An Object-like element is never an action.
	return false;
}

// Returns true if this is one of the few reserved fluent constants.
bool ObjectLikeElement::hasFluents()
{	// A Object-like element counts as a fluent if it's "true" or "false".
	return fullName() == "true" || fullName() == "false";
}

// Returns true if this or any sub expression is a static abnormality constant.
bool ObjectLikeElement::hasStaticAbnormalities()
{
	return false;
}

// Returns true if this or any sub expression is a dynamic abnormality constant.
bool ObjectLikeElement::hasDynamicAbnormalities()
{
	return false;
}

// Returns true if this or any sub expression is a rigid constant
bool ObjectLikeElement::hasRigidElements()
{
	return false;
}

// Returns true if this or any sub expression is a  non-rigid constant
bool ObjectLikeElement::hasNonRigidConstants()
{
	return false;
}


// Returns true if this expression corresponds to a single atom.
bool ObjectLikeElement::isSingleAtom() {
	// this is only valid if it's "true" or "false"
	return fullName() == "true" || fullName() == "false";
}

// returns true if this expression contains only "true" and "false" constants
bool ObjectLikeElement::isTrivial() {
	return true;
}

// returns true if this expression contains one or more LUA calls.
bool ObjectLikeElement::hasLuaCalls() {
	return objRef && objRef->isLua;
}

// Destructor.
ObjectLikeElement::~ObjectLikeElement()
{
	objRef = NULL;
}

/* VariableLikeElement methods. */

// Constructor.
VariableLikeElement::VariableLikeElement() : BaseLikeElement(PELEM_VARLIKE)
{
	varRef = NULL;
}

// Checks if the variable-like element is a constant variable.
bool VariableLikeElement::isConstantVariable()
{
	return this->varRef && this->varRef->sortRef && this->varRef->sortRef->isConstantSort();
}

// Translator method. Ignores parameters, as variables shouldn't have any.
std::string VariableLikeElement::translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context)
{
	std::ostringstream ret;

	switch (context.getPos()) {

	case Context::POS_HEAD:
	case Context::POS_BODY:
	case Context::POS_QUERY:
		// This occurs within the scope of a formula, we need to translate it as a constant.
		translateAsConstant(ret, extraClauses, extraStmts, context);
		break;

	case Context::POS_TERM:
	case Context::POS_ARITHEXPR:
	case Context::POS_INTERNAL:
		// Occurs as a term or within an arithmetic expression, translate as a variable.
		translateAsVariable(ret, extraClauses, extraStmts, context);
		break;
	}

	return ret.str();
}

std::ostream& VariableLikeElement::translateAsVariable(std::ostream& out, ClauseList& extraClauses, StmtList& extraStmts, Context const& context) {
	out << translateBeforeParen();
	if(varRef) {
		// Use the canonical translated variable name if it's available.
		out << varRef->transName;
	} else {
		// Otherwise, just wing it with this instance's base name.
		out << Translator::sanitizeVariableName(baseName);
	}
	out << translateAfterParen();

	return out;
}

// Translates the variable as though it were a constant.
std::ostream& VariableLikeElement::translateAsConstant(std::ostream& out, ClauseList& extraClauses, StmtList& extraStmts, Context const& context)
{
	out << translateBeforeParen();

	Constant::ConstantType type = (this->varRef && this->varRef->sortRef) ?
			this->varRef->sortRef->getConstantType()
			: Constant::CONST_UNKNOWN;

	if (type == Constant::CONST_UNKNOWN) {
		ltsyystartWarning();
		ltsyyossErr << "In trying to treat variable \"" << this->fullName() << "\" like a constant, unable to determine the type of the constant. Using default behavior.";
		ltsyyreportWarning();
	}

	// start the predicate
	out << Constant::translatePrefix(type);

	if(this->varRef && this->varRef->sortRef) {
		// Use the canonical translated variable name if it's available.
		out << this->varRef->transName;
	} else {
		// Otherwise, just wing it with this instance's information.
		out << Translator::sanitizeVariableName(this->baseName);
	}

	// finish up the predicate
	out << Constant::translatePostfix(type, context);
	out << translateAfterParen();

	return out;
}

// Returns true if this or any pre/postOp elements are action constants.
bool VariableLikeElement::hasActions()
{	// A Variable-like is an action if it is linked with an actual variable
	// whose sort is any of the "internal" action sorts.
	bool retVal = false;
	if(this->varRef && this->varRef->sortRef)
	{
		retVal = this->varRef->sortRef->isActionSort();
	}
	return retVal;
}

// Returns true if this or any pre/postOp elements are fluent constants.
bool VariableLikeElement::hasFluents()
{	// A Variable-like element counts as a fluent if it is linked to
	// a real Variable that isn't an "action" variable.
	// A broad definition, but necessary for certain laws.
	bool retVal = false;
	if(this->varRef && this->varRef->sortRef)
	{
//		retVal = !this->hasActions();
		retVal = this->varRef->sortRef->isFluentSort();
	}
	return retVal;
}

// Returns true if this or any sub expression is a static abnormality constant.
bool VariableLikeElement::hasStaticAbnormalities()
{
	return false;
}

// Returns true if this or any sub expression is a dynamic abnormality constant.
bool VariableLikeElement::hasDynamicAbnormalities()
{
	return false;
}

// Returns true if this or any sub expression is a rigid constant
bool VariableLikeElement::hasRigidElements()
{
	return false;
}

// Returns true if this or any sub expression is a  non-rigid constant
bool VariableLikeElement::hasNonRigidConstants()
{
	return false;
}

// Returns true if this expression corresponds to a single atom.
bool VariableLikeElement::isSingleAtom() {
	// this is only the case when it's a 'constant' variable of boolean type.
	return isConstantVariable() && this->varRef->sortRef->name == "boolean";
}

// returns true if this expression contains only "true" and "false" constants
bool VariableLikeElement::isTrivial() {
	return true;
}

// returns true if this expression contains one or more LUA calls
bool VariableLikeElement::hasLuaCalls() {
	// LUA calls are treated as object like elements.
	return false;
}

// Destructor.
VariableLikeElement::~VariableLikeElement()
{
	varRef = NULL;
}

