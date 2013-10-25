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


#include <cstring>  // Interaction with ltsyytext.
#include <list>
#include <string>

#include "types.h"
#include "DataStructs/Comment.h"
#include "DataStructs/Token.h"

#include "ltsglobals.h"
#include "Translator.h"

#include "lexerTokenStream.h"

// Used to pass comments directly to output.
extern Translator* mainTrans;

bool hack1 = true;//use the hack dealing with improper file assignment of tokens from included files

// Declarations of the static members of the class.
TokenStream ltsyyLexer::tokenStream;
std::list<Token*>::iterator ltsyyLexer::tokenIter;
std::list<std::pair<std::string, std::list<Comment*>* > > ltsyyLexer::commentStream;
std::list<std::pair <std::string, std::list<Comment*>::iterator*> > ltsyyLexer::commentIter;

// Prepares the class for use as a lexer.
void ltsyyLexer::initLexer()
{
	// Clear and reset the token stream.
	tokenStream.clear();
	tokenIter = tokenStream.begin();
	clearCommentStream();
	// Clear and reset the global variables.
	ltsyyleng = 0;
	if(ltsyytext != NULL)
	{
		delete [] ltsyytext;
	}
	ltsyytextSize = 256;
	ltsyytext = new char[ltsyytextSize];
	ltsyylval.integer = 0;
	ltsyylvalType = VT_INT;
	ltsyylloc.first_line = ltsyylloc.last_line = 1;
	ltsyylloc.first_column = ltsyylloc.last_column = 1;
	ltsyyFileName = "";
}

// Restarts the internal token stream iterator at the beginning of the stream without touching any of the global data.
void ltsyyLexer::restartLexer()
{
	tokenIter = tokenStream.begin();
	restartCommentIterators();
}


/* *** TOKEN STREAM METHODS *** */

// Wrapper for tokenStream.begin().
std::list<Token*>::iterator ltsyyLexer::streamBegin()
{
	return tokenStream.begin();
}
// Wrapper for tokenStream.end().
std::list<Token*>::iterator ltsyyLexer::streamEnd()
{
	return tokenStream.end();
}

// Wrapper for tokenStream.insert(...).
std::list<Token*>::iterator ltsyyLexer::insert(std::list<Token*>::iterator iter, Token* tok)
{
	return tokenStream.insert(iter, tok);
}
// Enhanced wrapper for tokenStream.insert(...).
std::list<Token*>::iterator ltsyyLexer::insert(std::list<Token*>::iterator position, std::list<Token*>::iterator first, std::list<Token*>::iterator last)
{
	std::list<Token*>::iterator retVal = position;
	// We have to pull some shenanigans to ensure we end up at the beginning of the inserted tokens, and don't fall off the edge of the token stream.
	bool atBeginning = (position == tokenStream.begin());
	if(!atBeginning)
	{	// Go just before where we'll be inserting, so we can easily shift forward after the insertion.
		--retVal;
	}
	tokenStream.insert(position, first, last);
	if(atBeginning)
	{	// If position was the beginning, it's easy to point to where the insertion happened.
		retVal = tokenStream.begin();
	}
	else
	{	// If it wasn't the beginning, shift forward onto the first token in the inserted set.
		++retVal;
	}
	return retVal;
}
// Wrapper for tokenStream.erase(...).
std::list<Token*>::iterator ltsyyLexer::erase(std::list<Token*>::iterator iter)
{
	return tokenStream.erase(iter);
}
// Wrapper for tokenStream.pop(...).
std::list<Token*>::iterator ltsyyLexer::pop(std::list<Token*>::iterator iter)
{
	return tokenStream.pop(iter);
}

/* *** COMMENT STREAM METHODS *** */

// Helper function to see if a file has any comments stored for it yet.
bool ltsyyLexer::fileHasComments(std::string fileName)
{
	bool retVal = false; // Start pessimistic.
	for(std::list<std::pair<std::string, std::list<Comment*>* > >::iterator pIter = commentStream.begin(); pIter != commentStream.end(); ++pIter)
	{
		if((*pIter).first == fileName)
		{
			retVal = true;
			break;
		}
	}
	return retVal;
}

