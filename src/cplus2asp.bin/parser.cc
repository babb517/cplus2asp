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

#include "languages.h"




/* Line 288 of yacc.c  */
#line 140 "parser.cc"

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
     T_TILDE = 326,
     T_SEMICOLON = 327,
     T_DBL_COLON = 328,
     T_ARROW_LDASH = 329,
     T_ARROW_REQ = 330,
     T_ARROW_LEQ = 331,
     T_ARROW_RDASH = 332,
     T_COLON = 333,
     T_COMMA = 334,
     T_EQUIV = 335,
     T_IMPL = 336,
     T_DBL_PLUS = 337,
     T_DBL_AMP = 338,
     T_AMP = 339,
     T_EQ = 340,
     T_GTHAN_EQ = 341,
     T_EQ_LTHAN = 342,
     T_GTHAN = 343,
     T_LTHAN = 344,
     T_NOT_EQ = 345,
     T_DBL_EQ = 346,
     T_NOT = 347,
     T_DBL_PERIOD = 348,
     T_PLUS = 349,
     T_DASH = 350,
     T_DBL_GTHAN = 351,
     T_MOD = 352,
     T_INT_DIV = 353,
     T_STAR = 354,
     T_BIG_CONJ = 355,
     T_BIG_DISJ = 356,
     T_POUND = 357,
     T_UMINUS = 358
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
#define T_TILDE 326
#define T_SEMICOLON 327
#define T_DBL_COLON 328
#define T_ARROW_LDASH 329
#define T_ARROW_REQ 330
#define T_ARROW_LEQ 331
#define T_ARROW_RDASH 332
#define T_COLON 333
#define T_COMMA 334
#define T_EQUIV 335
#define T_IMPL 336
#define T_DBL_PLUS 337
#define T_DBL_AMP 338
#define T_AMP 339
#define T_EQ 340
#define T_GTHAN_EQ 341
#define T_EQ_LTHAN 342
#define T_GTHAN 343
#define T_LTHAN 344
#define T_NOT_EQ 345
#define T_DBL_EQ 346
#define T_NOT 347
#define T_DBL_PERIOD 348
#define T_PLUS 349
#define T_DASH 350
#define T_DBL_GTHAN 351
#define T_MOD 352
#define T_INT_DIV 353
#define T_STAR 354
#define T_BIG_CONJ 355
#define T_BIG_DISJ 356
#define T_POUND 357
#define T_UMINUS 358




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 67 "parser.yy"

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
#line 400 "parser.cc"
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
#line 100 "parser.yy"

/**
 * @file parser.h
 * @brief Contains parser for C+ programs, including definitions and helper functions.
 */

extern Translator* mainTrans;
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
#line 587 "parser.cc"

/* Copy the second part of user declarations.  */

/* Line 343 of yacc.c  */
#line 261 "parser.yy"

#include "lexerTokenStream.h"


