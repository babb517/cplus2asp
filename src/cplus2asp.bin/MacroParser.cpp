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


#include <list>
#include <sstream>
#include <string>
#include <vector>

#include "types.h"
#include "DataStructs/Macro.h"
#include "DataStructs/Token.h"
#include "lexerTokenStream.h"
#include "utilities.h"

#include "MacroParser.h"

#include "Translator.h"
#include "parser.h"

extern Translator* mainTrans; ///< The main translator module, declared in the main parser.

// Constructor of MacroPoundNumMatch.
MacroPoundNumMatch::MacroPoundNumMatch()
{
	index = 0;
}

// Destructor for MacroPoundNumMatch.
MacroPoundNumMatch::~MacroPoundNumMatch()
{
	for(TokenStreamIterator tsIter = matchContents.begin(); tsIter != matchContents.end(); ++tsIter)
	{
		delete *tsIter;
		(*tsIter) = NULL;
	}
	matchContents.clear();
}

// Default constructor.
MacroParser::MacroParser()
{
	curTokIter = nextTokIter = ltsyyLexer::streamEnd();
	macroossErr.str("");
	macroNumErrors = 0;
	macroFileName = "";
	macroTokenLoc.first_line = macroTokenLoc.last_line = macroTokenLoc.first_column = macroTokenLoc.last_column = 0;
	parseError = false;
}

// Attempts to find, parse, and expand all macros and macro-like constructs in the contents of lexerTokenStream's internal data structures.
int MacroParser::parseMacros()
{
	int retVal = 0; // Start optimistic.
	int parseResult = 0;
	// First, make sure there's something to parse and try to find ":- macros..." definitions.
	do
	{
		if(this->restartTokens())
		{
			parseResult = this->findMacros();
		}
		else
		{
			parseResult = 0;
		}
	}while(parseResult < 0);
	// Second, repeatedly perform macro expansion until no more expansions can be made.
	if(parseResult < 1)
	{
		do
		{
			if(!this->restartTokens())
			{	// If we somehow run out of things to parse, just stop.
				break;
			}
			parseResult = this->expandMacros();
		}while(parseResult < 0);
		if(parseResult > 0)
		{	// Something important went wrong during macro expansion, send the message upward.
			retVal = 1;
		}
	}
	else
	{	// Something important went wrong during the first phase, stop.
		retVal = 1;
	}
	return retVal;
}

// Acts as Phase 1 of macro expansion, searching for macro definitions and processing each as it finds them.
int MacroParser::findMacros()
{
	int retVal = 0; // Start optimistic, assuming we won't find any definitions.
	std::list<Macro*> lstMacroDef; // Used to capture return value from the macro definition processing function.
	TokenStreamIterator macroDefStart, macroDefEnd; // Records the positions in the token stream where a macro definition started and ended (for later removal purposes).
	
	// This acts as the parser's "base" state, looking for macro definitions.
	// Look for grammar rules of the form "T_COLON_DASH T_MACROS parser_def_macro_tuple T_PERIOD", ignores anything else.
	// We know we need >= 2 tokens for a macro definition, so it's fine to check if either cur or next token is end-of-stream.
	while(curTokIter != ltsyyLexer::streamEnd() && (*curTokIter)->tokenID != END && nextTokIter != ltsyyLexer::streamEnd() && retVal <= 0)
	{
		// For efficiency, check for any declaration section (so we can skip over it entirely if it isn't a macros section).
		if((*curTokIter)->tokenID == T_COLON_DASH)
		{
			if((*nextTokIter)->tokenID == T_MACROS)
			{
				macroDefStart = curTokIter; // Remember this ":-" to remove it later.
				this->getNextToken();
				this->getNextToken();
				lstMacroDef = this->parser_def_macro_tuple();
				if(this->parseError == true)
				{	// If a parse error occurred somewhere during macro parsing, kill the contents of lstMacroDef and just move on.
					this->macroNumErrors++;
					utils::deallocateListContents(lstMacroDef);
					this->skipToNextPeriod();
					this->parseError = false;
				}
				else
				{
					// Expect to find a period after a successful macro definition. If not, throw an error.
					if(curTokIter != ltsyyLexer::streamEnd() && (*curTokIter)->tokenID == T_PERIOD)
					{
						// Add the newly defined macros to our list, set that we found a macro definition.
						this->macros.insert(this->macros.end(), lstMacroDef.begin(), lstMacroDef.end());
						lstMacroDef.clear();
						retVal = -1;
						this->getNextToken();
					}
					else
					{
						if(curTokIter == ltsyyLexer::streamEnd() || (*curTokIter)->tokenID == END)
						{	// Unexpected EOF. Don't set parseError, we're already in base state.
							this->macroNumErrors++;
							this->macroEOFError(false);
						}
						else
						{	// Unexpected token, just use the default error message.
							this->macroNumErrors++;
							this->macroReportError();
							this->skipToNextPeriod();
						}
					}
				}
				// We found a macros section. Even if we encountered errors, erase it from the token stream so the real parser doesn't throw erroneous errors about ":- macros" being unexpected.
				macroDefEnd = curTokIter;
				this->seekParserIterators(ltsyyLexer::lexEraseFromTokenStream(macroDefStart, macroDefEnd));
			}
			else
			{	// This declaration (whatever it is) is of no interest, skip it.
				this->skipToNextPeriod();
			}
		}
		else
		{	// We aren't at the start of a declaration, keep moving forward one token at a time.
			this->getNextToken();
		}
	}
	
	return retVal;
}

