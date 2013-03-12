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


#include "StringUtils.h"

namespace StringUtils {

	char const* scanAndMatchParens(char const* str, char delim, size_t strSize) {

		char const* end = str + strSize;
		size_t numParens = 0;

		if (strSize == 0) return NULL;

		do {
			if (*str == delim && numParens == 0) return str;
			else if (*str == '(') numParens++;
			else if (*str == ')') numParens--;
			else if (numParens < 0) return NULL;
		} while (++str < end);

		return NULL;

	}

	std::string trimWhitespace(std::string const& text)
	{
		std::string retVal = "";
		std::string whitespace = " \n\f\r\t\v";
		size_t sztFirstPos = 0, sztSecondPos = 0;
		if(text.length() > 0)
		{
			sztFirstPos = text.find_first_not_of(whitespace);
			sztSecondPos = text.find_last_not_of(whitespace);
			if(sztFirstPos != std::string::npos)
			{	// We got two valid positions, trim accordingly.
				retVal = text.substr(sztFirstPos, sztSecondPos - sztFirstPos + 1);
			}
			else
			{	// The whole dang string is whitespace, return blank.
				retVal = "";
			}
		}
		return retVal;
	}

}

