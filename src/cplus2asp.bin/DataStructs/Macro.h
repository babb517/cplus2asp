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


#ifndef MACRO_H
#define MACRO_H

#include <list>
class Token;

/**
 * A container class designed to store information about a macro definition, 
 */
class Macro
{
public:
	std::list<Token*> pattern; ///< The list of tokens that form the matching pattern for a macro.
	std::list<Token*> result; ///< What to put in pattern's place when it's matched with something.
	std::list<Token*> where; ///< The (optional) where clause of a macro, should be evaluated each time we're about to use the macro in an expansion.
	
	/**
	 * Default constructor. Initializes members to 0/blank/etc.
	 */
	Macro();
	
	/**
	 * Reconstructs a human-readable version of the original macro definition.
	 * @return A string consisting of "[pattern] -> [result]", with " where [where]" appended if the where token stream is not empty.
	 */
	std::string stringValue();
	
	/**
	 * Destructor. Deallocates all Tokens in each list and clears out the lists' contents.
	 */
	virtual ~Macro();
};

#endif
