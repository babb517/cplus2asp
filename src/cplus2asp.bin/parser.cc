/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         ltsyyparse
#define yylex           ltsyylex
#define yyerror         ltsyyerror
#define yylval          ltsyylval
#define yychar          ltsyychar
#define yydebug         ltsyydebug
#define yynerrs         ltsyynerrs
#define yylloc          ltsyylloc

/* Copy the first part of user declarations.  */


/* Line 268 of yacc.c  */
#line 79 "parser.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif

/* "%code requires" blocks.  */

/* Line 288 of yacc.c  */
#line 32 "parser.yy"

#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <libgen.h>
#include <string.h>

#include "types.h"
#include "DataStructs/Attribute.h"
#include "DataStructs/ASPCode.h"
#include "DataStructs/Comment.h"
#include "DataStructs/Constant.h"
#include "DataStructs/Object.h"
#include "DataStructs/NumberRange.h"
#include "DataStructs/Sort.h"
#include "DataStructs/Variable.h"
#include "DataStructs/Query.h"


#include "DataStructs/ElementCounter.h"
#include "DataStructs/SymbolTable.h"
#include "Translator.h"
#include "utilities.h"

#include "parser_types.h"

#include "ltsglobals.h"



/* Line 288 of yacc.c  */
#line 137 "parser.cc"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END = 0,
     T_INTEGER = 258,
     T_IDENTIFIER = 259,
     T_STRING = 260,
     T_ASP = 261,
     T_COMMENT = 262,
     T_CONSTANTS = 263,
     T_INCLUDE = 264,
     T_MACROS = 265,
     T_OBJECTS = 266,
     T_QUERY = 267,
     T_SHOW = 268,
     T_SORTS = 269,
     T_VARIABLES = 270,
     T_ABACTION = 271,
     T_ACTION = 272,
     T_ADDITIVEACTION = 273,
     T_ADDITIVEFLUENT = 274,
     T_AFTER = 275,
     T_ALWAYS = 276,
     T_ASSUMING = 277,
     T_ATTRIBUTE = 278,
     T_BY = 279,
     T_CAUSED = 280,
     T_CAUSES = 281,
     T_IMPOSSIBLE = 282,
     T_CONSTRAINT = 283,
     T_DECREMENTS = 284,
     T_DEFAULT = 285,
     T_DYNAMICAB = 286,
     T_EXOGENOUS = 287,
     T_EXOGENOUSACTION = 288,
     T_IF = 289,
     T_INCREMENTS = 290,
     T_INERTIAL = 291,
     T_INERTIALFLUENT = 292,
     T_LABEL = 293,
     T_MAY_CAUSE = 294,
     T_MAXADDITIVE = 295,
     T_MAXSTEP = 296,
     T_NEVER = 297,
     T_NOCONCURRENCY = 298,
     T_STRONG_NOCONCURRENCY = 299,
     T_NONEXECUTABLE = 300,
     T_OF = 301,
     T_POSSIBLY_CAUSED = 302,
     T_RIGID = 303,
     T_SDFLUENT = 304,
     T_SIMPLEFLUENT = 305,
     T_STATICAB = 306,
     T_UNLESS = 307,
     T_WHEN = 308,
     T_FOLLOWING = 309,
     T_WHERE = 310,
     T_FALSE = 311,
     T_NONE = 312,
     T_TRUE = 313,
     T_ABS = 314,
     T_AT = 315,
     T_BRACKET_L = 316,
     T_BRACKET_R = 317,
     T_COLON_DASH = 318,
     T_CBRACKET_L = 319,
     T_CBRACKET_R = 320,
     T_PAREN_L = 321,
     T_PAREN_R = 322,
     T_PERIOD = 323,
     T_PIPE = 324,
     T_NOOP = 325,
     T_SEMICOLON = 326,
     T_DBL_COLON = 327,
     T_ARROW_LDASH = 328,
     T_ARROW_REQ = 329,
     T_ARROW_LEQ = 330,
     T_ARROW_RDASH = 331,
     T_COLON = 332,
     T_COMMA = 333,
     T_EQUIV = 334,
     T_IMPL = 335,
     T_DBL_PLUS = 336,
     T_DBL_AMP = 337,
     T_AMP = 338,
     T_EQ = 339,
     T_GTHAN_EQ = 340,
     T_EQ_LTHAN = 341,
     T_GTHAN = 342,
     T_LTHAN = 343,
     T_NOT_EQ = 344,
     T_DBL_EQ = 345,
     T_NOT = 346,
     T_DBL_PERIOD = 347,
     T_PLUS = 348,
     T_DASH = 349,
     T_DBL_GTHAN = 350,
     T_MOD = 351,
     T_INT_DIV = 352,
     T_STAR = 353,
     T_BIG_CONJ = 354,
     T_BIG_DISJ = 355,
     T_POUND = 356,
     T_UMINUS = 357
   };
#endif
/* Tokens.  */
#define END 0
#define T_INTEGER 258
#define T_IDENTIFIER 259
#define T_STRING 260
#define T_ASP 261
#define T_COMMENT 262
#define T_CONSTANTS 263
#define T_INCLUDE 264
#define T_MACROS 265
#define T_OBJECTS 266
#define T_QUERY 267
#define T_SHOW 268
#define T_SORTS 269
#define T_VARIABLES 270
#define T_ABACTION 271
#define T_ACTION 272
#define T_ADDITIVEACTION 273
#define T_ADDITIVEFLUENT 274
#define T_AFTER 275
#define T_ALWAYS 276
#define T_ASSUMING 277
#define T_ATTRIBUTE 278
#define T_BY 279
#define T_CAUSED 280
#define T_CAUSES 281
#define T_IMPOSSIBLE 282
#define T_CONSTRAINT 283
#define T_DECREMENTS 284
#define T_DEFAULT 285
#define T_DYNAMICAB 286
#define T_EXOGENOUS 287
#define T_EXOGENOUSACTION 288
#define T_IF 289
#define T_INCREMENTS 290
#define T_INERTIAL 291
#define T_INERTIALFLUENT 292
#define T_LABEL 293
#define T_MAY_CAUSE 294
#define T_MAXADDITIVE 295
#define T_MAXSTEP 296
#define T_NEVER 297
#define T_NOCONCURRENCY 298
#define T_STRONG_NOCONCURRENCY 299
#define T_NONEXECUTABLE 300
#define T_OF 301
#define T_POSSIBLY_CAUSED 302
#define T_RIGID 303
#define T_SDFLUENT 304
#define T_SIMPLEFLUENT 305
#define T_STATICAB 306
#define T_UNLESS 307
#define T_WHEN 308
#define T_FOLLOWING 309
#define T_WHERE 310
#define T_FALSE 311
#define T_NONE 312
#define T_TRUE 313
#define T_ABS 314
#define T_AT 315
#define T_BRACKET_L 316
#define T_BRACKET_R 317
#define T_COLON_DASH 318
#define T_CBRACKET_L 319
#define T_CBRACKET_R 320
#define T_PAREN_L 321
#define T_PAREN_R 322
#define T_PERIOD 323
#define T_PIPE 324
#define T_NOOP 325
#define T_SEMICOLON 326
#define T_DBL_COLON 327
#define T_ARROW_LDASH 328
#define T_ARROW_REQ 329
#define T_ARROW_LEQ 330
#define T_ARROW_RDASH 331
#define T_COLON 332
#define T_COMMA 333
#define T_EQUIV 334
#define T_IMPL 335
#define T_DBL_PLUS 336
#define T_DBL_AMP 337
#define T_AMP 338
#define T_EQ 339
#define T_GTHAN_EQ 340
#define T_EQ_LTHAN 341
#define T_GTHAN 342
#define T_LTHAN 343
#define T_NOT_EQ 344
#define T_DBL_EQ 345
#define T_NOT 346
#define T_DBL_PERIOD 347
#define T_PLUS 348
#define T_DASH 349
#define T_DBL_GTHAN 350
#define T_MOD 351
#define T_INT_DIV 352
#define T_STAR 353
#define T_BIG_CONJ 354
#define T_BIG_DISJ 355
#define T_POUND 356
#define T_UMINUS 357




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 64 "parser.yy"

	/* Types returned by the lexer. */
	int integer;	 						///< Basic integer.
	std::string* str; 						///< String pointer.
	ASPCode* asp; 							///< Raw ASP code.
	Comment* com; 							///< Raw commented text.
	
	/* Classes directly used by the parser. */
	Attribute* attribute; 					///< Pointer to an Attribute element instance.
	Constant* constant; 					///< Pointer to a Constant element instance.
	NumberRange* numRange; 					///< Pointer to a NumRange element instance.
	Object* object; 						///< Pointer to an Object element instance.
	Sort* sort; 							///< Pointer to a Sort element instance.
	Variable* variable; 					///< Pointer to a Variable element instance.
	Constant::ConstantType constType; 		///< A ConstantType enum describing the type of a related constant.
	
	/* Containers used by the parser. */
	std::list<Constant*>* l_constant; 				///< Pointer to a list of Constant element pointers.
	ObjectList* l_object; 							///< Pointer to a list of Object element pointers.
	SortList* l_sort;		 						///< Pointer to a list of Sort element pointers.
	std::list<Variable*>* l_variable; 				///< Pointer to a list of Variable element pointers.
	ParseElementList* v_parseElement; 				///< Pointer to a list of ParseElement pointers.
	BigQuantifiers::QuantifierList* l_quantPair; 			///< List of pairs of QuantifierType enums and a associated ParseElement pointers.
	BigQuantifiers::Quantifier* p_quantPair; 			///< Pair of a QuantifierType enum and an associated ParseElement pointer.
			
	/* Types specific to the parser. */
	PT_constant_binder_t* constant_binder_t; 		///< An internal type for carrying information in a particular constant declaration grammar rule up the chain.
	ParseElement* parseElement; 					///< A pointer to a class like Element, but with translation features added and more loose ties to actual declared elements.
	
	/* Used to denote a rule whose $$ we don't care about and never (de)allocate or assign to. */
	void* not_used; 								///< Used for rules whose lvalues are not used or referenced by other grammar rules.



/* Line 293 of yacc.c  */
#line 395 "parser.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

/* "%code provides" blocks.  */

/* Line 340 of yacc.c  */
#line 97 "parser.yy"

/**
 * @file parser.h
 * @brief Contains parser for C+ programs, including definitions and helper functions.
 */

extern Translator mainTrans; ///< The main Translator instance, declared by the parser to create a close working relationship.
extern bool ltsyyendOfFile; ///< True if the parser has reached the end of the input stream.
extern int ltsyynerrs; ///< Output string stream used to store and output error messages from the parser and its helper modules.

/**
 * Invokes the parser, processing and translating input until either the end of input
 * or a fatal error are encountered.
 * @return 0 if parsing was successful (or if only non-fatal errors encountered), typically 1 if any fatal errors were encountered.
 */
int ltsyyparse();

/**
 * Wraps the given element in two new negation operators to create a "not not (...)." wrap.
 * @param elem - The element to wrap in a "not not (...)" wrapper.
 * @return A new SimpleUnaryOperator "not" object, wrapping another such object, wrapping the original element (or NULL if anything is invalid).
 */
SimpleUnaryOperator* createNotNot(ParseElement* elem);

/**
 * Deallocates a "not not" wrapper such that the original ParseElement is not deallocated.
 * Removes any parentheses flags from the original ParseElement object.
 * @param uop - The outermost "not" operator of the two to destroy.
 * @return The ParseElement object that was formerly wrapped by the two "not" operators (or NULL if anything is invalid).
 */
ParseElement* deallocateNotNot(SimpleUnaryOperator* uop);

/**
 * NULLs elem's preOp and postOp before deallocating so the sub-ParseElement objects don't get caught in the deallocation.
 * @param elem - The temporary SimpleBinaryOperator element to destroy.
 */
void deallocateTempBinaryOp(SimpleBinaryOperator* &elem);

/**
 * NULLs elem's postOp before deallocating so the sub-ParseElement object doesn't get caught in the deallocation.
 * @param elem - The temporary SimpleUnaryOperator element to destroy.
 */
void deallocateTempUnaryOp(SimpleUnaryOperator* &elem);

/**
 * Adds a standard parsing caution header to ltsyyossErr to make caution
 * notifications easier to pinpoint.
 * @param cautionLoc - YYLTYPE struct where the caution was invoked.
 */
void ltsyystartCaution(YYLTYPE cautionLoc);

/**
 * Adds a standard (location-unaware) parsing caution header to ltsyyossErr
 * to try making caution notifications easier to locate.
 */
void ltsyystartCaution();

/**
 * Caution reporting function for the parser.
 * Never called by bison, called by parser actions when a non-fatal
 * situation is identified that might produce unexpected/undesired
 * translation results.
 * If ltsyyossErr is empty, outputs a generic caution notification,
 * otherwise uses the existing contents of ltsyyossErr. In either case,
 * outputs to the same place errors go, always appends a newline, and
 * resets the contents of ltsyyossErr after outputting the caution.
 */
void ltsyycaution();

/**
 * Adds a standard parsing warning header to ltsyyossErr to make warning
 * notifications easier to pinpoint.
 * @param warningLoc - YYLTYPE struct where the warning was invoked.
 */
void ltsyystartWarning(YYLTYPE warningLoc);

/**
 * Adds a standard (location-unaware) parsing warning header to ltsyyossErr
 * to try making warning notifications easier to locate.
 */
void ltsyystartWarning();

/**
 * Warning reporting function for the parser.
 * Never called by bison, called by parser actions when a non-fatal
 * situation is identified that will probably produce unexpected/undesired
 * translation results.
 * If ltsyyossErr is empty, outputs a generic warning notification,
 * otherwise uses the existing contents of ltsyyossErr. In either case,
 * outputs to the same place errors go, always appends a newline, and
 * resets the contents of ltsyyossErr after outputting the warning.
 */
void ltsyywarning();

/**
 * Adds a standard parse error header to ltsyyossErr to make it easier
 * to report errors in actions.
 * @param errLoc - YYLTYPE struct of the location of the error.
 */
void ltsyystartParseError(YYLTYPE errLoc);

/**
 * Adds a standard (location-unaware) parse error header to ltsyyossErr to
 * make it easier to report errors in actions.
 */
void ltsyystartParseError();

/**
 * Adds a standard syntax error header to ltsyyossErr to make it easier
 * to report errors in actions.
 * @param errLoc - YYLTYPE struct of the location of the error.
 */
void ltsyystartSyntaxError(YYLTYPE errLoc);

/**
 * Adds a standard (location-unaware) syntax error header to ltsyyossErr to
 * make it easier to report errors in actions.
 */
void ltsyystartSyntaxError();

/**
 * Error reporting function for the bison parser.
 * Since bison's default error message ("syntax error") is not useful,
 * ignores the passed message and looks at the contents of the ltsyyossErr
 * stream to decide what to output. If ltsyyossErr is empty, outputs
 * a general syntax error message, otherwise outputs the contents of
 * ltsyyossErr. In either case, automatically adds a newline to the end
 * of the message.
 * Automatically clears the contents and state of ltsyyossErr after printing
 * the applicable error message.
 * @param msg - The (ignored) error message provided by bison.
 */
void ltsyyerror(char const* msg);

/**
 * Wraps caution reporting for convenience and unification with convention for error reporting.
 */
void ltsyyreportCaution();

/**
 * Wraps warning reporting for convenience and unification with convention for error reporting.
 */
void ltsyyreportWarning();

/**
 * Wraps error reporting for ease and to ensure the number of errors gets incremented with each (action-generated) error report.
 */
void ltsyyreportError();

/**
 * Retrives the name of the current file the parser is working with.
 */
std::string ltsyyGetFileName();

/**
 * Retrieves the current location of the parser.
 */
YYLTYPE ltsyyGetLoc();




/* Line 340 of yacc.c  */
#line 582 "parser.cc"

/* Copy the second part of user declarations.  */

/* Line 343 of yacc.c  */
#line 258 "parser.yy"

#include "lexerTokenStream.h"


/* Line 343 of yacc.c  */
#line 263 "parser.yy"

Translator mainTrans; 						// The main Translator instance, declared by the parser to create a close working relationship.
bool ltsyyendOfFile = false; 				// True if the parser has reached the end of the input stream.
std::ostringstream ltsyyossErr; 			// Output string stream used to store and output error messages from the parser and its helper modules.

/// Clears the contents and error flags of the output string stream used for error reporting.
#define LTSYYRESETOSS \
ltsyyossErr.str(""); \
ltsyyossErr.clear();

/// Placeholder value for parse rules whose lvals ($$) we don't end up needing.
#define PARSERULE_NOT_USED NULL

/// Clears out, deallocates, and nullifies a list/vector/etc. pointer.
#define deallocateList(lst) if (lst) { lst->clear(); delete lst; lst = NULL; }

/// Deallocates and nullifies a non-container pointer.
#define deallocateItem(item) if (item) { delete item; item = NULL; }

// Helper functions for actions.

/**
 * Tries to find an existing normal sort or declare a starred ("something*") sort.
 * Will not instantiate a normal sort (even as a child of a "something*" sort, will
 * report an error instead.
 * @param sortIdent - The name of the sort to check and find.
 * @return A pointer to the associated instantiated sort obect, or NULL if the sort wasn't found.
 */
Sort* checkDynamicSortDecl(std::string const& sortIdent);



