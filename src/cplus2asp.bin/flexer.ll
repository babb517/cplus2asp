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


%top{
#include <string>
#include "parser.h"
#include "flexertypes.h"
#include "ltsglobals.h"

#ifdef flexIN_HEADER
/**
 * @file flexer.h
 * @brief Contains rules and definitions used by flex to create a lexical analyzer.
 */

extern YYSTYPE yyxlval;
extern YYLTYPE yyxlloc;

extern int flexerLineNum;
extern int flexerCharPos;
extern std::string flexerFileName;

extern flexerValueType flexeryylvalType;

/**
 * Outputs an error message to stderr.
 * Automatically adds file and line number information to the message.
 * @param msg - The specific message to add after the error header info.
 */
void flexerError(char const *msg);

/**
 * Resets the internal state of the flexer to initial values.
 */
void flexerReset();
#endif
}

%{
int flexerLineNum = 1; // Saves having to use yylineno.
int flexerCharPos = 1; // Tracks current start character position to help populate yylloc.
std::string flexerFileName = ""; // Stores the file name (or equivalent identifier) for what yyin is pointing at.
flexerValueType flexeryylvalType;

void flexerError(char const *);

std::string tempStr = ""; // Used to collect string data in token rules.
YYLTYPE tempLoc; // Used to collect temporary location data for block text.

// Macro definitions to help set and return proper token values.
// Designed to be sent to intermediate "parser", hence the "yyx" prefix for the parser-specific variables (vs. standard "yy").
#define TOK_INT(value) \
yyxlloc.first_line = yyxlloc.last_line = flexerLineNum; \
yyxlloc.first_column = flexerCharPos - yyleng; \
yyxlloc.last_column = flexerCharPos - 1; \
yyxlval.integer = value; \
flexeryylvalType = VT_INT;

#define TOK_IDENT \
yyxlloc.first_line = yyxlloc.last_line = flexerLineNum; \
yyxlloc.first_column = flexerCharPos - yyleng; \
yyxlloc.last_column = flexerCharPos - 1; \
yyxlval.str = new std::string(yytext, yyleng); \
flexeryylvalType = VT_STR;

#define TOK_STR(strText) \
yyxlloc.first_line = yyxlloc.last_line = flexerLineNum; \
yyxlloc.first_column = flexerCharPos - strText.length(); \
yyxlloc.last_column = flexerCharPos - 1; \
yyxlval.str = new std::string(strText); \
flexeryylvalType = VT_STR;

#define TOK_COMMENT(strText,isComment) \
yyxlloc.first_line = tempLoc.first_line; \
yyxlloc.last_line = tempLoc.last_line; \
yyxlloc.first_column = tempLoc.first_column; \
yyxlloc.last_column = tempLoc.last_column; \
yyxlval.com = new Comment(); \
yyxlval.com->fileName = flexerFileName; \
yyxlval.com->contents = strText; \
yyxlval.com->loc->first_line = tempLoc.first_line; \
yyxlval.com->loc->last_line = tempLoc.last_line; \
yyxlval.com->loc->first_column = tempLoc.first_column; \
yyxlval.com->loc->last_column = tempLoc.last_column; \
yyxlval.com->isRealComment = isComment; \
flexeryylvalType = VT_COMMENT;

#define TOK_ASP(strText) \
yyxlloc.first_line = tempLoc.first_line; \
yyxlloc.last_line = tempLoc.last_line; \
yyxlloc.first_column = tempLoc.first_column; \
yyxlloc.last_column = tempLoc.last_column; \
yyxlval.asp = new ASPCode(); \
yyxlval.asp->fileName = flexerFileName; \
yyxlval.asp->contents = strText; \
yyxlval.asp->loc->first_line = tempLoc.first_line; \
yyxlval.asp->loc->last_line = tempLoc.last_line; \
yyxlval.asp->loc->first_column = tempLoc.first_column; \
yyxlval.asp->loc->last_column = tempLoc.last_column; \
flexeryylvalType = VT_ASP;

#define TOK_EOF \
yyxlloc.first_line = yyxlloc.last_line = flexerLineNum; \
yyxlloc.first_column = flexerCharPos - yyleng; \
yyxlloc.last_column = flexerCharPos - yyleng; \
yyxlval.integer = 0; \
flexeryylvalType = VT_INT;

// Set to always increment the character position tracker whenever a new token is identified.
#define YY_USER_ACTION \
flexerCharPos += yyleng;

// Used as a pretend return value when bad syntax is encountered.
#define BAD_TOKEN -1

%}