/* Line 343 of yacc.c  */
#line 266 "parser.yy"

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
#line 631 "parser.cc"

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
#define YYFINAL  107
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1033

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  281
/* YYNRULES -- Number of states.  */
#define YYNSTATES  561

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   358

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
      95,    96,    97,    98,    99,   100,   101,   102,   103
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
     403,   413,   418,   423,   430,   434,   444,   452,   461,   463,
     465,   476,   487,   496,   501,   511,   513,   515,   517,   519,
     523,   525,   528,   532,   536,   540,   544,   546,   550,   552,
     555,   559,   563,   567,   569,   571,   573,   575,   577,   581,
     583,   586,   590,   594,   598,   602,   604,   608,   610,   613,
     615,   617,   621,   623,   627,   629,   631,   634,   637,   641,
     645,   651,   657,   659,   661,   664,   667,   670,   673,   678,
     680,   684,   688,   692,   696,   700,   702,   704,   708,   712,
     714,   717,   721,   725,   729,   733,   735,   739,   741,   744,
     748,   752,   756,   758,   764,   767,   772,   778,   779,   781,
     783,   787,   789,   791,   795,   797,   799,   801,   803,   805,
     809,   811,   815,   819,   823,   827,   831,   834,   839,   841,
     843,   847,   849,   851,   853,   856,   858,   862,   864,   868,
     872,   876,   880,   884,   886,   888,   890,   892,   894,   896,
     898,   900
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     105,     0,    -1,    -1,   106,    -1,   107,    -1,   106,   107,
      -1,   108,    -1,   120,    -1,   121,    -1,   195,    -1,   130,
      -1,   133,    -1,   143,    -1,   158,    -1,     1,    68,    -1,
      70,    -1,    63,     8,   109,    68,    -1,   110,    -1,    66,
     110,    67,    -1,   111,    -1,   109,    72,   111,    -1,   112,
      -1,    66,   112,    67,    -1,   113,    73,   118,    -1,   114,
      -1,    66,   114,    67,    -1,   115,    -1,   113,    79,   115,
      -1,   116,    -1,    66,   116,    67,    -1,     4,    -1,     4,
      66,   207,    67,    -1,     4,    -1,     4,    66,   207,    67,
      -1,   119,    -1,    66,   119,    67,    -1,   137,    -1,   142,
      66,   139,    67,    -1,    23,    46,   117,    -1,    23,    66,
     139,    67,    46,   117,    -1,    63,    40,    73,   214,    68,
      -1,    63,    11,   122,    68,    -1,   123,    -1,    66,   123,
      67,    -1,   124,    -1,   122,    72,   122,    -1,   125,    -1,
      66,   125,    67,    -1,   126,    73,   138,    -1,   127,    -1,
      66,   127,    67,    -1,   128,    -1,   126,    79,   128,    -1,
     129,    -1,    66,   129,    67,    -1,     4,    -1,     4,    66,
     207,    67,    -1,   214,    -1,   212,    -1,    63,    13,   131,
      68,    -1,   132,    -1,   131,    72,   132,    -1,   203,    -1,
     203,    85,   208,    -1,    63,    14,   134,    68,    -1,   135,
      -1,    66,   135,    67,    -1,   136,    -1,   134,    72,   134,
      -1,   134,    79,   134,    -1,   140,    -1,   140,    96,   134,
      -1,   138,    -1,    51,    -1,    31,    -1,   139,    -1,    66,
     139,    67,    -1,   140,    -1,   212,    -1,   141,    -1,   141,
      99,    -1,   141,    94,    57,    -1,     4,    -1,   142,    -1,
      16,    -1,    17,    -1,    18,    -1,    19,    -1,    33,    -1,
      37,    -1,    48,    -1,    49,    -1,    50,    -1,    63,    15,
     144,    68,    -1,   145,    -1,    66,   145,    67,    -1,   146,
      -1,   146,    72,   144,    -1,   147,    -1,    66,   147,    67,
      -1,   148,    73,   150,    -1,   149,    -1,    66,   149,    67,
      -1,     4,    -1,   149,    79,     4,    -1,   138,    -1,    -1,
      34,   175,    -1,    -1,    22,   175,    -1,    -1,    20,   175,
      -1,    -1,    52,   203,    -1,    -1,    53,   180,    -1,    -1,
      54,   181,    -1,    -1,    55,   179,    -1,   159,    68,    -1,
     173,    68,    -1,   160,    -1,   161,    -1,   162,    -1,   163,
      -1,   164,    -1,   165,    -1,   166,    -1,   167,    -1,   168,
      -1,   169,    -1,   170,    -1,   171,    -1,   172,    -1,    21,
     175,   154,   155,   157,    -1,    28,   175,   153,   154,   155,
     156,   157,    -1,    27,   175,   153,   154,   155,   156,   157,
      -1,    42,   175,   153,   154,   155,   156,   157,    -1,    74,
     175,   157,    -1,    30,   174,   151,   152,   153,   154,   155,
     156,   157,    -1,    32,   203,   154,   157,    -1,    36,   203,
     154,   157,    -1,    45,   175,   151,   154,   155,   157,    -1,
      48,   203,   157,    -1,    47,   174,   151,   152,   153,   154,
     155,   156,   157,    -1,   188,    39,   174,   151,   152,   155,
     157,    -1,   188,    26,   174,   151,   152,   154,   155,   157,
      -1,    43,    -1,    44,    -1,   188,    35,   174,    24,   209,
     151,   152,   154,   155,   157,    -1,   188,    29,   174,    24,
     209,   151,   152,   154,   155,   157,    -1,   174,   151,   152,
     153,   154,   155,   156,   157,    -1,   174,    74,   175,   157,
      -1,    25,   174,   151,   152,   153,   154,   155,   156,   157,
      -1,   186,    -1,    58,    -1,    56,    -1,   176,    -1,    66,
     176,    67,    -1,   177,    -1,   217,   175,    -1,   175,   216,
     175,    -1,   175,    82,   175,    -1,   175,    80,   175,    -1,
     175,    81,   175,    -1,   178,    -1,    66,   178,    67,    -1,
     208,    -1,    71,   203,    -1,   208,    85,   208,    -1,   208,
      90,   208,    -1,   208,   218,   208,    -1,   190,    -1,   175,
      -1,   182,    -1,   182,    -1,   183,    -1,    66,   183,    67,
      -1,   184,    -1,   217,   182,    -1,   182,   216,   182,    -1,
     182,    82,   182,    -1,   182,    80,   182,    -1,   182,    81,
     182,    -1,   185,    -1,    66,   185,    67,    -1,   203,    -1,
      71,   203,    -1,   191,    -1,   187,    -1,    66,   187,    67,
      -1,   188,    -1,   186,   216,   186,    -1,   189,    -1,   203,
      -1,   217,   203,    -1,    71,   203,    -1,   203,    85,   208,
      -1,    64,   188,    65,    -1,    61,   192,    69,   175,    62,
      -1,    61,   192,    69,   182,    62,    -1,   193,    -1,   194,
      -1,   192,   193,    -1,   192,   194,    -1,   100,     4,    -1,
     101,     4,    -1,    63,    12,   196,    68,    -1,   197,    -1,
     196,    72,   196,    -1,    38,    73,     4,    -1,    38,    73,
       3,    -1,    41,    73,   212,    -1,    41,    73,   213,    -1,
     198,    -1,   199,    -1,    66,   198,    67,    -1,   210,    78,
     198,    -1,   200,    -1,   217,   198,    -1,   198,   216,   198,
      -1,   198,    82,   198,    -1,   198,    80,   198,    -1,   198,
      81,   198,    -1,   201,    -1,    66,   201,    67,    -1,   208,
      -1,    71,   203,    -1,   208,    85,   208,    -1,   208,    90,
     208,    -1,   208,   218,   208,    -1,   202,    -1,    61,   192,
      69,   198,    62,    -1,   204,     4,    -1,   204,     4,    66,
      67,    -1,   204,     4,    66,   205,    67,    -1,    -1,    60,
      -1,   206,    -1,   205,    79,   206,    -1,   208,    -1,   139,
      -1,   207,    79,   139,    -1,    58,    -1,    56,    -1,    57,
      -1,   209,    -1,   210,    -1,    66,   210,    67,    -1,   211,
      -1,   209,    94,   209,    -1,   209,    95,   209,    -1,   209,
      99,   209,    -1,   209,    98,   209,    -1,   209,    97,   209,
      -1,    59,   209,    -1,    59,    66,   209,    67,    -1,   213,
      -1,   203,    -1,   214,    93,   214,    -1,     3,    -1,    40,
      -1,    41,    -1,    95,   213,    -1,   215,    -1,    66,   215,
      67,    -1,   213,    -1,   214,    94,   214,    -1,   214,    95,
     214,    -1,   214,    99,   214,    -1,   214,    98,   214,    -1,
     214,    97,   214,    -1,    84,    -1,    79,    -1,    95,    -1,
      92,    -1,    91,    -1,    87,    -1,    86,    -1,    89,    -1,
      88,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   478,   478,   479,   490,   491,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   508,   516,   519,   520,   523,
     524,   527,   528,   531,   705,   709,   715,   724,   748,   752,
     758,   764,   778,   788,   804,   808,   814,   852,   875,   891,
     963,   980,   983,   984,   987,   988,   991,   992,   995,  1051,
    1055,  1061,  1071,  1095,  1099,  1105,  1111,  1118,  1124,  1133,
    1146,  1156,  1170,  1174,  1188,  1199,  1203,  1209,  1214,  1231,
    1250,  1260,  1273,  1277,  1282,  1289,  1293,  1301,  1306,  1384,
    1388,  1394,  1403,  1407,  1413,  1418,  1423,  1428,  1433,  1438,
    1443,  1448,  1453,  1462,  1465,  1466,  1469,  1470,  1473,  1474,
    1477,  1512,  1516,  1522,  1535,  1553,  1608,  1609,  1612,  1613,
    1616,  1617,  1620,  1621,  1624,  1625,  1628,  1629,  1632,  1633,
    1639,  1640,  1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,
    1651,  1652,  1653,  1654,  1655,  1659,  1674,  1689,  1704,  1719,
    1736,  1756,  1770,  1784,  1800,  1821,  1840,  1857,  1875,  1881,
    1889,  1907,  1927,  1944,  1958,  1969,  1973,  1977,  1983,  1987,
    1997,  2001,  2005,  2009,  2013,  2017,  2023,  2027,  2037,  2056,
    2060,  2065,  2069,  2096,  2102,  2108,  2114,  2120,  2124,  2134,
    2138,  2142,  2146,  2150,  2154,  2160,  2164,  2174,  2182,  2186,
    2192,  2196,  2206,  2210,  2214,  2220,  2224,  2228,  2232,  2238,
    2244,  2261,  2276,  2285,  2294,  2326,  2360,  2399,  2440,  2469,
    2473,  2479,  2497,  2515,  2534,  2552,  2570,  2574,  2582,  2602,
    2606,  2610,  2614,  2618,  2622,  2628,  2632,  2642,  2661,  2665,
    2669,  2673,  2700,  2706,  2723,  2766,  2790,  2836,  2837,  2839,
    2848,  2859,  2865,  2886,  2913,  2917,  2921,  2925,  2931,  2935,
    2946,  2950,  2954,  2958,  2962,  2966,  2970,  2974,  2982,  2987,
    2993,  3001,  3006,  3011,  3016,  3025,  3029,  3039,  3043,  3052,
    3061,  3070,  3079,  3091,  3095,  3101,  3105,  3111,  3115,  3119,
    3123,  3127
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
  "T_PERIOD", "T_PIPE", "T_NOOP", "T_TILDE", "T_SEMICOLON", "T_DBL_COLON",
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
  "cl_increment_forms", "cl_basic_rule_forms", "causal_law_basic_forms",
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
     355,   356,   357,   358
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   104,   105,   105,   106,   106,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   108,   109,   109,   110,
     110,   111,   111,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   119,   119,
     120,   121,   122,   122,   123,   123,   124,   124,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   129,   129,   130,
     131,   131,   132,   132,   133,   134,   134,   135,   135,   135,
     136,   136,   137,   137,   137,   138,   138,   139,   139,   140,
     140,   140,   141,   141,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   143,   144,   144,   145,   145,   146,   146,
     147,   148,   148,   149,   149,   150,   151,   151,   152,   152,
     153,   153,   154,   154,   155,   155,   156,   156,   157,   157,
     158,   158,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   160,   161,   161,   161,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   170,
     171,   171,   172,   172,   173,   174,   174,   174,   175,   175,
     176,   176,   176,   176,   176,   176,   177,   177,   178,   178,
     178,   178,   178,   178,   179,   180,   181,   182,   182,   183,
     183,   183,   183,   183,   183,   184,   184,   185,   185,   185,
     186,   186,   187,   187,   187,   188,   188,   188,   188,   189,
     190,   191,   192,   192,   192,   192,   193,   194,   195,   196,
     196,   197,   197,   197,   197,   197,   198,   198,   198,   199,
     199,   199,   199,   199,   199,   200,   200,   201,   201,   201,
     201,   201,   201,   202,   203,   203,   203,   204,   204,   205,
     205,   206,   207,   207,   208,   208,   208,   208,   209,   209,
     210,   210,   210,   210,   210,   210,   210,   210,   211,   211,
     212,   213,   213,   213,   213,   214,   214,   215,   215,   215,
     215,   215,   215,   216,   216,   217,   217,   218,   218,   218,
     218,   218
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
       1,     1,     1,     1,     1,     5,     7,     7,     7,     3,
       9,     4,     4,     6,     3,     9,     7,     8,     1,     1,
      10,    10,     8,     4,     9,     1,     1,     1,     1,     3,
       1,     2,     3,     3,     3,     3,     1,     3,     1,     2,
       3,     3,     3,     1,     1,     1,     1,     1,     3,     1,
       2,     3,     3,     3,     3,     1,     3,     1,     2,     1,
       1,     3,     1,     3,     1,     1,     2,     2,     3,     3,
       5,     5,     1,     1,     2,     2,     2,     2,     4,     1,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     1,
       2,     3,     3,     3,     3,     1,     3,     1,     2,     3,
       3,     3,     1,     5,     2,     4,     5,     0,     1,     1,
       3,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     3,     3,     3,     3,     3,     2,     4,     1,     1,
       3,     1,     1,     1,     2,     1,     3,     1,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,   237,   237,   237,   237,   237,   237,   237,   237,
     148,   149,   237,   237,   237,   157,   156,   238,     0,   237,
     237,    15,   237,   237,   276,   275,     0,     0,     4,     6,
       7,     8,    10,    11,    12,    13,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
       0,   106,   155,   190,   192,   194,     9,   195,     0,   237,
      14,   261,   262,   263,   245,   246,   244,   237,     0,   237,
     237,   275,   112,   158,   160,   166,   173,   259,   168,   247,
     248,   250,   258,   237,   106,   192,   110,   110,   106,   112,
     112,   110,   106,   106,   118,     0,     0,   237,   237,     0,
       0,     0,     0,     0,   190,   197,   118,     1,     5,   120,
     121,   237,   237,   108,   274,   273,   237,   237,   237,   237,
     237,   237,   234,   196,   237,     0,   256,     0,     0,     0,
     202,   203,     0,   158,   166,   248,   169,   264,   237,   237,
     237,   237,   114,   237,   237,   279,   278,   281,   280,   237,
     277,   237,   237,   237,   237,   237,   237,   161,   108,   237,
     112,   112,   108,   118,   118,   112,   112,   108,   237,   144,
      30,     0,     0,    17,    19,    21,     0,    24,    26,    28,
      55,     0,     0,    42,    44,    46,     0,    49,    51,    53,
      58,   267,    57,   265,     0,   263,     0,   237,   237,     0,
     209,   215,   216,   219,   225,   232,   227,   248,   237,     0,
      60,    62,    82,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,    65,    67,    70,    79,    83,   103,
       0,     0,    94,    96,    98,     0,   101,     0,   199,   191,
     139,   107,   118,   237,   110,   193,   106,     0,     0,   106,
     237,   198,   237,     0,   206,   207,   237,   204,   205,   159,
     167,   249,   113,   164,   165,   163,   237,   118,   162,   170,
     171,   172,   251,   252,   255,   254,   253,   110,   111,   114,
     114,   110,   141,   142,   114,   114,   110,   174,   119,     0,
       0,    17,    21,    24,    28,    16,     0,     0,     0,     0,
       0,    42,    46,    49,    53,   265,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,   248,   228,   208,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   220,    59,   237,   237,     0,    65,    64,
       0,     0,     0,     0,    80,     0,     0,    98,   101,    93,
       0,     0,     0,     0,     0,   153,   109,   112,   108,   237,
     237,   108,     0,   235,     0,   239,   241,   257,     0,     0,
     237,   237,   115,   175,   177,   179,   185,   189,   187,   237,
     135,   112,   116,   116,   112,   116,   118,   112,   242,    77,
       0,    78,     0,    18,    22,    25,    29,     0,    20,     0,
      74,    73,     0,    23,    34,    36,    72,    75,    83,     0,
      27,     0,    43,    47,    50,    54,   266,    45,     0,    48,
       0,    52,   260,   268,   269,   272,   271,   270,   212,   211,
     213,   267,   237,   217,   226,   210,   223,   224,   222,   221,
     229,   230,   231,   218,    61,    63,    66,    68,    69,    71,
      81,     0,     0,    95,    99,   102,    97,   105,   100,   104,
       0,    40,   114,   112,   106,   106,   114,   236,   237,   200,
       0,     0,   177,   185,   188,   237,   237,   237,   237,   180,
     114,   237,   118,   118,   114,   118,   143,   114,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
       0,     0,     0,   116,   114,   108,   108,   118,   240,   237,
     178,   186,   183,   184,   182,   181,   116,   117,   176,   137,
     136,   116,   138,   116,   243,     0,    32,    38,     0,    35,
      76,     0,   233,   118,   118,   112,   112,   146,     0,   118,
     118,   118,     0,     0,    37,   152,   147,   114,   114,   201,
     154,   140,   145,     0,     0,   118,   118,    33,    39,   151,
     150
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    27,    28,    29,   172,   173,   174,   175,   176,
     293,   178,   179,   527,   403,   404,    30,    31,   182,   183,
     184,   185,   186,   187,   188,   189,    32,   209,   210,    33,
     223,   224,   225,   405,   406,   388,   389,   227,   228,    34,
     231,   232,   233,   234,   235,   236,   458,   113,   244,   160,
     142,   267,   482,   169,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    72,    73,    74,    75,   288,   372,   517,   373,   374,
     375,   376,    52,    53,    85,    55,    76,   377,   129,   130,
     131,    56,   199,   200,   201,   202,   203,   204,   205,    77,
      58,   364,   365,   390,    78,    79,    80,    81,   391,    82,
     392,   193,   143,    83,   151
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -337
static const yytype_int16 yypact[] =
{
     522,    -7,   790,   862,   790,   790,   862,    22,    22,   790,
    -337,  -337,   790,   862,    22,  -337,  -337,  -337,   673,   312,
     549,  -337,    22,   790,  -337,  -337,    91,   606,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,    43,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
      56,    16,   184,  -337,   271,  -337,  -337,    29,   138,    22,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,   451,   176,   790,
      22,   109,   434,  -337,  -337,  -337,  -337,  -337,   904,   916,
    -337,  -337,  -337,   790,   158,  -337,   422,   422,   158,   148,
     148,   422,    20,   158,   170,    41,   521,   763,    22,   898,
      44,   130,   168,   184,   225,  -337,   887,  -337,  -337,  -337,
    -337,   790,   790,   280,  -337,  -337,   549,   862,   862,   862,
     862,   839,   251,  -337,   531,    65,   916,   315,   330,    -5,
    -337,  -337,   448,   274,   279,   286,  -337,  -337,    22,   790,
     790,   790,   294,   790,   839,  -337,  -337,  -337,  -337,   839,
    -337,   839,   531,   531,   531,   531,   531,  -337,   280,   790,
     148,   148,   280,   170,   170,   148,   148,   280,   790,  -337,
     318,    41,    85,  -337,  -337,  -337,   144,  -337,  -337,  -337,
     320,   521,   237,  -337,  -337,  -337,   159,  -337,  -337,  -337,
    -337,  -337,   910,  -337,   308,   319,   176,   812,    22,   244,
    -337,   937,  -337,  -337,  -337,  -337,   911,   310,   812,   252,
    -337,   311,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,   898,   110,  -337,  -337,   297,   205,  -337,  -337,
      47,   327,  -337,   326,  -337,   332,   324,   375,  -337,  -337,
    -337,   448,   887,   790,   386,  -337,   158,   384,   387,   158,
     531,  -337,   834,   814,  -337,  -337,   790,  -337,  -337,  -337,
    -337,  -337,  -337,   162,   178,   328,   772,   170,  -337,  -337,
    -337,  -337,   230,   230,  -337,  -337,  -337,   386,   448,   294,
     294,   386,  -337,  -337,   294,   294,   386,   448,  -337,   732,
     342,   355,   356,   367,   370,  -337,    67,   642,    69,   732,
     360,   372,   373,   376,   385,   392,  -337,   521,   759,   691,
     375,   375,   375,   375,   375,   375,   282,   375,   106,   903,
     393,    30,  -337,  -337,   763,   812,   812,   812,   812,   839,
     839,   839,   812,  -337,  -337,    22,   839,   100,   398,  -337,
     898,   898,   898,   411,  -337,    70,   412,   413,   -12,  -337,
      44,   759,   480,   375,   842,  -337,   448,   148,   280,   531,
     531,   280,   916,  -337,    -1,  -337,  -337,  -337,   641,   176,
     772,    22,  -337,   943,  -337,  -337,  -337,  -337,  -337,   772,
    -337,   148,   453,   453,   148,   453,   170,   148,  -337,  -337,
      72,  -337,   910,  -337,  -337,  -337,  -337,    71,  -337,    23,
    -337,  -337,   693,  -337,  -337,  -337,  -337,  -337,   442,   508,
    -337,    94,  -337,  -337,  -337,  -337,  -337,   360,   732,  -337,
     750,  -337,   934,   439,   439,  -337,  -337,  -337,  -337,  -337,
    -337,   254,   812,  -337,  -337,   447,   346,   275,   328,  -337,
    -337,  -337,  -337,   937,  -337,  -337,  -337,   100,  -337,  -337,
    -337,   529,   413,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
     934,  -337,   294,   148,    28,    28,   294,  -337,   839,  -337,
     121,   943,   473,   474,  -337,   772,   772,   772,   772,  -337,
     294,   772,   170,   170,   294,   170,  -337,   294,  -337,   732,
      71,   356,   540,   732,   481,   484,   732,   370,  -337,   484,
     385,   881,   -12,   453,   294,   280,   280,   170,  -337,   772,
    -337,  -337,   365,   293,   328,  -337,   453,  -337,   943,  -337,
    -337,   453,  -337,   453,  -337,   476,   487,  -337,   489,  -337,
    -337,   490,  -337,   170,   170,   148,   148,  -337,   893,   170,
     170,   170,   732,   513,  -337,  -337,  -337,   294,   294,  -337,
    -337,  -337,  -337,   129,   540,   170,   170,  -337,  -337,  -337,
    -337
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -337,  -337,  -337,   533,  -337,   397,   404,   267,  -141,    86,
     -86,   281,  -169,    27,  -337,   175,  -337,  -337,  -153,   402,
    -337,   403,  -337,   408,   285,  -155,  -337,  -337,   260,  -337,
    -176,   377,  -337,  -337,  -248,    46,   -46,  -337,  -254,  -337,
     248,   374,  -337,  -189,  -337,  -190,  -337,   -55,  -157,   108,
     -73,   -49,  -336,   -83,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
     213,   462,   539,  -337,   542,  -337,  -337,  -337,  -307,   242,
    -337,   249,    24,   580,    57,  -337,  -337,  -337,  -154,  -125,
     -94,  -337,   298,  -337,  -114,  -337,  -337,   421,  -337,     0,
    -337,  -337,   155,  -278,    37,    -9,   -45,  -337,   -19,   -60,
     -40,   -95,   -18,    12,   418
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -238
static const yytype_int16 yytable[] =
{
      57,   277,   294,    57,   257,   281,    57,    89,    90,   177,
     286,   137,    59,    57,    94,    59,   163,   164,    59,    57,
      57,   411,   105,   240,   135,    59,   304,    57,   300,   158,
     292,    59,    59,   162,   116,   258,   191,   166,   167,    59,
     348,   347,   318,   408,   103,   170,   337,   483,   229,   485,
     111,   229,   207,   226,   111,   455,   192,    54,   126,   123,
     419,    60,   111,   471,   256,   137,   467,   352,    61,   492,
     136,   170,   479,   170,   229,   170,   102,   190,   468,   135,
     282,   283,    17,   319,    54,   116,   305,   279,   280,   493,
     112,   107,   284,   285,   333,   127,   128,   261,   211,   114,
     139,   140,   141,   457,   115,    62,    63,   171,   332,   208,
     230,   109,    61,   345,   121,   253,    57,    57,    57,    57,
      57,   191,   152,   153,   110,   154,   155,   156,    59,    59,
      59,    59,    59,   397,   206,   409,   451,   490,   262,   488,
     245,   192,   122,   272,   273,   274,   275,   276,   408,    62,
      63,   489,   321,   295,   417,   348,   452,   296,   251,   355,
     125,   498,   190,   207,   447,   448,   449,   533,   512,   513,
     514,   515,   340,   489,   518,   432,   226,   191,   339,   341,
     539,   269,   340,   328,   380,   540,   270,   541,   271,   341,
     509,   358,   111,   257,   361,   161,   557,   354,   322,   165,
     138,   463,   538,   237,   466,   135,   127,   128,   489,   208,
     177,   436,   437,   438,   439,   470,    84,   297,   443,    88,
     208,   127,   128,   298,   258,   168,    93,   116,   294,   191,
     382,   383,   308,   238,   206,   385,   386,   191,   309,   191,
     497,   362,   139,   140,   141,   206,   115,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   491,   431,   305,   140,
     141,   502,   115,   114,   553,   500,   378,   192,   115,   192,
     422,   423,   424,   425,   426,   427,   127,   128,   379,   207,
     207,   207,   207,   207,   462,   428,   429,   207,   190,   366,
     190,   191,   239,   191,   226,   226,   226,   117,   430,   343,
     118,   328,   243,   486,   344,   306,   119,   305,   480,   307,
     120,   484,   323,   460,   487,   328,   324,   252,   501,   254,
     334,   294,  -214,   305,   335,   305,  -214,   154,   155,   156,
     246,   247,   248,   249,   255,   211,   208,   208,   208,   208,
     208,   259,   191,   407,   208,   257,   260,   266,   535,   536,
     464,   465,   357,   261,   407,   478,   326,   327,   191,   115,
     191,   206,   206,   206,   206,   206,   440,   441,   442,   206,
     378,   474,    17,   445,   476,   477,   258,   115,    61,   378,
     192,   316,   379,    22,   289,   381,   299,   207,   332,   384,
     504,   379,   317,   342,   387,   349,   336,   407,   350,   519,
     520,   190,   522,   352,    24,   351,   159,    25,   359,   505,
     506,   360,   115,   503,   296,    62,    63,   507,   328,   328,
     328,   328,   393,   394,   537,   328,   325,   326,   327,   191,
     115,   516,   307,   191,   395,   521,   191,   396,   523,   412,
     413,   353,   159,   414,   208,   475,   476,   477,   495,   115,
     545,   546,   415,   478,    61,   534,   550,   551,   552,   416,
     434,   478,   547,   548,   499,   446,    86,    87,   450,   206,
     125,    91,   559,   560,    92,   378,   378,   378,   378,   453,
     454,   378,   191,   328,   459,   106,   138,   379,   379,   379,
     379,    62,    63,   379,   478,   478,   478,   478,   555,   556,
     478,   114,   139,   140,   141,   366,   115,   481,   496,   378,
      67,    17,   170,   114,   139,   140,   141,   124,   115,   324,
     478,   379,    -2,     1,    61,   180,  -237,   114,   139,   140,
     141,   132,   115,   229,    61,   524,   313,   314,   315,   528,
     510,   511,   531,     2,   526,   157,   125,     3,   529,     4,
       5,   530,     6,   542,     7,   298,   543,   544,     8,   554,
     108,    62,    63,   398,     9,    10,    11,    12,   290,    13,
      14,    62,    63,   241,   242,   291,   525,   494,    15,   410,
      16,   558,    17,   301,   302,    18,    19,   181,    20,   303,
      67,    17,    21,    22,   421,   444,    23,   250,   456,   338,
     104,   263,   264,   265,   346,   268,    -3,     1,   133,    17,
    -237,   134,   472,    19,    24,    20,   125,    25,   320,   473,
      22,   278,   435,   508,   331,     0,   125,     2,     0,     0,
     287,     3,     0,     4,     5,     0,     6,     0,     7,     0,
       0,    24,     8,     0,    25,    61,   212,     0,     9,    10,
      11,    12,     0,    13,    14,     0,     0,     0,   213,   214,
     215,   216,    15,     0,    16,   399,    17,     0,     0,    18,
      19,     0,    20,   400,     0,   217,    21,    22,     0,   218,
      23,    95,    62,    63,    96,    97,    98,    99,   100,     0,
     219,   220,   221,   401,    61,   180,    61,   212,    24,     0,
       0,    25,     0,   469,     0,   356,     0,     0,   402,   213,
     214,   215,   216,   101,     0,     0,   399,     0,   368,     0,
     114,   139,   140,   141,   400,   115,   217,     0,     0,     0,
     218,    62,    63,    62,    63,    61,   212,   125,     0,     0,
       0,   219,   220,   221,   401,     0,     0,     0,   213,   214,
     215,   216,     0,    61,   180,     0,     0,   420,     0,   418,
       0,     0,    61,   212,     0,   217,    61,     0,     0,   218,
       0,     0,    62,    63,     0,   213,   214,   215,   216,     0,
     219,   220,   221,     0,     0,     0,   125,     0,   125,     0,
      62,    63,   217,    61,     0,     0,   218,     0,   353,    62,
      63,   194,     0,    62,   195,     0,     0,   219,   220,   221,
       0,     0,     0,     0,     0,    61,   353,     0,     0,    64,
      65,    66,    67,    17,   196,   418,     0,   125,     0,   197,
      62,    63,    17,   369,   198,     0,     0,    61,   370,     0,
       0,     0,    61,   371,     0,   125,    64,    65,    66,    67,
      17,    68,    62,    63,   125,    24,    69,     0,    71,     0,
       0,    70,     0,     0,    24,     0,     0,    25,    64,    65,
      66,    67,    17,   196,    62,    63,     0,     0,   197,    62,
      63,   367,    24,   198,     0,    71,     0,     0,     0,     0,
      64,    65,    66,    67,    17,    64,    65,    66,    67,    17,
     250,   363,   212,     0,    24,   250,     0,    71,   152,   153,
     461,   154,   155,   156,   213,   214,   215,   216,    15,     0,
      16,     0,    17,     0,     0,     0,    19,     0,    20,   125,
       0,   217,     0,    22,   125,   218,   311,   312,     0,   313,
     314,   315,   168,   532,     0,     0,   219,   220,   221,     0,
       0,     0,     0,     0,    24,   549,     0,    25,     0,     0,
     114,   325,   326,   327,   222,   115,   114,   139,   140,   141,
     433,   115,   114,   475,   476,   477,     0,   115,     0,     0,
       0,     0,   114,   325,   326,   327,     0,   115,     0,   144,
     145,   146,   147,   148,   149,   150,   329,   145,   146,   147,
     148,   330,   150,   310,   311,   312,     0,   313,   314,   315,
     152,   153,     0,   154,   155,   156,   114,   325,   326,   327,
       0,   115,   114,   475,   476,   477,     0,   115,   311,   312,
       0,   313,   314,   315
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-337))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,   158,   171,     3,   129,   162,     6,     7,     8,    95,
     167,    71,     0,    13,    14,     3,    89,    90,     6,    19,
      20,   299,    22,   106,    69,    13,   181,    27,   181,    84,
     171,    19,    20,    88,    52,   129,    96,    92,    93,    27,
     230,   230,   196,   297,    20,     4,   222,   383,     4,   385,
      34,     4,    97,    99,    34,    67,    96,     0,    67,    59,
     308,    68,    34,   370,    69,   125,    67,    79,     3,    46,
      70,     4,   379,     4,     4,     4,    19,    96,    79,   124,
     163,   164,    60,   197,    27,   103,   181,   160,   161,    66,
      74,     0,   165,   166,   208,   100,   101,    67,    98,    79,
      80,    81,    82,   351,    84,    40,    41,    66,    78,    97,
      66,    68,     3,    66,    85,   124,   116,   117,   118,   119,
     120,   181,    94,    95,    68,    97,    98,    99,   116,   117,
     118,   119,   120,    66,    97,    66,    66,    66,   138,    67,
     116,   181,     4,   152,   153,   154,   155,   156,   402,    40,
      41,    79,   197,    68,   307,   345,   345,    72,   121,   242,
      95,    67,   181,   208,   340,   341,   342,   503,   475,   476,
     477,   478,    72,    79,   481,    69,   222,   237,    68,    79,
     516,   144,    72,   201,   267,   521,   149,   523,   151,    79,
      69,   246,    34,   318,   249,    87,    67,   237,   198,    91,
      52,   358,   509,    73,   361,   250,   100,   101,    79,   197,
     296,   325,   326,   327,   328,   369,     3,    73,   332,     6,
     208,   100,   101,    79,   318,    55,    13,   245,   397,   289,
     279,   280,    73,    65,   197,   284,   285,   297,    79,   299,
     409,   250,    80,    81,    82,   208,    84,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   397,   317,   353,    81,
      82,   451,    84,    79,   542,   420,   266,   307,    84,   309,
     310,   311,   312,   313,   314,   315,   100,   101,   266,   324,
     325,   326,   327,   328,   357,     3,     4,   332,   307,   252,
     309,   351,    67,   353,   340,   341,   342,    26,   317,    94,
      29,   319,    22,   386,    99,    68,    35,   402,   381,    72,
      39,   384,    68,   353,   387,   333,    72,    66,   432,     4,
      68,   490,    68,   418,    72,   420,    72,    97,    98,    99,
     117,   118,   119,   120,     4,   335,   324,   325,   326,   327,
     328,    67,   402,   297,   332,   470,    67,    53,   505,   506,
     359,   360,   244,    67,   308,   373,    81,    82,   418,    84,
     420,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     370,   371,    60,   336,    81,    82,   470,    84,     3,   379,
     420,    73,   370,    71,    66,   277,    66,   432,    78,   281,
     463,   379,    73,    96,   286,    68,    85,   351,    72,   482,
     483,   420,   485,    79,    92,    73,    20,    95,    24,   464,
     465,    24,    84,   462,    72,    40,    41,   466,   436,   437,
     438,   439,    67,    67,   507,   443,    80,    81,    82,   489,
      84,   480,    72,   493,    67,   484,   496,    67,   487,    67,
      67,    66,    20,    67,   432,    80,    81,    82,   402,    84,
     533,   534,    67,   471,     3,   504,   539,   540,   541,    67,
      67,   479,   535,   536,   418,    67,     4,     5,    57,   432,
      95,     9,   555,   556,    12,   475,   476,   477,   478,    67,
      67,   481,   542,   501,     4,    23,    52,   475,   476,   477,
     478,    40,    41,   481,   512,   513,   514,   515,   547,   548,
     518,    79,    80,    81,    82,   468,    84,    54,    66,   509,
      59,    60,     4,    79,    80,    81,    82,    66,    84,    72,
     538,   509,     0,     1,     3,     4,     4,    79,    80,    81,
      82,    69,    84,     4,     3,   489,    97,    98,    99,   493,
      67,    67,   496,    21,     4,    83,    95,    25,    67,    27,
      28,    67,    30,    66,    32,    79,    67,    67,    36,    46,
      27,    40,    41,   296,    42,    43,    44,    45,   171,    47,
      48,    40,    41,   111,   112,   171,   490,   402,    56,   298,
      58,   554,    60,   181,   181,    63,    64,    66,    66,   181,
      59,    60,    70,    71,   309,   335,    74,    66,   350,   222,
      20,   139,   140,   141,   230,   143,     0,     1,    69,    60,
       4,    69,   370,    64,    92,    66,    95,    95,   197,   370,
      71,   159,   324,   468,   206,    -1,    95,    21,    -1,    -1,
     168,    25,    -1,    27,    28,    -1,    30,    -1,    32,    -1,
      -1,    92,    36,    -1,    95,     3,     4,    -1,    42,    43,
      44,    45,    -1,    47,    48,    -1,    -1,    -1,    16,    17,
      18,    19,    56,    -1,    58,    23,    60,    -1,    -1,    63,
      64,    -1,    66,    31,    -1,    33,    70,    71,    -1,    37,
      74,     8,    40,    41,    11,    12,    13,    14,    15,    -1,
      48,    49,    50,    51,     3,     4,     3,     4,    92,    -1,
      -1,    95,    -1,    62,    -1,   243,    -1,    -1,    66,    16,
      17,    18,    19,    40,    -1,    -1,    23,    -1,   256,    -1,
      79,    80,    81,    82,    31,    84,    33,    -1,    -1,    -1,
      37,    40,    41,    40,    41,     3,     4,    95,    -1,    -1,
      -1,    48,    49,    50,    51,    -1,    -1,    -1,    16,    17,
      18,    19,    -1,     3,     4,    -1,    -1,    66,    -1,    66,
      -1,    -1,     3,     4,    -1,    33,     3,    -1,    -1,    37,
      -1,    -1,    40,    41,    -1,    16,    17,    18,    19,    -1,
      48,    49,    50,    -1,    -1,    -1,    95,    -1,    95,    -1,
      40,    41,    33,     3,    -1,    -1,    37,    -1,    66,    40,
      41,    38,    -1,    40,    41,    -1,    -1,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,     3,    66,    -1,    -1,    56,
      57,    58,    59,    60,    61,    66,    -1,    95,    -1,    66,
      40,    41,    60,    61,    71,    -1,    -1,     3,    66,    -1,
      -1,    -1,     3,    71,    -1,    95,    56,    57,    58,    59,
      60,    61,    40,    41,    95,    92,    66,    -1,    95,    -1,
      -1,    71,    -1,    -1,    92,    -1,    -1,    95,    56,    57,
      58,    59,    60,    61,    40,    41,    -1,    -1,    66,    40,
      41,    67,    92,    71,    -1,    95,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    56,    57,    58,    59,    60,
      66,    67,     4,    -1,    92,    66,    -1,    95,    94,    95,
      68,    97,    98,    99,    16,    17,    18,    19,    56,    -1,
      58,    -1,    60,    -1,    -1,    -1,    64,    -1,    66,    95,
      -1,    33,    -1,    71,    95,    37,    94,    95,    -1,    97,
      98,    99,    55,    62,    -1,    -1,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    92,    62,    -1,    95,    -1,    -1,
      79,    80,    81,    82,    66,    84,    79,    80,    81,    82,
      67,    84,    79,    80,    81,    82,    -1,    84,    -1,    -1,
      -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,    85,
      86,    87,    88,    89,    90,    91,    85,    86,    87,    88,
      89,    90,    91,    93,    94,    95,    -1,    97,    98,    99,
      94,    95,    -1,    97,    98,    99,    79,    80,    81,    82,
      -1,    84,    79,    80,    81,    82,    -1,    84,    94,    95,
      -1,    97,    98,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    21,    25,    27,    28,    30,    32,    36,    42,
      43,    44,    45,    47,    48,    56,    58,    60,    63,    64,
      66,    70,    71,    74,    92,    95,   105,   106,   107,   108,
     120,   121,   130,   133,   143,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   186,   187,   188,   189,   195,   203,   204,   217,
      68,     3,    40,    41,    56,    57,    58,    59,    61,    66,
      71,    95,   175,   176,   177,   178,   190,   203,   208,   209,
     210,   211,   213,   217,   174,   188,   175,   175,   174,   203,
     203,   175,   175,   174,   203,     8,    11,    12,    13,    14,
      15,    40,   188,   186,   187,   203,   175,     0,   107,    68,
      68,    34,    74,   151,    79,    84,   216,    26,    29,    35,
      39,    85,     4,   203,    66,    95,   209,   100,   101,   192,
     193,   194,   175,   176,   178,   210,   203,   213,    52,    80,
      81,    82,   154,   216,    85,    86,    87,    88,    89,    90,
      91,   218,    94,    95,    97,    98,    99,   175,   151,    20,
     153,   153,   151,   154,   154,   153,   151,   151,    55,   157,
       4,    66,   109,   110,   111,   112,   113,   114,   115,   116,
       4,    66,   122,   123,   124,   125,   126,   127,   128,   129,
     212,   213,   214,   215,    38,    41,    61,    66,    71,   196,
     197,   198,   199,   200,   201,   202,   208,   210,   217,   131,
     132,   203,     4,    16,    17,    18,    19,    33,    37,    48,
      49,    50,    66,   134,   135,   136,   140,   141,   142,     4,
      66,   144,   145,   146,   147,   148,   149,    73,    65,    67,
     157,   175,   175,    22,   152,   186,   174,   174,   174,   174,
      66,   208,    66,   209,     4,     4,    69,   193,   194,    67,
      67,    67,   203,   175,   175,   175,    53,   155,   175,   208,
     208,   208,   209,   209,   209,   209,   209,   152,   175,   154,
     154,   152,   157,   157,   154,   154,   152,   175,   179,    66,
     109,   110,   112,   114,   116,    68,    72,    73,    79,    66,
     122,   123,   125,   127,   129,   215,    68,    72,    73,    79,
      93,    94,    95,    97,    98,    99,    73,    73,   192,   198,
     201,   210,   203,    68,    72,    80,    81,    82,   216,    85,
      90,   218,    78,   198,    68,    72,    85,   134,   135,    68,
      72,    79,    96,    94,    99,    66,   145,   147,   149,    68,
      72,    73,    79,    66,   214,   157,   175,   153,   151,    24,
      24,   151,   209,    67,   205,   206,   208,    67,   175,    61,
      66,    71,   180,   182,   183,   184,   185,   191,   203,   217,
     157,   153,   155,   155,   153,   155,   155,   153,   139,   140,
     207,   212,   214,    67,    67,    67,    67,    66,   111,    23,
      31,    51,    66,   118,   119,   137,   138,   139,   142,    66,
     115,   207,    67,    67,    67,    67,    67,   122,    66,   138,
      66,   128,   214,   214,   214,   214,   214,   214,     3,     4,
     212,   213,    69,    67,    67,   196,   198,   198,   198,   198,
     208,   208,   208,   198,   132,   208,    67,   134,   134,   134,
      57,    66,   147,    67,    67,    67,   144,   138,   150,     4,
     214,    68,   154,   152,   209,   209,   152,    67,    79,    62,
     192,   182,   183,   185,   203,    80,    81,    82,   216,   182,
     154,    54,   156,   156,   154,   156,   157,   154,    67,    79,
      66,   112,    46,    66,   119,   139,    66,   116,    67,   139,
     129,   198,   149,   155,   154,   151,   151,   155,   206,    69,
      67,    67,   182,   182,   182,   182,   155,   181,   182,   157,
     157,   155,   157,   155,   139,   113,     4,   117,   139,    67,
      67,   139,    62,   156,   155,   152,   152,   157,   182,   156,
     156,   156,    66,    67,    67,   157,   157,   154,   154,    62,
     157,   157,   157,   207,    46,   155,   155,    67,   117,   157,
     157
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
#line 462 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2242 "parser.cc"
	break;
      case 5: /* "T_STRING" */

