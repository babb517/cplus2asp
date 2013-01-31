#include <string>
#include <sstream>

#include "flexertypes.h"
#include "ltsglobals.h"

#include "Token.h"
#include "ASPCode.h"
#include "Comment.h"

// Default constructor. Inititalizes all member values to 0, blank, or equivalent.
Token::Token()
{
	tokenID = 0;
	tokenValue.integer = 0;
	tokenValueType = VT_INT;
	tokenLocation.first_line = tokenLocation.last_line = 0;
	tokenLocation.first_column = tokenLocation.last_column = 0;
	tokenFileName = "";
	stringValue = "";
}

// Assignment operator overload.
Token& Token::operator=(const Token &rhs)
{
	// Skip self-assignment.
	if(this != &rhs)
	{
		this->tokenID = rhs.tokenID;
		// Deallocate this token's tokenValue if necessary.
		if(this->tokenValueType != VT_INT && this->tokenValue.integer != 0)
		{
			switch(this->tokenValueType)
			{
			case VT_STR:
				delete this->tokenValue.str;
				break;
			case VT_ASP:
				delete this->tokenValue.asp;
				break;
			case VT_COMMENT:
				delete this->tokenValue.com;
				break;
			default:
				// Do nothing, nothing to delete.
				break;
			}
		}
		// Copy rhs's tokenValue and tokenValueType, as appropriate.
		switch(rhs.tokenValueType)
		{
		case VT_INT:
			// Integer, copy rhs's value.
			this->tokenValueType = VT_INT;
			this->tokenValue.integer = rhs.tokenValue.integer;
			break;
		case VT_STR:
			// String, allocate memory and copy rhs's contents.
			this->tokenValueType = VT_STR;
			this->tokenValue.str = new std::string;
			if(rhs.tokenValue.str != NULL)
			{
				*(this->tokenValue.str) = *(rhs.tokenValue.str);
			}
			break;
		case VT_ASP:
			// ASP code, allocate memory and copy rhs's contents.
			this->tokenValueType = VT_ASP;
			this->tokenValue.asp = new ASPCode();
			if(rhs.tokenValue.asp != NULL)
			{
				*(this->tokenValue.asp) = *(rhs.tokenValue.asp);
			}
			break;
		case VT_COMMENT:
			// Raw comment text, allocate memory and copy rhs's contents.
			this->tokenValueType = VT_COMMENT;
			this->tokenValue.com = new Comment();
			if(rhs.tokenValue.com != NULL)
			{
				*(this->tokenValue.com) = *(rhs.tokenValue.com);
			}
			break;
		default:
			// Unknown, just pretend it's an int with value 0.
			this->tokenValueType = VT_INT;
			this->tokenValue.integer = 0;
			break;
		}
		this->tokenLocation = rhs.tokenLocation;
		this->tokenFileName = rhs.tokenFileName;
		this->stringValue = rhs.stringValue;
	}
	return *this;
}

// Checks if this token's ID, value type, and value are the same as other's respective data.
bool Token::contentsEqual(const Token &other) const
{
	bool retVal = false; // Start pessimistic.
	if(this->tokenID == other.tokenID && this->tokenValueType == other.tokenValueType)
	{	// If the IDs and value types are equal, check the values.
		switch(this->tokenValueType)
		{
		case VT_INT:
			// Integers, compare directly.
			if(this->tokenValue.integer == other.tokenValue.integer)
			{
				retVal = true;
			}
			break;
		case VT_STR:
			// Strings, compare contents (if not NULL).
			if(this->tokenValue.str != NULL && other.tokenValue.str != NULL && *(this->tokenValue.str) == *(other.tokenValue.str))
			{
				retVal = true;
			}
			break;
		case VT_ASP:
			// ASP code, compare contents (if not NULL).
			if(this->tokenValue.asp != NULL && other.tokenValue.asp != NULL && this->tokenValue.asp->contents == other.tokenValue.asp->contents)
			{
				retVal = true;
			}
			break;
		case VT_COMMENT:
			// Raw comment text, compare contents (if not NULL).
			if(this->tokenValue.com != NULL && other.tokenValue.com != NULL && this->tokenValue.com->contents == other.tokenValue.com->contents)
			{
				retVal = true;
			}
			break;
		default:
			// Unknown, assume integer and hope for the best.
			if(this->tokenValue.integer == other.tokenValue.integer)
			{
				retVal = true;
			}
			break;
		}
	}
	return retVal;
}

// Checks if any of this token's ID, value type, and value are different from other's respective data.
bool Token::contentsNotEqual(const Token &other) const
{
	// This one's easy, just check for equality and return the opposite result.
	return !this->contentsEqual(other);
}

// Generates a human-readable string representation of a token.
std::string Token::toString()
{
	std::ostringstream oss("");
	oss << "[Token]" 
		<< "\nText: \"" << stringValue << "\""
		<< "\nFile: \"" << tokenFileName << "\""
		<< "\nLocation: Line " << tokenLocation.first_line << "." << tokenLocation.first_column << " - " 
		<< tokenLocation.last_line << "." << tokenLocation.last_column 
		<< std::endl;
	return oss.str();
}

// Destructor. Frees memory allocated for tokenValue if applicable.
Token::~Token()
{
	// The second condition here is a sneaky NULL check.
	if(tokenValueType != VT_INT && tokenValue.integer != 0)
	{
		switch(tokenValueType)
		{
		case VT_STR:
			delete tokenValue.str;
			break;
		case VT_ASP:
			delete tokenValue.asp;
			break;
		case VT_COMMENT:
			delete tokenValue.com;
			break;
		default:
			// Do nothing, nothing to delete.
			break;
		}
	}
}

