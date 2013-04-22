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


#include <string>
#include <vector>

#include "DataStructs/datastruct_externs.h"

#include "DataStructs/Element.h"

#include "DataStructs/Sort.h"
#include "utilities.h"
#include "Translator.h"
#include "DataStructs/Object.h"


// Full constructor.
Object::Object(std::string const& name, ObjectType type, bool internal, SortList const* params)
	: Element(name, Translator::sanitizeObjectName(name), Element::ELEM_OBJ, internal)
{
	mObjType = type;
	if (params) mParams = *params;

	mFullName = baseName();
	if(!mParams.empty())
	{
		mFullName += "(";
		mFullName += utils::elementVectorToFullNameString<Sort*>(mParams);
		mFullName += ")";
	}

	mFullTransName = baseTransName();
	if(!mParams.empty())
	{
		mFullTransName += "(";
		mFullTransName += utils::elementVectorToFullTransNameString<Sort*>(mParams);
		mFullTransName += ")";
	}

}

// LUA constructor.
Object::Object(std::string const& name, ObjectType type, bool internal, size_t params)
	: Element(name, Translator::sanitizeObjectName(name), Element::ELEM_OBJ, internal)
{
	mFullName = baseName();
	mFullTransName = baseName();
	mObjType = type;
	for (; params > 0; params--) {
		mParams.push_back(NULL);
	}
}

// Standard toString function.
std::string Object::toString() const
{
	std::string tempStr = "";
	tempStr += "  [Object]";
	tempStr += "\n  objType = ";

	// Print out the English version of the possible enum values of objType.
	switch (mObjType) {
	case OBJ_NAME:
		tempStr += "OBJ_NAME";
		break;
	case OBJ_RANGE:
		tempStr += "OBJ_RANGE";
		break;
	case OBJ_LUA:
		tempStr += "OBJ_LUA";
		break;
	default:
		tempStr += "UNKNOWN";
		break;
	}

	// If this is a "normal" object with parameters, list them.
	if(!mParams.empty())
	{
		tempStr += "\n  params = (";
		tempStr += utils::elementVectorToFullNameString<Sort*>(mParams, ", ", true);
		tempStr += ")";
	}
	return tempStr;
}


bool Object::translate(
		std::ostream& out,
		ClauseList& outClauses,
		ElementCounter* runningCount,
		std::vector<std::pair<Sort const*, std::string> >* matchMap,
		std::vector<std::pair<Sort const*, std::string> >* outMap) const {

	bool tmpCount = !runningCount;
	bool matchingMap = (bool)matchMap;							// Whether we are currently matching the mapped arguments.
	size_t count;												// The number of times this sort has appeared to date.
	std::string newVar;											// The name of the new variable to add.
	if (tmpCount) runningCount = new ElementCounter();

	// Translate the name...
	out << baseTransName();

	// Transform any parameters into sort variables.
	if(arity())
	{
		out << "(";

		// Use an occurrence counter to get guaranteed unique variable
		// names representing the sorts that comprise the parameters
		// of this constant.
		for(size_t i = 0; i < arity(); i++)
		{
			// check the argument against the known parameter list
			// Pragma: I'm fully aware that this does pointer-wise comparison.
			if (matchingMap && i < matchMap->size() && param(i) == matchMap->at(i).first) {
				// Everything (including this argument) has matched so far.
				// Keep using the mapped variables.
				if (i > 0) out << ", ";
				out << matchMap->at(i).second;
				if (outMap) outMap->push_back(std::pair<Sort const*, std::string>(param(i), matchMap->at(i).second));
			} else {
				// nope! Stop trying.
				matchingMap = false;

				newVar = param(i)->varTransName();
				// Generate our own variable to use.
				count = runningCount->add(param(i));
				if (count > 1) {
					newVar += "_" + utils::to_string(count);
				}

				// Add and register the new variable.
				if (i > 0) out << ", ";
				out << newVar;
				if (outMap) outMap->push_back(std::pair<Sort const*, std::string>(param(i), newVar));

				// Add the appropriate clause...
				if (count > 1) {
					outClauses.push_back(param(i)->fullTransName() + "(" + newVar + ")");
				}
			}
		}

		out << ")";
	}

	if (tmpCount) delete runningCount;

	return !matchMap || matchingMap;
}
