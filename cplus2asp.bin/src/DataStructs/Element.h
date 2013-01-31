#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

/**
 * The Element class is the super-parent class for almost all syntactic elements of a C+ program.
 * It contains name and transName, strings used to refer to the literal name of elements during translation.
 */
class Element
{
public:
	std::string name; ///< The original name of this element.
	std::string transName; ///< The translated (i.e., ASP-compatible) name of this element.
	
	/// An enum of the sub-classes of Element (including Element itself).
	enum ElementType { ELEM_CONST, ELEM_ELEM, ELEM_OBJ, ELEM_SORT, ELEM_VAR };
	enum ElementType elemType; ///< Used to identify what kind of Element an instance is.
	
	/**
	 * Default constructor. Initializes everything to blank/base values.
	 */
	Element();

	/**
	 * Full constructor. Sets attributes to given values.
	 * @param _name - The C+ name of an element.
	 * @param _transName - The ASP-compatible name of an element.
	 */
	Element(std::string _name, std::string _transName);

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
	 * Destructor. Does nothing, as there's nothing to destroy.
	 */
	virtual ~Element();
};

#endif /* ELEMENT_H */