/* Line 1391 of yacc.c  */
#line 462 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2251 "parser.cc"
	break;
      case 113: /* "constant_schema_outer_list" */

/* Line 1391 of yacc.c  */
#line 470 "parser.yy"
	{ if((yyvaluep->l_constant) != NULL) { deallocateList((yyvaluep->l_constant)); } };

/* Line 1391 of yacc.c  */
#line 2260 "parser.cc"
	break;
      case 114: /* "constant_schema_list" */

/* Line 1391 of yacc.c  */
#line 470 "parser.yy"
	{ if((yyvaluep->l_constant) != NULL) { deallocateList((yyvaluep->l_constant)); } };

/* Line 1391 of yacc.c  */
#line 2269 "parser.cc"
	break;
      case 115: /* "constant_outer_schema" */

/* Line 1391 of yacc.c  */
#line 464 "parser.yy"
	{ delete (yyvaluep->constant); };

/* Line 1391 of yacc.c  */
#line 2278 "parser.cc"
	break;
      case 116: /* "constant_schema" */

/* Line 1391 of yacc.c  */
#line 464 "parser.yy"
	{ delete (yyvaluep->constant); };

/* Line 1391 of yacc.c  */
#line 2287 "parser.cc"
	break;
      case 117: /* "constant_schema_nodecl" */

