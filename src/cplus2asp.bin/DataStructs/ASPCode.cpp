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

#include "DataStructs/Comment.h"
#include "ltsglobals.h"

#include "DataStructs/ASPCode.h"

// Default constructor.
ASPCode::ASPCode() : Comment()
{
	// ASP code isn't a "real" comment, it's just raw text.
	isRealComment = false;
}

// Assignment operator overload.
ASPCode& ASPCode::operator=(const ASPCode &rhs)
{
	// Skip self-assignment.
	if(this != &rhs)
	{
		this->contents = rhs.contents;
		this->fileName = rhs.fileName;
		if(rhs.loc != NULL)
		{
			if(this->loc == NULL)
			{
				this->loc = new YYLTYPE;
			}
			this->loc->first_line = rhs.loc->first_line;
			this->loc->last_line = rhs.loc->last_line;
			this->loc->first_column = rhs.loc->first_column;
			this->loc->last_column = rhs.loc->last_column;
		}
		else
		{
			if(this->loc != NULL)
			{
				delete this->loc;
			}
			this->loc = NULL;
		}
		this->isRealComment = rhs.isRealComment;
	}
	return *this;
}

// Destructor.
ASPCode::~ASPCode()
{
	// Nothing to do, intentionally empty.
}
