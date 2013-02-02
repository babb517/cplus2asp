#ifndef CONSTANT_H
#define CONSTANT_H

#include <string>
#include <vector>

#include "Element.h"

class Sort;
class Context;

/**
 * Representation of a C+ constant (i.e., fluent/action).
 */
class Constant : public Element
{
private:
public:
	/// An enum of the possible kinds of constants the system recognizes.
	enum ConstantType { CONST_UNKNOWN, CONST_ACTION, CONST_ABACTION, CONST_ATTRIBUTE, CONST_DYNAMICAB, CONST_EXOGENOUSACTION, CONST_INERTIALFLUENT, CONST_RIGID, CONST_SDFLUENT, CONST_SIMPLEFLUENT, CONST_STATICAB, CONST_ADDITIVEACTION, CONST_ADDITIVEFLUENT };

	std::vector<Sort*> params; ///< Vector of parameters for a constant, if any, expressed as references to sorts.
	Sort* domain; ///< Reference to the sort that represents the domain of a constant.
	
	enum ConstantType constType; ///< The type of a constant.

	/**
	 * Default constructor. Calls Element constructor and sets attributes to zero/blank/empty.
	 */
	Constant();
	
	/**
	 * Full constructor. Calls full Element constructor, still sets other attributes to zero/blank/empty.
	 * @param _name - The C+ name of this object.
	 * @param _transName - The ASP-compatible name of this object.
	 */
	Constant(std::string const& _name, std::string const& _transName);
	
	/**
	 * Generates the original full name of this element, including full parameter names (if any).
	 * @return A string representation of this element's base name plus a
	 * parenthesized, comma-separated list of the full names of any parameters
	 * (if it has any).
	 */
	virtual std::string fullName();
	
	/**
	 * Generates the translated full name of this element, including
	 * translated full parameter names (if any).
	 * @return A string representation of this element's translated base name
	 * plus a parenthesized, comma-separated list of the full names of any 
	 * parameters (if it has any).
	 */
	virtual std::string fullTransName(); 
	
	/**
	 * Generates a human-readable string representation of this object.
	 * @return A string suitable for printing to a console or log.
	 */
	virtual std::string toString();
	
	/**
	 * Function that generates a string representation of a Constant's type.
	 * @param _constType - The constant type instance to transform.
	 * @return A string representation of the constant type.
	 */
	static std::string constTypeToString(enum ConstantType _constType);
	
	/**
	 * Function that maps a string representation of a Constant's type to the type in question.
	 * @param _constType - A string representation of the constant's type.
	 * @return The type represented by the string (or CONST_UNKNOWN).
	 */
	static enum ConstantType stringToConstType(char const* _constType);

	/**
	 * Determines if the specified constant type is an action.
	 * @return True if the constant type is of the action archetype, false otherwise.
	 */
	static bool isActionType(enum ConstantType _constType);

	/**
	 * Determines if the specified constant type is an abnormality constant.
	 * @return True if the constant type is of the abnormality archetype, false otherwise.
	 */
	static bool isAbnormalityType(enum ConstantType _constType);

	/**
	 * Determines if the specified constant type is an fluent.
	 * @return True if the constant type is of the action fluent, false otherwise.
	 */
	static bool isFluentType(enum ConstantType _constType);


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

	/**
	 * Destructor. Clears params and sets domain to NULL, but does not deallocate associated memory.
	 */
	virtual ~Constant();
};

#endif // CONSTANT_H
