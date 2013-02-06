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

// Translates a query
std::ostream& ParseElement::translateQuery(std::ostream& out) {
	// We want to bind the variables and clauses
	Context localContext =
		Context(
			Context::POS_QUERY,
			Context::BASE,
			queryTimeStamp,
			NULL,
			NULL
	);

	return Translator::bindAndTranslate(out, this, localContext, false);
}

/* SimpleUnaryOperator methods. */

// Constructor.
SimpleUnaryOperator::SimpleUnaryOperator() : ParseElement(PELEM_UOP)
{
	opType = UOP_UNKNOWN;
	postOp = NULL;
}

// Translator method.
std::ostream& SimpleUnaryOperator::translate(std::ostream& out, Context& context)
{
	Context localContext;

	out << translateBeforeParen();

	// Sanity check: is the argument to the operator not NULL?
	if(!postOp) {
		// TODO: Throw warning
		return out;
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
				return out;
			}

			// output the constant with value false
			localContext = context.mkValue(Context::FALSE_STR);
			postOp->translate(out, localContext);


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

			localContext = context.mkValue(Context::FALSE_STR);
			varPostOp->translate(out, localContext);

		} else {

			// Just a normal negation.

			// Sanity check, make sure that we're not in the head of a rule before capturing clauses../
			// Make sure we capture the clauses locally...
			if (context.getPos() != Context::POS_HEAD) {

				out << translateOpType(opType) + "(";
				Translator::bindAndTranslate(out, postOp, context, false);
				out << ")";

			} else {

				// crap, we are. Just pass em up and hope for the best.
				// TODO

				localContext = context.mkNegated();
				out << translateOpType(opType) << "(";
				postOp->translate(out, localContext);
				out << ")";

			}
		}
		break;


	case UOP_NEGATIVE: // Numeric negative.
	case UOP_ABS: 	// Absolute value.

		localContext = context.mkPos(Context::POS_ARITHEXPR);
		out << translateOpType(opType);
		postOp->translate(out, localContext);
		break;

	case UOP_EXOGENOUS: // Exogenous declaration.
	case UOP_INERTIAL: // Inertial declaration.
	case UOP_RIGID: // Rigid declaration.

		// All three "operators" do the same thing, it's just a matter of what name to use.
		if(postOp->getType() == PELEM_CONSTLIKE)
		{
			localContext = context.mkPos(Context::POS_INTERNAL);
			out << translateOpType(opType) << "(";
			postOp->translate(out, localContext);
			out << ")";
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
		out << translateOpType(opType);
		postOp->translate(out, context);
		break;
	}

	out << translateAfterParen();
	return out;
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
std::ostream& SimpleBinaryOperator::translate(std::ostream& out, Context& context)
{
	Context localContext;
	std::ostringstream tmp;

	out << translateBeforeParen();

	if (!preOp && !postOp) {
		// TODO: Throw error
		return out;
	} else if(!preOp) {
		// If just preOp is NULL, pretend there's just postOp and translate it.
		postOp->translate(out, context);
	} else if(!postOp) {
		// If just postOp is NULL, pretend there's just preOp and translate it.
		preOp->translate(out, context);
	}
	else
	{ 	// Then, perform different translations based on what the operator is.
		// Lack of breaks is intentional.
		switch(opType) {
		case BOP_EQ:

			if (preOp->getType() == PELEM_CONSTLIKE && !postOp->hasConstants()) {

				// special case, direct assignment to a constant...
				// just translate the constant with the appropriate value.
				localContext = context.mkPos(Context::POS_TERM);
				postOp->translate(tmp, localContext);
				std::string tmpstr = tmp.str();
				localContext = context.mkValue(tmpstr);
				preOp->translate(out, localContext);
				break;
			}
			/* no break */

		case BOP_PLUS:
		case BOP_MINUS:
		case BOP_TIMES:
		case BOP_DIVIDE:
		case BOP_MOD:
		case BOP_NEQ:
		case BOP_LTHAN:
		case BOP_GTHAN:
		case BOP_LTHAN_EQ:
		case BOP_GTHAN_EQ:
			// arithmetic expressions...
			if (context.getPos() == Context::POS_ARITHEXPR || context.getPos() == Context::POS_TERM) {
				// Already inside an arithmetic expression.
				// pass all the variables up to the highest arith-expr level.
				preOp->translate(out, context);
				out << translateOpType(opType);
				postOp->translate(out, context);

			} else {

				// Entering an arithmetic expression
				// Bind all of the local variables as we may need existential quantifiers.
				localContext = localContext = context.mkPos(Context::POS_ARITHEXPR);
				Translator::bindAndTranslate(out, this, localContext, true);

			}
			break;

		default:
			// Logical operations...
			// If this isn't conjunction, then we want to capture local clauses for each term.
			// otherwise we'll just pass the clauses upward.

			if (opType != BOP_AND && context.getPos() != Context::POS_HEAD) {

				// preop
				Translator::bindAndTranslate(out, preOp, context, false);

				// operand
				out << translateOpType(opType);

				// postOp
				Translator::bindAndTranslate(out, postOp, context, false);

			} else {
				// conjunction (hopefully), just pass the clauses upward.
				preOp->translate(out, context);
				out << translateOpType(opType);
				postOp->translate(out, context);
			}
			break;
		}
	}

	out << translateAfterParen();
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
		opStr = " == ";
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
std::ostream& BigQuantifiers::translate(std::ostream& out, Context& context)
{

	// The local context is used for variable list.
	// They _shouldn't_ be declaring free variables and clauses.
	Context localContext = context.mkPos(Context::POS_TERM).mkBindVars(NULL).mkBindClauses(NULL);
	out << translateBeforeParen();

	// First, create a wrapping quantifier statement for each quantifier.
	std::list<std::pair<enum QuantifierType, ParseElement*>* >::iterator lIter;


	for(lIter = quants.begin(); lIter != quants.end(); ++lIter)
	{

		switch((*lIter)->first)
		{
		case QUANT_CONJ:
			out << "![";
			if((*lIter)->second)
				(*lIter)->second->translate(out, localContext);
			out << "]:(";
			break;
		case QUANT_DISJ:
			out << "?[";
			if((*lIter)->second)
				(*lIter)->second->translate(out, localContext);
			out << "]:(";
			break;
		default:
			// Unknown, just open a parenthesis.
			out << "(";
			break;
		}
		// Instead of having a bunch of linked lists lying around, we'll just push on a marker string for every nested quantifier.
	}

	// Next, translate whatever subformula was in the big quantifiers.
	if(postOp)
		Translator::bindAndTranslate(out, postOp, context, false);

	// Nested parens
	for(lIter = quants.begin(); lIter != quants.end(); ++lIter)
	{
		out << ")";
	}

	out << translateAfterParen();

	return out;
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
std::ostream& BaseLikeElement::translate(std::ostream& out, Context& context)
{

	out << translateBeforeParen()
		<< Translator::sanitizeObjectName(baseName);
	this->translateParams(out, context);
	out << translateAfterParen();
	return out;
}

// Translator helper method for params.
std::ostream& BaseLikeElement::translateParams(std::ostream& out, Context& context)
{
	Context localContext = context.mkPos(Context::POS_TERM);

	if(!params.empty())
	{
		out <<  "(";
		for(std::vector<ParseElement*>::iterator vIter = params.begin(); vIter != params.end(); ++vIter)
		{	
			if(vIter != params.begin())
			{
				out << ",";
			}
			if(*vIter)
			{
				(*vIter)->translate(out, localContext);
			}
		}
		out << ")";
	}
	return out;
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
std::ostream& ConstantLikeElement::translate(std::ostream& out, Context& context)
{
	// This tries it's best to output a wrapped atom (i.e. h(eql(<name>(<args>),<value>),<timestep>)).
	// If, for one reason or another, the constant's type isn't available, it'll wing it producing a bare atom <name>(<args>).
	switch (context.getPos()) {
	case Context::POS_INTERNAL:
		// Used for internal sorts and whatnot, just return the bare name.
		out << (constRef ? constRef->transName : Translator::sanitizeConstantName(baseName));
		translateParams(out, context);
		break;
	case Context::POS_HEAD:
	case Context::POS_BODY:
	case Context::POS_QUERY:
		translateAsConstant(out, context);
		break;
	case Context::POS_TERM:
	case Context::POS_ARITHEXPR:
		translateAsVariable(out, context);
		break;
	}

	return out;
}

// Translator helper
std::ostream& ConstantLikeElement::translateAsConstant(std::ostream& out, Context& context) {
	// We are in a logical formula, translate it as an atom
	out <<	translateBeforeParen()
				<< translatePrefix()
				<< (constRef ? constRef->transName : Translator::sanitizeConstantName(baseName));
	translateParams(out, context);
	out << translatePostfix(context)
				<< translateAfterParen();
	return out;
}

// Translator helper
std::ostream& ConstantLikeElement::translateAsVariable(std::ostream& out, Context& context) {
	Context localContext;
	std::ostringstream tmp;
	// We are in a term or arithmetic expression, translate it as a temporary variable.
	if (constRef && !Constant::isAbnormalityType(constRef->constType))
	{
		// The variable that holds the intermediate value (and register it!).
		std::string var = getNewVar();
		context.addFreeVariable(var);

		// add the appropriate extra clause
		localContext = context.mkPos(Context::POS_BODY).mkValue(var);
		translate(tmp, localContext);
		context.addExtraClause(tmp.str());

		if (context.getPos() == Context::POS_ARITHEXPR
				&& constRef->domain
				&& constRef->domain->fullName().find("*") != std::string::npos)
		{
			// ensure that the value isn't 'none'.
			context.addExtraClause(var + " != none");
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
std::ostream& ObjectLikeElement::translate(std::ostream& out, Context& context)
{
	out << translateBeforeParen();

	if(objRef)
	{	// Use the canonical translated object name if it's available.
		if(objRef->isLua) out << "#spatom{@";//need to make f2lp pass this through to ASP
		out << objRef->transName;
		if(objRef->isLua) {
				if (context.getPos() != Context::POS_ARITHEXPR
						&& context.getPos() != Context::POS_TERM)
					out << " == 1";
				out << "}";
		}
	}
	else
	{	// Otherwise, just wing it with this instance's base name.
		out << Translator::sanitizeObjectName(baseName);
	}

	translateParams(out, context);

	out << translateAfterParen();
	return out;
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
std::ostream& VariableLikeElement::translate(std::ostream& out, Context& context)
{

	switch (context.getPos()) {

	case Context::POS_HEAD:
	case Context::POS_BODY:
	case Context::POS_QUERY:
		// This occurs within the scope of a formula, we need to translate it as a constant.
		translateAsConstant(out, context);
		break;

	case Context::POS_TERM:
	case Context::POS_ARITHEXPR:
	case Context::POS_INTERNAL:
		// Occurs as a term or within an arithmetic expression, translate as a variable.
		translateAsVariable(out, context);
		break;
	}

	return out;
}

std::ostream& VariableLikeElement::translateAsVariable(std::ostream& out, Context& context) {
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
std::ostream& VariableLikeElement::translateAsConstant(std::ostream& out, Context& context)
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