// Pulls the correct Comment list from commentStream based on the given file name.
// Auto-instantiates a Comment list for the file name if one doesn't exist.
std::list<Comment*>* ltsyyLexer::getFileComments(std::string fileName)
{
	std::list<Comment*>* retVal = NULL;
	
	std::list<std::pair<std::string, std::list<Comment*>* > >::iterator pIter;
	for(pIter = commentStream.begin(); pIter != commentStream.end(); ++pIter)
	{
		if((*pIter).first == fileName)
		{
			retVal = (*pIter).second;
			break;
		}
	}
	if(pIter == commentStream.end())
	{	// Reached the end without finding a match, make a comment entry for this file.
		retVal = new std::list<Comment*>;
		commentStream.push_back(std::pair<std::string, std::list<Comment*>* >(fileName, retVal));
		retVal = commentStream.back().second;
		std::list<Comment*>::iterator* tempIter = new std::list<Comment*>::iterator();
		(*tempIter) = retVal->begin();
		commentIter.push_back(std::pair<std::string, std::list<Comment*>::iterator*>(fileName, tempIter));
	}
	
	return retVal;
}

// Pulls the correct iterator from commentIter that is working on the comments associated with the given file name.
std::list<Comment*>::iterator* ltsyyLexer::getFileCommentIterator(std::string fileName)
{
	std::list<Comment*>::iterator* retVal = NULL;
	
	std::list<std::pair<std::string, std::list<Comment*>::iterator* > >::iterator pIter;
	for(pIter = commentIter.begin(); pIter != commentIter.end(); ++pIter)
	{
		if((*pIter).first == fileName)
		{
			retVal = (*pIter).second;
			break;
		}
	}
	if(pIter == commentIter.end())
	{	// Reached the end without finding a match, make a comment entry for this file.
		std::list<Comment*>* tempList = new std::list<Comment*>;
		commentStream.push_back(std::pair<std::string, std::list<Comment*>* >(fileName, tempList));
		tempList = commentStream.back().second;
		retVal = new std::list<Comment*>::iterator();
		(*retVal) = tempList->begin();
		commentIter.push_back(std::pair<std::string, std::list<Comment*>::iterator*>(fileName, retVal));
		retVal = commentIter.back().second;
	}
	
	return retVal;
}

// Resets all comment stream iterators to start at the beginning of their files.
void ltsyyLexer::restartCommentIterators()
{
	std::list<std::pair<std::string, std::list<Comment*>* > >::iterator lpIter;
	std::list<std::pair<std::string, std::list<Comment*>::iterator* > >::iterator ipIter;
	std::list<Comment*>::iterator* tempIter = NULL;
	// Weirdly enough, the easiest way to do this is just to delete the iterators and recreate them.
	for(ipIter = commentIter.begin(); ipIter != commentIter.end(); ++ipIter)
	{
		if((*ipIter).second != NULL)
		{
			delete (*ipIter).second;
			(*ipIter).second = NULL;
		}
	}
	commentIter.clear();
	for(lpIter = commentStream.begin(); lpIter != commentStream.end(); ++lpIter)
	{
		tempIter = new std::list<Comment*>::iterator();
		(*tempIter) = (*lpIter).second->begin();
		commentIter.push_back(std::pair<std::string, std::list<Comment*>::iterator*>((*lpIter).first, tempIter));
	}
}

// Deallocates and clears out the contents of the comment stream.
void ltsyyLexer::clearCommentStream()
{
	// Clear out all working iterators.
	for(std::list<std::pair <std::string, std::list<Comment*>::iterator*> >::iterator pIter = commentIter.begin(); pIter != commentIter.end(); ++pIter)
	{
		if((*pIter).second != NULL)
		{
			delete (*pIter).second;
			(*pIter).second = NULL;
		}
	}
	commentIter.clear();
	// Clear out all comments.
	for(std::list<std::pair<std::string, std::list<Comment*>* > >::iterator pIter = commentStream.begin(); pIter != commentStream.end(); ++pIter)
	{
		if((*pIter).second != NULL)
		{
			for(std::list<Comment*>::iterator cIter = (*pIter).second->begin(); cIter != (*pIter).second->end(); ++cIter)
			{
				delete *cIter;
				*cIter = NULL;
			}
			(*pIter).second->clear();
			delete (*pIter).second;
			(*pIter).second = NULL;
		}
	}
	commentStream.clear();
}

/* *** LEXER METHODS *** */