/* Line 343 of yacc.c  */
#line 627 "parser.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  111
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   976

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  275
/* YYNRULES -- Number of states.  */
#define YYNSTATES  546

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   357

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    30,    32,    37,    39,    43,
      45,    49,    51,    55,    59,    61,    65,    67,    71,    73,
      77,    79,    84,    86,    91,    93,    97,    99,   104,   108,
     115,   121,   126,   128,   132,   134,   138,   140,   144,   148,
     150,   154,   156,   160,   162,   166,   168,   173,   175,   177,
     182,   184,   188,   190,   194,   199,   201,   205,   207,   211,
     215,   217,   221,   223,   225,   227,   229,   233,   235,   237,
     239,   242,   246,   248,   250,   252,   254,   256,   258,   260,
     262,   264,   266,   268,   273,   275,   279,   281,   285,   287,
     291,   295,   297,   301,   303,   307,   309,   310,   313,   314,
     317,   318,   321,   322,   325,   326,   329,   330,   333,   334,
     337,   340,   343,   345,   347,   349,   351,   353,   355,   357,
     359,   361,   363,   365,   367,   369,   375,   383,   391,   399,
     409,   414,   419,   426,   430,   440,   448,   457,   459,   461,
     472,   483,   492,   502,   504,   506,   508,   510,   514,   516,
     519,   523,   527,   531,   535,   537,   541,   543,   547,   551,
     555,   557,   559,   561,   563,   565,   569,   571,   574,   578,
     582,   586,   590,   592,   596,   598,   600,   602,   606,   608,
     612,   614,   616,   619,   623,   627,   633,   639,   641,   643,
     646,   649,   652,   655,   660,   662,   666,   670,   674,   678,
     682,   684,   686,   690,   694,   696,   699,   703,   707,   711,
     715,   717,   721,   723,   727,   731,   735,   737,   743,   746,
     751,   757,   758,   760,   762,   766,   768,   770,   774,   776,
     778,   780,   782,   784,   788,   790,   794,   798,   802,   806,
     810,   813,   818,   820,   822,   826,   828,   830,   832,   835,
     837,   841,   843,   847,   851,   855,   859,   863,   865,   867,
     869,   871,   873,   875,   877,   879
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     104,     0,    -1,    -1,   105,    -1,   106,    -1,   105,   106,
      -1,   107,    -1,   119,    -1,   120,    -1,   194,    -1,   129,
      -1,   132,    -1,   142,    -1,   157,    -1,     1,    68,    -1,
      70,    -1,    63,     8,   108,    68,    -1,   109,    -1,    66,
     109,    67,    -1,   110,    -1,   108,    71,   110,    -1,   111,
      -1,    66,   111,    67,    -1,   112,    72,   117,    -1,   113,
      -1,    66,   113,    67,    -1,   114,    -1,   112,    78,   114,
      -1,   115,    -1,    66,   115,    67,    -1,     4,    -1,     4,
      66,   206,    67,    -1,     4,    -1,     4,    66,   206,    67,
      -1,   118,    -1,    66,   118,    67,    -1,   136,    -1,   141,
      66,   138,    67,    -1,    23,    46,   116,    -1,    23,    66,
     138,    67,    46,   116,    -1,    63,    40,    72,   213,    68,
      -1,    63,    11,   121,    68,    -1,   122,    -1,    66,   122,
      67,    -1,   123,    -1,   121,    71,   121,    -1,   124,    -1,
      66,   124,    67,    -1,   125,    72,   137,    -1,   126,    -1,
      66,   126,    67,    -1,   127,    -1,   125,    78,   127,    -1,
     128,    -1,    66,   128,    67,    -1,     4,    -1,     4,    66,
     206,    67,    -1,   213,    -1,   211,    -1,    63,    13,   130,
      68,    -1,   131,    -1,   130,    71,   131,    -1,   202,    -1,
     202,    84,   207,    -1,    63,    14,   133,    68,    -1,   134,
      -1,    66,   134,    67,    -1,   135,    -1,   133,    71,   133,
      -1,   133,    78,   133,    -1,   139,    -1,   139,    95,   133,
      -1,   137,    -1,    51,    -1,    31,    -1,   138,    -1,    66,
     138,    67,    -1,   139,    -1,   211,    -1,   140,    -1,   140,
      98,    -1,   140,    93,    57,    -1,     4,    -1,   141,    -1,
      16,    -1,    17,    -1,    18,    -1,    19,    -1,    33,    -1,
      37,    -1,    48,    -1,    49,    -1,    50,    -1,    63,    15,
     143,    68,    -1,   144,    -1,    66,   144,    67,    -1,   145,
      -1,   145,    71,   143,    -1,   146,    -1,    66,   146,    67,
      -1,   147,    72,   149,    -1,   148,    -1,    66,   148,    67,
      -1,     4,    -1,   148,    78,     4,    -1,   137,    -1,    -1,
      34,   174,    -1,    -1,    22,   174,    -1,    -1,    20,   174,
      -1,    -1,    52,   202,    -1,    -1,    53,   179,    -1,    -1,
      54,   180,    -1,    -1,    55,   178,    -1,   158,    68,    -1,
     172,    68,    -1,   159,    -1,   160,    -1,   161,    -1,   162,
      -1,   163,    -1,   164,    -1,   165,    -1,   166,    -1,   167,
      -1,   168,    -1,   169,    -1,   170,    -1,   171,    -1,    21,
     174,   153,   154,   156,    -1,    28,   174,   152,   153,   154,
     155,   156,    -1,    27,   174,   152,   153,   154,   155,   156,
      -1,    42,   174,   152,   153,   154,   155,   156,    -1,    30,
     173,   150,   151,   152,   153,   154,   155,   156,    -1,    32,
     202,   153,   156,    -1,    36,   202,   153,   156,    -1,    45,
     174,   150,   153,   154,   156,    -1,    48,   202,   156,    -1,
      47,   173,   150,   151,   152,   153,   154,   155,   156,    -1,
     174,    39,   173,   150,   151,   154,   156,    -1,   174,    26,
     173,   150,   151,   153,   154,   156,    -1,    43,    -1,    44,
      -1,   174,    35,   173,    24,   208,   150,   151,   153,   154,
     156,    -1,   174,    29,   173,    24,   208,   150,   151,   153,
     154,   156,    -1,   174,   150,   151,   152,   153,   154,   155,
     156,    -1,    25,   173,   150,   151,   152,   153,   154,   155,
     156,    -1,   185,    -1,    58,    -1,    56,    -1,   175,    -1,
      66,   175,    67,    -1,   176,    -1,   216,   174,    -1,   174,
     215,   174,    -1,   174,    81,   174,    -1,   174,    79,   174,
      -1,   174,    80,   174,    -1,   177,    -1,    66,   177,    67,
      -1,   207,    -1,   207,    84,   207,    -1,   207,    89,   207,
      -1,   207,   217,   207,    -1,   189,    -1,   174,    -1,   181,
      -1,   181,    -1,   182,    -1,    66,   182,    67,    -1,   183,
      -1,   216,   181,    -1,   181,   215,   181,    -1,   181,    81,
     181,    -1,   181,    79,   181,    -1,   181,    80,   181,    -1,
     184,    -1,    66,   184,    67,    -1,   202,    -1,   190,    -1,
     186,    -1,    66,   186,    67,    -1,   187,    -1,   185,   215,
     185,    -1,   188,    -1,   202,    -1,   216,   202,    -1,   202,
      84,   207,    -1,    64,   187,    65,    -1,    61,   191,    69,
     174,    62,    -1,    61,   191,    69,   181,    62,    -1,   192,
      -1,   193,    -1,   191,   192,    -1,   191,   193,    -1,    99,
       4,    -1,   100,     4,    -1,    63,    12,   195,    68,    -1,
     196,    -1,   195,    71,   195,    -1,    38,    72,     4,    -1,
      38,    72,     3,    -1,    41,    72,   211,    -1,    41,    72,
     212,    -1,   197,    -1,   198,    -1,    66,   197,    67,    -1,
     209,    77,   197,    -1,   199,    -1,   216,   197,    -1,   197,
     215,   197,    -1,   197,    81,   197,    -1,   197,    79,   197,
      -1,   197,    80,   197,    -1,   200,    -1,    66,   200,    67,
      -1,   207,    -1,   207,    84,   207,    -1,   207,    89,   207,
      -1,   207,   217,   207,    -1,   201,    -1,    61,   191,    69,
     197,    62,    -1,   203,     4,    -1,   203,     4,    66,    67,
      -1,   203,     4,    66,   204,    67,    -1,    -1,    60,    -1,
     205,    -1,   204,    78,   205,    -1,   207,    -1,   138,    -1,
     206,    78,   138,    -1,    58,    -1,    56,    -1,    57,    -1,
     208,    -1,   209,    -1,    66,   209,    67,    -1,   210,    -1,
     208,    93,   208,    -1,   208,    94,   208,    -1,   208,    98,
     208,    -1,   208,    97,   208,    -1,   208,    96,   208,    -1,
      59,   208,    -1,    59,    66,   208,    67,    -1,   212,    -1,
     202,    -1,   213,    92,   213,    -1,     3,    -1,    40,    -1,
      41,    -1,    94,   212,    -1,   214,    -1,    66,   214,    67,
      -1,   212,    -1,   213,    93,   213,    -1,   213,    94,   213,
      -1,   213,    98,   213,    -1,   213,    97,   213,    -1,   213,
      96,   213,    -1,    83,    -1,    78,    -1,    94,    -1,    91,
      -1,    90,    -1,    86,    -1,    85,    -1,    88,    -1,    87,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   473,   473,   474,   485,   486,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   503,   511,   514,   515,   518,
     519,   522,   523,   526,   679,   683,   689,   698,   722,   726,
     732,   738,   752,   762,   778,   782,   788,   826,   849,   865,
     937,   954,   957,   958,   961,   962,   965,   966,   969,  1025,
    1029,  1035,  1045,  1069,  1073,  1079,  1085,  1092,  1098,  1107,
    1120,  1130,  1144,  1148,  1162,  1173,  1177,  1183,  1188,  1205,
    1224,  1234,  1247,  1251,  1256,  1263,  1267,  1275,  1280,  1358,
    1362,  1368,  1377,  1381,  1387,  1392,  1397,  1402,  1407,  1412,
    1417,  1422,  1427,  1436,  1439,  1440,  1443,  1444,  1447,  1448,
    1451,  1486,  1490,  1496,  1509,  1527,  1582,  1583,  1586,  1587,
    1590,  1591,  1594,  1595,  1598,  1599,  1602,  1603,  1606,  1607,
    1613,  1614,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1629,  1633,  1648,  1663,  1678,  1695,
    1715,  1729,  1743,  1759,  1780,  1799,  1816,  1834,  1840,  1848,
    1866,  1886,  1905,  1920,  1924,  1928,  1934,  1938,  1948,  1952,
    1956,  1960,  1964,  1968,  1974,  1978,  1988,  2007,  2012,  2016,
    2043,  2049,  2055,  2061,  2067,  2071,  2081,  2085,  2089,  2093,
    2097,  2101,  2107,  2111,  2121,  2129,  2135,  2139,  2149,  2153,
    2157,  2163,  2167,  2171,  2177,  2183,  2200,  2215,  2224,  2233,
    2265,  2299,  2338,  2379,  2408,  2412,  2418,  2436,  2454,  2473,
    2491,  2509,  2513,  2521,  2541,  2545,  2549,  2553,  2557,  2561,
    2567,  2571,  2581,  2600,  2604,  2608,  2635,  2641,  2658,  2701,
    2725,  2771,  2772,  2774,  2783,  2794,  2800,  2821,  2848,  2852,
    2856,  2860,  2866,  2870,  2881,  2885,  2889,  2893,  2897,  2901,
    2905,  2909,  2917,  2922,  2928,  2936,  2941,  2946,  2951,  2960,
    2964,  2974,  2978,  2987,  2996,  3005,  3014,  3026,  3030,  3036,
    3040,  3046,  3050,  3054,  3058,  3062
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "T_INTEGER", "T_IDENTIFIER",
  "T_STRING", "T_ASP", "T_COMMENT", "T_CONSTANTS", "T_INCLUDE", "T_MACROS",
  "T_OBJECTS", "T_QUERY", "T_SHOW", "T_SORTS", "T_VARIABLES", "T_ABACTION",
  "T_ACTION", "T_ADDITIVEACTION", "T_ADDITIVEFLUENT", "T_AFTER",
  "T_ALWAYS", "T_ASSUMING", "T_ATTRIBUTE", "T_BY", "T_CAUSED", "T_CAUSES",
  "T_IMPOSSIBLE", "T_CONSTRAINT", "T_DECREMENTS", "T_DEFAULT",
  "T_DYNAMICAB", "T_EXOGENOUS", "T_EXOGENOUSACTION", "T_IF",
  "T_INCREMENTS", "T_INERTIAL", "T_INERTIALFLUENT", "T_LABEL",
  "T_MAY_CAUSE", "T_MAXADDITIVE", "T_MAXSTEP", "T_NEVER",
  "T_NOCONCURRENCY", "T_STRONG_NOCONCURRENCY", "T_NONEXECUTABLE", "T_OF",
  "T_POSSIBLY_CAUSED", "T_RIGID", "T_SDFLUENT", "T_SIMPLEFLUENT",
  "T_STATICAB", "T_UNLESS", "T_WHEN", "T_FOLLOWING", "T_WHERE", "T_FALSE",
  "T_NONE", "T_TRUE", "T_ABS", "T_AT", "T_BRACKET_L", "T_BRACKET_R",
  "T_COLON_DASH", "T_CBRACKET_L", "T_CBRACKET_R", "T_PAREN_L", "T_PAREN_R",
  "T_PERIOD", "T_PIPE", "T_NOOP", "T_SEMICOLON", "T_DBL_COLON",
  "T_ARROW_LDASH", "T_ARROW_REQ", "T_ARROW_LEQ", "T_ARROW_RDASH",
  "T_COLON", "T_COMMA", "T_EQUIV", "T_IMPL", "T_DBL_PLUS", "T_DBL_AMP",
  "T_AMP", "T_EQ", "T_GTHAN_EQ", "T_EQ_LTHAN", "T_GTHAN", "T_LTHAN",
  "T_NOT_EQ", "T_DBL_EQ", "T_NOT", "T_DBL_PERIOD", "T_PLUS", "T_DASH",
  "T_DBL_GTHAN", "T_MOD", "T_INT_DIV", "T_STAR", "T_BIG_CONJ",
  "T_BIG_DISJ", "T_POUND", "T_UMINUS", "$accept", "program",
  "statement_sequence", "statement", "constant_statement",
  "constant_spec_outer_tuple", "constant_spec_tuple",
  "constant_outer_spec", "constant_spec", "constant_schema_outer_list",
  "constant_schema_list", "constant_outer_schema", "constant_schema",
  "constant_schema_nodecl", "constant_outer_binder", "constant_binder",
  "maxadditive_statement", "object_statement", "object_spec_outer_tuple",
  "object_spec_tuple", "object_outer_spec", "object_spec",
  "object_outer_schema_list", "object_schema_list", "object_outer_schema",
  "object_schema", "show_statement", "atomic_formula_list",
  "atomic_formula", "sort_statement", "sort_spec_outer_tuple",
  "sort_spec_tuple", "sort_spec", "sort_identifier_with_ab",
  "sort_outer_identifier", "sort_identifier", "sort_identifier_no_range",
  "sort_identifier_name", "sort_constant_name", "variable_statement",
  "variable_spec_outer_tuple", "variable_spec_tuple",
  "variable_outer_spec", "variable_spec", "variable_outer_list",
  "variable_list", "variable_binding", "cl_if_clause",
  "cl_assuming_clause", "cl_after_clause", "cl_unless_clause",
  "cl_when_clause", "cl_following_clause", "cl_where_clause", "causal_law",
  "causal_law_shortcut_forms", "cl_always_forms", "cl_constraint_forms",
  "cl_default_forms", "cl_exogenous_forms", "cl_inertial_forms",
  "cl_nonexecutable_forms", "cl_rigid_forms", "cl_possibly_caused_forms",
  "cl_may_cause_forms", "cl_causes_forms", "cl_noconcurrency_forms",
  "cl_increment_forms", "cl_trivial_forms", "causal_law_basic_forms",
  "cl_head_formula", "cl_body_formula", "cl_body_formula_inner",
  "cl_body_term", "cl_body_term_inner", "cl_where_expr", "cl_when_expr",
  "cl_following_expr", "cl_body_formula_bool",
  "cl_body_formula_bool_inner", "cl_body_term_bool",
  "cl_body_term_bool_inner", "literal_assign_choice_conj",
  "literal_assign_choice_conj_inner", "literal_assign_expr",
  "literal_assign_choice_expr", "expr_big_expression",
  "expr_big_expression_bool", "expr_big_quantifiers", "expr_big_conj",
  "expr_big_disj", "query_statement", "query_expression_tuple",
  "query_expression", "query_body_formula", "query_body_formula_inner",
  "query_body_term", "query_body_term_inner", "expr_big_query_expression",
  "constant_expr", "lua_indicator", "parameter_list", "parameter_general",
  "sort_identifier_list", "extended_value_expression",
  "extended_math_expression", "extended_math_expr_inner",
  "extended_math_term", "num_range", "extended_integer",
  "extended_integer_outer_expression", "extended_integer_expression",
  "AND", "NOT", "COMPARISON", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   104,   105,   105,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   107,   108,   108,   109,
     109,   110,   110,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   118,   118,
     119,   120,   121,   121,   122,   122,   123,   123,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   128,   128,   129,
     130,   130,   131,   131,   132,   133,   133,   134,   134,   134,
     135,   135,   136,   136,   136,   137,   137,   138,   138,   139,
     139,   139,   140,   140,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   142,   143,   143,   144,   144,   145,   145,
     146,   147,   147,   148,   148,   149,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   154,   155,   155,   156,   156,
     157,   157,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   159,   160,   160,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   169,   170,
     170,   171,   172,   173,   173,   173,   174,   174,   175,   175,
     175,   175,   175,   175,   176,   176,   177,   177,   177,   177,
     177,   178,   179,   180,   181,   181,   182,   182,   182,   182,
     182,   182,   183,   183,   184,   184,   185,   185,   186,   186,
     186,   187,   187,   187,   188,   189,   190,   191,   191,   191,
     191,   192,   193,   194,   195,   195,   196,   196,   196,   196,
     196,   197,   197,   197,   198,   198,   198,   198,   198,   198,
     199,   199,   200,   200,   200,   200,   200,   201,   202,   202,
     202,   203,   203,   204,   204,   205,   206,   206,   207,   207,
     207,   207,   208,   208,   209,   209,   209,   209,   209,   209,
     209,   209,   210,   210,   211,   212,   212,   212,   212,   213,
     213,   214,   214,   214,   214,   214,   214,   215,   215,   216,
     216,   217,   217,   217,   217,   217
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     4,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     4,     1,     4,     1,     3,     1,     4,     3,     6,
       5,     4,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     4,     1,     1,     4,
       1,     3,     1,     3,     4,     1,     3,     1,     3,     3,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     7,     7,     7,     9,
       4,     4,     6,     3,     9,     7,     8,     1,     1,    10,
      10,     8,     9,     1,     1,     1,     1,     3,     1,     2,
       3,     3,     3,     3,     1,     3,     1,     3,     3,     3,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     3,
       3,     3,     1,     3,     1,     1,     1,     3,     1,     3,
       1,     1,     2,     3,     3,     5,     5,     1,     1,     2,
       2,     2,     2,     4,     1,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     1,     2,     3,     3,     3,     3,
       1,     3,     1,     3,     3,     3,     1,     5,     2,     4,
       5,     0,     1,     1,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       2,     4,     1,     1,     3,     1,     1,     1,     2,     1,
       3,     1,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,   255,   231,   231,   231,   231,   231,   231,   231,
     256,   257,   231,   147,   148,   231,   231,   231,   239,   240,
     238,   231,   232,     0,     0,   231,    15,   270,   269,     0,
       0,     4,     6,     7,     8,    10,    11,    12,    13,     0,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,     0,   106,   156,   158,   164,   170,     9,
     253,     0,   166,   241,   242,   244,   252,   231,    14,   112,
     155,   154,   231,   231,   269,   106,   153,   186,   188,   190,
     191,   231,   110,   110,   106,   112,   112,   110,   106,   106,
     118,   231,     0,   250,     0,     0,     0,   197,   198,     0,
       0,   231,   231,     0,     0,     0,     0,   156,   164,   242,
     258,     1,     5,   120,   121,   231,   231,   231,   231,   231,
     268,   231,   231,   231,   267,   108,   231,   228,   231,   273,
     272,   275,   274,   231,   271,   231,   231,   231,   231,   231,
     231,   159,   231,   114,     0,     0,   186,   108,   231,   231,
     192,   231,   112,   112,   108,   118,   118,   112,   112,   108,
     231,   143,   231,     0,   201,   202,   231,   199,   200,    30,
       0,     0,    17,    19,    21,     0,    24,    26,    28,    55,
       0,     0,    42,    44,    46,     0,    49,    51,    53,    58,
     261,    57,   259,     0,   257,     0,   231,     0,   204,   210,
     211,   214,   220,   226,   222,   242,   231,     0,    60,    62,
      82,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,    65,    67,    70,    79,    83,   103,     0,     0,
      94,    96,    98,     0,   101,     0,   157,   165,   243,   106,
       0,   107,     0,   106,   162,   163,   161,   231,   110,   160,
     231,   167,   168,   169,   245,   246,   249,   248,   247,   113,
     231,   118,   194,   187,   110,   189,   193,   111,   114,   114,
     110,   140,   141,   114,   114,   110,   171,   119,     0,   251,
       0,     0,     0,    17,    21,    24,    28,    16,     0,     0,
       0,     0,     0,    42,    46,    49,    53,   259,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   242,   203,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   215,    59,   231,   231,     0,    65,
      64,     0,     0,     0,     0,    80,     0,     0,    98,   101,
      93,     0,     0,     0,     0,     0,   108,   231,   231,   108,
     109,   112,   229,     0,   233,   235,     0,   231,   115,   172,
     174,   176,   182,   185,   184,   231,   135,   112,   116,   116,
     112,   116,   118,   112,   195,   236,    77,     0,    78,     0,
      18,    22,    25,    29,     0,    20,     0,    74,    73,     0,
      23,    34,    36,    72,    75,    83,     0,    27,     0,    43,
      47,    50,    54,   260,    45,     0,    48,     0,    52,   254,
     262,   263,   266,   265,   264,   207,   206,   208,   261,   231,
     212,   221,   205,   218,   219,   217,   216,   223,   224,   225,
     213,    61,    63,    66,    68,    69,    71,    81,     0,     0,
      95,    99,   102,    97,   105,   100,   104,     0,    40,   112,
     106,   106,   114,   114,   230,   231,     0,     0,   174,   182,
     231,   231,   231,   231,   177,   114,   231,   118,   118,   114,
     118,   142,   114,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,     0,   114,   108,
     108,   118,   116,   234,   231,   175,   183,   180,   181,   179,
     178,   116,   117,   173,   137,   136,   116,   138,   116,   237,
       0,    32,    38,     0,    35,    76,     0,   227,   118,   112,
     112,   145,   118,     0,   118,   118,   118,     0,     0,    37,
     146,   114,   114,   151,   196,   152,   139,   144,     0,     0,
     118,   118,    33,    39,   150,   149
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    29,    30,    31,    32,   171,   172,   173,   174,   175,
     285,   177,   178,   512,   390,   391,    33,    34,   181,   182,
     183,   184,   185,   186,   187,   188,    35,   207,   208,    36,
     221,   222,   223,   392,   393,   375,   376,   225,   226,    37,
     229,   230,   231,   232,   233,   234,   445,   125,   248,   152,
     143,   261,   467,   161,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      75,    54,    55,    56,    57,   277,   358,   502,   359,   360,
     361,   362,    76,    77,    78,    79,    58,   363,    96,    97,
      98,    59,   197,   198,   199,   200,   201,   202,   203,    60,
      61,   353,   354,   377,    62,    63,    64,    65,   378,    66,
     379,   192,   126,    67,   135
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -291
static const yytype_int16 yypact[] =
{
     529,   -31,  -291,   787,   558,   787,   787,   558,    10,    10,
    -291,  -291,   787,  -291,  -291,   787,   558,    10,  -291,  -291,
    -291,   487,  -291,   -15,   594,   787,  -291,  -291,    53,    98,
     600,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,    54,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,   106,   893,  -291,  -291,  -291,  -291,  -291,
    -291,   112,   864,   428,  -291,  -291,  -291,   787,  -291,   249,
    -291,  -291,    -3,   109,  -291,   123,    75,  -291,  -291,  -291,
      82,    10,   330,   330,   123,   135,   135,   330,   264,   123,
     166,   669,    38,   428,   251,   252,   -10,  -291,  -291,    40,
     335,   774,    10,   881,    44,   188,   532,   169,   197,   198,
    -291,  -291,  -291,  -291,  -291,   558,   558,   787,   558,   558,
    -291,   787,   787,   787,  -291,   244,   787,   216,   814,  -291,
    -291,  -291,  -291,   814,  -291,   814,   669,   669,   669,   669,
     669,  -291,    10,   233,   241,    75,   230,   244,   109,   814,
    -291,   787,   135,   135,   244,   166,   166,   135,   135,   244,
     787,  -291,   669,   444,  -291,  -291,   787,  -291,  -291,   265,
      40,    -2,  -291,  -291,  -291,    59,  -291,  -291,  -291,   274,
     335,   134,  -291,  -291,  -291,   118,  -291,  -291,  -291,  -291,
    -291,   486,  -291,   292,   297,   -15,   801,   164,  -291,   810,
    -291,  -291,  -291,  -291,   871,   293,   801,   289,  -291,   290,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
     881,   217,  -291,  -291,   291,     9,  -291,  -291,    45,   319,
    -291,   323,  -291,   324,   328,    60,  -291,  -291,  -291,   123,
     378,   532,   394,   123,   232,   310,   336,   787,   412,  -291,
     846,  -291,  -291,  -291,   226,   226,  -291,  -291,  -291,  -291,
     339,   166,  -291,  -291,   412,  -291,  -291,   532,   233,   233,
     412,  -291,  -291,   233,   233,   412,   532,  -291,   428,  -291,
     687,   743,   369,   374,   375,   380,   385,  -291,    47,   664,
      48,   743,   383,   388,   389,   393,   399,   424,  -291,   335,
     770,   440,    60,    60,    60,    60,    60,    60,   237,    60,
      36,   595,   425,   146,  -291,   774,   801,   801,   801,   801,
     814,   814,   814,   801,  -291,  -291,    10,   814,   151,   426,
    -291,   881,   881,   881,   404,  -291,    63,   430,   431,   -20,
    -291,    44,   770,   441,    60,   500,   244,   669,   669,   244,
     532,   135,  -291,    73,  -291,  -291,   -15,   339,  -291,   884,
    -291,  -291,  -291,  -291,  -291,   339,  -291,   135,   462,   462,
     135,   462,   166,   135,  -291,  -291,  -291,    77,  -291,   486,
    -291,  -291,  -291,  -291,    64,  -291,    31,  -291,  -291,   703,
    -291,  -291,  -291,  -291,  -291,   442,   515,  -291,    89,  -291,
    -291,  -291,  -291,  -291,   383,   743,  -291,   454,  -291,   557,
     338,   338,  -291,  -291,  -291,  -291,  -291,  -291,   344,   801,
    -291,  -291,   460,   422,   609,   336,  -291,  -291,  -291,  -291,
     810,  -291,  -291,  -291,   151,  -291,  -291,  -291,   531,   431,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,   557,  -291,   135,
     196,   196,   233,   233,  -291,   814,   110,   884,   469,   472,
     339,   339,   339,   339,  -291,   233,   339,   166,   166,   233,
     166,  -291,   233,  -291,   743,    64,   375,   540,   743,   478,
     482,   743,   385,  -291,   482,   399,   855,   -20,   233,   244,
     244,   166,   462,  -291,   339,  -291,  -291,   605,   619,   336,
    -291,   462,  -291,   884,  -291,  -291,   462,  -291,   462,  -291,
     473,   489,  -291,   493,  -291,  -291,   495,  -291,   166,   135,
     135,  -291,   166,   863,   166,   166,   166,   743,   517,  -291,
    -291,   233,   233,  -291,  -291,  -291,  -291,  -291,   111,   540,
     166,   166,  -291,  -291,  -291,  -291
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -291,  -291,  -291,   534,  -291,   421,   447,   331,  -159,   154,
     -89,   341,  -165,    87,  -291,   246,  -291,  -291,  -154,   453,
    -291,   457,  -291,   458,   345,  -173,  -291,  -291,   343,  -291,
    -184,   445,  -291,  -291,  -262,  -277,   -74,  -291,  -255,  -291,
     352,   436,  -291,  -193,  -291,  -212,  -291,   -67,  -134,   -37,
     -71,    35,  -201,  -102,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
      76,   392,   646,  -291,   652,  -291,  -291,  -291,    16,   322,
    -291,   346,   -40,   623,   626,  -291,  -291,  -291,  -171,   -94,
     -93,  -291,   396,  -291,  -135,  -291,  -291,   512,  -291,    23,
    -291,  -291,   261,  -290,   -73,    24,    18,  -291,   -81,   -28,
     168,  -138,   -72,     2,   513
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -232
static const yytype_int16 yytable[] =
{
     110,   398,   167,   168,   148,   286,    81,   296,   147,    81,
     176,   284,   394,   264,   155,   156,   339,   154,    81,   189,
     270,   158,   159,   394,   310,   275,   292,    80,   204,   224,
      80,    85,    86,   145,   395,   338,   328,    68,   406,    80,
      90,     2,   297,   109,   169,    93,   153,   442,   227,   227,
     157,   169,   169,   271,   272,   251,     2,    22,   343,   166,
     252,   311,   253,     2,   110,   394,   287,   227,   169,   288,
      22,   324,   190,   148,    81,    81,   266,   477,    10,    11,
     444,   268,   269,    84,    94,    95,   273,   274,    27,    94,
      95,    74,    89,    10,    11,    80,    80,   478,   111,   189,
      10,    11,   334,   206,   150,   419,   170,   335,   265,   109,
     228,   336,   480,   384,   396,   163,   127,    81,    81,   205,
      81,    81,   113,   204,   339,   209,   344,   319,   484,   438,
     475,   289,    92,   204,   395,    94,    95,   290,    80,    80,
     454,    80,    80,   439,   473,   404,   224,   434,   435,   436,
      81,   455,   190,   120,    92,   474,   483,   117,   124,   366,
     254,   255,   256,   257,   258,   259,   149,   474,   468,    22,
     470,    80,   346,    72,   114,    73,   349,   355,   542,   494,
     109,   423,   424,   425,   426,   456,   278,   142,   430,   474,
     300,   239,   240,   148,   242,   243,   301,   509,   206,   176,
      27,   513,   298,    74,   516,   299,   297,   190,   206,    94,
      95,   351,   449,   238,   313,   452,   167,   168,   189,   286,
     189,   160,   331,   323,   205,   476,   487,   367,   417,   332,
     117,   482,   314,   370,   485,   315,   236,   538,   373,   319,
     415,   416,   204,   204,   204,   204,   204,   427,   428,   429,
     204,   297,   319,   190,   432,   164,   165,   224,   224,   224,
     235,   190,   365,   190,   237,   238,   247,   297,   191,   297,
     471,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     453,   418,   250,   364,   486,   330,   260,   463,   331,   136,
     137,   522,   138,   139,   140,   332,   465,   263,   117,   469,
     524,   142,   472,   368,   369,   525,   262,   526,   371,   372,
     286,   121,   122,   123,   190,   124,   190,   206,   206,   206,
     206,   206,   138,   139,   140,   206,   189,   120,   121,   122,
     123,   281,   124,   205,   205,   205,   205,   205,     2,   179,
     291,   205,   120,   121,   122,   123,   204,   124,   191,   209,
     151,   319,   319,   319,   319,   519,   520,   325,   319,   365,
     326,   190,   167,   168,   308,   504,   505,   365,   507,   309,
     323,   450,   451,   457,   327,    10,    11,   190,   488,   190,
     364,   464,   355,   489,   490,   463,   333,   340,   364,   521,
     122,   123,   463,   124,   341,    69,   342,    82,    83,    22,
     356,   180,   347,   345,    87,   357,   343,    88,   120,   121,
     122,   123,  -209,   124,   319,  -209,   530,   106,   348,   124,
     533,   206,   535,   536,   537,   463,   463,   463,   463,    92,
      27,   463,   151,    74,   305,   306,   307,   205,   544,   545,
     288,   380,   381,     2,   179,   446,   190,   382,   531,   532,
     190,   463,   383,   190,   299,   399,   400,     2,   179,   141,
     401,   437,   365,   365,   365,   365,   402,   191,   365,   191,
     409,   410,   411,   412,   413,   414,   497,   498,   499,   500,
      10,    11,   503,   364,   364,   364,   364,   491,   492,   364,
       2,   403,   421,   433,    10,    11,   365,   440,   441,   190,
     501,   316,   317,   318,   506,   124,   407,   508,   481,   241,
     523,   279,   447,   244,   245,   246,   466,   364,   249,   169,
     344,   136,   137,   518,   138,   139,   140,    10,    11,    -2,
       1,   315,     2,  -231,    92,   227,   495,   136,   137,   496,
     138,   139,   140,   267,   511,   514,    21,    22,    92,   515,
       3,   290,   276,    91,     4,   527,     5,     6,   280,     7,
     528,     8,   529,   539,   112,     9,   540,   541,   448,    10,
      11,    12,    13,    14,    15,   191,    16,    17,   302,   303,
     304,    92,   305,   306,   307,    18,    19,    20,    21,    22,
      23,   282,    24,   303,   304,    25,   305,   306,   307,    26,
      -3,     1,    99,     2,  -231,   100,   101,   102,   103,   104,
     120,   121,   122,   123,    70,   124,    71,   283,    22,   385,
      27,     3,    72,    28,    73,     4,   543,     5,     6,   510,
       7,   397,     8,   293,   105,   479,     9,   294,   295,   350,
      10,    11,    12,    13,    14,    15,   408,    16,    17,    27,
     303,   304,    74,   305,   306,   307,    18,    19,    20,    21,
      22,    23,   420,    24,   337,   329,    25,     2,   210,   431,
      26,   107,     2,   120,   316,   317,   318,   108,   124,   458,
     211,   212,   213,   214,   460,   461,   462,   386,   124,   317,
     318,    27,   124,   443,    28,   387,   146,   215,   144,   461,
     462,   216,   124,   459,    10,    11,     2,   210,   312,    10,
      11,   422,   217,   218,   219,   388,   493,   322,     0,   211,
     212,   213,   214,     0,     0,     0,   386,     0,    21,    22,
     389,     0,     0,     0,   387,   162,   215,     0,     0,     0,
     216,     0,     0,    10,    11,     0,     2,   210,     0,   374,
       0,   217,   218,   219,   388,     0,     0,     0,    92,   211,
     212,   213,   214,    92,     0,   120,   121,   122,   123,   405,
     124,     0,     0,     2,   210,     0,   215,     2,     0,     0,
     216,     0,     0,    10,    11,     0,   211,   212,   213,   214,
       2,   217,   218,   219,     0,     0,     0,    92,     0,     0,
       0,     0,     0,   215,     2,     0,     0,   216,     0,   344,
      10,    11,   193,     0,    10,   194,     0,     2,   217,   218,
     219,     0,     0,     0,     0,     0,     0,    10,    11,     0,
      18,    19,    20,    21,    22,   195,   405,    92,     0,     0,
     196,    10,    11,    18,    19,    20,    21,    22,    23,     2,
       0,     0,     0,    25,    10,    11,     0,    18,    19,    20,
      21,    22,   195,     0,    92,    27,     0,   196,    28,     0,
      18,    19,    20,    21,    22,     0,     0,     0,    27,     0,
     162,    28,     0,     0,     0,   210,    10,    11,   120,   316,
     317,   318,    27,   124,     0,    28,     0,   211,   212,   213,
     214,     0,    18,    19,    20,    21,    22,     0,    92,     0,
       0,     0,   162,   352,   215,     0,     0,   517,   216,   115,
       0,     0,   116,     0,     0,   534,     0,   117,   118,   217,
     218,   219,   119,   120,   316,   317,   318,     0,   124,     0,
      92,   120,   460,   461,   462,     0,   124,   220,   128,   129,
     130,   131,   132,   133,   134,   320,   129,   130,   131,   132,
     321,   134,   120,   460,   461,   462,     0,   124,     0,     0,
       0,   120,   121,   122,   123,     0,   124
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-291))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      28,   291,    96,    96,    76,   170,     4,   180,    75,     7,
      99,   170,   289,   147,    85,    86,   228,    84,    16,   100,
     154,    88,    89,   300,   195,   159,   180,     4,   101,   103,
       7,     8,     9,    73,   289,   228,   220,    68,   300,    16,
      17,     3,   180,    25,     4,    21,    83,    67,     4,     4,
      87,     4,     4,   155,   156,   128,     3,    60,    78,    69,
     133,   196,   135,     3,    92,   342,    68,     4,     4,    71,
      60,   206,   100,   145,    72,    73,   149,    46,    40,    41,
     342,   152,   153,     7,    99,   100,   157,   158,    91,    99,
     100,    94,    16,    40,    41,    72,    73,    66,     0,   180,
      40,    41,    93,   101,    81,    69,    66,    98,   148,    91,
      66,    66,   389,    66,    66,    91,     4,   115,   116,   101,
     118,   119,    68,   196,   336,   102,    66,   199,   405,    66,
      66,    72,    94,   206,   389,    99,   100,    78,   115,   116,
      67,   118,   119,   336,    67,   299,   220,   331,   332,   333,
     148,    78,   180,    78,    94,    78,    67,    34,    83,   261,
     136,   137,   138,   139,   140,   142,    84,    78,   369,    60,
     371,   148,   239,    64,    68,    66,   243,   250,    67,    69,
     162,   316,   317,   318,   319,   356,   162,    52,   323,    78,
      72,   115,   116,   265,   118,   119,    78,   474,   196,   288,
      91,   478,    68,    94,   481,    71,   344,   235,   206,    99,
     100,   248,   346,    67,   196,   349,   310,   310,   299,   384,
     301,    55,    71,    77,   206,   384,   438,   264,   309,    78,
      34,   396,    68,   270,   407,    71,    67,   527,   275,   311,
       3,     4,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   389,   324,   281,   327,     4,     4,   331,   332,   333,
      72,   289,   260,   291,    67,    67,    22,   405,   100,   407,
     372,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     351,   309,    66,   260,   419,    68,    53,   359,    71,    93,
      94,   492,    96,    97,    98,    78,   367,    67,    34,   370,
     501,    52,   373,   268,   269,   506,    65,   508,   273,   274,
     475,    79,    80,    81,   342,    83,   344,   315,   316,   317,
     318,   319,    96,    97,    98,   323,   407,    78,    79,    80,
      81,    66,    83,   315,   316,   317,   318,   319,     3,     4,
      66,   323,    78,    79,    80,    81,   419,    83,   180,   326,
      20,   423,   424,   425,   426,   489,   490,    68,   430,   357,
      71,   389,   456,   456,    72,   467,   468,   365,   470,    72,
      77,   347,   348,   357,    84,    40,    41,   405,   449,   407,
     357,   365,   455,   450,   451,   457,    95,    68,   365,   491,
      80,    81,   464,    83,    71,     3,    72,     5,     6,    60,
      61,    66,    24,   235,    12,    66,    78,    15,    78,    79,
      80,    81,    68,    83,   486,    71,   518,    25,    24,    83,
     522,   419,   524,   525,   526,   497,   498,   499,   500,    94,
      91,   503,    20,    94,    96,    97,    98,   419,   540,   541,
      71,    67,    67,     3,     4,     4,   474,    67,   519,   520,
     478,   523,    67,   481,    71,    67,    67,     3,     4,    67,
      67,    57,   460,   461,   462,   463,    67,   299,   466,   301,
     302,   303,   304,   305,   306,   307,   460,   461,   462,   463,
      40,    41,   466,   460,   461,   462,   463,   452,   453,   466,
       3,    67,    67,    67,    40,    41,   494,    67,    67,   527,
     465,    79,    80,    81,   469,    83,    66,   472,    66,   117,
     494,    67,   344,   121,   122,   123,    54,   494,   126,     4,
      66,    93,    94,   488,    96,    97,    98,    40,    41,     0,
       1,    71,     3,     4,    94,     4,    67,    93,    94,    67,
      96,    97,    98,   151,     4,    67,    59,    60,    94,    67,
      21,    78,   160,    66,    25,    66,    27,    28,   166,    30,
      67,    32,    67,    46,    30,    36,   531,   532,    68,    40,
      41,    42,    43,    44,    45,   407,    47,    48,    92,    93,
      94,    94,    96,    97,    98,    56,    57,    58,    59,    60,
      61,   170,    63,    93,    94,    66,    96,    97,    98,    70,
       0,     1,     8,     3,     4,    11,    12,    13,    14,    15,
      78,    79,    80,    81,    56,    83,    58,   170,    60,   288,
      91,    21,    64,    94,    66,    25,   539,    27,    28,   475,
      30,   290,    32,   180,    40,   389,    36,   180,   180,   247,
      40,    41,    42,    43,    44,    45,   301,    47,    48,    91,
      93,    94,    94,    96,    97,    98,    56,    57,    58,    59,
      60,    61,    67,    63,   228,   220,    66,     3,     4,   326,
      70,    25,     3,    78,    79,    80,    81,    25,    83,   357,
      16,    17,    18,    19,    79,    80,    81,    23,    83,    80,
      81,    91,    83,   341,    94,    31,    73,    33,    72,    80,
      81,    37,    83,   357,    40,    41,     3,     4,   196,    40,
      41,   315,    48,    49,    50,    51,   455,   204,    -1,    16,
      17,    18,    19,    -1,    -1,    -1,    23,    -1,    59,    60,
      66,    -1,    -1,    -1,    31,    66,    33,    -1,    -1,    -1,
      37,    -1,    -1,    40,    41,    -1,     3,     4,    -1,    62,
      -1,    48,    49,    50,    51,    -1,    -1,    -1,    94,    16,
      17,    18,    19,    94,    -1,    78,    79,    80,    81,    66,
      83,    -1,    -1,     3,     4,    -1,    33,     3,    -1,    -1,
      37,    -1,    -1,    40,    41,    -1,    16,    17,    18,    19,
       3,    48,    49,    50,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    33,     3,    -1,    -1,    37,    -1,    66,
      40,    41,    38,    -1,    40,    41,    -1,     3,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      56,    57,    58,    59,    60,    61,    66,    94,    -1,    -1,
      66,    40,    41,    56,    57,    58,    59,    60,    61,     3,
      -1,    -1,    -1,    66,    40,    41,    -1,    56,    57,    58,
      59,    60,    61,    -1,    94,    91,    -1,    66,    94,    -1,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    91,    -1,
      66,    94,    -1,    -1,    -1,     4,    40,    41,    78,    79,
      80,    81,    91,    83,    -1,    94,    -1,    16,    17,    18,
      19,    -1,    56,    57,    58,    59,    60,    -1,    94,    -1,
      -1,    -1,    66,    67,    33,    -1,    -1,    62,    37,    26,
      -1,    -1,    29,    -1,    -1,    62,    -1,    34,    35,    48,
      49,    50,    39,    78,    79,    80,    81,    -1,    83,    -1,
      94,    78,    79,    80,    81,    -1,    83,    66,    84,    85,
      86,    87,    88,    89,    90,    84,    85,    86,    87,    88,
      89,    90,    78,    79,    80,    81,    -1,    83,    -1,    -1,
      -1,    78,    79,    80,    81,    -1,    83
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    21,    25,    27,    28,    30,    32,    36,
      40,    41,    42,    43,    44,    45,    47,    48,    56,    57,
      58,    59,    60,    61,    63,    66,    70,    91,    94,   104,
     105,   106,   107,   119,   120,   129,   132,   142,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   174,   175,   176,   177,   189,   194,
     202,   203,   207,   208,   209,   210,   212,   216,    68,   174,
      56,    58,    64,    66,    94,   173,   185,   186,   187,   188,
     202,   216,   174,   174,   173,   202,   202,   174,   174,   173,
     202,    66,    94,   208,    99,   100,   191,   192,   193,     8,
      11,    12,    13,    14,    15,    40,   174,   175,   177,   209,
     212,     0,   106,    68,    68,    26,    29,    34,    35,    39,
      78,    79,    80,    81,    83,   150,   215,     4,    84,    85,
      86,    87,    88,    89,    90,   217,    93,    94,    96,    97,
      98,   174,    52,   153,   187,   185,   186,   150,   215,    84,
     202,    20,   152,   152,   150,   153,   153,   152,   150,   150,
      55,   156,    66,   208,     4,     4,    69,   192,   193,     4,
      66,   108,   109,   110,   111,   112,   113,   114,   115,     4,
      66,   121,   122,   123,   124,   125,   126,   127,   128,   211,
     212,   213,   214,    38,    41,    61,    66,   195,   196,   197,
     198,   199,   200,   201,   207,   209,   216,   130,   131,   202,
       4,    16,    17,    18,    19,    33,    37,    48,    49,    50,
      66,   133,   134,   135,   139,   140,   141,     4,    66,   143,
     144,   145,   146,   147,   148,    72,    67,    67,    67,   173,
     173,   174,   173,   173,   174,   174,   174,    22,   151,   174,
      66,   207,   207,   207,   208,   208,   208,   208,   208,   202,
      53,   154,    65,    67,   151,   185,   207,   174,   153,   153,
     151,   156,   156,   153,   153,   151,   174,   178,   208,    67,
     174,    66,   108,   109,   111,   113,   115,    68,    71,    72,
      78,    66,   121,   122,   124,   126,   128,   214,    68,    71,
      72,    78,    92,    93,    94,    96,    97,    98,    72,    72,
     191,   197,   200,   209,    68,    71,    79,    80,    81,   215,
      84,    89,   217,    77,   197,    68,    71,    84,   133,   134,
      68,    71,    78,    95,    93,    98,    66,   144,   146,   148,
      68,    71,    72,    78,    66,   213,   150,    24,    24,   150,
     174,   152,    67,   204,   205,   207,    61,    66,   179,   181,
     182,   183,   184,   190,   202,   216,   156,   152,   154,   154,
     152,   154,   154,   152,    62,   138,   139,   206,   211,   213,
      67,    67,    67,    67,    66,   110,    23,    31,    51,    66,
     117,   118,   136,   137,   138,   141,    66,   114,   206,    67,
      67,    67,    67,    67,   121,    66,   137,    66,   127,   213,
     213,   213,   213,   213,   213,     3,     4,   211,   212,    69,
      67,    67,   195,   197,   197,   197,   197,   207,   207,   207,
     197,   131,   207,    67,   133,   133,   133,    57,    66,   146,
      67,    67,    67,   143,   137,   149,     4,   213,    68,   151,
     208,   208,   151,   153,    67,    78,   191,   181,   182,   184,
      79,    80,    81,   215,   181,   153,    54,   155,   155,   153,
     155,   156,   153,    67,    78,    66,   111,    46,    66,   118,
     138,    66,   115,    67,   138,   128,   197,   148,   153,   150,
     150,   154,   154,   205,    69,    67,    67,   181,   181,   181,
     181,   154,   180,   181,   156,   156,   154,   156,   154,   138,
     112,     4,   116,   138,    67,    67,   138,    62,   154,   151,
     151,   156,   155,   181,   155,   155,   155,    66,    67,    67,
     156,   153,   153,   156,    62,   156,   156,   156,   206,    46,
     154,   154,    67,   116,   156,   156
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 4: /* "T_IDENTIFIER" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2214 "parser.cc"
	break;
      case 5: /* "T_STRING" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2223 "parser.cc"
	break;
      case 112: /* "constant_schema_outer_list" */

