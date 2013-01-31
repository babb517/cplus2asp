#ifndef PARSER_TYPES_H
#define PARSER_TYPES_H

/**
 * @file parser_types.h
 * @brief Data structures used to hold intermediate data for the parser.
 * @details Declarations of data structures used by the parser to contain
 * intermediate data while it processes grammar rules.
 */

#include <sstream>
#include <string>
#include <list>
#include <utility>

#include "Constant.h"
#include "Context.h"
#include "Sort.h"
#include "Variable.h"

class Object;

typedef std::list<std::string> ClauseList;						///< A list containing 0 or more clauses which should be conjoined to the body of a formula.
typedef std::pair<std::string,Context::IPart> Statement;		///< A simple tuple representing a statement occuring within an specified part of incremental module.
typedef std::list<Statement> StmtList;							///< A list containing 0 or more statements which should be added to the program and their corresponding IPARTs.


/**
 * Container class to hold information from the constant_binder grammar rule.
 */
class PT_constant_binder_t
{
public:
	Constant::ConstantType constType; ///< The binding constant type (e.g., CONST_EXOGENOUSACTION).
	Sort* domain; ///< The domain of the constant.
	Constant* attributeOf; ///< If the constant binder is an attribute, this is a reference to the connecting action constant.
	
	/**
	 * Default constructor. Sets all dynamic attributes to NULL.
	 */
	PT_constant_binder_t();
	
	/**
	 * Destructor. Just resets everything to NULL.
	 */
	~PT_constant_binder_t();
};

/**
 * General parent of all self-contained, self-translating parse tree elements.
 * Empty except for the virtual translate function.
 */
class ParseElement
{
public:
	/// The possible types of a ParseElement instance.
	enum ParseElementType { PELEM_PELEM, PELEM_UOP, PELEM_BOP, PELEM_QUANT, PELEM_BASELIKE, PELEM_CONSTLIKE, PELEM_OBJLIKE, PELEM_VARLIKE };

private:

	std::string queryTimeStamp; ///< A timestamp used for query formulas.
	bool parens; ///< If true, the expression should be wrapped in parentheses
	enum ParseElementType elemType; ///< The type of the parse element instance.

public:

	/// A global count of how many extra clauses have been created for any element.
	/// Used to help create dynamic variable names that won't clash with each other.
	/// Incremented when an extra clause is created, but not when it is added to anything.
	static size_t extraClauseCount;
	
	/**
	 * Default constructor. Sets elemType.
	 * @param elemType The type that the element is.
	 */
	ParseElement(ParseElementType elemType = PELEM_PELEM);
	

