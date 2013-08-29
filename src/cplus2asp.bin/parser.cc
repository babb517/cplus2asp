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
     T_PAREN_L = 319,
     T_PAREN_R = 320,
     T_PERIOD = 321,
     T_PIPE = 322,
     T_NOOP = 323,
     T_SEMICOLON = 324,
     T_DBL_COLON = 325,
     T_ARROW_LDASH = 326,
     T_ARROW_REQ = 327,
     T_ARROW_LEQ = 328,
     T_ARROW_RDASH = 329,
     T_COLON = 330,
     T_COMMA = 331,
     T_EQUIV = 332,
     T_IMPL = 333,
     T_DBL_PLUS = 334,
     T_DBL_AMP = 335,
     T_AMP = 336,
     T_EQ = 337,
     T_GTHAN_EQ = 338,
     T_EQ_LTHAN = 339,
     T_GTHAN = 340,
     T_LTHAN = 341,
     T_NOT_EQ = 342,
     T_DBL_EQ = 343,
     T_NOT = 344,
     T_DBL_PERIOD = 345,
     T_PLUS = 346,
     T_DASH = 347,
     T_DBL_GTHAN = 348,
     T_MOD = 349,
     T_INT_DIV = 350,
     T_STAR = 351,
     T_BIG_CONJ = 352,
     T_BIG_DISJ = 353,
     T_POUND = 354,
     T_UMINUS = 355
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
#define T_PAREN_L 319
#define T_PAREN_R 320
#define T_PERIOD 321
#define T_PIPE 322
#define T_NOOP 323
#define T_SEMICOLON 324
#define T_DBL_COLON 325
#define T_ARROW_LDASH 326
#define T_ARROW_REQ 327
#define T_ARROW_LEQ 328
#define T_ARROW_RDASH 329
#define T_COLON 330
#define T_COMMA 331
#define T_EQUIV 332
#define T_IMPL 333
#define T_DBL_PLUS 334
#define T_DBL_AMP 335
#define T_AMP 336
#define T_EQ 337
#define T_GTHAN_EQ 338
#define T_EQ_LTHAN 339
#define T_GTHAN 340
#define T_LTHAN 341
#define T_NOT_EQ 342
#define T_DBL_EQ 343
#define T_NOT 344
#define T_DBL_PERIOD 345
#define T_PLUS 346
#define T_DASH 347
#define T_DBL_GTHAN 348
#define T_MOD 349
#define T_INT_DIV 350
#define T_STAR 351
#define T_BIG_CONJ 352
#define T_BIG_DISJ 353
#define T_POUND 354
#define T_UMINUS 355




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
#line 391 "parser.cc"
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
#line 578 "parser.cc"

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
#line 623 "parser.cc"

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
#define YYFINAL  109
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1022

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  272
/* YYNRULES -- Number of states.  */
#define YYNSTATES  540

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   355

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
      95,    96,    97,    98,    99,   100
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
     213,   217,   219,   221,   223,   225,   229,   231,   233,   235,
     238,   242,   244,   246,   248,   250,   252,   254,   256,   258,
     260,   262,   264,   269,   271,   275,   277,   281,   283,   287,
     291,   293,   297,   299,   303,   305,   306,   309,   310,   313,
     314,   317,   318,   321,   322,   325,   326,   329,   330,   333,
     336,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   363,   365,   371,   379,   387,   395,   405,
     410,   415,   422,   426,   436,   444,   453,   455,   457,   468,
     479,   488,   498,   500,   502,   504,   506,   510,   512,   515,
     519,   523,   527,   531,   533,   537,   539,   543,   547,   551,
     553,   555,   557,   559,   561,   565,   567,   570,   574,   578,
     582,   586,   588,   592,   594,   596,   598,   602,   604,   608,
     610,   613,   617,   623,   629,   631,   633,   636,   639,   642,
     645,   650,   652,   656,   660,   664,   668,   672,   674,   676,
     680,   684,   686,   689,   693,   697,   701,   705,   707,   711,
     713,   717,   721,   725,   727,   733,   736,   741,   747,   748,
     750,   752,   756,   758,   760,   764,   766,   768,   770,   772,
     774,   778,   780,   784,   788,   792,   796,   800,   803,   808,
     810,   812,   816,   818,   820,   822,   825,   827,   831,   833,
     837,   841,   845,   849,   853,   855,   857,   859,   861,   863,
     865,   867,   869
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     102,     0,    -1,    -1,   103,    -1,   104,    -1,   103,   104,
      -1,   105,    -1,   117,    -1,   118,    -1,   191,    -1,   127,
      -1,   130,    -1,   140,    -1,   155,    -1,     1,    66,    -1,
      68,    -1,    63,     8,   106,    66,    -1,   107,    -1,    64,
     107,    65,    -1,   108,    -1,   106,    69,   108,    -1,   109,
      -1,    64,   109,    65,    -1,   110,    70,   115,    -1,   111,
      -1,    64,   111,    65,    -1,   112,    -1,   110,    76,   112,
      -1,   113,    -1,    64,   113,    65,    -1,     4,    -1,     4,
      64,   203,    65,    -1,     4,    -1,     4,    64,   203,    65,
      -1,   116,    -1,    64,   116,    65,    -1,   134,    -1,   139,
      64,   136,    65,    -1,    23,    46,   114,    -1,    23,    64,
     136,    65,    46,   114,    -1,    63,    40,    70,   210,    66,
      -1,    63,    11,   119,    66,    -1,   120,    -1,    64,   120,
      65,    -1,   121,    -1,   119,    69,   119,    -1,   122,    -1,
      64,   122,    65,    -1,   123,    70,   135,    -1,   124,    -1,
      64,   124,    65,    -1,   125,    -1,   123,    76,   125,    -1,
     126,    -1,    64,   126,    65,    -1,     4,    -1,     4,    64,
     203,    65,    -1,   210,    -1,   208,    -1,    63,    13,   128,
      66,    -1,   129,    -1,   128,    69,   129,    -1,   199,    -1,
     199,    82,   204,    -1,    63,    14,   131,    66,    -1,   132,
      -1,    64,   132,    65,    -1,   133,    -1,   131,    69,   131,
      -1,   137,    -1,   137,    93,   131,    -1,   135,    -1,    51,
      -1,    31,    -1,   136,    -1,    64,   136,    65,    -1,   137,
      -1,   208,    -1,   138,    -1,   138,    96,    -1,   138,    91,
      57,    -1,     4,    -1,   139,    -1,    16,    -1,    17,    -1,
      18,    -1,    19,    -1,    33,    -1,    37,    -1,    48,    -1,
      49,    -1,    50,    -1,    63,    15,   141,    66,    -1,   142,
      -1,    64,   142,    65,    -1,   143,    -1,   143,    69,   141,
      -1,   144,    -1,    64,   144,    65,    -1,   145,    70,   147,
      -1,   146,    -1,    64,   146,    65,    -1,     4,    -1,   146,
      76,     4,    -1,   135,    -1,    -1,    34,   172,    -1,    -1,
      22,   172,    -1,    -1,    20,   172,    -1,    -1,    52,   199,
      -1,    -1,    53,   177,    -1,    -1,    54,   178,    -1,    -1,
      55,   176,    -1,   156,    66,    -1,   170,    66,    -1,   157,
      -1,   158,    -1,   159,    -1,   160,    -1,   161,    -1,   162,
      -1,   163,    -1,   164,    -1,   165,    -1,   166,    -1,   167,
      -1,   168,    -1,   169,    -1,    21,   172,   151,   152,   154,
      -1,    28,   172,   150,   151,   152,   153,   154,    -1,    27,
     172,   150,   151,   152,   153,   154,    -1,    42,   172,   150,
     151,   152,   153,   154,    -1,    30,   171,   148,   149,   150,
     151,   152,   153,   154,    -1,    32,   199,   151,   154,    -1,
      36,   199,   151,   154,    -1,    45,   172,   148,   151,   152,
     154,    -1,    48,   199,   154,    -1,    47,   171,   148,   149,
     150,   151,   152,   153,   154,    -1,   172,    39,   171,   148,
     149,   152,   154,    -1,   172,    26,   171,   148,   149,   151,
     152,   154,    -1,    43,    -1,    44,    -1,   172,    35,   171,
      24,   205,   148,   149,   151,   152,   154,    -1,   172,    29,
     171,    24,   205,   148,   149,   151,   152,   154,    -1,   172,
     148,   149,   150,   151,   152,   153,   154,    -1,    25,   171,
     148,   149,   150,   151,   152,   153,   154,    -1,   183,    -1,
      58,    -1,    56,    -1,   173,    -1,    64,   173,    65,    -1,
     174,    -1,   213,   172,    -1,   172,   212,   172,    -1,   172,
      79,   172,    -1,   172,    77,   172,    -1,   172,    78,   172,
      -1,   175,    -1,    64,   175,    65,    -1,   204,    -1,   204,
      82,   204,    -1,   204,    87,   204,    -1,   204,   214,   204,
      -1,   186,    -1,   172,    -1,   179,    -1,   179,    -1,   180,
      -1,    64,   180,    65,    -1,   181,    -1,   213,   179,    -1,
     179,   212,   179,    -1,   179,    79,   179,    -1,   179,    77,
     179,    -1,   179,    78,   179,    -1,   182,    -1,    64,   182,
      65,    -1,   199,    -1,   187,    -1,   184,    -1,    64,   184,
      65,    -1,   185,    -1,   183,   212,   183,    -1,   199,    -1,
     213,   199,    -1,   199,    82,   204,    -1,    61,   188,    67,
     172,    62,    -1,    61,   188,    67,   179,    62,    -1,   189,
      -1,   190,    -1,   188,   189,    -1,   188,   190,    -1,    97,
       4,    -1,    98,     4,    -1,    63,    12,   192,    66,    -1,
     193,    -1,   192,    69,   192,    -1,    38,    70,     4,    -1,
      38,    70,     3,    -1,    41,    70,   208,    -1,    41,    70,
     209,    -1,   194,    -1,   195,    -1,    64,   194,    65,    -1,
     206,    75,   194,    -1,   196,    -1,   213,   194,    -1,   194,
     212,   194,    -1,   194,    79,   194,    -1,   194,    77,   194,
      -1,   194,    78,   194,    -1,   197,    -1,    64,   197,    65,
      -1,   204,    -1,   204,    82,   204,    -1,   204,    87,   204,
      -1,   204,   214,   204,    -1,   198,    -1,    61,   188,    67,
     194,    62,    -1,   200,     4,    -1,   200,     4,    64,    65,
      -1,   200,     4,    64,   201,    65,    -1,    -1,    60,    -1,
     202,    -1,   201,    76,   202,    -1,   204,    -1,   136,    -1,
     203,    76,   136,    -1,    58,    -1,    56,    -1,    57,    -1,
     205,    -1,   206,    -1,    64,   206,    65,    -1,   207,    -1,
     205,    91,   205,    -1,   205,    92,   205,    -1,   205,    96,
     205,    -1,   205,    95,   205,    -1,   205,    94,   205,    -1,
      59,   205,    -1,    59,    64,   205,    65,    -1,   209,    -1,
     199,    -1,   210,    90,   210,    -1,     3,    -1,    40,    -1,
      41,    -1,    92,   209,    -1,   211,    -1,    64,   211,    65,
      -1,   209,    -1,   210,    91,   210,    -1,   210,    92,   210,
      -1,   210,    96,   210,    -1,   210,    95,   210,    -1,   210,
      94,   210,    -1,    81,    -1,    76,    -1,    92,    -1,    89,
      -1,    88,    -1,    84,    -1,    83,    -1,    86,    -1,    85,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   471,   471,   472,   483,   484,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   501,   509,   512,   513,   516,
     517,   520,   521,   524,   652,   656,   662,   671,   695,   699,
     705,   711,   725,   735,   751,   755,   761,   799,   822,   838,
     910,   927,   930,   931,   934,   935,   938,   939,   942,   992,
     996,  1002,  1012,  1036,  1040,  1046,  1052,  1059,  1065,  1074,
    1087,  1097,  1111,  1115,  1129,  1140,  1144,  1150,  1155,  1188,
    1198,  1211,  1215,  1220,  1227,  1231,  1239,  1244,  1322,  1326,
    1332,  1341,  1345,  1351,  1356,  1361,  1366,  1371,  1376,  1381,
    1386,  1391,  1400,  1403,  1404,  1407,  1408,  1411,  1412,  1415,
    1450,  1454,  1460,  1473,  1491,  1546,  1547,  1550,  1551,  1554,
    1555,  1558,  1559,  1562,  1563,  1566,  1567,  1570,  1571,  1577,
    1578,  1581,  1582,  1583,  1584,  1585,  1586,  1587,  1588,  1589,
    1590,  1591,  1592,  1593,  1597,  1612,  1627,  1642,  1659,  1679,
    1693,  1707,  1723,  1744,  1763,  1780,  1798,  1804,  1812,  1830,
    1850,  1869,  1884,  1888,  1892,  1898,  1902,  1912,  1916,  1920,
    1924,  1928,  1932,  1938,  1942,  1952,  1971,  1976,  1980,  2007,
    2013,  2019,  2025,  2031,  2035,  2045,  2049,  2053,  2057,  2061,
    2065,  2071,  2075,  2085,  2093,  2099,  2103,  2113,  2117,  2123,
    2127,  2131,  2137,  2154,  2169,  2178,  2187,  2219,  2253,  2292,
    2333,  2362,  2366,  2372,  2388,  2405,  2424,  2442,  2460,  2464,
    2472,  2492,  2496,  2500,  2504,  2508,  2512,  2518,  2522,  2532,
    2551,  2555,  2559,  2586,  2592,  2609,  2652,  2676,  2721,  2722,
    2724,  2733,  2744,  2750,  2771,  2798,  2802,  2806,  2810,  2816,
    2820,  2831,  2835,  2839,  2843,  2847,  2851,  2855,  2859,  2867,
    2872,  2878,  2886,  2891,  2896,  2901,  2910,  2914,  2924,  2928,
    2937,  2946,  2955,  2964,  2976,  2980,  2986,  2990,  2996,  3000,
    3004,  3008,  3012
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
  "T_COLON_DASH", "T_PAREN_L", "T_PAREN_R", "T_PERIOD", "T_PIPE", "T_NOOP",
  "T_SEMICOLON", "T_DBL_COLON", "T_ARROW_LDASH", "T_ARROW_REQ",
  "T_ARROW_LEQ", "T_ARROW_RDASH", "T_COLON", "T_COMMA", "T_EQUIV",
  "T_IMPL", "T_DBL_PLUS", "T_DBL_AMP", "T_AMP", "T_EQ", "T_GTHAN_EQ",
  "T_EQ_LTHAN", "T_GTHAN", "T_LTHAN", "T_NOT_EQ", "T_DBL_EQ", "T_NOT",
  "T_DBL_PERIOD", "T_PLUS", "T_DASH", "T_DBL_GTHAN", "T_MOD", "T_INT_DIV",
  "T_STAR", "T_BIG_CONJ", "T_BIG_DISJ", "T_POUND", "T_UMINUS", "$accept",
  "program", "statement_sequence", "statement", "constant_statement",
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
  "cl_body_term_bool_inner", "literal_assign_conj",
  "literal_assign_conj_inner", "literal_assign_expr",
  "expr_big_expression", "expr_big_expression_bool",
  "expr_big_quantifiers", "expr_big_conj", "expr_big_disj",
  "query_statement", "query_expression_tuple", "query_expression",
  "query_body_formula", "query_body_formula_inner", "query_body_term",
  "query_body_term_inner", "expr_big_query_expression", "constant_expr",
  "lua_indicator", "parameter_list", "parameter_general",
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
     355
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   106,   106,   107,
     107,   108,   108,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   116,
     117,   118,   119,   119,   120,   120,   121,   121,   122,   123,
     123,   124,   124,   125,   125,   126,   126,   126,   126,   127,
     128,   128,   129,   129,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   134,   135,   135,   136,   136,   137,   137,
     137,   138,   138,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   140,   141,   141,   142,   142,   143,   143,   144,
     145,   145,   146,   146,   147,   148,   148,   149,   149,   150,
     150,   151,   151,   152,   152,   153,   153,   154,   154,   155,
     155,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   157,   158,   158,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   167,   168,   168,
     169,   170,   171,   171,   171,   172,   172,   173,   173,   173,
     173,   173,   173,   174,   174,   175,   175,   175,   175,   175,
     176,   177,   178,   179,   179,   180,   180,   180,   180,   180,
     180,   181,   181,   182,   182,   183,   183,   184,   184,   185,
     185,   185,   186,   187,   188,   188,   188,   188,   189,   190,
     191,   192,   192,   193,   193,   193,   193,   193,   194,   194,
     194,   195,   195,   195,   195,   195,   195,   196,   196,   197,
     197,   197,   197,   197,   198,   199,   199,   199,   200,   200,
     201,   201,   202,   203,   203,   204,   204,   204,   204,   205,
     205,   206,   206,   206,   206,   206,   206,   206,   206,   207,
     207,   208,   209,   209,   209,   209,   210,   210,   211,   211,
     211,   211,   211,   211,   212,   212,   213,   213,   214,   214,
     214,   214,   214
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
       1,     3,     1,     3,     4,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     7,     7,     9,     4,
       4,     6,     3,     9,     7,     8,     1,     1,    10,    10,
       8,     9,     1,     1,     1,     1,     3,     1,     2,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     3,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     3,     3,
       3,     1,     3,     1,     1,     1,     3,     1,     3,     1,
       2,     3,     5,     5,     1,     1,     2,     2,     2,     2,
       4,     1,     3,     3,     3,     3,     3,     1,     1,     3,
       3,     1,     2,     3,     3,     3,     3,     1,     3,     1,
       3,     3,     3,     1,     5,     2,     4,     5,     0,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     3,     3,     3,     3,     3,     2,     4,     1,
       1,     3,     1,     1,     1,     2,     1,     3,     1,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,   252,   228,   228,   228,   228,   228,   228,   228,
     253,   254,   228,   146,   147,   228,   228,   228,   236,   237,
     235,   228,   229,     0,     0,   228,    15,   267,   266,     0,
       0,     4,     6,     7,     8,    10,    11,    12,    13,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,     0,   105,   155,   157,   163,   169,     9,
     250,     0,   165,   238,   239,   241,   249,   228,    14,   111,
     154,   153,   228,   266,   105,   152,   185,   187,   189,   228,
     109,   109,   105,   111,   111,   109,   105,   105,   117,   228,
       0,   247,     0,     0,     0,   194,   195,     0,     0,   228,
     228,     0,     0,     0,     0,   155,   163,   239,   255,     1,
       5,   119,   120,   228,   228,   228,   228,   228,   265,   228,
     228,   228,   264,   107,   228,   225,   228,   270,   269,   272,
     271,   228,   268,   228,   228,   228,   228,   228,   228,   158,
     228,   113,     0,   185,   107,   228,   228,   190,   228,   111,
     111,   107,   117,   117,   111,   111,   107,   228,   142,   228,
       0,   198,   199,   228,   196,   197,    30,     0,     0,    17,
      19,    21,     0,    24,    26,    28,    55,     0,     0,    42,
      44,    46,     0,    49,    51,    53,    58,   258,    57,   256,
       0,   254,     0,   228,     0,   201,   207,   208,   211,   217,
     223,   219,   239,   228,     0,    60,    62,    81,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,    65,
      67,    69,    78,    82,   102,     0,     0,    93,    95,    97,
       0,   100,     0,   156,   164,   240,   105,     0,   106,     0,
     105,   161,   162,   160,   228,   109,   159,   228,   166,   167,
     168,   242,   243,   246,   245,   244,   112,   228,   117,   186,
     109,   188,   191,   110,   113,   113,   109,   139,   140,   113,
     113,   109,   170,   118,     0,   248,     0,     0,     0,    17,
      21,    24,    28,    16,     0,     0,     0,     0,     0,    42,
      46,    49,    53,   256,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   217,   239,
     200,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     212,    59,   228,   228,     0,    65,    64,     0,     0,     0,
      79,     0,     0,    97,   100,    92,     0,     0,     0,     0,
       0,   107,   228,   228,   107,   108,   111,   226,     0,   230,
     232,     0,   228,   114,   171,   173,   175,   181,   184,   183,
     228,   134,   111,   115,   115,   111,   115,   117,   111,   192,
     233,    76,     0,    77,     0,    18,    22,    25,    29,     0,
      20,     0,    73,    72,     0,    23,    34,    36,    71,    74,
      82,     0,    27,     0,    43,    47,    50,    54,   257,    45,
       0,    48,     0,    52,   251,   259,   260,   263,   262,   261,
     204,   203,   205,   258,   228,   209,   218,   202,   215,   216,
     214,   213,   220,   221,   222,   210,    61,    63,    66,    68,
      70,    80,     0,     0,    94,    98,   101,    96,   104,    99,
     103,     0,    40,   111,   105,   105,   113,   113,   227,   228,
       0,     0,   173,   181,   228,   228,   228,   228,   176,   113,
     228,   117,   117,   113,   117,   141,   113,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
       0,     0,   113,   107,   107,   117,   115,   231,   228,   174,
     182,   179,   180,   178,   177,   115,   116,   172,   136,   135,
     115,   137,   115,   234,     0,    32,    38,     0,    35,    75,
       0,   224,   117,   111,   111,   144,   117,     0,   117,   117,
     117,     0,     0,    37,   145,   113,   113,   150,   193,   151,
     138,   143,     0,     0,   117,   117,    33,    39,   149,   148
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    29,    30,    31,    32,   168,   169,   170,   171,   172,
     281,   174,   175,   506,   385,   386,    33,    34,   178,   179,
     180,   181,   182,   183,   184,   185,    35,   204,   205,    36,
     218,   219,   220,   387,   388,   370,   371,   222,   223,    37,
     226,   227,   228,   229,   230,   231,   439,   123,   245,   149,
     141,   258,   461,   158,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      74,    54,    55,    56,    57,   273,   353,   496,   354,   355,
     356,   357,    75,    76,    77,    58,   358,    94,    95,    96,
      59,   194,   195,   196,   197,   198,   199,   200,    60,    61,
     348,   349,   372,    62,    63,    64,    65,   373,    66,   374,
     189,   124,    67,   133
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -324
static const yytype_int16 yypact[] =
{
     582,    -1,  -324,   495,   555,   495,   495,   555,    -3,    -3,
    -324,  -324,   495,  -324,  -324,   495,   555,    -3,  -324,  -324,
    -324,    44,  -324,    83,   713,   495,  -324,  -324,    56,    86,
     652,  -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,    24,
    -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,
    -324,  -324,  -324,    28,   900,  -324,  -324,  -324,  -324,  -324,
    -324,    94,   882,   908,  -324,  -324,  -324,   495,  -324,   802,
    -324,  -324,   363,  -324,    73,    84,  -324,  -324,    32,    -3,
     584,   584,    73,    72,    72,   584,   515,    73,   107,   507,
      51,   908,   137,   160,    60,  -324,  -324,    31,   242,   835,
      -3,   686,    41,   105,   591,   127,   147,   155,  -324,  -324,
    -324,  -324,  -324,   555,   555,   495,   555,   555,  -324,   495,
     495,   495,  -324,   210,   495,   106,   448,  -324,  -324,  -324,
    -324,   448,  -324,   448,   507,   507,   507,   507,   507,  -324,
      -3,   180,    84,   172,   210,   363,   448,  -324,   495,    72,
      72,   210,   107,   107,    72,    72,   210,   495,  -324,   507,
     391,  -324,  -324,   495,  -324,  -324,   175,    31,   148,  -324,
    -324,  -324,   -12,  -324,  -324,  -324,   183,   242,   156,  -324,
    -324,  -324,    63,  -324,  -324,  -324,  -324,  -324,   902,  -324,
     178,   188,    83,   844,   162,  -324,   929,  -324,  -324,  -324,
    -324,   901,   187,   844,   241,  -324,   182,  -324,  -324,  -324,
    -324,  -324,  -324,  -324,  -324,  -324,  -324,   686,   285,  -324,
    -324,   186,    77,  -324,  -324,    42,   219,  -324,   222,  -324,
     233,   223,   212,  -324,  -324,  -324,    73,   281,   591,   288,
      73,   211,   116,   232,   495,   299,  -324,   857,  -324,  -324,
    -324,   274,   274,  -324,  -324,  -324,  -324,   688,   107,  -324,
     299,  -324,  -324,   591,   180,   180,   299,  -324,  -324,   180,
     180,   299,   591,  -324,   908,  -324,   763,   779,   262,   282,
     287,   294,   300,  -324,    47,   714,    48,   779,   277,   306,
     317,   318,   324,   325,  -324,   242,   818,   431,   212,   212,
     212,   212,   212,   212,   199,   212,    85,   881,   334,    -4,
    -324,   835,   844,   844,   844,   844,   448,   448,   448,   844,
    -324,  -324,    -3,   448,   295,   335,  -324,   686,   686,   344,
    -324,    49,   348,   349,   -16,  -324,    41,   818,   411,   212,
     719,   210,   507,   507,   210,   591,    72,  -324,   -10,  -324,
    -324,    83,   688,  -324,   935,  -324,  -324,  -324,  -324,  -324,
     688,  -324,    72,   366,   366,    72,   366,   107,    72,  -324,
    -324,  -324,    -9,  -324,   902,  -324,  -324,  -324,  -324,    59,
    -324,   110,  -324,  -324,   753,  -324,  -324,  -324,  -324,  -324,
     357,   418,  -324,    12,  -324,  -324,  -324,  -324,  -324,   277,
     779,  -324,   594,  -324,   926,   283,   283,  -324,  -324,  -324,
    -324,  -324,  -324,   292,   844,  -324,  -324,   360,   261,   130,
     232,  -324,  -324,  -324,  -324,   929,  -324,  -324,  -324,   295,
    -324,  -324,   422,   349,  -324,  -324,  -324,  -324,  -324,  -324,
    -324,   926,  -324,    72,   229,   229,   180,   180,  -324,   448,
      92,   935,   365,   371,   688,   688,   688,   688,  -324,   180,
     688,   107,   107,   180,   107,  -324,   180,  -324,   779,    59,
     287,   435,   779,   381,   385,   779,   300,  -324,   385,   324,
     866,   -16,   180,   210,   210,   107,   366,  -324,   688,  -324,
    -324,   364,   163,   232,  -324,   366,  -324,   935,  -324,  -324,
     366,  -324,   366,  -324,   378,   397,  -324,   403,  -324,  -324,
     404,  -324,   107,    72,    72,  -324,   107,   875,   107,   107,
     107,   779,   416,  -324,  -324,   180,   180,  -324,  -324,  -324,
    -324,  -324,    34,   435,   107,   107,  -324,  -324,  -324,  -324
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -324,  -324,  -324,   443,  -324,   307,   312,   208,  -153,    25,
     -74,   213,  -161,   -37,  -324,   113,  -324,  -324,  -144,   326,
    -324,   345,  -324,   347,   204,  -166,  -324,  -324,   207,  -324,
    -173,   313,  -324,  -324,  -256,   100,   -77,  -324,  -259,  -324,
     166,   316,  -324,  -213,  -324,  -209,  -324,   -69,  -117,    -5,
     -81,    80,  -323,  -132,  -324,  -324,  -324,  -324,  -324,  -324,
    -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,
      71,   413,   506,  -324,   513,  -324,  -324,  -324,  -310,   190,
    -324,   192,   -36,   473,  -324,  -324,  -324,  -160,   -93,   -90,
    -324,   239,  -324,  -114,  -324,  -324,   367,  -324,    21,  -324,
    -324,   108,  -278,   202,    -6,   -17,  -324,   -76,   -28,   109,
    -146,   -27,     3,   362
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -229
static const yytype_int16 yytable[] =
{
     108,   164,   152,   153,   165,   144,   282,    79,   107,   393,
      79,   292,   333,   151,   280,    91,   334,   155,   156,    79,
     267,   268,   186,   173,   221,    78,   390,   260,    78,    83,
      84,   293,   306,   288,   266,   166,   142,    78,    88,   271,
     401,   462,   451,   464,   324,   224,   224,     2,   145,   436,
     458,   166,   166,   224,     2,   448,   467,    22,   285,     2,
     338,   235,   108,   166,   286,    68,   449,   468,   264,   265,
     187,   319,   107,   269,   270,    79,   150,   477,    82,   307,
     154,   438,   202,   160,    10,    11,   109,    87,   468,   320,
     111,    10,    11,    78,   112,   167,    10,    11,   125,   536,
     147,   186,   203,    21,    22,   225,   331,   115,    89,   261,
     468,   379,   391,   432,   146,   145,    79,    79,   433,    79,
      79,   206,   334,   469,   140,   390,   361,   163,   251,   252,
     253,   254,   255,   296,    78,    78,    90,    78,    78,   297,
     221,   161,   107,    90,   491,   492,   493,   494,    79,   187,
     497,   399,   414,   274,   429,   430,   471,    92,    93,   488,
     118,   256,   157,   516,   162,   122,    78,   341,   329,   315,
     247,   344,   518,   330,   472,   232,   309,   519,   517,   520,
      92,    93,    92,    93,   236,   237,   202,   239,   240,    92,
      93,   450,   233,   293,   120,   121,   203,   122,   418,   419,
     420,   421,   410,   411,   187,   425,   203,   188,   313,   314,
     173,   122,   234,   164,   283,     2,   165,   284,   282,   186,
     235,   186,   294,   481,   443,   295,   470,   446,   310,   412,
     476,   311,   244,   257,   145,   465,   479,   259,   293,   277,
     346,   455,   456,   532,   122,     2,   176,   287,   304,   187,
     221,   221,    10,    11,   293,   362,   293,   187,   305,   187,
     360,   365,   319,   115,   323,   447,   368,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   339,   413,   359,   328,
     315,   459,    10,    11,   463,   335,   188,   466,   119,   120,
     121,   336,   122,   315,   202,   202,   202,   202,   202,   338,
     480,   201,   202,   337,    90,   342,   177,   321,   282,   187,
     322,   187,   343,   122,   203,   203,   203,   203,   203,   148,
     134,   135,   203,   136,   137,   138,   186,   457,   248,   498,
     499,   284,   501,   249,    90,   250,   444,   445,   312,   313,
     314,   340,   122,   206,   363,   364,   295,   375,   262,   366,
     367,   326,   376,   515,   327,   360,   187,   164,  -206,   377,
     165,  -206,   482,   360,   327,   378,   513,   514,   136,   137,
     138,   394,   187,   359,   187,   483,   484,   301,   302,   303,
     524,   359,   395,   396,   527,   389,   529,   530,   531,   397,
     398,   315,   315,   315,   315,   201,   389,   202,   315,   416,
     428,   431,   538,   539,   188,   201,   188,   404,   405,   406,
     407,   408,   409,   434,   435,   440,    69,   203,    80,    81,
     460,   475,   166,    22,   457,    85,   224,    72,    86,   311,
     489,   457,   525,   526,     2,   176,   490,   389,   104,   505,
     187,   454,   455,   456,   187,   122,   508,   187,   441,   350,
     509,     2,    27,   315,   286,    73,   275,   360,   360,   360,
     360,   521,   533,   360,   457,   457,   457,   457,   522,   523,
     457,    10,    11,   110,   278,   359,   359,   359,   359,   279,
     139,   359,   134,   135,   474,   136,   137,   138,    10,    11,
     457,   360,   380,   187,   504,   402,   537,   473,     2,   392,
     478,   403,   437,   289,    18,    19,    20,    21,    22,   359,
       2,   188,   159,   201,   201,   201,   201,   201,   422,   423,
     424,   201,   290,    90,   291,   427,   485,   486,   238,   426,
     325,   105,   241,   242,   243,    10,    11,   246,   106,   495,
      90,   332,   452,   500,   453,   143,   502,    10,    11,   115,
     417,    18,    19,    20,    21,    22,    23,   487,     0,    25,
     308,   263,   512,   318,     0,     0,    21,    22,   503,     0,
     272,   159,   507,     0,     0,   510,   276,     0,     0,     0,
       0,     0,    -2,     1,    27,     2,  -228,    28,     0,     0,
       0,   118,   119,   120,   121,     0,   122,     2,   176,    90,
       0,     0,     0,     3,   148,   534,   535,     4,     0,     5,
       6,    70,     7,    71,     8,    22,   201,     0,     9,    72,
       0,     0,    10,    11,    12,    13,    14,    15,     0,    16,
      17,     0,     0,     0,    10,    11,     0,     0,    18,    19,
      20,    21,    22,    23,    27,    24,    25,    73,     0,     0,
      26,   350,    -3,     1,     0,     2,  -228,   345,   339,     0,
     118,   119,   120,   121,     0,   122,     0,   118,   119,   120,
     121,    27,   122,     3,    28,     0,     0,     4,     0,     5,
       6,     0,     7,     0,     8,     0,    90,     0,     9,     0,
     207,     0,    10,    11,    12,    13,    14,    15,     0,    16,
      17,     0,   208,   209,   210,   211,     0,     0,    18,    19,
      20,    21,    22,    23,     0,    24,    25,     2,   207,   212,
      26,    97,     0,   213,    98,    99,   100,   101,   102,     0,
     208,   209,   210,   211,   214,   215,   216,   381,     0,     0,
       0,    27,     0,     0,    28,   382,     0,   212,    22,   351,
     217,   213,   352,   103,    10,    11,     2,   207,     0,     0,
       0,     0,   214,   215,   216,   383,     0,     0,     0,   208,
     209,   210,   211,     0,     0,     0,   381,    27,   384,     0,
      73,     0,     2,   207,   382,   442,   212,     0,     0,     0,
     213,     0,     0,    10,    11,   208,   209,   210,   211,     0,
       0,   214,   215,   216,   383,     0,    90,     0,     0,     0,
     299,   300,   212,   301,   302,   303,   213,   400,     0,    10,
      11,     2,   207,     0,     0,   369,     0,   214,   215,   216,
       0,     0,     0,     0,   208,   209,   210,   211,     2,   118,
     119,   120,   121,   339,   122,    90,     0,     2,     0,     0,
       0,   212,     0,     0,   140,   213,     0,     0,    10,    11,
       2,     0,     0,     0,     0,     0,   214,   215,   216,     0,
       0,    90,     0,   190,     0,    10,   191,     0,   118,   119,
     120,   121,   400,   122,    10,    11,     0,     0,     0,     0,
       0,    18,    19,    20,    21,    22,   192,    10,    11,   193,
      18,    19,    20,    21,    22,   192,     0,     0,   193,     0,
      90,     0,     0,    18,    19,    20,    21,    22,     0,     0,
       0,   159,   347,     0,    27,     0,   113,    28,   511,   114,
       0,     0,     0,    27,   115,   116,    28,   528,     0,   117,
       0,     0,   118,   312,   313,   314,   415,   122,     0,    90,
       0,   118,   454,   455,   456,     0,   122,   118,   312,   313,
     314,     0,   122,     0,   126,   127,   128,   129,   130,   131,
     132,     0,     0,     0,     0,     0,   118,   119,   120,   121,
       0,   122,     0,   316,   127,   128,   129,   130,   317,   132,
       0,     0,   298,   299,   300,     0,   301,   302,   303,   134,
     135,     0,   136,   137,   138,   118,   312,   313,   314,     0,
     122,   118,   454,   455,   456,     0,   122,   299,   300,     0,
     301,   302,   303
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-324))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      28,    94,    83,    84,    94,    74,   167,     4,    25,   287,
       7,   177,   225,    82,   167,    21,   225,    86,    87,    16,
     152,   153,    98,    97,   101,     4,   285,   144,     7,     8,
       9,   177,   192,   177,   151,     4,    72,    16,    17,   156,
     296,   364,   352,   366,   217,     4,     4,     3,    75,    65,
     360,     4,     4,     4,     3,    65,    65,    60,    70,     3,
      76,    65,    90,     4,    76,    66,    76,    76,   149,   150,
      98,    75,    89,   154,   155,    72,    81,    65,     7,   193,
      85,   337,    99,    89,    40,    41,     0,    16,    76,   203,
      66,    40,    41,    72,    66,    64,    40,    41,     4,    65,
      79,   177,    99,    59,    60,    64,    64,    34,    64,   145,
      76,    64,    64,    64,    82,   142,   113,   114,   331,   116,
     117,   100,   331,    64,    52,   384,   258,    67,   134,   135,
     136,   137,   138,    70,   113,   114,    92,   116,   117,    76,
     217,     4,   159,    92,   454,   455,   456,   457,   145,   177,
     460,   295,    67,   159,   327,   328,    46,    97,    98,    67,
      76,   140,    55,   486,     4,    81,   145,   236,    91,   196,
      64,   240,   495,    96,    64,    70,   193,   500,   488,   502,
      97,    98,    97,    98,   113,   114,   203,   116,   117,    97,
      98,   351,    65,   339,    78,    79,   193,    81,   312,   313,
     314,   315,     3,     4,   232,   319,   203,    98,    78,    79,
     284,    81,    65,   306,    66,     3,   306,    69,   379,   295,
      65,   297,    66,   432,   341,    69,   379,   344,    66,   305,
     391,    69,    22,    53,   261,   367,   402,    65,   384,    64,
     245,    78,    79,   521,    81,     3,     4,    64,    70,   277,
     327,   328,    40,    41,   400,   260,   402,   285,    70,   287,
     257,   266,    75,    34,    82,   346,   271,   295,   296,   297,
     298,   299,   300,   301,   302,   303,    64,   305,   257,    93,
     307,   362,    40,    41,   365,    66,   177,   368,    77,    78,
      79,    69,    81,   320,   311,   312,   313,   314,   315,    76,
     414,    99,   319,    70,    92,    24,    64,    66,   469,   337,
      69,   339,    24,    81,   311,   312,   313,   314,   315,    20,
      91,    92,   319,    94,    95,    96,   402,   354,   126,   461,
     462,    69,   464,   131,    92,   133,   342,   343,    77,    78,
      79,   232,    81,   322,   264,   265,    69,    65,   146,   269,
     270,    66,    65,   485,    69,   352,   384,   450,    66,    65,
     450,    69,   443,   360,    69,    65,   483,   484,    94,    95,
      96,    65,   400,   352,   402,   444,   445,    94,    95,    96,
     512,   360,    65,    65,   516,   285,   518,   519,   520,    65,
      65,   418,   419,   420,   421,   193,   296,   414,   425,    65,
      65,    57,   534,   535,   295,   203,   297,   298,   299,   300,
     301,   302,   303,    65,    65,     4,     3,   414,     5,     6,
      54,    64,     4,    60,   451,    12,     4,    64,    15,    69,
      65,   458,   513,   514,     3,     4,    65,   337,    25,     4,
     468,    77,    78,    79,   472,    81,    65,   475,   339,   247,
      65,     3,    89,   480,    76,    92,    65,   454,   455,   456,
     457,    64,    46,   460,   491,   492,   493,   494,    65,    65,
     497,    40,    41,    30,   167,   454,   455,   456,   457,   167,
      67,   460,    91,    92,   384,    94,    95,    96,    40,    41,
     517,   488,   284,   521,   469,    64,   533,   384,     3,   286,
     400,   297,   336,   177,    56,    57,    58,    59,    60,   488,
       3,   402,    64,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   177,    92,   177,   323,   446,   447,   115,   322,
     217,    25,   119,   120,   121,    40,    41,   124,    25,   459,
      92,   225,   352,   463,   352,    72,   466,    40,    41,    34,
     311,    56,    57,    58,    59,    60,    61,   449,    -1,    64,
     193,   148,   482,   201,    -1,    -1,    59,    60,   468,    -1,
     157,    64,   472,    -1,    -1,   475,   163,    -1,    -1,    -1,
      -1,    -1,     0,     1,    89,     3,     4,    92,    -1,    -1,
      -1,    76,    77,    78,    79,    -1,    81,     3,     4,    92,
      -1,    -1,    -1,    21,    20,   525,   526,    25,    -1,    27,
      28,    56,    30,    58,    32,    60,   414,    -1,    36,    64,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    -1,    -1,    -1,    40,    41,    -1,    -1,    56,    57,
      58,    59,    60,    61,    89,    63,    64,    92,    -1,    -1,
      68,   449,     0,     1,    -1,     3,     4,   244,    64,    -1,
      76,    77,    78,    79,    -1,    81,    -1,    76,    77,    78,
      79,    89,    81,    21,    92,    -1,    -1,    25,    -1,    27,
      28,    -1,    30,    -1,    32,    -1,    92,    -1,    36,    -1,
       4,    -1,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    -1,    16,    17,    18,    19,    -1,    -1,    56,    57,
      58,    59,    60,    61,    -1,    63,    64,     3,     4,    33,
      68,     8,    -1,    37,    11,    12,    13,    14,    15,    -1,
      16,    17,    18,    19,    48,    49,    50,    23,    -1,    -1,
      -1,    89,    -1,    -1,    92,    31,    -1,    33,    60,    61,
      64,    37,    64,    40,    40,    41,     3,     4,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    -1,    -1,    -1,    16,
      17,    18,    19,    -1,    -1,    -1,    23,    89,    64,    -1,
      92,    -1,     3,     4,    31,    66,    33,    -1,    -1,    -1,
      37,    -1,    -1,    40,    41,    16,    17,    18,    19,    -1,
      -1,    48,    49,    50,    51,    -1,    92,    -1,    -1,    -1,
      91,    92,    33,    94,    95,    96,    37,    64,    -1,    40,
      41,     3,     4,    -1,    -1,    62,    -1,    48,    49,    50,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,     3,    76,
      77,    78,    79,    64,    81,    92,    -1,     3,    -1,    -1,
      -1,    33,    -1,    -1,    52,    37,    -1,    -1,    40,    41,
       3,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    92,    -1,    38,    -1,    40,    41,    -1,    76,    77,
      78,    79,    64,    81,    40,    41,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    40,    41,    64,
      56,    57,    58,    59,    60,    61,    -1,    -1,    64,    -1,
      92,    -1,    -1,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    -1,    89,    -1,    26,    92,    62,    29,
      -1,    -1,    -1,    89,    34,    35,    92,    62,    -1,    39,
      -1,    -1,    76,    77,    78,    79,    65,    81,    -1,    92,
      -1,    76,    77,    78,    79,    -1,    81,    76,    77,    78,
      79,    -1,    81,    -1,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      -1,    81,    -1,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    90,    91,    92,    -1,    94,    95,    96,    91,
      92,    -1,    94,    95,    96,    76,    77,    78,    79,    -1,
      81,    76,    77,    78,    79,    -1,    81,    91,    92,    -1,
      94,    95,    96
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    21,    25,    27,    28,    30,    32,    36,
      40,    41,    42,    43,    44,    45,    47,    48,    56,    57,
      58,    59,    60,    61,    63,    64,    68,    89,    92,   102,
     103,   104,   105,   117,   118,   127,   130,   140,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   172,   173,   174,   175,   186,   191,
     199,   200,   204,   205,   206,   207,   209,   213,    66,   172,
      56,    58,    64,    92,   171,   183,   184,   185,   199,   213,
     172,   172,   171,   199,   199,   172,   172,   171,   199,    64,
      92,   205,    97,    98,   188,   189,   190,     8,    11,    12,
      13,    14,    15,    40,   172,   173,   175,   206,   209,     0,
     104,    66,    66,    26,    29,    34,    35,    39,    76,    77,
      78,    79,    81,   148,   212,     4,    82,    83,    84,    85,
      86,    87,    88,   214,    91,    92,    94,    95,    96,   172,
      52,   151,   183,   184,   148,   212,    82,   199,    20,   150,
     150,   148,   151,   151,   150,   148,   148,    55,   154,    64,
     205,     4,     4,    67,   189,   190,     4,    64,   106,   107,
     108,   109,   110,   111,   112,   113,     4,    64,   119,   120,
     121,   122,   123,   124,   125,   126,   208,   209,   210,   211,
      38,    41,    61,    64,   192,   193,   194,   195,   196,   197,
     198,   204,   206,   213,   128,   129,   199,     4,    16,    17,
      18,    19,    33,    37,    48,    49,    50,    64,   131,   132,
     133,   137,   138,   139,     4,    64,   141,   142,   143,   144,
     145,   146,    70,    65,    65,    65,   171,   171,   172,   171,
     171,   172,   172,   172,    22,   149,   172,    64,   204,   204,
     204,   205,   205,   205,   205,   205,   199,    53,   152,    65,
     149,   183,   204,   172,   151,   151,   149,   154,   154,   151,
     151,   149,   172,   176,   205,    65,   172,    64,   106,   107,
     109,   111,   113,    66,    69,    70,    76,    64,   119,   120,
     122,   124,   126,   211,    66,    69,    70,    76,    90,    91,
      92,    94,    95,    96,    70,    70,   188,   194,   197,   206,
      66,    69,    77,    78,    79,   212,    82,    87,   214,    75,
     194,    66,    69,    82,   131,   132,    66,    69,    93,    91,
      96,    64,   142,   144,   146,    66,    69,    70,    76,    64,
     210,   148,    24,    24,   148,   172,   150,    65,   201,   202,
     204,    61,    64,   177,   179,   180,   181,   182,   187,   199,
     213,   154,   150,   152,   152,   150,   152,   152,   150,    62,
     136,   137,   203,   208,   210,    65,    65,    65,    65,    64,
     108,    23,    31,    51,    64,   115,   116,   134,   135,   136,
     139,    64,   112,   203,    65,    65,    65,    65,    65,   119,
      64,   135,    64,   125,   210,   210,   210,   210,   210,   210,
       3,     4,   208,   209,    67,    65,    65,   192,   194,   194,
     194,   194,   204,   204,   204,   194,   129,   204,    65,   131,
     131,    57,    64,   144,    65,    65,    65,   141,   135,   147,
       4,   210,    66,   149,   205,   205,   149,   151,    65,    76,
     188,   179,   180,   182,    77,    78,    79,   212,   179,   151,
      54,   153,   153,   151,   153,   154,   151,    65,    76,    64,
     109,    46,    64,   116,   136,    64,   113,    65,   136,   126,
     194,   146,   151,   148,   148,   152,   152,   202,    67,    65,
      65,   179,   179,   179,   179,   152,   178,   179,   154,   154,
     152,   154,   152,   136,   110,     4,   114,   136,    65,    65,
     136,    62,   152,   149,   149,   154,   153,   179,   153,   153,
     153,    64,    65,    65,   154,   151,   151,   154,    62,   154,
     154,   154,   203,    46,   152,   152,    65,   114,   154,   154
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
#line 455 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2215 "parser.cc"
	break;
      case 5: /* "T_STRING" */