/* Line 1391 of yacc.c  */
#line 464 "parser.yy"
	{ delete (yyvaluep->constant); };

/* Line 1391 of yacc.c  */
#line 2296 "parser.cc"
	break;
      case 118: /* "constant_outer_binder" */

/* Line 1391 of yacc.c  */
#line 474 "parser.yy"
	{ if((yyvaluep->constant_binder_t) != NULL) { deallocateItem((yyvaluep->constant_binder_t)); } };

/* Line 1391 of yacc.c  */
#line 2305 "parser.cc"
	break;
      case 119: /* "constant_binder" */

/* Line 1391 of yacc.c  */
#line 474 "parser.yy"
	{ if((yyvaluep->constant_binder_t) != NULL) { deallocateItem((yyvaluep->constant_binder_t)); } };

/* Line 1391 of yacc.c  */
#line 2314 "parser.cc"
	break;
      case 126: /* "object_outer_schema_list" */

/* Line 1391 of yacc.c  */
#line 471 "parser.yy"
	{ if((yyvaluep->l_object) != NULL) { deallocateList((yyvaluep->l_object)); } };

/* Line 1391 of yacc.c  */
#line 2323 "parser.cc"
	break;
      case 127: /* "object_schema_list" */

/* Line 1391 of yacc.c  */
#line 471 "parser.yy"
	{ if((yyvaluep->l_object) != NULL) { deallocateList((yyvaluep->l_object)); } };

