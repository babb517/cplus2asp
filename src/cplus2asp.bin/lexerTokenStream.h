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


#ifndef LEXERTOKENSTREAM_H
#define LEXERTOKENSTREAM_H

/**
 * @file lexerTokenStream.h
 * @brief Functions, globals, and classes that fake being a lex-style lexer.
 * @details Using a TokenStream object encapsulated in a static class, 
 * provides functions and global values that emulate the functionality 
 * of a lex-style lexer, along with methods designed to populate the 
 * TokenStream object with tokens from a real lex-style lexer.
 */

#include <cstring>  // Interaction with ltsyytext.
#include <list>
#include <string>

#include "DataStructs/TokenStream.h"
#include "flexertypes.h"
class Token;
class Comment;


/**
 * Encapsulates a TokenStream object and provides functions to populate it with 
 * Token objects created from the output of a real lex-style lexer.
 */
class ltsyyLexer
{
protected:
	static TokenStream tokenStream; ///< The encapsulated token stream object.
	static std::list<Token*>::iterator tokenIter; ///< An internal iterator used to wander through the token stream.
	static std::list<std::pair<std::string, std::list<Comment*>* > > commentStream; ///< A collection of any comments and other raw text, encountered while reading input, that needs to be passed through to output at the appropriate point during lexing.
	static std::list<std::pair <std::string, std::list<Comment*>::iterator*> > commentIter; ///< An internal super-iterator used to keep track of which comments have already been output and which are still waiting.
	/**
	 * Helper to the yylex()-reading tokenStream manipulators, this method
	 * actually calls the yylex()-style function and populates the (already
	 * allocated) passed Token with the information from the call.
	 * @param _yylexptr - Pointer to the yylex()-style function to call.
	 * @param _yytext - Reference to the cstring containing each token's raw text.
	 * @param _yyleng - Reference to the length of each token's raw text.
	 * @param _yylval - Reference to the lexer's yylval variable/union that should be filled with the semantic value of each token.
	 * @param _yylloc - Reference to the lexer's yylloc struct that should be populated with line and column information for each token.
	 * @param _flexeryylvalType - Reference to the lexer's flag for which member of YYSTYPE yylval is using for the given token.
	 * @param _flexerFileName - Reference to the name of the file being processed by the lexer.
	 * @param newToken - The pre-allocated Token object to populate with the data from the call to _yylexptr.
	 * @return True on success, false on any error.
	 */
	static int getNextyylexToken(int (*_yylexptr)(), char *&_yytext, int &_yyleng, YYSTYPE &_yylval, YYLTYPE &_yylloc, flexerValueType &_flexeryylvalType, std::string &_flexerFileName, Token* newToken);
public:
	/**
	 * Prepares the class for use as a lexer.
	 * Clears the token stream, sets tokenIter to the beginning of the token 
	 * stream, and initializes all state trackers and global token data to 
	 * default values.
	 */
	static void initLexer();
	
	/**
	 * Restarts the internal token stream iterator at the beginning of 
	 * the stream without touching any of the global data.
	 */
	static void restartLexer();
	
	/* *** TOKEN STREAM METHODS *** */
	
	/**
	 * Wrapper for tokenStream.begin().
	 * @return An iterator starting at the beginning of the token stream.
	 */
	static std::list<Token*>::iterator streamBegin();
	/**
	 * Wrapper for tokenStream.end().
	 * @return An iterator pointing at the end of the token stream.
	 */
	static std::list<Token*>::iterator streamEnd();
	
