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

