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


#include "Token.h"
#include "ltsglobals.h"

int ltsyyleng; // Equivalent to yyleng, the length of the last token retrieved by a call to the emulated yylex() function.
char *ltsyytext = NULL; // Equivalent to yytext, the contents of the last token retrieved by the emulated yylex().
size_t ltsyytextSize = 0; // Tracks the current size of the ltsyytext buffer (for resizing as necessary).
FILE *ltsyyin = NULL; // A stub equivalent of yyin, never touched or used.
FILE *ltsyyout = NULL; // A stub equivalent of yyout, never touched or used.
std::string ltsyyFileName = ""; // Emulated lexer enhancement making it aware of the file name it's processing.
flexerValueType ltsyylvalType; // Emulated lexer enhancement indicating the type of the value contained in yylval.
// yylval and yylloc are used by the parser, populated by the fake lexer.
extern YYSTYPE ltsyylval; // Equivalent to yylval, the type-transformed value of the last token retrieved by the emulated yylex().
extern YYLTYPE ltsyylloc; // Equivalent to yylloc, the struct that tracks the location of the last token retrieved by the emulated yylex().

// These let us pretend to be a bison-style parser from the perspective of a real lexer.
YYSTYPE yyxlval; // Our instance of yylval (for when we have to act as "parser" to a real lexer), named uniquely to avoid clashes.
YYLTYPE yyxlloc; // Our instance of yylloc (for when we have to act as "parser" to a real lexer), named uniquely to avoid clashes.