	/**
	 * Wrapper for tokenStream.insert(...).
	 * Inserts a token into the internal stream just before the passed iterator's position.
	 * @param iter - Iterator at the desired insert position.
	 * @param tok - The Token pointer to insert.
	 * @return An iterator to the newly inserted Token pointer.
	 */
	static std::list<Token*>::iterator insert(std::list<Token*>::iterator iter, Token* tok);
	/**
	 * Enhanced wrapper for tokenStream.insert(...).
	 * Inserts a series of tokens into the internal stream just before the passed iterator's position.
	 * @param position - Iterator at the desired insert position.
	 * @param first - An iterator pointing to the first token to insert from another stream.
	 * @param last - An iterator pointing just past the last token to insert from another stream.
	 * @return An iterator pointing to the first inserted token.
	 */
	static std::list<Token*>::iterator insert(std::list<Token*>::iterator position, std::list<Token*>::iterator first, std::list<Token*>::iterator last);
	/**
	 * Wrapper for tokenStream.erase(...).
	 * Removes a token from the internal stream at the passed iterator's position.
	 * Wrapped function will delete the associated token's memory.
	 * @param iter - Iterator at the desired Token pointer to erase.
	 * @return An iterator to the Token pointer immediately following the removed element.
	 */
	static std::list<Token*>::iterator erase(std::list<Token*>::iterator iter);
	/**
	 * Wrapper for tokenStream.pop(...).
	 * Removes a token from the internal stream at the passed iterator's position.
	 * Wrapped function does not do anything to/with the popped token.
	 * @param iter - Iterator at the desired Token pointer to pop.
	 * @return An iterator to the Token pointer immediately following the removed element.
	 */
	static std::list<Token*>::iterator pop(std::list<Token*>::iterator iter);
	
	/* *** COMMENT STREAM METHODS *** */
	
	/**
	 * Clears out the contents of the comment stream and deallocates
	 * all memory held in its data structures.
	 */
	static void clearCommentStream();
	
	/**
	 * Resets all comment stream iterators to start at the beginning of their files.
	 */
	static void restartCommentIterators();
		
	/**
	 * Helper function to see if a file has any comments stored for it yet.
	 * @param fileName - The name of the file being checked.
	 * @return True if there is an entry in commentStream for the file, false otherwise.
	 */
	static bool fileHasComments(std::string fileName);
	
	/**
	 * Pulls the correct Comment list from commentStream based on the given file name.
	 * If fileName doesn't have a data structure for it in commentStream / commentIter yet, one will be created.
	 * @param fileName - The name of the file whose comments we are interested in.
	 * @return The current list of Comment objects associated with that file.
	 */
	static std::list<Comment*>* getFileComments(std::string fileName);
	
	/**
	 * Pulls the correct iterator from commentIter that is working on the comments associated with the given file name.
	 * If fileName doesn't have a data structure for it in commentStream / commentIter yet, one will be created.
	 * @param fileName - The name of the file whose comments the iterator is wandering through.
	 * @return The current comment iterator for that file.
	 */
	static std::list<Comment*>::iterator* getFileCommentIterator(std::string fileName);
	
	/* *** LEXER METHODS *** */
	
	/**
	 * Calls the passed yylex()-style function until EOF, adding all 
	 * returned tokens into the tokenStream.
	 * Assumes that the real lexer has already been initialized and
	 * is ready to process & return tokens.
	 * @param _yylexptr - Pointer to the yylex()-style function to call.
	 * @param _yytext - Reference to the cstring containing each token's raw text.
	 * @param _yyleng - Reference to the length of each token's raw text.
	 * @param _yylval - Reference to the lexer's yylval variable/union that should be filled with the semantic value of each token.
	 * @param _yylloc - Reference to the lexer's yylloc struct that should be populated with line and column information for each token.
	 * @param _flexeryylvalType - Reference to the lexer's flag for which member of YYSTYPE yylval is using for the given token.
	 * @param _flexerFileName - Reference to the name of the file being processed by the lexer.
	 * @return True on success, false on any error.
	 */
	static bool lexAppendToTokenStream(int (*_yylexptr)(), char *&_yytext, int &_yyleng, YYSTYPE &_yylval, YYLTYPE &_yylloc, flexerValueType &_flexeryylvalType, std::string &_flexerFileName);
	
