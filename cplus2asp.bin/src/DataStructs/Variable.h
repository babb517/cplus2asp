#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

#include "Element.h"
class Sort;


/**
 * Represents a C+ variable, an element that can stand for any value of a certain sort.
 */
class Variable : public Element
{
public:
	Sort *sortRef; ///< Reference to the sort that this variable represents.
	/**
	 * Default constructor. Calls the default Element constructor and sets sortRef to NULL.
	 */
	Variable();
	
	/**
	 * Full constructor. Calls the full Element constructor, then sets sortRef to NULL.
	 * @param _name - The C+ name of the variable.
	 * @param _transName - The ASP-compatible name of the variable.
	 */
	Variable(std::string _name, std::string _transName);
	
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
	 * Destructor. This class does not allocate memory, so it just sets sortRef to NULL but doesn't free anything.
	 */
	virtual ~Variable();
};

#endif /* VARIABLE_H */