// Wanders through the lexer token stream looking for matches to the internally-stored macro definitions, performing expansions as it finds them.
int MacroParser::expandMacros()
{
	int retVal = 0; // Start assuming that no expansions will be found/made.
	
	// Optimization check: did we even find any macros to expand?
	if(!this->macros.empty())
	{
		// For each macro, go through all input trying to match it.
		std::list<Macro*>::iterator mIter;
		TokenStreamIterator matchStart, matchEnd;
		TokenStreamIterator macroTokIter, macroNextTokIter;
		TokenStreamIterator nextPeriodIter;
		std::vector<MacroPoundNumMatch*> poundNumMatches;
		
		for(mIter = this->macros.begin(); mIter != this->macros.end(); ++mIter)
		{
			// Reset all the macro-specific stuff.
			macroNextTokIter = macroTokIter = (*mIter)->pattern.begin();
			if(macroNextTokIter != (*mIter)->pattern.end())
			{
				++macroNextTokIter;
			}
			for(this->restartTokens(); this->curTokIter != ltsyyLexer::streamEnd(); /* Intentionally empty */)
			{
				// Check for macro matches.
				if((*curTokIter)->contentsEqual(*(*macroTokIter)) || ((*macroTokIter)->tokenID == T_POUND && macroNextTokIter != (*mIter)->pattern.end() && (*macroNextTokIter)->tokenID == T_INTEGER))
				{	// We may have found a match, start checking.
					for(size_t i = 0; i < poundNumMatches.size(); i++)
					{
						delete poundNumMatches[i];
					}
					poundNumMatches.clear();
					nextPeriodIter = this->findNextPeriod(curTokIter, ltsyyLexer::streamEnd());
					if(checkForMacroExpandMatch(*(*mIter), curTokIter, nextPeriodIter, matchStart, matchEnd, poundNumMatches) && this->evalMacroWhereClause(*(*mIter), poundNumMatches))
					{	// Match found, expand the macro.
						
						// Create a composite file name and location that encompasses the complete matched region.
						std::string matchFileName = (*matchStart)->tokenFileName;
						TokenStreamIterator tempMatchLocEnd = matchEnd;
						if(tempMatchLocEnd != ltsyyLexer::streamBegin())
						{
							--tempMatchLocEnd;
						}
						YYLTYPE matchLoc;
						matchLoc.first_line = (*matchStart)->tokenLocation.first_line;
						matchLoc.first_column = (*matchStart)->tokenLocation.first_column;
						matchLoc.last_line = (*tempMatchLocEnd)->tokenLocation.last_line;
						matchLoc.last_column = (*tempMatchLocEnd)->tokenLocation.last_column;
						// Remove the text that matched the macro pattern.
						matchEnd = ltsyyLexer::lexEraseFromTokenStream(matchStart, matchEnd);
						// Create a copy of the macro expansion result and replace the matched text with that.
						std::list<Token*> tempMacroExpansion;
						Token *tempExpansionToken = NULL;
						for(TokenStreamIterator sIter = (*mIter)->result.begin(); sIter != (*mIter)->result.end(); ++sIter)
						{
							tempExpansionToken = new Token();
							(*tempExpansionToken) = *(*sIter);
							tempMacroExpansion.push_back(tempExpansionToken);
							tempExpansionToken = NULL;
						}
						matchStart = ltsyyLexer::insert(matchEnd, tempMacroExpansion.begin(), tempMacroExpansion.end());
						tempMacroExpansion.clear();
						// Override the macro's original token locations with a composite location representing the original replaced region's location.
						this->overrideTokenInfo(matchStart, matchEnd, matchLoc, matchFileName);
						// Go through the replaced result, replacing any "#something" instances with appropriate sequences from poundNumMatches.
						TokenStreamIterator matchIter, matchNextIter;
						for(this->seekInputTokens(matchIter, matchNextIter, matchEnd, matchStart); matchIter != matchEnd; this->nextInputTokens(matchIter, matchNextIter, matchEnd))
						{
							if((*matchIter)->tokenID == T_POUND && matchNextIter != matchEnd && (*matchNextIter)->tokenID == T_INTEGER)
							{	// Found a "#something", replace it with the appropriate content from poundNumMatches.
								MacroPoundNumMatch *tempMatch = NULL;
								for(size_t i = 0; i < poundNumMatches.size(); i++)
								{
									if(poundNumMatches[i]->index == (*matchNextIter)->tokenValue.integer)
									{
										tempMatch = poundNumMatches[i];
										break;
									}
								}
								if(tempMatch != NULL)
								{
									std::list<Token*> tempStream;
									Token *tempToken = NULL;
									for(TokenStreamIterator sIter = tempMatch->matchContents.begin(); sIter != tempMatch->matchContents.end(); ++sIter)
									{	// Copy the match region's contents (they'll be deallocated later, so we need a fresh copy).
										tempToken = new Token();
										(*tempToken) = *(*sIter);
										tempStream.push_back(tempToken);
										tempToken = NULL;
									}
									TokenStreamIterator tempEnd = matchNextIter;
									++tempEnd; // Move just past the "something" in "#something" in preparation to remove it from the token stream.
									tempEnd = ltsyyLexer::lexEraseFromTokenStream(matchIter, tempEnd);
									TokenStreamIterator tempStart = ltsyyLexer::insert(tempEnd, tempStream.begin(), tempStream.end());
									// Seek the wandering iterators to the beginning of the insertion in case there are other "#something"s in the replacement stream that need expansion as well.
									this->seekInputTokens(matchIter, matchNextIter, matchEnd, tempStart);
									tempStream.clear();
									tempMatch = NULL;
								}
							}
						}
						// Clear out poundNumMatches now that we're done using it.
						for(size_t i = 0; i < poundNumMatches.size(); i++)
						{
							delete poundNumMatches[i];
						}
						poundNumMatches.clear();
						// Move to the end of the expansion to continue on.
						this->seekParserIterators(matchEnd);
						retVal = -1; // Found at least one macro to expand.
					}
					else
					{	// False alarm, just grab the next token and keep looking.
						this->getNextToken();
					}
				}
				else
				{	// No match, grab the next token.
					this->getNextToken();
				}
			}
		}
	}
	
	return retVal;
}