/* Line 1391 of yacc.c  */
#line 465 "parser.yy"
	{ if((yyvaluep->l_constant) != NULL) { deallocateList((yyvaluep->l_constant)); } };

/* Line 1391 of yacc.c  */
#line 2232 "parser.cc"
	break;
      case 113: /* "constant_schema_list" */

/* Line 1391 of yacc.c  */
#line 465 "parser.yy"
	{ if((yyvaluep->l_constant) != NULL) { deallocateList((yyvaluep->l_constant)); } };

/* Line 1391 of yacc.c  */
#line 2241 "parser.cc"
	break;
      case 114: /* "constant_outer_schema" */

/* Line 1391 of yacc.c  */
#line 459 "parser.yy"
	{ delete (yyvaluep->constant); };

/* Line 1391 of yacc.c  */
#line 2250 "parser.cc"
	break;
      case 115: /* "constant_schema" */

/* Line 1391 of yacc.c  */
#line 459 "parser.yy"
	{ delete (yyvaluep->constant); };

/* Line 1391 of yacc.c  */
#line 2259 "parser.cc"
	break;
      case 116: /* "constant_schema_nodecl" */

/* Line 1391 of yacc.c  */
#line 459 "parser.yy"
	{ delete (yyvaluep->constant); };

/* Line 1391 of yacc.c  */
#line 2268 "parser.cc"
	break;
      case 117: /* "constant_outer_binder" */

