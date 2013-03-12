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
 * Context.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: joseph
 */

#include "DataStructs/Context.h"
#include "DataStructs/Sort.h"
#include <iostream>

/************************************************************/
/* Static Members */
/************************************************************/

std::string const Context::TRUE_STR = "true";
std::string const Context::FALSE_STR = "false";
std::string const Context::EMPTY_STR = "";
std::string const Context::ANON_STR = "_";


/************************************************************/
/* Methods */
/************************************************************/

/// Adds a variable to the list (if it's bound) and generated a #domain statement.
bool Context::addFreeVariable(std::string const& var, Sort const* domain) {
	if (domain && mPreStmts) {
		std::string stmt("#domain " + domain->baseTransName() + "(" + var + ").");
		addPreStmt(Statement(stmt, IPART_BASE));
	}

	if (mFreeVars) {
		mFreeVars->push_back(var);
		return true;
	} else {
		return false;
	}
}

/// Copy another context
Context const& Context::copy(Context const& other) {
	mPos = other.mPos;
	mPart = other.mPart;
	mNeg = other.mNeg;
	mPositive = other.mPositive;
	mVal = other.mVal;
	mTime = other.mTime;
	mFreeVars = other.mFreeVars;
	mExtraClauses = other.mExtraClauses;
	mPreStmts = other.mPreStmts;
	return *this;
}