%option nounput noyywrap
%option prefix="flex"

WHITESPACE			[ \f\r\t\v]+
INTEGER				[0-9]+
CAP_IDENT			[A-Z][a-zA-Z0-9_]*
LWR_IDENT			[a-z][a-zA-Z0-9_]*
UND_IDENT			_+[a-zA-Z0-9][a-zA-Z0-9_]*

%x BLK_SCOMMENT
%x LINE_COMMENT
%x SINGLE_QUOTE_STR
%x DOUBLE_QUOTE_STR
%x RAW_ASP
%x RAW_LUA

%%
"/*"				{
						// For the sake of everyone's sanity, we convert block comments
						// into line comments.
						tempStr = "% ";
						tempLoc.first_line = flexerLineNum;
						tempLoc.first_column = flexerCharPos - 2;
						BEGIN(BLK_SCOMMENT);
					}
	/* \%[^\n] */
\%					{
						tempStr = "";
						tempLoc.first_line = flexerLineNum;
						tempLoc.first_column = flexerCharPos - 1;
						BEGIN(LINE_COMMENT);
					}
	/* Grab comments of all shapes and sizes. */
<BLK_SCOMMENT>{
"*/"				{	// Block comment finished, return its contents.
						tempLoc.last_line = flexerLineNum;
						tempLoc.last_column = flexerCharPos;
						TOK_COMMENT(tempStr,true);
						BEGIN(INITIAL);
						return T_COMMENT;
					}
[^*\n]+				{	// Grab comment text in chunks.
						tempStr += yytext;
					}
"*"					{	// Grab a lone "*".
						tempStr += yytext;
					}
\n					{	// Handle newlines in block comments.
						flexerLineNum++;
						flexerCharPos = 1;
						tempStr += "\n% ";
					}
}
<LINE_COMMENT>{
[^\n]+				{	// Grab anything that isn't a newline.
						tempStr += yytext;
					}
\n					{	// Line comment finished, return its contents and aknowledge the newline.
						tempLoc.last_line = flexerLineNum;
						tempLoc.last_column = flexerCharPos;
						TOK_COMMENT(tempStr,true);
						flexerLineNum++;
						flexerCharPos = 1;
						BEGIN(INITIAL);
						return T_COMMENT;
					}
}
	/*\%\n				{	// Handle single-character comment corner case.
						tempStr = "";
						tempLoc.first_line = flexerLineNum;
						tempLoc.first_column = flexerCharPos - 2;
						tempLoc.last_line = flexerLineNum;
						tempLoc.last_column = flexerCharPos - 1;
						TOK_COMMENT(tempStr,true);
						flexerLineNum++;
						flexerCharPos = 1;
						return T_COMMENT;
					}*/

	/* Handle quoted strings gracefully. */
