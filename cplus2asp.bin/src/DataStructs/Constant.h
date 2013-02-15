#ifndef CONSTANT_H
#define CONSTANT_H

#include <string>
#include <vector>
#include <iostream>

#include "utilities.h"
#include "Element.h"
#include "Context.h"
#include "types.h"

class ElementCounter;
class Sort;
class Attribute;

/**
 * Representation of a C+ constant (i.e., fluent/action).
 */
class Constant : public Element
{
public:
	/// An enum of the possible kinds of constants the system recognizes.
	enum ConstantType { CONST_UNKNOWN, CONST_ACTION, CONST_ABACTION, CONST_ABFLUENT, CONST_ATTRIBUTE, CONST_DYNAMICAB, CONST_EXOGENOUSACTION, CONST_INERTIALFLUENT, CONST_RIGID, CONST_SDFLUENT, CONST_SIMPLEFLUENT, CONST_STATICAB, CONST_ADDITIVEACTION, CONST_ADDITIVEFLUENT };

private:
	ConstSortList mParams; ///< Vector of parameters for a constant, if any, expressed as references to sorts.
	Sort const* mDomain; ///< Reference to the sort that represents the domain of a constant.
	enum ConstantType mConstType; ///< The type of a constant.
	
	std::string mFullName;				///< The full name of the constant, with parameters.
	std::string mFullTransName;			///< The full ASP-compatible name of the constant, with parameters.

public:

	/**
	 * Full constructor for regular constants.
	 * @param name - The C+ name of this constant.
	 * @param domain - The sort which this constant ranges over.
	 * @param type - The type of constant we are representing.
	 * @param params - A list of parameters for the constant. NULL indicates that there are no parameters.
	 */
	Constant(std::string const& name, Sort const* domain, ConstantType type, ConstSortList const* params = NULL);

	/**
	 * Full constructor for abnormal constants.
	 * @param name - The C+ name of this constant.
	 * @param type - The type of constant we are representing.
	 * @param params - A list of parameters for the constant. NULL indicates that there are no parameters.
	 */
	Constant(std::string const& name, ConstantType type, ConstSortList const* params = NULL);
	

	inline virtual std::string const& fullName() const 				{ return mFullName; }
	inline virtual std::string const& fullTransName() const			{ return mFullTransName; }
	virtual std::string toString() const;
	virtual bool isNumeric() const;
	virtual bool isBoolean() const;
	virtual bool isStarred() const;

	/// Returns the domain that this constant ranges over (NULL if the constant is an abnormal constant.)
	inline Sort const* domain() const								{ return mDomain; }

	/// Sets the domain that this constant ranges over.
	inline void domain(Sort const* domain)							{ mDomain = domain; }


	/// Gets the specific type that this constant is.
	inline ConstantType constType() const 							{ return mConstType; }

	/// Sets the specific type that this constant is.
	inline void constType(ConstantType type)						{ mConstType = type; }

	/// Gets a string representing the constant type.
	inline std::string constTypeStr() const							{ return constTypeToString(constType()); }

	/// Gets the arity of the constant.
	inline size_t arity() const										{ return mParams.size(); }

	/// Determines if the constant is one of the abnormality types.
	inline bool isAbnormal() const 									{ return isAbnormalityType(constType()); }

	/// Determines if the constant is an fluent type.
	inline bool isFluent() const 									{ return isFluentType(constType()); }

	/// Determines if the constant is an action type.
	inline bool isAction() const 									{ return isActionType(constType()); }

	/// Determines if the constant is an additive type.
	inline bool isAdditive() const 									{ return isAdditiveType(constType()); }

	/// Determines if the constant is rigid.
	inline bool isRigid() const										{ return constType() == CONST_RIGID; }

	/// Gets the beginning of the constant's parameter list.
	inline ConstSortList::const_iterator beginParams() const		{ return mParams.begin(); }

