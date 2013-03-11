#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include "types.h"


/**
 * The Element class is the super-parent class for almost all syntactic elements of a C+ program.
 * It contains name and transName, strings used to refer to the literal name of elements during translation.
 */
class Element
{
public:
	/// An enum of the sub-classes of Element (including Element itself).
	enum ElementType { ELEM_CONST, ELEM_ELEM, ELEM_OBJ, ELEM_SORT, ELEM_VAR };
private:
	std::string mBaseName; 				///< The original base name of this element.
	std::string mBaseTransName; 		///< The translated (i.e., ASP-compatible) base name of this element.
	enum ElementType mElemType; 		///< Used to identify what kind of Element an instance is.

public:

	/**
	 * Partial constructor. Sets attributes to given values.
	 * @param baseName - The C+ name of an element.
	 * @param baseTransName - The ASP-compatible name of an element.
	 * @param type - The type of element which is being instantiated.
	 */
	Element(std::string const& baseName, std::string const& baseTransName, ElementType type);


	/**
	 * Generates a human-readable string representation of this object.
	 * @return A string suitable for printing to a console or log.
	 */
	virtual std::string toString() const = 0;

	/**
	 * Determines if the element archetype ranges over strictly numeric values.
	 * @return True if it does, false otherwise.
	 */
	virtual bool isNumeric() const = 0;


	/**
	 * Determines if the element archetype ranges over strictly boolean values.
	 * @return True if it does, false otherwise.
	 */
	virtual bool isBoolean() const = 0;

	/**
	 * Determines if the element archetype contains the value 'none' in its range.
	 * @return True if it does, false otherwise.
	 */
	virtual bool isStarred() const = 0;

	/**
	 * Generates the original full name of this element, including full parameter names (if any).
	 * @return A string representation of this element's base name plus a
	 * parenthesized, comma-separated list of the full names of any parameters
	 * (if it has any).
	 */
	virtual std::string const& fullName() const = 0;
	
	/**
	 * Generates the translated full name of this element, including
	 * translated full parameter names (if any).
	 * @return A string representation of this element's translated base name
	 * plus a parenthesized, comma-separated list of the full names of any
	 * parameters (if it has any).
	 */
	virtual std::string const& fullTransName() const = 0;

	/// Gets the type of element being represented.
	ElementType getElemType() const { return mElemType; }


	/// Gets the base name of the element.
	inline std::string const& baseName() const { return mBaseName; }

	/// Gets the base translated name of the element.
	inline std::string const& baseTransName() const { return mBaseTransName; }

	/**
	 * Destructor. Does nothing, as there's nothing to destroy.
	 */
	virtual ~Element();

};

#endif /* ELEMENT_H */