\'					{ BEGIN(SINGLE_QUOTE_STR); }
<SINGLE_QUOTE_STR>{
\\\'				{ tempStr += "'"; }
\'					{TOK_STR(tempStr); BEGIN(INITIAL); return T_STRING;}
\\					{ tempStr += "\\"; }
[^\n\\']+		{ tempStr += yytext; BEGIN(INITIAL); return T_STRING;}//Currently a hack, need to find a way to get the string into a token properly
\n					{
						TOK_EOF;
						flexerError("Unexpected line break in quoted string.");
						tempStr = "";
						flexerLineNum++;
						flexerCharPos = 1;
						BEGIN(INITIAL);
						return BAD_TOKEN;
					}
}
\"					{ BEGIN(DOUBLE_QUOTE_STR); }
<DOUBLE_QUOTE_STR>{
\\\"				{ tempStr += "\""; }
\"					{ TOK_STR(tempStr); BEGIN(INITIAL); return T_STRING; }
\\					{ tempStr += "\\"; }
[^\n\\"]+			{ tempStr += yytext; TOK_STR(tempStr); BEGIN(INITIAL); return T_STRING;}
\n					{
						TOK_EOF;
						flexerError("Unexpected line break in quoted string.");
						tempStr = "";
						flexerLineNum++;
						flexerCharPos = 1;
						BEGIN(INITIAL);
						return BAD_TOKEN;
					}
}
	/* Intercept any raw ASP code blocks and pass them straight through. */
^\:\-{WHITESPACE}begin_asp\.		{
									tempStr = "";
									tempLoc.first_line = flexerLineNum;
									tempLoc.first_column = flexerCharPos - 2;
									BEGIN(RAW_ASP);
								}
<RAW_ASP>{
^\:\-{WHITESPACE}end_asp\.		{	// ASP code block finished, return its contents.
									tempLoc.last_line = flexerLineNum;
									tempLoc.last_column = flexerCharPos;
									TOK_ASP(tempStr);
									BEGIN(INITIAL);
									return T_ASP;
								}
[^\n]+							{	// Grab anything that isn't a newline.
									tempStr += yytext;
								}
\n								{	// Handle newlines in ASP code blocks.
									flexerLineNum++;
									flexerCharPos = 1;
									tempStr += "\n";
								}
}

^\#begin_lua	{	
									tempStr = "#begin_lua";
									tempLoc.first_line = flexerLineNum;
									tempLoc.first_column = flexerCharPos - 2;
									BEGIN(RAW_LUA);
								}
<RAW_LUA>{
^\#end_lua\.		{	// LUA code block finished, return its contents.
									tempStr += "#end_lua.";
									tempLoc.last_line = flexerLineNum;
									tempLoc.last_column = flexerCharPos;
									TOK_ASP(tempStr);
									BEGIN(INITIAL);
									return T_ASP;
								}

[^\n]+							{	// Grab anything that isn't a newline.
									tempStr += yytext;
								}
\n								{	// Handle newlines in LUA code blocks.
									flexerLineNum++;
									flexerCharPos = 1;
									tempStr += "\n";
								}
}

^{WHITESPACE}$		{	// Lines that are just whitespace get passed through as special comments.
						tempStr = yytext;
						//tempStr += "\n";
						tempLoc.first_line = flexerLineNum;
						tempLoc.first_column = flexerCharPos - yyleng;
						tempLoc.last_line = flexerLineNum;
						tempLoc.last_column = flexerCharPos - 1;
						TOK_COMMENT(tempStr,false);
						flexerLineNum++;
						flexerCharPos = 1;
						return T_COMMENT;
					}
^\n					{	// Empty, blank lines get passed through as special comments.
						//tempStr = "\n";
						tempStr = "";
						tempLoc.first_line = flexerLineNum;
						tempLoc.first_column = flexerCharPos - yyleng;
						tempLoc.last_line = flexerLineNum;
						tempLoc.last_column = flexerCharPos - 1;
						TOK_COMMENT(tempStr,false);
						flexerLineNum++;
						flexerCharPos = 1;
						return T_COMMENT;
					}
\n					{	// Handle normal newlines.
						flexerLineNum++;
						flexerCharPos = 1;
					}

{WHITESPACE}		// Eat any unclaimed whitespace.

