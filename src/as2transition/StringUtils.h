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


#ifndef STRINGUTILS_DOT_H
#define STRINGUTILS_DOT_H

#include <sstream>
#include <string>

/**
 * A class of static string utilities that help with processing raw text into various forms.
 */
namespace StringUtils
{
	/**
	 * Attempts to transform a string into a numeric representation of itself.
	 * For numbers, fmt should be dec, hex, or oct.
	 * @param val - A reference to the recipient of the generated number.
	 * @param s - The string to convert.
	 * @param fmt - An optional parameter that specifies what kind of numeric conversion to attempt. If not given, will default to std::dec.
	 * @return True if s could be converted into a number using fmt, false if there was a problem performing the conversion.
	 */
	template <class T>
	bool from_string(T& val, std::string const& s, std::ios_base& (*fmt)(std::ios_base&)=std::dec)
	{
			std::istringstream iss(s);
			return !(iss >> fmt >> val).fail();
	}

	/**
	 * Transforms something (usually a number) into a string representation of itself.
	 * For integers, fmt should be dec, hex, or oct. For floating-point numbers, fmt should be fixed or scientific.
	 * Precision will help control the precision of floating-point numbers.
	 * @param val - The number to transform into a string.
	 * @param fmt - An optional parameter controlling what kind of number val should be treated as. Defaults to std::dec.
	 * @param precision - The decimal precision to use with floating-point numbers. Defaults to -1.
	 * @return The string version of val on success, a blank string on failure.
	 */
	template <class T>
	std::string to_string(T val, std::ios_base& (*fmt)(std::ios_base&)=std::dec, int precision=-1)
	{
			std::stringstream ss;
			if(precision > -1)
			{
				ss.precision(precision);
			}
			ss << fmt << val;
			return ss.str();
	}

	/**
	 * Trims whitespace from both ends of a text string.
	 * @param text - The text to trim.
	 * @return The string stripped of whitespace on both sides.
	 */
	std::string trimWhitespace(std::string const& text);

	/**
	 * Starting from position index, finds the first character in text that isn't whitespace, returns its position.
	 * @param text - The string to search.
	 * @param index - Optional parameter specifying starting index of the search. Defaults to 0.
	 * @return The index of the first character in text that isn't whitespace, or string::npos if it's all whitespace.
	 */
	inline size_t findFirstNotWhitespace(std::string const& text, size_t index=0)
	{
		return text.find_first_not_of(" \n\f\r\t\v", index);
	}

	/**
	 * Starting from position index, finds the first character in text that is whitespace, returns its position.
	 * @param text - The string to search through.
	 * @param index - Optional parameter specifying starting index of the search. Defaults to 0.
	 * @return The index of the first character in text that is whitespace, or string::npos if none of it is whitespace.
	 */
	inline size_t findFirstWhitespace(std::string const& text, size_t index=0)
	{
		return text.find_first_of(" \n\f\r\t\v", index);
	}

	/**
	 * Scans a string for the first occurrence of a delimiter within the same parentheses context
	 * (i.e. s.t. the number of opening parentheses encountered equals the number of closing).
	 * @param str The string to scan.
	 * @param delim The delimiter to look for.
	 * @param strSize The size of the string, or maximum length to look at.
	 * @return A pointer to the delimiter if it was found. NULL if it wasn't (reached strSize or an unmatched close paren before encountering it).
	 */
	char const* scanAndMatchParens(char const* str, char delim, size_t strSize);

};

#endif // STRINGUTILS_DOT_H
