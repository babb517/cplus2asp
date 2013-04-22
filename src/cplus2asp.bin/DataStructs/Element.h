/* 
 * Copyright (c) 2010-2013 <Joseph Babb, Michael Cassollary, Joohyung Lee>
 *
 * For information on how to contact the authors, please visit
 *	http://reasoning.eas.asu.edu/cplus2asp
 *
 * This file is part of the cplus2asp system.
 *
 * cplus2asp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cplus2asp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


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
	enum ElementType { ELEM_CONST, ELEM_ELEM, ELEM_OBJ, ELEM_SORT, ELEM_VAR, _ELEM_TYPE_COUNT };
private:
	std::string mBaseName; 				///< The original base name of this element.
	std::string mBaseTransName; 		///< The translated (i.e., ASP-compatible) base name of this element.
	enum ElementType mElemType; 		///< Used to identify what kind of Element an instance is.
	bool mInternal;						///< Whether or not this is a symbol internal to the translator.

public:

	/**
	 * Partial constructor. Sets attributes to given values.
	 * @param baseName - The C+ name of an element.
	 * @param baseTransName - The ASP-compatible name of an element.
	 * @param type - The type of element which is being instantiated.
	 * @param internal - Whether this symbol is internal to the translator or not.
	 */
	Element(std::string const& baseName, std::string const& baseTransName, ElementType type, bool internal);


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


	/// Gets the arity of the element.
	virtual size_t arity() const = 0;

	/// Gets the type of element being represented.
	ElementType getElemType() const { return mElemType; }


	/// Determines if this symbol is internal to the translator
	inline bool internal() const { return mInternal; }
	/// Sets if this symbol is internal to the translator
	inline void internal(bool internal) { mInternal = internal; }

	/// Gets the base name of the element.
	inline std::string const& baseName() const { return mBaseName; }

	/// Gets the base translated name of the element.
	inline std::string const& baseTransName() const { return mBaseTransName; }

	/**
	 * Destructor. Does nothing, as there's nothing to destroy.
	 */
	virtual ~Element();


	/// converts the element type to a string representation.
	static std::string elemTypeToString(ElementType type);

};

#endif /* ELEMENT_H */
