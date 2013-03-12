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


#ifndef QUERY_H
#define QUERY_H

#include <list>
#include <string>

#include "types.h"

class ParseElement;


/**
 * Container class that holds information and logic expressions representing a query.
 */
class Query
{
public:
	std::string label; ///< The numeric label used to refer to the query, expressed as a string for maximal flexibility.
	std::string maxstep; ///< A (positive) integer or integer range (e.g., "2..4") describing the maximum time step value(s) to use when trying to find solutions for the query.
	ParseElementList queryConditions; ///< A collection of the expressions that form the query.
	
	/**
	 * Default constructor. Initializes everything to blank/zero/etc.
	 */
	Query();
	
	/**
	 * Destructor. Deallocates the contents of queryContents and clears the list.
	 */
	virtual ~Query();
};

#endif // QUERY_H

