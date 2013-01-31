#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <sstream>

#include "flexertypes.h"
#include "ltsglobals.h"

/**
 * Contains all the information for a token retrieved from an input stream via a lex-style lexer.
 */
class Token
{
public:
	int tokenID; ///< The numeric ID type for a token.
	YYSTYPE tokenValue; ///< The value (i.e., yylval) for a token.
	flexerValueType tokenValueType; ///< The flag for a token to indicate the data type for its stored value.
	YYLTYPE tokenLocation; ///< The location (i.e., yylloc) of a token in the original input.
	std::string tokenFileName; ///< The name of the file a token came from.
	std::string stringValue; ///< String representation of the value of a token (i.e., yytext).
	
	/**
	 * Default constructor. Inititalizes all member values to 0, blank, or equivalent.
	 */
	Token();
	
	/**
	 * Assignment operator overload.
	 * Copies all data from rhs to the lhs token.
	 * @param rhs - The Token to grab the data from.
	 * @return A reference to the lhs token.
	 */
	Token& operator=(const Token &rhs);
	
	/**
	 * Checks if this token's ID, value type, and value are the same
	 * as other's respective data.
	 * @param other - The Token object to compare against.
	 * @return True if the aforementioned data matches, false otherwise.
	 */
	bool contentsEqual(const Token &other) const;
	
	/**
	 * Checks if any of this token's ID, value type, and value are different
	 * from other's respective data.
	 * @param other - The Token object to compare against.
	 * @return True if any of the aforementioned data is different, false otherwise.
	 */
	bool contentsNotEqual(const Token &other) const;
	
	/**
	 * Generates a human-readable string representation of a token.
	 * @return Returns a string suitable for printing to a console or log.
	 */
	virtual std::string toString();
	
	/**
	 * Destructor. Frees memory allocated for tokenValue if applicable.
	 */
	virtual ~Token();
};

#endif /* TOKEN_H */
