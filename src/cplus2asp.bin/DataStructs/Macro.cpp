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


#include <list>

#include "DataStructs/Token.h"

#include "DataStructs/Macro.h"

// Default constructor.
Macro::Macro()
{
	// Nothing to do, intentionally empty.
}

// Returns a human-readable reconstruction of the original macro.
std::string Macro::stringValue()
{
	std::string retVal = "";
	for(std::list<Token*>::iterator lIter = pattern.begin(); lIter != pattern.end(); ++lIter)
	{
		if(*lIter != NULL)
		{
			retVal += (*lIter)->stringValue;
		}
	}
	retVal += " -> ";
	for(std::list<Token*>::iterator lIter = result.begin(); lIter != result.end(); ++lIter)
	{
		if(*lIter != NULL)
		{
			retVal += (*lIter)->stringValue;
		}
	}
	if(!where.empty())
	{
		retVal += " where ";
		for(std::list<Token*>::iterator lIter = where.begin(); lIter != where.end(); ++lIter)
		{
			if(*lIter != NULL)
			{
				retVal += (*lIter)->stringValue;
			}
		}
	}
	return retVal;
}

// Destructor.
Macro::~Macro()
{
	// Delete all Tokens in the lists.
	for(std::list<Token*>::iterator lIter = pattern.begin(); lIter != pattern.end(); ++lIter)
	{
		if(*lIter != NULL)
		{
			delete *lIter;
		}
	}
	pattern.clear();
	for(std::list<Token*>::iterator lIter = result.begin(); lIter != result.end(); ++lIter)
	{
		if(*lIter != NULL)
		{
			delete *lIter;
		}
	}
	result.clear();
	for(std::list<Token*>::iterator lIter = where.begin(); lIter != where.end(); ++lIter)
	{
		if(*lIter != NULL)
		{
			delete *lIter;
		}
	}
	where.clear();
}