/* Line 1391 of yacc.c  */
#line 2332 "parser.cc"
	break;
      case 128: /* "object_outer_schema" */

/* Line 1391 of yacc.c  */
#line 466 "parser.yy"
	{ delete (yyvaluep->object); };

/* Line 1391 of yacc.c  */
#line 2341 "parser.cc"
	break;
      case 129: /* "object_schema" */

/* Line 1391 of yacc.c  */
#line 466 "parser.yy"
	{ delete (yyvaluep->object); };

/* Line 1391 of yacc.c  */
#line 2350 "parser.cc"
	break;
      case 134: /* "sort_spec_outer_tuple" */

/* Line 1391 of yacc.c  */
#line 472 "parser.yy"
	{ if((yyvaluep->l_sort) != NULL) { deallocateList((yyvaluep->l_sort)); } };

/* Line 1391 of yacc.c  */
#line 2359 "parser.cc"
	break;
      case 135: /* "sort_spec_tuple" */

/* Line 1391 of yacc.c  */
#line 472 "parser.yy"
	{ if((yyvaluep->l_sort) != NULL) { deallocateList((yyvaluep->l_sort)); } };

/* Line 1391 of yacc.c  */
#line 2368 "parser.cc"
	break;
      case 136: /* "sort_spec" */

/* Line 1391 of yacc.c  */
#line 468 "parser.yy"
	{ delete (yyvaluep->sort); };

/* Line 1391 of yacc.c  */
#line 2377 "parser.cc"
	break;
      case 137: /* "sort_identifier_with_ab" */

/* Line 1391 of yacc.c  */
#line 462 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2386 "parser.cc"
	break;
      case 138: /* "sort_outer_identifier" */

/* Line 1391 of yacc.c  */
#line 462 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2395 "parser.cc"
	break;
      case 139: /* "sort_identifier" */

/* Line 1391 of yacc.c  */
#line 462 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2404 "parser.cc"
	break;
      case 140: /* "sort_identifier_no_range" */

/* Line 1391 of yacc.c  */
#line 462 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2413 "parser.cc"
	break;
      case 141: /* "sort_identifier_name" */

/* Line 1391 of yacc.c  */
#line 462 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2422 "parser.cc"
	break;
      case 142: /* "sort_constant_name" */

/* Line 1391 of yacc.c  */
#line 462 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2431 "parser.cc"
	break;
      case 148: /* "variable_outer_list" */

/* Line 1391 of yacc.c  */
#line 473 "parser.yy"
	{ if((yyvaluep->l_variable) != NULL) { deallocateList((yyvaluep->l_variable)); } };

/* Line 1391 of yacc.c  */
#line 2440 "parser.cc"
	break;
      case 149: /* "variable_list" */

/* Line 1391 of yacc.c  */
#line 473 "parser.yy"
	{ if((yyvaluep->l_variable) != NULL) { deallocateList((yyvaluep->l_variable)); } };

/* Line 1391 of yacc.c  */
#line 2449 "parser.cc"
	break;
      case 150: /* "variable_binding" */

/* Line 1391 of yacc.c  */
#line 468 "parser.yy"
	{ delete (yyvaluep->sort); };

/* Line 1391 of yacc.c  */
#line 2458 "parser.cc"
	break;
      case 204: /* "lua_indicator" */

/* Line 1391 of yacc.c  */
#line 462 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2467 "parser.cc"
	break;
      case 207: /* "sort_identifier_list" */

/* Line 1391 of yacc.c  */
#line 472 "parser.yy"
	{ if((yyvaluep->l_sort) != NULL) { deallocateList((yyvaluep->l_sort)); } };

/* Line 1391 of yacc.c  */
#line 2476 "parser.cc"
	break;
      case 212: /* "num_range" */

/* Line 1391 of yacc.c  */
#line 465 "parser.yy"
	{ delete (yyvaluep->numRange); };

/* Line 1391 of yacc.c  */
#line 2485 "parser.cc"
	break;
      case 213: /* "extended_integer" */

/* Line 1391 of yacc.c  */
#line 462 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2494 "parser.cc"
	break;
      case 214: /* "extended_integer_outer_expression" */

/* Line 1391 of yacc.c  */
#line 462 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2503 "parser.cc"
	break;
      case 215: /* "extended_integer_expression" */

