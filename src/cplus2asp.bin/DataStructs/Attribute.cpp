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

#include "DataStructs/Attribute.h"

// Standard toString function.
std::string Attribute::toString() const {
	// Start with Constant info, then add on Attribute-specific stuff.
	std::string tempStr = Constant::toString();
	tempStr += "\n    [Attribute]";
	tempStr += "\n    parent = ";
	// If we don't have connected action yet, just say NULL.
	if(parent() == NULL)
	{
		tempStr += "NULL";
	}
	else
	{
		tempStr += "\"";
		tempStr += parent()->fullName();
		tempStr += "\"";
	}
	return tempStr;
}