/* PHASE 1 (DEFINITIONS) RECURSIVE PARSER METHODS */

// Expects to be able to find and process one or more macro definitions, returns them as a list.
// parser_def_macro_tuple:   parser_def_macro_definition T_SEMICOLON parser_def_macro_tuple
//                         | parser_def_macro_definition
std::list<Macro*> MacroParser::parser_def_macro_tuple()
{
	std::list<Macro*> retVal, tempMacroList;
	Macro* tempMacro = NULL; // Grabs return value from calls to macro definition parse method.
	
	if(curTokIter != ltsyyLexer::streamEnd() && nextTokIter != ltsyyLexer::streamEnd())
	{
		if(((*curTokIter)->tokenID == T_PERIOD || (*curTokIter)->tokenID == T_SEMICOLON) && retVal.empty())
		{	// An empty macro definition, an error.
			this->parseError = true;
			this->macroStartSyntaxError();
			this->macroossErr << "Empty macro definition.";
			this->macroReportError();
		}
		else
		{	// Try getting a macro definition.
			tempMacro = parser_def_macro_definition();
			if(tempMacro != NULL)
			{
				// Check if it's an old maxAdditive declaration ("maxAdditive -> something").
				if(tempMacro->pattern.size() == 1 && (*(tempMacro->pattern.begin()))->stringValue.compare("maxAdditive") == 0)
				{	// It's a maxAdditive definition. Don't store this macro, immediately output a "hint" comment instead.
					std::ostringstream ossMaxAdd("");
					ossMaxAdd << "% [MaxAdditive:";
					for(TokenStreamIterator sIter = tempMacro->result.begin(); sIter != tempMacro->result.end(); ++sIter)
					{
						ossMaxAdd << (*sIter)->stringValue;
					}
					ossMaxAdd << "]";
					std::string maxAddOut = ossMaxAdd.str();
					mainTrans->output(maxAddOut, IPART_NONE, true);
					ossMaxAdd.str("");
					delete tempMacro;
				}
				else
				{	// Just a normal macro definition, add it.
					retVal.push_back(tempMacro);
				}
				tempMacro = NULL;
			}
		}
		if(this->parseError == true)
		{	// If we ran into trouble getting the macro definition, clear out the return contents and stop parsing.
			utils::deallocateListContents(retVal);
		}
		else
		{
			if((*curTokIter)->tokenID == T_PERIOD)
			{	// We've verified we found at least one valid macro definition, this is the end of a legit macro definition section.
				// Intentionally empty.
			}
			else if((*curTokIter)->tokenID == T_SEMICOLON)
			{	// A semicolon indicates there should be at least one more macro definition after it. recursively call this function to grab them.
				this->getNextToken();
				tempMacroList = this->parser_def_macro_tuple();
				retVal.insert(retVal.end(), tempMacroList.begin(), tempMacroList.end());
				tempMacroList.clear();
				if(this->parseError == true)
				{	// Clear out our return value if the sub-method call had problems.
					utils::deallocateListContents(retVal);
				}
			}
			else
			{	// Whatever this token is, it's wrong. Let the error reporter give a general error.
				utils::deallocateListContents(retVal);
				this->parseError = true;
				this->macroReportError();
			}
		}
	}
	
	return retVal;
}

