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


#include "IncludeHandler.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>		// realpath
#include <climits>		// PATH_MAX
#include <list>
#include <sstream>
#include <vector>


#include "Macro.h"
#include "Token.h"

#include "utilities.h"

#include "Translator.h"
#include "parser.h"
#include "flexer.h"

extern Translator mainTrans; ///< The main translator module, declared in the main parser.

IncludeHandler::IncludeHandler()
{
	curTokIter = nextTokIter = ltsyyLexer::streamEnd();
	includeossErr.str("");
	includeNumErrors = 0;
	includeFileName = "";
	includeTokenLoc.first_line = includeTokenLoc.last_line = includeTokenLoc.first_column = includeTokenLoc.last_column = 0;
	parseError = false;
}


//Current issue: doesn't handle included files' comments correctly
//seg faults when the include is the last thing in a file
//This seems to be due to the token stream's end being the same as the beginning...
int IncludeHandler::handleInclude(int (*flexlex)(), char *&flextext, int &flexleng, YYSTYPE &yyxlval, YYLTYPE &yyxlloc, flexerValueType &flexeryylvalType)
//int IncludeHandler::handleInclude()
{
	int retVal = 0; // Start optimistic, assuming we won't find any includes.
	TokenStreamIterator includeDefStart, includeDefEnd; // Records the positions in the token stream where an include started and ended (for later removal purposes).
	bool includeFound = false;
	std::list<std::string> includeList;
	std::list<std::string>::iterator includeListIterator;
	std::list<Comment*>* tempComments;
	std::string line = "";//part of a hack
	std::string includeAlias;

	char resolvedFileName[PATH_MAX];

	// This acts as the handler's "base" state, looking for includes.
	// Look for grammar rules of the form "T_COLON_DASH T_INCLUDE include_file_tuple T_PERIOD", ignores anything else.
	// We know we need >= 2 tokens for a macro definition, so it's fine to check if either cur or next token is end-of-stream.
	if(this->restartTokens())//start searching for includes at the beginning of the token stream
	{
		while(curTokIter != ltsyyLexer::streamEnd() && (*curTokIter)->tokenID != END && nextTokIter != ltsyyLexer::streamEnd() && retVal <= 0)
		{
			includeFound = false;
			// For efficiency, check for any declaration section (so we can skip over it entirely if it isn't a macros section).
			if((*curTokIter)->tokenID == T_COLON_DASH)
			{
				if((*nextTokIter)->tokenID == T_INCLUDE)
				{
					includeDefStart = curTokIter; // Remember this ":-" to remove it later.
					this->getNextToken(); //currently holds the include token but we don't need this, just get the next token
					this->getNextToken(); //currently holds the first file to be included

					while(curTokIter != ltsyyLexer::streamEnd() && (*curTokIter)->tokenID != T_PERIOD && ((*curTokIter)->stringValue).compare(".") != 0)//this is a hack should just be able to check for period token but not sure how to get the tokenizer to do this correctly
					{
						if((*curTokIter)->stringValue.compare(";") != 0)
						{	
							includeList.push_back((*curTokIter)->stringValue);
						}
						if(curTokIter != ltsyyLexer::streamEnd())this->getNextToken();
					}
					if((curTokIter != ltsyyLexer::streamEnd()) && (((*curTokIter)->tokenID == T_PERIOD) || ((*curTokIter)->stringValue).compare(".") == 0))
					{
						this->getNextToken();
						includeDefEnd = curTokIter;//this is the last token we will delete, a period
						ltsyyLexer::lexEraseFromTokenStream(includeDefStart, includeDefEnd);//remove the entire include statement.
						
						for(includeListIterator = includeList.begin(); includeListIterator != includeList.end(); includeListIterator++)//add each files tokens to the current stream.
						{

							includeAlias = *includeListIterator;
							flexin = NULL;

							flexerReset();

							// Start by checking path's relative to the current include directory.
							if (realpath(includeFileName.c_str(), resolvedFileName)) {
								std::string tmp = resolvedFileName;
								tmp = tmp.substr(0,tmp.find_last_of("/")) + "/" + includeAlias;
								flexin = fopen(tmp.c_str(), "r");
								if (flexin) {
									(*includeListIterator) = tmp;
								}
							}

							// If that didn't work, fall back to the standard PATH variables and current working directory.
							if (!flexin) {
								flexin = fopen((*includeListIterator).c_str(), "r");
							}


							if(flexin != NULL)							
							{

								ltsyyLexer::lexInsertIntoTokenStream(flexlex, flextext, flexleng, yyxlval, yyxlloc, flexeryylvalType, *includeListIterator, curTokIter,false);
								//Insert a comment marking the start of the included file
								Comment* fileCom = new Comment();
								fileCom->contents = "";
								fileCom->contents += " File \"";
								fileCom->contents += includeAlias;
								fileCom->contents += "\".";
								fileCom->fileName = *includeListIterator;
								fileCom->loc->first_line = 0;
								fileCom->loc->first_column = 0;
								fileCom->loc->last_line = 0;
								fileCom->loc->last_column = 0;
								tempComments = ltsyyLexer::getFileComments(*includeListIterator);
								tempComments->push_front(fileCom);
								
								
							}
							else
							{	//File not found.
								this->includeNumErrors++;
								includeFileNotFoundError(includeAlias,false);
							}
							
						}
						while(includeList.size() != 0) includeList.pop_front();//empty the include list
						this->restartTokens();//this could be done more efficiently--recursion.
						includeFound = true;
					}
					else
					{
						if(curTokIter == ltsyyLexer::streamEnd() || (*curTokIter)->tokenID == END)
						{	// Unexpected EOF. Don't set parseError, we're already in base state.
							this->includeNumErrors++;
							this->includeEOFError(false);
						}
						else
						{	// Unexpected token, just use the default error message.
							this->includeNumErrors++;
							this->includeReportError();
							this->skipToNextPeriod();
						}
					}
				}
			}
			//only go to the next token if an include wasn't found in this iteration
			if(!includeFound && curTokIter != ltsyyLexer::streamEnd() && (*curTokIter)->tokenID != END)
				this->getNextToken();
		}
	}

	return includeNumErrors;
}
/*
int IncludeHandler::findIncludes()
{
	int retVal = 0; // Start optimistic, assuming we won't find any includes.
	//std::list<Macro*> lstMacroDef; // Used to capture return value from the macro processing function.
	TokenStreamIterator includeDefStart, includeDefEnd; // Records the positions in the token stream where an include started and ended (for later removal purposes).
	
	// This acts as the parser's "base" state, looking for macro definitions.
	// Look for grammar rules of the form "T_COLON_DASH T_MACROS parser_def_macro_tuple T_PERIOD", ignores anything else.
	// We know we need >= 2 tokens for a macro definition, so it's fine to check if either cur or next token is end-of-stream.
	while(curTokIter != ltsyyLexer::streamEnd() && (*curTokIter)->tokenID != END && nextTokIter != ltsyyLexer::streamEnd() && retVal <= 0)
	{
		// For efficiency, check for any declaration section (so we can skip over it entirely if it isn't a macros section).
		if((*curTokIter)->tokenID == T_COLON_DASH)
		{
			if((*nextTokIter)->tokenID == T_INCLUDE)
			{
				includeDefStart = curTokIter; // Remember this ":-" to remove it later.
				this->getNextToken();
				this->getNextToken(); //currently holds the first file to be included
				//lstMacroDef = this->parser_def_macro_tuple();
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
}*/