/* Line 1391 of yacc.c  */
#line 455 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2224 "parser.cc"
	break;
      case 110: /* "constant_schema_outer_list" */

/* Line 1391 of yacc.c  */
#line 463 "parser.yy"
	{ if((yyvaluep->l_constant) != NULL) { deallocateList((yyvaluep->l_constant)); } };

/* Line 1391 of yacc.c  */
#line 2233 "parser.cc"
	break;
      case 111: /* "constant_schema_list" */

/* Line 1391 of yacc.c  */
#line 463 "parser.yy"
	{ if((yyvaluep->l_constant) != NULL) { deallocateList((yyvaluep->l_constant)); } };

/* Line 1391 of yacc.c  */
#line 2242 "parser.cc"
	break;
      case 112: /* "constant_outer_schema" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->constant); };

/* Line 1391 of yacc.c  */
#line 2251 "parser.cc"
	break;
      case 113: /* "constant_schema" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->constant); };

/* Line 1391 of yacc.c  */
#line 2260 "parser.cc"
	break;
      case 114: /* "constant_schema_nodecl" */

/* Line 1391 of yacc.c  */
#line 457 "parser.yy"
	{ delete (yyvaluep->constant); };

/* Line 1391 of yacc.c  */
#line 2269 "parser.cc"
	break;
      case 115: /* "constant_outer_binder" */

