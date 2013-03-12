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



#include "DataStructs/NumberRange.h"
#include "utilities.h"

NumberRange::NumberRange(std::string const& name)
			: Object(name, Object::OBJ_RANGE, NULL) {
	// Figure out the proper range based on the name.

	size_t pos;
	if ((pos = name.find("..")) != std::string::npos) {
		mMin = utils::trimWhitespace(name.substr(0, pos));
		mMax = utils::trimWhitespace(name.substr(pos+2));
	} else {
		// TODO: Throw a warning.
		mMin = "UNKNOWN";
		mMax = "UNKNOWN";
	}
}

// Standard toString function.
std::string NumberRange::toString() const
{
	// Start with Object info, then add on NumberRange-specific stuff.
	std::string tempStr = Object::toString();
	tempStr += "\n    [NumberRange]";
	tempStr += "\n    min = ";
	tempStr += min();
	tempStr += "\n    max = ";
	tempStr += max();
	return tempStr;
}
