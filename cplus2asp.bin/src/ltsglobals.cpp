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