/* Line 1391 of yacc.c  */
#line 467 "parser.yy"
	{ if((yyvaluep->constant_binder_t) != NULL) { deallocateItem((yyvaluep->constant_binder_t)); } };

/* Line 1391 of yacc.c  */
#line 2278 "parser.cc"
	break;
      case 116: /* "constant_binder" */

/* Line 1391 of yacc.c  */
#line 467 "parser.yy"
	{ if((yyvaluep->constant_binder_t) != NULL) { deallocateItem((yyvaluep->constant_binder_t)); } };

/* Line 1391 of yacc.c  */
#line 2287 "parser.cc"
	break;
      case 123: /* "object_outer_schema_list" */

/* Line 1391 of yacc.c  */
#line 464 "parser.yy"
	{ if((yyvaluep->l_object) != NULL) { deallocateList((yyvaluep->l_object)); } };

/* Line 1391 of yacc.c  */
#line 2296 "parser.cc"
	break;
      case 124: /* "object_schema_list" */

/* Line 1391 of yacc.c  */
#line 464 "parser.yy"
	{ if((yyvaluep->l_object) != NULL) { deallocateList((yyvaluep->l_object)); } };

/* Line 1391 of yacc.c  */
#line 2305 "parser.cc"
	break;
      case 125: /* "object_outer_schema" */

