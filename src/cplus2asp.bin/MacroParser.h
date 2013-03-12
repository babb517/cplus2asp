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


#ifndef MACROPARSER_H
#define MACROPARSER_H

#include <list>
#include <sstream>
#include <string>
#include <vector>

#include "ltsglobals.h"
class Token;
class Macro;

/**
 * Container class designed to hold a short stream of tokens corresponding to a numeric match region from a macro rule (e.g., "#2").
 */
class MacroPoundNumMatch
{
public:
	int index; ///< The integer of a match region (e.g., 2 if it was "#2").
	std::list<Token*> matchContents; ///< A copy of a portion of a token stream the match region corresponds to.
	TokenStreamIterator tempStart; ///< Adjusted during matching to point at the start of a match region's contents.
	TokenStreamIterator tempEnd; ///< Adjusted during matching to point just past the end of a match region's contents.
	TokenStreamIterator tempMacroStart; ///< During matching, points to the start of the match region's "#something" key in the macro pattern.
	TokenStreamIterator tempMacroEnd; ///< During matching, points just past the end of the match region's "#something" key in the macro pattern.
	
	/**
	 * Default constructor. Initializes all members to 0/blank/etc.
	 */
	MacroPoundNumMatch();
	
	/**
	 * Destructor. Deallocates contents of matchContents and clears the list.
	 */
	virtual ~MacroPoundNumMatch();
};

/**
 * Specialized parsing module designed to recognize and match/expand CCalc macro definitions.
 */
class MacroParser
{
public:
	std::list<Macro*> macros; ///< All macros the parser has found.
	int macroNumErrors; ///< Tracks how many errors the macro parser encounters.
	std::string macroFileName; ///< Tracks which file is currently being parsed.
	YYLTYPE macroTokenLoc; ///< Tracks the last known location of a valid token being parsed.
	bool parseError; ///< If true, the parser is in an error state, and should ignore the rest of whatever statement it's parsing.
	
	/**
	 * Default constructor. Ensures all attributes are 0/empty/NULL/etc.
	 */
	MacroParser();
	
	/**
	 * Attempts to find, parse, and expand all macros and macro-like
	 * constructs in the contents of lexerTokenStream's internal data structures.
	 * Potentially heavily modifies the lexerTokenStream's internal contents,
	 * so it is wise to avoid calling this method during any other process
	 * that expects the lexerTokenStream to have stateful behavior.
	 * @return 0 if parsing and expanding were successful, 1 on a failure (in keeping with bison-style parser conventions).
	 */
	int parseMacros();
	
	/**
	 * Destructor. Deallocates and clears out the contents of macros,
	 * along with all other attributes (as appropriate).
	 */
	virtual ~MacroParser();
	
protected:
	TokenStreamIterator curTokIter; ///< Iterator to current token being examined during parsing.
	TokenStreamIterator nextTokIter; ///< Iterator to lookahead token to help disambiguate parsing.
	std::ostringstream macroossErr; ///< Used to form warning and error messages.
	
	/**
	 * Acts as Phase 1 of macro expansion, searching for macro definitions
	 * and processing each as it finds them.
	 * Removes macro definitions from the token streams after storing them.
	 * @return -1 if any macro definitions are found, 0 if none are found, 1 on any critical failures or errors (e.g., File Not Found).
	 */
	int findMacros();
	
	/**
	 * Wanders through the lexer token stream looking for matches to the
	 * internally-stored macro definitions, performing expansions as it finds
	 * them. Does one full pass through the stream's contents, performing
	 * one set of expansions (i.e., doesn't necessarily exhaustively expand).
	 * @return -1 if at least one expansion was successfully performed, 0 if no expansions were made, 1 on a serious error.
	 */
	int expandMacros();
	
	/* Phase 1 (Definitions) recursive parser methods */
	
	/**
	 * Grammar production method for phase 1 (macro definition) parser that recognizes a tuple of macro definitions.
	 * @return A list of Macro objects representing valid macro definitions found in a macro declaration block.
	 */
	std::list<Macro*> parser_def_macro_tuple();
	
	/**
	 * Grammar production method for phase 1 (macro definition) parser that recognizes a single macro definition.
	 * @return A Macro object representing a valid macro definition.
	 * @note Currently recognizes the presence of a "where" clause in a macro definition, but flags it as unsupported and raises a parse error.
	 */
	Macro* parser_def_macro_definition();
	
