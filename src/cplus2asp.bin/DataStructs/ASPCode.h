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


#ifndef ASPCODE_H
#define ASPCODE_H

#include <string>
#include "DataStructs/Comment.h"

//#include "DataStructs/datastruct_externs.h"

/**
 * A child of Comment that has been tweaked to store raw ASP code to pass through
 * from input to output.
 */
class ASPCode : public Comment
{
public:
	/**
	 * Default constructor. Sets everything to blank or zero, forces isRealComment (from parent) to false.
	 */
	ASPCode();
	
	/**
	 * Assignment operator overload.
	 * Copies all data from rhs to the lhs code block.
	 * @param rhs - The ASPCode to grab the data from.
	 * @return A reference to the lhs code block.
	 */
	ASPCode& operator=(const ASPCode &rhs);
	
	/**
	 * Destructor.
	 */
	virtual ~ASPCode();
};

#endif