// Expects to parse and process one complete macro definition.
// parser_def_macro_definition:   ANY_TOKEN+ T_ARROW_RDASH ANY_TOKEN+ where ANY_TOKEN+
//                              | ANY_TOKEN+ T_ARROW_RDASH ANY_TOKEN+
Macro* MacroParser::parser_def_macro_definition()
{
	Macro* retVal = NULL;
	std::list<Token*> tempTokens; // Captures return value from the "any_token+" gathering method.
	
	// Initial "sanity checks" to ensure we don't have an obviously malformed macro definition.
	if(curTokIter == ltsyyLexer::streamEnd())
	{	// Unexpected EOF.
		this->macroEOFError();
	}
	else if((*curTokIter)->tokenID == T_PERIOD)
	{	// An empty and invalid macro definition.
		this->parseError = true;
		this->macroStartSyntaxError();
		this->macroossErr << "Empty macro definition.";
		this->macroReportError();
	}
	else if((*curTokIter)->tokenID == T_ARROW_RDASH)
	{	// Probably an invalid macro definition that doesn't have a pattern (e.g., "-> F.")
		this->parseError = true;
		this->macroStartSyntaxError();
		this->macroossErr << "Empty macro search pattern.";
		this->macroReportError();
	}
	else if((*curTokIter)->tokenID == T_WHERE)
	{	// An invalid macro definition that is a where clause without an associated macro.
		this->parseError = true;
		this->macroStartSyntaxError();
		this->macroossErr << "Found a where clause in macros without an accompanying macro definition (did a \".\" or \";\" end up somewhere it shouldn't?).";
		this->macroReportError();
	}
	else
	{	// Passed all the sanity checks, try grabbing a macro definition.
		retVal = new Macro();
		// A macro definition starts with a pattern of arbitrary length.
		tempTokens = parser_def_macro_tokens();
		if(this->parseError == false && !tempTokens.empty())
		{	// Ensure a "->" token follows the pattern.
			if(curTokIter != ltsyyLexer::streamEnd() && (*curTokIter)->tokenID == T_ARROW_RDASH)
			{	// Valid so far, save the pattern and try finding a transform result.
				retVal->pattern = tempTokens;
				tempTokens.clear();
				this->getNextToken();
				tempTokens = parser_def_macro_tokens();
				if(this->parseError == false && !tempTokens.empty())
				{	// Check for what follows the transform result, take action accordingly.
					if(curTokIter != ltsyyLexer::streamEnd())
					{
						if((*curTokIter)->tokenID == T_SEMICOLON || (*curTokIter)->tokenID == T_PERIOD)
						{	// End of a valid macro definition, save the transform result.
							retVal->result = tempTokens;
							tempTokens.clear();
						}
						else if((*curTokIter)->tokenID == T_WHERE)
						{	// Macro definition includes a where clause, save it for later evaluation.
							// Where clauses are normally valid in CCalc, but we don't support the "where" clause in macros yet. Warn about potential unexpected behavior.
							this->macroStartWarning();
							this->macroossErr << "Evaluation of the \"where\" clause in macro definitions is not supported yet, this macro will be handled as though it had no where clause.";
							this->macroReportWarning();
							// Save the transform result before we grab the where clause.
							retVal->result = tempTokens;
							tempTokens.clear();
							// Go get the where clause.
							this->getNextToken();
							tempTokens = parser_def_macro_tokens();
							if(this->parseError == false && !tempTokens.empty())
							{	// Check what follows the where clause, take actions accordingly.
								if(curTokIter != ltsyyLexer::streamEnd())
								{
									if((*curTokIter)->tokenID == T_SEMICOLON || (*curTokIter)->tokenID == T_PERIOD)
									{	// End of a valid macro definition, save the where clause.
										retVal->where = tempTokens;
										tempTokens.clear();
									}
									else
									{	// Something's wrong with the syntax, report an appropriate error.
										this->parseError = true;
										// General unexpected token.
										this->macroReportError();
									}
								}
								else
								{	// Unexpected EOF.
									this->macroEOFError();
								}
							}
							else
							{	// Something went wrong, ensure we set the parse error flag.
								this->parseError = true;
							}
						}
						else
						{	// Something's wrong with the syntax, report an appropriate error.
							this->parseError = true;
							// General unexpected token.
							this->macroReportError();
						}
					}
					else
					{	// Unexpected EOF.
						this->macroEOFError();
					}
				}
				else
				{	// Something went wrong, ensure we set the parse error flag.
					this->parseError = true;
				}
			}
			else
			{	// Something's wrong with the syntax, report an error.
				if(curTokIter == ltsyyLexer::streamEnd())
				{	// Unexpected end of file.
					this->macroEOFError();
				}
				else
				{	// General unexpected token.
					this->parseError = true;
					this->macroReportError();
				}
			}
		}
		else
		{	// Something went wrong, ensure we set the parse error flag.
			this->parseError = true;
		}
	}
	
	// If we encountered a parse error at any point in the process above, destroy the return value contents.
	if(this->parseError == true)
	{
		utils::deallocateListContents(tempTokens);
		if(retVal != NULL)
		{
			delete retVal;
			retVal = NULL;
		}
	}
	
	return retVal;
}

