
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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


/* Line 189 of yacc.c  */
#line 81 "parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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

/* Line 209 of yacc.c  */
#line 8 "parser.y"

#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <libgen.h>
#include <string.h>

#include "Attribute.h"
#include "ASPCode.h"
#include "Comment.h"
#include "Constant.h"
#include "Object.h"
#include "NumberRange.h"
#include "Sort.h"
#include "Variable.h"
#include "Query.h"


#include "ElementCounter.h"
#include "SymbolTable.h"
#include "Translator.h"
#include "utilities.h"

#include "parser_types.h"

#include "ltsglobals.h"



/* Line 209 of yacc.c  */
#line 138 "parser.cpp"

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
     T_GTHAN_EQ = 337,
     T_EQ_LTHAN = 338,
     T_GTHAN = 339,
     T_LTHAN = 340,
     T_NOT_EQ = 341,
     T_DBL_EQ = 342,
     T_EQ = 343,
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



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 39 "parser.y"

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
	std::list<Object*>* l_object; 					///< Pointer to a list of Object element pointers.
	std::list<Sort*>* l_sort; 						///< Pointer to a list of Sort element pointers.
	std::list<Variable*>* l_variable; 				///< Pointer to a list of Variable element pointers.
	std::vector<ParseElement*>* v_parseElement; 	///< Pointer to a list of ParseElement pointers.
	std::list<std::pair<enum BigQuantifiers::QuantifierType, 
			ParseElement*>* >* l_quantPair; 		///< List of pairs of QuantifierType enums and a associated ParseElement pointers.
	std::pair<enum BigQuantifiers::QuantifierType, 
			ParseElement*>* p_quantPair; 			///< Pair of a QuantifierType enum and an associated ParseElement pointer.
			
	/* Types specific to the parser. */
	PT_constant_binder_t* constant_binder_t; 		///< An internal type for carrying information in a particular constant declaration grammar rule up the chain.
	ParseElement* parseElement; 					///< A pointer to a class like Element, but with translation features added and more loose ties to actual declared elements.
	
	/* Used to denote a rule whose $$ we don't care about and never (de)allocate or assign to. */
	void* not_used; 								///< Used for rules whose lvalues are not used or referenced by other grammar rules.



/* Line 214 of yacc.c  */
#line 293 "parser.cpp"
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

/* Line 261 of yacc.c  */
#line 74 "parser.y"

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
 * Creates an object-like element that mirrors the contents of elem.
 * Used when a constant needs to be treated directly as an object.
 * @param elem - The constant to mirror.
 * @return A new ObjectLikeElement object whose contents mirror those of elem.
 * @note The parameters of elem are shallow copied to the new element, be sure to safely clear the new element's parameters before deallocating it!
 */
ObjectLikeElement* createObjLikeFromConstLike(ConstantLikeElement* elem);

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




/* Line 261 of yacc.c  */
#line 489 "parser.cpp"

/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 244 "parser.y"

#include "lexerTokenStream.h"


/* Line 264 of yacc.c  */
#line 249 "parser.y"

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
#define deallocateItem(item) if (item) delete item; item = NULL;

// Helper functions for actions.
/**
 * Takes a sort identifier and a (possibly empty) list of subsorts and tries to
 * create, add, and translate a sort from the information.
 * @param sortIdent - A string of the new sort's original name.
 * @param subsorts - A (possibly empty) list of subsorts of the desired sort.
 * @return A pointer to the new sort object, or NULL on an error.
 */
Sort* processSort(std::string* sortIdent, std::list<Sort*>* subsorts);

/**
 * Tries to find an existing normal sort or declare a starred ("something*") sort.
 * Will not instantiate a normal sort (even as a child of a "something*" sort, will
 * report an error instead.
 * @param sortIdent - The name of the sort to check and find.
 * @return A pointer to the associated instantiated sort obect, or NULL if the sort wasn't found.
 */
Sort* checkDynamicSortDecl(std::string* sortIdent);

/**
 * Transforms declarative laws ("inertial p", "exogenous a(X)", "rigid q", etc.) to basic form and calls the translator for them.
 * @param head - The head of the law, in this case a bare constant-like expression.
 * @param ifBody - Optional conditional formula to govern when the law applies.
 * @param assumingBody - Optional conditional formula similar to the 'ifBody', except results in edges in the dependency graph.
 * @param afterBody - Optional conditional formula specifying conditions from the prior time step.
 * @param unlessBody -  Optional formula that acts as an abnormality condition.
 * @param whenBody - Optional conditional formula specifying abnormalities in the current time step.
 * @param followingBody - Optional conditional formula specifying abnormalities in the previous time step.
 * @param whereBody - Another conditional formula to govern when the law applies.
 * @param opType - The kind of declaration this is (exogenous, inertial, etc.).
 * @return True if everything translates properly, false if anything goes wrong.
 */
bool handleDeclarativeLaw(
	ParseElement* head, 
	ParseElement* ifBody, 
	ParseElement* assumingBody,
	ParseElement* afterBody, 
	ParseElement* unlessBody,
	ParseElement* whenBody, 
	ParseElement* followingBody, 
	ParseElement* whereBody, 
	SimpleUnaryOperator::UnaryOperatorType opType
);

/**
 * Transforms a causal law of the form "always F [where G]." to basic form, then calls the translator for it.
 * @param constraint - The condition that must be true.
 * @param whenBody - Optional conditional formula specifying abnormalities in the current time step.
 * @param whereBody - A conditional formula to govern when the law applies.
 * @return True if everything translates properly, false if anything goes wrong.
 */
bool handleAlwaysLaw(
	ParseElement* constraint, 
	ParseElement* whenBody,
	ParseElement* whereBody
);

/**
 * Transforms a causal law of the form "constraint F [after H] [where J]." to basic form, then calls the translator for it.
 * @param constraint - The condition that must be true.
 * @param afterBody - Optional conditional formula specifying restrictions from the prior time step.
 * @param unlessBody - Optional formula that acts as an abnormality condition.
 * @param whenBody - Optional conditional formula specifying abnormalities in the current time step.
 * @param followingBody - Optional conditional formula specifying abnormalities in the previous time step.
 * @param whereBody - Another conditional formula to govern when the law applies.
 * @param positive - Whether the constraint is of the positive 'constraint F' form, or negative 'impossible F' form.
 * @return True if everything translates properly, false if anything goes wrong.
 */
bool handleConstraintLaw(
	ParseElement* constraint, 
	ParseElement* afterBody, 
	ParseElement* unlessBody, 
	ParseElement* whenBody,
	ParseElement* followingBody,
	ParseElement* whereBody,
	bool positive
);

/**
 * Transforms a causal law of the form "default F [if G] [after H] [where J]." to basic form, then calls the translator on it.
 * @param head - The head of the law.
 * @param ifBody - Optional conditional formula to govern when the law applies.
 * @param assumingBody - Optional conditional formula similar to the 'ifBody', except results in edges in the dependency graph.
 * @param afterBody - Optional conditional formula specifying conditions from the prior time step.
 * @param unlessBody - Optional atom to be dynamically declared as an default-false constant.
 * @param whenBody - Optional conditional formula specifying abnormalities in the current time step.
 * @param followingBody - Optional conditional formula specifying abnormalities in the previous time step.
 * @param whereBody - Another conditional formula to govern when the law applies.
 * @return True if everything translates properly, false if anything goes wrong.
 */
bool handleDefaultLaw(
	ParseElement* head, 
	ParseElement* ifBody, 
	ParseElement* assumingBody,
	ParseElement* afterBody, 
	ParseElement* unlessBody,
	ParseElement* whenBody,
	ParseElement* followingBody,
	ParseElement* whereBody
);

/**
 * Transforms a causal law of the form "nonexecutable F [if G] [where H]." to basic form, then calls the translator for it.
 * @param nonEx - The formula that should not be executed.
 * @param ifBody - Optional conditional formula to govern when the law applies.
 * @param whenBody - Optional conditional formula specifying abnormalities in the current time step.
 * @param whereBody - Another conditional formula to govern when the law applies.
 * @return True if everything translates properly, false if anything goes wrong.
 */
bool handleNonexecutableLaw(
	ParseElement* nonEx, 
	ParseElement* ifBody, 
	ParseElement* whenBody,
	ParseElement* whereBody
);

/**
 * Transforms a causal law of the form "possibly caused F [if G] [after H] [where J]." to basic form, then calls the translator on it.
 * @param head - The head of the law.
 * @param ifBody - Optional conditional formula to govern when the law applies.
 * @param assumingBody - Optional conditional formula similar to the 'ifBody', except results in edges in the dependency graph.
 * @param afterBody - Optional conditional formula specifying conditions from the prior time step.
 * @param unlessBody - Optional atom to be dynamically declared as an default-false constant.
 * @param whenBody - Optional conditional formula specifying abnormalities in the current time step.
 * @param followingBody - Optional conditional formula specifying abnormalities in the previous time step.
 * @param whereBody - Another conditional formula to govern when the law applies.
 * @return True if everything translates properly, false if anything goes wrong.
 */
bool handlePossiblyCausedLaw(
	ParseElement* head, 
	ParseElement* ifBody, 
	ParseElement* assumingBody,
	ParseElement* afterBody, 
	ParseElement* unlessBody,
	ParseElement* whenBody,
	ParseElement* followingBody,
	ParseElement* whereBody
);

/**
 * Transforms a causal law of the form "G may cause F [if H] [where J]." to basic form, then calls the translator on it.
 * @param causer - The causing action formula.
 * @param causee - The formula being caused.
 * @param ifBody - Optional conditional formula to govern when the law applies.
 * @param whenBody - Optional conditional formula specifying abnormalities in the current time step.
 * @param whereBody - Another conditional formula to govern when the law applies.
 * @return True if everything translates properly, false if anything goes wrong.
 */
bool handleMayCauseLaw(
	ParseElement* causer, 
	ParseElement* causee, 
	ParseElement* ifBody, 
	ParseElement* whenBody,
	ParseElement* whereBody
);

/**
 * Transforms a causal law of the form "G causes F [if H] [where J]." to basic form, then calls the translator on it.
 * @param causer - The causing action formula.
 * @param causee - The formula being caused.
 * @param ifBody - Optional conditional formula to govern when the law applies.
 * @param whenBody - Optional conditional formula specifying abnormalities in the current time step.
 * @param whereBody - Another conditional formula to govern when the law applies.
 * @return True if everything translates properly, false if anything goes wrong.
 */
bool handleCausesLaw(
	ParseElement* causer, 
	ParseElement* causee, 
	ParseElement* ifBody, 
	ParseElement* whenBody,
	ParseElement* whereBody
);

/**
 * Transforms a causal law of the form "A increments B by N [if H] [where J]." to basic form, then calls the translator on it.
 * @param causer - The causing action.
 * @param causee - The additive constant being incremented.
 * @param increment - The increment expression
 * @param ifBody - Optional conditional formula to govern when the law applies.
 * @param whenBody - Optional conditional formula specifying abnormalities in the current time step.
 * @param whereBody - Another conditional formula to govern when the law applies.
 * @param isIncrement - True if the law is increment, false if it is decrement.
 * @return True if everything translates properly, false if anything goes wrong.
 */
bool handleIncrementLaw(
	ParseElement* causer, 
	ParseElement* causee, 
	ParseElement* increment, 
	ParseElement* ifBody, 
	ParseElement* whenBody,
	ParseElement* whereBody, 
	bool isIncrement
);