"NOOP"				{ TOK_INT(T_NOOP); return T_NOOP; }
"constants"			{ TOK_INT(T_CONSTANTS); return T_CONSTANTS; }
"include"			{ TOK_INT(T_INCLUDE); return T_INCLUDE; }
"macros"			{ TOK_INT(T_MACROS); return T_MACROS; }
"objects"			{ TOK_INT(T_OBJECTS); return T_OBJECTS; }
"query"				{ TOK_INT(T_QUERY); return T_QUERY; }
"show"				{ TOK_INT(T_SHOW); return T_SHOW; }
"sorts"				{ TOK_INT(T_SORTS); return T_SORTS; }
"variables"			{ TOK_INT(T_VARIABLES); return T_VARIABLES; }

"abAction"			{ TOK_INT(T_ABACTION); return T_ABACTION; }
"action"			{ TOK_INT(T_ACTION); return T_ACTION; }
"additiveAction"	{ TOK_INT(T_ADDITIVEACTION); return T_ADDITIVEACTION; }
"additiveFluent"	{ TOK_INT(T_ADDITIVEFLUENT); return T_ADDITIVEFLUENT; }
"after"				{ TOK_INT(T_AFTER); return T_AFTER; }
"always"			{ TOK_INT(T_ALWAYS); return T_ALWAYS; }
"attribute"			{ TOK_INT(T_ATTRIBUTE); return T_ATTRIBUTE; }
"assuming"			{ TOK_INT(T_ASSUMING); return T_ASSUMING; }
"by"				{ TOK_INT(T_BY); return T_BY; }
"caused"			{ TOK_INT(T_CAUSED); return T_CAUSED; }
"causes"			{ TOK_INT(T_CAUSES); return T_CAUSES; }
"impossible"			{ TOK_INT(T_IMPOSSIBLE); return T_IMPOSSIBLE; }
"constraint"		{ TOK_INT(T_CONSTRAINT); return T_CONSTRAINT; }
"decrements"		{ TOK_INT(T_DECREMENTS); return T_DECREMENTS; }
"default"			{ TOK_INT(T_DEFAULT); return T_DEFAULT; }
"dynamicAbnormality"	{ TOK_INT(T_DYNAMICAB); return T_DYNAMICAB; }
"exogenous"			{ TOK_INT(T_EXOGENOUS); return T_EXOGENOUS; }
"exogenousAction"	{ TOK_INT(T_EXOGENOUSACTION); return T_EXOGENOUSACTION; }
"if"				{ TOK_INT(T_IF); return T_IF; }
"increments"		{ TOK_INT(T_INCREMENTS); return T_INCREMENTS; }
"inertial"			{ TOK_INT(T_INERTIAL); return T_INERTIAL; }
"inertialFluent"	{ TOK_INT(T_INERTIALFLUENT); return T_INERTIALFLUENT; }
"label"				{ TOK_INT(T_LABEL); return T_LABEL; }
"may cause"			{ TOK_INT(T_MAY_CAUSE); return T_MAY_CAUSE; }
"maxAdditive"		{ TOK_INT(T_MAXADDITIVE); return T_MAXADDITIVE; }
"maxstep"			{ TOK_INT(T_MAXSTEP); return T_MAXSTEP; }
"never"				{ TOK_INT(T_NEVER); return T_NEVER; }
"noconcurrency"		{ TOK_INT(T_NOCONCURRENCY); return T_NOCONCURRENCY; }
"strong_noconcurrency" { TOK_INT(T_STRONG_NOCONCURRENCY); return T_STRONG_NOCONCURRENCY; }
"nonexecutable"		{ TOK_INT(T_NONEXECUTABLE); return T_NONEXECUTABLE; }
"of"				{ TOK_INT(T_OF); return T_OF; }
"possibly caused"	{ TOK_INT(T_POSSIBLY_CAUSED); return T_POSSIBLY_CAUSED; }
"rigid"				{ TOK_INT(T_RIGID); return T_RIGID; }
"sdFluent"			{ TOK_INT(T_SDFLUENT); return T_SDFLUENT; }
"simpleFluent"		{ TOK_INT(T_SIMPLEFLUENT); return T_SIMPLEFLUENT; }
"staticAbnormality" { TOK_INT(T_STATICAB); return T_STATICAB; }
"unless"			{ TOK_INT(T_UNLESS); return T_UNLESS; }
"when"				{ TOK_INT(T_WHEN); return T_WHEN; }
"following"			{ TOK_INT(T_FOLLOWING); return T_FOLLOWING; }
"where"				{ TOK_INT(T_WHERE); return T_WHERE; }

