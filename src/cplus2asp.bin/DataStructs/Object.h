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


#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <vector>
#include <iostream>

#include "datastruct_externs.h"

#include "utilities.h"
#include "Element.h"
#include "Context.h"

class Sort;
class ElementCounter;


/**
 * The Object class represents an object in C+, a member of a sort's domain.
 * (I.e., one of the possible values fluents of the object's sort could be.)
 */
class Object : public Element
{
public:
	/// Enum to differentiate the valid kinds of objects, a basic object name ("bananas"), numeric range (1..10), or LUA call (@bananas).
	enum ObjectType { OBJ_NAME, OBJ_RANGE, OBJ_LUA };
	
private:
	enum ObjectType mObjType; 			///< Used to specify which kind of object this is.
	SortList mParams; 				///< Vector of parameters for this object, if any, expressed as references to sorts.

	std::string mFullName;				///< The full name of the object, with parameters.
	std::string mFullTransName;			///< The full ASP-compatible name of the object, with parameters.

public:
	
	/**
	 * Full constructor.
	 * @param name - The C+ name of this object.
	 * @param type - The type of object which is being instantiated.
	 * @param params - The list of parameters that the object uses, if any. (Null will result in the object having 0 parameters.)
	 */
	Object(std::string const& name, ObjectType type, SortList const* params = NULL);
	
	/**
	 * Full constructor with anonymous parameters (for LUA calls).
	 * Sets the object's type to LUA.
	 * @param name - The C+ name of this object.
	 * @param params - The number of anonymous parameters the object has.
	 */
	Object(std::string const& name, size_t params);

	inline virtual std::string const& fullName() const { return mFullName; }
	inline virtual std::string const& fullTransName() const { return mFullTransName; }
	virtual std::string toString() const;
	inline virtual bool isNumeric() const { int tmp; return mObjType == OBJ_RANGE || mObjType == OBJ_LUA || utils::from_string(tmp, fullName()); }
	inline virtual bool isBoolean() const { return fullName() == "true" || fullName() == "false"; }
	inline virtual bool isStarred() const { return fullName() == "none"; }
	
	/// Gets the number of parameters the object uses
	inline size_t arity() const	{ return mParams.size(); }

	/// Determines the type of object being represented.
	inline ObjectType getObjType() const { return mObjType; }

	/**
	 * Determines if the element archetype resembled an external LUA call.
	 * @return True if it does, false otherwise.
	 */
	inline bool isLua() const { return mObjType == OBJ_LUA; }

	/// Gets the beginning of the constant's parameter list.
	inline SortList::const_iterator beginParams() const		{ return mParams.begin(); }

	/// Gets the end of the constant's parameter list.
	inline SortList::const_iterator endParams() const			{ return mParams.end(); }

	/// Gets the ith parameter.
	inline Sort const* param(size_t i) const						{ return mParams[i]; }


	/**
	 * Outputs an ASP friendly declarable form for the object.
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
	 * Destructor. Nothing to deallocate, so it's empty.
	 */
	inline virtual ~Object() { /* Intentionally Left Blank */ }
};

#endif /* OBJECT_H */