/* Line 264 of yacc.c  */
#line 717 "parser.cpp"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  109
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   999

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  121
/* YYNRULES -- Number of rules.  */
#define YYNRULES  282
/* YYNRULES -- Number of states.  */
#define YYNSTATES  534

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
     357,   359,   361,   363,   365,   370,   378,   386,   394,   404,
     408,   412,   418,   422,   432,   439,   446,   448,   450,   459,
     468,   470,   480,   482,   484,   486,   488,   492,   494,   497,
     501,   505,   509,   513,   515,   519,   521,   525,   529,   533,
     535,   537,   539,   541,   543,   547,   549,   552,   556,   560,
     564,   568,   570,   574,   576,   578,   580,   584,   586,   590,
     592,   595,   599,   605,   611,   613,   615,   618,   621,   624,
     627,   632,   634,   638,   642,   646,   652,   654,   656,   660,
     664,   666,   669,   673,   677,   681,   685,   687,   691,   693,
     697,   701,   705,   707,   713,   716,   722,   723,   725,   727,
     731,   733,   735,   739,   741,   743,   745,   747,   749,   753,
     755,   759,   763,   767,   771,   775,   778,   783,   785,   787,
     791,   793,   795,   797,   800,   802,   806,   808,   812,   816,
     820,   824,   828,   830,   832,   834,   836,   838,   840,   842,
     844,   847,   850,   852,   854,   856,   858,   860,   862,   864,
     866,   869,   871
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
     199,    88,   204,    -1,    63,    14,   131,    66,    -1,   132,
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
      -1,   168,    -1,   169,    -1,    21,   172,   152,   154,    -1,
      28,   172,   150,   151,   152,   153,   154,    -1,    27,   172,
     150,   151,   152,   153,   154,    -1,    42,   172,   150,   151,
     152,   153,   154,    -1,    30,   171,   148,   149,   150,   151,
     152,   153,   154,    -1,    32,   199,   154,    -1,    36,   199,
     154,    -1,    45,   172,   148,   152,   154,    -1,    48,   199,
     154,    -1,    47,   171,   148,   149,   150,   151,   152,   153,
     154,    -1,   172,    39,   171,   148,   152,   154,    -1,   172,
      26,   171,   148,   152,   154,    -1,    43,    -1,    44,    -1,
     172,    35,   171,    24,   205,   148,   152,   154,    -1,   172,
      29,   171,    24,   205,   148,   152,   154,    -1,   172,    -1,
      25,   171,   148,   149,   150,   151,   152,   153,   154,    -1,
     183,    -1,    58,    -1,    56,    -1,   173,    -1,    64,   173,
      65,    -1,   174,    -1,   214,   172,    -1,   172,   212,   172,
      -1,   172,   213,   172,    -1,   172,    77,   172,    -1,   172,
      78,   172,    -1,   175,    -1,    64,   175,    65,    -1,   204,
      -1,   204,   215,   204,    -1,   204,   216,   204,    -1,   204,
     217,   204,    -1,   186,    -1,   172,    -1,   179,    -1,   179,
      -1,   180,    -1,    64,   180,    65,    -1,   181,    -1,   214,
     179,    -1,   179,   212,   179,    -1,   179,   213,   179,    -1,
     179,    77,   179,    -1,   179,    78,   179,    -1,   182,    -1,
      64,   182,    65,    -1,   199,    -1,   187,    -1,   184,    -1,
      64,   184,    65,    -1,   185,    -1,   183,   212,   183,    -1,
     199,    -1,   214,   199,    -1,   199,    88,   204,    -1,    61,
     188,    67,   172,    62,    -1,    61,   188,    67,   179,    62,
      -1,   189,    -1,   190,    -1,   188,   189,    -1,   188,   190,
      -1,    97,     4,    -1,    98,     4,    -1,    63,    12,   192,
      66,    -1,   193,    -1,   192,    69,   192,    -1,    38,    70,
       3,    -1,    41,    70,     3,    -1,    41,    70,     3,    90,
       3,    -1,   194,    -1,   195,    -1,    64,   194,    65,    -1,
     206,    75,   194,    -1,   196,    -1,   214,   194,    -1,   194,
     212,   194,    -1,   194,   213,   194,    -1,   194,    77,   194,
      -1,   194,    78,   194,    -1,   197,    -1,    64,   197,    65,
      -1,   204,    -1,   204,   215,   204,    -1,   204,   216,   204,
      -1,   204,   217,   204,    -1,   198,    -1,    61,   188,    67,
     194,    62,    -1,   200,     4,    -1,   200,     4,    64,   201,
      65,    -1,    -1,    60,    -1,   202,    -1,   201,    76,   202,
      -1,   205,    -1,   136,    -1,   203,    76,   136,    -1,    58,
      -1,    56,    -1,    57,    -1,   205,    -1,   206,    -1,    64,
     206,    65,    -1,   207,    -1,   205,    91,   205,    -1,   205,
      92,   205,    -1,   205,    96,   205,    -1,   205,    95,   205,
      -1,   205,    94,   205,    -1,    59,   205,    -1,    59,    64,
     205,    65,    -1,   209,    -1,   199,    -1,   210,    90,   210,
      -1,     3,    -1,    40,    -1,    41,    -1,    92,   209,    -1,
     211,    -1,    64,   211,    65,    -1,   209,    -1,   210,    91,
     210,    -1,   210,    92,   210,    -1,   210,    96,   210,    -1,
     210,    95,   210,    -1,   210,    94,   210,    -1,    81,    -1,
      80,    -1,    76,    -1,    79,    -1,    92,    -1,    89,    -1,
      88,    -1,    86,    -1,    60,    85,    -1,    60,    84,    -1,
      87,    -1,   218,    -1,   219,    -1,   220,    -1,   221,    -1,
      85,    -1,    84,    -1,    83,    -1,    60,    83,    -1,    82,
      -1,    60,    82,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   637,   637,   638,   649,   650,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   667,   675,   678,   679,   682,
     683,   686,   687,   690,   782,   786,   792,   801,   825,   829,
     835,   841,   862,   868,   882,   886,   892,   931,   954,   972,
    1046,  1063,  1066,  1067,  1070,  1071,  1074,  1075,  1078,  1152,
    1156,  1162,  1172,  1196,  1200,  1206,  1212,  1229,  1235,  1244,
    1257,  1267,  1281,  1285,  1303,  1314,  1318,  1324,  1329,  1362,
    1374,  1387,  1391,  1396,  1403,  1407,  1415,  1420,  1458,  1462,
    1468,  1477,  1481,  1487,  1492,  1497,  1502,  1507,  1512,  1517,
    1522,  1527,  1536,  1539,  1540,  1543,  1544,  1547,  1548,  1551,
    1571,  1575,  1581,  1617,  1657,  1712,  1713,  1716,  1717,  1720,
    1721,  1724,  1725,  1728,  1729,  1732,  1733,  1736,  1737,  1743,
    1744,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,
    1756,  1757,  1758,  1759,  1763,  1777,  1792,  1807,  1824,  1843,
    1856,  1869,  1884,  1905,  1924,  1940,  1956,  1962,  1970,  1986,
    2004,  2016,  2031,  2035,  2042,  2051,  2055,  2065,  2069,  2076,
    2084,  2092,  2100,  2110,  2114,  2124,  2143,  2151,  2159,  2187,
    2193,  2199,  2205,  2211,  2215,  2225,  2229,  2236,  2244,  2252,
    2260,  2270,  2274,  2284,  2292,  2298,  2302,  2312,  2316,  2326,
    2330,  2337,  2347,  2361,  2375,  2384,  2393,  2425,  2459,  2504,
    2550,  2579,  2583,  2589,  2604,  2619,  2637,  2655,  2659,  2667,
    2691,  2695,  2702,  2710,  2718,  2726,  2736,  2740,  2750,  2769,
    2777,  2785,  2813,  2819,  2835,  2886,  2940,  2941,  2943,  2952,
    2963,  2969,  2990,  3017,  3024,  3031,  3038,  3044,  3048,  3059,
    3063,  3071,  3079,  3087,  3095,  3103,  3110,  3121,  3129,  3135,
    3150,  3155,  3160,  3165,  3174,  3178,  3188,  3192,  3201,  3210,
    3219,  3228,  3240,  3244,  3248,  3254,  3260,  3264,  3270,  3276,
    3280,  3285,  3292,  3296,  3300,  3304,  3308,  3314,  3320,  3326,
    3330,  3337,  3341
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
  "T_IMPL", "T_DBL_PLUS", "T_DBL_AMP", "T_AMP", "T_GTHAN_EQ", "T_EQ_LTHAN",
  "T_GTHAN", "T_LTHAN", "T_NOT_EQ", "T_DBL_EQ", "T_EQ", "T_NOT",
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
  "AND", "OR", "NOT", "EQUALS", "NOT_EQUALS", "COMPARISON", "LESS_THAN",
  "GREATER_THAN", "LESS_THAN_EQ", "GREATER_THAN_EQ", 0
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
     191,   192,   192,   193,   193,   193,   193,   194,   194,   194,
     195,   195,   195,   195,   195,   195,   196,   196,   197,   197,
     197,   197,   197,   198,   199,   199,   200,   200,   201,   201,
     202,   203,   203,   204,   204,   204,   204,   205,   205,   206,
     206,   206,   206,   206,   206,   206,   206,   207,   207,   208,
     209,   209,   209,   209,   210,   210,   211,   211,   211,   211,
     211,   211,   212,   212,   212,   213,   214,   214,   215,   216,
     216,   216,   217,   217,   217,   217,   217,   218,   219,   220,
     220,   221,   221
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
       1,     1,     1,     1,     4,     7,     7,     7,     9,     3,
       3,     5,     3,     9,     6,     6,     1,     1,     8,     8,
       1,     9,     1,     1,     1,     1,     3,     1,     2,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     3,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     3,     3,
       3,     1,     3,     1,     1,     1,     3,     1,     3,     1,
       2,     3,     5,     5,     1,     1,     2,     2,     2,     2,
       4,     1,     3,     3,     3,     5,     1,     1,     3,     3,
       1,     2,     3,     3,     3,     3,     1,     3,     1,     3,
       3,     3,     1,     5,     2,     5,     0,     1,     1,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       3,     3,     3,     3,     3,     2,     4,     1,     1,     3,
       1,     1,     1,     2,     1,     3,     1,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,   250,   226,   226,   226,   226,   226,   226,   226,
     251,   252,   226,   146,   147,   226,   226,   226,   234,   235,
     233,   226,   227,     0,     0,   226,    15,   267,   266,     0,
       0,     4,     6,     7,     8,    10,    11,    12,    13,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,     0,   150,   155,   157,   163,   169,     9,
     248,     0,   165,   236,   237,   239,   247,   226,    14,   113,
     154,   153,   226,   266,   105,   152,   185,   187,   189,   226,
     109,   109,   105,   117,   117,   109,   105,   105,   117,   226,
       0,   245,     0,     0,     0,   194,   195,     0,     0,   226,
     226,     0,     0,     0,     0,   155,   163,   237,   253,     1,
       5,   119,   120,   226,   226,   226,   226,   264,   226,   226,
     265,   263,   262,   226,   226,   224,     0,   281,   279,   278,
     277,   269,   272,   268,   226,   226,   226,   273,   274,   275,
     276,   226,   226,   226,   226,   226,   158,   226,   117,     0,
     185,   226,   107,   226,   226,   190,   226,   111,   111,   107,
     226,   139,   140,   111,   113,   107,   142,   226,     0,   198,
     199,   226,   196,   197,    30,     0,     0,    17,    19,    21,
       0,    24,    26,    28,    55,     0,     0,    42,    44,    46,
       0,    49,    51,    53,    58,   256,    57,   254,     0,   252,
       0,   226,     0,   201,   206,   207,   210,   216,   222,   218,
     237,   226,     0,    60,    62,    81,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,    65,    67,    69,
      78,    82,   102,     0,     0,    93,    95,    97,     0,   100,
       0,   156,   164,   238,   105,     0,     0,   105,   161,   162,
     159,   160,   226,   282,   280,   271,   270,   166,   167,   168,
     240,   241,   244,   243,   242,     0,   226,   114,   171,   173,
     175,   181,   184,   183,   226,   134,   186,   106,   226,   109,
     188,   191,   110,   226,   113,   113,   109,   170,   118,   113,
     117,   109,     0,   246,     0,     0,     0,    17,    21,    24,
      28,    16,     0,     0,     0,     0,     0,    42,    46,    49,
      53,   254,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,   237,   200,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   211,    59,
     226,   226,     0,    65,    64,     0,     0,     0,    79,     0,
       0,    97,   100,    92,     0,     0,     0,     0,     0,   113,
     226,   226,   113,     0,   228,   230,     0,     0,   173,   181,
     226,   226,   226,   226,   176,   108,   111,   112,   115,   115,
     111,   115,   141,   111,   192,   231,    76,     0,    77,     0,
      18,    22,    25,    29,     0,    20,     0,    73,    72,     0,
      23,    34,    36,    71,    74,    82,     0,    27,     0,    43,
      47,    50,    54,   255,    45,     0,    48,     0,    52,   249,
     257,   258,   261,   260,   259,   203,   204,   226,   208,   217,
     202,   214,   215,   212,   213,   219,   220,   221,   209,    61,
      63,    66,    68,    70,    80,     0,     0,    94,    98,   101,
      96,   104,    99,   103,     0,    40,   117,   105,   105,   117,
     225,   226,   226,   174,   182,   179,   180,   177,   178,   113,
     226,   117,   117,   113,   117,   113,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,   145,   113,   113,   144,   229,     0,   115,   116,
     172,   136,   135,   115,   137,   115,   232,     0,    32,    38,
       0,    35,    75,     0,   205,   223,   117,   117,   193,   117,
     117,   117,     0,     0,    37,   149,   148,   151,   138,   143,
       0,     0,    33,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    29,    30,    31,    32,   176,   177,   178,   179,   180,
     299,   182,   183,   509,   400,   401,    33,    34,   186,   187,
     188,   189,   190,   191,   192,   193,    35,   212,   213,    36,
     226,   227,   228,   402,   403,   385,   386,   230,   231,    37,
     234,   235,   236,   237,   238,   239,   452,   152,   279,   157,
     284,   148,   471,   161,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      74,    54,    55,    56,    57,   288,   267,   499,   268,   269,
     270,   271,    75,    76,    77,    58,   272,    94,    95,    96,
      59,   202,   203,   204,   205,   206,   207,   208,    60,    61,
     363,   364,   387,    62,    63,    64,    65,   388,    66,   389,
     197,   123,   124,    67,   134,   135,   136,   137,   138,   139,
     140
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -340
static const yytype_int16 yypact[] =
{
     521,   -10,  -340,   797,   674,   797,   797,   674,    16,    16,
    -340,  -340,   797,  -340,  -340,   797,   674,    16,  -340,  -340,
    -340,   374,  -340,   133,   505,   797,  -340,  -340,    26,    78,
     605,  -340,  -340,  -340,  -340,  -340,  -340,  -340,  -340,    25,
    -340,  -340,  -340,  -340,  -340,  -340,  -340,  -340,  -340,  -340,
    -340,  -340,  -340,    37,   859,  -340,  -340,  -340,  -340,  -340,
    -340,   106,   867,   787,  -340,  -340,  -340,   797,  -340,   601,
    -340,  -340,    90,  -340,    86,   126,  -340,  -340,    60,    16,
     538,   538,    86,    97,    97,   538,   495,    86,    97,   869,
      40,   787,   169,   174,   -26,  -340,  -340,    30,   158,   788,
      16,   639,    34,   118,   906,    65,   119,   121,  -340,  -340,
    -340,  -340,  -340,   674,   674,   674,   674,  -340,   797,   797,
    -340,  -340,  -340,   797,   797,   152,   196,  -340,  -340,  -340,
    -340,  -340,  -340,  -340,   856,   856,   856,  -340,  -340,  -340,
    -340,   869,   869,   869,   869,   869,  -340,   343,    97,   126,
     161,   797,   198,    90,   856,  -340,   797,   187,   187,   198,
     797,  -340,  -340,   187,   191,   198,  -340,   869,   529,  -340,
    -340,   797,  -340,  -340,   183,    30,    36,  -340,  -340,  -340,
     -21,  -340,  -340,  -340,   199,   158,    69,  -340,  -340,  -340,
      64,  -340,  -340,  -340,  -340,  -340,   873,  -340,   194,   195,
     133,   810,   114,  -340,   912,  -340,  -340,  -340,  -340,   867,
     208,   810,   149,  -340,   182,  -340,  -340,  -340,  -340,  -340,
    -340,  -340,  -340,  -340,  -340,   639,   155,  -340,  -340,   180,
      -1,  -340,  -340,    35,   229,  -340,   232,  -340,   234,   230,
      47,  -340,  -340,  -340,    86,   281,   285,    86,   737,   345,
     906,   906,   869,  -340,  -340,  -340,  -340,  -340,  -340,  -340,
     100,   100,  -340,  -340,  -340,   133,   343,  -340,   918,  -340,
    -340,  -340,  -340,  -340,   343,  -340,  -340,   906,   797,   290,
     126,  -340,   906,    16,   191,   191,   290,   906,  -340,   191,
      97,   290,   787,  -340,   845,   732,   244,   249,   255,   257,
     260,  -340,    42,   667,    49,   732,   259,   261,   265,   271,
     272,   278,  -340,   158,   771,   381,    47,    47,    47,    47,
      47,    47,   348,   350,   103,   865,   292,   -17,  -340,   788,
     810,   810,   810,   810,   856,   856,   856,   810,  -340,  -340,
      16,   856,   286,   293,  -340,   639,   639,   302,  -340,    50,
     298,   299,   -13,  -340,    34,   771,   361,    47,   711,   191,
     869,   869,   191,    -8,  -340,   787,   107,   918,   305,   311,
     343,   343,   343,   343,  -340,   906,   187,  -340,   313,   313,
     187,   313,  -340,   187,  -340,  -340,  -340,     8,  -340,   873,
    -340,  -340,  -340,  -340,    73,  -340,     1,  -340,  -340,   706,
    -340,  -340,  -340,  -340,  -340,   319,   384,  -340,    17,  -340,
    -340,  -340,  -340,  -340,   259,   732,  -340,   387,  -340,   809,
     157,   157,  -340,  -340,  -340,  -340,   306,   810,  -340,  -340,
     323,   753,   382,   912,   912,  -340,  -340,  -340,   912,  -340,
    -340,  -340,   286,  -340,  -340,   398,   299,  -340,  -340,  -340,
    -340,  -340,  -340,  -340,   809,  -340,    97,   496,   496,    97,
    -340,   869,   343,  -340,  -340,   762,   389,   918,   918,   191,
     343,    97,    97,   191,    97,   191,  -340,   732,    73,   255,
     401,   732,   341,   351,   732,   260,  -340,   351,   272,   414,
     894,   -13,  -340,   191,   191,  -340,  -340,   900,   313,  -340,
     918,  -340,  -340,   313,  -340,   313,  -340,   344,   367,  -340,
     371,  -340,  -340,   375,  -340,  -340,    97,    97,  -340,    97,
      97,    97,   732,   393,  -340,  -340,  -340,  -340,  -340,  -340,
      32,   401,  -340,  -340
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -340,  -340,  -340,   412,  -340,   268,   273,   145,  -161,    -4,
     -77,   146,  -171,   -66,  -340,    53,  -340,  -340,  -155,   295,
    -340,   296,  -340,   303,   172,  -180,  -340,  -340,   144,  -340,
    -200,   264,  -340,  -340,  -291,   116,   -74,  -340,  -270,  -340,
     137,   263,  -340,  -218,  -340,  -216,  -340,   -79,     4,    75,
    -142,  -113,  -339,   -62,  -340,  -340,  -340,  -340,  -340,  -340,
    -340,  -340,  -340,  -340,  -340,  -340,  -340,  -340,  -340,  -340,
      76,   480,   468,  -340,   472,  -340,  -340,  -340,  -162,   233,
    -340,   240,   -44,   428,  -340,  -340,  -340,  -169,   -84,   -82,
    -340,   178,  -340,   -34,  -340,  -340,   322,  -340,    28,  -340,
    -340,    66,  -286,   -75,   -20,   -14,  -340,   -96,   -28,    29,
    -172,    44,    70,     2,   317,   324,   330,  -340,  -340,  -340,
    -340
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -227
static const yytype_int16 yytable[] =
{
     108,    91,   194,   159,   300,   310,    79,   164,   165,    79,
     172,   107,   173,   311,   298,   351,   285,   352,    79,   408,
     181,   289,   162,   416,   209,   342,   166,   229,   149,     2,
     306,   324,    78,   405,   174,    78,    83,    84,   232,   232,
     472,   171,   474,     2,    78,    88,   174,   480,   243,   303,
       2,   290,   449,   174,   232,   304,    68,   460,   337,   257,
     258,   259,   108,   356,   451,   481,    10,    11,   461,   168,
     195,    92,    93,   476,    79,   107,    22,   174,   109,   281,
      10,    11,   486,    82,   477,   210,   275,    10,    11,   194,
     347,   111,    87,   477,   175,   348,   366,   532,   233,   349,
      78,   211,   301,   112,   367,   302,   394,   155,   477,   280,
     125,   357,   374,   406,   445,    79,    79,    79,    79,   153,
     151,   260,   261,   262,   263,   264,   209,   196,   214,   405,
     241,   446,    90,   352,   314,   312,   209,   478,   313,    90,
     315,    78,    78,    78,    78,   442,   443,   292,   154,   274,
      22,   229,   160,   107,    72,    79,   158,   195,   414,   519,
     163,     2,   184,   286,   520,   359,   521,   325,   362,   291,
     427,   378,   379,   169,   462,   273,   381,   338,   170,    27,
     328,    78,    73,   329,   242,   311,   243,   327,   240,   244,
     245,   246,   247,   153,   143,   144,   145,   210,    10,    11,
      92,    93,   117,   211,    92,    93,   121,   122,   465,   466,
     467,   468,   195,   211,   196,   339,   252,   194,   340,   194,
     278,   344,   185,   300,   345,   181,   276,   311,   382,   491,
      92,    93,   365,   479,   469,   485,   530,   488,   473,   283,
     172,   475,   173,   311,   147,   311,   456,   295,   332,   459,
      90,   319,   320,   321,   209,   209,   209,   209,   209,   435,
     436,   437,   209,   305,   322,   323,   440,   195,   274,   358,
     341,   229,   229,   346,   333,   195,   274,   195,   253,   254,
     255,   256,   172,   337,   173,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   273,   353,   431,   432,   433,   434,
     497,   354,   273,   438,   355,   360,   356,   300,   500,   361,
     156,   377,   372,   302,   390,   210,   210,   210,   210,   210,
     391,   194,   392,   210,   153,   393,   409,   195,   313,   195,
     410,   211,   211,   211,   211,   211,   411,   412,   373,   211,
     457,   458,   196,   413,   196,   419,   420,   421,   422,   423,
     424,   425,   209,   426,   376,   345,   498,   429,   441,   444,
     503,   380,   505,   447,   448,   453,   383,   470,   214,   332,
     463,   195,   274,   274,   274,   274,   464,     2,   493,   494,
     516,   517,   332,   484,     2,   184,   454,   195,   174,   195,
       2,   184,   329,   490,   492,   333,   489,   495,   273,   273,
     273,   273,   232,    22,   265,   508,   511,   266,   333,   501,
     502,   372,   504,   210,    10,    11,   512,   514,   372,   404,
     304,    10,    11,   119,   120,   121,   122,    10,    11,   211,
     404,   522,    27,    21,    22,    73,   523,   373,    89,   531,
     524,   365,   110,   296,   373,   417,   196,   395,   297,   195,
     407,   357,   482,   195,   525,   526,   195,   527,   528,   529,
     331,   120,   121,   122,   274,   533,    90,   371,   120,   121,
     122,   404,   274,    90,   507,   332,   332,   332,   332,    90,
     307,   308,   332,    69,   439,    80,    81,   418,   309,   343,
     273,   450,    85,   105,   195,    86,   350,   106,   273,   368,
     150,   333,   333,   333,   333,   104,   369,   430,   333,   372,
     372,   372,   372,    97,     0,   483,    98,    99,   100,   101,
     102,    -2,     1,   326,     2,  -226,   334,   496,     0,   151,
     151,   487,     0,   335,   332,   373,   373,   373,   373,   336,
       0,   372,     3,     0,   372,   103,     4,   146,     5,     6,
       0,     7,     0,     8,     0,     0,     0,     9,   156,     0,
     333,    10,    11,    12,    13,    14,    15,   373,    16,    17,
     373,   117,   118,   119,   120,   121,   122,    18,    19,    20,
      21,    22,    23,     0,    24,    25,     0,   141,   142,    26,
     143,   144,   145,   506,   293,     0,     0,   510,   248,   249,
     513,     0,     0,   250,   251,    -3,     1,     0,     2,  -226,
      27,     0,     0,    28,   117,   118,   119,   120,   121,   122,
     141,   142,     0,   143,   144,   145,     3,     0,     0,     0,
       4,   277,     5,     6,     0,     7,   282,     8,     0,     0,
     287,     9,     0,   215,     0,    10,    11,    12,    13,    14,
      15,   294,    16,    17,   147,   216,   217,   218,   219,     0,
       0,    18,    19,    20,    21,    22,    23,     0,    24,    25,
       2,   215,   220,    26,     0,     0,   221,   117,   118,   119,
     120,   121,   122,   216,   217,   218,   219,   222,   223,   224,
     396,     0,     0,     0,    27,     0,     0,    28,   397,     0,
     220,     0,     0,   225,   221,     0,     0,    10,    11,     2,
     215,     0,     0,     0,     0,   222,   223,   224,   398,     0,
       0,     0,   216,   217,   218,   219,     0,     0,     0,   396,
      70,   399,    71,     0,    22,     2,   215,   397,    72,   220,
       0,     0,     0,   221,     0,     0,    10,    11,   216,   217,
     218,   219,     0,     0,   222,   223,   224,   398,   375,    90,
       0,     0,     0,    27,     0,   220,    73,     0,     0,   221,
     415,     0,    10,    11,     2,   215,     0,   455,     0,     0,
     222,   223,   224,     0,     0,     0,     0,   216,   217,   218,
     219,     2,     0,     0,     0,     0,   357,     0,    90,     0,
       2,     0,   317,   318,   220,   319,   320,   321,   221,     0,
       0,    10,    11,     2,   118,   119,   120,   121,   122,   222,
     223,   224,     0,     0,    90,     0,   198,     0,    10,   199,
     330,   331,   120,   121,   122,   415,     0,    10,    11,   370,
     371,   120,   121,   122,    18,    19,    20,    21,    22,   200,
      10,    11,   201,    18,    19,    20,    21,    22,    23,     2,
       0,    25,     0,    90,     0,     0,    18,    19,    20,    21,
      22,   200,     2,     0,   201,     0,     0,    27,   141,   142,
      28,   143,   144,   145,     0,   113,    27,     0,   114,    28,
       0,     0,     0,     0,   115,     0,    10,    11,   116,    27,
     317,   318,    28,   319,   320,   321,     0,   384,     0,    10,
      11,     0,    18,    19,    20,    21,    22,     0,     0,     0,
     167,   117,   118,   119,   120,   121,   122,   126,    21,    22,
     428,     0,     0,   167,     0,   117,   118,   119,   120,   121,
     122,   117,   330,   331,   120,   121,   122,     0,    90,   127,
     128,   129,   130,   131,   132,   133,   515,     0,     0,     0,
       0,    90,   518,   316,   317,   318,     0,   319,   320,   321,
     117,   330,   331,   120,   121,   122,   117,   370,   371,   120,
     121,   122,   117,   118,   119,   120,   121,   122,   117,   330,
     331,   120,   121,   122,   117,   370,   371,   120,   121,   122
};

static const yytype_int16 yycheck[] =
{
      28,    21,    98,    82,   175,   185,     4,    86,    87,     7,
      94,    25,    94,   185,   175,   233,   158,   233,    16,   305,
      97,   163,    84,   314,    99,   225,    88,   101,    72,     3,
     185,   200,     4,   303,     4,     7,     8,     9,     4,     4,
     379,    67,   381,     3,    16,    17,     4,    46,    65,    70,
       3,   164,    65,     4,     4,    76,    66,    65,    75,   134,
     135,   136,    90,    76,   355,    64,    40,    41,    76,    89,
      98,    97,    98,    65,    72,    89,    60,     4,     0,   154,
      40,    41,    65,     7,    76,    99,   148,    40,    41,   185,
      91,    66,    16,    76,    64,    96,   265,    65,    64,    64,
      72,    99,    66,    66,   266,    69,    64,    79,    76,   153,
       4,    64,   274,    64,    64,   113,   114,   115,   116,    75,
      34,   141,   142,   143,   144,   145,   201,    98,   100,   399,
      65,   349,    92,   349,    70,    66,   211,    64,    69,    92,
      76,   113,   114,   115,   116,   345,   346,   167,    88,   147,
      60,   225,    55,   167,    64,   153,    81,   185,   313,   498,
      85,     3,     4,   159,   503,   244,   505,   201,   247,   165,
      67,   284,   285,     4,    67,   147,   289,   211,     4,    89,
      66,   153,    92,    69,    65,   357,    65,   201,    70,   113,
     114,   115,   116,   149,    94,    95,    96,   211,    40,    41,
      97,    98,    76,   201,    97,    98,    80,    81,   370,   371,
     372,   373,   240,   211,   185,    66,    64,   313,    69,   315,
      22,    66,    64,   394,    69,   302,    65,   399,   290,   445,
      97,    98,   252,   394,   376,   406,   522,   417,   380,    52,
     324,   383,   324,   415,    53,   417,   359,    64,   204,   362,
      92,    94,    95,    96,   329,   330,   331,   332,   333,   334,
     335,   336,   337,    64,    70,    70,   341,   295,   266,   240,
      88,   345,   346,    93,   204,   303,   274,   305,    82,    83,
      84,    85,   366,    75,   366,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   266,    66,   330,   331,   332,   333,
     462,    69,   274,   337,    70,    24,    76,   478,   470,    24,
      20,   283,   268,    69,    65,   329,   330,   331,   332,   333,
      65,   417,    65,   337,   280,    65,    65,   355,    69,   357,
      65,   329,   330,   331,   332,   333,    65,    65,   268,   337,
     360,   361,   313,    65,   315,   316,   317,   318,   319,   320,
     321,     3,   427,     3,   279,    69,   469,    65,    65,    57,
     473,   286,   475,    65,    65,     4,   291,    54,   340,   325,
      65,   399,   370,   371,   372,   373,    65,     3,   457,   458,
     493,   494,   338,    64,     3,     4,   357,   415,     4,   417,
       3,     4,    69,   427,   456,   325,    90,   459,   370,   371,
     372,   373,     4,    60,    61,     4,    65,    64,   338,   471,
     472,   367,   474,   427,    40,    41,    65,     3,   374,   303,
      76,    40,    41,    78,    79,    80,    81,    40,    41,   427,
     314,    64,    89,    59,    60,    92,    65,   367,    64,    46,
      65,   461,    30,   175,   374,    64,   417,   302,   175,   477,
     304,    64,   399,   481,   516,   517,   484,   519,   520,   521,
      78,    79,    80,    81,   462,   531,    92,    78,    79,    80,
      81,   355,   470,    92,   478,   431,   432,   433,   434,    92,
     185,   185,   438,     3,   340,     5,     6,   315,   185,   225,
     462,   354,    12,    25,   522,    15,   233,    25,   470,   266,
      72,   431,   432,   433,   434,    25,   266,   329,   438,   465,
     466,   467,   468,     8,    -1,   399,    11,    12,    13,    14,
      15,     0,     1,   201,     3,     4,   209,   461,    -1,    34,
      34,   415,    -1,   209,   490,   465,   466,   467,   468,   209,
      -1,   497,    21,    -1,   500,    40,    25,    67,    27,    28,
      -1,    30,    -1,    32,    -1,    -1,    -1,    36,    20,    -1,
     490,    40,    41,    42,    43,    44,    45,   497,    47,    48,
     500,    76,    77,    78,    79,    80,    81,    56,    57,    58,
      59,    60,    61,    -1,    63,    64,    -1,    91,    92,    68,
      94,    95,    96,   477,    65,    -1,    -1,   481,   118,   119,
     484,    -1,    -1,   123,   124,     0,     1,    -1,     3,     4,
      89,    -1,    -1,    92,    76,    77,    78,    79,    80,    81,
      91,    92,    -1,    94,    95,    96,    21,    -1,    -1,    -1,
      25,   151,    27,    28,    -1,    30,   156,    32,    -1,    -1,
     160,    36,    -1,     4,    -1,    40,    41,    42,    43,    44,
      45,   171,    47,    48,    53,    16,    17,    18,    19,    -1,
      -1,    56,    57,    58,    59,    60,    61,    -1,    63,    64,
       3,     4,    33,    68,    -1,    -1,    37,    76,    77,    78,
      79,    80,    81,    16,    17,    18,    19,    48,    49,    50,
      23,    -1,    -1,    -1,    89,    -1,    -1,    92,    31,    -1,
      33,    -1,    -1,    64,    37,    -1,    -1,    40,    41,     3,
       4,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    -1,
      -1,    -1,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      56,    64,    58,    -1,    60,     3,     4,    31,    64,    33,
      -1,    -1,    -1,    37,    -1,    -1,    40,    41,    16,    17,
      18,    19,    -1,    -1,    48,    49,    50,    51,   278,    92,
      -1,    -1,    -1,    89,    -1,    33,    92,    -1,    -1,    37,
      64,    -1,    40,    41,     3,     4,    -1,    66,    -1,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,     3,    -1,    -1,    -1,    -1,    64,    -1,    92,    -1,
       3,    -1,    91,    92,    33,    94,    95,    96,    37,    -1,
      -1,    40,    41,     3,    77,    78,    79,    80,    81,    48,
      49,    50,    -1,    -1,    92,    -1,    38,    -1,    40,    41,
      77,    78,    79,    80,    81,    64,    -1,    40,    41,    77,
      78,    79,    80,    81,    56,    57,    58,    59,    60,    61,
      40,    41,    64,    56,    57,    58,    59,    60,    61,     3,
      -1,    64,    -1,    92,    -1,    -1,    56,    57,    58,    59,
      60,    61,     3,    -1,    64,    -1,    -1,    89,    91,    92,
      92,    94,    95,    96,    -1,    26,    89,    -1,    29,    92,
      -1,    -1,    -1,    -1,    35,    -1,    40,    41,    39,    89,
      91,    92,    92,    94,    95,    96,    -1,    62,    -1,    40,
      41,    -1,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      64,    76,    77,    78,    79,    80,    81,    60,    59,    60,
      65,    -1,    -1,    64,    -1,    76,    77,    78,    79,    80,
      81,    76,    77,    78,    79,    80,    81,    -1,    92,    82,
      83,    84,    85,    86,    87,    88,    62,    -1,    -1,    -1,
      -1,    92,    62,    90,    91,    92,    -1,    94,    95,    96,
      76,    77,    78,    79,    80,    81,    76,    77,    78,    79,
      80,    81,    76,    77,    78,    79,    80,    81,    76,    77,
      78,    79,    80,    81,    76,    77,    78,    79,    80,    81
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
     199,   200,   204,   205,   206,   207,   209,   214,    66,   172,
      56,    58,    64,    92,   171,   183,   184,   185,   199,   214,
     172,   172,   171,   199,   199,   172,   172,   171,   199,    64,
      92,   205,    97,    98,   188,   189,   190,     8,    11,    12,
      13,    14,    15,    40,   172,   173,   175,   206,   209,     0,
     104,    66,    66,    26,    29,    35,    39,    76,    77,    78,
      79,    80,    81,   212,   213,     4,    60,    82,    83,    84,
      85,    86,    87,    88,   215,   216,   217,   218,   219,   220,
     221,    91,    92,    94,    95,    96,   172,    53,   152,   183,
     184,    34,   148,   212,    88,   199,    20,   150,   150,   148,
      55,   154,   154,   150,   148,   148,   154,    64,   205,     4,
       4,    67,   189,   190,     4,    64,   106,   107,   108,   109,
     110,   111,   112,   113,     4,    64,   119,   120,   121,   122,
     123,   124,   125,   126,   208,   209,   210,   211,    38,    41,
      61,    64,   192,   193,   194,   195,   196,   197,   198,   204,
     206,   214,   128,   129,   199,     4,    16,    17,    18,    19,
      33,    37,    48,    49,    50,    64,   131,   132,   133,   137,
     138,   139,     4,    64,   141,   142,   143,   144,   145,   146,
      70,    65,    65,    65,   171,   171,   171,   171,   172,   172,
     172,   172,    64,    82,    83,    84,    85,   204,   204,   204,
     205,   205,   205,   205,   205,    61,    64,   177,   179,   180,
     181,   182,   187,   199,   214,   154,    65,   172,    22,   149,
     183,   204,   172,    52,   151,   151,   149,   172,   176,   151,
     152,   149,   205,    65,   172,    64,   106,   107,   109,   111,
     113,    66,    69,    70,    76,    64,   119,   120,   122,   124,
     126,   211,    66,    69,    70,    76,    90,    91,    92,    94,
      95,    96,    70,    70,   188,   194,   197,   206,    66,    69,
      77,    78,   212,   213,   215,   216,   217,    75,   194,    66,
      69,    88,   131,   132,    66,    69,    93,    91,    96,    64,
     142,   144,   146,    66,    69,    70,    76,    64,   210,   148,
      24,    24,   148,   201,   202,   205,   188,   179,   180,   182,
      77,    78,   212,   213,   179,   172,   150,   199,   152,   152,
     150,   152,   154,   150,    62,   136,   137,   203,   208,   210,
      65,    65,    65,    65,    64,   108,    23,    31,    51,    64,
     115,   116,   134,   135,   136,   139,    64,   112,   203,    65,
      65,    65,    65,    65,   119,    64,   135,    64,   125,   210,
     210,   210,   210,   210,   210,     3,     3,    67,    65,    65,
     192,   194,   194,   194,   194,   204,   204,   204,   194,   129,
     204,    65,   131,   131,    57,    64,   144,    65,    65,    65,
     141,   135,   147,     4,   210,    66,   152,   205,   205,   152,
      65,    76,    67,    65,    65,   179,   179,   179,   179,   151,
      54,   153,   153,   151,   153,   151,    65,    76,    64,   109,
      46,    64,   116,   136,    64,   113,    65,   136,   126,    90,
     194,   146,   154,   148,   148,   154,   202,   179,   152,   178,
     179,   154,   154,   152,   154,   152,   136,   110,     4,   114,
     136,    65,    65,   136,     3,    62,   152,   152,    62,   153,
     153,   153,    64,    65,    65,   154,   154,   154,   154,   154,
     203,    46,    65,   114
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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
# if YYLTYPE_IS_TRIVIAL
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Line 1000 of yacc.c  */
#line 621 "parser.y"
	{ delete (yyvaluep->str); };

/* Line 1000 of yacc.c  */
#line 2267 "parser.cpp"
	break;
      case 5: /* "T_STRING" */

/* Line 1000 of yacc.c  */
#line 621 "parser.y"
	{ delete (yyvaluep->str); };

/* Line 1000 of yacc.c  */
#line 2276 "parser.cpp"
	break;
      case 110: /* "constant_schema_outer_list" */

/* Line 1000 of yacc.c  */
#line 629 "parser.y"
	{ if((yyvaluep->l_constant) != NULL) { deallocateList((yyvaluep->l_constant)); } };

/* Line 1000 of yacc.c  */
#line 2285 "parser.cpp"
	break;
      case 111: /* "constant_schema_list" */

/* Line 1000 of yacc.c  */
#line 629 "parser.y"
	{ if((yyvaluep->l_constant) != NULL) { deallocateList((yyvaluep->l_constant)); } };

/* Line 1000 of yacc.c  */
#line 2294 "parser.cpp"
	break;
      case 112: /* "constant_outer_schema" */

/* Line 1000 of yacc.c  */
#line 623 "parser.y"
	{ delete (yyvaluep->constant); };

/* Line 1000 of yacc.c  */
#line 2303 "parser.cpp"
	break;
      case 113: /* "constant_schema" */

/* Line 1000 of yacc.c  */
#line 623 "parser.y"
	{ delete (yyvaluep->constant); };

/* Line 1000 of yacc.c  */
#line 2312 "parser.cpp"
	break;
      case 114: /* "constant_schema_nodecl" */

/* Line 1000 of yacc.c  */
#line 623 "parser.y"
	{ delete (yyvaluep->constant); };

/* Line 1000 of yacc.c  */
#line 2321 "parser.cpp"
	break;
      case 115: /* "constant_outer_binder" */

/* Line 1000 of yacc.c  */
#line 633 "parser.y"
	{ if((yyvaluep->constant_binder_t) != NULL) { deallocateItem((yyvaluep->constant_binder_t)); } };

/* Line 1000 of yacc.c  */
#line 2330 "parser.cpp"
	break;
      case 116: /* "constant_binder" */

/* Line 1000 of yacc.c  */
#line 633 "parser.y"
	{ if((yyvaluep->constant_binder_t) != NULL) { deallocateItem((yyvaluep->constant_binder_t)); } };

/* Line 1000 of yacc.c  */
#line 2339 "parser.cpp"
	break;
      case 123: /* "object_outer_schema_list" */

/* Line 1000 of yacc.c  */
#line 630 "parser.y"
	{ if((yyvaluep->l_object) != NULL) { deallocateList((yyvaluep->l_object)); } };

/* Line 1000 of yacc.c  */
#line 2348 "parser.cpp"
	break;
      case 124: /* "object_schema_list" */

/* Line 1000 of yacc.c  */
#line 630 "parser.y"
	{ if((yyvaluep->l_object) != NULL) { deallocateList((yyvaluep->l_object)); } };

/* Line 1000 of yacc.c  */
#line 2357 "parser.cpp"
	break;
      case 125: /* "object_outer_schema" */

/* Line 1000 of yacc.c  */
#line 625 "parser.y"
	{ delete (yyvaluep->object); };

/* Line 1000 of yacc.c  */
#line 2366 "parser.cpp"
	break;
      case 126: /* "object_schema" */

/* Line 1000 of yacc.c  */
#line 625 "parser.y"
	{ delete (yyvaluep->object); };

/* Line 1000 of yacc.c  */
#line 2375 "parser.cpp"
	break;
      case 131: /* "sort_spec_outer_tuple" */

/* Line 1000 of yacc.c  */
#line 631 "parser.y"
	{ if((yyvaluep->l_sort) != NULL) { deallocateList((yyvaluep->l_sort)); } };

/* Line 1000 of yacc.c  */
#line 2384 "parser.cpp"
	break;
      case 132: /* "sort_spec_tuple" */

/* Line 1000 of yacc.c  */
#line 631 "parser.y"
	{ if((yyvaluep->l_sort) != NULL) { deallocateList((yyvaluep->l_sort)); } };

/* Line 1000 of yacc.c  */
#line 2393 "parser.cpp"
	break;
      case 133: /* "sort_spec" */

/* Line 1000 of yacc.c  */
#line 627 "parser.y"
	{ delete (yyvaluep->sort); };

/* Line 1000 of yacc.c  */
#line 2402 "parser.cpp"
	break;
      case 134: /* "sort_identifier_with_ab" */

/* Line 1000 of yacc.c  */
#line 621 "parser.y"
	{ delete (yyvaluep->str); };

/* Line 1000 of yacc.c  */
#line 2411 "parser.cpp"
	break;
      case 135: /* "sort_outer_identifier" */

/* Line 1000 of yacc.c  */
#line 621 "parser.y"
	{ delete (yyvaluep->str); };

/* Line 1000 of yacc.c  */
#line 2420 "parser.cpp"
	break;
      case 136: /* "sort_identifier" */

/* Line 1000 of yacc.c  */
#line 621 "parser.y"
	{ delete (yyvaluep->str); };

/* Line 1000 of yacc.c  */
#line 2429 "parser.cpp"
	break;
      case 137: /* "sort_identifier_no_range" */

/* Line 1000 of yacc.c  */
#line 621 "parser.y"
	{ delete (yyvaluep->str); };

/* Line 1000 of yacc.c  */
#line 2438 "parser.cpp"
	break;
      case 138: /* "sort_identifier_name" */

/* Line 1000 of yacc.c  */
#line 621 "parser.y"
	{ delete (yyvaluep->str); };

/* Line 1000 of yacc.c  */
#line 2447 "parser.cpp"
	break;
      case 139: /* "sort_constant_name" */

/* Line 1000 of yacc.c  */
#line 621 "parser.y"
	{ delete (yyvaluep->str); };

/* Line 1000 of yacc.c  */
#line 2456 "parser.cpp"
	break;
      case 145: /* "variable_outer_list" */

/* Line 1000 of yacc.c  */
#line 632 "parser.y"
	{ if((yyvaluep->l_variable) != NULL) { deallocateList((yyvaluep->l_variable)); } };

/* Line 1000 of yacc.c  */
#line 2465 "parser.cpp"
	break;
      case 146: /* "variable_list" */

/* Line 1000 of yacc.c  */
#line 632 "parser.y"
	{ if((yyvaluep->l_variable) != NULL) { deallocateList((yyvaluep->l_variable)); } };

/* Line 1000 of yacc.c  */
#line 2474 "parser.cpp"
	break;
      case 147: /* "variable_binding" */

/* Line 1000 of yacc.c  */
#line 627 "parser.y"
	{ delete (yyvaluep->sort); };

/* Line 1000 of yacc.c  */
#line 2483 "parser.cpp"
	break;
      case 200: /* "lua_indicator" */

/* Line 1000 of yacc.c  */
#line 621 "parser.y"
	{ delete (yyvaluep->str); };

/* Line 1000 of yacc.c  */
#line 2492 "parser.cpp"
	break;
      case 203: /* "sort_identifier_list" */

/* Line 1000 of yacc.c  */
#line 631 "parser.y"
	{ if((yyvaluep->l_sort) != NULL) { deallocateList((yyvaluep->l_sort)); } };

/* Line 1000 of yacc.c  */
#line 2501 "parser.cpp"
	break;
      case 208: /* "num_range" */

/* Line 1000 of yacc.c  */
#line 624 "parser.y"
	{ delete (yyvaluep->numRange); };

/* Line 1000 of yacc.c  */
#line 2510 "parser.cpp"
	break;
      case 209: /* "extended_integer" */

/* Line 1000 of yacc.c  */
#line 621 "parser.y"
	{ delete (yyvaluep->str); };

/* Line 1000 of yacc.c  */
#line 2519 "parser.cpp"
	break;
      case 210: /* "extended_integer_outer_expression" */

/* Line 1000 of yacc.c  */
#line 621 "parser.y"
	{ delete (yyvaluep->str); };

/* Line 1000 of yacc.c  */
#line 2528 "parser.cpp"
	break;
      case 211: /* "extended_integer_expression" */

/* Line 1000 of yacc.c  */
#line 621 "parser.y"
	{ delete (yyvaluep->str); };

/* Line 1000 of yacc.c  */
#line 2537 "parser.cpp"
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



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    YYLTYPE yyerror_range[2];

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

#if YYLTYPE_IS_TRIVIAL
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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 637 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 639 "parser.y"
    { 
		(yyval.not_used) = PARSERULE_NOT_USED; 

		// Ensure that we append the footer
		// after the program has finished translating
		mainTrans.outputFooter();
		
;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 649 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 650 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 653 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 654 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 655 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 656 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 657 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 658 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 659 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 660 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 662 "parser.y"
    { 
	(yyval.not_used) = PARSERULE_NOT_USED;
	/* On an error, go to the end of the bad statement and try to continue.
       Set the error handler to not wait to report syntax errors if more show up. */
	yyerrok;
;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 667 "parser.y"
    {(yyval.not_used) = PARSERULE_NOT_USED;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 675 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 678 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 679 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 682 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 683 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 686 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 687 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 691 "parser.y"
    {
	// Fill in each Constant's type and domain and translate each of them.
	bool constantError = true; // Set to true if any of the constants have trouble getting added to the symbol table.
	Sort* tempSort = NULL;
	if((yyvsp[(1) - (3)].l_constant) != NULL && (yyvsp[(3) - (3)].constant_binder_t) != NULL)
	{
		tempSort = (yyvsp[(3) - (3)].constant_binder_t)->domain;
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
					tempAttribute = new Attribute((*lIter)->name, (*lIter)->transName);
					tempAttribute->domain = (*lIter)->domain; // Should be NULL = NULL, but just in case.
					for(std::vector<Sort*>::iterator vIter = (*lIter)->params.begin(); vIter != (*lIter)->params.end(); ++vIter)
					{
						if((*vIter) != NULL)
						{
							tempAttribute->params.push_back(*vIter);
						}
					}
					deallocateItem(*lIter);
					(*lIter) = tempAttribute;
				}
			}
			
			for(lIter = (yyvsp[(1) - (3)].l_constant)->begin(); lIter != (yyvsp[(1) - (3)].l_constant)->end(); ++lIter)
			{	// Try to add each constant to the symbol table before hooking it up and translating it.
				int addSymResult = mainTrans.addConstant(*lIter);
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
					(*lIter)->constType = (yyvsp[(3) - (3)].constant_binder_t)->constType;
					(*lIter)->domain = tempSort;
					if((*lIter)->constType == Constant::CONST_ATTRIBUTE && (yyvsp[(3) - (3)].constant_binder_t)->attributeOf != NULL)
					{
						((Attribute*)(*lIter))->attributeOf = (yyvsp[(3) - (3)].constant_binder_t)->attributeOf;
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
;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 783 "parser.y"
    {
	(yyval.l_constant) = (yyvsp[(1) - (1)].l_constant);
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 787 "parser.y"
    {
	(yyval.l_constant) = (yyvsp[(2) - (3)].l_constant);
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 793 "parser.y"
    {
	// Create a new constant list, add the schema as the first element.
	(yyval.l_constant) = new std::list<Constant*>;
	if((yyvsp[(1) - (1)].constant) != NULL)
	{
		(yyval.l_constant)->push_back((yyvsp[(1) - (1)].constant));
	}
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 802 "parser.y"
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
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 826 "parser.y"
    {
	(yyval.constant) = (yyvsp[(1) - (1)].constant);
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 830 "parser.y"
    {
	(yyval.constant) = (yyvsp[(2) - (3)].constant);
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 836 "parser.y"
    {
	// Create a new Constant from a bare identifier.
	(yyval.constant) = new Constant(*(yyvsp[(1) - (1)].str), Translator::sanitizeConstantName(*(yyvsp[(1) - (1)].str)));
	deallocateItem((yyvsp[(1) - (1)].str));
;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 842 "parser.y"
    {
	// Create a new Constant from a parameterized identifier.
	(yyval.constant) = NULL;
	if((yyvsp[(3) - (4)].l_sort) != NULL)
	{
		(yyval.constant) = new Constant(*(yyvsp[(1) - (4)].str), Translator::sanitizeConstantName(*(yyvsp[(1) - (4)].str)));
		for(std::list<Sort*>::iterator lIter = (yyvsp[(3) - (4)].l_sort)->begin(); lIter != (yyvsp[(3) - (4)].l_sort)->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				(yyval.constant)->params.push_back(*lIter);
			}
		}
		deallocateList((yyvsp[(3) - (4)].l_sort));
	}
	deallocateItem((yyvsp[(1) - (4)].str));
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 863 "parser.y"
    {
	std::vector<std::string> dummyParams;
	(yyval.constant) = mainTrans.getConstant(*(yyvsp[(1) - (1)].str), dummyParams);
	deallocateItem((yyvsp[(1) - (1)].str));
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 869 "parser.y"
    {
	(yyval.constant) = NULL;
	if((yyvsp[(3) - (4)].l_sort) != NULL)
	{
		std::vector<Sort*> constVecParams = utils::elementListToElementVector(*(yyvsp[(3) - (4)].l_sort));
		std::vector<std::string> constParamNames = utils::elementVectorToFullNameVector(constVecParams);
		(yyval.constant) = mainTrans.getConstant(*(yyvsp[(1) - (4)].str), constParamNames);
		deallocateList((yyvsp[(3) - (4)].l_sort));
	}
	deallocateItem((yyvsp[(1) - (4)].str));
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 883 "parser.y"
    {
	(yyval.constant_binder_t) = (yyvsp[(1) - (1)].constant_binder_t);
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 887 "parser.y"
    {
	(yyval.constant_binder_t) = (yyvsp[(2) - (3)].constant_binder_t);
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 893 "parser.y"
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
		std::string domainName = "boolean";
		(yyval.constant_binder_t)->domain = checkDynamicSortDecl(&domainName);
	}
	else
	{	// If it wasn't a real constant type, it's just a shortcut for "rigid(identifier)".
		(yyval.constant_binder_t)->constType = Constant::CONST_RIGID;
		(yyval.constant_binder_t)->domain = checkDynamicSortDecl(&tempIdent);
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
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 932 "parser.y"
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
		(yyval.constant_binder_t)->domain = checkDynamicSortDecl((yyvsp[(3) - (4)].str));
		deallocateItem((yyvsp[(3) - (4)].str));
	}
	if((yyval.constant_binder_t)->domain == NULL)
	{	// Start error mode if anything went wrong.
		deallocateItem((yyval.constant_binder_t));
		YYERROR;
	}
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 955 "parser.y"
    {
	// Attribute binder with Boolean(*) domain.
	(yyval.constant_binder_t) = new PT_constant_binder_t;
	(yyval.constant_binder_t)->constType = Constant::CONST_ATTRIBUTE;
	std::string* domainName = new std::string("boolean*");
	(yyval.constant_binder_t)->domain = checkDynamicSortDecl(domainName);
	deallocateItem(domainName);
	if((yyvsp[(3) - (3)].constant) != NULL)
	{
		(yyval.constant_binder_t)->attributeOf = (yyvsp[(3) - (3)].constant);
	}
	else
	{	// Something's wrong, start error mode.
		deallocateItem((yyval.constant_binder_t));
		YYERROR;
	}
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 973 "parser.y"
    {
	// Attribute binder with given(*) domain.
	(yyval.constant_binder_t) = new PT_constant_binder_t;
	(yyval.constant_binder_t)->constType = Constant::CONST_ATTRIBUTE;
	if((yyvsp[(3) - (6)].str) != NULL)
	{
		std::string* domainName = new std::string(*(yyvsp[(3) - (6)].str));
		(*domainName) += "*";
		(yyval.constant_binder_t)->domain = checkDynamicSortDecl(domainName);
		deallocateItem(domainName);
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
		(yyval.constant_binder_t)->attributeOf = (yyvsp[(6) - (6)].constant);
	}
	if((yyval.constant_binder_t)->domain == NULL || (yyval.constant_binder_t)->attributeOf == NULL)
	{	// If $$'s attributes are NULL, an error happened.
		deallocateItem((yyval.constant_binder_t));
		YYERROR;
	}
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1047 "parser.y"
    {
	// The new style of maxAdditive declaration. Insert a hint comment with the given maxAdditive value.
	if((yyvsp[(4) - (5)].str) != NULL)
	{
		std::string maxAdditiveHint = "% [MaxAdditive:";
		maxAdditiveHint += *((yyvsp[(4) - (5)].str));
		maxAdditiveHint += "]";
		mainTrans.output(maxAdditiveHint, Context::NONE, true);
		(yyval.not_used) = PARSERULE_NOT_USED;
		deallocateItem((yyvsp[(4) - (5)].str));
	}
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1063 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1066 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1067 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1070 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1071 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1074 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1075 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1079 "parser.y"
    {
	// Connect each Object in the list to its sort, (try to) add them to the symbol table, and translate each object.
	Sort* tempSort = NULL;
	bool objectError = false; // Set to true if a serious error happens during object adding.
	if((yyvsp[(1) - (3)].l_object) != NULL && (yyvsp[(3) - (3)].str) != NULL)
	{
		tempSort = mainTrans.getSort(*(yyvsp[(3) - (3)].str));
		if(tempSort != NULL)
		{
			for(std::list<Object*>::iterator lIter = (yyvsp[(1) - (3)].l_object)->begin(); lIter != (yyvsp[(1) - (3)].l_object)->end(); ++lIter)
			{	// Try to add the object to the symbol table (mostly to check for dupes).
			
				if ((*lIter)->isLua) {
					// They appear to have included a LUA call in the object definition. Don't allow this.

					ltsyystartParseError(ltsyylloc);
					ltsyyossErr << "Bad object declaration: \"" << (*lIter)->fullName() << "\". LUA calls may not be present in object declarations!";
					ltsyyreportError();
					deallocateItem(*lIter);
					objectError = true;
					
				} else {
			
					int addSymResult = mainTrans.addObject(*lIter);
					if(addSymResult != SymbolTable::ADDSYM_OK)
					{	// Something went wrong adding the object, skip connecting & translating it.
						if(addSymResult == SymbolTable::ADDSYM_DUP)
						{	// Warn about duplicate object declarations (not an error), then move on.
							ltsyystartCaution(ltsyylloc);
							ltsyyossErr << "Duplicate object declaration: \"" << (*lIter)->fullName() << "\".";
							ltsyyreportCaution();
							deallocateItem(*lIter);
						}
						else
						{	// A real object error.
							ltsyystartParseError(ltsyylloc);
							ltsyyossErr << "Bad object declaration: \"" << (*lIter)->fullName() << "\".";
							ltsyyreportError();
							deallocateItem(*lIter);
							objectError = true;
						}
					}
					else
					{	// Object add went okay, connect the sort to the object and translate them.
						tempSort->domainObjs.push_back(*lIter);
						// Translate each object as we add it to the sort's domain.
						mainTrans.translateObjectDecl(*lIter, tempSort);
					}
				}
			}
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << *(yyvsp[(3) - (3)].str) << "\" not declared, can't use as the target of an object declaration.";
			ltsyyreportError();
			// Deallocate all of the objects in the errant list, they're never going to get used by anything.
			for(std::list<Object*>::iterator lIter = (yyvsp[(1) - (3)].l_object)->begin(); lIter != (yyvsp[(1) - (3)].l_object)->end(); ++lIter)
			{
				deallocateItem(*lIter);
			}
		}
		deallocateList((yyvsp[(1) - (3)].l_object));
		deallocateItem((yyvsp[(3) - (3)].str));
	}
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(tempSort == NULL || objectError == true)
	{	// If the binding sort never got a match or an object had a problem getting added, an error occurred.
		YYERROR;
	}
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 1153 "parser.y"
    {
	(yyval.l_object) = (yyvsp[(1) - (1)].l_object);
;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1157 "parser.y"
    {
	(yyval.l_object) = (yyvsp[(2) - (3)].l_object);
;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1163 "parser.y"
    {
	// Create a new list and make the new object the first element.
	(yyval.l_object) = NULL;
	if((yyvsp[(1) - (1)].object) != NULL)
	{
		(yyval.l_object) = new std::list<Object*>;
		(yyval.l_object)->push_back((yyvsp[(1) - (1)].object));
	}
;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1173 "parser.y"
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
		for(std::list<Object*>::iterator lIter = (yyvsp[(1) - (3)].l_object)->begin(); lIter != (yyvsp[(1) - (3)].l_object)->end(); ++lIter)
		{
			deallocateItem(*lIter);
		}
		deallocateList((yyvsp[(1) - (3)].l_object));
	}
;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1197 "parser.y"
    {
	(yyval.object) = (yyvsp[(1) - (1)].object);
;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1201 "parser.y"
    {
	(yyval.object) = (yyvsp[(2) - (3)].object);
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1207 "parser.y"
    {
	// Create a new Object from a bare identifier.
	(yyval.object) = new Object(*(yyvsp[(1) - (1)].str), Translator::sanitizeObjectName(*(yyvsp[(1) - (1)].str)));
	deallocateItem((yyvsp[(1) - (1)].str));
;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1213 "parser.y"
    {
	// Create a new Object from a parameterized identifier.
	(yyval.object) = new Object(*(yyvsp[(1) - (4)].str), Translator::sanitizeObjectName(*(yyvsp[(1) - (4)].str)));
	if((yyvsp[(3) - (4)].l_sort) != NULL)
	{
		for(std::list<Sort*>::iterator lIter = (yyvsp[(3) - (4)].l_sort)->begin(); lIter != (yyvsp[(3) - (4)].l_sort)->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				(yyval.object)->params.push_back(*lIter);
			}
		}
		deallocateList((yyvsp[(3) - (4)].l_sort));
	}
	deallocateItem((yyvsp[(1) - (4)].str));
;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1230 "parser.y"
    {
	// Create a new object from arbitrary math.
	(yyval.object) = new Object(*(yyvsp[(1) - (1)].str), Translator::sanitizeObjectName(*(yyvsp[(1) - (1)].str)));
	deallocateItem((yyvsp[(1) - (1)].str)); // Free dynamic memory that's not needed anymore.
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1236 "parser.y"
    {
	// Upcast a NumberRange into an Object.
	(yyval.object) = (Object*)(yyvsp[(1) - (1)].numRange);
;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1245 "parser.y"
    {
	if ((yyvsp[(3) - (4)].v_parseElement)) {
		mainTrans.handleShowStmt(*(yyvsp[(3) - (4)].v_parseElement));
	} else {
		YYERROR;
	}
	deallocateList((yyvsp[(3) - (4)].v_parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1258 "parser.y"
    {
	if ((yyvsp[(1) - (1)].parseElement)) {
		(yyval.v_parseElement) = new std::vector<ParseElement*>();
		(yyval.v_parseElement)->push_back((yyvsp[(1) - (1)].parseElement));
	} else {
		(yyval.v_parseElement) = NULL;
	}
	 
;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1268 "parser.y"
    {
	if ((yyvsp[(1) - (3)].v_parseElement)) {
		(yyval.v_parseElement) = (yyvsp[(1) - (3)].v_parseElement);
		if ((yyvsp[(3) - (3)].parseElement)) (yyvsp[(1) - (3)].v_parseElement)->push_back((yyvsp[(3) - (3)].parseElement));
	} else if ((yyvsp[(3) - (3)].parseElement)) {
		(yyval.v_parseElement) = new std::vector<ParseElement*>();
		(yyval.v_parseElement)->push_back((yyvsp[(3) - (3)].parseElement));
	} else {
		(yyval.v_parseElement) = NULL;
	}
;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1282 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1286 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQ;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1304 "parser.y"
    {
	// Deallocate the main sort list of the statement.
	if((yyvsp[(3) - (4)].l_sort) != NULL)
	{
		deallocateList((yyvsp[(3) - (4)].l_sort));
	}
	(yyval.not_used) = PARSERULE_NOT_USED;
;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1315 "parser.y"
    {
	(yyval.l_sort) = (yyvsp[(1) - (1)].l_sort);
;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1319 "parser.y"
    {
	(yyval.l_sort) = (yyvsp[(2) - (3)].l_sort);
;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1325 "parser.y"
    {
	(yyval.l_sort) = new std::list<Sort*>;
	(yyval.l_sort)->push_back((yyvsp[(1) - (1)].sort));
;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1330 "parser.y"
    {
	(yyval.l_sort) = NULL;
	if((yyvsp[(1) - (3)].l_sort) != NULL || (yyvsp[(3) - (3)].l_sort) != NULL)
	{
		(yyval.l_sort) = new std::list<Sort*>;
	}
	// Merge the two sort lists, if they exist.
	if((yyvsp[(1) - (3)].l_sort) != NULL)
	{
		for(std::list<Sort*>::iterator lIter = (yyvsp[(1) - (3)].l_sort)->begin(); lIter != (yyvsp[(1) - (3)].l_sort)->end(); ++lIter)
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
		for(std::list<Sort*>::iterator lIter = (yyvsp[(3) - (3)].l_sort)->begin(); lIter != (yyvsp[(3) - (3)].l_sort)->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				(yyval.l_sort)->push_back((*lIter));
			}
		}
		deallocateList((yyvsp[(3) - (3)].l_sort));
	}
;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1363 "parser.y"
    {
	// Have a helper function handle making and translating the sort.
	std::list<Sort*>* dummyList = new std::list<Sort*>;
	(yyval.sort) = processSort((yyvsp[(1) - (1)].str), dummyList);
	deallocateList(dummyList);
	deallocateItem((yyvsp[(1) - (1)].str));
	if((yyval.sort) == NULL)
	{
		YYERROR;
	}
;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1375 "parser.y"
    {
	// Have a helper function handle making and translating the sort.
	(yyval.sort) = processSort((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].l_sort));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateList((yyvsp[(3) - (3)].l_sort));
	if((yyval.sort) == NULL)
	{
		YYERROR;
	}
;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1388 "parser.y"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1392 "parser.y"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("staticAbnormality");
;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1397 "parser.y"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("dynamicAbnormality");
;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1404 "parser.y"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1408 "parser.y"
    {
	(yyval.str) = (yyvsp[(2) - (3)].str);
;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1416 "parser.y"
    {
	// A standard identifier.
	(yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1421 "parser.y"
    {
	// A quick-and-dirty dynamically declared sort.

	// Turn it into a sort and pass it down the chain.
	if((yyvsp[(1) - (1)].numRange) != NULL)
	{
		(yyval.str) = new std::string();
		*(yyval.str) = Translator::numRangeToSortName((yyvsp[(1) - (1)].numRange)->min, (yyvsp[(1) - (1)].numRange)->max);
		Sort* tempSort = mainTrans.getSort(*(yyval.str));
		if(tempSort == NULL)
		{
			// Have a helper function handle making and translating the sort.
			std::list<Sort*>* dummyList = new std::list<Sort*>; // No subsorts.
			tempSort = processSort((yyval.str), dummyList);
			deallocateList(dummyList);
			// Also add the number range as an object for this new sort.
			int addResult = mainTrans.addObject((yyvsp[(1) - (1)].numRange));
			if(addResult == SymbolTable::ADDSYM_OK)
			{
				tempSort->domainObjs.push_back((yyvsp[(1) - (1)].numRange));
				// Output the translation of the object declaration.
				mainTrans.translateObjectDecl((yyvsp[(1) - (1)].numRange), tempSort);
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
;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1459 "parser.y"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1463 "parser.y"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = (*(yyvsp[(1) - (2)].str)) + "*";
	deallocateItem((yyvsp[(1) - (2)].str));
;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1469 "parser.y"
    {
	// Alternate way to express the idea of a starred sort.
	(yyval.str) = new std::string;
	(*(yyval.str)) = (*(yyvsp[(1) - (3)].str)) + "*";
	deallocateItem((yyvsp[(1) - (3)].str));
;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1478 "parser.y"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1482 "parser.y"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str)
;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1488 "parser.y"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("abAction");
;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1493 "parser.y"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("action");
;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1498 "parser.y"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("additiveAction");
;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1503 "parser.y"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("additiveFluent");
;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1508 "parser.y"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("exogenousAction");
;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1513 "parser.y"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("inertialFluent");
;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1518 "parser.y"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("rigid");
;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1523 "parser.y"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("sdFluent");
;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1528 "parser.y"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("simpleFluent");
;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1536 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1539 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1540 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1543 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1544 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1547 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1548 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1552 "parser.y"
    {
	// Connect the variables in the list to the binding sort, then translate them.
	if((yyvsp[(1) - (3)].l_variable) != NULL && (yyvsp[(3) - (3)].sort) != NULL)
	{
		std::list<Variable*>::iterator vIter;
		for(vIter = (yyvsp[(1) - (3)].l_variable)->begin(); vIter != (yyvsp[(1) - (3)].l_variable)->end(); ++vIter)
		{
			(*vIter)->sortRef = (yyvsp[(3) - (3)].sort);
			mainTrans.translateVariableDecl(*vIter);
		}
	}
	if((yyvsp[(1) - (3)].l_variable) != NULL)
	{	// Clear out the list, we don't need it anymore.
		deallocateList((yyvsp[(1) - (3)].l_variable));
	}
	(yyval.not_used) = PARSERULE_NOT_USED;
;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1572 "parser.y"
    {
	(yyval.l_variable) = (yyvsp[(1) - (1)].l_variable);
;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1576 "parser.y"
    {
	(yyval.l_variable) = (yyvsp[(2) - (3)].l_variable);
;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1582 "parser.y"
    {
	// Create a new list of Variables, add this one as the first item.
	(yyval.l_variable) = new std::list<Variable*>;
	Variable* tempVar = new Variable(*(yyvsp[(1) - (1)].str), Translator::sanitizeVariableName(*(yyvsp[(1) - (1)].str)));
	int addSymResult = mainTrans.addVariable(tempVar);
	if(addSymResult != SymbolTable::ADDSYM_OK)
	{
		if(addSymResult == SymbolTable::ADDSYM_DUP)
		{	// Warn about duplicate variable declarations (not an error), then grab the already-declared variable.
			ltsyystartCaution(ltsyylloc);
			ltsyyossErr << "Duplicate variable declaration: \"" << *(yyvsp[(1) - (1)].str) << "\".";
			ltsyyreportCaution();
			deallocateItem(tempVar);
			tempVar = mainTrans.getVariable(*(yyvsp[(1) - (1)].str));
			(yyval.l_variable)->push_back(tempVar);
		}
		else
		{	// A real variable error.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Bad variable declaration: \"" << *(yyvsp[(1) - (1)].str) << "\".";
			ltsyyreportError();
			deallocateList((yyval.l_variable));
			deallocateItem(tempVar);
		}
	}
	else
	{
		(yyval.l_variable)->push_back(tempVar);
	}
	deallocateItem((yyvsp[(1) - (1)].str));
	if(tempVar == NULL || (yyval.l_variable) == NULL)
	{	// If $$ or tempVar are NULL, something went wrong.
		YYERROR;
	}
;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1618 "parser.y"
    {
	// Merge a new variable declaration into an existing list of variables.
	if((yyvsp[(1) - (3)].l_variable) == NULL)
	{
		(yyval.l_variable) = new std::list<Variable*>;
	}
	Variable* tempVar = new Variable(*(yyvsp[(3) - (3)].str), Translator::sanitizeVariableName(*(yyvsp[(3) - (3)].str)));
	int addSymResult = mainTrans.addVariable(tempVar);
	if(addSymResult != SymbolTable::ADDSYM_OK)
	{
		if(addSymResult == SymbolTable::ADDSYM_DUP)
		{	// Warn about duplicate variable declarations (not an error), then grab the already-declared variable.
			ltsyystartCaution(ltsyylloc);
			ltsyyossErr << "Duplicate variable declaration: \"" << *(yyvsp[(3) - (3)].str) << "\".";
			ltsyyreportCaution();
			deallocateItem(tempVar);
			tempVar = mainTrans.getVariable(*(yyvsp[(3) - (3)].str));
			(yyval.l_variable)->push_back(tempVar);
		}
		else
		{	// A real variable error.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Bad variable declaration: \"" << *(yyvsp[(3) - (3)].str) << "\".";
			ltsyyreportError();
			deallocateItem(tempVar);
		}
	}
	else
	{
		(yyval.l_variable)->push_back(tempVar);
	}
	deallocateItem((yyvsp[(3) - (3)].str));
	if(tempVar == NULL)
	{	// If tempVar is NULL, something went wrong.
		YYERROR;
	}
;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1658 "parser.y"
    {
	// Find the sort in question, create it if it doesn't exist and is a "something*" sort (whose "something" exists already), or report an error.
	(yyval.sort) = mainTrans.getSort(*(yyvsp[(1) - (1)].str));
	if((yyval.sort) == NULL)
	{
		(yyval.sort) = checkDynamicSortDecl((yyvsp[(1) - (1)].str)); // Reports appropriate errors, we just need to YYERROR if that happens.
	}
	deallocateItem((yyvsp[(1) - (1)].str));
	if((yyval.sort) == NULL)
	{	// If $$ is NULL, something went wrong.
		YYERROR;
	}
;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1712 "parser.y"
    { (yyval.parseElement) = NULL; ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1713 "parser.y"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1716 "parser.y"
    { (yyval.parseElement) = NULL; ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1717 "parser.y"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1720 "parser.y"
    { (yyval.parseElement) = NULL; ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1721 "parser.y"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1724 "parser.y"
    { (yyval.parseElement) = NULL; ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1725 "parser.y"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1728 "parser.y"
    { (yyval.parseElement) = NULL; ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1729 "parser.y"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1732 "parser.y"
    { (yyval.parseElement) = NULL; ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1733 "parser.y"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1736 "parser.y"
    { (yyval.parseElement) = NULL; ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1737 "parser.y"
    { (yyval.parseElement) = (yyvsp[(2) - (2)].parseElement);   ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1743 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1744 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1747 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1748 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1749 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1750 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1751 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1752 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1753 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1754 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1755 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1756 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1757 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1758 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1759 "parser.y"
    { (yyval.not_used) = PARSERULE_NOT_USED; ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1764 "parser.y"
    {
	bool transResult = handleAlwaysLaw((yyvsp[(2) - (4)].parseElement), (yyvsp[(3) - (4)].parseElement), (yyvsp[(4) - (4)].parseElement));
	deallocateItem((yyvsp[(2) - (4)].parseElement));
	deallocateItem((yyvsp[(3) - (4)].parseElement));
	deallocateItem((yyvsp[(4) - (4)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1778 "parser.y"
    {
	bool transResult = handleConstraintLaw((yyvsp[(2) - (7)].parseElement), (yyvsp[(3) - (7)].parseElement), (yyvsp[(4) - (7)].parseElement), (yyvsp[(5) - (7)].parseElement), (yyvsp[(6) - (7)].parseElement), (yyvsp[(7) - (7)].parseElement), true);
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
;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1793 "parser.y"
    {
	bool transResult = handleConstraintLaw((yyvsp[(2) - (7)].parseElement), (yyvsp[(3) - (7)].parseElement), (yyvsp[(4) - (7)].parseElement), (yyvsp[(5) - (7)].parseElement), (yyvsp[(6) - (7)].parseElement), (yyvsp[(7) - (7)].parseElement), false);
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
;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1808 "parser.y"
    {
	bool transResult = handleConstraintLaw((yyvsp[(2) - (7)].parseElement), (yyvsp[(3) - (7)].parseElement), (yyvsp[(4) - (7)].parseElement), (yyvsp[(5) - (7)].parseElement), (yyvsp[(6) - (7)].parseElement), (yyvsp[(7) - (7)].parseElement), false);
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
;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1825 "parser.y"
    {
	bool transResult = handleDefaultLaw((yyvsp[(2) - (9)].parseElement), (yyvsp[(3) - (9)].parseElement), (yyvsp[(4) - (9)].parseElement), (yyvsp[(5) - (9)].parseElement), (yyvsp[(6) - (9)].parseElement), (yyvsp[(7) - (9)].parseElement), (yyvsp[(8) - (9)].parseElement), (yyvsp[(9) - (9)].parseElement));
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
;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1844 "parser.y"
    {
	bool transResult = handleDeclarativeLaw((yyvsp[(2) - (3)].parseElement), NULL, NULL, NULL, NULL, NULL, NULL, (yyvsp[(3) - (3)].parseElement), SimpleUnaryOperator::UOP_EXOGENOUS);
	deallocateItem((yyvsp[(2) - (3)].parseElement));
	deallocateItem((yyvsp[(3) - (3)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1857 "parser.y"
    {
	bool transResult = handleDeclarativeLaw((yyvsp[(2) - (3)].parseElement), NULL, NULL, NULL, NULL, NULL, NULL, (yyvsp[(3) - (3)].parseElement), SimpleUnaryOperator::UOP_INERTIAL);
	deallocateItem((yyvsp[(2) - (3)].parseElement));
	deallocateItem((yyvsp[(3) - (3)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1870 "parser.y"
    {
	bool transResult = handleNonexecutableLaw((yyvsp[(2) - (5)].parseElement), (yyvsp[(3) - (5)].parseElement), (yyvsp[(4) - (5)].parseElement), (yyvsp[(5) - (5)].parseElement));
	deallocateItem((yyvsp[(2) - (5)].parseElement));
	deallocateItem((yyvsp[(3) - (5)].parseElement));
	deallocateItem((yyvsp[(4) - (5)].parseElement));
	deallocateItem((yyvsp[(5) - (5)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1885 "parser.y"
    {
	/*
	 * Let's _try_ to handle this, but we should throw a warning as this statement is not fully supported.
	 */

	ltsyystartWarning(ltsyylloc);
	ltsyyossErr << "Rules of the form \"rigid p [where F]\" are not fully supported and may produce unintended behavior. Please declare the constant as rigid instead.";
	ltsyyreportWarning();

	bool transResult = handleDeclarativeLaw((yyvsp[(2) - (3)].parseElement), NULL, NULL, NULL, NULL, NULL, NULL, (yyvsp[(3) - (3)].parseElement), SimpleUnaryOperator::UOP_RIGID);
	deallocateItem((yyvsp[(2) - (3)].parseElement));
	deallocateItem((yyvsp[(3) - (3)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1906 "parser.y"
    {
	bool transResult = handlePossiblyCausedLaw((yyvsp[(2) - (9)].parseElement), (yyvsp[(3) - (9)].parseElement), (yyvsp[(4) - (9)].parseElement), (yyvsp[(5) - (9)].parseElement), (yyvsp[(6) - (9)].parseElement), (yyvsp[(7) - (9)].parseElement), (yyvsp[(8) - (9)].parseElement), (yyvsp[(9) - (9)].parseElement));
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
;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1925 "parser.y"
    {
	bool transResult = handleMayCauseLaw((yyvsp[(1) - (6)].parseElement), (yyvsp[(3) - (6)].parseElement), (yyvsp[(4) - (6)].parseElement), (yyvsp[(5) - (6)].parseElement), (yyvsp[(6) - (6)].parseElement));
	deallocateItem((yyvsp[(1) - (6)].parseElement));
	deallocateItem((yyvsp[(3) - (6)].parseElement));
	deallocateItem((yyvsp[(4) - (6)].parseElement));
	deallocateItem((yyvsp[(5) - (6)].parseElement));
	deallocateItem((yyvsp[(6) - (6)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1941 "parser.y"
    {
	bool transResult = handleCausesLaw((yyvsp[(1) - (6)].parseElement), (yyvsp[(3) - (6)].parseElement), (yyvsp[(4) - (6)].parseElement), (yyvsp[(5) - (6)].parseElement), (yyvsp[(6) - (6)].parseElement));
	deallocateItem((yyvsp[(1) - (6)].parseElement));
	deallocateItem((yyvsp[(3) - (6)].parseElement));
	deallocateItem((yyvsp[(4) - (6)].parseElement));
	deallocateItem((yyvsp[(5) - (6)].parseElement));
	deallocateItem((yyvsp[(6) - (6)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1957 "parser.y"
    {
	// This one's easy, it's just a pass-through.
	mainTrans.output("noconcurrency.", Context::BASE, true);
	(yyval.not_used) = PARSERULE_NOT_USED;
;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1963 "parser.y"
    {
	// This one is also very easy.
	mainTrans.output("strong_noconcurrency.", Context::BASE, true);
	(yyval.not_used) = PARSERULE_NOT_USED;
;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1971 "parser.y"
    {
	bool transResult = handleIncrementLaw((yyvsp[(1) - (8)].parseElement), (yyvsp[(3) - (8)].parseElement), (yyvsp[(5) - (8)].parseElement), (yyvsp[(6) - (8)].parseElement), (yyvsp[(7) - (8)].parseElement), (yyvsp[(8) - (8)].parseElement), true);
	deallocateItem((yyvsp[(1) - (8)].parseElement));
	deallocateItem((yyvsp[(3) - (8)].parseElement));
	deallocateItem((yyvsp[(5) - (8)].parseElement));
	deallocateItem((yyvsp[(6) - (8)].parseElement));
	deallocateItem((yyvsp[(7) - (8)].parseElement));
	deallocateItem((yyvsp[(8) - (8)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	
	if(!transResult)
	{
		YYERROR;
	}
;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1987 "parser.y"
    {
	bool transResult = handleIncrementLaw((yyvsp[(1) - (8)].parseElement), (yyvsp[(3) - (8)].parseElement), (yyvsp[(5) - (8)].parseElement), (yyvsp[(6) - (8)].parseElement), (yyvsp[(7) - (8)].parseElement), (yyvsp[(8) - (8)].parseElement), false);
	deallocateItem((yyvsp[(1) - (8)].parseElement));
	deallocateItem((yyvsp[(3) - (8)].parseElement));
	deallocateItem((yyvsp[(5) - (8)].parseElement));
	deallocateItem((yyvsp[(6) - (8)].parseElement));
	deallocateItem((yyvsp[(7) - (8)].parseElement));
	deallocateItem((yyvsp[(8) - (8)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	
	if(!transResult)
	{
		YYERROR;
	}
;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 2005 "parser.y"
    {
	// This is a law of the form c=v.
	// Which is really just a lazy shortcut for
	// caused c=v.

	mainTrans.translateCausalLaw((yyvsp[(1) - (1)].parseElement), NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	deallocateItem((yyvsp[(1) - (1)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 2017 "parser.y"
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
;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 2032 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 2036 "parser.y"
    {
	ObjectLikeElement* tempPE = new ObjectLikeElement();
	tempPE->baseName = "true";
	tempPE->objRef = mainTrans.getObjectLike(tempPE->baseName, 0);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 2043 "parser.y"
    {
	ObjectLikeElement* tempPE = new ObjectLikeElement();
	tempPE->baseName = "false";
	tempPE->objRef = mainTrans.getObjectLike(tempPE->baseName, 0);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 2052 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 2056 "parser.y"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->setParens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 2066 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 2070 "parser.y"
    {
	SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
	tempPE->opType = SimpleUnaryOperator::UOP_NOT;
	tempPE->postOp = (yyvsp[(2) - (2)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 2077 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_AND;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 2085 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_OR;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 2093 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQUIV;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 2101 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_IMPL;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 2111 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 2115 "parser.y"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->setParens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 2125 "parser.y"
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
;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 2144 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQ;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 2152 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_NEQ;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 2160 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	// A bunch of possible operators bundle into COMPARISON. Find out which one.
	switch((yyvsp[(2) - (3)].integer))
	{
	case T_DBL_EQ:
		tempPE->opType = SimpleBinaryOperator::BOP_DBL_EQ;
		break;
	case T_LTHAN:
		tempPE->opType = SimpleBinaryOperator::BOP_LTHAN;
		break;
	case T_GTHAN:
		tempPE->opType = SimpleBinaryOperator::BOP_GTHAN;
		break;
	case T_EQ_LTHAN:
		tempPE->opType = SimpleBinaryOperator::BOP_LTHAN_EQ;
		break;
	case T_GTHAN_EQ:
		tempPE->opType = SimpleBinaryOperator::BOP_GTHAN_EQ;
		break;
	default:
		tempPE->opType = SimpleBinaryOperator::BOP_UNKNOWN;
	}
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 2188 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 2194 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 2200 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 2206 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 2212 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 2216 "parser.y"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->setParens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 2226 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 2230 "parser.y"
    {
	SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
	tempPE->opType = SimpleUnaryOperator::UOP_NOT;
	tempPE->postOp = (yyvsp[(2) - (2)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 2237 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_AND;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 2245 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_OR;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 2253 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQUIV;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 2261 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_IMPL;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 2271 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 2275 "parser.y"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->setParens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 2285 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
	if((yyval.parseElement) == NULL)
	{
		YYERROR;
	}
;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 2293 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 2299 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 2303 "parser.y"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->setParens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 2313 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 2317 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_AND;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 2327 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 2331 "parser.y"
    {
	SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
	tempPE->opType = SimpleUnaryOperator::UOP_NOT;
	tempPE->postOp = (yyvsp[(2) - (2)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 2338 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQ;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 2348 "parser.y"
    {
	(yyval.parseElement) = NULL;
	if((yyvsp[(2) - (5)].l_quantPair) != NULL && (yyvsp[(4) - (5)].parseElement) != NULL)
	{
		BigQuantifiers* tempPE = new BigQuantifiers();
		tempPE->quants = *(yyvsp[(2) - (5)].l_quantPair);
		tempPE->postOp = (yyvsp[(4) - (5)].parseElement);
		deallocateList((yyvsp[(2) - (5)].l_quantPair));
		(yyval.parseElement) = tempPE;
	}
;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 2362 "parser.y"
    {
	(yyval.parseElement) = NULL;
	if((yyvsp[(2) - (5)].l_quantPair) != NULL && (yyvsp[(4) - (5)].parseElement) != NULL)
	{
		BigQuantifiers* tempPE = new BigQuantifiers();
		tempPE->quants = *(yyvsp[(2) - (5)].l_quantPair);
		tempPE->postOp = (yyvsp[(4) - (5)].parseElement);
		deallocateList((yyvsp[(2) - (5)].l_quantPair));
		(yyval.parseElement) = tempPE;
	}
;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 2376 "parser.y"
    {
	(yyval.l_quantPair) = NULL;
	if((yyvsp[(1) - (1)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = new std::list<std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>* >();
		(yyval.l_quantPair)->push_back((yyvsp[(1) - (1)].p_quantPair));
	}
;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 2385 "parser.y"
    {
	(yyval.l_quantPair) = NULL;
	if((yyvsp[(1) - (1)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = new std::list<std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>* >();
		(yyval.l_quantPair)->push_back((yyvsp[(1) - (1)].p_quantPair));
	}
;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 2394 "parser.y"
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
			for(std::list<std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>* >::iterator lIter = (yyvsp[(1) - (2)].l_quantPair)->begin(); lIter != (yyvsp[(1) - (2)].l_quantPair)->end(); ++lIter)
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
;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 2426 "parser.y"
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
			for(std::list<std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>* >::iterator lIter = (yyvsp[(1) - (2)].l_quantPair)->begin(); lIter != (yyvsp[(1) - (2)].l_quantPair)->end(); ++lIter)
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
;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 2460 "parser.y"
    {
	(yyval.p_quantPair) = new std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>();
	(yyval.p_quantPair)->first = BigQuantifiers::QUANT_CONJ;
	// That identifier better be a variable...
	Variable* varRef = mainTrans.getVariableLike(*(yyvsp[(2) - (2)].str));
	if(varRef == NULL)
	{
		// It's not. We should tell them.
		// First. Let's figure out exactly what kind of error it is...
		if (mainTrans.getConstantLike(*(yyvsp[(2) - (2)].str),0) || mainTrans.getObjectLike(*(yyvsp[(2) - (2)].str),0)) {
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
		varRef = new Variable();
		varRef->name = *(yyvsp[(2) - (2)].str);
		varRef->transName = Translator::sanitizeVariableName(*(yyvsp[(2) - (2)].str));
		
		VariableLikeElement* tempPE = new VariableLikeElement();
		tempPE->baseName = *(yyvsp[(2) - (2)].str);
		tempPE->varRef = varRef;
		(yyval.p_quantPair)->second = tempPE;
		
		
	}
	else
	{
		VariableLikeElement* tempPE = new VariableLikeElement();
		tempPE->baseName = *(yyvsp[(2) - (2)].str);
		tempPE->varRef = varRef;
		(yyval.p_quantPair)->second = tempPE;
	}
	deallocateItem((yyvsp[(2) - (2)].str));
;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 2505 "parser.y"
    {
	(yyval.p_quantPair) = new std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>();
	(yyval.p_quantPair)->first = BigQuantifiers::QUANT_DISJ;
	// Guess that the identifier is a variable, otherwise just default to object.
	Variable* varRef = mainTrans.getVariableLike(*(yyvsp[(2) - (2)].str));
	if(varRef == NULL)
	{
		// It's not. We should tell them.
		// First. Let's figure out exactly what kind of error it is...
		if (mainTrans.getConstantLike(*(yyvsp[(2) - (2)].str),0) || mainTrans.getObjectLike(*(yyvsp[(2) - (2)].str),0)) {
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
		varRef = new Variable();
		varRef->name = *(yyvsp[(2) - (2)].str);
		varRef->transName = Translator::sanitizeVariableName(*(yyvsp[(2) - (2)].str));
		
		VariableLikeElement* tempPE = new VariableLikeElement();
		tempPE->baseName = *(yyvsp[(2) - (2)].str);
		tempPE->varRef = varRef;
		(yyval.p_quantPair)->second = tempPE;
		
	}
	else
	{
		VariableLikeElement* tempPE = new VariableLikeElement();
		tempPE->baseName = *(yyvsp[(2) - (2)].str);
		tempPE->varRef = varRef;
		(yyval.p_quantPair)->second = tempPE;
	}
	deallocateItem((yyvsp[(2) - (2)].str));
;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 2551 "parser.y"
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
;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 2580 "parser.y"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 2584 "parser.y"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 2590 "parser.y"
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
;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 2605 "parser.y"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(mainTrans.tempQuery->maxstep == "")
	{
		mainTrans.tempQuery->maxstep = utils::to_string((yyvsp[(3) - (3)].integer));
	}
	else
	{
		ltsyystartParseError(ltsyylloc);
		ltsyyossErr << "maxstep already defined as \"" << mainTrans.tempQuery->maxstep << "\" in this query, can only define it once per query.";
		ltsyyreportError();
		YYERROR;
	}
;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 2620 "parser.y"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	// Explicit declaration of a limited form of a number range that only supports (positive) integers as its bounds.
	if(mainTrans.tempQuery->maxstep == "")
	{
		mainTrans.tempQuery->maxstep = utils::to_string((yyvsp[(3) - (5)].integer));
		mainTrans.tempQuery->maxstep += "..";
		mainTrans.tempQuery->maxstep += utils::to_string((yyvsp[(5) - (5)].integer));
	}
	else
	{
		ltsyystartParseError(ltsyylloc);
		ltsyyossErr << "maxstep already defined as \"" << mainTrans.tempQuery->maxstep << "\" in this query, can only define it once per query.";
		ltsyyreportError();
		YYERROR;
	}
;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 2638 "parser.y"
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
;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 2656 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 2660 "parser.y"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->setParens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 2668 "parser.y"
    {
	// Turn the time stamp into a plain, translated string representation, then propogate it through the body formula.
	std::string tempTimeStamp = "UNKNOWN";
	if((yyvsp[(1) - (3)].parseElement) != NULL)
	{
		ClauseList throwaway;
		tempTimeStamp =  Translator::sanitizeObjectName(((ObjectLikeElement*)(yyvsp[(1) - (3)].parseElement))->baseName);
		deallocateItem((yyvsp[(1) - (3)].parseElement));
	}
	if((yyvsp[(3) - (3)].parseElement) != NULL)
	{
		(yyvsp[(3) - (3)].parseElement)->setQueryTimeStamp(tempTimeStamp);
	}
	else
	{
		ltsyystartWarning(ltsyylloc);
		ltsyyossErr << "Query body formula with time stamp \"" << tempTimeStamp << "\" is NULL!";
		ltsyyreportWarning();
	}
	(yyval.parseElement) = (yyvsp[(3) - (3)].parseElement);
;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 2692 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 2696 "parser.y"
    {
	SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
	tempPE->opType = SimpleUnaryOperator::UOP_NOT;
	tempPE->postOp = (yyvsp[(2) - (2)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 2703 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_AND;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 2711 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_OR;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 2719 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQUIV;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 2727 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_IMPL;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 2737 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 2741 "parser.y"
    {
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyvsp[(2) - (3)].parseElement)->setParens(true);
	}
	(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 2751 "parser.y"
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
;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 2770 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQ;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 2778 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_NEQ;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 2786 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	// A bunch of possible operators bundle into COMPARISON. Find out which one.
	switch((yyvsp[(2) - (3)].integer))
	{
	case T_DBL_EQ:
		tempPE->opType = SimpleBinaryOperator::BOP_DBL_EQ;
		break;
	case T_LTHAN:
		tempPE->opType = SimpleBinaryOperator::BOP_LTHAN;
		break;
	case T_GTHAN:
		tempPE->opType = SimpleBinaryOperator::BOP_GTHAN;
		break;
	case T_EQ_LTHAN:
		tempPE->opType = SimpleBinaryOperator::BOP_LTHAN_EQ;
		break;
	case T_GTHAN_EQ:
		tempPE->opType = SimpleBinaryOperator::BOP_GTHAN_EQ;
		break;
	default:
		tempPE->opType = SimpleBinaryOperator::BOP_UNKNOWN;
	}
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 2814 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 2820 "parser.y"
    {
	(yyval.parseElement) = NULL;
	if((yyvsp[(2) - (5)].l_quantPair) != NULL && (yyvsp[(4) - (5)].parseElement) != NULL)
	{
		BigQuantifiers* tempPE = new BigQuantifiers();
		tempPE->quants = *(yyvsp[(2) - (5)].l_quantPair);
		tempPE->postOp = (yyvsp[(4) - (5)].parseElement);
		deallocateList((yyvsp[(2) - (5)].l_quantPair));
		(yyval.parseElement) = tempPE;
	}
;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 2836 "parser.y"
    {
	// Guess what kind of instance this might be, go with the best match.
	// Guess variable, then constant, then try object.
	Variable* varRef = mainTrans.getVariableLike(*(yyvsp[(2) - (2)].str));
	if(varRef == NULL)
	{
		Constant* constRef = mainTrans.getConstantLike(*(yyvsp[(2) - (2)].str),0);
		if(constRef == NULL || (yyvsp[(1) - (2)].str) != NULL)
		{
			Object* objRef = mainTrans.getObjectLike(*(yyvsp[(2) - (2)].str),0, (yyvsp[(1) - (2)].str) != NULL);
			
			if (objRef == NULL) {
				// This doesn't appear to be a declared identifier.
				// Bitch.
				
				ltsyystartParseError(ltsyylloc);
				ltsyyossErr << "\"" << *(yyvsp[(2) - (2)].str) << "\" appears to be undeclared.";
				ltsyyreportError();
				(yyval.parseElement) = NULL;
				
				// For the sake of system stability, we'll return an object.z
				ObjectLikeElement* tempPE = new ObjectLikeElement();
				tempPE->baseName = *(yyvsp[(2) - (2)].str);
				tempPE->objRef = objRef;
				(yyval.parseElement) = tempPE;
			
			}
			ObjectLikeElement* tempPE = new ObjectLikeElement();
			tempPE->baseName = *(yyvsp[(2) - (2)].str);
			tempPE->objRef = objRef;
			(yyval.parseElement) = tempPE;
		}
		else
		{
			ConstantLikeElement* tempPE = new ConstantLikeElement();
			tempPE->baseName = *(yyvsp[(2) - (2)].str);
			tempPE->constRef = constRef;
			(yyval.parseElement) = tempPE;
		}
	}
	else
	{
		VariableLikeElement* tempPE = new VariableLikeElement();
		tempPE->baseName = *(yyvsp[(2) - (2)].str);
		tempPE->varRef = varRef;
		(yyval.parseElement) = tempPE;
	}
	deallocateItem((yyvsp[(1) - (2)].str));
	deallocateItem((yyvsp[(2) - (2)].str));
;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 2887 "parser.y"
    {
	// Guess what kind of instance this might be, go with the best match.
	// Guess constant, then try object.
	Constant* constRef = mainTrans.getConstantLike(*(yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].v_parseElement)->size());
	if(constRef == NULL || (yyvsp[(1) - (5)].str) != NULL)
	{
		Object* objRef = mainTrans.getObjectLike(*(yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].v_parseElement)->size(), (yyvsp[(1) - (5)].str) != NULL);
		
		if (objRef == NULL) {
			// This doesn't appear to be a declared identifier.
			// Bitch.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << *(yyvsp[(2) - (5)].str) << "\" appears to be undeclared.";
			ltsyyreportError();
			(yyval.parseElement) = NULL;
			
			// For the sake of system stability, we'll return an object.
			ObjectLikeElement* tempPE = new ObjectLikeElement();
			tempPE->baseName = *(yyvsp[(2) - (5)].str);
			tempPE->objRef = objRef;
			tempPE->params = *(yyvsp[(4) - (5)].v_parseElement);
			(yyval.parseElement) = tempPE;
				
		
		}
		
		ObjectLikeElement* tempPE = new ObjectLikeElement();
		tempPE->baseName = *(yyvsp[(2) - (5)].str);
		tempPE->objRef = objRef;
		(yyval.parseElement) = tempPE;
	}
	else
	{
		ConstantLikeElement* tempPE = new ConstantLikeElement();
		tempPE->baseName = *(yyvsp[(2) - (5)].str);
		tempPE->constRef = constRef;
		(yyval.parseElement) = tempPE;
	}
	// Add the parameters.
	if((yyvsp[(4) - (5)].v_parseElement) != NULL)
	{
		for(std::vector<ParseElement*>::iterator vIter = (yyvsp[(4) - (5)].v_parseElement)->begin(); vIter != (yyvsp[(4) - (5)].v_parseElement)->end(); ++vIter)
		{
			((BaseLikeElement*)(yyval.parseElement))->params.push_back(*vIter);
		}
	}
	deallocateItem((yyvsp[(1) - (5)].str));
	deallocateItem((yyvsp[(2) - (5)].str));
	deallocateList((yyvsp[(4) - (5)].v_parseElement));
;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 2940 "parser.y"
    { (yyval.str) = NULL; ;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 2941 "parser.y"
    { (yyval.str) = new std::string("@"); ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 2944 "parser.y"
    {
	(yyval.v_parseElement) = NULL;
	if((yyvsp[(1) - (1)].parseElement) != NULL)
	{
		(yyval.v_parseElement) = new std::vector<ParseElement*>();
		(yyval.v_parseElement)->push_back((yyvsp[(1) - (1)].parseElement));
	}
;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 2953 "parser.y"
    {
	(yyval.v_parseElement) = NULL;
	if((yyvsp[(1) - (3)].v_parseElement) != NULL && (yyvsp[(3) - (3)].parseElement) != NULL)
	{
		(yyval.v_parseElement) = (yyvsp[(1) - (3)].v_parseElement);
		(yyval.v_parseElement)->push_back((yyvsp[(3) - (3)].parseElement));
	}
;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 2964 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 2970 "parser.y"
    {
	Sort* tempSort = mainTrans.getSort(*(yyvsp[(1) - (1)].str));
	(yyval.l_sort) = NULL;
	if(tempSort != NULL)
	{
		(yyval.l_sort) = new std::list<Sort*>;
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
;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 2991 "parser.y"
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
;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 3018 "parser.y"
    {
	ObjectLikeElement* tempPE = new ObjectLikeElement();
	tempPE->baseName = "true";
	tempPE->objRef = mainTrans.getObjectLike(tempPE->baseName, 0);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 3025 "parser.y"
    {
	ObjectLikeElement* tempPE = new ObjectLikeElement();
	tempPE->baseName = "false";
	tempPE->objRef = mainTrans.getObjectLike(tempPE->baseName, 0);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 3032 "parser.y"
    {
	ObjectLikeElement* tempPE = new ObjectLikeElement();
	tempPE->baseName = "none";
	tempPE->objRef = mainTrans.getObjectLike(tempPE->baseName, 0);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 3039 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 3045 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 3049 "parser.y"
    {
	(yyval.parseElement) = NULL;
	if((yyvsp[(2) - (3)].parseElement) != NULL)
	{
		(yyval.parseElement) = (yyvsp[(2) - (3)].parseElement);
		(yyval.parseElement)->setParens(true);
	}
;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 3060 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 3064 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_PLUS;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 3072 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_MINUS;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 3080 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_TIMES;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 3088 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_DIVIDE;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 3096 "parser.y"
    {
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_MOD;
	tempPE->preOp = (yyvsp[(1) - (3)].parseElement);
	tempPE->postOp = (yyvsp[(3) - (3)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 3104 "parser.y"
    {
	SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
	tempPE->opType = SimpleUnaryOperator::UOP_ABS;
	tempPE->postOp = (yyvsp[(2) - (2)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 3111 "parser.y"
    {
	// Not necessary to flag parenBefore and parenAfter, translation of abs
	// automatically adds parentheses around the expression.
	SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
	tempPE->opType = SimpleUnaryOperator::UOP_ABS;
	tempPE->postOp = (yyvsp[(3) - (4)].parseElement);
	(yyval.parseElement) = tempPE;
;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 3122 "parser.y"
    {
	ObjectLikeElement* tempPE = new ObjectLikeElement();
	tempPE->baseName = *(yyvsp[(1) - (1)].str);
	tempPE->objRef = mainTrans.getObjectLike(tempPE->baseName, 0);
	(yyval.parseElement) = tempPE;
	deallocateItem((yyvsp[(1) - (1)].str));
;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 3130 "parser.y"
    {
	(yyval.parseElement) = (yyvsp[(1) - (1)].parseElement);
;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 3136 "parser.y"
    {
	(yyval.numRange) = new NumberRange();
	std::string tempStr = (*(yyvsp[(1) - (3)].str));
	tempStr += "..";
	tempStr += (*(yyvsp[(3) - (3)].str));
	(yyval.numRange)->name = tempStr;
	(yyval.numRange)->transName = Translator::sanitizeObjectName(tempStr);
	(yyval.numRange)->min = (*(yyvsp[(1) - (3)].str));
	(yyval.numRange)->max = (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 3151 "parser.y"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) = utils::to_string((yyvsp[(1) - (1)].integer));
;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 3156 "parser.y"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = "maxAdditive";
;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 3161 "parser.y"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = "maxstep";
;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 3166 "parser.y"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) = "-";
	(*(yyval.str)) += (*(yyvsp[(2) - (2)].str));
	deallocateItem((yyvsp[(2) - (2)].str));
;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 3175 "parser.y"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 3179 "parser.y"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += "(";
	(*(yyval.str)) += (*(yyvsp[(2) - (3)].str));
	(*(yyval.str)) += ")";
	deallocateItem((yyvsp[(2) - (3)].str));
;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 3189 "parser.y"
    {
	(yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 3193 "parser.y"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " + ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 3202 "parser.y"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " - ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 3211 "parser.y"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " * ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 3220 "parser.y"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " // ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 3229 "parser.y"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yyvsp[(1) - (3)].str));
	(*(yyval.str)) += " mod ";
	(*(yyval.str)) += (*(yyvsp[(3) - (3)].str));
	deallocateItem((yyvsp[(1) - (3)].str));
	deallocateItem((yyvsp[(3) - (3)].str));
;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 3241 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 3245 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 3249 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 3255 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 3261 "parser.y"
    {
	(yyval.integer) = T_UMINUS;
;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 3265 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 3271 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 3277 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 3281 "parser.y"
    {
	// This means "less than in sorted order", which can be safely approximated with !=.
	(yyval.integer) = (yyvsp[(2) - (2)].integer);
;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 3286 "parser.y"
    {
	// This means "greater than in sorted order", which can be safely approximated with !=.
	(yyval.integer) = (yyvsp[(2) - (2)].integer);
;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 3293 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 3297 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 3301 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 3305 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 3309 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 3315 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 3321 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 3327 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 3331 "parser.y"
    {
	// This means "less than or equal to in sorted order", which has no good approximation except for <=.
	(yyval.integer) = (yyvsp[(2) - (2)].integer);
;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 3338 "parser.y"
    {
	(yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 3342 "parser.y"
    {
	// This means "greater than or equal to in sorted order", which has no good approximation except for >=.
	(yyval.integer) = (yyvsp[(2) - (2)].integer);
;}
    break;



/* Line 1455 of yacc.c  */
#line 6695 "parser.cpp"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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

  yyerror_range[0] = yylsp[1-yylen];
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
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
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



/* Line 1675 of yacc.c  */
#line 3348 "parser.y"


// Tries to create a Sort out of an identifier and (possibly empty) subsort list.
Sort* processSort(std::string* sortIdent, std::list<Sort*>* subsorts)
{
	Sort* retVal = NULL;
	bool alreadyDeclared = true;
	// Add the sort if it isn't already in the symbol table.
	retVal = mainTrans.getSort(*sortIdent);
	if(retVal == NULL)
	{
		alreadyDeclared = false;
		retVal = new Sort(*sortIdent, Translator::sanitizeSortName(*sortIdent));
		int addSymResult = mainTrans.addSort(retVal);
		if(addSymResult != SymbolTable::ADDSYM_OK)
		{
			if(addSymResult == SymbolTable::ADDSYM_DUP)
			{	// Warn about duplicate sort declarations (not an error), then grab the already-declared sort.
				// Shouldn't encounter this bit of code, the getSort call earlier should take care of the "already exists" case.
				ltsyystartCaution(ltsyylloc);
				ltsyyossErr << "Duplicate sort declaration: \"" << *sortIdent << "\".";
				ltsyyreportCaution();
				deallocateItem(retVal);
				retVal = mainTrans.getSort(*sortIdent);
				alreadyDeclared = true;
			}
			else
			{	// Report a real sort error.
				ltsyystartParseError(ltsyylloc);
				ltsyyossErr << "Bad sort declaration: \"" << *sortIdent << "\".";
				ltsyyreportError();
				deallocateItem(retVal);
			}
		}
		else
		{
			// Create for ourselves a new default variable.
			// Note: We used to try to retrieve an already-defined variable, however this
			//       may cause variable conflicts in some cases (as we're using a variable they're using).

			std::string tempName = retVal->fullName();
			std::string tempTransName = retVal->fullTransName();
			std::string tempVarName = Translator::sortNameToVariable(tempName);

			std::string tempTransVarName = Translator::sortNameToVariable(tempTransName);
			Variable* tempVar = new Variable(tempVarName, tempTransVarName);


			int stat, i = 0;

			// Handle possible duplicates by appending a counter to the end of the variable.
			while ((stat = mainTrans.addVariable(tempVar)) == SymbolTable::ADDSYM_DUP) {
				i++;
				tempVar->name = tempVarName + utils::to_string(i);
				tempVar->transName = tempTransVarName + utils::to_string(i);
			}


			if( stat != SymbolTable::ADDSYM_OK )
			{
				// Something went very very wrong.
				deallocateItem(tempVar);
				ltsyystartParseError(ltsyylloc);
				ltsyyossErr << "Could not create default variable \"" << tempVarName << "\" ";
				ltsyyossErr << "for sort \"" << tempName << "\".";
				ltsyyreportError();
				retVal = NULL; // Won't affect the translator's storage of the (incomplete) sort.
			}
			else
			{
				tempVar->sortRef = retVal;
			}

			if(tempVar != NULL)
			{
				retVal->sortVar = tempVar;
			}
		}
	}
	
	// Add subsorts to the sort's list.
	if(retVal != NULL && subsorts != NULL)
	{
		for(std::list<Sort*>::iterator lIter = subsorts->begin(); lIter != subsorts->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				retVal->subsorts.push_back((*lIter));
				// If the sort was already declared and we're just adding subsorts,
				// perform the translation now.
				if(alreadyDeclared)
				{
					mainTrans.translateSubsortDecl(retVal,*lIter);
				}
			}
		}
	}
	
	// If the sort is new and is a "something*" sort, make sure its child ("something")
	// is declared too, and link them together.
	if(!alreadyDeclared && sortIdent->length() > 0 && (*sortIdent)[sortIdent->length()-1] == '*')
	{
		// Now find/create the child "something" sort.
		std::string* nonStarIdent = new std::string;
		(*nonStarIdent) = sortIdent->substr(0, sortIdent->length()-1);
		
		// Check if the child already exists before proceeding with declaration etc.
		Sort *nonStarSort = mainTrans.getSort(*nonStarIdent);
		if(nonStarSort == NULL)
		{	// Declare "something" so it can be added as the child of "something*".
			std::list<Sort*>* nonStarSubsorts = new std::list<Sort*>; // Empty on purpose.
			nonStarSort = processSort(nonStarIdent, nonStarSubsorts);
			deallocateList(nonStarSubsorts);
		}
		if(nonStarSort != NULL)
		{
			// Add "something" to subsorts.
			retVal->subsorts.push_back(nonStarSort);
		}
		deallocateItem(nonStarIdent);
		
		// Create an object "none" and associate it with the "something*" sort.
		std::string noneName = "none";
		Object* noneObj = new Object(noneName, Translator::sanitizeObjectName(noneName));
		int noneAddResult = mainTrans.addObject(noneObj);
		if(noneAddResult == SymbolTable::ADDSYM_OK)
		{
			retVal->domainObjs.push_back(noneObj);
			// Output the translation of the object declaration.
			mainTrans.translateObjectDecl(noneObj, retVal);
		}
	}
	// If the sort is new, output its translated declaration.
	if(!alreadyDeclared)
	{
		mainTrans.translateSortDecl(retVal);
	}
	return retVal;
}

// Tries to find an existing normal sort or declare a starred ("something*") sort.
Sort* checkDynamicSortDecl(std::string* sortIdent)
{
	Sort* retVal = mainTrans.getSort(*sortIdent);
	// Allow dynamic instantiation of starred sorts.
	if(retVal == NULL && sortIdent->length() > 0 && (*sortIdent)[sortIdent->length()-1] == '*')
	{
		// Verify that the non-starred version exists before instantiating the starred version.
		std::string* nonStarIdent = new std::string;
		(*nonStarIdent) = sortIdent->substr(0, sortIdent->length()-1);
		Sort *nonStarSort = mainTrans.getSort(*nonStarIdent);
		if(nonStarSort == NULL)
		{	
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << *nonStarIdent << "\" not declared, can't dynamically use \"" << *sortIdent << "\" as the domain of another declaration.";
			ltsyyreportError();
		}
		else
		{
			// Instantiate the starred version, link to child.
			std::list<Sort*>* starSubsorts = new std::list<Sort*>;
			// No need to add unstarred version to subsorts, that's done automatically.
			retVal = processSort(sortIdent, starSubsorts);
			if(retVal == NULL)
			{
				ltsyystartParseError(ltsyylloc);
				ltsyyossErr << "Bad domain declaration \"" << *sortIdent << "\".";
				ltsyyreportError();
			}
			deallocateList(starSubsorts);
		}
		deallocateItem(nonStarIdent);
	}
	else if(retVal == NULL)
	{	// The domain isn't an undeclared starred case, it's just undeclared.
		ltsyystartParseError(ltsyylloc);
		ltsyyossErr << "Sort \"" << *sortIdent << "\" not declared, can't use as the domain of another declaration.";
		ltsyyreportError();
	}
	return retVal;
}

// Transforms declarative laws ("inertial p", "exogenous a(X)", "rigid q", etc.) to basic form and calls the translator for them.
bool handleDeclarativeLaw(
	ParseElement* head, 
	ParseElement* ifBody, 
	ParseElement* assumingBody,
	ParseElement* afterBody, 
	ParseElement* unlessBody,
	ParseElement* whenBody, 
	ParseElement* followingBody,
	ParseElement* whereBody, 
	SimpleUnaryOperator::UnaryOperatorType opType
	)
{
	bool retVal = false; // Start pessimistic.
	if(head != NULL)
	{
		// head needs to be wrapped in the appropriate declarative operator.
		SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
		tempPE->opType = opType;
		tempPE->postOp = head;
		// This law becomes "delaration(F) [if G] [after H] [unless J] [when K] [following L] [where M]."
		mainTrans.translateCausalLaw(tempPE, ifBody, assumingBody, afterBody, unlessBody, whenBody, followingBody, whereBody);
		retVal = true;
		deallocateTempUnaryOp(tempPE);
	}
	return retVal;
}

// Transforms a causal law of the form "always F [when H] [where G]." to basic form, then calls the translator for it.
bool handleAlwaysLaw(
	ParseElement* constraint, 
	ParseElement* whenBody, 
	ParseElement* whereBody
	)
{
	bool retVal = false; // Start pessimistic.
	if(constraint != NULL)
	{
		// "not constraint" is the afterBody.
		SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
		tempPE->opType = SimpleUnaryOperator::UOP_NOT;
		tempPE->postOp = constraint;
		// The head is "false".l
		ObjectLikeElement* tempObj = new ObjectLikeElement();
		tempObj->baseName = "false";
		tempObj->objRef = mainTrans.getObjectLike(tempObj->baseName, 0);
		// The law becomes "caused false after -F when H where G."
		mainTrans.translateCausalLaw(tempObj, NULL, NULL, tempPE, NULL, whenBody, NULL, whereBody);
		delete tempObj;
		deallocateTempUnaryOp(tempPE);
		retVal = true;
	}
	return retVal;
}

// Transforms a causal law of the form "constraint F [after H] [when J] [following K] [where L]." to basic form, then calls the translator for it.
bool handleConstraintLaw(
	ParseElement* constraint, 
	ParseElement* afterBody, 
	ParseElement* unlessBody, 
	ParseElement* whenBody, 
	ParseElement* followingBody, 
	ParseElement* whereBody,
	bool positive
	)
{
	bool retVal = false; // Start pessimistic.
	if(constraint != NULL)
	{
		// constraint has to be a fluent formula or the law is malformed. Soft warn if we can't tell what it is (i.e., not a fluent or action formula).
		if(!constraint->hasActions())
		{
			if(!constraint->hasFluents())
			{
				ltsyystartWarning(ltsyylloc);
				ltsyyossErr << "Cannot determine if \"" << constraint->fullName() << "\" is a fluent formula or not, it might not work as F in a \"constraint F\" style law.";
				ltsyyreportWarning();
			}
			
			// "not constraint" is the ifBody.
			SimpleUnaryOperator* tempUOP = NULL;
			ParseElement* tempPE = NULL; // Points at whatever ends up becoming the head of the rule.
			
			if (positive) {
				// If the constraint is "not something", then we can just drop the not (we'd end up with "not not something", which is equivalent to "something" since "false" is the head).
				if(constraint->getType() == ParseElement::PELEM_UOP && ((SimpleUnaryOperator*)constraint)->opType == SimpleUnaryOperator::UOP_NOT)
				{
					tempPE = ((SimpleUnaryOperator*)constraint)->postOp;
				}
				else
				{	// It's not an optimizable case, just tack "not" onto the constraint.
					tempUOP = new SimpleUnaryOperator();
					tempUOP->opType = SimpleUnaryOperator::UOP_NOT;
					tempUOP->postOp = constraint;
					tempPE = (ParseElement*)tempUOP;
				}
			}
			else {
				// We are working with the negative version of the constraint, we don't have to negate the body.
				tempPE = constraint;
			}
				
			// The head is "false".
			ObjectLikeElement* tempObj = new ObjectLikeElement();
			tempObj->baseName = "false";
			tempObj->objRef = mainTrans.getObjectLike(tempObj->baseName, 0);
			// The law becomes "caused false if -F after H when J following K where L."
			mainTrans.translateCausalLaw(tempObj, tempPE, NULL, afterBody, unlessBody, whenBody, followingBody, whereBody);
			delete tempObj;
			deallocateTempUnaryOp(tempUOP);
			retVal = true;
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << constraint->fullName() << "\" is not a fluent formula, can't use it as F in a \"constraint F\" style law.";
			ltsyyreportError();
		}
	}
	return retVal;
}

// Transforms a causal law of the form "default F [if G] [assuming H] [after J] [when K] [following L] [where M]." to basic form, then calls the translator on it.
bool handleDefaultLaw(
	ParseElement* head, 
	ParseElement* ifBody, 
	ParseElement* assumingBody,
	ParseElement* afterBody, 
	ParseElement* unlessBody,
	ParseElement* whenBody, 
	ParseElement* followingBody,
	ParseElement* whereBody
	)
{
	bool retVal = false; // Start pessimistic.
	if(head != NULL)
	{
		// head and ifBody are going to end up together no matter what.
		SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
		tempPE->opType = SimpleBinaryOperator::BOP_AND;
		// however, we need to ensure parenthesis are aroudn the ifBody
		if(ifBody != NULL)
		{
			ifBody->setParens(true);
		}
		tempPE->preOp = head;
		tempPE->postOp = ifBody;
		// This law becomes "caused F if F [& G] [assuming H] [after J] [when K] [following L] [where M]."
		mainTrans.translateCausalLaw(head, tempPE, assumingBody, afterBody, unlessBody, whenBody, followingBody, whereBody);
		retVal = true;
		deallocateTempBinaryOp(tempPE);
	}
	return retVal;
}

// Transforms a causal law of the form "nonexecutable F [if G] [when H] [where K]." to basic form, then calls the translator for it.
bool handleNonexecutableLaw(
	ParseElement* nonEx, 
	ParseElement* ifBody, 
	ParseElement* whenBody,
	ParseElement* whereBody
	)
{
	bool retVal = false; // Start pessimistic.
	if(nonEx != NULL)
	{
		// nonEx has to be an action formula or the law is malformed. Soft warn if its neither kind of formula.
		if(!nonEx->hasFluents())
		{
			if(!nonEx->hasActions())
			{
				ltsyystartWarning(ltsyylloc);
				ltsyyossErr << "Cannot determine if \"" << nonEx->fullName() << "\" is an action formula or not, it might not work as F in a \"nonexecutable F\" style law.";
				ltsyyreportWarning();
			}
			// nonEx and ifBody are going to end up together no matter what.
			SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
			// however, we need to ensure parenthesis are aroudn the ifBody
			if(ifBody != NULL)
			{
				ifBody->setParens(true);
			}
			tempPE->opType = SimpleBinaryOperator::BOP_AND;
			tempPE->preOp = nonEx;
			tempPE->postOp = ifBody;
			// Create a head of "false".
			ObjectLikeElement* tempObj = new ObjectLikeElement();
			tempObj->baseName = "false";
			tempObj->objRef = mainTrans.getObjectLike(tempObj->baseName, 0);

			// becomes caused false after F [& G] following H where K.
			mainTrans.translateCausalLaw(tempObj, NULL, NULL, tempPE, NULL, NULL, whenBody, whereBody);
			delete tempObj;
			deallocateTempBinaryOp(tempPE);
			retVal = true;
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << nonEx->fullName() << "\" is not an action formula, can't use it as F in a \"nonexecutable F\" style law.";
			ltsyyreportError();
		}
	}
	return retVal;
}

// Transforms a causal law of the form "possibly caused F [if G] [assuming H] [after J] [unless K] [when L] [following M] [where N]." to basic form, then calls the translator on it.
bool handlePossiblyCausedLaw(
	ParseElement* head, 
	ParseElement* ifBody, 
	ParseElement* assumingBody,
	ParseElement* afterBody, 
	ParseElement* unlessBody,
	ParseElement* whenBody,
	ParseElement* followingBody,
	ParseElement* whereBody
	)
{
	bool retVal = false; // Start pessimistic.
	if(head != NULL)
	{
		// head and ifBody are going to end up together no matter what.
		SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
		// however, we need to ensure parenthesis are aroudn the ifBody
		if(ifBody != NULL)
		{	
			ifBody->setParens(true);
		}
		tempPE->opType = SimpleBinaryOperator::BOP_AND;
		tempPE->preOp = head;
		tempPE->postOp = ifBody;
		// This law becomes "caused F if F [& G] [assuming H] [after J] [unless K] [when L] [following M] [where N]."
		mainTrans.translateCausalLaw(head, tempPE, assumingBody, afterBody, unlessBody, whenBody, followingBody, whereBody);
		retVal = true;
		deallocateTempBinaryOp(tempPE);
	}
	return retVal;
}

// Transforms a causal law of the form "G may cause F [if H] [when J] [where K]." to basic form, then calls the translator on it.
bool handleMayCauseLaw(
	ParseElement* causer, 
	ParseElement* causee, 
	ParseElement* ifBody, 
	ParseElement* whenBody,
	ParseElement* whereBody
	)
{
	bool retVal = false; // Start pessimistic.
	if(causer != NULL && causee != NULL)
	{
		// Causer has to be an action formula, or the law is not properly written.
		if(causer->hasActions() && !causer->hasFluents())
		{
			// Causer and ifBody are going to end up together no matter what.
			SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
			// however, we need to ensure parenthesis are aroudn the ifBody
			if(ifBody != NULL)
			{
				ifBody->setParens(true);
			}
			tempPE->opType = SimpleBinaryOperator::BOP_AND;
			tempPE->preOp = causer;
			tempPE->postOp = ifBody;

			// Where causer and ifBody end up in the basic form depend on what's in causee.
			if(causee->hasActions() && !causee->hasFluents())
			{	// Causee is an action formula, this is "caused F if F & G & H following J where K".
				// Merge F into G & H.
				SimpleBinaryOperator* tempPE2 = new SimpleBinaryOperator();
				tempPE2->opType = SimpleBinaryOperator::BOP_AND;
				tempPE2->preOp = causee;
				tempPE2->postOp = tempPE;
				mainTrans.translateCausalLaw(causee, tempPE2, NULL, NULL, NULL, NULL, whenBody, whereBody);
				retVal = true;
				deallocateTempBinaryOp(tempPE2);
			}
			else if(!causee->hasActions() && causee->hasFluents())
			{	// Causee is a fluent formula, this is "caused F if F after G & H following J where K".
				mainTrans.translateCausalLaw(causee, causee, NULL, tempPE, NULL, NULL, whenBody, whereBody);
				retVal = true;
			}
			else
			{	// Causee is mixed, that isn't allowed.
				ltsyystartParseError(ltsyylloc);
				ltsyyossErr << "\"" << causee->fullName() << "\" must be a pure action formula or pure fluent formula in this law, it can't have both kinds of constants.";
				ltsyyreportError();
			}
			deallocateTempBinaryOp(tempPE);
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << causer->fullName() << "\" is not an action formula, can't use it as G in a \"G may cause F\" style law.";
			ltsyyreportError();
		}
	}
	return retVal;
}

// Transforms a causal law of the form "G causes F [if H] [where J]." to basic form, then calls the translator on it.
bool handleCausesLaw(
	ParseElement* causer, 
	ParseElement* causee, 
	ParseElement* ifBody, 
	ParseElement* whenBody,
	ParseElement* whereBody
	)
{
	bool retVal = false; // Start pessimistic.
	if(causer != NULL && causee != NULL)
	{
		// Causer has to be an action formula, or the law is not properly written.
		if(causer->hasActions() && !causer->hasFluents())
		{
			// Causer and ifBody are going to end up together no matter what.
			SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
			tempPE->opType = SimpleBinaryOperator::BOP_AND;
			// however, we need to ensure parenthesis are aroudn the ifBody
			if(ifBody != NULL)
			{
				ifBody->setParens(true);
			}
			tempPE->preOp = causer;
			tempPE->postOp = ifBody;
			// Where causer and ifBody end up in the basic form depend on what's in causee.
			if((causee->hasActions() && !causee->hasFluents()) || causee->getType() == ParseElement::PELEM_OBJLIKE)
			{	// Causee is an action formula, this is "caused F if G".
				mainTrans.translateCausalLaw(causee, tempPE, NULL, NULL, NULL, NULL, whenBody, whereBody);
				retVal = true;
			}
			else if(!causee->hasActions() && causee->hasFluents())
			{	// Causee is a fluent formula, this is "caused F after G".
				mainTrans.translateCausalLaw(causee, NULL, NULL, tempPE, NULL, NULL, whenBody, whereBody);
				retVal = true;
			}
			else
			{	// Causee is mixed, that isn't allowed.
				ltsyystartParseError(ltsyylloc);
				ltsyyossErr << "\"" << causee->fullName() << "\" must be a pure action formula or pure fluent formula in this law, it can't have both kinds of constants.";
				ltsyyreportError();
			}
			deallocateTempBinaryOp(tempPE);
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << causer->fullName() << "\" is not an action formula, can't use it as G in a \"G causes F\" style law.";
			ltsyyreportError();
		}
	}
	return retVal;
}

// Transforms an increment law of the form "A increments B by N [if H] [when J] [where K]." to basic form, then calls the translator on it.
bool handleIncrementLaw(
	ParseElement* causer, 
	ParseElement* causee, 
	ParseElement* increment, 
	ParseElement* ifBody, 
	ParseElement* whenBody,
	ParseElement* whereBody, 
	bool isIncrement
	)
{
	SimpleBinaryOperator* inc_expr = NULL;
	SimpleBinaryOperator* negative_expr = NULL;
	VariableLikeElement* x_val = NULL;
	ObjectLikeElement* tempNegOnePE = NULL;
	SimpleBinaryOperator* tempPE = NULL;
	SimpleBinaryOperator* newCausee = NULL;
	Constant* constRef;
	bool retVal = false; // Start pessimistic.
	if(causer != NULL && causee != NULL)
	{
		// Causer has to be a single action, or the law is not properly written.
		if(causer->hasActions() && causer->getType() == ParseElement::PELEM_CONSTLIKE && !causer->hasFluents())
		{
			// Causer and ifBody are going to end up together no matter what.
			
			//define the expression of the increment variable, X_VAL
			inc_expr = new SimpleBinaryOperator();
			inc_expr->opType = SimpleBinaryOperator::BOP_EQ;
			
			x_val = new VariableLikeElement();
			x_val->baseName = "X_Value";
			x_val->varRef = NULL;
			inc_expr->preOp = x_val;
			
			if(isIncrement)
			{
				increment->setParens(true);
				inc_expr->postOp = increment;
			}
			else //multiply by -1
			{
				negative_expr = new SimpleBinaryOperator();
				negative_expr->opType = SimpleBinaryOperator::BOP_TIMES;
				
				tempNegOnePE = new ObjectLikeElement();
				tempNegOnePE->baseName = "-1";
				//tempNegOnePE->objRef = mainTrans.getObjectLike("-1", 0);
				tempNegOnePE->objRef = NULL;
				tempNegOnePE->setParens(true);
				increment->setParens(true);
				negative_expr->preOp = tempNegOnePE;
				negative_expr->postOp = increment;
				inc_expr->postOp = negative_expr;
			}

			//add the expression to the whereBody
			SimpleBinaryOperator* tempWherePE = NULL;
			if(whereBody != NULL)
			{
				tempWherePE = new SimpleBinaryOperator();
				tempWherePE->opType = SimpleBinaryOperator::BOP_AND;
				whereBody->setParens(true);
				// however, we need to ensure parenthesis are aroudn the ifBody
				if(ifBody != NULL)
				{
					ifBody->setParens(true);
				}
				tempWherePE->preOp = whereBody;
				tempWherePE->postOp = inc_expr;
			}
			else
			{
				tempWherePE = inc_expr;
			}
			
			tempPE = new SimpleBinaryOperator();
			tempPE->opType = SimpleBinaryOperator::BOP_AND;
			tempPE->preOp = causer;
			tempPE->postOp = ifBody;
			// Causee must be a single constant-like additive fluent or additive action.
			if(causee->getType() == ParseElement::PELEM_CONSTLIKE)
			{
				if(((ConstantLikeElement*)causee)->constRef->constType == Constant::CONST_ADDITIVEACTION || ((ConstantLikeElement*)causee)->constRef->constType == Constant::CONST_ADDITIVEFLUENT)
				{
					// Create contribution element.
					newCausee = new SimpleBinaryOperator();
					newCausee->opType = SimpleBinaryOperator::BOP_EQ;
					ConstantLikeElement* contrib = new ConstantLikeElement();
					std::string contrib_str("contribution");
					contrib->baseName = contrib_str;
					// To avoid a weird translation, temporarily create object-like versions of causer and causee and use those instead.
					// ObjectLikeElement *tempCauser = createObjLikeFromConstLike((ConstantLikeElement*)causer);
					// ObjectLikeElement *tempCausee = createObjLikeFromConstLike((ConstantLikeElement*)causee);
					// contrib->params.push_back(tempCauser);
					// contrib->params.push_back(tempCausee);
					contrib->params.push_back(causer);
					contrib->params.push_back(causee);
					constRef = mainTrans.getConstantLike(contrib_str,2);
					contrib->constRef = constRef;
					newCausee->preOp = contrib;
					newCausee->postOp = x_val;

					mainTrans.translateCausalLaw(newCausee, tempPE, NULL, NULL, NULL, NULL, whenBody, tempWherePE);
					retVal = true;
					deallocateTempBinaryOp(newCausee);
					contrib->params.clear();
					deallocateItem(contrib);
					//tempCauser->params.clear();
					//deallocateItem(tempCauser);
					//tempCausee->params.clear();
					//deallocateItem(tempCausee);
				}
				else
				{
					ltsyystartParseError(ltsyylloc);
					ltsyyossErr << "\"" << causee->fullName() << "\" is not an additive constant, can't use it as B in a \"A increments B by N\" style law.";
					ltsyyreportError();
				}	
			}
			else
			{
				ltsyystartParseError(ltsyylloc);
				ltsyyossErr << "\"" << causer->fullName() << "\" is not a single additive constant, can't use it as B in a \"A increments B by N\" style law.";
				ltsyyreportError();
			}
			deallocateTempBinaryOp(tempWherePE);
			deallocateTempBinaryOp(tempPE);
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << causer->fullName() << "\" is not a single action, can't use it as A in a \"A increments B by N\" style law.";
			ltsyyreportError();
		}
	}
	return retVal;
}

// Wraps the given element in two new negation operators to create a "not not (...)" wrap.
SimpleUnaryOperator* createNotNot(ParseElement* elem)
{
	SimpleUnaryOperator* retVal = NULL;
	if(elem != NULL)
	{
		elem->setParens(true);
		SimpleUnaryOperator* tempNotNot1 = new SimpleUnaryOperator();
		SimpleUnaryOperator* tempNotNot2 = new SimpleUnaryOperator();
		tempNotNot1->opType = SimpleUnaryOperator::UOP_NOT;
		tempNotNot1->postOp = elem;
		tempNotNot2->opType = SimpleUnaryOperator::UOP_NOT;
		tempNotNot2->postOp = tempNotNot1;
		retVal = tempNotNot2;
	}
	return retVal;
}

// Creates an object-like element that mirrors the contents of elem.
ObjectLikeElement* createObjLikeFromConstLike(ConstantLikeElement* elem)
{
	ObjectLikeElement* retVal = NULL;
	
	if(elem != NULL)
	{
		retVal = new ObjectLikeElement();
		retVal->baseName = elem->baseName;
		retVal->params = elem->params;
		retVal->objRef = NULL;
	}
	
	return retVal;
}

// Deallocates a "not not" wrapper such that the original ParseElement is not touched, and returns the original ParseElement object.
ParseElement* deallocateNotNot(SimpleUnaryOperator* uop)
{
	ParseElement* retVal = NULL;
	if(uop != NULL)
	{
		if(uop->postOp != NULL)
		{
			retVal = ((SimpleUnaryOperator*)(uop->postOp))->postOp;
			((SimpleUnaryOperator*)(uop->postOp))->postOp->setParens(false);
			((SimpleUnaryOperator*)(uop->postOp))->postOp = NULL;
			delete uop->postOp;
			uop->postOp = NULL;
		}
		delete uop;
		uop = NULL;
	}
	return retVal;
}

// NULLs elem's preOp and postOp before deallocating so the sub-ParseElement objects don't get caught in the deallocation.
void deallocateTempBinaryOp(SimpleBinaryOperator* &elem)
{
	if(elem != NULL)
	{
		elem->preOp = NULL;
		elem->postOp = NULL;
		delete elem;
		elem = NULL;
	}
}

// NULLs elem's postOp before deallocating so the sub-ParseElement object doesn't get caught in the deallocation.
void deallocateTempUnaryOp(SimpleUnaryOperator* &elem)
{
	if(elem != NULL)
	{
		elem->postOp = NULL;
		delete elem;
		elem = NULL;
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