// Saves arbitrary tokens from the token stream until it hits a "key" token ("->", "where", ";", or ".") not encased in parentheses.
std::list<Token*> MacroParser::parser_def_macro_tokens()
{
	std::list<Token*> retVal;
	int curParenDepth = 0, curBracketDepth = 0; // Tracks how many unclosed parentheses/brackets we've found to be sure we only react to "key" tokens when we're supposed to.
	Token* tempToken = NULL; // Used to create copies of the token stream's tokens.
	
	while(curTokIter != ltsyyLexer::streamEnd())
	{
		// If this is a "key" token at parenthesis level 0, stop gathering tokens and return what we've got.
		if(curParenDepth == 0)
		{
			if((*curTokIter)->tokenID == T_ARROW_RDASH || (*curTokIter)->tokenID == T_WHERE || (*curTokIter)->tokenID == T_SEMICOLON || (*curTokIter)->tokenID == T_PERIOD)
			{
				break;
			}
		}
		// Copy this token and save its copy into the return list.
		tempToken = new Token();
		(*tempToken) = *(*curTokIter);
		retVal.push_back(tempToken);
		tempToken = NULL;
		// Check for parentheses, update curParenDepth accordingly.
		if((*curTokIter)->tokenID == T_PAREN_L)
		{
			curParenDepth++;
		}
		else if((*curTokIter)->tokenID == T_PAREN_R)
		{
			// Sanity check: does this right paren have a left paren buddy?
			if(curParenDepth > 0)
			{
				curParenDepth--;
			}
			else
			{	// Unmatched parenthesis error: too many right parentheses.
				this->parseError = true;
				this->macroStartSyntaxError();
				this->macroossErr << "Unmatched \")\" parenthesis in macro definition.";
				this->macroReportError();
				break;
			}
		}
		// Brackets aren't used to "hide" key tokens, but still check for mismatches while we're here.
		if((*curTokIter)->tokenID == T_BRACKET_L)
		{
			curBracketDepth++;
		}
		else if((*curTokIter)->tokenID == T_BRACKET_R)
		{
			// Sanity check: does this right bracket have a left bracket buddy?
			if(curBracketDepth > 0)
			{
				curBracketDepth--;
			}
			else
			{	// Unmatched bracket error: too many right brackets.
				this->parseError = true;
				this->macroStartSyntaxError();
				this->macroossErr << "Unmatched \"]\" bracket in macro definition.";
				this->macroReportError();
				break;
			}
		}
		this->getNextToken();
	}
	// Last error check: did every parenthesis and bracket have a match?
	if(curParenDepth > 0)
	{
		this->parseError = true;
		this->macroStartSyntaxError();
		this->macroossErr << "Unmatched \"(\" parenthesis in macro definition.";
		this->macroReportError();
	}
	if(curBracketDepth > 0)
	{
		this->parseError = true;
		this->macroStartSyntaxError();
		this->macroossErr << "Unmatched \"[\" bracket in macro definition.";
		this->macroReportError();
	}
	// If we ran into a parse error, destroy the return value contents.
	if(this->parseError == true)
	{
		utils::deallocateListContents(retVal);
	}
	// No need to report an error on EOF or empty retVal, parent grammar rule handles that for us.
	return retVal;
}

/* PHASE 2 (EXPANSION) HELPER METHODS */

