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


#ifndef LUAOBJECT_H
#define LUAOBJECT_H

#include <string>
#include <vector>
#include <iostream>


#include "utilities.h"
#include "DataStructs/Object.h"

/**
 * An object representing a LUA call in the program.
 */
class LUAObject : public Object {
private:
	/***********************************************************/
	/* Private Members */
	/***********************************************************/

	/**
	 * The intermediate resolved LUA object used.
	 */
	private Object* mLUARef;
	
public:	
	/***********************************************************/
	/* Private Members */
	/***********************************************************/

	/**
	 * Full constructor with anonymous parameters (for LUA calls).
	 * Sets the object's type to LUA.
	 * @param name - The C+ name of this object.
	 * @
	 * @param params - The number of anonymous parameters the object has.
	 */
	inline LUAObject(std::string const& name, Object* lua = NULL, size_t params = 0)
		: Object(name, ObjectType::OBJ_LUA, false, params), mLUARef(lua)
	{ /* Intentionally Left Blank */ }


	/// Gets the reference to the internal LUA object.
	inline Object* luaRef() const { return mLUARef; }

	/// Sets the reference to the internal LUA object.
	inline luaRef(Object* lua) { mLUARef = lua; }

};


#endif