	/**
	 * Method that generates a translated string representation of the element with 
	 * preceeding @ if a symbol is understood as a lua function call.
	 * @param[out] extraClauses - A list to append the extra clauses which should be conjoined to the formula.
	 * @param[out] extraStmts - A list to append the extra statements which should be added to the program.
	 * @param context -  The formula context to be used for translation.
	 * @return A string containing the translated form of the element.
	 */
	virtual std::string translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context) = 0;

	/**
	 * This is true if the element (or any of its pre/postOp nodes) were
	 * identified as action constant(s).
	 * @return True if the element or any elements "beneath" it are identified action constants, false otherwise.
	 */
	virtual bool hasActions() = 0;
	
	/**
	 * This is true if the element (or any of its pre/postOp nodes) were
	 * identified as fluent constant(s).
	 * @return True if the element or any elements "beneath" it are identified fluent constants, false otherwise.
	 */
	virtual bool hasFluents() = 0;

	/**
	 * This is true if the element (or any of its children) have been identified as static abnormalities.
	 * @return True if the element or any elements "beneath" it are static abnormality constants, false otherwise.
	 */
	virtual bool hasStaticAbnormalities() = 0;

	/**
	 * This is true if the element (or any of its children) have been identified as dynamic abnormalities.
	 * @return True if the element or any elements "beneath" it are dynamic abnormality constants, false otherwise.
	 */
	virtual bool hasDynamicAbnormalities() = 0;

	/**
	 * Determines if this parse element has any constants which aren't declared as 'rigid'
	 * @return True if there are any non-rigid constants in this element or any of its children.
	 */
	virtual bool hasNonRigidConstants() = 0;

	/**
	 * Determines if this parse element has any constants which are declared as 'rigid'
	 * @return True if there are any rigid constants in this element or any of its children.
	 */
	virtual bool hasRigidElements() = 0;

	/**
	 * Determines if the element contains a single atom (or a unary expression w/ a single atom), which would be suitable for the head of a rule.
	 * @return True if the element contains a single atom suitable for the head of a rule.
	 */
	virtual bool isSingleAtom() = 0;

	/**
	 * Determines if the element contains no (real) constants. (i.e. only "true" and/or "false").
	 * @return True if the only constants contained in the formula are "true" and "false".
	 */
	virtual bool isTrivial() = 0;

	/**
	 * Determines if the element contains any calls to LUA.
	 * @return True if the element or any of its children is a LUA call.
	 */
	virtual bool hasLuaCalls() = 0;

	/**
	 * Stub method that returns a blank string (for pointer-wise compatibility 
	 * with BaseLikeElement's real version of this method).
	 */
	virtual std::string fullName() = 0;
	
	inline ParseElementType getType() { return elemType; }

	inline std::string const& getQueryTimeStamp() { return queryTimeStamp; }

	/**
	 * Special helper method used for translating query formulas.
	 * @param[out] extraClauses - A list to append the extra clauses which should be conjoined to the formula.
	 * @param[out] extraStmts - A list to append the extra statements which should be added to the program.
	 * @return The translated element using the time stamp previously attached to the element.
	 */
	inline std::string translateQuery(ClauseList& extraClauses, StmtList& extraStmts)
		{ return translate(extraClauses, extraStmts, Context(Context::POS_QUERY, Context::VOLATILE, queryTimeStamp)); }

	/**
	 * Attaches a timestamp to a query formula which will be used during translation.
	 * @param timestamp The new timestamp to use during translation.
	 */
	inline void  setQueryTimeStamp(std::string const& timestamp) { queryTimeStamp = timestamp; }

	/**
	 * Sets whether the expression is wrapped in parentheses.
	 * @param parens Whether the expression should be wrapped in parentheses.
	 */
	inline void setParens(bool parens) { this->parens = parens; }

	/**
	 * This is true if the element (or any of its children) have been identified as static OR dynamic abnormalities.
	 * @return True if the element or any elements "beneath" it are abnormality constants, false otherwise.
	 */
	inline bool hasAbnormalities() { return hasStaticAbnormalities() || hasDynamicAbnormalities(); }

	/**
	 * Returns true if the element (or any of its children) are constants.
	 * @return True if the element, or any elements "beneach" it, are constants, false otherwise.
	 */
	inline bool hasConstants() { return hasActions() || hasFluents() || hasAbnormalities(); }

	/**
	 * Gets a new variable whose name is unique within the rule we're translating.
	 * @return The name of the new variable.
	 */
	static inline std::string getNewVar() { return "X_Value_" + extraClauseCount++; }

	/**
	 * Destructor. Empty.
	 */
	virtual ~ParseElement();
protected:

	/**
	 * Determines if the element has parentheses around it.
	 * @return True if the element has parentheses around it, false otherwise.
	 */
	inline bool hasParens() { return parens; }

	/**
	 * Helper to translate that intelligently handles the value of parenBefore.
	 * @return A blank string if parenBefore is false, "(" if it's true.
	 */
	inline std::string translateBeforeParen() { return (parens) ? "(" : ""; }

	/**
	 * Helper to translate that intelligently handles the value of parenAfter.
	 * @return A blank string if parenAfter is false, ")" if it's true.
	 */
	inline std::string translateAfterParen() { return (parens) ? ")" : ""; }
};

/**
 * Child of ParseElement that represents a unary operator and the associated elements it operates on.
 */
class SimpleUnaryOperator : public ParseElement
{
public:
	/// Enum of the kinds of unary operators this class can be.
	enum UnaryOperatorType { UOP_UNKNOWN, UOP_NOT, UOP_NEGATIVE, UOP_ABS, UOP_EXOGENOUS, UOP_INERTIAL, UOP_RIGID };
	enum UnaryOperatorType opType; ///< Which kind of operator an instance represents.
	
	ParseElement* postOp; ///< What comes after (and is affected by) the operator.
	
