#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <vector>

#include "datastruct_externs.h"

#include "Element.h"

class Sort;


/**
 * The Object class represents an object in C+, a member of a sort's domain.
 * (I.e., one of the possible values fluents of the object's sort could be.)
 */
class Object : public Element
{
public:
	/// Enum to differentiate the valid kinds of objects, a basic object name ("bananas") or a numeric range (1..10).
	enum ObjectType { OBJ_NAME, OBJ_RANGE };
	enum ObjectType objType; ///< Used to specify which kind of object this is.
	
	std::vector<Sort*> params; ///< Vector of parameters for this object, if any, expressed as references to sorts.
	
	bool isLua;		///< Indicates whether the object is actually a LUA call.

	/**
	 * Default constructor. Calls default Element constructor, sets objType to OBJ_NAME.
	 */
	Object();
	
	/**
	 * Full constructor. Passes _name and _transName to the full Element constructor, sets objType to OBJ_NAME.
	 * @param _name - The C+ name of this object.
	 * @param _transName - The ASP-compatible name of this object.
	 */
	Object(std::string _name, std::string _transName, bool _isLua = false);

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
	 * Destructor. Nothing to deallocate, so it's empty.
	 */
	virtual ~Object();
};

#endif /* OBJECT_H */