// Checks if the given macro matches the input starting at inputStart and potentially ranging to inputEnd.
bool MacroParser::checkForMacroExpandMatch(Macro &macro, TokenStreamIterator inputStart, TokenStreamIterator inputEnd, TokenStreamIterator &matchStart, TokenStreamIterator &matchEnd, std::vector<MacroPoundNumMatch*> &poundNumMatches)
{
	bool retVal = false; // Start pessimistic.
	
	matchStart = inputStart;
	matchEnd = inputEnd;
	
	// Quick sanity check: is there any input to check?
	if(inputStart != inputEnd)
	{
		TokenStreamIterator curMacroInput, nextMacroInput, macroStart, macroEnd;
		TokenStreamIterator curInput, nextInput;
		
		macroStart = macro.pattern.begin();
		macroEnd = macro.pattern.end();
		nextMacroInput = curMacroInput = macroStart;
		if(nextMacroInput != macroEnd)
		{
			++nextMacroInput;
		}
		
		nextInput = curInput = inputStart;
		++nextInput;
		
		MacroPoundNumMatch *tempMatchRegion = NULL;
		
		while(true)
		{
			while(curMacroInput != macroEnd && curInput != inputEnd)
			{
				if((*curMacroInput)->tokenID == T_POUND && nextMacroInput != macroEnd && (*nextMacroInput)->tokenID == T_INTEGER)
				{	// Found a "#something" key in the macro pattern, greedy match the rest of input and see if that works.
					tempMatchRegion = new MacroPoundNumMatch();
					tempMatchRegion->index = (*nextMacroInput)->tokenValue.integer;
					tempMatchRegion->tempStart = curInput;
					tempMatchRegion->tempEnd = this->findEndParen(curInput, inputEnd);
					if(tempMatchRegion->tempStart == tempMatchRegion->tempEnd)
					{	// Sanity check: If we immediately run into an end parenthesis (i.e., empty region), we need to try shrinking.
						delete tempMatchRegion;
						tempMatchRegion = NULL;
						// Breaking out of this loop will auto-engage the shrinking routine.
						break;
					}
					tempMatchRegion->tempMacroStart = curMacroInput;
					tempMatchRegion->tempMacroEnd = nextMacroInput;
					++(tempMatchRegion->tempMacroEnd); // Move just past "#something"'s integer.
					this->seekInputTokens(curInput, nextInput, inputEnd, tempMatchRegion->tempEnd); // Also move current input past the greedy grab.
					poundNumMatches.push_back(tempMatchRegion);
					tempMatchRegion = NULL;
					this->nextInputTokens(curMacroInput,nextMacroInput,macroEnd);
					this->nextInputTokens(curMacroInput,nextMacroInput,macroEnd);
				}
				else if((*curMacroInput)->contentsEqual(*(*curInput)))
				{	// If both the current macro token and current input token match, move both forward.
					this->nextInputTokens(curMacroInput, nextMacroInput, macroEnd);
					this->nextInputTokens(curInput, nextInput, inputEnd);
				}
				else
				{	// There's a mismatch, try shrinking applicable match regions and seeing if that helps things.
					// If we break out of this loop, the checks below will auto-engage the shrinking process.
					break;
				}
			}
			
			if(curMacroInput == macroEnd)
			{	// If the macro ran out of tokens, then we have a match on the input.
				// Last check: if there were duplicate "#something"s in the matched pattern, are their contents all the same?
				bool goodDuplicates = true; // Start optimistic.
				for(size_t i = 0; i < poundNumMatches.size(); i++)
				{
					for(size_t j = i + 1; j < poundNumMatches.size(); j++)
					{
						if(poundNumMatches[i]->index == poundNumMatches[j]->index)
						{
							TokenStreamIterator iIter = poundNumMatches[i]->tempStart;
							TokenStreamIterator jIter = poundNumMatches[j]->tempStart;
							while(iIter != poundNumMatches[i]->tempEnd && jIter != poundNumMatches[j]->tempEnd)
							{
								if(!(*iIter)->contentsEqual(*(*jIter)))
								{	// If any "parallel" tokens aren't the same, the regions aren't equal.
									goodDuplicates = false;
									break;
								}
								++iIter;
								++jIter;
							}
							if(iIter != poundNumMatches[i]->tempEnd || jIter != poundNumMatches[j]->tempEnd)
							{	// If either region didn't get to the end, they aren't equal.
								goodDuplicates = false;
							}
						}
						if(!goodDuplicates)
						{	// If we already know there's at least one mismatch, don't bother checking the rest.
							break;
						}
					}
					if(!goodDuplicates)
					{	// If we already know there's at least one mismatch, don't bother checking the rest.
						break;
					}
				}
				if(goodDuplicates)
				{	// If everything matched, then we have a true match!
					matchEnd = curInput;
					retVal = true;
				}
				break; // Match or no, we're at the end of processing.
			}
			else
			{	// If the macro had tokens left, try shrink match regions and retry if there are any left to shrink.
				if(!this->shrinkMatchRegions(curInput, nextInput, inputStart, inputEnd, curMacroInput, nextMacroInput, macroStart, macroEnd, poundNumMatches))
				{	// There was nothing left to shrink, this macro is not a match.
					break;
				}
			}
		}
	}
	
	// On a match, take all the numeric matched regions and copy their final matched tokens (so when the input changes during expansion the original tokens aren't lost).
	if(retVal == true)
	{
		for(size_t i = 0; i < poundNumMatches.size(); i++)
		{
			TokenStreamIterator iIter;
			Token *tempTok = NULL;
			for(iIter = poundNumMatches[i]->tempStart; iIter != poundNumMatches[i]->tempEnd; ++iIter)
			{
				tempTok = new Token();
				(*tempTok) = *(*iIter);
				poundNumMatches[i]->matchContents.push_back(tempTok);
				tempTok = NULL;
			}
		}
	}
	else
	{	// On a failed match, deallocate the contents of poundNumMatches.
		for(size_t i = 0; i < poundNumMatches.size(); i++)
		{
			delete poundNumMatches[i];
		}
		poundNumMatches.clear();
		matchStart = matchEnd = inputEnd; // Appropriate "we found nothing" values.
	}
	
	return retVal;
}

// Rewinds a "cur/next" pair of input stream tokens one step backward, until curInput becomes inputStart.
bool previousInputTokens(TokenStreamIterator &curInput, TokenStreamIterator &nextInput, TokenStreamIterator inputStart)
{
	bool retVal = true;
	if(curInput != inputStart)
	{
		nextInput = curInput;
		--curInput;
	}
	else
	{
		retVal = false;
	}
	return retVal;
}

// Moves a "cur/next" pair of input stream tokens one step forward, until curInput becomes inputEnd.
bool MacroParser::nextInputTokens(TokenStreamIterator &curInput, TokenStreamIterator &nextInput, TokenStreamIterator inputEnd)
{
	bool retVal = true;
	curInput = nextInput;
	if(nextInput != inputEnd)
	{
		++nextInput;
	}
	else
	{
		retVal = false;
	}
	return retVal;
}

// Moves a "cur/next" pair of input stream token iterators to seekPos and one past seekPos (respectively).
void MacroParser::seekInputTokens(TokenStreamIterator &curInput, TokenStreamIterator &nextInput, TokenStreamIterator inputEnd, TokenStreamIterator seekPos)
{
	nextInput = curInput = seekPos;
	if(nextInput != inputEnd)
	{
		++nextInput;
	}
}