	/**
	 * Default constructor. Performs basic initialization.
	 */
	SimpleUnaryOperator();
	
	// inherited stuffs
	virtual std::string translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context);
	virtual bool hasActions();
	virtual bool hasFluents();
	virtual bool hasStaticAbnormalities();
	virtual bool hasDynamicAbnormalities();
	virtual bool hasNonRigidConstants();
	virtual bool hasRigidElements();
	virtual bool isSingleAtom();
	virtual bool isTrivial();
	virtual bool hasLuaCalls();
	virtual std::string fullName();
	
	/**
	 * Destructor. Deallocates postOp.
	 */
	virtual ~SimpleUnaryOperator();

protected:
	/**
	 * Simple helper function. Converts the provided operator to a string representation.
	 * @param op The operator to convert
	 * @return A string corresponding to that operator.
	 */
	static std::string translateOpType(UnaryOperatorType op);
};

/**
 * Child of ParseElement that represents a binary operator and the associated elements it operates on.
 */
class SimpleBinaryOperator : public ParseElement
{
public:
	/// Enum of the kinds of unary operators this class can be.
	enum BinaryOperatorType { BOP_UNKNOWN, BOP_PLUS, BOP_MINUS, BOP_TIMES, BOP_DIVIDE, BOP_MOD, BOP_AND, BOP_OR, BOP_EQUIV, BOP_IMPL, BOP_EQ, BOP_NEQ, BOP_DBL_EQ, BOP_LTHAN, BOP_GTHAN, BOP_LTHAN_EQ, BOP_GTHAN_EQ };
	enum BinaryOperatorType opType; ///< Which kind of operator an instance represents.
	
	ParseElement* preOp; ///< The bit(s) bound to the operator that come before it.
	ParseElement* postOp; ///< The bit(s) bound to the operator that come after it.
	
	/**
	 * Default constructor. Performs basic initialization.
	 */
	SimpleBinaryOperator();
	

	// inherted stuffs
	virtual std::string translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context);
	virtual bool hasActions();
	virtual bool hasFluents();
	virtual bool hasStaticAbnormalities();
	virtual bool hasDynamicAbnormalities();
	virtual bool hasNonRigidConstants();
	virtual bool hasRigidElements();
	virtual bool isSingleAtom();
	virtual bool isTrivial();
	virtual bool hasLuaCalls();
	virtual std::string fullName();
	


	/**
	 * Destructor. Deallocates preOp and postOp.
	 */
	virtual ~SimpleBinaryOperator();

protected:

	/**
	 * Simple helper function. Converts the provided operator to a string representation.
	 * @param op The operator to convert
	 * @return A string corresponding to that operator.
	 */
	static std::string translateOpType(BinaryOperatorType op);

	/**
	 * A helper method which translates an arithmetic expression of the form F @ G, where @ is an arithmetic operator.
	 * @param[out] out - The output stream to write the translation to.
	 * @param[out] extraClauses - A list to append the extra clauses which should be conjoined to the formula.
	 * @param[out] extraStmts - A list to append the extra statements which should be added to the program.
	 * @param context - The translation context the expression occurs within.
	 * @return out.
	 */
	std::ostream& translateArithExpr(std::ostream& out, ClauseList& extraClauses, StmtList& extraStmts, Context const& context);
};

/**
 * Child of ParseElement that represents a big quantifier group and its associated subformula.
 */
class BigQuantifiers : public ParseElement
{
public:
	/// Which kinds of "quantifiers" can be present.
	enum QuantifierType { QUANT_UNKNOWN, QUANT_CONJ, QUANT_DISJ };

	/// A list of the quantifiers present in this grouping, both the kinds
	/// of quantifiers and references to the quantifying variables.
	std::list<std::pair<enum QuantifierType, ParseElement*>* > quants;
	
	ParseElement* postOp; ///< The bit(s) affected by the quantifier(s).
	
	/**
	 * Default constructor. Performs basic initialization.
	 */
	BigQuantifiers();
	