/* Line 1391 of yacc.c  */
#line 459 "parser.yy"
	{ delete (yyvaluep->object); };

/* Line 1391 of yacc.c  */
#line 2314 "parser.cc"
	break;
      case 126: /* "object_schema" */

/* Line 1391 of yacc.c  */
#line 459 "parser.yy"
	{ delete (yyvaluep->object); };

/* Line 1391 of yacc.c  */
#line 2323 "parser.cc"
	break;
      case 131: /* "sort_spec_outer_tuple" */

/* Line 1391 of yacc.c  */
#line 465 "parser.yy"
	{ if((yyvaluep->l_sort) != NULL) { deallocateList((yyvaluep->l_sort)); } };

/* Line 1391 of yacc.c  */
#line 2332 "parser.cc"
	break;
      case 132: /* "sort_spec_tuple" */

/* Line 1391 of yacc.c  */
#line 465 "parser.yy"
	{ if((yyvaluep->l_sort) != NULL) { deallocateList((yyvaluep->l_sort)); } };

/* Line 1391 of yacc.c  */
#line 2341 "parser.cc"
	break;
      case 133: /* "sort_spec" */

/* Line 1391 of yacc.c  */
#line 461 "parser.yy"
	{ delete (yyvaluep->sort); };

/* Line 1391 of yacc.c  */
#line 2350 "parser.cc"
	break;
      case 134: /* "sort_identifier_with_ab" */