	/**
	 * Grammar production method for phase 1 (macro definition) parser that recognizes a series of tokens.
	 * Used for the different parts of a macro definition, which (with some "key" token exceptions) can be pretty much anything of arbitrary length.
	 * @return A list of Token objects copied from the token stream that represent one of the clauses of a macro definition.
	 */
	std::list<Token*> parser_def_macro_tokens();
	
	/* Phase 2 (Expansion) helper methods */
	
	/**
	 * Checks a macro against a region of token stream input to see if the macro's pattern matches part of the token stream region.
	 * Assumes inputStart must be the start of the macro match, but allows an arbitrary amount of the rest of the input (up to inputEnd) to be part of the match.
	 * Returns specific match information as reference parameters.
	 * @param macro - [In] The macro to use when checking for a match.
	 * @param inputStart - [In] Where to start the matching process in the input.
	 * @param inputEnd - [In] An iterator representing the end() of the input region to check, i.e., one past the last token to check.
	 * @param matchStart - [Out] Populated with where the start of the match was actually found. Should be equal to inputStart.
	 * @param matchEnd - [Out] Populated with an iterator pointing just past the last token that matched the macro's pattern.
	 * @param poundNumMatches - [Out] Populated with any MacroPoundNumMatch objects created as part of matching the macro's pattern to the input.
	 * @return True if a match is found, false otherwise.
	 */
	bool checkForMacroExpandMatch(Macro &macro, TokenStreamIterator inputStart, TokenStreamIterator inputEnd, TokenStreamIterator &matchStart, TokenStreamIterator &matchEnd, std::vector<MacroPoundNumMatch*> &poundNumMatches);
	
	/**
	 * Rewinds a "cur/next" pair of input stream token iterators one step backward, until curInput becomes inputStart.
	 * Ensures that if cur/next were pointing at different tokens before this method, they still will
	 * be at the end (i.e., nextInput will never point at inputStart unless it already was).
	 * @param curInput - The "current token" stream iterator.
	 * @param nextInput - The "next token" stream iterator.
	 * @param inputStart - The first token of the token stream (i.e., begin()).
	 * @return True if both tokens could go backward successfully, false otherwise.
	 */
	bool previousInputTokens(TokenStreamIterator &curInput, TokenStreamIterator &nextInput, TokenStreamIterator inputStart);
	
	/**
	 * Moves a "cur/next" pair of input stream token iterators one step forward, until curInput becomes inputEnd.
	 * Stops moving forward once curInput points at inputEnd (& prevents nextInput from wandering past inputEnd).
	 * @param curInput - The "current token" stream iterator.
	 * @param nextInput - The "next token" stream iterator.
	 * @param inputEnd - The end of the token stream (i.e., end()).
	 * @return True if nextInput could go forward successfully, false if it was already at inputEnd.
	 */
	bool nextInputTokens(TokenStreamIterator &curInput, TokenStreamIterator &nextInput, TokenStreamIterator inputEnd);
	
	/**
	 * Moves a "cur/next" pair of input stream token iterators to seekPos and one past seekPos (respectively).
	 * Ensures "next" iterator won't wander past inputEnd.
	 * @param curInput - The "current token" stream iterator.
	 * @param nextInput - The "next token" stream iterator.
	 * @param inputEnd - The end of the token stream (i.e., end()).
	 * @param seekPos - The iterator position where curInput should end up.
	 */
	void seekInputTokens(TokenStreamIterator &curInput, TokenStreamIterator &nextInput, TokenStreamIterator inputEnd, TokenStreamIterator seekPos);
	
	/**
	 * Starting from curInput, looks for a closing parenthesis/bracket that signals the end of the parenthesis/bracket nesting level curInput currently sits in.
	 * If curInput isn't nested in any parentheses/brackets, inputEnd will be returned.
	 * @param curInput - An iterator to the input stream location to start looking.
	 * @param inputEnd - The end of the given input stream.
	 * @return An iterator pointing to the parenthesis ending curInput's nested parenthesis/bracket level, or inputEnd if it couldn't be found.
	 */
	TokenStreamIterator findEndParen(TokenStreamIterator &curInput, TokenStreamIterator inputEnd);
	