":-"				{ TOK_INT(T_COLON_DASH); return T_COLON_DASH; }
"::"				{ TOK_INT(T_DBL_COLON); return T_DBL_COLON; }
":"					{ TOK_INT(T_COLON); return T_COLON; }

"->>"				{ TOK_INT(T_IMPL); return T_IMPL; }
"->"				{ TOK_INT(T_ARROW_RDASH); return T_ARROW_RDASH; }
"-"					{ TOK_INT(T_DASH); return T_DASH; }

"<->"				{ TOK_INT(T_EQUIV); return T_EQUIV; }
"<-"				{ TOK_INT(T_ARROW_LDASH); return T_ARROW_LDASH; }
"<="				{ TOK_INT(T_ARROW_LEQ); return T_ARROW_LEQ; }
"<>"				{ TOK_INT(T_NOT_EQ); return T_NOT_EQ; }
"<"				{ TOK_INT(T_LTHAN); return T_LTHAN; }
"@<"				{ TOK_INT(T_LTHAN); return T_LTHAN; }			// less than in sorted order.

">="				{ TOK_INT(T_GTHAN_EQ); return T_GTHAN_EQ; }
"@>="				{ TOK_INT(T_GTHAN_EQ); return T_GTHAN_EQ; }		// greater than equal in sorted order.
">>"				{ TOK_INT(T_DBL_GTHAN); return T_DBL_GTHAN; }
">"				{ TOK_INT(T_GTHAN); return T_GTHAN; }
"@>"				{ TOK_INT(T_GTHAN); return T_GTHAN; }			// greater than in sorted order.

"=>"				{ TOK_INT(T_ARROW_REQ); return T_ARROW_REQ; }
"=<"				{ TOK_INT(T_EQ_LTHAN); return T_EQ_LTHAN; }
"@=<"				{ TOK_INT(T_EQ_LTHAN); return T_EQ_LTHAN; }		// less than equal in sorted order.
"=="				{ TOK_INT(T_DBL_EQ); return T_DBL_EQ; }
"="				{ TOK_INT(T_EQ); return T_EQ; }

"&&"				{ TOK_INT(T_AMP); return T_AMP; }			// NOTE: we hide double ampersand from the parser.
"&"				{ TOK_INT(T_AMP); return T_AMP; }

"++"				{ TOK_INT(T_DBL_PLUS); return T_DBL_PLUS; }
"+"					{ TOK_INT(T_PLUS); return T_PLUS; }

".."				{ TOK_INT(T_DBL_PERIOD); return T_DBL_PERIOD; }
"."					{ TOK_INT(T_PERIOD); return T_PERIOD; }

"\\="				{ TOK_INT(T_NOT_EQ); return T_NOT_EQ; }
"\\/"				{ TOK_INT(T_BIG_DISJ); return T_BIG_DISJ; }

"//"				{ TOK_INT(T_INT_DIV); return T_INT_DIV; }
"/\\"				{ TOK_INT(T_BIG_CONJ); return T_BIG_CONJ; }

","					{ TOK_INT(T_COMMA); return T_COMMA; }

";"					{ TOK_INT(T_SEMICOLON); return T_SEMICOLON; }

"|"					{ TOK_INT(T_PIPE); return T_PIPE; }

"#"					{ TOK_INT(T_POUND); return T_POUND; }