// Calls the passed yylex()-style function until EOF, adding all returned tokens into the tokenStream.
bool ltsyyLexer::lexAppendToTokenStream(int (*_yylexptr)(), char *&_yytext, int &_yyleng, YYSTYPE &_yylval, YYLTYPE &_yylloc, flexerValueType &_flexeryylvalType, std::string &_flexerFileName)
{
	int retVal = true; // Start optimistic.
	int lexResult = 0;
	Token *tempToken = NULL;
	
	// If the token stream already has contents in it, pop off ending EOF token(s) (if any).
	// ========As in insertToTokenStream, this may be detrimental, Check this
	while(!tokenStream.empty() && (tokenStream.back())->tokenID == 0)
	{
		tempToken = tokenStream.back();
		tokenStream.pop_back();
		delete tempToken;
		tempToken = NULL;
	}
	
	do
	{	// Grab tokens in a loop until the lexer throws an EOF or error token at us.
		tempToken = new Token();
		lexResult = getNextyylexToken(_yylexptr, _yytext, _yyleng, _yylval, _yylloc, _flexeryylvalType, _flexerFileName, tempToken);
		if(lexResult == T_COMMENT || lexResult == T_ASP)
		{	// Store comment-style raw text in the separate stream so it doesn't mess up the main token stream.
			// Copy the Comment out of the token, the Token's version is going to get deleted.
			std::list<Comment*>* tempComments = NULL;
			tempComments = getFileComments(tempToken->tokenFileName);
			if(lexResult == T_COMMENT)
			{
				Comment *newComment = new Comment();
				*newComment = *(tempToken->tokenValue.com);
				tempComments->push_back(newComment);
			}
			else
			{
				
				ASPCode *newASPCode = new ASPCode();
				*newASPCode = *(tempToken->tokenValue.asp);
				tempComments->push_back(newASPCode);
				//tokenStream.push_back(tempToken);
			}
			// Delete the Token object, we don't need it anymore.
			delete tempToken;
		}
		else
		{
			tokenStream.push_back(tempToken);
		}
		// If an error token is stopping us, warn the caller that something
		// went wrong during lexing.
		if(lexResult < 0)
		{
			retVal = false;
		}
	}while(lexResult > 0);
	
	return retVal;
}

// Erases a range of tokens from the token stream, starting with the one
// at iterBegin, and finishing with the one just before iterEnd (i.e.,
// [iterBegin, iterEnd) in math range notation).
std::list<Token*>::iterator ltsyyLexer::lexEraseFromTokenStream(std::list<Token*>::iterator iterBegin, std::list<Token*>::iterator iterEnd)
{
	std::list<Token*>::iterator retVal = iterBegin;
	while(retVal != iterEnd && retVal != tokenStream.end())
	{
		retVal = ltsyyLexer::erase(retVal);		
	}
	return retVal;
}

// Calls the passed yylex()-style function until EOF, inserting the tokens
// into the stream at iterLoc.
bool ltsyyLexer::lexInsertIntoTokenStream(int (*_yylexptr)(), char *&_yytext, int &_yyleng, YYSTYPE &_yylval, YYLTYPE &_yylloc, flexerValueType &_flexeryylvalType, std::string &_flexerFileName, std::list<Token*>::iterator &iterLoc,bool backToBeginning=true)
{
	int retVal = true; // Start optimistic.
	int lexResult = 0;
	Token *tempToken = NULL;
	std::list<Token*>::iterator newIterLoc;
	// If the token stream already has contents in it, pop off ending EOF token(s) (if any).
	// This seems to work now with this block commented out
	/*while(!tokenStream.empty() && (tokenStream.back())->tokenID == 0)
	{
		tempToken = tokenStream.back();
		tokenStream.pop_back();
		delete tempToken;
		tempToken = NULL;
	}*/
	
	do
	{	// Grab tokens in a loop until the lexer throws an EOF or error token at us.
		tempToken = new Token();
		lexResult = getNextyylexToken(_yylexptr, _yytext, _yyleng, _yylval, _yylloc, _flexeryylvalType, _flexerFileName, tempToken);

		// Insert all non-EOF tokens, but only insert an EOF token
		// if iterLoc happens to be at the end of the token stream.
		if(tempToken->tokenID != 0 || iterLoc == tokenStream.end())
		{
			if(lexResult == T_COMMENT || lexResult == T_ASP)
			{	// Store comment-style raw text in the separate stream so it doesn't mess up the main token stream. Store it in the appropriate location so it's in order with the rest of the comments.
				// Copy the Comment out of the token, the Token's version is going to get deleted.
				std::list<Comment*>* tempComments = NULL;
				if(lexResult == T_COMMENT)
				{
					Comment *newComment = new Comment();
					*newComment = *(tempToken->tokenValue.com);
					if(hack1) (*newComment).fileName = _flexerFileName;//this should not have to be done but somehow the fileName is improperly assigned
					tempComments = getFileComments(newComment->fileName);
					std::list<Comment*>::iterator cIter;
					for(cIter = tempComments->begin(); cIter != tempComments->end(); ++cIter)
					{
						if(newComment->isBeforeLoc(*((*cIter)->loc)))
						{
							break;
						}
					}
					tempComments->insert(cIter,newComment);
				}
				else
				{
					
					ASPCode *newASPCode = new ASPCode();
					*newASPCode = *(tempToken->tokenValue.asp);
					
					if(hack1) (*newASPCode).fileName = _flexerFileName;//this should not have to be done but somehow the fileName is improperly assigned
					tempComments = getFileComments(newASPCode->fileName);
					std::list<Comment*>::iterator cIter;

					for(cIter = tempComments->begin(); cIter != tempComments->end(); ++cIter)
					{
						if(newASPCode->isBeforeLoc(*((*cIter)->loc)))
						{
							break;
						}
					}
					tempComments->insert(cIter,newASPCode);
				}
				// Delete the Token object, we don't need it anymore.
				delete tempToken;
			}
			else
			{
				newIterLoc = tokenStream.insert(iterLoc, tempToken);
			}
		}

		// If an error token is stopping us, warn the caller that something
		// went wrong during lexing.

		if(lexResult < 0)
		{
			retVal = false;
		}
	}while(lexResult > 0);
	
	

	if(backToBeginning)
		iterLoc = newIterLoc; // Move iterLoc to the beginning of the inserted tokens. Maybe delete this statement or make a copy without this functionality.
	return retVal;
}