// Starting from curInput, looks for a closing parenthesis that signals the end of the parenthesis nesting level curInput currently sits in.
TokenStreamIterator MacroParser::findEndParen(TokenStreamIterator &curInput, TokenStreamIterator inputEnd)
{
	TokenStreamIterator retVal = curInput;
	int curParenDepth = 0, curBracketDepth = 0;
	while(retVal != inputEnd)
	{
		if((*retVal)->tokenID == T_PAREN_L)
		{
			curParenDepth++;
		}
		else if((*retVal)->tokenID == T_PAREN_R)
		{
			curParenDepth--;
		}
		if((*retVal)->tokenID == T_BRACKET_L)
		{
			curBracketDepth++;
		}
		else if((*retVal)->tokenID == T_BRACKET_R)
		{
			curBracketDepth--;
		}
		if(curParenDepth < 0 || curBracketDepth < 0)
		{	// Break once we find an unmatched right paren/bracket, that's the end of our current paren/bracket depth.
			break;
		}
		++retVal;
	}
	// If we never found an unmatched right paren/bracket, we were at depth 0 the whole time, so auto-return end of input.
	return retVal;
}

// Reduce the size of the last match region by 1, rolling back to previous region(s) if that would empty any of them.
bool MacroParser::shrinkMatchRegions(TokenStreamIterator &curInput, TokenStreamIterator &nextInput, TokenStreamIterator inputStart, TokenStreamIterator inputEnd, TokenStreamIterator &curMacroInput, TokenStreamIterator &nextMacroInput, TokenStreamIterator macroStart, TokenStreamIterator macroEnd, std::vector<MacroPoundNumMatch*> &matchRegions)
{
	bool retVal = false; // Start pessimistic.
	
	// Sanity check: do we even have any regions to potentially shrink?
	if(!matchRegions.empty())
	{	// Reduce the size of the end region by one, deallocating any regions that get reduced to being empty in the process.
		for(int i = (int)matchRegions.size() - 1; i >= 0; i--)
		{
			if(matchRegions[i]->tempEnd != matchRegions[i]->tempStart)
			{
				--(matchRegions[i]->tempEnd);
/*				if(matchRegions[i]->tempEnd == matchRegions[i]->tempStart)
				{
					delete matchRegions[i];
					matchRegions[i] = NULL;
					matchRegions.pop_back();
					i--; // Record that we lost a match region before breaking.
				} //*/
				break; // Found a place we could shrink a region by 1.
			}
			else
			{
				delete matchRegions[i];
				matchRegions[i] = NULL;
				matchRegions.pop_back();
				// Recursively pop off a token from the prior match region, if there is one.
				return shrinkMatchRegions(curInput, nextInput, inputStart, inputEnd, curMacroInput, nextMacroInput, macroStart, macroEnd, matchRegions);
			}
		}
		// If after shrinking we've still got at least one non-empty match region, move all token stream iterators to new locations just after the last match region.
		if(!matchRegions.empty())
		{
			this->seekInputTokens(curInput, nextInput, inputEnd, matchRegions.back()->tempEnd);
			this->seekInputTokens(curMacroInput, nextMacroInput, macroEnd, matchRegions.back()->tempMacroEnd);
			retVal = true;
		}
	}
	
	return retVal;
}

// Changes a series of tokens' locations to be newLoc and changes their origin file names as well (in math notation, [first, last)).
void MacroParser::overrideTokenInfo(TokenStreamIterator first, TokenStreamIterator last, YYLTYPE newLoc, std::string newFileName)
{
	for(TokenStreamIterator tsIter = first; tsIter != last; ++tsIter)
	{
		(*tsIter)->tokenLocation = newLoc;
		(*tsIter)->tokenFileName = newFileName;
	}
}

// Evaluates the where clause of a macro to determine if a particular expansion should take place.
bool MacroParser::evalMacroWhereClause(Macro &macro, std::vector<MacroPoundNumMatch*> &matchRegions)
{
	/// @note MacroParser::evalMacroWhereClause() is an "always return true" stub.
	bool retVal = false; // Start pessimistic.
	// Sanity check: if the macro doesn't have a where clause, it always evals to true.
	if(macro.where.empty())
	{
		retVal = true;
	}
	else
	{
		// Stub: No eval functionality implemented, just assume successful eval.
		retVal = true;
	}
	return true;
}

/* UTILITY/SUPPORT METHODS */

// Sets curTokIter to the beginning of the lexer token stream and nextTokIter to just after curTokIter, if possible.
bool MacroParser::restartTokens()
{
	bool retVal = true;
	curTokIter = nextTokIter = ltsyyLexer::streamBegin();
	if(curTokIter != ltsyyLexer::streamEnd())
	{
		this->macroFileName = (*curTokIter)->tokenFileName;
		this->macroTokenLoc = (*curTokIter)->tokenLocation;
		++nextTokIter;
	}
	else
	{
		this->macroFileName = "";
		this->macroTokenLoc.first_line = this->macroTokenLoc.last_line = this->macroTokenLoc.first_column = this->macroTokenLoc.last_column = 0;
		retVal = false;
	}
	return retVal;
}