/* Line 1391 of yacc.c  */
#line 469 "parser.yy"
	{ if((yyvaluep->constant_binder_t) != NULL) { deallocateItem((yyvaluep->constant_binder_t)); } };

/* Line 1391 of yacc.c  */
#line 2277 "parser.cc"
	break;
      case 118: /* "constant_binder" */

/* Line 1391 of yacc.c  */
#line 469 "parser.yy"
	{ if((yyvaluep->constant_binder_t) != NULL) { deallocateItem((yyvaluep->constant_binder_t)); } };

/* Line 1391 of yacc.c  */
#line 2286 "parser.cc"
	break;
      case 125: /* "object_outer_schema_list" */

/* Line 1391 of yacc.c  */
#line 466 "parser.yy"
	{ if((yyvaluep->l_object) != NULL) { deallocateList((yyvaluep->l_object)); } };

/* Line 1391 of yacc.c  */
#line 2295 "parser.cc"
	break;
      case 126: /* "object_schema_list" */

/* Line 1391 of yacc.c  */
#line 466 "parser.yy"
	{ if((yyvaluep->l_object) != NULL) { deallocateList((yyvaluep->l_object)); } };

/* Line 1391 of yacc.c  */
#line 2304 "parser.cc"
	break;
      case 127: /* "object_outer_schema" */

/* Line 1391 of yacc.c  */
#line 461 "parser.yy"
	{ delete (yyvaluep->object); };

/* Line 1391 of yacc.c  */
#line 2313 "parser.cc"
	break;
      case 128: /* "object_schema" */

/* Line 1391 of yacc.c  */
#line 461 "parser.yy"
	{ delete (yyvaluep->object); };

/* Line 1391 of yacc.c  */
#line 2322 "parser.cc"
	break;
      case 133: /* "sort_spec_outer_tuple" */

/* Line 1391 of yacc.c  */
#line 467 "parser.yy"
	{ if((yyvaluep->l_sort) != NULL) { deallocateList((yyvaluep->l_sort)); } };

/* Line 1391 of yacc.c  */
#line 2331 "parser.cc"
	break;
      case 134: /* "sort_spec_tuple" */

/* Line 1391 of yacc.c  */
#line 467 "parser.yy"
	{ if((yyvaluep->l_sort) != NULL) { deallocateList((yyvaluep->l_sort)); } };

/* Line 1391 of yacc.c  */
#line 2340 "parser.cc"
	break;
      case 135: /* "sort_spec" */

/* Line 1391 of yacc.c  */
#line 463 "parser.yy"
	{ delete (yyvaluep->sort); };

/* Line 1391 of yacc.c  */
#line 2349 "parser.cc"
	break;
      case 136: /* "sort_identifier_with_ab" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2358 "parser.cc"
	break;
      case 137: /* "sort_outer_identifier" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2367 "parser.cc"
	break;
      case 138: /* "sort_identifier" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2376 "parser.cc"
	break;
      case 139: /* "sort_identifier_no_range" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2385 "parser.cc"
	break;
      case 140: /* "sort_identifier_name" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2394 "parser.cc"
	break;
      case 141: /* "sort_constant_name" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2403 "parser.cc"
	break;
      case 147: /* "variable_outer_list" */

/* Line 1391 of yacc.c  */
#line 468 "parser.yy"
	{ if((yyvaluep->l_variable) != NULL) { deallocateList((yyvaluep->l_variable)); } };

/* Line 1391 of yacc.c  */
#line 2412 "parser.cc"
	break;
      case 148: /* "variable_list" */

/* Line 1391 of yacc.c  */
#line 468 "parser.yy"
	{ if((yyvaluep->l_variable) != NULL) { deallocateList((yyvaluep->l_variable)); } };

/* Line 1391 of yacc.c  */
#line 2421 "parser.cc"
	break;
      case 149: /* "variable_binding" */

/* Line 1391 of yacc.c  */
#line 463 "parser.yy"
	{ delete (yyvaluep->sort); };

/* Line 1391 of yacc.c  */
#line 2430 "parser.cc"
	break;
      case 203: /* "lua_indicator" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2439 "parser.cc"
	break;
      case 206: /* "sort_identifier_list" */

/* Line 1391 of yacc.c  */
#line 467 "parser.yy"
	{ if((yyvaluep->l_sort) != NULL) { deallocateList((yyvaluep->l_sort)); } };

/* Line 1391 of yacc.c  */
#line 2448 "parser.cc"
	break;
      case 211: /* "num_range" */

/* Line 1391 of yacc.c  */
#line 460 "parser.yy"
	{ delete (yyvaluep->numRange); };

