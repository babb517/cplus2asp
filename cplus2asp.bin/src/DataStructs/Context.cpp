/*
 * Context.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: joseph
 */

#include "Context.h"

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
	return *this;
}
