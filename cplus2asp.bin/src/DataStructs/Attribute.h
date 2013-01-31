#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>
#include "Constant.h"

/**
 * Subclass of Constant designed to represent an attribute declaration.
 * Contains additional information that connects an attribute to its action.
 */
class Attribute : public Constant
{
public:
	Constant* attributeOf; ///< Reference to the constant (action) this attribute binds to.
	
	/**
	 * Default constructor. Calls Constant constructor, sets constType to 
	 * CONST_ATTRIBUTE and attributeOf to NULL.
	 */
	Attribute();
	
	/**
	 * Full constructor. Calls full Constant constructor, sets constType and
	 * attributeOf appropriately.
	 * @param _name - The C+ name of this object.
	 * @param _transName - The ASP-compatible name of this object.
	 */
	Attribute(std::string _name, std::string _transName);
	
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
	 * @return Returns a string suitable for printing to a console or log.
	 */
	virtual std::string toString();
	
	/**
	 * Destructor. Nothing to deallocate, just sets attributeOf to NULL.
	 */
	virtual ~Attribute();
};

#endif // ATTRIBUTE_H
