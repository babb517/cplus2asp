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


#include <cstring>
#include <iostream>

#include "Predicate.h"
#include "Config.h"


std::string Predicate::sNoneValue = "none";

// Re-creates an appropriate string representation of the predicate and returns it.
std::string Predicate::toPredicateString(Config::Format fmt)
{
	std::string stripped_name;

	// Strip the 'saniConst_' from the constant.
	if (name.find("saniConst_") == 0) {
		stripped_name = name.substr(10);
	} else {
		stripped_name = name;
	}
	// Most of the special formatting only happens to special predicates, so check that first.
	if(predType == T_UNKNOWN) {
		return stripped_name;
	}

	switch (fmt) {
	case Config::FMT_AF_COMPRESSED_BOOL:
		if (isBool())
			return (isFalse() ? "-" : "") + stripped_name;

		/* no break */
	case Config::FMT_ATOMIC_FORMULA:
		if (hasEql)
			return stripped_name + "=" + value;
		else return stripped_name;

	case Config::FMT_STRIP_PREFIX:
		if (hasEql)
			return "eq(" + stripped_name + ", " + value + ")";
		else return stripped_name;

	case Config::FMT_ORIGINAL:
	default:
		std::stringstream ret;

		ret << predTypeToPrefixString(predType);

		if (hasEql)
			ret << "eq(" << stripped_name << ", " << value << ")";
		else ret << stripped_name;


		if (predType != T_RIGID && timeStamp != UNKNOWN_TIME) {
			ret << ", " << timeStamp;
		}

		if (predType != T_UNKNOWN) ret << ")";

		return ret.str();
	}

}


Predicate::Type Predicate::getPrefixType(std::string const& text, size_t* outOffset) {
	std::string trimStr = StringUtils::trimWhitespace(text);
	char const* tempStr = trimStr.c_str();

	// check the prefix
	if (trimStr.size() >= 2 && !strncmp(tempStr,"h(",2)) {
		if (outOffset) *outOffset = 2;
		return T_FLUENT;
	} else if (trimStr.size() >= 4 && !strncmp(tempStr,"occ(",4)) {
		if (outOffset) *outOffset = 4;
		return T_ACTION;
	} else if (trimStr.size() >= 5 && !strncmp(tempStr,"ab_h(",5)) {
		if (outOffset) *outOffset = 5;
		return T_STATIC_AB;
	} else if (trimStr.size() >= 7 && !strncmp(tempStr,"ab_occ(",7)) {
		if (outOffset) *outOffset = 7;
		return T_DYNAMIC_AB;
	} else {
		// This isn't a specially formatted predicate, we give up.
		if (outOffset) *outOffset = 0;
		return T_UNKNOWN;
	}
}

void Predicate::getPredInfo(std::string const& text, Type& outType, bool& outHasEql, std::string& outName, bool& outXPred, std::string& outVal, int& outTime)
{
	// Intermediate results
	std::string tmpName;

	size_t curpos = 0;
	size_t offset = 0;
	size_t size;

	std::string trimStr = StringUtils::trimWhitespace(text);
	char const* tempStr = trimStr.c_str();
	size = trimStr.size();

	
	outType = getPrefixType(trimStr, &offset);

	curpos += offset;

	// we don't want to try if we don't know the type.
	if (outType == T_UNKNOWN) {
		outType = T_UNKNOWN;
		outHasEql = false;
		outName = trimStr;
		outVal = "";
		outTime = UNKNOWN_TIME;
		return;
	}


	// If we're still here then we still have work to do. Lets keep working

	// check the function specifier
	if (size - curpos >= 3 && !strncmp(tempStr + curpos, "eq(", 3)) {
		outHasEql = true;
		curpos += 3;
	} else if (size - curpos >= 4 && !strncmp(tempStr + curpos, "eql(", 4)) {
		outHasEql = true;
		curpos += 4;
	} else {
		outHasEql = false;
	}


	// Let's check to see if this is really a contribution predicate...
	if (outType == T_ACTION &&
			((size - curpos >= 10 && !strncmp(tempStr + curpos, "x_contrib(",10))
					|| (size - curpos >= 13 && !strncmp(tempStr + curpos, "contribution(",13))))
	{
			outType = T_CONTRIB;
	}

	// We also should verify whether this is an x_pred.
	if ((size - curpos >= 2 && !strncmp(tempStr + curpos, "x_", 2))) {
		outXPred = true;
	} else {
		outXPred = false;
	}


	// get the base name.
	offset = (int)(StringUtils::scanAndMatchParens(tempStr + curpos, ',', size - curpos) - (tempStr + curpos));

	// check to make sure we found it!
	if (offset < 1) {
		outType = T_UNKNOWN;
		outHasEql = false;
		outName = trimStr;
		outVal = "";
		outTime = UNKNOWN_TIME;
		return;
	}

	// endpos is now pointing the comma right after the atom name
	outName = StringUtils::trimWhitespace(trimStr.substr(curpos, offset));

	// start after the comma...
	curpos += offset + 1;

	if (outHasEql) {
		// if the predicate has an eql() wrapper, then we want to get the value it's equal to.

		offset = (int)(StringUtils::scanAndMatchParens(tempStr + curpos, ')', size - curpos) - (tempStr + curpos));

		// make sure we found something...
		if (offset < 1) {
			outType = T_UNKNOWN;
			outHasEql = false;
			outName = trimStr;
			outVal = "";
			outTime = UNKNOWN_TIME;
			return;
		}
		outVal = StringUtils::trimWhitespace(trimStr.substr(curpos, offset));

		// skip the ")"
		curpos += offset + 1;

	} else {
		// Doesn't have an eql(), so we don't bother unwrapping the value.
		outVal = "";
	}

	// skip the comma if it exists...
	if (*(tempStr + curpos) == ',') curpos++;


	// last but not least, find ourselves the time
	offset = (int)(StringUtils::scanAndMatchParens(tempStr + curpos, ')', size - curpos) - (tempStr + curpos));

	// make sure we found something...


	if (offset == 0 && outType == T_FLUENT) {
		// special case: we're looking at a rigid predicate.
		outType = T_RIGID;
		outTime = RIGID_TIME;

	} else if (offset < 1) {
		outType = T_UNKNOWN;
		outHasEql = false;
		outName = trimStr;
		outVal = "";
		outTime = UNKNOWN_TIME;
		return;
	} else if (!StringUtils::from_string<int>(outTime, StringUtils::trimWhitespace(trimStr.substr(curpos, offset)))) {
		// can't convert to an integer time.
		outTime = UNKNOWN_TIME;
	}

	return;
}

std::string Predicate::predTypeToPrefixString(Type predType) {
	switch (predType) {
	case T_FLUENT:
	case T_RIGID:
		return "h(";
	case T_ACTION:
	case T_CONTRIB:
		return "occ(";
	case T_STATIC_AB:
		return "ab_(";
	case T_DYNAMIC_AB:
		return "ab_occ(";
	case T_UNKNOWN:
	default:
		return "";
	}
}
