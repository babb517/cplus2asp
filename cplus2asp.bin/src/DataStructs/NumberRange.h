#ifndef NUMBERRANGE_H
#define NUMBERRANGE_H

#include <string>

#include "Object.h"

/**
 * Subclass of Object, represents a range of integers as objects.
 */
class NumberRange : public Object
{
public:
	std::string min; ///< The lower bound of the range.
	std::string max; ///< The upper bound of the range.
	/**
	 * Default constructor. Sets min and max to 0, calls the default Object 
	 * constructor, and sets the inherited objType to OBJ_RANGE.
	 */
	NumberRange();
	
	/**
	 * Full constructor. Sets min and max to given values, calls the full 
	 * Object constructor, and sets the inherited objType to OBJ_RANGE.
	 * @param _name - The C+ raw name of the range.
	 * @param _transName - The ASP-compatible raw name of the range.
	 * @param _min - The lower bound of the range.
	 * @param _max - The upper bound of the range.
	 */
	NumberRange(std::string _name, std::string _transName, std::string _min, std::string _max);
	
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
	 * Destructor. Left empty, as there's nothing to do.
	 */
	virtual ~NumberRange();
};

#endif /* NUMBERRANGE_H */