	// inherited stuffs
	virtual std::string translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context);
	virtual bool hasActions();
	virtual bool hasFluents();
	virtual bool hasStaticAbnormalities();
	virtual bool hasDynamicAbnormalities();
	virtual bool hasNonRigidConstants();
	virtual bool hasRigidElements();
	virtual bool isSingleAtom();
	virtual bool isTrivial();
	virtual bool hasLuaCalls();
	virtual std::string fullName();
	
	/**
	 * Destructor. Deallocates postOp and the contents of quants.
	 */
	virtual ~BigQuantifiers();
};

/**
 * Child of ParseElement that acts as a base class for parsed elements like constants and objects.
 */
class BaseLikeElement : public ParseElement
{
public:
	std::string baseName; ///< The original name of the element, sans parameters.
	std::vector<ParseElement*> params; ///< References to representations of the element's parameters, if any.
	
	/**
	 * Default constructor. Performs basic initialization.
	 */
	BaseLikeElement(ParseElementType elemType = PELEM_BASELIKE);
	
	// inherited stuffs
	virtual std::string translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context);
	virtual bool hasActions();
	virtual bool hasFluents();
	virtual bool hasStaticAbnormalities();
	virtual bool hasDynamicAbnormalities();
	virtual bool hasNonRigidConstants();
	virtual bool hasRigidElements();
	virtual bool isSingleAtom();
	virtual bool isTrivial();
	virtual bool hasLuaCalls();
	virtual std::string fullName();

	/**
	 * Internal helper to translate, creates a list of translated params.
	 * @param[out] extraClauses - A list to append the extra clauses which should be conjoined to the formula.
	 * @param[out] extraStmts - A list to append the extra statements which should be added to the program.
	 * @param context The context used for translation.
	 * @return A parentheses-surrounded, comma-separated list of translated
	 * params, or a blank string if params is empty.
	 */
	virtual std::string translateParams(ClauseList& extraClauses, StmtList& extraStmts, Context const& context);
	
	/**
	 * Destructor. Deallocates contents of params.
	 */
	virtual ~BaseLikeElement();
};

/**
 * Child of BaseLikeElement that represents a base element with the behavior of a constant.
 */
class ConstantLikeElement : public BaseLikeElement
{
public:
	/// Reference to the Constant object it's believed this element is an instance of.
	Constant* constRef;
	
	/**
	 * Default constructor. Performs basic initialization.
	 */
	ConstantLikeElement();


	// inherited stuffs
	virtual std::string translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context);
	virtual bool hasActions();
	virtual bool hasFluents();
	virtual bool hasStaticAbnormalities();
	virtual bool hasDynamicAbnormalities();
	virtual bool hasNonRigidConstants();
	virtual bool hasRigidElements();
	virtual bool isSingleAtom();
	virtual bool isTrivial();
	virtual bool hasLuaCalls();

	/**
	 * Determines if the constant has a boolean domain or not.
	 * @return True if the constant is boolean, false otherwise.
	 */
	inline bool isBoolean() const
		{ return constRef && constRef->domain && constRef->domain->isBooleanSort(); }

	/**
	 * Destructor. Does not deallocate anything.
	 */
	virtual ~ConstantLikeElement();

protected:

	/**
	 * Outputs the string this constant uses as a prefix for the atom.
	 * @return A prefix to the atom's name, usually "h(eql(".
	 */
	inline std::string translatePrefix()
		{ return (this->constRef) ? Constant::translatePrefix(this->constRef->constType) : ""; }

	/**
	 * Outputs the string used as a postfix. This is usually ",<value>),<timestamp>)".
	 * @param context - The context to be used for translation.
	 * @return A postfix to the atom's name.
	 */
	std::string translatePostfix(Context const& context)
		{ return (this->constRef) ? Constant::translatePostfix(this->constRef->constType, context) : ""; }

	/**
	 * Helper translator method to handle translating the constant as an atom.
	 * @param[out] out - The output stream to write the translation to.
	 * @param[out] extraClauses - A list to append the extra clauses which should be conjoined to the formula.
	 * @param[out] extraStmts - A list to append the extra statements which should be added to the program.
	 * preceeding @ if a symbol is understood as a lua function call.
	 * @param context -  The formula context to be used for translation.
	 * Uses constant translating conventions for the base name.
	 * @return A string containing the translated form of the element.
	 */
	virtual std::ostream& translateAsConstant(std::ostream& out, ClauseList& extraClauses, StmtList& extraStmts, Context const& context);

	/**
	 * Helper translator method to handle translating the constant as a variable.
	 * @param[out] out - The output stream to write the translation to.
	 * @param[out] extraClauses - A list to append the extra clauses which should be conjoined to the formula.
	 * @param[out] extraStmts - A list to append the extra statements which should be added to the program.
	 * preceeding @ if a symbol is understood as a lua function call.
	 * @param context -  The formula context to be used for translation.
	 * Uses constant translating conventions for the base name.
	 * @return A string containing the translated form of the element.
	 */
	virtual std::ostream& translateAsVariable(std::ostream& out, ClauseList& extraClauses, StmtList& extraStmts, Context const& context);

};

