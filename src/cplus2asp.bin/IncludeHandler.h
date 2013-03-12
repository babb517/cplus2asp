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


#ifndef INCLUDEHANDLER_H
#define INCLUDEHANDLER_H

#include <list>
#include <sstream>
#include <string>
#include <vector>

#include "ltsglobals.h"
#include "lexerTokenStream.h"



//-----TODO: Handle comments from included files correctly
//-----TODO: Fix include as last line bug

/**
 * Container class designed to insert the stream of tokens from a file specified in a statement like ":- include 'filename1'."
 */
class IncludeHandler
{
public:
	int includeNumErrors; ///< Tracks how many errors the include handler encounters.
	std::string includeFileName; ///< Tracks which file is currently being parsed.
	YYLTYPE includeTokenLoc; ///< Tracks the last known location of a valid token being parsed.
	bool parseError; ///< If true, the parser is in an error state, and should ignore the rest of whatever statement it's parsing.
	
	/**
	 * Default constructor. Ensures all attributes are 0/empty/NULL/etc.
	 */
	IncludeHandler();

	/**
	 * @param _yylexptr - Pointer to the yylex()-style function to call.
	 * @param _yytext - Reference to the cstring containing each token's raw text.
	 * @param _yyleng - Reference to the length of each token's raw text.
	 * @param _yylval - Reference to the lexer's yylval variable/union that should be filled with the semantic value of each token.
	 * @param _yylloc - Reference to the lexer's yylloc struct that should be populated with line and column information for each token.
	 * @param _flexeryylvalType - Reference to the lexer's flag for which member of YYSTYPE yylval is using for the given token.
	 * @return The number of errors encountered while handling include statements.
	 */
	int handleInclude(int (*_yylexptr)(), char *&_yytext, int &_yyleng, YYSTYPE &_yylval, YYLTYPE &_yylloc, flexerValueType &_flexeryylvalType);

	/**
	 * Destructor. Deallocates and clears out the contents of macros,
	 * along with all other attributes (as appropriate).
	 */
	
	virtual ~IncludeHandler();

protected:
	
	/**
	 * Sets curTokIter to the beginning of the lexer token stream and
	 * nextTokIter to just after curTokIter, if possible.
	 * @return True if curTokIter and nextTokIter are different, false if curTokIter == nextTokIter == end().
	 */
	bool restartTokens();

	/**
	 * Moves curTokIter and nextTokIter to the next tokens in the lexer token stream.
	 * @return True if there was another token to give to curTokIter, false if nextTokIter was already at end().
	 */
	bool getNextToken();

	/**
	 * Moves curTokIter and nextTokIter just past the next period found in the lexer token stream.
	 * Usually used to skip over unnecessary/erroneous bits of input.
	 */
	void skipToNextPeriod();

	/**
	 * Moves the current token iterator to the position specified, and safely
	 * sets the lookahead token iterator to just after the new position.
	 * @param newCurTokIter - The new token stream position to start the current token iterator at.
	 */
	void seekParserIterators(TokenStreamIterator newCurTokIter);

	/**
	 * Error reporting function. Called when a fatal situation is
	 * identified that prevents parsing from continuing or guarantees
	 * that the translation will fail.
	 * If macroossErr is empty, outputs a generic error notification,
	 * otherwise uses the contents of macroossErr.
	 * Always appends a newline, and resets the contents of macroossErr.
	 */
	void includeReportError();

	/**
	 * Adds a standard syntax error header to macroossErr to make it easier
	 * to report errors.
	 */
	void includeStartSyntaxError();

	/**
	 * Wrapper for error reporting function that outputs a generic "unexpected
	 * end of file" error.
	 * @param setParseError - If true, sets the parseError attribute to true in addition to reporting the error. Default true.
	 */
	void includeEOFError(bool setParseError);

	/**
	 * Wrapper for error reporting function that outputs a generic "file not found" error.
	 * @param fileName - Name of the file not found
	 * @param setParseError - If true, sets the parseError attribute to true in addition to reporting the error. Default true.
	 */
	void includeFileNotFoundError(std::string fileName, bool setParseError);

	TokenStreamIterator curTokIter; ///< Iterator to current token being examined during parsing.
	TokenStreamIterator nextTokIter; ///< Iterator to lookahead token to help disambiguate parsing.
	std::ostringstream includeossErr; ///< Used to form warning and error messages.
};

#endif