/* Line 1391 of yacc.c  */
#line 455 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2359 "parser.cc"
	break;
      case 135: /* "sort_outer_identifier" */

/* Line 1391 of yacc.c  */
#line 455 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2368 "parser.cc"
	break;
      case 136: /* "sort_identifier" */

/* Line 1391 of yacc.c  */
#line 455 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2377 "parser.cc"
	break;
      case 137: /* "sort_identifier_no_range" */

/* Line 1391 of yacc.c  */
#line 455 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2386 "parser.cc"
	break;
      case 138: /* "sort_identifier_name" */

/* Line 1391 of yacc.c  */
#line 455 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2395 "parser.cc"
	break;
      case 139: /* "sort_constant_name" */

/* Line 1391 of yacc.c  */
#line 455 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2404 "parser.cc"
	break;
      case 145: /* "variable_outer_list" */

/* Line 1391 of yacc.c  */
#line 466 "parser.yy"
	{ if((yyvaluep->l_variable) != NULL) { deallocateList((yyvaluep->l_variable)); } };

/* Line 1391 of yacc.c  */
#line 2413 "parser.cc"
	break;
      case 146: /* "variable_list" */

/* Line 1391 of yacc.c  */
#line 466 "parser.yy"
	{ if((yyvaluep->l_variable) != NULL) { deallocateList((yyvaluep->l_variable)); } };