/**
 * Child of BaseLikeElement that represents a base element with the behavior of an object.
 */
class ObjectLikeElement : public BaseLikeElement
{
public:
	/// Reference to the Object instance it's believed this element is an instance of.
	Object* objRef;
	
	/**
	 * Default constructor. Performs basic initialization.
	 */
	ObjectLikeElement();
	

	// inherited stuffs
	virtual std::string translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context);
	virtual bool hasActions();
	virtual bool hasFluents();
	virtual bool hasStaticAbnormalities();
	virtual bool hasDynamicAbnormalities();
	virtual bool hasNonRigidConstants();
	virtual bool hasRigidElements();
	virtual bool isSingleAtom();
	virtual bool isTrivial();
	virtual bool hasLuaCalls();

	/**
	 * Destructor. Does not deallocate anything.
	 */
	virtual ~ObjectLikeElement();
};

/**
 * Child of BaseLikeElement that represents a base element with the behavior of a variable.
 */
class VariableLikeElement : public BaseLikeElement
{
public:
	/// Reference to the Variable object it's believed this element is an instance of.
	Variable* varRef;
	
	/**
	 * Default constructor. Performs basic initialization.
	 */
	VariableLikeElement();
	
	/**
	 * Checks if a variable-like element represents a constant of some kind.
	 * @return True if the element is a constant variable, false otherwise.
	 */
	bool isConstantVariable();
	
	// inherited stuffs
	virtual std::string translate(ClauseList& extraClauses, StmtList& extraStmts, Context const& context);
	virtual bool hasActions();
	virtual bool hasFluents();
	virtual bool hasStaticAbnormalities();
	virtual bool hasDynamicAbnormalities();
	virtual bool hasNonRigidConstants();
	virtual bool hasRigidElements();
	virtual bool isSingleAtom();
	virtual bool isTrivial();
	virtual bool hasLuaCalls();

	/**
	 * Determines if the variable has a boolean domain or not.
	 * @return True if the variable is boolean, false otherwise.
	 */
	inline bool isBoolean() const
		{ return varRef && varRef->sortRef && varRef->sortRef->isBooleanSort(); }

	/**
	 * Destructor. Does not deallocate anything.
	 */
	virtual ~VariableLikeElement();

protected:

	/**
	 * Helper translator method to handle translating the variable as an atom.
	 * @param[out] out - The output stream to write the translation to.
	 * @param[out] extraClauses - A list to append the extra clauses which should be conjoined to the formula.
	 * @param[out] extraStmts - A list to append the extra statements which should be added to the program.
	 * preceeding @ if a symbol is understood as a lua function call.
	 * @param context -  The formula context to be used for translation.
	 * Uses constant translating conventions for the base name.
	 * @return A string containing the translated form of the element.
	 */
	virtual std::ostream& translateAsConstant(std::ostream& out, ClauseList& extraClauses, StmtList& extraStmts, Context const& context);

	/**
	 * Helper translator method to handle translating the variable as a variable.
	 * @param[out] out - The output stream to write the translation to.
	 * @param[out] extraClauses - A list to append the extra clauses which should be conjoined to the formula.
	 * @param[out] extraStmts - A list to append the extra statements which should be added to the program.
	 * preceeding @ if a symbol is understood as a lua function call.
	 * @param context -  The formula context to be used for translation.
	 * Uses constant translating conventions for the base name.
	 * @return A string containing the translated form of the element.
	 */
	virtual std::ostream& translateAsVariable(std::ostream& out, ClauseList& extraClauses, StmtList& extraStmts, Context const& context);
};

#endif // PARSER_TYPES_H