// Clears the internal token stream, calls lexAppendToTokenStream, passing 
// along the appropriate parameters, then resets the internal token iterator 
// to the beginning of the stream.
bool ltsyyLexer::lexReplaceTokenStream(int (*_yylexptr)(), char *&_yytext, int &_yyleng, YYSTYPE &_yylval, YYLTYPE &_yylloc, flexerValueType &_flexeryylvalType, std::string &_flexerFileName)
{
	bool retVal = true; // Start optimistic.
	tokenStream.clear();
	retVal = lexAppendToTokenStream(_yylexptr, _yytext, _yyleng, _yylval, _yylloc, _flexeryylvalType, _flexerFileName);
	tokenIter = tokenStream.begin();
	return retVal;
}

// Moves the internal token stream iterator to the position at seekPos.
void ltsyyLexer::lexSeek(std::list<Token*>::iterator seekPos)
{
	tokenIter = seekPos;
}

// Updates the global variables with information about the token currently 
// pointed at by the iterator, then moves the iterator forward by one position (if it isn't at the end).
int ltsyyLexer::nextToken()
{
	int retVal = 0; // Start pessimistic (EOF).
	Token *tempToken = NULL;
	
	// Sanity check: only grab a token if we haven't reached the end of the token stream.
	if(!tokenStream.empty() && tokenIter != tokenStream.end())
	{
		tempToken = *tokenIter;
		retVal = tempToken->tokenID;
		
		// Update all emulated global variables.
		ltsyyleng = (int)tempToken->stringValue.length();
		// Reallocate our emulated yytext to ensure a) we've got 
		// good memory to populate, and b) the buffer's big enough.
		if(ltsyytext != NULL)
		{
			delete [] ltsyytext;
		}
		ltsyytextSize = (size_t)ltsyyleng + 1;
		ltsyytext = new char[ltsyytextSize];
		strcpy(ltsyytext, tempToken->stringValue.c_str());
		// Like the real flexer, this should only return ints and strings.
		switch(tempToken->tokenValueType)
		{
		case VT_INT:
			ltsyylval.integer = tempToken->tokenValue.integer;
			break;
		case VT_STR:
			// This should be dynamically copied so the parser's
			// memory management routines don't accidentally depend on
			// or destroy this (temporary & self-managed) token's data.
			ltsyylval.str = new std::string(*(tempToken->tokenValue.str));
			break;
		default:
			// Unknown, stick 0 in the union.
			ltsyylval.integer = 0;
			break;
		}
		ltsyylvalType = tempToken->tokenValueType;
		ltsyylloc.first_line = tempToken->tokenLocation.first_line;
		ltsyylloc.last_line = tempToken->tokenLocation.last_line;
		ltsyylloc.first_column = tempToken->tokenLocation.first_column;
		ltsyylloc.last_column = tempToken->tokenLocation.last_column;
		ltsyyFileName = tempToken->tokenFileName;
		
		// Check to see if any comments came before this token, output them if so.
		std::list<Comment*>* cList = getFileComments(tempToken->tokenFileName);
		std::list<Comment*>::iterator* cIter = getFileCommentIterator(tempToken->tokenFileName);
		
		while((*cIter) != cList->end() && (*(*cIter))->isBeforeLoc(tempToken->tokenLocation))
		{
			std::string tempStr = (*(*cIter))->output();
			mainTrans->output(tempStr, IPART_NONE, true);
			++(*cIter);
		}
		
		// Move the iterator and finish up.
		if(tokenIter != tokenStream.end())
		{
			tokenIter++;
		}
	}
	else
	{
		// Bug fix: ensure that we print out the last comments!
		if (tempToken) {
			std::list<Comment*>* cList = getFileComments(tempToken->tokenFileName);
			std::list<Comment*>::iterator* cIter = getFileCommentIterator(tempToken->tokenFileName);

			while((*cIter) != cList->end() && (*(*cIter))->isBeforeLoc(tempToken->tokenLocation))
			{
				std::string tempStr = (*(*cIter))->output();
				mainTrans->output(tempStr, IPART_NONE, true);
				++(*cIter);
			}
		}

		// Failed the sanity check, fill the globals with EOF/bad values.
		retVal = 0;
		std::string tempString = "EOF";
		ltsyyleng = tempString.length();
		// Reallocate our emulated yytext to ensure a) we've got 
		// good memory to populate, and b) the buffer's big enough.
		if(ltsyytext != NULL)
		{
			delete [] ltsyytext;
		}
		ltsyytextSize = (size_t)ltsyyleng + 1;
		ltsyytext = new char[ltsyytextSize];
		strcpy(ltsyytext, tempString.c_str());
		ltsyylval.integer = 0;
		ltsyylvalType = VT_INT;
		ltsyylloc.first_line = 0;
		ltsyylloc.last_line = 0;
		ltsyylloc.first_column = 0;
		ltsyylloc.last_column = 0;
		ltsyyFileName = "";
	}
	
	return retVal;
}