/* Line 1391 of yacc.c  */
#line 2422 "parser.cc"
	break;
      case 147: /* "variable_binding" */

/* Line 1391 of yacc.c  */
#line 461 "parser.yy"
	{ delete (yyvaluep->sort); };

/* Line 1391 of yacc.c  */
#line 2431 "parser.cc"
	break;
      case 200: /* "lua_indicator" */

/* Line 1391 of yacc.c  */
#line 455 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2440 "parser.cc"
	break;
      case 203: /* "sort_identifier_list" */

/* Line 1391 of yacc.c  */
#line 465 "parser.yy"
	{ if((yyvaluep->l_sort) != NULL) { deallocateList((yyvaluep->l_sort)); } };

/* Line 1391 of yacc.c  */
#line 2449 "parser.cc"
	break;
      case 208: /* "num_range" */

/* Line 1391 of yacc.c  */
#line 458 "parser.yy"
	{ delete (yyvaluep->numRange); };

/* Line 1391 of yacc.c  */
#line 2458 "parser.cc"
	break;
      case 209: /* "extended_integer" */

/* Line 1391 of yacc.c  */
#line 455 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2467 "parser.cc"
	break;
      case 210: /* "extended_integer_outer_expression" */

/* Line 1391 of yacc.c  */
#line 455 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2476 "parser.cc"
	break;
      case 211: /* "extended_integer_expression" */