// Sets curTokIter to the beginning of the lexer token stream and nextTokIter to just after curTokIter, if possible.
bool IncludeHandler::restartTokens()
{
	bool retVal = true;
	curTokIter = nextTokIter = ltsyyLexer::streamBegin();
	if(curTokIter != ltsyyLexer::streamEnd())
	{
		this->includeFileName = (*curTokIter)->tokenFileName;
		this->includeTokenLoc = (*curTokIter)->tokenLocation;
		++nextTokIter;
	}
	else
	{
		this->includeFileName = "";
		this->includeTokenLoc.first_line = this->includeTokenLoc.last_line = this->includeTokenLoc.first_column = this->includeTokenLoc.last_column = 0;
		retVal = false;
	}
	return retVal;
}

bool IncludeHandler::getNextToken()
{
	bool retVal = true;
	curTokIter = nextTokIter;
	if(nextTokIter != ltsyyLexer::streamEnd())
	{
		if(curTokIter != ltsyyLexer::streamEnd())
		{
			this->includeFileName = (*curTokIter)->tokenFileName;
			this->includeTokenLoc = (*curTokIter)->tokenLocation;
		}
		++nextTokIter;
	}
	else
	{
		retVal = false;
	}
	return retVal;
}

// Moves the current token iterator to the position specified, also safely sets the lookahead token iterator to just after the new position.
void IncludeHandler::seekParserIterators(TokenStreamIterator newCurTokIter)
{
	this->curTokIter = this->nextTokIter = newCurTokIter;
	if(this->curTokIter != ltsyyLexer::streamEnd())
	{
		++nextTokIter;
	}
}

// Moves curTokIter and nextTokIter just past the next period found in the lexer token stream.
void IncludeHandler::skipToNextPeriod()
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

// Adds a standard syntax error header to macroossErr to make it easier to report errors.
void IncludeHandler::includeStartSyntaxError()
{
	includeossErr << "% Syntax Error, ";
	if(this->includeFileName != "")
	{
		includeossErr << "File \"" << this->includeFileName << "\", ";
	}
	includeossErr << "Line #" << this->includeTokenLoc.first_line << "." << this->includeTokenLoc.first_column << ": ";
}

// Error reporting function. Called when a fatal situation is identified
// that prevents parsing from continuing or guarantees that the translation will fail.
void IncludeHandler::includeReportError()
{
	if(includeossErr.str() == "")
	{
		this->includeStartSyntaxError();
		includeossErr << "Unexpected token \"" << (*curTokIter)->stringValue << "\".";
	}
	mainTrans.error(includeossErr.str(), true);
	includeossErr.str("");
	includeossErr.clear();
}

// Wrapper for error reporting function that outputs a generic "unexpected end of file" error.
void IncludeHandler::includeEOFError(bool setParseError)
{
	if(setParseError == true)
	{
		this->parseError = true;
	}
	this->includeStartSyntaxError();
	this->includeossErr << "Unexpected end of file in include statment.";
	this->includeReportError();
}

// Wrapper for error reporting function that outputs a generic "file not found" error.
void IncludeHandler::includeFileNotFoundError(std::string fileName, bool setParseError)
{
	if(setParseError == true)
	{
		this->parseError = true;
	}
	this->includeStartSyntaxError();
	this->includeossErr << "File '"<< fileName <<"' not found in include statement.";
	this->includeReportError();
}

IncludeHandler::~IncludeHandler()
{
	curTokIter = nextTokIter = ltsyyLexer::streamEnd(); // Dont deallocate these, just invalidate them.
	includeossErr.str("");
}