	/// Gets the end of the constant's parameter list.
	inline ConstSortList::const_iterator endParams() const			{ return mParams.end(); }

	/// Gets the ith parameter.
	inline Sort const* param(size_t i) const						{ return mParams[i]; }

	/// Examines the constant's information and determines if the
	/// constant is actually the internal 'contribution' constant.
	bool isContribConstant() const;

	/**
	 * Gets the full names of all parameters associated with the constant.
	 * @param out The vector to place the names within.
	 */
	void getParamFullNames(NameList& out) const;

	/**
	 * Outputs an ASP friendly declarable form for the constant.
	 * @param out The stream to output the translation to.
	 * @param outClauses A list to append to clauses to which dynamically bind variables.
	 * @param runningCount A running counter to ensure uniqueness of variables amongst multiple translations. passing NULL will ensure local uniqueness only.
	 * @param matchMap The map (if any) to attempt the match the first arguments to.
	 * While the first argument sorts match the arguments will share the same variables
	 * as those within the map. Once the arguments begin to differ this map will be ignored
	 * and new variables will be generated.
	 * @param outMap The map (if any) to append the resulting ordered mappings to.
	 * @return True if matchMap matched the prefix for the arguments completely.
	 */
	bool translate(
			std::ostream& out,
			ClauseList& outClauses,
			ElementCounter* runningCount = NULL,
			std::vector<std::pair<Sort const*, std::string> >* matchMap = NULL,
			std::vector<std::pair<Sort const*, std::string> >* outMap = NULL
	) const;

	/**
	 * Creates a duplicate constant bound as an attribute.
	 * @param parent The parent sort to bind the new attribute to.
	 * @return A copy of this object as an Attribute.
	 */
	Attribute* makeAttribute(Constant const* parent) const;


	/**
	 * Destructor.
	 */
	inline virtual ~Constant() { /* Intentionally Left Blank */ }

	/***********************************************************************/
	/* Static Helpers */
	/***********************************************************************/


	/**
	 * Function that generates a string representation of a Constant's type.
	 * @param _constType - The constant type instance to transform.
	 * @return A string representation of the constant type.
	 */
	static std::string constTypeToString(ConstantType _constType);
	
	/**
	 * Function that maps a string representation of a Constant's type to the type in question.
	 * @param _constType - A string representation of the constant's type.
	 * @return The type represented by the string (or CONST_UNKNOWN).
	 */
	static ConstantType stringToConstType(char const* _constType);

	/**
	 * Determines if the specified constant type is an action.
	 * @return True if the constant type is of the action archetype, false otherwise.
	 */
	static bool isActionType(ConstantType _constType);

	/**
	 * Determines if the specified constant type is an abnormality constant.
	 * @return True if the constant type is of the abnormality archetype, false otherwise.
	 */
	static bool isAbnormalityType(ConstantType _constType);

	/**
	 * Determines if the specified constant type is an fluent.
	 * @param _constType The type to check.
	 * @param includeRigid Whether to count a 'rigid' constant as a fluent.
	 * @return True if the constant type is a fluent, false otherwise.
	 */
	static bool isFluentType(ConstantType _constType, bool includeRigid = true);

	/**
	 * Determines if the specified constant type is an additive constant.
	 * @return True if the constant type is a additive constant, false otherwise.
	 */
	static bool isAdditiveType(ConstantType _constType);

	/**
	 * Outputs the string that a constant should use as a prefix given the constant.
	 * @param constType The type of constant we're working with.
	 * @return A prefix to the atom's name, usually "h(eql(".
	 */
	static std::string translatePrefix(ConstantType constType);

	/**
	 * Outputs the string a constant should use as a postfix given its type.
	 * @param constType The type of constant we're working with.
	 * @param context The translation context the constant appears within.
	 * @return A postfix to the atom's name.
	 */
	static std::string translatePostfix(ConstantType constType, Context const& context);

};

#endif // CONSTANT_H