/* Line 1391 of yacc.c  */
#line 462 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2512 "parser.cc"
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
#line 478 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 480 "parser.yy"
    { 
		(yyval.not_used) = PARSERULE_NOT_USED; 

		// Ensure that we append the footer
		// after the program has finished translating
		mainTrans->outputFooter();
		
}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 490 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 491 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 494 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 495 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 496 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 497 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 498 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 499 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 500 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 501 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 503 "parser.yy"
    { 
	(yyval.not_used) = PARSERULE_NOT_USED;
	/* On an error, go to the end of the bad statement and try to continue.
       Set the error handler to not wait to report syntax errors if more show up. */
	yyerrok;
}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 508 "parser.yy"
    {(yyval.not_used) = PARSERULE_NOT_USED;}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 516 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 519 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 520 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 523 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 524 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 527 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 528 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 532 "parser.yy"
    {

	// Fill in each Constant's type and domain and translate each of them.
	bool constantError = true; // Set to true if any of the constants have trouble getting added to the symbol table.
	Sort* tempSort = NULL;

	// double check that this is a valid constant type for the language we're working in.
	// TODO: This is where you would add other language constnat type checks.

	if ((yyvsp[(3) - (3)].constant_binder_t)) {

		switch (mainTrans->lang()) {
		case LANG_CPLUS:
			switch ((yyvsp[(3) - (3)].constant_binder_t)->constType) {
			case Constant::CONST_UNKNOWN:
				mainTrans->error("Bad constant declaration. The constant type is not recognized.", true);
				break;
			default:
				break;
			}
			break;

		case LANG_BC:
			switch ((yyvsp[(3) - (3)].constant_binder_t)->constType) {
			case Constant::CONST_UNKNOWN:
				mainTrans->error("Bad constant declaration. The constant type is not recognized.", true);
				break;
			case Constant::CONST_STATICAB:
			case Constant::CONST_DYNAMICAB:
				mainTrans->error("Bad constant declaration. Abnormality constants aren't supported in language BC.", true);
				break;
			case Constant::CONST_ATTRIBUTE:
				mainTrans->error("Bad constant declaration. The specified constant type isn't supported in language BC.", true);
				break;
			case Constant::CONST_ADDITIVEACTION:
			case Constant::CONST_ADDITIVEFLUENT:
				mainTrans->error("Bad constant declaration. Additive constants aren't supported in language BC.", true);
				break;
			case Constant::CONST_ACTION:
				// bc uses only exogenous actions.
				(yyvsp[(3) - (3)].constant_binder_t)->constType = Constant::CONST_EXOGENOUSACTION;
				break;
			case Constant::CONST_EXOGENOUSACTION:
				break;
			}
		case LANG_BCPLUS:
			switch ((yyvsp[(3) - (3)].constant_binder_t)->constType) {
			case Constant::CONST_UNKNOWN:
				mainTrans->error("Bad constant declaration. The constant type is not recognized.", true);
				break;
			case Constant::CONST_STATICAB:
			case Constant::CONST_DYNAMICAB:
				mainTrans->error("Bad constant declaration. Abnormality constants aren't supported in language BC.", true);
				break;
			case Constant::CONST_ATTRIBUTE:
				mainTrans->error("Bad constant declaration. The specified constant type isn't supported in language BC.", true);
				break;
			case Constant::CONST_ADDITIVEACTION:
			case Constant::CONST_ADDITIVEFLUENT:
				mainTrans->error("Bad constant declaration. Additive constants aren't supported in language BC.", true);
				break;
			case Constant::CONST_ACTION:
				break;
			case Constant::CONST_EXOGENOUSACTION:
				break;
			}
			break;
		case LANG_MVPF:
			// MVPF only allows rigid constants.
			switch ((yyvsp[(3) - (3)].constant_binder_t)->constType) {
			case Constant::CONST_UNKNOWN:
				mainTrans->error("Bad constant declaration. The constant type is not recognized.", true);
				break;
			case Constant::CONST_RIGID:
				break;
			case Constant::CONST_STATICAB:
			case Constant::CONST_DYNAMICAB:
			case Constant::CONST_ATTRIBUTE:
			case Constant::CONST_ADDITIVEACTION:
			case Constant::CONST_ADDITIVEFLUENT:
			case Constant::CONST_ACTION:
			case Constant::CONST_EXOGENOUSACTION:
				mainTrans->error("Bad constant declaration. The specified constant type isn't supported in MVPF.", true);
				break;
			}
			break;

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
				int addSymResult = mainTrans->addSymbol(*lIter);
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
					mainTrans->translateConstantDecl(*lIter);
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
#line 706 "parser.yy"
    {
	(yyval.l_constant) = (yyvsp[(1) - (1)].l_constant);
}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 710 "parser.yy"
    {
	(yyval.l_constant) = (yyvsp[(2) - (3)].l_constant);
}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 716 "parser.yy"
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
#line 725 "parser.yy"
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
#line 749 "parser.yy"
    {
	(yyval.constant) = (yyvsp[(1) - (1)].constant);
}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 753 "parser.yy"
    {
	(yyval.constant) = (yyvsp[(2) - (3)].constant);
}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 759 "parser.yy"
    {
	// Create a new Constant from a bare identifier.
	(yyval.constant) = new Constant(*(yyvsp[(1) - (1)].str), Constant::CONST_UNKNOWN, false);
	deallocateItem((yyvsp[(1) - (1)].str));
}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 765 "parser.yy"
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
#line 779 "parser.yy"
    {
	// TODO: Check if not found.
	(yyval.constant) = mainTrans->getConstant(*(yyvsp[(1) - (1)].str));

	if (!(yyval.constant))
		mainTrans->error("\"" + *(yyvsp[(1) - (1)].str) + std::string("/0") + "\" is not a valid constant identifier.", true);

	deallocateItem((yyvsp[(1) - (1)].str));
}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 789 "parser.yy"
    {
	(yyval.constant) = NULL;
	if((yyvsp[(3) - (4)].l_sort) != NULL)
	{
		(yyval.constant) = mainTrans->getConstant(*(yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].l_sort)->size());

		if (!(yyval.constant))
			mainTrans->error("\"" + *(yyvsp[(1) - (4)].str) + utils::to_string((yyvsp[(3) - (4)].l_sort)->size()) + "\" is not a valid constant identifier.", true);

		deallocateList((yyvsp[(3) - (4)].l_sort));
	}
	deallocateItem((yyvsp[(1) - (4)].str));
}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 805 "parser.yy"
    {
	(yyval.constant_binder_t) = (yyvsp[(1) - (1)].constant_binder_t);
}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 809 "parser.yy"
    {
	(yyval.constant_binder_t) = (yyvsp[(2) - (3)].constant_binder_t);
}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 815 "parser.yy"
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
#line 853 "parser.yy"
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
#line 876 "parser.yy"
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
#line 892 "parser.yy"
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
#line 964 "parser.yy"
    {
	// The new style of maxAdditive declaration. Insert a hint comment with the given maxAdditive value.
	if((yyvsp[(4) - (5)].str) != NULL)
	{
		std::string maxAdditiveHint = "% [MaxAdditive:";
		maxAdditiveHint += *((yyvsp[(4) - (5)].str));
		maxAdditiveHint += "]";
		mainTrans->output(maxAdditiveHint, IPART_NONE, true);
		(yyval.not_used) = PARSERULE_NOT_USED;
		deallocateItem((yyvsp[(4) - (5)].str));
	}
}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 980 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 983 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 984 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 987 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 988 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 991 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 992 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 996 "parser.yy"
    {
	// Connect each Object in the list to its sort, (try to) add them to the symbol table, and translate each object.

	if ((yyvsp[(1) - (3)].l_object) && (yyvsp[(3) - (3)].str)) {

		Sort* sort = mainTrans->getSort(*(yyvsp[(3) - (3)].str));
		Element* elem;

		if (!sort) {
			mainTrans->error("Bad object declaration. \"" + *(yyvsp[(3) - (3)].str) + "\" is not a valid sort.", true);
		} else if (!(yyvsp[(1) - (3)].l_object)) {
			// directly referenced sorts should be made visible.
			sort->internal(false);

			mainTrans->error("Bad object declaration.", true);
		} else {
			// directly referenced sorts should be made visible.
			sort->internal(false);

			// add each of the objects. 
			for (ObjectList::iterator it = (yyvsp[(1) - (3)].l_object)->begin(); it != (yyvsp[(1) - (3)].l_object)->end(); it++) {
				// make sure it's valid and hasn't been declared to something conflicting
				if (!*it) mainTrans->error("Bad object declaration.", true);
				else if ((elem = mainTrans->getSymbol((*it)->baseName(), (*it)->arity())) && elem->getElemType() != Element::ELEM_OBJ ) {
						mainTrans->error("Detected a conflicting definition of \"" + elem->baseName() 
							+ "/" + utils::to_string(elem->arity()) + "\".", true);
				} else {
					mainTrans->translateObjectDecl(*it, sort);
					
					if (!elem) {
						elem = *it;
						if (mainTrans->addSymbol(elem) != SymbolTable::ADDSYM_OK) {
							mainTrans->error("An error occurred processing the definition of \"" + elem->baseName() 
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
#line 1052 "parser.yy"
    {
	(yyval.l_object) = (yyvsp[(1) - (1)].l_object);
}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 1056 "parser.yy"
    {
	(yyval.l_object) = (yyvsp[(2) - (3)].l_object);
}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 1062 "parser.yy"
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
#line 1072 "parser.yy"
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
#line 1096 "parser.yy"
    {
	(yyval.object) = (yyvsp[(1) - (1)].object);
}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 1100 "parser.yy"
    {
	(yyval.object) = (yyvsp[(2) - (3)].object);
}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 1106 "parser.yy"
    {
	// Create a new Object from a bare identifier.
	(yyval.object) = new Object(*(yyvsp[(1) - (1)].str), Object::OBJ_NAME, false);
	deallocateItem((yyvsp[(1) - (1)].str));
}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 1112 "parser.yy"
    {
	// Create a new Object from a parameterized identifier.
	(yyval.object) = new Object(*(yyvsp[(1) - (4)].str), Object::OBJ_NAME, false, (yyvsp[(3) - (4)].l_sort));
	deallocateList((yyvsp[(3) - (4)].l_sort));
	deallocateItem((yyvsp[(1) - (4)].str));
}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 1119 "parser.yy"
    {
	// Create a new object from arbitrary math.
	(yyval.object) = new Object(*(yyvsp[(1) - (1)].str), Object::OBJ_NAME, true);
	deallocateItem((yyvsp[(1) - (1)].str)); // Free dynamic memory that's not needed anymore.
}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 1125 "parser.yy"
    {
	// Upcast a NumberRange into an Object.
	(yyval.object) = (Object*)(yyvsp[(1) - (1)].numRange);
}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 1134 "parser.yy"
    {
	if ((yyvsp[(3) - (4)].v_parseElement)) {
		mainTrans->translateShowStmt(*(yyvsp[(3) - (4)].v_parseElement));
	} else {
		YYERROR;
	}
	deallocateList((yyvsp[(3) - (4)].v_parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 1147 "parser.yy"
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
#line 1157 "parser.yy"
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
#line 1171 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 1175 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 1189 "parser.yy"
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
#line 1200 "parser.yy"
    {
	(yyval.l_sort) = (yyvsp[(1) - (1)].l_sort);
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 1204 "parser.yy"
    {
	(yyval.l_sort) = (yyvsp[(2) - (3)].l_sort);
}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 1210 "parser.yy"
    {
	(yyval.l_sort) = new SortList();
	(yyval.l_sort)->push_back((yyvsp[(1) - (1)].sort));
}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 1215 "parser.yy"
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
#line 1232 "parser.yy"
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
#line 1251 "parser.yy"
    {
	// Have a helper function handle making and translating the sort.
	(yyval.sort) = mainTrans->addSort(*(yyvsp[(1) - (1)].str), false, NULL, true, false);
	deallocateItem((yyvsp[(1) - (1)].str));
	if((yyval.sort) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 1261 "parser.yy"
    {
	// Have a helper function handle making and translating the sort.
	(yyval.sort) = mainTrans->addSort(*(yyvsp[(1) - (3)].str), false, (yyvsp[(3) - (3)].l_sort), true, false);
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
#line 1274 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1278 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("staticAbnormality");
}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1283 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("dynamicAbnormality");
}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1290 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 1294 "parser.yy"
    {
	(yyval.str) = (yyvsp[(2) - (3)].str);
}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1302 "parser.yy"
    {
	// A standard identifier.
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1307 "parser.yy"
    {
	// A quick-and-dirty dynamically declared sort.

	// Turn it into a sort and pass it down the chain.
	if((yyvsp[(1) - (1)].numRange) != NULL)
	{
		(yyval.str) = new std::string();
		*(yyval.str) = Translator::numRangeToSortName((yyvsp[(1) - (1)].numRange)->min(), (yyvsp[(1) - (1)].numRange)->max());
		Sort* tempSort = mainTrans->getSort(*(yyval.str));
		if(tempSort == NULL)
		{
			// Have a helper function handle making and translating the sort.
			tempSort = mainTrans->addSort(*(yyval.str), true, NULL, true, false);
			// Also add the number range as an object for this new sort.

			int min, max;
			if (utils::from_string(min, (yyvsp[(1) - (1)].numRange)->min()) && utils::from_string(max, (yyvsp[(1) - (1)].numRange)->max())) {			

				for (int i = min; i <= max; i++) {

					std::string str = utils::to_string(i);
					Element* obj = mainTrans->getSymbol(str);
					if (obj) {
						if (obj->getElemType() != Element::ELEM_OBJ) {
							mainTrans->error("detected a conflicting definition of \"" + str + "\"", true);
							obj = NULL;
						}
					} else {
						obj = new Object(str, Object::OBJ_NAME, false);
						if (mainTrans->addSymbol(obj) != SymbolTable::ADDSYM_OK) {
							delete obj;
							obj = NULL;
						} 
					}

					if (obj) {
						tempSort->addObject((Object*)obj);
						mainTrans->translateObjectDecl((Object*)obj, tempSort);
					}
				}
			} else {
				tempSort = mainTrans->addSort(*(yyval.str), true, NULL, true, false);
				Element* obj = mainTrans->getSymbol((yyvsp[(1) - (1)].numRange)->baseName());
				if (obj) {
					if (obj->getElemType() != Element::ELEM_OBJ) {
						mainTrans->error("detected a conflicting definition of \"" + (yyvsp[(1) - (1)].numRange)->baseName() + "\"", true);
						obj = NULL;
					}
				} else {
					obj = new Object((yyvsp[(1) - (1)].numRange)->baseName(), Object::OBJ_NAME, false);
					if (mainTrans->addSymbol(obj) != SymbolTable::ADDSYM_OK) {
						delete obj;
						obj = NULL;
					} 
				}

				if (obj) {
					tempSort->addObject((Object*)obj);
					mainTrans->translateObjectDecl((Object*)obj, tempSort);
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
#line 1385 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 1389 "parser.yy"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = (*(yyvsp[(1) - (2)].str)) + "*";
	deallocateItem((yyvsp[(1) - (2)].str));
}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 1395 "parser.yy"
    {
	// Alternate way to express the idea of a starred sort.
	(yyval.str) = new std::string;
	(*(yyval.str)) = (*(yyvsp[(1) - (3)].str)) + "*";
	deallocateItem((yyvsp[(1) - (3)].str));
}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1404 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1408 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 1414 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("abAction");
}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1419 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("action");
}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1424 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("additiveAction");
}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1429 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("additiveFluent");
}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1434 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("exogenousAction");
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1439 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("inertialFluent");
}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1444 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("rigid");
}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1449 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("sdFluent");
}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1454 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("simpleFluent");
}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1462 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1465 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1466 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1469 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1470 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1473 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1474 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1478 "parser.yy"
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

			if ((elem = mainTrans->getSymbol((*vIter)->baseName(), 0)) && (elem->getElemType() != Element::ELEM_VAR 
				|| ((Variable*)elem)->domain() != (yyvsp[(3) - (3)].sort) )) {
				mainTrans->error("Detected a conflicted definition for the \"" + (*vIter)->baseName() + std::string("/0") + "\" identifier.", true);
			} else if (elem) {
				mainTrans->warn("Detected a redeclaration of \"" + (*vIter)->baseName() + std::string("/0") + "\".", true);
			}
			else if (mainTrans->addSymbol(*vIter) != SymbolTable::ADDSYM_OK) {
				mainTrans->error("An error occurred declaring variable \"" + (*vIter)->baseName() + "\".", true);
				delete *vIter;
			} else 
				mainTrans->translateVariableDecl(*vIter);
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
#line 1513 "parser.yy"
    {
	(yyval.l_variable) = (yyvsp[(1) - (1)].l_variable);
}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 1517 "parser.yy"
    {
	(yyval.l_variable) = (yyvsp[(2) - (3)].l_variable);
}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 1523 "parser.yy"
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
#line 1536 "parser.yy"
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
#line 1554 "parser.yy"
    {
	// Find the sort in question, create it if it doesn't exist and is a "something*" sort (whose "something" exists already), or report an error.
	(yyval.sort) = mainTrans->getSort(*(yyvsp[(1) - (1)].str));
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
#line 1608 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1609 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 1612 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1613 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 1616 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 1617 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1620 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 1621 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1624 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1625 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 1628 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1629 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 1632 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 1633 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 1639 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 1640 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 1643 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1644 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1645 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1646 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1647 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 1648 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 1649 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 1650 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 1651 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 1652 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 1653 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 1654 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 1655 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 1660 "parser.yy"
    {
	bool transResult = mainTrans->translateAlwaysLaw((yyvsp[(2) - (5)].parseElement), (yyvsp[(3) - (5)].parseElement), (yyvsp[(4) - (5)].parseElement), (yyvsp[(5) - (5)].parseElement));
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
#line 1675 "parser.yy"
    {
	bool transResult = mainTrans->translateConstraintLaw((yyvsp[(2) - (7)].parseElement), (yyvsp[(3) - (7)].parseElement), (yyvsp[(4) - (7)].parseElement), (yyvsp[(5) - (7)].parseElement), (yyvsp[(6) - (7)].parseElement), (yyvsp[(7) - (7)].parseElement), true);
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
#line 1690 "parser.yy"
    {
	bool transResult = mainTrans->translateConstraintLaw((yyvsp[(2) - (7)].parseElement), (yyvsp[(3) - (7)].parseElement), (yyvsp[(4) - (7)].parseElement), (yyvsp[(5) - (7)].parseElement), (yyvsp[(6) - (7)].parseElement), (yyvsp[(7) - (7)].parseElement), false);
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
#line 1705 "parser.yy"
    {
	bool transResult = mainTrans->translateConstraintLaw((yyvsp[(2) - (7)].parseElement), (yyvsp[(3) - (7)].parseElement), (yyvsp[(4) - (7)].parseElement), (yyvsp[(5) - (7)].parseElement), (yyvsp[(6) - (7)].parseElement), (yyvsp[(7) - (7)].parseElement), false);
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
#line 1720 "parser.yy"
    {
	// This is a law of the form false <- F.
	// Which is really just a lazy shortcut for
	// caused c=v if F.

	bool transResult = mainTrans->translateConstraintLaw((yyvsp[(2) - (3)].parseElement), NULL, NULL, NULL, NULL, (yyvsp[(3) - (3)].parseElement), false);
	deallocateItem((yyvsp[(2) - (3)].parseElement));
	deallocateItem((yyvsp[(3) - (3)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 1737 "parser.yy"
    {

	bool transResult = mainTrans->translateDefaultLaw((yyvsp[(2) - (9)].parseElement), (yyvsp[(3) - (9)].parseElement), (yyvsp[(4) - (9)].parseElement), (yyvsp[(5) - (9)].parseElement), (yyvsp[(6) - (9)].parseElement), (yyvsp[(7) - (9)].parseElement), (yyvsp[(8) - (9)].parseElement), (yyvsp[(9) - (9)].parseElement));
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

  case 141:

/* Line 1806 of yacc.c  */
#line 1757 "parser.yy"
    {
	bool transResult = mainTrans->translateDeclarativeLaw((yyvsp[(2) - (4)].parseElement), NULL, NULL, NULL, (yyvsp[(3) - (4)].parseElement), NULL, NULL, (yyvsp[(4) - (4)].parseElement), SimpleUnaryOperator::UOP_EXOGENOUS);
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
#line 1771 "parser.yy"
    {
	bool transResult = mainTrans->translateDeclarativeLaw((yyvsp[(2) - (4)].parseElement), NULL, NULL, NULL, (yyvsp[(3) - (4)].parseElement), NULL, NULL, (yyvsp[(4) - (4)].parseElement), SimpleUnaryOperator::UOP_INERTIAL);
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

  case 143:

/* Line 1806 of yacc.c  */
#line 1785 "parser.yy"
    {
	bool transResult = mainTrans->translateNonexecutableLaw((yyvsp[(2) - (6)].parseElement), (yyvsp[(3) - (6)].parseElement), (yyvsp[(4) - (6)].parseElement), (yyvsp[(5) - (6)].parseElement), (yyvsp[(6) - (6)].parseElement));
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

  case 144:

/* Line 1806 of yacc.c  */
#line 1801 "parser.yy"
    {
	/*
	 * Let's _try_ to handle this, but we should throw a warning as this statement is not fully supported.
	 */

	ltsyystartWarning(ltsyylloc);
	ltsyyossErr << "Rules of the form \"rigid p [where F]\" are not fully supported and may produce unintended behavior. Please declare the constant as rigid instead.";
	ltsyyreportWarning();

	bool transResult = mainTrans->translateDeclarativeLaw((yyvsp[(2) - (3)].parseElement), NULL, NULL, NULL, NULL, NULL, NULL, (yyvsp[(3) - (3)].parseElement), SimpleUnaryOperator::UOP_RIGID);
	deallocateItem((yyvsp[(2) - (3)].parseElement));
	deallocateItem((yyvsp[(3) - (3)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 1822 "parser.yy"
    {
	bool transResult = mainTrans->translatePossiblyCausedLaw((yyvsp[(2) - (9)].parseElement), (yyvsp[(3) - (9)].parseElement), (yyvsp[(4) - (9)].parseElement), (yyvsp[(5) - (9)].parseElement), (yyvsp[(6) - (9)].parseElement), (yyvsp[(7) - (9)].parseElement), (yyvsp[(8) - (9)].parseElement), (yyvsp[(9) - (9)].parseElement));
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

  case 146:

/* Line 1806 of yacc.c  */
#line 1841 "parser.yy"
    {
	bool transResult = mainTrans->translateMayCauseLaw((yyvsp[(1) - (7)].parseElement), (yyvsp[(3) - (7)].parseElement), (yyvsp[(4) - (7)].parseElement), (yyvsp[(5) - (7)].parseElement), (yyvsp[(6) - (7)].parseElement), (yyvsp[(7) - (7)].parseElement));
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

  case 147:

/* Line 1806 of yacc.c  */
#line 1858 "parser.yy"
    {
	bool transResult = mainTrans->translateCausesLaw((yyvsp[(1) - (8)].parseElement), (yyvsp[(3) - (8)].parseElement), (yyvsp[(4) - (8)].parseElement), (yyvsp[(5) - (8)].parseElement), (yyvsp[(6) - (8)].parseElement), (yyvsp[(7) - (8)].parseElement), (yyvsp[(8) - (8)].parseElement));
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

  case 148:

/* Line 1806 of yacc.c  */
#line 1876 "parser.yy"
    {
	// This one's easy, it's just a pass-through.
	mainTrans->output("noconcurrency.", IPART_BASE, true);
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1882 "parser.yy"
    {
	// This one is also very easy.
	mainTrans->output("strong_noconcurrency.", IPART_BASE, true);
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1890 "parser.yy"
    {
	bool transResult = mainTrans->translateIncrementLaw((yyvsp[(1) - (10)].parseElement), (yyvsp[(3) - (10)].parseElement), (yyvsp[(5) - (10)].parseElement), (yyvsp[(6) - (10)].parseElement), (yyvsp[(7) - (10)].parseElement), (yyvsp[(8) - (10)].parseElement), (yyvsp[(9) - (10)].parseElement), (yyvsp[(10) - (10)].parseElement), true);
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
#line 1908 "parser.yy"
    {
	bool transResult = mainTrans->translateIncrementLaw((yyvsp[(1) - (10)].parseElement), (yyvsp[(3) - (10)].parseElement), (yyvsp[(5) - (10)].parseElement), (yyvsp[(6) - (10)].parseElement), (yyvsp[(7) - (10)].parseElement), (yyvsp[(8) - (10)].parseElement), (yyvsp[(9) - (10)].parseElement), (yyvsp[(10) - (10)].parseElement), false);
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

  case 152:

/* Line 1806 of yacc.c  */
#line 1928 "parser.yy"
    {
	// This is a law of the form c=v.
	// Which is really just a lazy shortcut for
	// caused c=v.

	mainTrans->translateCausalLaw((yyvsp[(1) - (8)].parseElement), (yyvsp[(2) - (8)].parseElement), (yyvsp[(3) - (8)].parseElement), (yyvsp[(4) - (8)].parseElement), (yyvsp[(5) - (8)].parseElement), (yyvsp[(6) - (8)].parseElement), (yyvsp[(7) - (8)].parseElement), (yyvsp[(8) - (8)].parseElement));
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

  case 153:

/* Line 1806 of yacc.c  */
#line 1945 "parser.yy"
    {
	// This is a law of the form c=v <- F.
	// Which is really just a lazy shortcut for
	// caused c=v if F.

	mainTrans->translateCausalLaw((yyvsp[(1) - (4)].parseElement), (yyvsp[(3) - (4)].parseElement), NULL, NULL, NULL, NULL, NULL, (yyvsp[(4) - (4)].parseElement));
	deallocateItem((yyvsp[(1) - (4)].parseElement));
	deallocateItem((yyvsp[(3) - (4)].parseElement));
	deallocateItem((yyvsp[(4) - (4)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1959 "parser.yy"
    {
	mainTrans->translateCausalLaw((yyvsp[(2) - (9)].parseElement), (yyvsp[(3) - (9)].parseElement), (yyvsp[(4) - (9)].parseElement), (yyvsp[(5) - (9)].parseElement), (yyvsp[(6) - (9)].parseElement), (yyvsp[(7) - (9)].parseElement), (yyvsp[(8) - (9)].parseElement), (yyvsp[(9) - (9)].parseElement));
	deallocateItem((yyvsp[(2) - (9)].parseElement));
	deallocateItem((yyvsp[(3) - (9)].parseElement));
	deallocateItem((yyvsp[(4) - (9)].parseElement));
	deallocateItem((yyvsp[(5) - (9)].parseElement));
	deallocateItem((yyvsp[(6) - (9)].parseElement));
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1970 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1974 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("true", mainTrans->getOrCreateObject("true"));
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1978 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("false", mainTrans->getOrCreateObject("false"));
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1984 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1988 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1998 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 2002 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 2006 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_AND, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 2010 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_OR, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 2014 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQUIV, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 2018 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_IMPL, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 2024 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 2028 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 2038 "parser.yy"
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

  case 169:

/* Line 1806 of yacc.c  */
#line 2057 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_STRONG_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 2061 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQ, (yyvsp[(3) - (3)].parseElement));

}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 2066 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_NEQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 2070 "parser.yy"
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

  case 173:

/* Line 1806 of yacc.c  */
#line 2097 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 2103 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 2109 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 2115 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 2121 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 2125 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 2135 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 2139 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 2143 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_AND, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 2147 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_OR, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 2151 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQUIV, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 2155 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_IMPL, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 2161 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 2165 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 2175 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
	if((yyval.parseElement) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 2183 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_STRONG_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 2187 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 2193 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 2197 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 2207 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 2211 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_AND, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 2215 "parser.yy"
    {
        (yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 2221 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 2225 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 2229 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_STRONG_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 2233 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 2239 "parser.yy"
    {
        (yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_CHOICE, (yyvsp[(2) - (3)].parseElement));
}
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 2245 "parser.yy"
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

  case 201:

/* Line 1806 of yacc.c  */
#line 2262 "parser.yy"
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

  case 202:

/* Line 1806 of yacc.c  */
#line 2277 "parser.yy"
    {
	(yyval.l_quantPair) = NULL;
	if((yyvsp[(1) - (1)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = new BigQuantifiers::QuantifierList();
		(yyval.l_quantPair)->push_back((yyvsp[(1) - (1)].p_quantPair));
	}
}
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 2286 "parser.yy"
    {
	(yyval.l_quantPair) = NULL;
	if((yyvsp[(1) - (1)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = new BigQuantifiers::QuantifierList();
		(yyval.l_quantPair)->push_back((yyvsp[(1) - (1)].p_quantPair));
	}
}
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 2295 "parser.yy"
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

  case 205:

/* Line 1806 of yacc.c  */
#line 2327 "parser.yy"
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

  case 206:

/* Line 1806 of yacc.c  */
#line 2361 "parser.yy"
    {
	(yyval.p_quantPair) = new BigQuantifiers::Quantifier( BigQuantifiers::QUANT_CONJ, NULL);

	// That identifier better be a variable...
	Variable* varRef = mainTrans->getVariable(*(yyvsp[(2) - (2)].str));
	if(varRef == NULL)
	{
		// It's not. We should tell them.
		// First. Let's figure out exactly what kind of error it is...
		if (mainTrans->getSymbol(*(yyvsp[(2) - (2)].str),0)) {
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
		if (mainTrans->addSymbol(varRef) == SymbolTable::ADDSYM_OK) { 
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

  case 207:

/* Line 1806 of yacc.c  */
#line 2400 "parser.yy"
    {
	(yyval.p_quantPair) = new std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>();
	(yyval.p_quantPair)->first = BigQuantifiers::QUANT_DISJ;
	// Guess that the identifier is a variable, otherwise just default to object.
	Variable* varRef = mainTrans->getVariable(*(yyvsp[(2) - (2)].str));
	if(varRef == NULL)
	{
		// It's not. We should tell them.
		// First. Let's figure out exactly what kind of error it is...
		if (mainTrans->getSymbol(*(yyvsp[(2) - (2)].str),0)) {
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
		if (mainTrans->addSymbol(varRef) == SymbolTable::ADDSYM_OK) { 
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

  case 208:

/* Line 1806 of yacc.c  */
#line 2441 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	int addQueryResult = mainTrans->addQuery(mainTrans->tempQuery);
	if(addQueryResult != SymbolTable::ADDSYM_OK)
	{
		if(addQueryResult == SymbolTable::ADDSYM_DUP)
		{	// Query with same label already exists.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "A query with label \"" << mainTrans->tempQuery->label << "\" already exists, query labels must be unique.";
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
		mainTrans->translateQuery(mainTrans->tempQuery);
		mainTrans->allocateNewTempQuery();
	}
}
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 2470 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 2474 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 2480 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	if (mainTrans->tempQuery && (yyvsp[(3) - (3)].str)) {
		if(mainTrans->tempQuery->label == "")
		{
			mainTrans->tempQuery->label = *(yyvsp[(3) - (3)].str);
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "label already defined as \"" << mainTrans->tempQuery->maxstep << "\" in this query, can only define it once per query.";
			ltsyyreportError();
			YYERROR;
		}
	}
	if ((yyvsp[(3) - (3)].str))	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 2498 "parser.yy"
    {

	(yyval.not_used) = PARSERULE_NOT_USED;
	if (mainTrans->tempQuery) {
		if(mainTrans->tempQuery->label == "")
		{
			mainTrans->tempQuery->label = utils::to_string((yyvsp[(3) - (3)].integer));
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "label already defined as \"" << mainTrans->tempQuery->maxstep << "\" in this query, can only define it once per query.";
			ltsyyreportError();
			YYERROR;
		}
	}
}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 2516 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	if (mainTrans->tempQuery && (yyvsp[(3) - (3)].numRange)) {
		if(mainTrans->tempQuery->maxstep == "")
		{
			mainTrans->tempQuery->maxstep = (yyvsp[(3) - (3)].numRange)->baseName();
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "maxstep already defined as \"" << mainTrans->tempQuery->maxstep << "\" in this query, can only define it once per query.";
			ltsyyreportError();
			YYERROR;
		}
	}
	if ((yyvsp[(3) - (3)].numRange)) deallocateItem((yyvsp[(3) - (3)].numRange));

}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 2535 "parser.yy"
    {
	if (mainTrans->tempQuery && (yyvsp[(3) - (3)].str)) {
		if(mainTrans->tempQuery->maxstep == "")
		{
			mainTrans->tempQuery->maxstep = *(yyvsp[(3) - (3)].str);
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "maxstep already defined as \"" << mainTrans->tempQuery->maxstep << "\" in this query, can only define it once per query.";
			ltsyyreportError();
			YYERROR;
		}
	}
	if ((yyvsp[(3) - (3)].str)) deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 2553 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	if((yyvsp[(1) - (1)].parseElement) != NULL)
	{
		// Add this new condition to the temp query.
		mainTrans->tempQuery->queryConditions.push_back((yyvsp[(1) - (1)].parseElement));
	}
	else
	{
		ltsyystartWarning(ltsyylloc);
		ltsyyossErr << "Query body formula is NULL!";
		ltsyyreportWarning();
	}
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 2571 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 2575 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 2583 "parser.yy"
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

  case 219:

/* Line 1806 of yacc.c  */
#line 2603 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 2607 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 2611 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_AND, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 2615 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_OR, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 2619 "parser.yy"
    {
		(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQUIV, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 2623 "parser.yy"
    {
		(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_IMPL, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 2629 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 2633 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 2643 "parser.yy"
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

  case 228:

/* Line 1806 of yacc.c  */
#line 2662 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_STRONG_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 2666 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 2670 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_NEQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 2674 "parser.yy"
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

  case 232:

/* Line 1806 of yacc.c  */
#line 2701 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 2707 "parser.yy"
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

  case 234:

/* Line 1806 of yacc.c  */
#line 2724 "parser.yy"
    {
	// Guess what kind of instance this might be, go with the best match.

	Element* elem = NULL;

	if ((yyvsp[(1) - (2)].str)) {

		elem = mainTrans->getOrCreateObject(*(yyvsp[(1) - (2)].str) + *(yyvsp[(2) - (2)].str), Object::OBJ_LUA);
		if (!elem || elem->getElemType() != Element::ELEM_OBJ || !((Object*)elem)->isLua()) {
			mainTrans->error("\"" + elem->baseName() + "/" + utils::to_string(elem->arity()) + "\" is used as a LUA call but has been declared.", true);
			elem = NULL;
		}
		(yyval.parseElement) = new ObjectLikeElement(*(yyvsp[(1) - (2)].str) + *(yyvsp[(2) - (2)].str), (Object*)elem);
		mainTrans->handleLUACall((ObjectLikeElement*)(yyval.parseElement));


	} else if ((elem = mainTrans->getSymbol(*(yyvsp[(2) - (2)].str)))) {

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

  case 235:

/* Line 1806 of yacc.c  */
#line 2767 "parser.yy"
    {
	// special case for empty parameter list LUA call 'a()'.
	Element* elem = NULL;

	if ((yyvsp[(1) - (4)].str)) {

		elem = mainTrans->getOrCreateObject(*(yyvsp[(1) - (4)].str) + *(yyvsp[(2) - (4)].str), Object::OBJ_LUA);
		if (!elem || elem->getElemType() != Element::ELEM_OBJ || !((Object*)elem)->isLua()) {
			mainTrans->error("\"" + elem->baseName() + "/" + utils::to_string(elem->arity()) + "\" is used as a LUA call but has been declared.", true);
			elem = NULL;
		}
		(yyval.parseElement) = new ObjectLikeElement(*(yyvsp[(1) - (4)].str) + *(yyvsp[(2) - (4)].str), (Object*)elem);
		mainTrans->handleLUACall((ObjectLikeElement*)(yyval.parseElement));

	} else {
		// not a LUA call.
		YYERROR;
	}

	deallocateItem((yyvsp[(1) - (4)].str));
	deallocateItem((yyvsp[(2) - (4)].str));
}
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 2791 "parser.yy"
    {
	Element* elem = NULL;

	if ((yyvsp[(1) - (5)].str)) {

		elem = mainTrans->getOrCreateObject(*(yyvsp[(1) - (5)].str) + *(yyvsp[(2) - (5)].str), Object::OBJ_LUA, false, (yyvsp[(4) - (5)].v_parseElement)->size());
		if (!elem || elem->getElemType() != Element::ELEM_OBJ || !((Object*)elem)->isLua()) {
			mainTrans->error("\"" + elem->baseName() + "/" + utils::to_string(elem->arity()) + "\" is used as a LUA call but has been declared.", true);
			elem = NULL;
		}

		(yyval.parseElement) = new ObjectLikeElement(*(yyvsp[(1) - (5)].str) + *(yyvsp[(2) - (5)].str), (Object*)elem, (yyvsp[(4) - (5)].v_parseElement));
		mainTrans->handleLUACall((ObjectLikeElement*)(yyval.parseElement));


	} else if ((elem = mainTrans->getSymbol(*(yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].v_parseElement)->size()))) {

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

  case 237:

/* Line 1806 of yacc.c  */
#line 2836 "parser.yy"
    { (yyval.str) = NULL; }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 2837 "parser.yy"
    { (yyval.str) = new std::string("@"); }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 2840 "parser.yy"
    {
	(yyval.v_parseElement) = NULL;
	(yyval.v_parseElement) = new ParseElementList();
	if((yyvsp[(1) - (1)].parseElement) != NULL)
	{
		(yyval.v_parseElement)->push_back((yyvsp[(1) - (1)].parseElement));
	}
}
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 2849 "parser.yy"
    {
	(yyval.v_parseElement) = NULL;
	if((yyvsp[(1) - (3)].v_parseElement) != NULL && (yyvsp[(3) - (3)].parseElement) != NULL)
	{
		(yyval.v_parseElement) = (yyvsp[(1) - (3)].v_parseElement);
		(yyval.v_parseElement)->push_back((yyvsp[(3) - (3)].parseElement));
	}
}
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 2860 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 2866 "parser.yy"
    {
	Sort* tempSort = mainTrans->getSort(*(yyvsp[(1) - (1)].str));
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

  case 243:

/* Line 1806 of yacc.c  */
#line 2887 "parser.yy"
    {
	(yyval.l_sort) = NULL;
	if((yyvsp[(1) - (3)].l_sort) != NULL)
	{
		(yyval.l_sort) = (yyvsp[(1) - (3)].l_sort);
		Sort* tempSort = mainTrans->getSort(*(yyvsp[(3) - (3)].str));
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

  case 244:

/* Line 1806 of yacc.c  */
#line 2914 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("true", mainTrans->getOrCreateObject("true"));
}
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 2918 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("false", mainTrans->getOrCreateObject("false"));
}
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 2922 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("none", mainTrans->getOrCreateObject("none"));
}
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 2926 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 2932 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 2936 "parser.yy"
    {
	(yyval.parseElement) = NULL;
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
		(yyval.parseElement)->parens(true);
	}
}
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 2947 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 2951 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_PLUS, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 2955 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_MINUS, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 2959 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_TIMES, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 2963 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_DIVIDE, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 2967 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_MOD, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 2971 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_ABS, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 2975 "parser.yy"
    {
	// Not necessary to flag parenBefore and parenAfter, translation of abs
	// automatically adds parentheses around the expression.
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_ABS, (yyvsp[(3) - (4)].parseElement));
}
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 2983 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement(*(yyvsp[(1) - (1)].str), mainTrans->getOrCreateObject(*(yyvsp[(1) - (1)].str)));
	deallocateItem((yyvsp[(1) - (1)].str));
}
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 2988 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 2994 "parser.yy"
    {
	(yyval.numRange) = new NumberRange(*(yyvsp[(1) - (3)].str), *(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 3002 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) = utils::to_string((yyvsp[(1) - (1)].integer));
}
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 3007 "parser.yy"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = "maxAdditive";
}
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 3012 "parser.yy"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = "maxstep";
}
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 3017 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) = "-";
	(*(yyval.str)) += (*(yyvsp[(2) - (2)].str));
	deallocateItem((yyvsp[(2) - (2)].str));
}
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 3026 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 3030 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += "(";
	(*(yyval.str)) += (*(yyvsp[(2) - (3)].str));
	(*(yyval.str)) += ")";
	deallocateItem((yyvsp[(2) - (3)].str));
}
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 3040 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 3044 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " + ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 3053 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " - ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 3062 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " * ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 3071 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " // ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 3080 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " mod ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 3092 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 3096 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 3102 "parser.yy"
    {
	(yyval.integer) = T_UMINUS;
}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 3106 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 3112 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 3116 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 3120 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 3124 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 3128 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;



/* Line 1806 of yacc.c  */
#line 6616 "parser.cc"
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
#line 3134 "parser.yy"


// Tries to find an existing normal sort or declare a starred ("something*") sort.
Sort* checkDynamicSortDecl(std::string const& sortIdent)
{
	Sort* retVal = mainTrans->getSort(sortIdent);
	// Allow dynamic instantiation of starred sorts.
	if(retVal == NULL && sortIdent.length() > 0 && sortIdent[sortIdent.length()-1] == '*')
	{
		// Verify that the non-starred version exists before instantiating the starred version.
		std::string nonStarIdent = sortIdent.substr(0, sortIdent.length()-1);
		Sort *nonStarSort = mainTrans->getSort(nonStarIdent);
		if(nonStarSort == NULL)
		{	
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << nonStarIdent << "\" not declared, can't dynamically use \"" << sortIdent << "\" as the domain of another declaration.";
			ltsyyreportError();
		}
		else
		{
			// No need to add unstarred version to subsorts, that's done automatically.
			retVal = mainTrans->addSort(sortIdent, false, NULL, true, false);
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
	mainTrans->caution(ltsyyossErr.str(), true);
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
	mainTrans->warn(ltsyyossErr.str(), true);
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
	mainTrans->error(ltsyyossErr.str(), true);
	LTSYYRESETOSS;

	// If the translator's temporary query appears to have been partially populated, destroy it and create another in its place.
	if(mainTrans->tempQuery != NULL && (mainTrans->tempQuery->label != "" || mainTrans->tempQuery->maxstep != "" || !(mainTrans->tempQuery->queryConditions.empty())))
	{
		mainTrans->allocateNewTempQuery(true);
	}
	if(mainTrans->tempQuery == NULL)
	{
		mainTrans->allocateNewTempQuery();
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

