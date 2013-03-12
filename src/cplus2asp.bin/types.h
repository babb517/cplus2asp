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


/*
 * types.h
 *
 *  Created on: Feb 8, 2013
 *      Author: joseph
 */

#ifndef TYPES_H_
#define TYPES_H_

#include<list>
#include<vector>



class Sort;
class Object;
class ParseElement;
class BaseLikeElement;

/// The incremental module that a statement is associated with.
enum IPart { IPART_BASE, IPART_CUMULATIVE, IPART_VOLATILE, IPART_NONE };


typedef std::list<std::string> ClauseList;						///< A list containing 0 or more clauses which should be conjoined to the body of a formula.
typedef std::pair<std::string,IPart> Statement;					///< A simple tuple representing a statement occuring within an specified part of incremental module.
typedef std::list<Statement> StmtList;							///< A list containing 0 or more statements which should be added to the program and their corresponding IPARTs.
typedef std::vector<std::string> NameList;						///< A list of identifier names.

typedef std::vector<Object*> ObjectList;						///< A list of object elements.
typedef std::vector<Object const*> ConstObjectList;				///< A list of constant object elements.
typedef std::vector<Sort*> SortList;							///< A list of sort elements.
typedef std::vector<Sort const*> ConstSortList;					///< A list of constant sort elemetns.

typedef std::list<ParseElement*> ParseElementList;				///< A list of parse elements.
typedef std::list<BaseLikeElement*> BaseElementList;			///< A list of base parse elements.

#endif /* TYPES_H_ */