"*"					{ TOK_INT(T_STAR); return T_STAR; }

"@"					{ TOK_INT(T_AT); return T_AT; }

"["					{ TOK_INT(T_BRACKET_L); return T_BRACKET_L; }
"]"					{ TOK_INT(T_BRACKET_R); return T_BRACKET_R; }

"("					{ TOK_INT(T_PAREN_L); return T_PAREN_L; }
")"					{ TOK_INT(T_PAREN_R); return T_PAREN_R; }

"abs"				{ TOK_INT(T_ABS); return T_ABS; }
"eq"				{ TOK_INT(T_EQ); return T_EQ; }
"false"				{ TOK_INT(T_FALSE); return T_FALSE; }
"mod"				{ TOK_INT(T_MOD); return T_MOD; }
"neq"				{ TOK_INT(T_NOT_EQ); return T_NOT_EQ; }
"none"				{ TOK_INT(T_NONE); return T_NONE; }
"not"				{ TOK_INT(T_NOT); return T_NOT; }
"true"				{ TOK_INT(T_TRUE); return T_TRUE; }

{INTEGER}			{ TOK_INT(atoi(yytext)); return T_INTEGER; }
{CAP_IDENT}			{ TOK_IDENT; return T_IDENTIFIER; }
{LWR_IDENT}			{ TOK_IDENT; return T_IDENTIFIER; }
{UND_IDENT}			{ TOK_IDENT; return T_IDENTIFIER; }

					/* Match any other unrecognized character tokens, warn about them and stop. */
[^\n]				{
						TOK_EOF;
						std::string badTokErrStr = "";
						badTokErrStr += "Unexpected token \"";
						badTokErrStr += yytext;
						badTokErrStr += "\".";
						flexerError(badTokErrStr.c_str());
						return BAD_TOKEN;
					}

<BLK_SCOMMENT><<EOF>>	{
							TOK_EOF;
							flexerError("Unterminated \"/*\" block comment.");
							flexerLineNum = 1; // Reset flexerLineNum on EOF
							flexerCharPos = 1; // Also reset flexerCharPos
							return BAD_TOKEN;
						}
<SINGLE_QUOTE_STR><<EOF>>	{
								TOK_EOF;
								flexerError("Unterminated quoted string.");
								flexerLineNum = 1; // Reset flexerLineNum on EOF
								flexerCharPos = 1; // Also reset flexerCharPos
								return BAD_TOKEN;
							}
<DOUBLE_QUOTE_STR><<EOF>>	{
								TOK_EOF;
								flexerError("Unterminated quoted string.");
								flexerLineNum = 1; // Reset flexerLineNum on EOF
								flexerCharPos = 1; // Also reset flexerCharPos
								return BAD_TOKEN;
							}
<RAW_ASP><<EOF>>	{
						TOK_EOF;
						flexerError("Unterminated ASP code block.");
						flexerLineNum = 1; // Reset flexerLineNum on EOF
						flexerCharPos = 1; // Also reset flexerCharPos
						return BAD_TOKEN;
					}
<INITIAL><<EOF>>		{
							TOK_EOF;
							flexerLineNum = 1; // Reset flexerLineNum on EOF
							flexerCharPos = 1; // Also reset flexerCharPos
							yyterminate();
						}

%%

// Outputs an error message to stderr.
void flexerError(char const *msg)
{
	std::cerr << "% Syntax Error, ";
	if(flexerFileName.length() > 0)
	{
		std::cerr << "File \"" << flexerFileName << "\", ";
	}
	std::cerr << "Line #" << flexerLineNum << "." << (flexerCharPos - yyleng) << ": " << msg << std::endl;
	return;
}

// Resets the state of the flexer.
void flexerReset()
{
	flexerLineNum = 1;
	flexerCharPos = 1;
	YY_FLUSH_BUFFER;
	BEGIN(INITIAL);
	return;
}