// Moves curTokIter and nextTokIter to the next tokens in the lexer token stream.
bool MacroParser::getNextToken()
{
	bool retVal = true;
	curTokIter = nextTokIter;
	if(nextTokIter != ltsyyLexer::streamEnd())
	{
		if(curTokIter != ltsyyLexer::streamEnd())
		{
			this->macroFileName = (*curTokIter)->tokenFileName;
			this->macroTokenLoc = (*curTokIter)->tokenLocation;
		}
		++nextTokIter;
	}
	else
	{
		retVal = false;
	}
	return retVal;
}

// Moves curTokIter and nextTokIter just past the next period found in the lexer token stream.
void MacroParser::skipToNextPeriod()
{
	while(curTokIter != ltsyyLexer::streamEnd() && (*curTokIter)->tokenID != END && (*curTokIter)->tokenID != T_PERIOD)
	{
		this->getNextToken();
	}
	if(curTokIter != ltsyyLexer::streamEnd() && (*curTokIter)->tokenID != T_PERIOD)
	{	// If we stopped on a period, go one past it.
		this->getNextToken();
	}
}

// Looks for the next period from tsIter to tsEnd, returning where it was found (or tsEnd on failure).
TokenStreamIterator MacroParser::findNextPeriod(TokenStreamIterator tsIter, TokenStreamIterator tsEnd)
{
	TokenStreamIterator findIter = tsIter;
	while(findIter != tsEnd)
	{
		if((*findIter)->tokenID == T_PERIOD)
		{
			break;
		}
		++findIter;
	}
	// If a period wasn't found, we'll naturally drop out of the while loop when findIter == tsEnd.
	return findIter;
}

// Moves the current token iterator to the position specified, also safely sets the lookahead token iterator to just after the new position.
void MacroParser::seekParserIterators(TokenStreamIterator newCurTokIter)
{
	this->curTokIter = this->nextTokIter = newCurTokIter;
	if(this->curTokIter != ltsyyLexer::streamEnd())
	{
		++nextTokIter;
	}
}

// Adds a standard parsing warning header to macroossErr to make warning notifications easier to pinpoint.
void MacroParser::macroStartWarning()
{
	macroossErr << "% Warning, ";
	if(this->macroFileName != "")
	{
		macroossErr << "File \"" << this->macroFileName << "\", ";
	}
	macroossErr << "Line #" << this->macroTokenLoc.first_line << "." << this->macroTokenLoc.first_column << ": ";
}

// Warning reporting function. Called when a non-fatal situation is identified
// that will probably produce unexpected/undesired translation results.
void MacroParser::macroReportWarning()
{
	if(macroossErr.str() == "")
	{
		this->macroStartWarning();
		macroossErr << "Using \"" << (*curTokIter)->stringValue << "\" here will probably break something.";
	}
	mainTrans->error(macroossErr.str(), true);
	macroossErr.str("");
	macroossErr.clear();
}

// Adds a standard parse error header to macroossErr to make it easier to report errors.
void MacroParser::macroStartParseError()
{
	macroossErr << "% Parse Error, ";
	if(this->macroFileName != "")
	{
		macroossErr << "File \"" << this->macroFileName << "\", ";
	}
	macroossErr << "Line #" << this->macroTokenLoc.first_line << "." << this->macroTokenLoc.first_column << ": ";
}

// Adds a standard syntax error header to macroossErr to make it easier to report errors.
void MacroParser::macroStartSyntaxError()
{
	macroossErr << "% Syntax Error, ";
	if(this->macroFileName != "")
	{
		macroossErr << "File \"" << this->macroFileName << "\", ";
	}
	macroossErr << "Line #" << this->macroTokenLoc.first_line << "." << this->macroTokenLoc.first_column << ": ";
}

// Error reporting function. Called when a fatal situation is identified
// that prevents parsing from continuing or guarantees that the translation will fail.
void MacroParser::macroReportError()
{
	if(macroossErr.str() == "")
	{
		this->macroStartSyntaxError();
		macroossErr << "Unexpected token \"" << (*curTokIter)->stringValue << "\".";
	}
	mainTrans->error(macroossErr.str(), true);
	macroossErr.str("");
	macroossErr.clear();
}

// Wrapper for error reporting function that outputs a generic "unexpected end of file" error.
void MacroParser::macroEOFError(bool setParseError)
{
	if(setParseError == true)
	{
		this->parseError = true;
	}
	this->macroStartSyntaxError();
	this->macroossErr << "Unexpected end of file in macro definition.";
	this->macroReportError();
}

// Destructor.
MacroParser::~MacroParser()
{
	curTokIter = nextTokIter = ltsyyLexer::streamEnd(); // Dont deallocate these, just invalidate them.
	macroossErr.str("");
	// Deallocate and clear out the macros list.
	for(std::list<Macro*>::iterator lIter = macros.begin(); lIter != macros.end(); ++lIter)
	{
		if(*lIter != NULL)
		{
			delete *lIter;
		}
	}
	macros.clear();
}