	/**
	 * Erases a range of tokens from the token stream, starting with the one
	 * at iterBegin, and finishing with the one just before iterEnd (i.e.,
	 * [iterBegin, iterEnd) in math range notation).
	 * Will deallocate the removed Token objects.
	 * @param iterBegin - An iterator pointing at the first token to remove.
	 * @param iterEnd - An iterator pointing just past the last token to remove.
	 * @return An iterator to the Token pointer immediately following the removed token range.
	 */
	static std::list<Token*>::iterator lexEraseFromTokenStream(std::list<Token*>::iterator iterBegin, std::list<Token*>::iterator iterEnd);
	
	/**
	 * Acts like lexAppendToTokenStream, calling the passed yylex()-style
	 * function until EOF, but instead inserting the returned tokens into
	 * the token stream at iterLoc's position.
	 * At the end of this method's operation, iterLoc ends up pointing at the
	 * beginning of the set of tokens inserted into the token stream unless otherwise specified by the default false bool backToBeginning.
	 * @param _yylexptr - Pointer to the yylex()-style function to call.
	 * @param _yytext - Reference to the cstring containing each token's raw text.
	 * @param _yyleng - Reference to the length of each token's raw text.
	 * @param _yylval - Reference to the lexer's yylval variable/union that should be filled with the semantic value of each token.
	 * @param _yylloc - Reference to the lexer's yylloc struct that should be populated with line and column information for each token.
	 * @param _flexeryylvalType - Reference to the lexer's flag for which member of YYSTYPE yylval is using for the given token.
	 * @param _flexerFileName - Reference to the name of the file being processed by the lexer.
	 * @param iterLoc - The location in the token stream to insert the tokens returned by _yylexptr.
	 * @param backToBeginning - bool determining whether iterLoc ends up pointing at the beginning of the set of tokens inserted into the token stream; default false
	 * @return True on success, false on any error.
	 */
	static bool lexInsertIntoTokenStream(int (*_yylexptr)(), char *&_yytext, int &_yyleng, YYSTYPE &_yylval, YYLTYPE &_yylloc, flexerValueType &_flexeryylvalType, std::string &_flexerFileName, std::list<Token*>::iterator &iterLoc, bool backToBeginning);
	
	/**
	 * Clears the internal token stream, calls 
	 * lexAppendToTokenStream, passing along the appropriate parameters,
	 * then resets the internal token iterator to the beginning of the stream.
	 * @param _yylexptr - Pointer to the yylex()-style function to call.
	 * @param _yytext - Reference to the cstring containing each token's raw text.
	 * @param _yyleng - Reference to the length of each token's raw text.
	 * @param _yylval - Reference to the lexer's yylval variable/union that should be filled with the semantic value of each token.
	 * @param _yylloc - Reference to the lexer's yylloc struct that should be populated with line and column information for each token.
	 * @param _flexeryylvalType - Reference to the lexer's flag for which member of YYSTYPE yylval is using for the given token.
	 * @param _flexerFileName - Reference to the name of the file being processed by the lexer.
	 * @return True on success, false on any error.
	 */
	static bool lexReplaceTokenStream(int (*_yylexptr)(), char *&_yytext, int &_yyleng, YYSTYPE &_yylval, YYLTYPE &_yylloc, flexerValueType &_flexeryylvalType, std::string &_flexerFileName);
	
	/**
	 * Moves the internal token stream iterator to the position at seekPos.
	 * Allows for arbitrary moving or restarting of the "lexer" through its stream.
	 * @param seekPos - An iterator at the desired position for the "lexer" to continue with the next token request.
	 */
	static void lexSeek(std::list<Token*>::iterator seekPos);
	
	/**
	 * Updates the global variables with information about the token 
	 * currently pointed at by the iterator, then moves the iterator forward 
	 * by one position (if it isn't at the end).
	 * @return The token ID of the next token in the stream, or 0 if at the end of the stream.
	 */
	static int nextToken();
};

/**
 * Emulates the functionality of a typical yylex() function, returning 
 * the token number for the next token in the stream, or 0 
 * at the end of the stream.
 * The static function this wraps automatically updates the emulated 
 * global variables accordingly.
 * 
 * @return A positive integer describing the next token, or 0 at the end of the token stream.
 */
int ltsyylex();

#endif /* LEXERTOKENSTREAM_H */