/* Line 1391 of yacc.c  */
#line 455 "parser.yy"
	{ delete (yyvaluep->str); };

/* Line 1391 of yacc.c  */
#line 2485 "parser.cc"
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
#line 471 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 473 "parser.yy"
    { 
		(yyval.not_used) = PARSERULE_NOT_USED; 

		// Ensure that we append the footer
		// after the program has finished translating
		mainTrans.outputFooter();
		
}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 483 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 484 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 487 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 488 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 489 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 490 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 491 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 492 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 493 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 494 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 496 "parser.yy"
    { 
	(yyval.not_used) = PARSERULE_NOT_USED;
	/* On an error, go to the end of the bad statement and try to continue.
       Set the error handler to not wait to report syntax errors if more show up. */
	yyerrok;
}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 501 "parser.yy"
    {(yyval.not_used) = PARSERULE_NOT_USED;}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 509 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 512 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 513 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 516 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 517 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 520 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 521 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 525 "parser.yy"
    {
	// Fill in each Constant's type and domain and translate each of them.
	bool constantError = true; // Set to true if any of the constants have trouble getting added to the symbol table.
	Sort* tempSort = NULL;

	// double check that this is a valid constant type for the language we're working in.
	// TODO: This is where you would add other language constnat type checks.

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
			// bc uses only exogenous actions.
			(yyvsp[(3) - (3)].constant_binder_t)->constType = Constant::CONST_EXOGENOUSACTION;
			break;
		case Constant::CONST_EXOGENOUSACTION:
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
#line 653 "parser.yy"
    {
	(yyval.l_constant) = (yyvsp[(1) - (1)].l_constant);
}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 657 "parser.yy"
    {
	(yyval.l_constant) = (yyvsp[(2) - (3)].l_constant);
}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 663 "parser.yy"
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
#line 672 "parser.yy"
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
#line 696 "parser.yy"
    {
	(yyval.constant) = (yyvsp[(1) - (1)].constant);
}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 700 "parser.yy"
    {
	(yyval.constant) = (yyvsp[(2) - (3)].constant);
}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 706 "parser.yy"
    {
	// Create a new Constant from a bare identifier.
	(yyval.constant) = new Constant(*(yyvsp[(1) - (1)].str), Constant::CONST_UNKNOWN, false);
	deallocateItem((yyvsp[(1) - (1)].str));
}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 712 "parser.yy"
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
#line 726 "parser.yy"
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
#line 736 "parser.yy"
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
#line 752 "parser.yy"
    {
	(yyval.constant_binder_t) = (yyvsp[(1) - (1)].constant_binder_t);
}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 756 "parser.yy"
    {
	(yyval.constant_binder_t) = (yyvsp[(2) - (3)].constant_binder_t);
}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 762 "parser.yy"
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
#line 800 "parser.yy"
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
#line 823 "parser.yy"
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
#line 839 "parser.yy"
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
#line 911 "parser.yy"
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
#line 927 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 930 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 931 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 934 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 935 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 938 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 939 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 943 "parser.yy"
    {
	// Connect each Object in the list to its sort, (try to) add them to the symbol table, and translate each object.

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

	(yyval.not_used) = PARSERULE_NOT_USED;
	deallocateList((yyvsp[(1) - (3)].l_object));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 993 "parser.yy"
    {
	(yyval.l_object) = (yyvsp[(1) - (1)].l_object);
}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 997 "parser.yy"
    {
	(yyval.l_object) = (yyvsp[(2) - (3)].l_object);
}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 1003 "parser.yy"
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
#line 1013 "parser.yy"
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
#line 1037 "parser.yy"
    {
	(yyval.object) = (yyvsp[(1) - (1)].object);
}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 1041 "parser.yy"
    {
	(yyval.object) = (yyvsp[(2) - (3)].object);
}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 1047 "parser.yy"
    {
	// Create a new Object from a bare identifier.
	(yyval.object) = new Object(*(yyvsp[(1) - (1)].str), Object::OBJ_NAME, false);
	deallocateItem((yyvsp[(1) - (1)].str));
}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 1053 "parser.yy"
    {
	// Create a new Object from a parameterized identifier.
	(yyval.object) = new Object(*(yyvsp[(1) - (4)].str), Object::OBJ_NAME, false, (yyvsp[(3) - (4)].l_sort));
	deallocateList((yyvsp[(3) - (4)].l_sort));
	deallocateItem((yyvsp[(1) - (4)].str));
}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 1060 "parser.yy"
    {
	// Create a new object from arbitrary math.
	(yyval.object) = new Object(*(yyvsp[(1) - (1)].str), Object::OBJ_NAME, true);
	deallocateItem((yyvsp[(1) - (1)].str)); // Free dynamic memory that's not needed anymore.
}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 1066 "parser.yy"
    {
	// Upcast a NumberRange into an Object.
	(yyval.object) = (Object*)(yyvsp[(1) - (1)].numRange);
}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 1075 "parser.yy"
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
#line 1088 "parser.yy"
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
#line 1098 "parser.yy"
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
#line 1112 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 1116 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 1130 "parser.yy"
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
#line 1141 "parser.yy"
    {
	(yyval.l_sort) = (yyvsp[(1) - (1)].l_sort);
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 1145 "parser.yy"
    {
	(yyval.l_sort) = (yyvsp[(2) - (3)].l_sort);
}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 1151 "parser.yy"
    {
	(yyval.l_sort) = new SortList();
	(yyval.l_sort)->push_back((yyvsp[(1) - (1)].sort));
}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 1156 "parser.yy"
    {
	(yyval.l_sort) = NULL;
	if((yyvsp[(1) - (3)].l_sort) != NULL || (yyvsp[(3) - (3)].l_sort) != NULL)
	{
		(yyval.l_sort) = new  SortList();
	}
	// Merge the two sort lists, if they exist.
	if((yyvsp[(1) - (3)].l_sort) != NULL)
	{
		for(SortList::iterator lIter = (yyvsp[(1) - (3)].l_sort)->begin(); lIter != (yyvsp[(1) - (3)].l_sort)->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				(yyval.l_sort)->push_back((*lIter));
			}
		}
		deallocateList((yyvsp[(1) - (3)].l_sort));
	}
	if((yyvsp[(3) - (3)].l_sort) != NULL)
	{
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
#line 1189 "parser.yy"
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

  case 70:

/* Line 1806 of yacc.c  */
#line 1199 "parser.yy"
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

  case 71:

/* Line 1806 of yacc.c  */
#line 1212 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 1216 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("staticAbnormality");
}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1221 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("dynamicAbnormality");
}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1228 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1232 "parser.yy"
    {
	(yyval.str) = (yyvsp[(2) - (3)].str);
}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 1240 "parser.yy"
    {
	// A standard identifier.
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1245 "parser.yy"
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

  case 78:

/* Line 1806 of yacc.c  */
#line 1323 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1327 "parser.yy"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = (*(yyvsp[(1) - (2)].str)) + "*";
	deallocateItem((yyvsp[(1) - (2)].str));
}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 1333 "parser.yy"
    {
	// Alternate way to express the idea of a starred sort.
	(yyval.str) = new std::string;
	(*(yyval.str)) = (*(yyvsp[(1) - (3)].str)) + "*";
	deallocateItem((yyvsp[(1) - (3)].str));
}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 1342 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1346 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1352 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("abAction");
}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 1357 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("action");
}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1362 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("additiveAction");
}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1367 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("additiveFluent");
}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1372 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("exogenousAction");
}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1377 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("inertialFluent");
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1382 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("rigid");
}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1387 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("sdFluent");
}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1392 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("simpleFluent");
}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1400 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1403 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1404 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1407 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1408 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1411 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1412 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1416 "parser.yy"
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

  case 100:

/* Line 1806 of yacc.c  */
#line 1451 "parser.yy"
    {
	(yyval.l_variable) = (yyvsp[(1) - (1)].l_variable);
}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 1455 "parser.yy"
    {
	(yyval.l_variable) = (yyvsp[(2) - (3)].l_variable);
}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 1461 "parser.yy"
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

  case 103:

/* Line 1806 of yacc.c  */
#line 1474 "parser.yy"
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

  case 104:

/* Line 1806 of yacc.c  */
#line 1492 "parser.yy"
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

  case 105:

/* Line 1806 of yacc.c  */
#line 1546 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 1547 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1550 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 1551 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1554 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 1555 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 1558 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1559 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 1562 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1563 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1566 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 1567 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1570 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 1571 "parser.yy"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 1577 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 1578 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 1581 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 1582 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1583 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1584 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1585 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1586 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 1587 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 1588 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 1589 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 1590 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 1591 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 1592 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 1593 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 1598 "parser.yy"
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

  case 135:

/* Line 1806 of yacc.c  */
#line 1613 "parser.yy"
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

  case 136:

/* Line 1806 of yacc.c  */
#line 1628 "parser.yy"
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

  case 137:

/* Line 1806 of yacc.c  */
#line 1643 "parser.yy"
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
#line 1660 "parser.yy"
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

  case 139:

/* Line 1806 of yacc.c  */
#line 1680 "parser.yy"
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

  case 140:

/* Line 1806 of yacc.c  */
#line 1694 "parser.yy"
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

  case 141:

/* Line 1806 of yacc.c  */
#line 1708 "parser.yy"
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

  case 142:

/* Line 1806 of yacc.c  */
#line 1724 "parser.yy"
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

  case 143:

/* Line 1806 of yacc.c  */
#line 1745 "parser.yy"
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

  case 144:

/* Line 1806 of yacc.c  */
#line 1764 "parser.yy"
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

  case 145:

/* Line 1806 of yacc.c  */
#line 1781 "parser.yy"
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

  case 146:

/* Line 1806 of yacc.c  */
#line 1799 "parser.yy"
    {
	// This one's easy, it's just a pass-through.
	mainTrans.output("noconcurrency.", IPART_BASE, true);
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1805 "parser.yy"
    {
	// This one is also very easy.
	mainTrans.output("strong_noconcurrency.", IPART_BASE, true);
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1813 "parser.yy"
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

  case 149:

/* Line 1806 of yacc.c  */
#line 1831 "parser.yy"
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

  case 150:

/* Line 1806 of yacc.c  */
#line 1851 "parser.yy"
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

  case 151:

/* Line 1806 of yacc.c  */
#line 1870 "parser.yy"
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

  case 152:

/* Line 1806 of yacc.c  */
#line 1885 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1889 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("true", mainTrans.getOrCreateObject("true"));
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1893 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("false", mainTrans.getOrCreateObject("false"));
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1899 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1903 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1913 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1917 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1921 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_AND, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1925 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_OR, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1929 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQUIV, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1933 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_IMPL, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1939 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1943 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1953 "parser.yy"
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

  case 166:

/* Line 1806 of yacc.c  */
#line 1972 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQ, (yyvsp[(3) - (3)].parseElement));

}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1977 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_NEQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1981 "parser.yy"
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

  case 169:

/* Line 1806 of yacc.c  */
#line 2008 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 2014 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 2020 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 2026 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 2032 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 2036 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 2046 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 2050 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 2054 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_AND, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 2058 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_OR, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 2062 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQUIV, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 2066 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_IMPL, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 2072 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 2076 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 2086 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
	if((yyval.parseElement) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 2094 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 2100 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 2104 "parser.yy"
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
#line 2114 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 2118 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_AND, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 2124 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 2128 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 2132 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 2138 "parser.yy"
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

  case 193:

/* Line 1806 of yacc.c  */
#line 2155 "parser.yy"
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

  case 194:

/* Line 1806 of yacc.c  */
#line 2170 "parser.yy"
    {
	(yyval.l_quantPair) = NULL;
	if((yyvsp[(1) - (1)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = new BigQuantifiers::QuantifierList();
		(yyval.l_quantPair)->push_back((yyvsp[(1) - (1)].p_quantPair));
	}
}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 2179 "parser.yy"
    {
	(yyval.l_quantPair) = NULL;
	if((yyvsp[(1) - (1)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = new BigQuantifiers::QuantifierList();
		(yyval.l_quantPair)->push_back((yyvsp[(1) - (1)].p_quantPair));
	}
}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 2188 "parser.yy"
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

  case 197:

/* Line 1806 of yacc.c  */
#line 2220 "parser.yy"
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

  case 198:

/* Line 1806 of yacc.c  */
#line 2254 "parser.yy"
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

  case 199:

/* Line 1806 of yacc.c  */
#line 2293 "parser.yy"
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

  case 200:

/* Line 1806 of yacc.c  */
#line 2334 "parser.yy"
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

  case 201:

/* Line 1806 of yacc.c  */
#line 2363 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 2367 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 2373 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
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
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 2389 "parser.yy"
    {

	(yyval.not_used) = PARSERULE_NOT_USED;
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
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 2406 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	if ((yyvsp[(3) - (3)].numRange)) {
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
		deallocateItem((yyvsp[(3) - (3)].numRange));
	}

}
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 2425 "parser.yy"
    {
	if ((yyvsp[(3) - (3)].str)) {
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
		deallocateItem((yyvsp[(3) - (3)].str));
	}
}
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 2443 "parser.yy"
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

  case 208:

/* Line 1806 of yacc.c  */
#line 2461 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 2465 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 2473 "parser.yy"
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

  case 211:

/* Line 1806 of yacc.c  */
#line 2493 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 2497 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 2501 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_AND, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 2505 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_OR, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 2509 "parser.yy"
    {
		(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQUIV, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 2513 "parser.yy"
    {
		(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_IMPL, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 2519 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 2523 "parser.yy"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 2533 "parser.yy"
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

  case 220:

/* Line 1806 of yacc.c  */
#line 2552 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_EQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 2556 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_NEQ, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 2560 "parser.yy"
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

  case 223:

/* Line 1806 of yacc.c  */
#line 2587 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 2593 "parser.yy"
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

  case 225:

/* Line 1806 of yacc.c  */
#line 2610 "parser.yy"
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

  case 226:

/* Line 1806 of yacc.c  */
#line 2653 "parser.yy"
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

  case 227:

/* Line 1806 of yacc.c  */
#line 2677 "parser.yy"
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

  case 228:

/* Line 1806 of yacc.c  */
#line 2721 "parser.yy"
    { (yyval.str) = NULL; }
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 2722 "parser.yy"
    { (yyval.str) = new std::string("@"); }
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 2725 "parser.yy"
    {
	(yyval.v_parseElement) = NULL;
	if((yyvsp[(1) - (1)].parseElement) != NULL)
	{
		(yyval.v_parseElement) = new ParseElementList();
		(yyval.v_parseElement)->push_back((yyvsp[(1) - (1)].parseElement));
	}
}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 2734 "parser.yy"
    {
	(yyval.v_parseElement) = NULL;
	if((yyvsp[(1) - (3)].v_parseElement) != NULL && (yyvsp[(3) - (3)].parseElement) != NULL)
	{
		(yyval.v_parseElement) = (yyvsp[(1) - (3)].v_parseElement);
		(yyval.v_parseElement)->push_back((yyvsp[(3) - (3)].parseElement));
	}
}
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 2745 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 2751 "parser.yy"
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

  case 234:

/* Line 1806 of yacc.c  */
#line 2772 "parser.yy"
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

  case 235:

/* Line 1806 of yacc.c  */
#line 2799 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("true", mainTrans.getOrCreateObject("true"));
}
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 2803 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("false", mainTrans.getOrCreateObject("false"));
}
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 2807 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("none", mainTrans.getOrCreateObject("none"));
}
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 2811 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 2817 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 2821 "parser.yy"
    {
	(yyval.parseElement) = NULL;
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
		(yyval.parseElement)->parens(true);
	}
}
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 2832 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 2836 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_PLUS, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 2840 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_MINUS, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 2844 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_TIMES, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 2848 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_DIVIDE, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 2852 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yyvsp[(1) - (3)].parseElement), SimpleBinaryOperator::BOP_MOD, (yyvsp[(3) - (3)].parseElement));
}
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 2856 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_ABS, (yyvsp[(2) - (2)].parseElement));
}
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 2860 "parser.yy"
    {
	// Not necessary to flag parenBefore and parenAfter, translation of abs
	// automatically adds parentheses around the expression.
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_ABS, (yyvsp[(3) - (4)].parseElement));
}
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 2868 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement(*(yyvsp[(1) - (1)].str), mainTrans.getOrCreateObject(*(yyvsp[(1) - (1)].str)));
	deallocateItem((yyvsp[(1) - (1)].str));
}
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 2873 "parser.yy"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
}
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 2879 "parser.yy"
    {
	(yyval.numRange) = new NumberRange(*(yyvsp[(1) - (3)].str), *(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 2887 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) = utils::to_string((yyvsp[(1) - (1)].integer));
}
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 2892 "parser.yy"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = "maxAdditive";
}
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 2897 "parser.yy"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = "maxstep";
}
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 2902 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) = "-";
	(*(yyval.str)) += (*(yyvsp[(2) - (2)].str));
	deallocateItem((yyvsp[(2) - (2)].str));
}
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 2911 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 2915 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += "(";
	(*(yyval.str)) += (*(yyvsp[(2) - (3)].str));
	(*(yyval.str)) += ")";
	deallocateItem((yyvsp[(2) - (3)].str));
}
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 2925 "parser.yy"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
}
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 2929 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " + ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 2938 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " - ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 2947 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " * ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 2956 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " // ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 2965 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " mod ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
}
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 2977 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 2981 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 2987 "parser.yy"
    {
	(yyval.integer) = T_UMINUS;
}
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 2991 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 2997 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 3001 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 3005 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 3009 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 3013 "parser.yy"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
}
    break;



/* Line 1806 of yacc.c  */
#line 6438 "parser.cc"
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
#line 3019 "parser.yy"


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

