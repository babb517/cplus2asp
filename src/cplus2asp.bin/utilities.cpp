#include "utilities.h"

namespace utils
{


/// Trims whitespace from a string.
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

/**
 * Checks if a character represents a digit or not.
 * @param testChar - The character to test.
 * @return True if it's a digit, false otherwise.
 */
bool isDigit(char testChar)
{
	bool retVal = false;
	if(testChar >= '0' && testChar <= '9')
	{
		retVal = true;
	}
	return retVal;
}

// Checks if a character is an lower-case (English) letter or not.
bool isLowercase(char testChar)
{
	bool retVal = false;
	if(testChar >= 'a' && testChar <= 'z')
	{
		retVal = true;
	}
	return retVal;
}

// Checks if a character is an upper-case (English) letter or not.
bool isUppercase(char testChar)
{
	bool retVal = false;
	if(testChar >= 'A' && testChar <= 'Z')
	{
		retVal = true;
	}
	return retVal;
}

// Checks if a character is an English letter or not, regardless of case.
bool isLetter(char testChar)
{
	return (isUppercase(testChar) || isLowercase(testChar));
}

}