// Helper to the yylex()-reading tokenStream manipulators, actually calls
// the yylex()-style function _yylexptr and populates the (already
// allocated) passed Token with the information from the call.
int ltsyyLexer::getNextyylexToken(int (*_yylexptr)(), char *&_yytext, int &_yyleng, YYSTYPE &_yylval, YYLTYPE &_yylloc, flexerValueType &_flexeryylvalType, std::string &_flexerFileName, Token* newToken)
{
	int retVal = (*_yylexptr)();
	// If the token was a normal token, store that value.
	// If it was an error token, store 0 (EOF).
	if(retVal >= 0)
	{
		newToken->tokenID = retVal;
	}
	else
	{
		newToken->tokenID = 0;
	}
	newToken->tokenValueType = _flexeryylvalType;
	// The flexer is only supposed to return ints and strings.
	switch(newToken->tokenValueType)
	{
	case VT_INT:
		newToken->tokenValue.integer = _yylval.integer;
		break;
	case VT_STR:
		// This is dynamically allocated, so make a copy of it
		// and delete the one the flexer allocated.
		newToken->tokenValue.str = new std::string(*(_yylval.str));
		delete _yylval.str;
		break;
	case VT_ASP:
		// This is dynamically allocated, so make a copy of it
		// and delete the flexer's copy.
		newToken->tokenValue.asp = new ASPCode();
		*(newToken->tokenValue.asp) = *(_yylval.asp);
		delete _yylval.asp;
		break;
	case VT_COMMENT:
	  	// This is dynamically allocated, so make a copy of it
		// and delete the flexer's copy.
		newToken->tokenValue.com = new Comment();
		*(newToken->tokenValue.com) = *(_yylval.com);
		delete _yylval.com;
		break;
	default:
		// Unknown, stick 0 / NULL in the union.
		newToken->tokenValue.integer = 0;
		break;
	}
	newToken->tokenLocation.first_line = _yylloc.first_line;
	newToken->tokenLocation.last_line = _yylloc.last_line;
	newToken->tokenLocation.first_column = _yylloc.first_column;
	newToken->tokenLocation.last_column = _yylloc.last_column;
	newToken->tokenFileName = _flexerFileName;
	// If it's the EOF token, store a special yytext value, otherwise
	// just keep what was given.
	if(retVal == 0)
	{
		newToken->stringValue = "EOF";
	}
	else
	{
		newToken->stringValue = std::string(_yytext);
	}
	return retVal;
}

/* --- Global functions --- */

// Emulation of yylex().
int ltsyylex()
{
	return ltsyyLexer::nextToken();
}
