/*
 * Context.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: joseph
 */

#include "Context.h"
#include "Sort.h"
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