/* Line 1391 of yacc.c  */
#line 2457 "parser.cc"
	break;
      case 212: /* "extended_integer" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2466 "parser.cc"
	break;
      case 213: /* "extended_integer_outer_expression" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2475 "parser.cc"
	break;
      case 214: /* "extended_integer_expression" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2484 "parser.cc"
	break;

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 473 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 475 "parser.yy"
    { 
		(yyval.not_used) = PARSERULE_NOT_USED; 

		// Ensure that we append the footer
		// after the program has finished translating
		mainTrans.outputFooter();
		
}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 485 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 486 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 489 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 490 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 491 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 492 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 493 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 494 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 495 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 496 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 498 "parser.yy"
    { 
	(yyval.not_used) = PARSERULE_NOT_USED;
	/* On an error, go to the end of the bad statement and try to continue.
       Set the error handler to not wait to report syntax errors if more show up. */
	yyerrok;
}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 503 "parser.yy"
    {(yyval.not_used) = PARSERULE_NOT_USED;}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 511 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 514 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 515 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 518 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 519 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 522 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 523 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 527 "parser.yy"
    {

	// Fill in each Constant's type and domain and translate each of them.
	bool constantError = true; // Set to true if any of the constants have trouble getting added to the symbol table.
	Sort* tempSort = NULL;

	// double check that this is a valid constant type for the language we're working in.
	// TODO: This is where you would add other language constnat type checks.

	if ((yyvsp[(3) - (3)].constant_binder_t)) {

		switch (mainTrans.lang()) {
		case Translator::LANG_CPLUS:
			switch ((yyvsp[(3) - (3)].constant_binder_t)->constType) {
			case Constant::CONST_UNKNOWN:
				mainTrans.error("Bad constant declaration. The constant type is not recognized.", true);
				break;
			default:
				break;
			}
			break;

		case Translator::LANG_BC:
			switch ((yyvsp[(3) - (3)].constant_binder_t)->constType) {
			case Constant::CONST_UNKNOWN:
				mainTrans.error("Bad constant declaration. The constant type is not recognized.", true);
				break;
			case Constant::CONST_STATICAB:
			case Constant::CONST_DYNAMICAB:
				mainTrans.error("Bad constant declaration. Abnormality constants aren't supported in language BC.", true);
				break;
			case Constant::CONST_ATTRIBUTE:
				mainTrans.error("Bad constant declaration. The specified constant type isn't supported in language BC.", true);
				break;
			case Constant::CONST_ADDITIVEACTION:
			case Constant::CONST_ADDITIVEFLUENT:
				mainTrans.error("Bad constant declaration. Additive constants aren't supported in language BC.", true);
				break;
			case Constant::CONST_ACTION:
				// bc uses only exogenous actions.
				(yyvsp[(3) - (3)].constant_binder_t)->constType = Constant::CONST_EXOGENOUSACTION;
				break;
			case Constant::CONST_EXOGENOUSACTION:
				break;
			}
		case Translator::LANG_BCPLUS:
			switch ((yyvsp[(3) - (3)].constant_binder_t)->constType) {
			case Constant::CONST_UNKNOWN:
				mainTrans.error("Bad constant declaration. The constant type is not recognized.", true);
				break;
			case Constant::CONST_STATICAB:
			case Constant::CONST_DYNAMICAB:
				mainTrans.error("Bad constant declaration. Abnormality constants aren't supported in language BC.", true);
				break;
			case Constant::CONST_ATTRIBUTE:
				mainTrans.error("Bad constant declaration. The specified constant type isn't supported in language BC.", true);
				break;
			case Constant::CONST_ADDITIVEACTION:
			case Constant::CONST_ADDITIVEFLUENT:
				mainTrans.error("Bad constant declaration. Additive constants aren't supported in language BC.", true);
				break;
			case Constant::CONST_ACTION:
				break;
			case Constant::CONST_EXOGENOUSACTION:
				break;
			}
		}
	}

	if((yyvsp[(1) - (3)].l_constant) != NULL && (yyvsp[(3) - (3)].constant_binder_t) != NULL)
	{
		tempSort = (yyvsp[(3) - (3)].constant_binder_t)->domain;

		// directly referenced sorts should be made visible.
		if (tempSort) tempSort->internal(false);
		
		if((yyvsp[(3) - (3)].constant_binder_t)->constType == Constant::CONST_STATICAB || (yyvsp[(3) - (3)].constant_binder_t)->constType == Constant::CONST_DYNAMICAB || tempSort != NULL)
		{
			constantError = false;
			std::list<Constant*>::iterator lIter;
			// If the binding type is "attribute", turn the Constant objects into Attribute objects before adding them.
			if((yyvsp[(3) - (3)].constant_binder_t)->constType == Constant::CONST_ATTRIBUTE)
			{
				Attribute* tempAttribute = NULL;
				for(lIter = (yyvsp[(1) - (3)].l_constant)->begin(); lIter != (yyvsp[(1) - (3)].l_constant)->end(); ++lIter)
				{
					tempAttribute = (*lIter)->makeAttribute(NULL);
					deallocateItem(*lIter);
					(*lIter) = tempAttribute;
				}
			}
			
			for(lIter = (yyvsp[(1) - (3)].l_constant)->begin(); lIter != (yyvsp[(1) - (3)].l_constant)->end(); ++lIter)
			{	// Try to add each constant to the symbol table before hooking it up and translating it.
				int addSymResult = mainTrans.addSymbol(*lIter);
				if(addSymResult != SymbolTable::ADDSYM_OK)
				{	// Something went wrong adding this constant, skip connecting & translating it.
					if(addSymResult == SymbolTable::ADDSYM_DUP)
					{	// Duplicate constant declarations are errors, but give a separate error message for clarity.
						ltsyystartParseError(ltsyylloc);
						ltsyyossErr << "Duplicate constant declaration: \"" << (*lIter)->fullName() << "\".";
						ltsyyreportError();
						deallocateItem(*lIter);
						constantError = true;
					}
					else
					{	// Other constant adding errors can get grouped together.
						ltsyystartParseError(ltsyylloc);
						ltsyyossErr << "Bad constant declaration: \"" << (*lIter)->fullName() << "\".";
						ltsyyreportError();
						deallocateItem(*lIter);
						constantError = true;
					}
				}
				else
				{	// Successfully added constant, hook it up and translate it.
					(*lIter)->constType((yyvsp[(3) - (3)].constant_binder_t)->constType);
					(*lIter)->domain(tempSort);
					if((*lIter)->constType() == Constant::CONST_ATTRIBUTE && (yyvsp[(3) - (3)].constant_binder_t)->parent != NULL)
					{
						((Attribute*)(*lIter))->parent((yyvsp[(3) - (3)].constant_binder_t)->parent);
					}
					// Translate each constant once its information is complete.
					mainTrans.translateConstantDecl(*lIter);
				}
			}
		}
		else
		{
			// Deallocate all of the constants in the errant list, they're never going to get used by anything.
			for(std::list<Constant*>::iterator lIter = (yyvsp[(1) - (3)].l_constant)->begin(); lIter != (yyvsp[(1) - (3)].l_constant)->end(); ++lIter)
			{
				deallocateItem(*lIter);
			}
		}
	}
	if((yyvsp[(3) - (3)].constant_binder_t) != NULL)
	{
		deallocateItem((yyvsp[(3) - (3)].constant_binder_t));
	}
	if((yyvsp[(1) - (3)].l_constant) != NULL)
	{
		deallocateList((yyvsp[(1) - (3)].l_constant));
	}
	(yyval.not_used) = PARSERULE_NOT_USED;
	if (constantError)
	{
		YYERROR;
	}
}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 680 "parser.yy"
    {
	(yyval.l_constant) = (yyvsp[(1) - (1)].l_constant);
}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 684 "parser.yy"
    {
	(yyval.l_constant) = (yyvsp[(2) - (3)].l_constant);
}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 690 "parser.yy"
    {
	// Create a new constant list, add the schema as the first element.
	(yyval.l_constant) = new std::list<Constant*>;
	if((yyvsp[(1) - (1)].constant) != NULL)
	{
		(yyval.l_constant)->push_back((yyvsp[(1) - (1)].constant));
	}
}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 699 "parser.yy"
    {
	// Merge a schema into an existing list.
	(yyval.l_constant) = NULL;
	if((yyvsp[(1) - (3)].l_constant) != NULL && (yyvsp[(3) - (3)].constant) != NULL)
	{
		(yyval.l_constant) = (yyvsp[(1) - (3)].l_constant);
		(yyval.l_constant)->push_back((yyvsp[(3) - (3)].constant));
	}
	if((yyvsp[(1) - (3)].l_constant) == NULL)
	{
		deallocateItem((yyvsp[(3) - (3)].constant));
	}
	if((yyvsp[(3) - (3)].constant) == NULL)
	{
		for(std::list<Constant*>::iterator lIter = (yyvsp[(1) - (3)].l_constant)->begin(); lIter != (yyvsp[(1) - (3)].l_constant)->end(); ++lIter)
		{
			deallocateItem(*lIter);
		}
		deallocateItem((yyvsp[(3) - (3)].constant));
	}
}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 723 "parser.yy"
    {
	(yyval.constant) = (yyvsp[(1) - (1)].constant);
}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 727 "parser.yy"
    {
	(yyval.constant) = (yyvsp[(2) - (3)].constant);
}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 733 "parser.yy"
    {
	// Create a new Constant from a bare identifier.
	(yyval.constant) = new Constant(*(yyvsp[(1) - (1)].str), Constant::CONST_UNKNOWN, false);
	deallocateItem((yyvsp[(1) - (1)].str));
}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 739 "parser.yy"
    {
	// Create a new Constant from a parameterized identifier.
	(yyval.constant) = NULL;
	if((yyvsp[(3) - (4)].l_sort) != NULL)
	{
		(yyval.constant) = new Constant(*(yyvsp[(1) - (4)].str), Constant::CONST_UNKNOWN, false, (ConstSortList*)(yyvsp[(3) - (4)].l_sort));
		deallocateList((yyvsp[(3) - (4)].l_sort));
	}
	deallocateItem((yyvsp[(1) - (4)].str));
}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 753 "parser.yy"
    {
	// TODO: Check if not found.
	(yyval.constant) = mainTrans.getConstant(*(yyvsp[(1) - (1)].str));

	if (!(yyval.constant))
		mainTrans.error("\"" + *(yyvsp[(1) - (1)].str) + std::string("/0") + "\" is not a valid constant identifier.", true);

	deallocateItem((yyvsp[(1) - (1)].str));
}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 763 "parser.yy"
    {
	(yyval.constant) = NULL;
	if((yyvsp[(3) - (4)].l_sort) != NULL)
	{
		(yyval.constant) = mainTrans.getConstant(*(yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].l_sort)->size());

		if (!(yyval.constant))
			mainTrans.error("\"" + *(yyvsp[(1) - (4)].str) + utils::to_string((yyvsp[(3) - (4)].l_sort)->size()) + "\" is not a valid constant identifier.", true);

		deallocateList((yyvsp[(3) - (4)].l_sort));
	}
	deallocateItem((yyvsp[(1) - (4)].str));
}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 779 "parser.yy"
    {
	(yyval.constant_binder_t) = (yyvsp[(1) - (1)].constant_binder_t);
}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 783 "parser.yy"
    {
	(yyval.constant_binder_t) = (yyvsp[(2) - (3)].constant_binder_t);
}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 789 "parser.yy"
    {
	// Two possibilities, check for each:
	// 1) The identifier is a plain constant type (e.g. "exogenousAction").
	// 2) The identifier is something else, which is a shortcut for "rigid(identifier)".
	Constant::ConstantType constType = Constant::CONST_UNKNOWN;
	std::string tempIdent = (*(yyvsp[(1) - (1)].str));
	deallocateItem((yyvsp[(1) - (1)].str));
	// Check for a real constant type.
	constType = Constant::stringToConstType(tempIdent.c_str());
	(yyval.constant_binder_t) = new PT_constant_binder_t;
	if (constType == Constant::CONST_STATICAB || constType == Constant::CONST_DYNAMICAB) {
		// it's an abnormality
		(yyval.constant_binder_t)->constType = constType;
		(yyval.constant_binder_t)->domain = NULL;
	} 
	else if(constType != Constant::CONST_UNKNOWN)
	{	// Basic constant binder with Boolean domain.
		(yyval.constant_binder_t)->constType = constType;
		(yyval.constant_binder_t)->domain = checkDynamicSortDecl("boolean");
	}
	else
	{	// If it wasn't a real constant type, it's just a shortcut for "rigid(identifier)".
		(yyval.constant_binder_t)->constType = Constant::CONST_RIGID;
		(yyval.constant_binder_t)->domain = checkDynamicSortDecl(tempIdent);
		if((yyval.constant_binder_t)->domain == NULL)
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << tempIdent << "\" not declared, can't use as the domain of a constant declaration.";
			ltsyyreportError();
		}
		if((yyval.constant_binder_t)->domain == NULL)
		{	// If $$'s domain attribute is NULL, an error happened.
			deallocateItem((yyval.constant_binder_t));
			YYERROR;
		}
	}
}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 827 "parser.yy"
    {
	// Basic constant binder with given domain.
	Constant::ConstantType constType = Constant::CONST_UNKNOWN;
	std::string tempIdent = (*(yyvsp[(1) - (4)].str));
	deallocateItem((yyvsp[(1) - (4)].str));

	// Figure out which constant type was given.
	constType = Constant::stringToConstType(tempIdent.c_str());
	
	(yyval.constant_binder_t) = new PT_constant_binder_t;
	(yyval.constant_binder_t)->constType = constType;
	if((yyvsp[(3) - (4)].str) != NULL)
	{
		(yyval.constant_binder_t)->domain = checkDynamicSortDecl(*(yyvsp[(3) - (4)].str));
		deallocateItem((yyvsp[(3) - (4)].str));
	}
	if((yyval.constant_binder_t)->domain == NULL)
	{	// Start error mode if anything went wrong.
		deallocateItem((yyval.constant_binder_t));
		YYERROR;
	}
}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 850 "parser.yy"
    {
	// Attribute binder with Boolean(*) domain.
	(yyval.constant_binder_t) = new PT_constant_binder_t;
	(yyval.constant_binder_t)->constType = Constant::CONST_ATTRIBUTE;
	(yyval.constant_binder_t)->domain = checkDynamicSortDecl("boolean*");
	if((yyvsp[(3) - (3)].constant) != NULL)
	{
		(yyval.constant_binder_t)->parent = (yyvsp[(3) - (3)].constant);
	}
	else
	{	// Something's wrong, start error mode.
		deallocateItem((yyval.constant_binder_t));
		YYERROR;
	}
}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 866 "parser.yy"
    {
	// Attribute binder with given(*) domain.
	(yyval.constant_binder_t) = new PT_constant_binder_t;
	(yyval.constant_binder_t)->constType = Constant::CONST_ATTRIBUTE;
	if((yyvsp[(3) - (6)].str) != NULL)
	{
		std::string domainName = *(yyvsp[(3) - (6)].str) + "*";
		(yyval.constant_binder_t)->domain = checkDynamicSortDecl(domainName);
		if((yyval.constant_binder_t)->domain == NULL)
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << *(yyvsp[(3) - (6)].str) << "\" not declared, can't use as the domain of a constant declaration.";
			ltsyyreportError();
		}
		deallocateItem((yyvsp[(3) - (6)].str));
	}
	if((yyvsp[(6) - (6)].constant) != NULL)
	{
		(yyval.constant_binder_t)->parent = (yyvsp[(6) - (6)].constant);
	}
	if((yyval.constant_binder_t)->domain == NULL || (yyval.constant_binder_t)->parent == NULL)
	{	// If $$'s attributes are NULL, an error happened.
		deallocateItem((yyval.constant_binder_t));
		YYERROR;
	}
}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 938 "parser.yy"
    {
	// The new style of maxAdditive declaration. Insert a hint comment with the given maxAdditive value.
	if((yyvsp[(4) - (5)].str) != NULL)
	{
		std::string maxAdditiveHint = "% [MaxAdditive:";
		maxAdditiveHint += *((yyvsp[(4) - (5)].str));
		maxAdditiveHint += "]";
		mainTrans.output(maxAdditiveHint, IPART_NONE, true);
		(yyval.not_used) = PARSERULE_NOT_USED;
		deallocateItem((yyvsp[(4) - (5)].str));
	}
}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 954 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 957 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 958 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 961 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 962 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 965 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 966 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 970 "parser.yy"
    {
	// Connect each Object in the list to its sort, (try to) add them to the symbol table, and translate each object.

	if ((yyvsp[(1) - (3)].l_object) && (yyvsp[(3) - (3)].str)) {

		Sort* sort = mainTrans.getSort(*(yyvsp[(3) - (3)].str));
		Element* elem;

		if (!sort) {
			mainTrans.error("Bad object declaration. \"" + *(yyvsp[(3) - (3)].str) + "\" is not a valid sort.", true);
		} else if (!(yyvsp[(1) - (3)].l_object)) {
			// directly referenced sorts should be made visible.
			sort->internal(false);

			mainTrans.error("Bad object declaration.", true);
		} else {
			// directly referenced sorts should be made visible.
			sort->internal(false);

			// add each of the objects. 
			for (ObjectList::iterator it = (yyvsp[(1) - (3)].l_object)->begin(); it != (yyvsp[(1) - (3)].l_object)->end(); it++) {
				// make sure it's valid and hasn't been declared to something conflicting
				if (!*it) mainTrans.error("Bad object declaration.", true);
				else if ((elem = mainTrans.getSymbol((*it)->baseName(), (*it)->arity())) && elem->getElemType() != Element::ELEM_OBJ ) {
						mainTrans.error("Detected a conflicting definition of \"" + elem->baseName() 
							+ "/" + utils::to_string(elem->arity()) + "\".", true);
				} else {
					mainTrans.translateObjectDecl(*it, sort);
					
					if (!elem) {
						elem = *it;
						if (mainTrans.addSymbol(elem) != SymbolTable::ADDSYM_OK) {
							mainTrans.error("An error occurred processing the definition of \"" + elem->baseName() 
								+ "/" + utils::to_string(elem->arity()) + "\".", true);
							delete elem;
							elem = NULL;
						}
					}
					else delete *it;

					if (elem) sort->addObject((Object*)elem);
				}
			}
		}

		deallocateList((yyvsp[(1) - (3)].l_object));
		deallocateItem((yyvsp[(3) - (3)].str));
	} else if ((yyvsp[(1) - (3)].l_object)) {
		deallocateList((yyvsp[(1) - (3)].l_object));
	}
		
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 1026 "parser.yy"
    {
	(yyval.l_object) = (yyvsp[(1) - (1)].l_object);
}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 1030 "parser.yy"
    {
	(yyval.l_object) = (yyvsp[(2) - (3)].l_object);
}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 1036 "parser.yy"
    {
	// Create a new list and make the new object the first element.
	(yyval.l_object) = NULL;
	if((yyvsp[(1) - (1)].object) != NULL)
	{
		(yyval.l_object) = new ObjectList();
		(yyval.l_object)->push_back((yyvsp[(1) - (1)].object));
	}
}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 1046 "parser.yy"
    {
	// Merge a new object with an exisiting list.
	(yyval.l_object) = NULL;
	if((yyvsp[(1) - (3)].l_object) != NULL && (yyvsp[(3) - (3)].object) != NULL)
	{
		(yyval.l_object) = (yyvsp[(1) - (3)].l_object);
		(yyval.l_object)->push_back((yyvsp[(3) - (3)].object));
	}
	if((yyvsp[(1) - (3)].l_object) == NULL)
	{
		deallocateItem((yyvsp[(3) - (3)].object));
	}
	if((yyvsp[(3) - (3)].object) == NULL)
	{
		for(ObjectList::iterator lIter = (yyvsp[(1) - (3)].l_object)->begin(); lIter != (yyvsp[(1) - (3)].l_object)->end(); ++lIter)
		{
			deallocateItem(*lIter);
		}
		deallocateList((yyvsp[(1) - (3)].l_object));
	}
}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 1070 "parser.yy"
    {
	(yyval.object) = (yyvsp[(1) - (1)].object);
}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 1074 "parser.yy"
    {
	(yyval.object) = (yyvsp[(2) - (3)].object);
}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 1080 "parser.yy"
    {
	// Create a new Object from a bare identifier.
	(yyval.object) = new Object(*(yyvsp[(1) - (1)].str), Object::OBJ_NAME, false);
	deallocateItem((yyvsp[(1) - (1)].str));
}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 1086 "parser.yy"
    {
	// Create a new Object from a parameterized identifier.
	(yyval.object) = new Object(*(yyvsp[(1) - (4)].str), Object::OBJ_NAME, false, (yyvsp[(3) - (4)].l_sort));
	deallocateList((yyvsp[(3) - (4)].l_sort));
	deallocateItem((yyvsp[(1) - (4)].str));
}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 1093 "parser.yy"
    {
	// Create a new object from arbitrary math.
	(yyval.object) = new Object(*(yyvsp[(1) - (1)].str), Object::OBJ_NAME, true);
	deallocateItem((yyvsp[(1) - (1)].str)); // Free dynamic memory that's not needed anymore.
}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 1099 "parser.yy"
    {
	// Upcast a NumberRange into an Object.
	(yyval.object) = (Object*)(yyvsp[(1) - (1)].numRange);
}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 1108 "parser.yy"
    {
	if ((yyvsp[(3) - (4)].v_parseElement)) {
		mainTrans.translateShowStmt(*(yyvsp[(3) - (4)].v_parseElement));
	} else {
		YYERROR;
	}
	deallocateList((yyvsp[(3) - (4)].v_parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 1121 "parser.yy"
    {
	if ((yyvsp[(1) - (1)].parseElement)) {
		(yyval.v_parseElement) = new ParseElementList();
		(yyval.v_parseElement)->push_back((yyvsp[(1) - (1)].parseElement));
	} else {
		(yyval.v_parseElement) = NULL;
	}
	 
}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 1131 "parser.yy"
    {
	if ((yyvsp[(1) - (3)].v_parseElement)) {
		(yyval.v_parseElement) = (yyvsp[(1) - (3)].v_parseElement);
		if ((yyvsp[(3) - (3)].parseElement)) (yyvsp[(1) - (3)].v_parseElement)->push_back((yyvsp[(3) - (3)].parseElement));
	} else if ((yyvsp[(3) - (3)].parseElement)) {
		(yyval.v_parseElement) = new ParseElementList();
		(yyval.v_parseElement)->push_back((yyvsp[(3) - (3)].parseElement));
	} else {
		(yyval.v_parseElement) = NULL;
	}
}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 1145 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 1149 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 1163 "parser.yy"
    {
	// Deallocate the main sort list of the statement.
	if((yyvsp[(3) - (4)].l_sort) != NULL)
	{
		deallocateList((yyvsp[(3) - (4)].l_sort));
	}
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 1174 "parser.yy"
    {
	(yyval.l_sort) = (yyvsp[(1) - (1)].l_sort);
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 1178 "parser.yy"
    {
	(yyval.l_sort) = (yyvsp[(2) - (3)].l_sort);
}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 1184 "parser.yy"
    {
	(yyval.l_sort) = new SortList();
	(yyval.l_sort)->push_back((yyvsp[(1) - (1)].sort));
}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 1189 "parser.yy"
    {
	if (!(yyvsp[(1) - (3)].l_sort)) (yyval.l_sort) = (yyvsp[(3) - (3)].l_sort);
	else if (!(yyvsp[(3) - (3)].l_sort)) (yyval.l_sort) = (yyvsp[(1) - (3)].l_sort);
	else {
		(yyval.l_sort) = (yyvsp[(1) - (3)].l_sort);

		for(SortList::iterator lIter = (yyvsp[(3) - (3)].l_sort)->begin(); lIter != (yyvsp[(3) - (3)].l_sort)->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				(yyval.l_sort)->push_back((*lIter));
			}
		}
		deallocateList((yyvsp[(3) - (3)].l_sort));
	}
}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 1206 "parser.yy"
    {
	if (!(yyvsp[(1) - (3)].l_sort)) (yyval.l_sort) = (yyvsp[(3) - (3)].l_sort);
	else if (!(yyvsp[(3) - (3)].l_sort)) (yyval.l_sort) = (yyvsp[(1) - (3)].l_sort);
	else {
		(yyval.l_sort) = (yyvsp[(1) - (3)].l_sort);

		for(SortList::iterator lIter = (yyvsp[(3) - (3)].l_sort)->begin(); lIter != (yyvsp[(3) - (3)].l_sort)->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				(yyval.l_sort)->push_back((*lIter));
			}
		}
		deallocateList((yyvsp[(3) - (3)].l_sort));
	}
}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 1225 "parser.yy"
    {
	// Have a helper function handle making and translating the sort.
	(yyval.sort) = mainTrans.addSort(*(yyvsp[(1) - (1)].str), false, NULL, true, false);
	deallocateItem((yyvsp[(1) - (1)].str));
	if((yyval.sort) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 1235 "parser.yy"
    {
	// Have a helper function handle making and translating the sort.
	(yyval.sort) = mainTrans.addSort(*(yyvsp[(1) - (3)].str), false, (yyvsp[(3) - (3)].l_sort), true, false);
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateList((yyvsp[(3) - (3)].l_sort));
	if((yyval.sort) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 1248 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1252 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("staticAbnormality");
}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1257 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("dynamicAbnormality");
}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1264 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 1268 "parser.yy"
    {
	(yyval.str) = (yyvsp[(2) - (3)].str);
}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1276 "parser.yy"
    {
	// A standard identifier.
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1281 "parser.yy"
    {
	// A quick-and-dirty dynamically declared sort.

	// Turn it into a sort and pass it down the chain.
	if((yyvsp[(1) - (1)].numRange) != NULL)
	{
		(yyval.str) = new std::string();
		*(yyval.str) = Translator::numRangeToSortName((yyvsp[(1) - (1)].numRange)->min(), (yyvsp[(1) - (1)].numRange)->max());
		Sort* tempSort = mainTrans.getSort(*(yyval.str));
		if(tempSort == NULL)
		{
			// Have a helper function handle making and translating the sort.
			tempSort = mainTrans.addSort(*(yyval.str), true, NULL, true, false);
			// Also add the number range as an object for this new sort.

			int min, max;
			if (utils::from_string(min, (yyvsp[(1) - (1)].numRange)->min()) && utils::from_string(max, (yyvsp[(1) - (1)].numRange)->max())) {			

				for (int i = min; i <= max; i++) {

					std::string str = utils::to_string(i);
					Element* obj = mainTrans.getSymbol(str);
					if (obj) {
						if (obj->getElemType() != Element::ELEM_OBJ) {
							mainTrans.error("detected a conflicting definition of \"" + str + "\"", true);
							obj = NULL;
						}
					} else {
						obj = new Object(str, Object::OBJ_NAME, false);
						if (mainTrans.addSymbol(obj) != SymbolTable::ADDSYM_OK) {
							delete obj;
							obj = NULL;
						} 
					}

					if (obj) {
						tempSort->addObject((Object*)obj);
						mainTrans.translateObjectDecl((Object*)obj, tempSort);
					}
				}
			} else {
				tempSort = mainTrans.addSort(*(yyval.str), true, NULL, true, false);
				Element* obj = mainTrans.getSymbol((yyvsp[(1) - (1)].numRange)->baseName());
				if (obj) {
					if (obj->getElemType() != Element::ELEM_OBJ) {
						mainTrans.error("detected a conflicting definition of \"" + (yyvsp[(1) - (1)].numRange)->baseName() + "\"", true);
						obj = NULL;
					}
				} else {
					obj = new Object((yyvsp[(1) - (1)].numRange)->baseName(), Object::OBJ_NAME, false);
					if (mainTrans.addSymbol(obj) != SymbolTable::ADDSYM_OK) {
						delete obj;
						obj = NULL;
					} 
				}

				if (obj) {
					tempSort->addObject((Object*)obj);
					mainTrans.translateObjectDecl((Object*)obj, tempSort);
				}
			}
		}

		if(tempSort == NULL)
		{
			// We were unable to allocate the sort properly. Error.
			deallocateItem((yyvsp[(1) - (1)].numRange));
			YYERROR;
		}
	} else {
	      // The number range doesn't exist?
	      YYERROR;
	}
}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1359 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 1363 "parser.yy"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = (*(yyvsp[(1) - (2)].str)) + "*";
	deallocateItem((yyvsp[(1) - (2)].str));
}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 1369 "parser.yy"
    {
	// Alternate way to express the idea of a starred sort.
	(yyval.str) = new std::string;
	(*(yyval.str)) = (*(yyvsp[(1) - (3)].str)) + "*";
	deallocateItem((yyvsp[(1) - (3)].str));
}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1378 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1382 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 1388 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("abAction");
}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1393 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("action");
}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1398 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("additiveAction");
}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1403 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("additiveFluent");
}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1408 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("exogenousAction");
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1413 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("inertialFluent");
}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1418 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("rigid");
}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1423 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("sdFluent");
}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1428 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("simpleFluent");
}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1436 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1439 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1440 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1443 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1444 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1447 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1448 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1452 "parser.yy"
    {
	// Connect the variables in the list to the binding sort, then translate them.
	if((yyvsp[(1) - (3)].l_variable) != NULL && (yyvsp[(3) - (3)].sort) != NULL)
	{
		// directly referenced sorts should be made visible.
		(yyvsp[(3) - (3)].sort)->internal(false);
	
		std::list<Variable*>::iterator vIter;
		Element* elem;
		for(vIter = (yyvsp[(1) - (3)].l_variable)->begin(); vIter != (yyvsp[(1) - (3)].l_variable)->end(); ++vIter)
		{
			(*vIter)->domain((yyvsp[(3) - (3)].sort));

			if ((elem = mainTrans.getSymbol((*vIter)->baseName(), 0)) && (elem->getElemType() != Element::ELEM_VAR 
				|| ((Variable*)elem)->domain() != (yyvsp[(3) - (3)].sort) )) {
				mainTrans.error("Detected a conflicted definition for the \"" + (*vIter)->baseName() + std::string("/0") + "\" identifier.", true);
			} else if (elem) {
				mainTrans.warn("Detected a redeclaration of \"" + (*vIter)->baseName() + std::string("/0") + "\".", true);
			}
			else if (mainTrans.addSymbol(*vIter) != SymbolTable::ADDSYM_OK) {
				mainTrans.error("An error occurred declaring variable \"" + (*vIter)->baseName() + "\".", true);
				delete *vIter;
			} else 
				mainTrans.translateVariableDecl(*vIter);
		}
	}
	if((yyvsp[(1) - (3)].l_variable) != NULL)
	{	// Clear out the list, we don't need it anymore.
		deallocateList((yyvsp[(1) - (3)].l_variable));
	}
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 1487 "parser.yy"
    {
	(yyval.l_variable) = (yyvsp[(1) - (1)].l_variable);
}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 1491 "parser.yy"
    {
	(yyval.l_variable) = (yyvsp[(2) - (3)].l_variable);
}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 1497 "parser.yy"
    {
	// Create a new list of Variables, add this one as the first item.
	(yyval.l_variable) = new std::list<Variable*>;
	Variable* tempVar = new Variable(*(yyvsp[(1) - (1)].str), NULL);
	(yyval.l_variable)->push_back(tempVar);

	deallocateItem((yyvsp[(1) - (1)].str));
	if(tempVar == NULL || (yyval.l_variable) == NULL)
	{	// If $$ or tempVar are NULL, something went wrong.
		YYERROR;
	}
}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 1510 "parser.yy"
    {
	// Merge a new variable declaration into an existing list of variables.
	if((yyvsp[(1) - (3)].l_variable) == NULL)
	{
		(yyval.l_variable) = new std::list<Variable*>;
	} else (yyval.l_variable) = (yyvsp[(1) - (3)].l_variable);
	Variable* tempVar = new Variable(*(yyvsp[(3) - (3)].str), NULL);
	(yyval.l_variable)->push_back(tempVar);
	
	deallocateItem((yyvsp[(3) - (3)].str));
	if(tempVar == NULL)
	{	// If tempVar is NULL, something went wrong.
		YYERROR;
	}
}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 1528 "parser.yy"
    {
	// Find the sort in question, create it if it doesn't exist and is a "something*" sort (whose "something" exists already), or report an error.
	(yyval.sort) = mainTrans.getSort(*(yyvsp[(1) - (1)].str));
	if((yyval.sort) == NULL)
	{
		(yyval.sort) = checkDynamicSortDecl(*(yyvsp[(1) - (1)].str)); // Reports appropriate errors, we just need to YYERROR if that happens.
	}
	deallocateItem((yyvsp[(1) - (1)].str));
	if((yyval.sort) == NULL)
	{	// If $$ is NULL, something went wrong.
		YYERROR;
	}
}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 1582 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1583 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 1586 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1587 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 1590 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 1591 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1594 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 1595 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1598 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1599 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 1602 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1603 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 1606 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 1607 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 1613 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 1614 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 1617 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1618 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1619 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1620 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1621 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 1622 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 1623 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 1624 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 1625 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 1626 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 1627 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 1628 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 1629 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 1634 "parser.yy"
    {
	bool transResult = mainTrans.translateAlwaysLaw((yyvsp[(2) - (5)].parseElement), (yyvsp[(3) - (5)].parseElement), (yyvsp[(4) - (5)].parseElement), (yyvsp[(5) - (5)].parseElement));
	deallocateItem((yyvsp[(2) - (5)].parseElement));
	deallocateItem((yyvsp[(3) - (5)].parseElement));
	deallocateItem((yyvsp[(4) - (5)].parseElement));
	deallocateItem((yyvsp[(5) - (5)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 1649 "parser.yy"
    {
	bool transResult = mainTrans.translateConstraintLaw((yyvsp[(2) - (7)].parseElement), (yyvsp[(3) - (7)].parseElement), (yyvsp[(4) - (7)].parseElement), (yyvsp[(5) - (7)].parseElement), (yyvsp[(6) - (7)].parseElement), (yyvsp[(7) - (7)].parseElement), true);
	deallocateItem((yyvsp[(2) - (7)].parseElement));
	deallocateItem((yyvsp[(3) - (7)].parseElement));
	deallocateItem((yyvsp[(4) - (7)].parseElement));
	deallocateItem((yyvsp[(5) - (7)].parseElement));
	deallocateItem((yyvsp[(6) - (7)].parseElement));
	deallocateItem((yyvsp[(7) - (7)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 1664 "parser.yy"
    {
	bool transResult = mainTrans.translateConstraintLaw((yyvsp[(2) - (7)].parseElement), (yyvsp[(3) - (7)].parseElement), (yyvsp[(4) - (7)].parseElement), (yyvsp[(5) - (7)].parseElement), (yyvsp[(6) - (7)].parseElement), (yyvsp[(7) - (7)].parseElement), false);
	deallocateItem((yyvsp[(2) - (7)].parseElement));
	deallocateItem((yyvsp[(3) - (7)].parseElement));
	deallocateItem((yyvsp[(4) - (7)].parseElement));
	deallocateItem((yyvsp[(5) - (7)].parseElement));
	deallocateItem((yyvsp[(6) - (7)].parseElement));
	deallocateItem((yyvsp[(7) - (7)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 1679 "parser.yy"
    {
	bool transResult = mainTrans.translateConstraintLaw((yyvsp[(2) - (7)].parseElement), (yyvsp[(3) - (7)].parseElement), (yyvsp[(4) - (7)].parseElement), (yyvsp[(5) - (7)].parseElement), (yyvsp[(6) - (7)].parseElement), (yyvsp[(7) - (7)].parseElement), false);
	deallocateItem((yyvsp[(2) - (7)].parseElement));
	deallocateItem((yyvsp[(3) - (7)].parseElement));
	deallocateItem((yyvsp[(4) - (7)].parseElement));
	deallocateItem((yyvsp[(5) - (7)].parseElement));
	deallocateItem((yyvsp[(6) - (7)].parseElement));
	deallocateItem((yyvsp[(7) - (7)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 1696 "parser.yy"
    {

	bool transResult = mainTrans.translateDefaultLaw((yyvsp[(2) - (9)].parseElement), (yyvsp[(3) - (9)].parseElement), (yyvsp[(4) - (9)].parseElement), (yyvsp[(5) - (9)].parseElement), (yyvsp[(6) - (9)].parseElement), (yyvsp[(7) - (9)].parseElement), (yyvsp[(8) - (9)].parseElement), (yyvsp[(9) - (9)].parseElement));
	deallocateItem((yyvsp[(2) - (9)].parseElement));
	deallocateItem((yyvsp[(3) - (9)].parseElement));
	deallocateItem((yyvsp[(4) - (9)].parseElement));
	deallocateItem((yyvsp[(5) - (9)].parseElement));
	deallocateItem((yyvsp[(6) - (9)].parseElement));
	deallocateItem((yyvsp[(7) - (9)].parseElement));
	deallocateItem((yyvsp[(8) - (9)].parseElement));
	deallocateItem((yyvsp[(9) - (9)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 1716 "parser.yy"
    {
	bool transResult = mainTrans.translateDeclarativeLaw((yyvsp[(2) - (4)].parseElement), NULL, NULL, NULL, (yyvsp[(3) - (4)].parseElement), NULL, NULL, (yyvsp[(4) - (4)].parseElement), SimpleUnaryOperator::UOP_EXOGENOUS);
	deallocateItem((yyvsp[(2) - (4)].parseElement));
	deallocateItem((yyvsp[(3) - (4)].parseElement));
	deallocateItem((yyvsp[(4) - (4)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 1730 "parser.yy"
    {
	bool transResult = mainTrans.translateDeclarativeLaw((yyvsp[(2) - (4)].parseElement), NULL, NULL, NULL, (yyvsp[(3) - (4)].parseElement), NULL, NULL, (yyvsp[(4) - (4)].parseElement), SimpleUnaryOperator::UOP_INERTIAL);
	deallocateItem((yyvsp[(2) - (4)].parseElement));
	deallocateItem((yyvsp[(3) - (4)].parseElement));
	deallocateItem((yyvsp[(4) - (4)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 1744 "parser.yy"
    {
	bool transResult = mainTrans.translateNonexecutableLaw((yyvsp[(2) - (6)].parseElement), (yyvsp[(3) - (6)].parseElement), (yyvsp[(4) - (6)].parseElement), (yyvsp[(5) - (6)].parseElement), (yyvsp[(6) - (6)].parseElement));
	deallocateItem((yyvsp[(2) - (6)].parseElement));
	deallocateItem((yyvsp[(3) - (6)].parseElement));
	deallocateItem((yyvsp[(4) - (6)].parseElement));
	deallocateItem((yyvsp[(5) - (6)].parseElement));
	deallocateItem((yyvsp[(6) - (6)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 1760 "parser.yy"
    {
	/*
	 * Let's _try_ to handle this, but we should throw a warning as this statement is not fully supported.
	 */

	ltsyystartWarning(ltsyylloc);
	ltsyyossErr << "Rules of the form \"rigid p [where F]\" are not fully supported and may produce unintended behavior. Please declare the constant as rigid instead.";
	ltsyyreportWarning();

	bool transResult = mainTrans.translateDeclarativeLaw((yyvsp[(2) - (3)].parseElement), NULL, NULL, NULL, NULL, NULL, NULL, (yyvsp[(3) - (3)].parseElement), SimpleUnaryOperator::UOP_RIGID);
	deallocateItem((yyvsp[(2) - (3)].parseElement));
	deallocateItem((yyvsp[(3) - (3)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 1781 "parser.yy"
    {
	bool transResult = mainTrans.translatePossiblyCausedLaw((yyvsp[(2) - (9)].parseElement), (yyvsp[(3) - (9)].parseElement), (yyvsp[(4) - (9)].parseElement), (yyvsp[(5) - (9)].parseElement), (yyvsp[(6) - (9)].parseElement), (yyvsp[(7) - (9)].parseElement), (yyvsp[(8) - (9)].parseElement), (yyvsp[(9) - (9)].parseElement));
	deallocateItem((yyvsp[(2) - (9)].parseElement));
	deallocateItem((yyvsp[(3) - (9)].parseElement));
	deallocateItem((yyvsp[(4) - (9)].parseElement));
	deallocateItem((yyvsp[(5) - (9)].parseElement));
	deallocateItem((yyvsp[(6) - (9)].parseElement));
	deallocateItem((yyvsp[(7) - (9)].parseElement));
	deallocateItem((yyvsp[(8) - (9)].parseElement));
	deallocateItem((yyvsp[(9) - (9)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 1800 "parser.yy"
    {
	bool transResult = mainTrans.translateMayCauseLaw((yyvsp[(1) - (7)].parseElement), (yyvsp[(3) - (7)].parseElement), (yyvsp[(4) - (7)].parseElement), (yyvsp[(5) - (7)].parseElement), (yyvsp[(6) - (7)].parseElement), (yyvsp[(7) - (7)].parseElement));
	deallocateItem((yyvsp[(1) - (7)].parseElement));
	deallocateItem((yyvsp[(3) - (7)].parseElement));
	deallocateItem((yyvsp[(4) - (7)].parseElement));
	deallocateItem((yyvsp[(5) - (7)].parseElement));
	deallocateItem((yyvsp[(6) - (7)].parseElement));
	deallocateItem((yyvsp[(7) - (7)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1817 "parser.yy"
    {
	bool transResult = mainTrans.translateCausesLaw((yyvsp[(1) - (8)].parseElement), (yyvsp[(3) - (8)].parseElement), (yyvsp[(4) - (8)].parseElement), (yyvsp[(5) - (8)].parseElement), (yyvsp[(6) - (8)].parseElement), (yyvsp[(7) - (8)].parseElement), (yyvsp[(8) - (8)].parseElement));
	deallocateItem((yyvsp[(1) - (8)].parseElement));
	deallocateItem((yyvsp[(3) - (8)].parseElement));
	deallocateItem((yyvsp[(4) - (8)].parseElement));
	deallocateItem((yyvsp[(5) - (8)].parseElement));
	deallocateItem((yyvsp[(6) - (8)].parseElement));
	deallocateItem((yyvsp[(7) - (8)].parseElement));
	deallocateItem((yyvsp[(8) - (8)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1835 "parser.yy"
    {
	// This one's easy, it's just a pass-through.
	mainTrans.output("noconcurrency.", IPART_BASE, true);
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1841 "parser.yy"
    {
	// This one is also very easy.
	mainTrans.output("strong_noconcurrency.", IPART_BASE, true);
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1849 "parser.yy"
    {
	bool transResult = mainTrans.translateIncrementLaw((yyvsp[(1) - (10)].parseElement), (yyvsp[(3) - (10)].parseElement), (yyvsp[(5) - (10)].parseElement), (yyvsp[(6) - (10)].parseElement), (yyvsp[(7) - (10)].parseElement), (yyvsp[(8) - (10)].parseElement), (yyvsp[(9) - (10)].parseElement), (yyvsp[(10) - (10)].parseElement), true);
	deallocateItem((yyvsp[(1) - (10)].parseElement));
	deallocateItem((yyvsp[(3) - (10)].parseElement));
	deallocateItem((yyvsp[(5) - (10)].parseElement));
	deallocateItem((yyvsp[(6) - (10)].parseElement));
	deallocateItem((yyvsp[(7) - (10)].parseElement));
	deallocateItem((yyvsp[(8) - (10)].parseElement));
	deallocateItem((yyvsp[(9) - (10)].parseElement));
	deallocateItem((yyvsp[(10) - (10)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1867 "parser.yy"
    {
	bool transResult = mainTrans.translateIncrementLaw((yyvsp[(1) - (10)].parseElement), (yyvsp[(3) - (10)].parseElement), (yyvsp[(5) - (10)].parseElement), (yyvsp[(6) - (10)].parseElement), (yyvsp[(7) - (10)].parseElement), (yyvsp[(8) - (10)].parseElement), (yyvsp[(9) - (10)].parseElement), (yyvsp[(10) - (10)].parseElement), false);
	deallocateItem((yyvsp[(1) - (10)].parseElement));
	deallocateItem((yyvsp[(3) - (10)].parseElement));
	deallocateItem((yyvsp[(5) - (10)].parseElement));
	deallocateItem((yyvsp[(6) - (10)].parseElement));
	deallocateItem((yyvsp[(7) - (10)].parseElement));
	deallocateItem((yyvsp[(8) - (10)].parseElement));
	deallocateItem((yyvsp[(9) - (10)].parseElement));
	deallocateItem((yyvsp[(10) - (10)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1887 "parser.yy"
    {
	// This is a law of the form c=v.
	// Which is really just a lazy shortcut for
	// caused c=v.

	mainTrans.translateCausalLaw((yyvsp[(1) - (8)].parseElement), (yyvsp[(2) - (8)].parseElement), (yyvsp[(3) - (8)].parseElement), (yyvsp[(4) - (8)].parseElement), (yyvsp[(5) - (8)].parseElement), (yyvsp[(6) - (8)].parseElement), (yyvsp[(7) - (8)].parseElement), (yyvsp[(8) - (8)].parseElement));
	deallocateItem((yyvsp[(1) - (8)].parseElement));
	deallocateItem((yyvsp[(2) - (8)].parseElement));
	deallocateItem((yyvsp[(3) - (8)].parseElement));
	deallocateItem((yyvsp[(4) - (8)].parseElement));
	deallocateItem((yyvsp[(5) - (8)].parseElement));
	deallocateItem((yyvsp[(6) - (8)].parseElement));
	deallocateItem((yyvsp[(7) - (8)].parseElement));
	deallocateItem((yyvsp[(8) - (8)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1906 "parser.yy"
    {
	mainTrans.translateCausalLaw((yyvsp[(2) - (9)].parseElement), (yyvsp[(3) - (9)].parseElement), (yyvsp[(4) - (9)].parseElement), (yyvsp[(5) - (9)].parseElement), (yyvsp[(6) - (9)].parseElement), (yyvsp[(7) - (9)].parseElement), (yyvsp[(8) - (9)].parseElement), (yyvsp[(9) - (9)].parseElement));
	deallocateItem((yyvsp[(2) - (9)].parseElement));
	deallocateItem((yyvsp[(3) - (9)].parseElement));
	deallocateItem((yyvsp[(4) - (9)].parseElement));
	deallocateItem((yyvsp[(5) - (9)].parseElement));
	deallocateItem((yyvsp[(6) - (9)].parseElement));
	deallocateItem((yyvsp[(7) - (9)].parseElement));
	deallocateItem((yyvsp[(8) - (9)].parseElement));
	deallocateItem((yyvsp[(9) - (9)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1921 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1925 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("true", mainTrans.getOrCreateObject("true"));
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1929 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("false", mainTrans.getOrCreateObject("false"));
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1935 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1939 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1949 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1953 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1957 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_AND, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1961 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_OR, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1965 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQUIV, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1969 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_IMPL, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1975 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1979 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1989 "parser.yy"
    {
	// This is really only allowed to be a constant/variable/object expression, verify that.
	if((yyvsp[(1) - (1)].parseElement) != NULL)
	{
		if((yyvsp[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_BASELIKE && (yyvsp[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_CONSTLIKE && (yyvsp[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_OBJLIKE && (yyvsp[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_VARLIKE)
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Bare expression \"" << (yyvsp[(1) - (1)].parseElement)->fullName() << "\" not allowed there, did you forget an equality or comparison sign?";
			ltsyyreportError();
			deallocateItem((yyvsp[(1) - (1)].parseElement));
		}
	}
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
	if((yyval.parseElement) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 2008 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQ, (yyvsp[(3) - (3)].parseElement));

}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 2013 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_NEQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 2017 "parser.yy"
    {

	SimpleBinaryOperator::BinaryOperatorType type;
	// A bunch of possible operators bundle into COMPARISON. Find out which one.
	switch((yyvsp[(2) - (3)].integer))
	{
	case T_DBL_EQ:
		type = SimpleBinaryOperator::BOP_DBL_EQ;
		break;
	case T_LTHAN:
		type = SimpleBinaryOperator::BOP_LTHAN;
		break;
	case T_GTHAN:
		type = SimpleBinaryOperator::BOP_GTHAN;
		break;
	case T_EQ_LTHAN:
		type = SimpleBinaryOperator::BOP_LTHAN_EQ;
		break;
	case T_GTHAN_EQ:
		type = SimpleBinaryOperator::BOP_GTHAN_EQ;
		break;
	default:
		type = SimpleBinaryOperator::BOP_UNKNOWN;
	}
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), type, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 2044 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 2050 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 2056 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 2062 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 2068 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 2072 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 2082 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 2086 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 2090 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_AND, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 2094 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_OR, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 2098 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQUIV, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 2102 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_IMPL, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 2108 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 2112 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 2122 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
	if((yyval.parseElement) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 2130 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 2136 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 2140 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 2150 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 2154 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_AND, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 2158 "parser.yy"
    {
        (yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 2164 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 2168 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 2172 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 2178 "parser.yy"
    {
        (yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_CHOICE, (yyvsp[(2) - (3)].parseElement));
}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 2184 "parser.yy"
    {
	(yyval.parseElement) = NULL;
	if((yyvsp[(2) - (5)].l_quantPair) != NULL && (yyvsp[(4) - (5)].parseElement) != NULL)
	{
		(yyval.parseElement) = new BigQuantifiers((yyvsp[(2) - (5)].l_quantPair), (yyvsp[(4) - (5)].parseElement));
	} else if ((yyvsp[(4) - (5)].parseElement)) {
		(yyval.parseElement) = (yyvsp[(4) - (5)].parseElement);
	}

	if ((yyvsp[(2) - (5)].l_quantPair)) deallocateList((yyvsp[(2) - (5)].l_quantPair));
	

	
}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 2201 "parser.yy"
    {
	(yyval.parseElement) = NULL;
	if((yyvsp[(2) - (5)].l_quantPair) != NULL && (yyvsp[(4) - (5)].parseElement) != NULL)
	{
		(yyval.parseElement) = new BigQuantifiers((yyvsp[(2) - (5)].l_quantPair), (yyvsp[(4) - (5)].parseElement));
	} else if ((yyvsp[(4) - (5)].parseElement)) {
		(yyval.parseElement) = (yyvsp[(4) - (5)].parseElement);
	}

	if ((yyvsp[(2) - (5)].l_quantPair)) deallocateList((yyvsp[(2) - (5)].l_quantPair));
  
}
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 2216 "parser.yy"
    {
	(yyval.l_quantPair) = NULL;
	if((yyvsp[(1) - (1)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = new BigQuantifiers::QuantifierList();
		(yyval.l_quantPair)->push_back((yyvsp[(1) - (1)].p_quantPair));
	}
}
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 2225 "parser.yy"
    {
	(yyval.l_quantPair) = NULL;
	if((yyvsp[(1) - (1)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = new BigQuantifiers::QuantifierList();
		(yyval.l_quantPair)->push_back((yyvsp[(1) - (1)].p_quantPair));
	}
}
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 2234 "parser.yy"
    {
	if((yyvsp[(1) - (2)].l_quantPair) != NULL && (yyvsp[(2) - (2)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = (yyvsp[(1) - (2)].l_quantPair);
		(yyval.l_quantPair)->push_back((yyvsp[(2) - (2)].p_quantPair));
	}
	else
	{
		if((yyvsp[(1) - (2)].l_quantPair) != NULL)
		{
			for(BigQuantifiers::QuantifierList::iterator lIter = (yyvsp[(1) - (2)].l_quantPair)->begin(); lIter != (yyvsp[(1) - (2)].l_quantPair)->end(); ++lIter)
			{
				if((*lIter)->second != NULL)
				{
					deallocateItem((*lIter)->second);
				}
				deallocateItem(*lIter);
			}
			deallocateList((yyvsp[(1) - (2)].l_quantPair));
		}
		if((yyvsp[(2) - (2)].p_quantPair) != NULL)
		{
			if((yyvsp[(2) - (2)].p_quantPair)->second != NULL)
			{
				deallocateItem((yyvsp[(2) - (2)].p_quantPair)->second);
			}
			deallocateItem((yyvsp[(2) - (2)].p_quantPair));
		}
		(yyval.l_quantPair) = NULL;
	}
}
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 2266 "parser.yy"
    {
	if((yyvsp[(1) - (2)].l_quantPair) != NULL && (yyvsp[(2) - (2)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = (yyvsp[(1) - (2)].l_quantPair);
		(yyval.l_quantPair)->push_back((yyvsp[(2) - (2)].p_quantPair));
	}
	else
	{
		if((yyvsp[(1) - (2)].l_quantPair) != NULL)
		{
			for(BigQuantifiers::QuantifierList::iterator lIter = (yyvsp[(1) - (2)].l_quantPair)->begin(); lIter != (yyvsp[(1) - (2)].l_quantPair)->end(); ++lIter)
			{
				if((*lIter)->second != NULL)
				{
					deallocateItem((*lIter)->second);
				}
				deallocateItem(*lIter);
			}
			deallocateList((yyvsp[(1) - (2)].l_quantPair));
		}
		if((yyvsp[(2) - (2)].p_quantPair) != NULL)
		{
			if((yyvsp[(2) - (2)].p_quantPair)->second != NULL)
			{
				deallocateItem((yyvsp[(2) - (2)].p_quantPair)->second);
			}
			deallocateItem((yyvsp[(2) - (2)].p_quantPair));
		}
		(yyval.l_quantPair) = NULL;
	}
}
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 2300 "parser.yy"
    {
	(yyval.p_quantPair) = new BigQuantifiers::Quantifier( BigQuantifiers::QUANT_CONJ, NULL);

	// That identifier better be a variable...
	Variable* varRef = mainTrans.getVariable(*(yyvsp[(2) - (2)].str));
	if(varRef == NULL)
	{
		// It's not. We should tell them.
		// First. Let's figure out exactly what kind of error it is...
		if (mainTrans.getSymbol(*(yyvsp[(2) - (2)].str),0)) {
			// They've given us something that clearly isn't a variable.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Unexpected token \"" << *(yyvsp[(2) - (2)].str) << "\" in quantifier. Expected a variable.";
			ltsyyreportError();
		} else {
			// They've given us an undeclared identifier.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << *(yyvsp[(2) - (2)].str) << "\" is undeclared.";
			ltsyyreportError();
		}
		
		// For the sake of system stability, we'll return a new variable.
		varRef = new Variable(*(yyvsp[(2) - (2)].str), true);
		if (mainTrans.addSymbol(varRef) == SymbolTable::ADDSYM_OK) { 
			(yyval.p_quantPair)->second = new VariableLikeElement(*(yyvsp[(2) - (2)].str), varRef);
		} else {
			(yyval.p_quantPair)->second = NULL;
		}
		
	}
	else
	{
		(yyval.p_quantPair)->second = new VariableLikeElement(*(yyvsp[(2) - (2)].str), varRef);
	}
	deallocateItem((yyvsp[(2) - (2)].str));
}
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 2339 "parser.yy"
    {
	(yyval.p_quantPair) = new std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>();
	(yyval.p_quantPair)->first = BigQuantifiers::QUANT_DISJ;
	// Guess that the identifier is a variable, otherwise just default to object.
	Variable* varRef = mainTrans.getVariable(*(yyvsp[(2) - (2)].str));
	if(varRef == NULL)
	{
		// It's not. We should tell them.
		// First. Let's figure out exactly what kind of error it is...
		if (mainTrans.getSymbol(*(yyvsp[(2) - (2)].str),0)) {
			// They've given us something that clearly isn't a variable.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Unexpected token \"" << *(yyvsp[(2) - (2)].str) << "\" in quantifier. Expected a variable.";
			ltsyyreportError();
		} else {
			// They've given us an undeclared identifier.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << *(yyvsp[(2) - (2)].str) << "\" is undeclared.";
			ltsyyreportError();
		}
		
		// For the sake of system stability, we'll return a new variable.
		varRef = new Variable(*(yyvsp[(2) - (2)].str), true);
		if (mainTrans.addSymbol(varRef) == SymbolTable::ADDSYM_OK) { 
			(yyval.p_quantPair)->second = new VariableLikeElement(*(yyvsp[(2) - (2)].str), varRef);
		} else {
			(yyval.p_quantPair)->second = NULL;
		}
		
	}
	else
	{
		(yyval.p_quantPair)->second  = new VariableLikeElement(*(yyvsp[(2) - (2)].str), varRef);
	}
	deallocateItem((yyvsp[(2) - (2)].str));
}
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 2380 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	int addQueryResult = mainTrans.addQuery(mainTrans.tempQuery);
	if(addQueryResult != SymbolTable::ADDSYM_OK)
	{
		if(addQueryResult == SymbolTable::ADDSYM_DUP)
		{	// Query with same label already exists.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "A query with label \"" << mainTrans.tempQuery->label << "\" already exists, query labels must be unique.";
			ltsyyreportError();
		}
		else
		{	// General error.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Query malformed or missing critical information (e.g., maxstep).";
			ltsyyreportError();
		}
		// We can just error here, the error reporting functions already handle creating a new tempQuery.
		YYERROR;
	}
	else
	{	// It added okay, translate it and make a new tempQuery without destroying the one that just got added.
		mainTrans.translateQuery(mainTrans.tempQuery);
		mainTrans.allocateNewTempQuery();
	}
}
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 2409 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 2413 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 2419 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	if (mainTrans.tempQuery && (yyvsp[(3) - (3)].str)) {
		if(mainTrans.tempQuery->label == "")
		{
			mainTrans.tempQuery->label = *(yyvsp[(3) - (3)].str);
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "label already defined as \"" << mainTrans.tempQuery->maxstep << "\" in this query, can only define it once per query.";
			ltsyyreportError();
			YYERROR;
		}
	}
	if ((yyvsp[(3) - (3)].str))	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 2437 "parser.yy"
    {

	(yyval.not_used) = PARSERULE_NOT_USED;
	if (mainTrans.tempQuery) {
		if(mainTrans.tempQuery->label == "")
		{
			mainTrans.tempQuery->label = utils::to_string((yyvsp[(3) - (3)].integer));
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "label already defined as \"" << mainTrans.tempQuery->maxstep << "\" in this query, can only define it once per query.";
			ltsyyreportError();
			YYERROR;
		}
	}
}
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 2455 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	if (mainTrans.tempQuery && (yyvsp[(3) - (3)].numRange)) {
		if(mainTrans.tempQuery->maxstep == "")
		{
			mainTrans.tempQuery->maxstep = (yyvsp[(3) - (3)].numRange)->baseName();
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "maxstep already defined as \"" << mainTrans.tempQuery->maxstep << "\" in this query, can only define it once per query.";
			ltsyyreportError();
			YYERROR;
		}
	}
	if ((yyvsp[(3) - (3)].numRange)) deallocateItem((yyvsp[(3) - (3)].numRange));

}
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 2474 "parser.yy"
    {
	if (mainTrans.tempQuery && (yyvsp[(3) - (3)].str)) {
		if(mainTrans.tempQuery->maxstep == "")
		{
			mainTrans.tempQuery->maxstep = *(yyvsp[(3) - (3)].str);
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "maxstep already defined as \"" << mainTrans.tempQuery->maxstep << "\" in this query, can only define it once per query.";
			ltsyyreportError();
			YYERROR;
		}
	}
	if ((yyvsp[(3) - (3)].str)) deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 2492 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	if((yyvsp[(1) - (1)].parseElement) != NULL)
	{
		// Add this new condition to the temp query.
		mainTrans.tempQuery->queryConditions.push_back((yyvsp[(1) - (1)].parseElement));
	}
	else
	{
		ltsyystartWarning(ltsyylloc);
		ltsyyossErr << "Query body formula is NULL!";
		ltsyyreportWarning();
	}
}
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 2510 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 2514 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 2522 "parser.yy"
    {
	// Turn the time stamp into a plain, translated string representation, then propogate it through the body formula.
	if((yyvsp[(1) - (3)].parseElement) != NULL && (yyvsp[(3) - (3)].parseElement) != NULL)
	{
		(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_BIND_STEP, (yyvsp[(3) - (3)].parseElement));
	} 
	else if ((yyvsp[(3) - (3)].parseElement) != NULL) 
	{
		(yyval.parseElement) = (yyvsp[(3) - (3)].parseElement);
	}
	else
	{
		ltsyystartWarning(ltsyylloc);
		ltsyyossErr << "Query body formula is NULL!";
		ltsyyreportWarning();
	}
}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 2542 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 2546 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 2550 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_AND, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 2554 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_OR, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 2558 "parser.yy"
    {
		(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQUIV, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 2562 "parser.yy"
    {
		(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_IMPL, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 2568 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 2572 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 2582 "parser.yy"
    {
	// This is really only allowed to be a constant/variable/object expression, verify that.
	if((yyvsp[(1) - (1)].parseElement) != NULL)
	{
		if((yyvsp[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_BASELIKE && (yyvsp[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_CONSTLIKE && (yyvsp[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_OBJLIKE && (yyvsp[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_VARLIKE)
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Bare expression \"" << (yyvsp[(1) - (1)].parseElement)->fullName() << "\" not allowed there, did you forget an equality or comparison sign?";
			ltsyyreportError();
			deallocateItem((yyvsp[(1) - (1)].parseElement));
		}
	}
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
	if((yyval.parseElement) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 2601 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 2605 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_NEQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 2609 "parser.yy"
    {
	SimpleBinaryOperator::BinaryOperatorType type;
	// A bunch of possible operators bundle into COMPARISON. Find out which one.
	switch((yyvsp[(2) - (3)].integer))
	{
	case T_DBL_EQ:
		type = SimpleBinaryOperator::BOP_DBL_EQ;
		break;
	case T_LTHAN:
		type = SimpleBinaryOperator::BOP_LTHAN;
		break;
	case T_GTHAN:
		type = SimpleBinaryOperator::BOP_GTHAN;
		break;
	case T_EQ_LTHAN:
		type = SimpleBinaryOperator::BOP_LTHAN_EQ;
		break;
	case T_GTHAN_EQ:
		type = SimpleBinaryOperator::BOP_GTHAN_EQ;
		break;
	default:
		type = SimpleBinaryOperator::BOP_UNKNOWN;
	}

	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), type, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 2636 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 2642 "parser.yy"
    {
	(yyval.parseElement) = NULL;
	if((yyvsp[(2) - (5)].l_quantPair) != NULL && (yyvsp[(4) - (5)].parseElement) != NULL)
	{
		(yyval.parseElement) = new BigQuantifiers((yyvsp[(2) - (5)].l_quantPair), (yyvsp[(4) - (5)].parseElement));
		deallocateList((yyvsp[(2) - (5)].l_quantPair));
	} else if ((yyvsp[(4) - (5)].parseElement)) {
		(yyval.parseElement) = (yyvsp[(4) - (5)].parseElement);
	}

	if ((yyvsp[(2) - (5)].l_quantPair)) deallocateList((yyvsp[(2) - (5)].l_quantPair));
}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 2659 "parser.yy"
    {
	// Guess what kind of instance this might be, go with the best match.

	Element* elem = NULL;

	if ((yyvsp[(1) - (2)].str)) {

		elem = mainTrans.getOrCreateObject(*(yyvsp[(1) - (2)].str) + *(yyvsp[(2) - (2)].str), Object::OBJ_LUA);
		if (!elem || elem->getElemType() != Element::ELEM_OBJ || !((Object*)elem)->isLua()) {
			mainTrans.error("\"" + elem->baseName() + "/" + utils::to_string(elem->arity()) + "\" is used as a LUA call but has been declared.", true);
			elem = NULL;
		}
		(yyval.parseElement) = new ObjectLikeElement(*(yyvsp[(1) - (2)].str) + *(yyvsp[(2) - (2)].str), (Object*)elem);
		mainTrans.handleLUACall((ObjectLikeElement*)(yyval.parseElement));


	} else if ((elem = mainTrans.getSymbol(*(yyvsp[(2) - (2)].str)))) {

		switch(elem->getElemType()) {
		case Element::ELEM_CONST:
			(yyval.parseElement) = new ConstantLikeElement(*(yyvsp[(2) - (2)].str), (Constant*)elem);
			break;

		case Element::ELEM_OBJ:
			(yyval.parseElement) = new ObjectLikeElement(*(yyvsp[(2) - (2)].str), (Object*)elem);
			break;

		case Element::ELEM_VAR:
			(yyval.parseElement) = new VariableLikeElement(*(yyvsp[(2) - (2)].str), (Variable*)elem);
			break;

		default:
			break;
		}
	} else {
		// undeclared. Assume constant for now
		(yyval.parseElement) = new ConstantLikeElement(*(yyvsp[(2) - (2)].str), NULL);
	}

	deallocateItem((yyvsp[(1) - (2)].str));
	deallocateItem((yyvsp[(2) - (2)].str));
}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 2702 "parser.yy"
    {
	// special case for empty parameter list LUA call 'a()'.
	Element* elem = NULL;

	if ((yyvsp[(1) - (4)].str)) {

		elem = mainTrans.getOrCreateObject(*(yyvsp[(1) - (4)].str) + *(yyvsp[(2) - (4)].str), Object::OBJ_LUA);
		if (!elem || elem->getElemType() != Element::ELEM_OBJ || !((Object*)elem)->isLua()) {
			mainTrans.error("\"" + elem->baseName() + "/" + utils::to_string(elem->arity()) + "\" is used as a LUA call but has been declared.", true);
			elem = NULL;
		}
		(yyval.parseElement) = new ObjectLikeElement(*(yyvsp[(1) - (4)].str) + *(yyvsp[(2) - (4)].str), (Object*)elem);
		mainTrans.handleLUACall((ObjectLikeElement*)(yyval.parseElement));

	} else {
		// not a LUA call.
		YYERROR;
	}

	deallocateItem((yyvsp[(1) - (4)].str));
	deallocateItem((yyvsp[(2) - (4)].str));
}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 2726 "parser.yy"
    {
	Element* elem = NULL;

	if ((yyvsp[(1) - (5)].str)) {

		elem = mainTrans.getOrCreateObject(*(yyvsp[(1) - (5)].str) + *(yyvsp[(2) - (5)].str), Object::OBJ_LUA, false, (yyvsp[(4) - (5)].v_parseElement)->size());
		if (!elem || elem->getElemType() != Element::ELEM_OBJ || !((Object*)elem)->isLua()) {
			mainTrans.error("\"" + elem->baseName() + "/" + utils::to_string(elem->arity()) + "\" is used as a LUA call but has been declared.", true);
			elem = NULL;
		}

		(yyval.parseElement) = new ObjectLikeElement(*(yyvsp[(1) - (5)].str) + *(yyvsp[(2) - (5)].str), (Object*)elem, (yyvsp[(4) - (5)].v_parseElement));
		mainTrans.handleLUACall((ObjectLikeElement*)(yyval.parseElement));


	} else if ((elem = mainTrans.getSymbol(*(yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].v_parseElement)->size()))) {

		switch(elem->getElemType()) {
		case Element::ELEM_CONST:
			(yyval.parseElement) = new ConstantLikeElement(*(yyvsp[(2) - (5)].str), (Constant*)elem, (yyvsp[(4) - (5)].v_parseElement));
			break;

		case Element::ELEM_OBJ:
			(yyval.parseElement) = new ObjectLikeElement(*(yyvsp[(2) - (5)].str), (Object*)elem, (yyvsp[(4) - (5)].v_parseElement));
			break;

		case Element::ELEM_VAR:
			(yyval.parseElement) = new VariableLikeElement(*(yyvsp[(2) - (5)].str), (Variable*)elem, (yyvsp[(4) - (5)].v_parseElement));
			break;

		default:
			break;
		}
	} else {
		// undeclared. Assume constant for now (unless clause support).
		(yyval.parseElement) = new ConstantLikeElement(*(yyvsp[(2) - (5)].str), NULL, (yyvsp[(4) - (5)].v_parseElement));
	}

	deallocateItem((yyvsp[(1) - (5)].str));
	deallocateItem((yyvsp[(2) - (5)].str));
	deallocateList((yyvsp[(4) - (5)].v_parseElement));
}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 2771 "parser.yy"
    { (yyval.str) = NULL; }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 2772 "parser.yy"
    { (yyval.str) = new std::string("@"); }
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 2775 "parser.yy"
    {
	(yyval.v_parseElement) = NULL;
	(yyval.v_parseElement) = new ParseElementList();
	if((yyvsp[(1) - (1)].parseElement) != NULL)
	{
		(yyval.v_parseElement)->push_back((yyvsp[(1) - (1)].parseElement));
	}
}
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 2784 "parser.yy"
    {
	(yyval.v_parseElement) = NULL;
	if((yyvsp[(1) - (3)].v_parseElement) != NULL && (yyvsp[(3) - (3)].parseElement) != NULL)
	{
		(yyval.v_parseElement) = (yyvsp[(1) - (3)].v_parseElement);
		(yyval.v_parseElement)->push_back((yyvsp[(3) - (3)].parseElement));
	}
}
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 2795 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 2801 "parser.yy"
    {
	Sort* tempSort = mainTrans.getSort(*(yyvsp[(1) - (1)].str));
	(yyval.l_sort) = NULL;
	if(tempSort != NULL)
	{
		(yyval.l_sort) = new SortList();
		(yyval.l_sort)->push_back(tempSort);
	}
	else
	{
		ltsyystartParseError(ltsyylloc);
		ltsyyossErr << "Sort \"" << *(yyvsp[(1) - (1)].str) << "\" not declared, can't use as part of another declaration.";
		ltsyyreportError();
	}
	deallocateItem((yyvsp[(1) - (1)].str));
	if((yyval.l_sort) == NULL)
	{	// If $$ is NULL, something went wrong.
		YYERROR;
	}
}
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 2822 "parser.yy"
    {
	(yyval.l_sort) = NULL;
	if((yyvsp[(1) - (3)].l_sort) != NULL)
	{
		(yyval.l_sort) = (yyvsp[(1) - (3)].l_sort);
		Sort* tempSort = mainTrans.getSort(*(yyvsp[(3) - (3)].str));
		if(tempSort != NULL)
		{
			(yyval.l_sort)->push_back(tempSort);
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << *(yyvsp[(3) - (3)].str) << "\" not declared, can't use as part of another declaration.";
			ltsyyreportError();
			deallocateList((yyval.l_sort));
		}
	}
	deallocateItem((yyvsp[(3) - (3)].str));
	if((yyval.l_sort) == NULL)
	{	// If $$ is NULL, something went wrong.
		YYERROR;
	}
}
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 2849 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("true", mainTrans.getOrCreateObject("true"));
}
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 2853 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("false", mainTrans.getOrCreateObject("false"));
}
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 2857 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("none", mainTrans.getOrCreateObject("none"));
}
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 2861 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 2867 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 2871 "parser.yy"
    {
	(yyval.parseElement) = NULL;
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
		(yyval.parseElement)->parens(true);
	}
}
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 2882 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 2886 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_PLUS, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 2890 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_MINUS, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 2894 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_TIMES, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 2898 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_DIVIDE, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 2902 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_MOD, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 2906 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_ABS, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 2910 "parser.yy"
    {
	// Not necessary to flag parenBefore and parenAfter, translation of abs
	// automatically adds parentheses around the expression.
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_ABS, (yyvsp[(3) - (4)].parseElement));
}
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 2918 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement(*(yyvsp[(1) - (1)].str), mainTrans.getOrCreateObject(*(yyvsp[(1) - (1)].str)));
	deallocateItem((yyvsp[(1) - (1)].str));
}
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 2923 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 2929 "parser.yy"
    {
	(yyval.numRange) = new NumberRange(*(yyvsp[(1) - (3)].str), *(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 2937 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) = utils::to_string((yyvsp[(1) - (1)].integer));
}
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 2942 "parser.yy"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = "maxAdditive";
}
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 2947 "parser.yy"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = "maxstep";
}
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 2952 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) = "-";
	(*(yyval.str)) += (*(yyvsp[(2) - (2)].str));
	deallocateItem((yyvsp[(2) - (2)].str));
}
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 2961 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 2965 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += "(";
	(*(yyval.str)) += (*(yyvsp[(2) - (3)].str));
	(*(yyval.str)) += ")";
	deallocateItem((yyvsp[(2) - (3)].str));
}
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 2975 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 2979 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " + ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 2988 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " - ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 2997 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " * ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 3006 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " // ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 3015 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " mod ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 3027 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 3031 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 3037 "parser.yy"
    {
	(yyval.integer) = T_UMINUS;
}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 3041 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 3047 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 3051 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 3055 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 3059 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 3063 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;



/* Line 1806 of yacc.c  */
#line 6498 "parser.cc"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 3069 "parser.yy"


// Tries to find an existing normal sort or declare a starred ("something*") sort.
Sort* checkDynamicSortDecl(std::string const& sortIdent)
{
	Sort* retVal = mainTrans.getSort(sortIdent);
	// Allow dynamic instantiation of starred sorts.
	if(retVal == NULL && sortIdent.length() > 0 && sortIdent[sortIdent.length()-1] == '*')
	{
		// Verify that the non-starred version exists before instantiating the starred version.
		std::string nonStarIdent = sortIdent.substr(0, sortIdent.length()-1);
		Sort *nonStarSort = mainTrans.getSort(nonStarIdent);
		if(nonStarSort == NULL)
		{	
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << nonStarIdent << "\" not declared, can't dynamically use \"" << sortIdent << "\" as the domain of another declaration.";
			ltsyyreportError();
		}
		else
		{
			// No need to add unstarred version to subsorts, that's done automatically.
			retVal = mainTrans.addSort(sortIdent, false, NULL, true, false);
			if(retVal == NULL)
			{
				ltsyystartParseError(ltsyylloc);
				ltsyyossErr << "Bad domain declaration \"" << sortIdent << "\".";
				ltsyyreportError();
			}
		}
	}
	if(retVal == NULL)
	{	// The domain isn't an undeclared starred case, it's just undeclared.
		ltsyystartParseError(ltsyylloc);
		ltsyyossErr << "Sort \"" << sortIdent << "\" not declared, can't use as the domain of another declaration.";
		ltsyyreportError();
	}
	return retVal;
}

// Wraps the given element in two new negation operators to create a "not not (...)" wrap.
SimpleUnaryOperator* createNotNot(ParseElement* elem)
{
	SimpleUnaryOperator* retVal = NULL;
	if(elem != NULL)
	{
		elem->parens(true);
		SimpleUnaryOperator* tempNotNot1 = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, elem);
		SimpleUnaryOperator* tempNotNot2 = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, tempNotNot1);
		retVal = tempNotNot2;
	}
	return retVal;
}

// Deallocates a "not not" wrapper such that the original ParseElement is not touched, and returns the original ParseElement object.
ParseElement* deallocateNotNot(SimpleUnaryOperator* uop)
{
	ParseElement* retVal = NULL;
	if(uop != NULL)
	{
		SimpleUnaryOperator* inner = ((SimpleUnaryOperator*)(uop->detachPostOp()));
		if(inner != NULL)
		{
		    retVal = inner->detachPostOp();
		    deallocateItem(inner);
		}
	       deallocateItem(uop);
	}
	return retVal;
}

// NULLs elem's preOp and postOp before deallocating so the sub-ParseElement objects don't get caught in the deallocation.
void deallocateTempBinaryOp(SimpleBinaryOperator* &elem)
{
	if(elem != NULL)
	{
		elem->detachPreOp();
		elem->detachPostOp();
		deallocateItem(elem);
	}
}

// NULLs elem's postOp before deallocating so the sub-ParseElement object doesn't get caught in the deallocation.
void deallocateTempUnaryOp(SimpleUnaryOperator* &elem)
{
	if(elem != NULL)
	{
		elem->detachPostOp();
		deallocateItem(elem);
	}
}

// Adds a standard parsing caution header to ltsyyossErr.
void ltsyystartCaution(YYLTYPE cautionLoc)
{
	ltsyyossErr << "Caution, ";
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\", ";
		}
		ltsyyossErr << "Line #" << cautionLoc.first_line << "." << cautionLoc.first_column << ": ";
	*/
}

// Adds a standard (location-unaware) parsing caution header to ltsyyossErr.
void ltsyystartCaution()
{
	ltsyyossErr << "Caution, ";
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\"";
		}
		ltsyyossErr << ": ";
	*/
}

// Caution reporting function for the parser.
void ltsyycaution()
{
	if(ltsyyossErr.str() == "")
	{
		ltsyystartCaution(ltsyylloc);
		ltsyyossErr << "Using \"" << ltsyytext << "\" here may not be a good idea.";
	}
	mainTrans.caution(ltsyyossErr.str(), true);
	LTSYYRESETOSS;
}

// Adds a standard parsing warning header to ltsyyossErr.
void ltsyystartWarning(YYLTYPE warningLoc)
{
	ltsyyossErr << "Warning, ";
	
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\", ";
		}
		ltsyyossErr << "Line #" << warningLoc.first_line << "." << warningLoc.first_column << ": ";
	*/
}

// Adds a standard (location-unaware) parsing warning header to ltsyyossErr.
void ltsyystartWarning()
{
	ltsyyossErr << "Warning, ";
	
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\"";
		}
		ltsyyossErr << ": ";
	*/
}

// Warning reporting function for the parser.
void ltsyywarning()
{
	if(ltsyyossErr.str() == "")
	{
		ltsyystartWarning(ltsyylloc);
		ltsyyossErr << "Using \"" << ltsyytext << "\" here will probably break something.";
	}
	mainTrans.warn(ltsyyossErr.str(), true);
	LTSYYRESETOSS;
}

// Adds a standard parse error header to ltsyyossErr to make it easier to report errors in actions.
void ltsyystartParseError(YYLTYPE errLoc)
{
	ltsyyossErr << "Parse Error, ";
	
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\", ";
		}
		ltsyyossErr << "Line #" << errLoc.first_line << "." << errLoc.first_column << ": ";
	*/
}

// Adds a standard (location-unaware) parse error header to ltsyyossErr to make it easier to report errors in actions.
void ltsyystartParseError()
{
	ltsyyossErr << "Parse Error, ";
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\"";
		}
		ltsyyossErr << ": ";
	*/
}

// Adds a standard syntax error header to ltsyyossErr to make it easier to report errors in actions.
void ltsyystartSyntaxError(YYLTYPE errLoc)
{
	ltsyyossErr << "Syntax Error, ";
	
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\", ";
		}
		ltsyyossErr << "Line #" << errLoc.first_line << "." << errLoc.first_column << ": ";
	*/
}

// Adds a standard (location-unaware) syntax error header to ltsyyossErr to make it easier to report errors in actions.
void ltsyystartSyntaxError()
{
	ltsyyossErr << "Syntax Error, ";
	
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\"";
		}
		ltsyyossErr << ": ";
	*/
}

// Error reporting function for the bison parser.
void ltsyyerror(char const* msg)
{
	if(ltsyyossErr.str() == "")
	{
		ltsyystartSyntaxError(ltsyylloc);
		ltsyyossErr << "Unexpected token \"" << ltsyytext << "\".";
	}
	mainTrans.error(ltsyyossErr.str(), true);
	LTSYYRESETOSS;

	// If the translator's temporary query appears to have been partially populated, destroy it and create another in its place.
	if(mainTrans.tempQuery != NULL && (mainTrans.tempQuery->label != "" || mainTrans.tempQuery->maxstep != "" || !(mainTrans.tempQuery->queryConditions.empty())))
	{
		mainTrans.allocateNewTempQuery(true);
	}
	if(mainTrans.tempQuery == NULL)
	{
		mainTrans.allocateNewTempQuery();
	}
}

// Wraps caution reporting for convenience and unification with convention for error reporting.
void ltsyyreportCaution()
{
	ltsyycaution();
}
// Wraps warning reporting for convenience and unification with convention for error reporting.
void ltsyyreportWarning()
{
	ltsyywarning();
}
// Wraps error reporting for ease and to ensure the number of errors gets incremented with each (action-generated) error report.
void ltsyyreportError()
{
	ltsyynerrs++;
	ltsyyerror("");
}

//Retreives the name of the current file the parser is working with.
std::string ltsyyGetFileName() { 
  char* fn = strdup(ltsyyFileName.c_str());
  std::string res = std::string(basename(fn));
  free(fn);
  return res;
}

// Retrieves the current location of the parser.
YYLTYPE ltsyyGetLoc() { return ltsyylloc; }