	/**
	 * Reduce the size of the last match region by 1, rolling back to previous region(s) if that would empty any of them.
	 * Moves cur/nextInput and cur/nextMacroInput to appropriate new (sane) locations to continue matching.
	 * @param curInput - The "current token" input stream iterator.
	 * @param nextInput - The "next token" input stream iterator.
	 * @param inputStart - An iterator to the first token of the token stream (i.e., begin()).
	 * @param inputEnd - An iterator just past the last token of the token stream (i.e., end()).
	 * @param curMacroInput - The "current token" macro pattern iterator.
	 * @param nextMacroInput - The "next token" macro pattern iterator.
	 * @param macroStart - An iterator to the first token of the macro pattern stream (i.e., begin()).
	 * @param macroEnd - An iterator just past the last token of the macro pattern stream (i.e., end()).
	 * @param matchRegions - The data structure holding the records of all match regions.
	 * @return True if the shrink operation was successful, false if it was not possible to shrink the regions any more.
	 */
	bool shrinkMatchRegions(TokenStreamIterator &curInput, TokenStreamIterator &nextInput, TokenStreamIterator inputStart, TokenStreamIterator inputEnd, TokenStreamIterator &curMacroInput, TokenStreamIterator &nextMacroInput, TokenStreamIterator macroStart, TokenStreamIterator macroEnd, std::vector<MacroPoundNumMatch*> &matchRegions);
	
	/**
	 * Changes a series of tokens' locations to be newLoc and changes their origin file names as well (in math notation, [first, last)).
	 * Used during expansion to keep locations & file names as useful as possible for error reporting purposes.
	 * @param first - An iterator to the first token to override with new information.
	 * @param last - An iterator just past the last token to override with new information.
	 * @param newLoc - A YYLTYPE struct containing new location info for the tokens.
	 * @param newFileName - A string containing the new "origin" file name for the tokens.
	 */
	void overrideTokenInfo(TokenStreamIterator first, TokenStreamIterator last, YYLTYPE newLoc, std::string newFileName);
	
	/**
	 * Evaluates the where clause of a macro to determine if a particular expansion should take place.
	 * @note This is currently a stub that does no evaluation and always returns true.
	 * @param macro - The macro whose where clause should be evaluated.
	 * @param matchRegions - The contents of any "#something" regions that were matched for a particular potential expansion.
	 * @return True if the where clause's contents evaluate to true (or otherwise successfully evaluate), false if they don't.
	 */
	bool evalMacroWhereClause(Macro &macro, std::vector<MacroPoundNumMatch*> &matchRegions);
	
	/* General helper methods */
	
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
	 * Starting from the position of tsIter, finds the next period (".") in
	 * that token stream, returning its position (or tsEnd).
	 * @param tsIter - The position in the token stream to start looking.
	 * @param tsEnd - An iterator representing the end of that token stream (i.e., when to stop looking).
	 * @return An iterator pointing to the next period in the token stream, or tsEnd if it was encountered first (i.e., no period found).
	 */
	TokenStreamIterator findNextPeriod(TokenStreamIterator tsIter, TokenStreamIterator tsEnd);
	
	/**
	 * Moves the current token iterator to the position specified, and safely
	 * sets the lookahead token iterator to just after the new position.
	 * @param newCurTokIter - The new token stream position to start the current token iterator at.
	 */
	void seekParserIterators(TokenStreamIterator newCurTokIter);
	
	/**
	 * Adds a standard parsing warning header to macroossErr to make warning
	 * notifications easier to pinpoint.
	 */
	void macroStartWarning();
	/**
	 * Warning reporting function. Called when a non-fatal situation is
	 * identified that will probably produce unexpected/undesired translation
	 * results.
	 * If macroossErr is empty, outputs a generic warning notification,
	 * otherwise uses the contents of macroossErr.
	 * Always appends a newline, and resets the contents of macroossErr.
	 */
	void macroReportWarning();
	/**
	 * Adds a standard parse error header to macroossErr to make it easier
	 * to report errors.
	 */
	void macroStartParseError();
	/**
	 * Adds a standard syntax error header to macroossErr to make it easier
	 * to report errors.
	 */
	void macroStartSyntaxError();
	/**
	 * Error reporting function. Called when a fatal situation is
	 * identified that prevents parsing from continuing or guarantees
	 * that the translation will fail.
	 * If macroossErr is empty, outputs a generic error notification,
	 * otherwise uses the contents of macroossErr.
	 * Always appends a newline, and resets the contents of macroossErr.
	 */
	void macroReportError();
	
	/**
	 * Wrapper for error reporting function that outputs a generic "unexpected
	 * end of file" error.
	 * @param setParseError - If true, sets the parseError attribute to true in addition to reporting the error. Default true.
	 */
	void macroEOFError(bool setParseError=true);
};

#endif
