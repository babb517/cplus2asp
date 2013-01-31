#ifndef SORT_H
#define SORT_H

#include <string>
#include <vector>

#include "Constant.h"
#include "Element.h"

class Object;
class Variable;

/**
 * The Sort class defines a C+ sort (i.e., domain of objects used as arguments and values).
 * Each Sort is set up to be aware of its objects and any subsorts it has.
 */
class Sort : public Element
{
public:
	std::vector<Object*> domainObjs; ///< Dynamic array to keep track of the objects specific to this sort.
	std::vector<Sort*> subsorts; ///< Dynamic array to track any subsorts of this sort.
	Variable* sortVar; ///< The default Variable associated with this sort.
	/**
	 * Default constructor. Calls Element's default constructor and initializes variables to blank (or equivalent).
	 */
	Sort();
	
	/**
	 * Full constructor. Calls Element's full constructor, saves the given varName, and initializes the domainObjs and subsorts vectors.
	 * @param _name - The C+ name of the sort.
	 * @param _transName - The ASP-compatible name of the sort.
	 */
	Sort(std::string _name, std::string _transName);
	
	/**
	 * Examines its own name and determines if it is any of the special
	 * "internal" sorts for tracking action constants.
	 * @return True if it is an action sort, false otherwise.
	 */
	inline bool isActionSort() const { return Constant::isActionType(getConstantType()); }
	
	/**
	 * Examines its own name and determines if it is any of the special
	 * "internal" sorts for tracking fluent constants.
	 * @return True if it is a fluent sort, false otherwise.
	 */
	inline bool isFluentSort() const { return Constant::isFluentType(getConstantType()); }

	/**
	 * Examines its own name and determines if it is the special internal
	 * sort used to track static abnormalities.
	 * @return True if it is the static abnormality sort.
	 */
	inline bool isStaticAbnormalitySort() const { return Constant::constTypeToString(Constant::CONST_STATICAB) == name; }

	/**
	 * Examines its own name and determines if it is the special internal
	 * sort used to track dynamic abnormalities.
	 * @return True if it is the dynamic abnormality sort.
	 */
	inline bool isDynamicAbnormalitySort() const { return Constant::constTypeToString(Constant::CONST_DYNAMICAB) == name; }

	/**
	 * Examines its own name and determines if it is the special sort used to
	 * denote boolean values.
	 * @return True if it is the special boolean sort.
	 */
	inline bool isBooleanSort() const { return name == "boolean"; }

	/**
	 * Examines its own name and determines if it is a special internal
	 * sort used to track a type of constant.
	 * @return True if it is a special internal constant sort.
	 */
	inline bool isConstantSort() const { return getConstantType() != Constant::CONST_UNKNOWN; }

	/**
	 * Determines the type of constant that this sort tracks.
	 * Returns Constant::CONST_UNKNOWN if this sort isn't an internal sort
	 * used to track constants.
	 * @return The type of constant the sort tracks or CONST_UNKNOWN.
	 */
	inline Constant::ConstantType getConstantType() const { return Constant::stringToConstType(name.c_str()); }


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
	 * Destructor. Clears domainObjs and subsorts, but does not deallocate memory associated with the pointers in those lists.
	 */
	virtual ~Sort();
};

#endif // SORT_H
