%defines "parser.h"
%locations
%name-prefix "ltsyy"
%output "parser.cpp"
%token-table
%verbose

%code requires {
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
}

%union {
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
}

%code provides {
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

}

%{
#include "lexerTokenStream.h"

%}

%{
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

%}

%token <integer> T_INTEGER			// Any positive integer.
%token <str> T_IDENTIFIER			// Any identifier starting with a letter or
                            		// with underscore(s) and a letter/number, & optionally
                            		// followed by letters/numbers/underscores,
%token <str> T_STRING				// A quoted string containing arbitrary text.
%token <asp> T_ASP					// Raw ASP code from input.
%token <comment> T_COMMENT			// Raw text from input that was commented out.

%token <integer> T_CONSTANTS		// constants
%token <integer> T_INCLUDE			// include
%token <integer> T_MACROS			// macros
%token <integer> T_OBJECTS			// objects
%token <integer> T_QUERY			// query
%token <integer> T_SHOW				// show
%token <integer> T_SORTS			// sorts
%token <integer> T_VARIABLES		// variables

%token <integer> T_ABACTION			// abAction
%token <integer> T_ACTION			// action
%token <integer> T_ADDITIVEACTION	// additiveAction
%token <integer> T_ADDITIVEFLUENT	// additiveFluent
%token <integer> T_AFTER			// after
%token <integer> T_ALWAYS			// always
%token <integer> T_ASSUMING			// assuming 			-- "if2" construct
%token <integer> T_ATTRIBUTE		// attribute
%token <integer> T_BY				// by
%token <integer> T_CAUSED			// caused
%token <integer> T_CAUSES			// causes
%token <integer> T_IMPOSSIBLE		// impossible
%token <integer> T_CONSTRAINT		// constraint
%token <integer> T_DECREMENTS		// decrements
%token <integer> T_DEFAULT			// default
%token <integer> T_DYNAMICAB		// dynamicAbnormality	-- aC+ construct
%token <integer> T_EXOGENOUS		// exogenous
%token <integer> T_EXOGENOUSACTION	// exogenousAction
%token <integer> T_IF				// if
%token <integer> T_INCREMENTS		// increments
%token <integer> T_INERTIAL			// inertial
%token <integer> T_INERTIALFLUENT	// inertialFluent
%token <integer> T_LABEL			// label
%token <integer> T_MAY_CAUSE		// may cause
%token <integer> T_MAXADDITIVE		// maxAdditive
%token <integer> T_MAXSTEP			// maxstep
%token <integer> T_NEVER			// never
%token <integer> T_NOCONCURRENCY	// noconcurrency
%token <integer> T_STRONG_NOCONCURRENCY // strong_noconcurrency
%token <integer> T_NONEXECUTABLE	// nonexecutable
%token <integer> T_OF				// of
%token <integer> T_POSSIBLY_CAUSED	// possibly caused
%token <integer> T_RIGID			// rigid
%token <integer> T_SDFLUENT			// sdFluent
%token <integer> T_SIMPLEFLUENT		// simpleFluent
%token <integer> T_STATICAB			// staticAbnormality 	-- aC+ construct
%token <integer> T_UNLESS			// unless
%token <integer> T_WHEN				// when 				-- aC+ construct
%token <integer> T_FOLLOWING			// following 				-- aC+ construct
%token <integer> T_WHERE			// where

%token <integer> T_FALSE			// false
%token <integer> T_NONE				// none
%token <integer> T_TRUE				// true

%token <integer> T_ABS				// abs
%token <integer> T_AT				// @
%token <integer> T_BRACKET_L		// [
%token <integer> T_BRACKET_R		// ]
%token <integer> T_COLON_DASH		// :-
%token <integer> T_PAREN_L			// (
%token <integer> T_PAREN_R			// )
%token <integer> T_PERIOD			// .
%token <integer> T_PIPE				// |
%token <integer> T_NOOP				// hack token

/* Tokens singled out to establish precedence. */
%right <integer> T_SEMICOLON			// ;
%nonassoc <integer> T_DBL_COLON			// ::
%nonassoc <integer> T_ARROW_LEQ T_ARROW_REQ T_ARROW_LDASH		// <= => <-
%right <integer> T_ARROW_RDASH			// ->
%nonassoc <integer> T_COLON				// :
%left <integer> T_COMMA					// ,
%right <integer> T_EQUIV				// <->
%right <integer> T_IMPL					// ->>
%left <integer> T_DBL_PLUS				// ++
%left <integer> T_AMP T_DBL_AMP			// &, &&
%nonassoc <integer> T_EQ T_DBL_EQ T_NOT_EQ T_LTHAN T_GTHAN T_EQ_LTHAN T_GTHAN_EQ		// = or eq, ==, \= or <> or neq, <, >, =<, >=
%left <integer> T_NOT					// not
%nonassoc <integer> T_DBL_PERIOD		// ..
%left <integer> T_DASH T_PLUS			// -, +
%right <integer> T_DBL_GTHAN			// >>
%left <integer> T_STAR T_INT_DIV T_MOD	// *, //, mod
%token <integer> T_BIG_CONJ T_BIG_DISJ		// /\ \/
%token <integer> T_POUND				// #
%left <integer> T_UMINUS				// Pseudo-token, unary minus

%token <integer> END 0 "end of file"

/* Top-level nonterminal types */
%type <not_used> program statement_sequence statement

/* Constant declaration nonterminal types */
%type <not_used> constant_statement constant_spec_outer_tuple constant_spec_tuple constant_outer_spec constant_spec
%type <l_constant> constant_schema_outer_list constant_schema_list
%type <constant> constant_outer_schema constant_schema constant_schema_nodecl
%type <constant_binder_t> constant_outer_binder constant_binder

/* maxAdditive declaration nonterminal types */
%type <not_used> maxadditive_statement

/* Object declaration nonterminal types */
%type <not_used> object_statement object_spec_outer_tuple object_spec_tuple object_outer_spec object_spec
%type <l_object> object_outer_schema_list object_schema_list
%type <object> object_outer_schema object_schema

/* Show declaration nonterminal types */
%type <not_used> show_statement
%type <parseElement> atomic_formula
%type <v_parseElement> atomic_formula_list
/// @todo finish Show decl nonterminal types.

/* Sort declaration nonterminal types */
%type <not_used> sort_statement
%type <l_sort> sort_spec_outer_tuple sort_spec_tuple
%type <sort> sort_spec
%type <str> sort_outer_identifier sort_identifier sort_identifier_name sort_constant_name sort_identifier_with_ab sort_identifier_no_range

/* Variable declaration nonterminal types */
%type <not_used> variable_statement variable_spec_outer_tuple variable_spec_tuple variable_outer_spec variable_spec
%type <l_variable> variable_outer_list variable_list
%type <sort> variable_binding

/* Query declaration nonterminal types */
%type <not_used> query_statement query_expression_tuple query_expression
%type <parseElement> query_body_formula query_body_formula_inner query_body_term query_body_term_inner
%type <parseElement> expr_big_query_expression

/* Causal law nonterminal types */
%type <not_used> causal_law causal_law_shortcut_forms causal_law_basic_forms
%type <not_used> cl_always_forms cl_constraint_forms cl_default_forms cl_exogenous_forms cl_inertial_forms cl_nonexecutable_forms cl_rigid_forms 
%type <not_used> cl_possibly_caused_forms cl_may_cause_forms cl_causes_forms cl_noconcurrency_forms cl_increment_forms cl_trivial_forms
%type <parseElement> cl_head_formula cl_body_formula cl_body_formula_inner cl_body_term cl_body_term_inner cl_where_expr
%type <parseElement> literal_assign_conj literal_assign_conj_inner literal_assign_expr //literal_conj literal_conj_inner
%type <parseElement> expr_big_expression
%type <parseElement> cl_if_clause cl_assuming_clause cl_after_clause cl_unless_clause cl_when_clause cl_following_clause cl_where_clause
%type <parseElement> cl_when_expr cl_following_expr cl_body_formula_bool cl_body_formula_bool_inner cl_body_term_bool cl_body_term_bool_inner expr_big_expression_bool
%type <l_quantPair> expr_big_quantifiers
%type <p_quantPair> expr_big_conj expr_big_disj

/* Miscellaneous nonterminal types */
%type <parseElement> constant_expr
%type <v_parseElement> parameter_list
%type <l_sort> sort_identifier_list
%type <parseElement> parameter_general extended_value_expression extended_math_expression extended_math_expr_inner extended_math_term
%type <numRange> num_range
%type <str> extended_integer extended_integer_outer_expression extended_integer_expression lua_indicator
%type <integer> AND OR NOT EQUALS NOT_EQUALS COMPARISON LESS_THAN GREATER_THAN LESS_THAN_EQ GREATER_THAN_EQ

/* Destructors for union types that had dynamic memory associated with them. */
%destructor { delete $$; } <str>
%destructor { delete $$; } <attribute>
%destructor { delete $$; } <constant>
%destructor { delete $$; } <numRange>
%destructor { delete $$; } <object>
//%destructor { delete $$; } <query>
%destructor { delete $$; } <sort>
%destructor { delete $$; } <variable>
%destructor { if($$ != NULL) { deallocateList($$); } } <l_constant>
%destructor { if($$ != NULL) { deallocateList($$); } } <l_object>
%destructor { if($$ != NULL) { deallocateList($$); } } <l_sort>
%destructor { if($$ != NULL) { deallocateList($$); } } <l_variable>
%destructor { if($$ != NULL) { deallocateItem($$); } } <constant_binder_t>

%%

program:					 	 /*  empty  */		{ $$ = PARSERULE_NOT_USED; }
							| statement_sequence		
{ 
		$$ = PARSERULE_NOT_USED; 

		// Ensure that we append the footer
		// after the program has finished translating
		mainTrans.outputFooter();
		
}
							;

statement_sequence:			  		statement		{ $$ = PARSERULE_NOT_USED; }
							| statement_sequence statement		{ $$ = PARSERULE_NOT_USED; }
							;

statement:					  	constant_statement		{ $$ = PARSERULE_NOT_USED; }
							| maxadditive_statement		{ $$ = PARSERULE_NOT_USED; }
							| object_statement		{ $$ = PARSERULE_NOT_USED; }
							| query_statement		{ $$ = PARSERULE_NOT_USED; }
							| show_statement		{ $$ = PARSERULE_NOT_USED; }
							| sort_statement		{ $$ = PARSERULE_NOT_USED; }
							| variable_statement		{ $$ = PARSERULE_NOT_USED; }
							| causal_law			{ $$ = PARSERULE_NOT_USED; }
							| error T_PERIOD
{ 
	$$ = PARSERULE_NOT_USED;
	/* On an error, go to the end of the bad statement and try to continue.
       Set the error handler to not wait to report syntax errors if more show up. */
	yyerrok;
}							| T_NOOP		{$$ = PARSERULE_NOT_USED;}//hack to get terminal comments recognized
							;
/*							| include_statement */ /* Probably going to treat this as a macro / "pre-processor" thing. */

/* ***DECLARATIONS*** */

/* ***Constants*** */

constant_statement:			  		T_COLON_DASH T_CONSTANTS constant_spec_outer_tuple T_PERIOD		{ $$ = PARSERULE_NOT_USED; }
							;

constant_spec_outer_tuple:	  			constant_spec_tuple		{ $$ = PARSERULE_NOT_USED; }
							| T_PAREN_L constant_spec_tuple T_PAREN_R		{ $$ = PARSERULE_NOT_USED; }
							;

constant_spec_tuple:		  			constant_outer_spec		{ $$ = PARSERULE_NOT_USED; }
							| constant_spec_outer_tuple T_SEMICOLON constant_outer_spec		{ $$ = PARSERULE_NOT_USED; }
							;

constant_outer_spec:		  			constant_spec		{ $$ = PARSERULE_NOT_USED; } 
							| T_PAREN_L constant_spec T_PAREN_R		{ $$ = PARSERULE_NOT_USED; }
							;

constant_spec:				 		 constant_schema_outer_list T_DBL_COLON constant_outer_binder
{
	// Fill in each Constant's type and domain and translate each of them.
	bool constantError = true; // Set to true if any of the constants have trouble getting added to the symbol table.
	Sort* tempSort = NULL;
	if($1 != NULL && $3 != NULL)
	{
		tempSort = $3->domain;
		if($3->constType == Constant::CONST_STATICAB || $3->constType == Constant::CONST_DYNAMICAB || tempSort != NULL)
		{
			constantError = false;
			std::list<Constant*>::iterator lIter;
			// If the binding type is "attribute", turn the Constant objects into Attribute objects before adding them.
			if($3->constType == Constant::CONST_ATTRIBUTE)
			{
				Attribute* tempAttribute = NULL;
				for(lIter = $1->begin(); lIter != $1->end(); ++lIter)
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
			
			for(lIter = $1->begin(); lIter != $1->end(); ++lIter)
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
					(*lIter)->constType = $3->constType;
					(*lIter)->domain = tempSort;
					if((*lIter)->constType == Constant::CONST_ATTRIBUTE && $3->attributeOf != NULL)
					{
						((Attribute*)(*lIter))->attributeOf = $3->attributeOf;
					}
					// Translate each constant once its information is complete.
					mainTrans.translateConstantDecl(*lIter);
				}
			}
		}
		else
		{
			// Deallocate all of the constants in the errant list, they're never going to get used by anything.
			for(std::list<Constant*>::iterator lIter = $1->begin(); lIter != $1->end(); ++lIter)
			{
				deallocateItem(*lIter);
			}
		}
	}
	if($3 != NULL)
	{
		deallocateItem($3);
	}
	if($1 != NULL)
	{
		deallocateList($1);
	}
	$$ = PARSERULE_NOT_USED;
	if (constantError)
	{
		YYERROR;
	}
}
							;

constant_schema_outer_list:	  			constant_schema_list
{
	$$ = $1;
}
							| T_PAREN_L constant_schema_list T_PAREN_R
{
	$$ = $2;
}
							;

constant_schema_list:		  			constant_outer_schema
{
	// Create a new constant list, add the schema as the first element.
	$$ = new std::list<Constant*>;
	if($1 != NULL)
	{
		$$->push_back($1);
	}
}
							| constant_schema_outer_list T_COMMA constant_outer_schema
{
	// Merge a schema into an existing list.
	$$ = NULL;
	if($1 != NULL && $3 != NULL)
	{
		$$ = $1;
		$$->push_back($3);
	}
	if($1 == NULL)
	{
		deallocateItem($3);
	}
	if($3 == NULL)
	{
		for(std::list<Constant*>::iterator lIter = $1->begin(); lIter != $1->end(); ++lIter)
		{
			deallocateItem(*lIter);
		}
		deallocateItem($3);
	}
}
							;

constant_outer_schema:		  			constant_schema
{
	$$ = $1;
}
							| T_PAREN_L constant_schema T_PAREN_R
{
	$$ = $2;
}
							;

constant_schema:			  		T_IDENTIFIER
{
	// Create a new Constant from a bare identifier.
	$$ = new Constant(*$1, Translator::sanitizeConstantName(*$1));
	deallocateItem($1);
}
							| T_IDENTIFIER T_PAREN_L sort_identifier_list T_PAREN_R
{
	// Create a new Constant from a parameterized identifier.
	$$ = NULL;
	if($3 != NULL)
	{
		$$ = new Constant(*$1, Translator::sanitizeConstantName(*$1));
		for(std::list<Sort*>::iterator lIter = $3->begin(); lIter != $3->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				$$->params.push_back(*lIter);
			}
		}
		deallocateList($3);
	}
	deallocateItem($1);
}
							;

/* Similar to constant_schema, but looks in the symbol table for an equivalent Constant instead of creating one. */
constant_schema_nodecl:		  T_IDENTIFIER
{
	std::vector<std::string> dummyParams;
	$$ = mainTrans.getConstant(*$1, dummyParams);
	deallocateItem($1);
}
							| T_IDENTIFIER T_PAREN_L sort_identifier_list T_PAREN_R
{
	$$ = NULL;
	if($3 != NULL)
	{
		std::vector<Sort*> constVecParams = utils::elementListToElementVector(*$3);
		std::vector<std::string> constParamNames = utils::elementVectorToFullNameVector(constVecParams);
		$$ = mainTrans.getConstant(*$1, constParamNames);
		deallocateList($3);
	}
	deallocateItem($1);
}
							;

constant_outer_binder:		  constant_binder
{
	$$ = $1;
}
							| T_PAREN_L constant_binder T_PAREN_R
{
	$$ = $2;
}
							;

constant_binder:			  		sort_identifier_with_ab
{
	// Two possibilities, check for each:
	// 1) The identifier is a plain constant type (e.g. "exogenousAction").
	// 2) The identifier is something else, which is a shortcut for "rigid(identifier)".
	Constant::ConstantType constType = Constant::CONST_UNKNOWN;
	std::string tempIdent = (*$1);
	deallocateItem($1);
	// Check for a real constant type.
	constType = Constant::stringToConstType(tempIdent.c_str());
	$$ = new PT_constant_binder_t;
	if (constType == Constant::CONST_STATICAB || constType == Constant::CONST_DYNAMICAB) {
		// it's an abnormality
		$$->constType = constType;
		$$->domain = NULL;
	} 
	else if(constType != Constant::CONST_UNKNOWN)
	{	// Basic constant binder with Boolean domain.
		$$->constType = constType;
		std::string domainName = "boolean";
		$$->domain = checkDynamicSortDecl(&domainName);
	}
	else
	{	// If it wasn't a real constant type, it's just a shortcut for "rigid(identifier)".
		$$->constType = Constant::CONST_RIGID;
		$$->domain = checkDynamicSortDecl(&tempIdent);
		if($$->domain == NULL)
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << tempIdent << "\" not declared, can't use as the domain of a constant declaration.";
			ltsyyreportError();
		}
		if($$->domain == NULL)
		{	// If $$'s domain attribute is NULL, an error happened.
			deallocateItem($$);
			YYERROR;
		}
	}
}
							| sort_constant_name T_PAREN_L sort_identifier T_PAREN_R
{
	// Basic constant binder with given domain.
	Constant::ConstantType constType = Constant::CONST_UNKNOWN;
	std::string tempIdent = (*$1);
	deallocateItem($1);

	// Figure out which constant type was given.
	constType = Constant::stringToConstType(tempIdent.c_str());
	
	$$ = new PT_constant_binder_t;
	$$->constType = constType;
	if($3 != NULL)
	{
		$$->domain = checkDynamicSortDecl($3);
		deallocateItem($3);
	}
	if($$->domain == NULL)
	{	// Start error mode if anything went wrong.
		deallocateItem($$);
		YYERROR;
	}
}
							| T_ATTRIBUTE T_OF constant_schema_nodecl
{
	// Attribute binder with Boolean(*) domain.
	$$ = new PT_constant_binder_t;
	$$->constType = Constant::CONST_ATTRIBUTE;
	std::string* domainName = new std::string("boolean*");
	$$->domain = checkDynamicSortDecl(domainName);
	deallocateItem(domainName);
	if($3 != NULL)
	{
		$$->attributeOf = $3;
	}
	else
	{	// Something's wrong, start error mode.
		deallocateItem($$);
		YYERROR;
	}
}
							| T_ATTRIBUTE T_PAREN_L sort_identifier T_PAREN_R T_OF constant_schema_nodecl
{
	// Attribute binder with given(*) domain.
	$$ = new PT_constant_binder_t;
	$$->constType = Constant::CONST_ATTRIBUTE;
	if($3 != NULL)
	{
		std::string* domainName = new std::string(*$3);
		(*domainName) += "*";
		$$->domain = checkDynamicSortDecl(domainName);
		deallocateItem(domainName);
		if($$->domain == NULL)
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << *$3 << "\" not declared, can't use as the domain of a constant declaration.";
			ltsyyreportError();
		}
		deallocateItem($3);
	}
	if($6 != NULL)
	{
		$$->attributeOf = $6;
	}
	if($$->domain == NULL || $$->attributeOf == NULL)
	{	// If $$'s attributes are NULL, an error happened.
		deallocateItem($$);
		YYERROR;
	}
}
/* This is now included in sort_identifier
							| num_range
{
	// A (dirty) shortcut for rigid(num_range), dynamically instantiating a sort for the num range.
	$$ = new PT_constant_binder_t;
	$$->constType = Constant::CONST_RIGID;
	// Turn the number range into a sort (if that hasn't happened already).
	if($1 != NULL)
	{
		std::string numRangeSortName = Translator::numRangeToSortName($1->min, $1->max);
		Sort* tempSort = mainTrans.getSort(numRangeSortName);
		if(tempSort == NULL)
		{
			// Have a helper function handle making and translating the sort.
			std::list<Sort*>* dummyList = new std::list<Sort*>; // No subsorts.
			tempSort = processSort(&numRangeSortName, dummyList);
			deallocateList(dummyList);
			// Also add the number range as an object for this new sort.
			int addResult = mainTrans.addObject($1);
			if(addResult == SymbolTable::ADDSYM_OK)
			{
				tempSort->domainObjs.push_back($1);
				// Output the translation of the object declaration.
				mainTrans.translateObjectDecl($1, tempSort);
			}
		}
		if($$ != NULL && tempSort != NULL)
		{
			$$->domain = tempSort;
		}
		if(tempSort == NULL)
		{
			deallocateItem($1);
		}
	}
	if($$->domain == NULL)
	{	// If $$'s domain is NULL, an error happened.
		deallocateItem($$);
		YYERROR;
	}
}
*/							;

/* ***maxAdditive*** */

maxadditive_statement:		  T_COLON_DASH T_MAXADDITIVE T_DBL_COLON extended_integer_outer_expression T_PERIOD
{
	// The new style of maxAdditive declaration. Insert a hint comment with the given maxAdditive value.
	if($4 != NULL)
	{
		std::string maxAdditiveHint = "% [MaxAdditive:";
		maxAdditiveHint += *($4);
		maxAdditiveHint += "]";
		mainTrans.output(maxAdditiveHint, Context::NONE, true);
		$$ = PARSERULE_NOT_USED;
		deallocateItem($4);
	}
}
							;

/* ***Objects*** */

object_statement:			  T_COLON_DASH T_OBJECTS object_spec_outer_tuple T_PERIOD		{ $$ = PARSERULE_NOT_USED; }
							;

object_spec_outer_tuple:	  object_spec_tuple		{ $$ = PARSERULE_NOT_USED; }
							| T_PAREN_L object_spec_tuple T_PAREN_R		{ $$ = PARSERULE_NOT_USED; }
							;

object_spec_tuple:			  object_outer_spec		{ $$ = PARSERULE_NOT_USED; }
							| object_spec_outer_tuple T_SEMICOLON object_spec_outer_tuple		{ $$ = PARSERULE_NOT_USED; }
							;

object_outer_spec:			  object_spec		{ $$ = PARSERULE_NOT_USED; }
							| T_PAREN_L object_spec T_PAREN_R		{ $$ = PARSERULE_NOT_USED; }
							;

object_spec:				  object_outer_schema_list T_DBL_COLON sort_outer_identifier
{
	// Connect each Object in the list to its sort, (try to) add them to the symbol table, and translate each object.
	Sort* tempSort = NULL;
	bool objectError = false; // Set to true if a serious error happens during object adding.
	if($1 != NULL && $3 != NULL)
	{
		tempSort = mainTrans.getSort(*$3);
		if(tempSort != NULL)
		{
			for(std::list<Object*>::iterator lIter = $1->begin(); lIter != $1->end(); ++lIter)
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
			ltsyyossErr << "Sort \"" << *$3 << "\" not declared, can't use as the target of an object declaration.";
			ltsyyreportError();
			// Deallocate all of the objects in the errant list, they're never going to get used by anything.
			for(std::list<Object*>::iterator lIter = $1->begin(); lIter != $1->end(); ++lIter)
			{
				deallocateItem(*lIter);
			}
		}
		deallocateList($1);
		deallocateItem($3);
	}
	$$ = PARSERULE_NOT_USED;
	if(tempSort == NULL || objectError == true)
	{	// If the binding sort never got a match or an object had a problem getting added, an error occurred.
		YYERROR;
	}
}
							;

object_outer_schema_list:	  object_schema_list
{
	$$ = $1;
}
							| T_PAREN_L object_schema_list T_PAREN_R
{
	$$ = $2;
}
							;

object_schema_list:			  object_outer_schema
{
	// Create a new list and make the new object the first element.
	$$ = NULL;
	if($1 != NULL)
	{
		$$ = new std::list<Object*>;
		$$->push_back($1);
	}
}
							| object_outer_schema_list T_COMMA object_outer_schema
{
	// Merge a new object with an exisiting list.
	$$ = NULL;
	if($1 != NULL && $3 != NULL)
	{
		$$ = $1;
		$$->push_back($3);
	}
	if($1 == NULL)
	{
		deallocateItem($3);
	}
	if($3 == NULL)
	{
		for(std::list<Object*>::iterator lIter = $1->begin(); lIter != $1->end(); ++lIter)
		{
			deallocateItem(*lIter);
		}
		deallocateList($1);
	}
}
							;

object_outer_schema:		  object_schema
{
	$$ = $1;
}
							| T_PAREN_L object_schema T_PAREN_R
{
	$$ = $2;
}
							;

object_schema:				  T_IDENTIFIER
{
	// Create a new Object from a bare identifier.
	$$ = new Object(*$1, Translator::sanitizeObjectName(*$1));
	deallocateItem($1);
}
							| T_IDENTIFIER T_PAREN_L sort_identifier_list T_PAREN_R
{
	// Create a new Object from a parameterized identifier.
	$$ = new Object(*$1, Translator::sanitizeObjectName(*$1));
	if($3 != NULL)
	{
		for(std::list<Sort*>::iterator lIter = $3->begin(); lIter != $3->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				$$->params.push_back(*lIter);
			}
		}
		deallocateList($3);
	}
	deallocateItem($1);
}
							| extended_integer_outer_expression
{
	// Create a new object from arbitrary math.
	$$ = new Object(*$1, Translator::sanitizeObjectName(*$1));
	deallocateItem($1); // Free dynamic memory that's not needed anymore.
}
							| num_range
{
	// Upcast a NumberRange into an Object.
	$$ = (Object*)$1;
}
							;

/* ***Show Declaration*** */

show_statement:				  		T_COLON_DASH T_SHOW atomic_formula_list T_PERIOD
{
	if ($3) {
		mainTrans.handleShowStmt(*$3);
	} else {
		YYERROR;
	}
	deallocateList($3);
	$$ = PARSERULE_NOT_USED;
}							;



atomic_formula_list:					atomic_formula
{
	if ($1) {
		$$ = new std::vector<ParseElement*>();
		$$->push_back($1);
	} else {
		$$ = NULL;
	}
	 
}		
							| atomic_formula_list T_SEMICOLON atomic_formula
{
	if ($1) {
		$$ = $1;
		if ($3) $1->push_back($3);
	} else if ($3) {
		$$ = new std::vector<ParseElement*>();
		$$->push_back($3);
	} else {
		$$ = NULL;
	}
}
							;
			
atomic_formula:		  			constant_expr
{
	$$ = $1;
}
							| constant_expr T_EQ extended_value_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQ;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							 ;







/* ***Sorts*** */

sort_statement:				  		T_COLON_DASH T_SORTS sort_spec_outer_tuple T_PERIOD
{
	// Deallocate the main sort list of the statement.
	if($3 != NULL)
	{
		deallocateList($3);
	}
	$$ = PARSERULE_NOT_USED;
}
							;

sort_spec_outer_tuple:		  sort_spec_tuple
{
	$$ = $1;
}
							| T_PAREN_L sort_spec_tuple T_PAREN_R
{
	$$ = $2;
}
							;

sort_spec_tuple:			  sort_spec
{
	$$ = new std::list<Sort*>;
	$$->push_back($1);
}
							| sort_spec_outer_tuple T_SEMICOLON sort_spec_outer_tuple
{
	$$ = NULL;
	if($1 != NULL || $3 != NULL)
	{
		$$ = new std::list<Sort*>;
	}
	// Merge the two sort lists, if they exist.
	if($1 != NULL)
	{
		for(std::list<Sort*>::iterator lIter = $1->begin(); lIter != $1->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				$$->push_back((*lIter));
			}
		}
		deallocateList($1);
	}
	if($3 != NULL)
	{
		for(std::list<Sort*>::iterator lIter = $3->begin(); lIter != $3->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				$$->push_back((*lIter));
			}
		}
		deallocateList($3);
	}
}
							;

sort_spec:					  sort_identifier_no_range
{
	// Have a helper function handle making and translating the sort.
	std::list<Sort*>* dummyList = new std::list<Sort*>;
	$$ = processSort($1, dummyList);
	deallocateList(dummyList);
	deallocateItem($1);
	if($$ == NULL)
	{
		YYERROR;
	}
}
							| sort_identifier_no_range T_DBL_GTHAN sort_spec_outer_tuple
{
	// Have a helper function handle making and translating the sort.
	$$ = processSort($1, $3);
	deallocateItem($1);
	deallocateList($3);
	if($$ == NULL)
	{
		YYERROR;
	}
}	
							;

sort_identifier_with_ab:	 sort_outer_identifier
{
	$$ = $1;
}
							| T_STATICAB
{
	// Directly referencing an internal sort, return the name of the desired sort.
	$$ = new std::string("staticAbnormality");
}
							| T_DYNAMICAB
{
	// Directly referencing an internal sort, return the name of the desired sort.
	$$ = new std::string("dynamicAbnormality");
}
							;

sort_outer_identifier:		  			sort_identifier
{
	$$ = $1;
}
							| T_PAREN_L sort_identifier T_PAREN_R
{
	$$ = $2;
}

							;

sort_identifier:
							sort_identifier_no_range
{
	// A standard identifier.
	$$ = $1;
}
							| num_range
{
	// A quick-and-dirty dynamically declared sort.

	// Turn it into a sort and pass it down the chain.
	if($1 != NULL)
	{
		$$ = new std::string();
		*$$ = Translator::numRangeToSortName($1->min, $1->max);
		Sort* tempSort = mainTrans.getSort(*$$);
		if(tempSort == NULL)
		{
			// Have a helper function handle making and translating the sort.
			std::list<Sort*>* dummyList = new std::list<Sort*>; // No subsorts.
			tempSort = processSort($$, dummyList);
			deallocateList(dummyList);
			// Also add the number range as an object for this new sort.
			int addResult = mainTrans.addObject($1);
			if(addResult == SymbolTable::ADDSYM_OK)
			{
				tempSort->domainObjs.push_back($1);
				// Output the translation of the object declaration.
				mainTrans.translateObjectDecl($1, tempSort);
			}
		}
		if(tempSort == NULL)
		{
			// We were unable to allocate the sort properly. Error.
			deallocateItem($1);
			YYERROR;
		}
	} else {
	      // The number range doesn't exist?
	      YYERROR;
	}
}
							;

sort_identifier_no_range:		  		sort_identifier_name
{
	$$ = $1;
}
							| sort_identifier_name T_STAR
{
	$$ = new std::string;
	(*$$) = (*$1) + "*";
	deallocateItem($1);
}
							| sort_identifier_name T_PLUS T_NONE
{
	// Alternate way to express the idea of a starred sort.
	$$ = new std::string;
	(*$$) = (*$1) + "*";
	deallocateItem($1);
}
							;

sort_identifier_name:		  			T_IDENTIFIER
{
	$$ = $1;
}
							| sort_constant_name
{
	$$ = $1
}
							;

sort_constant_name:					T_ABACTION
{
	// Directly referencing an internal sort, return the name of the desired sort.
	$$ = new std::string("abAction");
}
							| T_ACTION
{
	// Directly referencing an internal sort, return the name of the desired sort.
	$$ = new std::string("action");
}
							| T_ADDITIVEACTION
{
	// Directly referencing an internal sort, return the name of the desired sort.
	$$ = new std::string("additiveAction");
}
							| T_ADDITIVEFLUENT
{
	// Directly referencing an internal sort, return the name of the desired sort.
	$$ = new std::string("additiveFluent");
}
							| T_EXOGENOUSACTION
{
	// Directly referencing an internal sort, return the name of the desired sort.
	$$ = new std::string("exogenousAction");
}
							| T_INERTIALFLUENT
{
	// Directly referencing an internal sort, return the name of the desired sort.
	$$ = new std::string("inertialFluent");
}
							| T_RIGID
{
	// Directly referencing an internal sort, return the name of the desired sort.
	$$ = new std::string("rigid");
}
							| T_SDFLUENT
{
	// Directly referencing an internal sort, return the name of the desired sort.
	$$ = new std::string("sdFluent");
}
							| T_SIMPLEFLUENT
{
	// Directly referencing an internal sort, return the name of the desired sort.
	$$ = new std::string("simpleFluent");
}
							;

/* ***Variables*** */

variable_statement:			  T_COLON_DASH T_VARIABLES variable_spec_outer_tuple T_PERIOD		{ $$ = PARSERULE_NOT_USED; }
							;

variable_spec_outer_tuple:	  variable_spec_tuple		{ $$ = PARSERULE_NOT_USED; }
							| T_PAREN_L variable_spec_tuple T_PAREN_R		{ $$ = PARSERULE_NOT_USED; }
							;

variable_spec_tuple:		  variable_outer_spec		{ $$ = PARSERULE_NOT_USED; }
							| variable_outer_spec T_SEMICOLON variable_spec_outer_tuple		{ $$ = PARSERULE_NOT_USED; }
							;

variable_outer_spec:		  variable_spec		{ $$ = PARSERULE_NOT_USED; }
							| T_PAREN_L variable_spec T_PAREN_R		{ $$ = PARSERULE_NOT_USED; }
							;

variable_spec:				  variable_outer_list T_DBL_COLON variable_binding
{
	// Connect the variables in the list to the binding sort, then translate them.
	if($1 != NULL && $3 != NULL)
	{
		std::list<Variable*>::iterator vIter;
		for(vIter = $1->begin(); vIter != $1->end(); ++vIter)
		{
			(*vIter)->sortRef = $3;
			mainTrans.translateVariableDecl(*vIter);
		}
	}
	if($1 != NULL)
	{	// Clear out the list, we don't need it anymore.
		deallocateList($1);
	}
	$$ = PARSERULE_NOT_USED;
}
							;

variable_outer_list:		  variable_list
{
	$$ = $1;
}
							| T_PAREN_L variable_list T_PAREN_R
{
	$$ = $2;
}
							;

variable_list:				  T_IDENTIFIER
{
	// Create a new list of Variables, add this one as the first item.
	$$ = new std::list<Variable*>;
	Variable* tempVar = new Variable(*$1, Translator::sanitizeVariableName(*$1));
	int addSymResult = mainTrans.addVariable(tempVar);
	if(addSymResult != SymbolTable::ADDSYM_OK)
	{
		if(addSymResult == SymbolTable::ADDSYM_DUP)
		{	// Warn about duplicate variable declarations (not an error), then grab the already-declared variable.
			ltsyystartCaution(ltsyylloc);
			ltsyyossErr << "Duplicate variable declaration: \"" << *$1 << "\".";
			ltsyyreportCaution();
			deallocateItem(tempVar);
			tempVar = mainTrans.getVariable(*$1);
			$$->push_back(tempVar);
		}
		else
		{	// A real variable error.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Bad variable declaration: \"" << *$1 << "\".";
			ltsyyreportError();
			deallocateList($$);
			deallocateItem(tempVar);
		}
	}
	else
	{
		$$->push_back(tempVar);
	}
	deallocateItem($1);
	if(tempVar == NULL || $$ == NULL)
	{	// If $$ or tempVar are NULL, something went wrong.
		YYERROR;
	}
}
							| variable_list T_COMMA T_IDENTIFIER
{
	// Merge a new variable declaration into an existing list of variables.
	if($1 == NULL)
	{
		$$ = new std::list<Variable*>;
	}
	Variable* tempVar = new Variable(*$3, Translator::sanitizeVariableName(*$3));
	int addSymResult = mainTrans.addVariable(tempVar);
	if(addSymResult != SymbolTable::ADDSYM_OK)
	{
		if(addSymResult == SymbolTable::ADDSYM_DUP)
		{	// Warn about duplicate variable declarations (not an error), then grab the already-declared variable.
			ltsyystartCaution(ltsyylloc);
			ltsyyossErr << "Duplicate variable declaration: \"" << *$3 << "\".";
			ltsyyreportCaution();
			deallocateItem(tempVar);
			tempVar = mainTrans.getVariable(*$3);
			$$->push_back(tempVar);
		}
		else
		{	// A real variable error.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Bad variable declaration: \"" << *$3 << "\".";
			ltsyyreportError();
			deallocateItem(tempVar);
		}
	}
	else
	{
		$$->push_back(tempVar);
	}
	deallocateItem($3);
	if(tempVar == NULL)
	{	// If tempVar is NULL, something went wrong.
		YYERROR;
	}
}
							;

variable_binding:			  		sort_outer_identifier
{
	// Find the sort in question, create it if it doesn't exist and is a "something*" sort (whose "something" exists already), or report an error.
	$$ = mainTrans.getSort(*$1);
	if($$ == NULL)
	{
		$$ = checkDynamicSortDecl($1); // Reports appropriate errors, we just need to YYERROR if that happens.
	}
	deallocateItem($1);
	if($$ == NULL)
	{	// If $$ is NULL, something went wrong.
		YYERROR;
	}
}
/* This is now included in sort_identifier
							| num_range
{
	// Turn the number range into a sort (if that hasn't happened already).
	$$ = NULL;
	if($1 != NULL)
	{
		std::string numRangeSortName = Translator::numRangeToSortName($1->min, $1->max);
		$$ = mainTrans.getSort(numRangeSortName);
		if($$ == NULL)
		{
			// Have a helper function handle making and translating the sort.
			std::list<Sort*>* dummyList = new std::list<Sort*>; // No subsorts.
			$$ = processSort(&numRangeSortName, dummyList);
			deallocateList(dummyList);
			// Also add the number range as an object for this new sort.
			int addResult = mainTrans.addObject($1);
			if(addResult == SymbolTable::ADDSYM_OK)
			{
				$$->domainObjs.push_back($1);
				// Output the translation of the object declaration.
				mainTrans.translateObjectDecl($1, $$);
			}
		}
	}
	if($$ == NULL)
	{	// If $$ is NULL, something went wrong.
		deallocateItem($1);
		YYERROR;
	}
}
*/
							;

/* ***CLAUSES*** */

/*
 * These denote optional clauses that can be appended to the end of various rules. 
 * As such, they each have an epsilon option which initializes them to null.
 */

cl_if_clause:	/* Empty */			{ $$ = NULL; }
		| T_IF cl_body_formula 		{ $$ = $2;   }
		;
		
cl_assuming_clause: /* Empty */		{ $$ = NULL; }
		| T_ASSUMING cl_body_formula	{ $$ = $2; }
		;

cl_after_clause: /* Empty */			{ $$ = NULL; }
		| T_AFTER cl_body_formula	{ $$ = $2;   }
		;

cl_unless_clause: /* Empty */			{ $$ = NULL; }
		| T_UNLESS constant_expr	{ $$ = $2;   }
		;

cl_when_clause:	/* Empty */			{ $$ = NULL; }
		| T_WHEN cl_when_expr		{ $$ = $2;   }
		;

cl_following_clause: /* Empty */		{ $$ = NULL; }
		| T_FOLLOWING cl_following_expr { $$ = $2;   }
		;

cl_where_clause: /* Empty */			{ $$ = NULL; }
		| T_WHERE cl_where_expr		{ $$ = $2;   }
		;


/* ***LAWS*** */

causal_law:					  	causal_law_shortcut_forms T_PERIOD		{ $$ = PARSERULE_NOT_USED; }
							| causal_law_basic_forms T_PERIOD		{ $$ = PARSERULE_NOT_USED; }
							;

causal_law_shortcut_forms:	  			cl_always_forms			{ $$ = PARSERULE_NOT_USED; }
							| cl_constraint_forms		{ $$ = PARSERULE_NOT_USED; }
							| cl_default_forms		{ $$ = PARSERULE_NOT_USED; }
							| cl_exogenous_forms		{ $$ = PARSERULE_NOT_USED; }
							| cl_inertial_forms		{ $$ = PARSERULE_NOT_USED; }
							| cl_nonexecutable_forms	{ $$ = PARSERULE_NOT_USED; }
							| cl_rigid_forms		{ $$ = PARSERULE_NOT_USED; }
							| cl_possibly_caused_forms	{ $$ = PARSERULE_NOT_USED; }
							| cl_may_cause_forms		{ $$ = PARSERULE_NOT_USED; }
							| cl_causes_forms		{ $$ = PARSERULE_NOT_USED; }
							| cl_noconcurrency_forms	{ $$ = PARSERULE_NOT_USED; }
							| cl_increment_forms		{ $$ = PARSERULE_NOT_USED; }
							| cl_trivial_forms		{ $$ = PARSERULE_NOT_USED; }
							;


cl_always_forms:					T_ALWAYS cl_body_formula cl_when_clause cl_where_clause
{
	bool transResult = handleAlwaysLaw($2, $3, $4);
	deallocateItem($2);
	deallocateItem($3);
	deallocateItem($4);
	$$ = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
							;

cl_constraint_forms:					T_CONSTRAINT cl_body_formula cl_after_clause cl_unless_clause cl_when_clause cl_following_clause cl_where_clause
{
	bool transResult = handleConstraintLaw($2, $3, $4, $5, $6, $7, true);
	deallocateItem($2);
	deallocateItem($3);
	deallocateItem($4);
	deallocateItem($5);
	deallocateItem($6);
	deallocateItem($7);
	$$ = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
							| T_IMPOSSIBLE cl_body_formula cl_after_clause cl_unless_clause cl_when_clause cl_following_clause cl_where_clause
{
	bool transResult = handleConstraintLaw($2, $3, $4, $5, $6, $7, false);
	deallocateItem($2);
	deallocateItem($3);
	deallocateItem($4);
	deallocateItem($5);
	deallocateItem($6);
	deallocateItem($7);
	$$ = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
							| T_NEVER cl_body_formula cl_after_clause cl_unless_clause cl_when_clause cl_following_clause cl_where_clause
{
	bool transResult = handleConstraintLaw($2, $3, $4, $5, $6, $7, false);
	deallocateItem($2);
	deallocateItem($3);
	deallocateItem($4);
	deallocateItem($5);
	deallocateItem($6);
	deallocateItem($7);
	$$ = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
					;

cl_default_forms:					T_DEFAULT cl_head_formula cl_if_clause cl_assuming_clause cl_after_clause cl_unless_clause cl_when_clause cl_following_clause cl_where_clause
{
	bool transResult = handleDefaultLaw($2, $3, $4, $5, $6, $7, $8, $9);
	deallocateItem($2);
	deallocateItem($3);
	deallocateItem($4);
	deallocateItem($5);
	deallocateItem($6);
	deallocateItem($7);
	deallocateItem($8);
	deallocateItem($9);
	$$ = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
							;

cl_exogenous_forms:			  		T_EXOGENOUS constant_expr cl_where_clause
{
	bool transResult = handleDeclarativeLaw($2, NULL, NULL, NULL, NULL, NULL, NULL, $3, SimpleUnaryOperator::UOP_EXOGENOUS);
	deallocateItem($2);
	deallocateItem($3);
	$$ = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
							;

cl_inertial_forms:			  		T_INERTIAL constant_expr cl_where_clause
{
	bool transResult = handleDeclarativeLaw($2, NULL, NULL, NULL, NULL, NULL, NULL, $3, SimpleUnaryOperator::UOP_INERTIAL);
	deallocateItem($2);
	deallocateItem($3);
	$$ = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
							;

cl_nonexecutable_forms:		  			T_NONEXECUTABLE cl_body_formula cl_if_clause cl_when_clause cl_where_clause
{
	bool transResult = handleNonexecutableLaw($2, $3, $4, $5);
	deallocateItem($2);
	deallocateItem($3);
	deallocateItem($4);
	deallocateItem($5);
	$$ = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
							;

cl_rigid_forms:				  		T_RIGID constant_expr cl_where_clause
{
	/*
	 * Let's _try_ to handle this, but we should throw a warning as this statement is not fully supported.
	 */

	ltsyystartWarning(ltsyylloc);
	ltsyyossErr << "Rules of the form \"rigid p [where F]\" are not fully supported and may produce unintended behavior. Please declare the constant as rigid instead.";
	ltsyyreportWarning();

	bool transResult = handleDeclarativeLaw($2, NULL, NULL, NULL, NULL, NULL, NULL, $3, SimpleUnaryOperator::UOP_RIGID);
	deallocateItem($2);
	deallocateItem($3);
	$$ = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
							;

cl_possibly_caused_forms:	  			T_POSSIBLY_CAUSED cl_head_formula cl_if_clause cl_assuming_clause cl_after_clause cl_unless_clause cl_when_clause cl_following_clause cl_where_clause
{
	bool transResult = handlePossiblyCausedLaw($2, $3, $4, $5, $6, $7, $8, $9);
	deallocateItem($2);
	deallocateItem($3);
	deallocateItem($4);
	deallocateItem($5);
	deallocateItem($6);
	deallocateItem($7);
	deallocateItem($8);
	deallocateItem($9);
	$$ = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
							;

cl_may_cause_forms:			  		cl_body_formula T_MAY_CAUSE cl_head_formula cl_if_clause cl_when_clause cl_where_clause
{
	bool transResult = handleMayCauseLaw($1, $3, $4, $5, $6);
	deallocateItem($1);
	deallocateItem($3);
	deallocateItem($4);
	deallocateItem($5);
	deallocateItem($6);
	$$ = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
							;

cl_causes_forms:			 		 cl_body_formula T_CAUSES cl_head_formula cl_if_clause cl_when_clause cl_where_clause
{
	bool transResult = handleCausesLaw($1, $3, $4, $5, $6);
	deallocateItem($1);
	deallocateItem($3);
	deallocateItem($4);
	deallocateItem($5);
	deallocateItem($6);
	$$ = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
							;

cl_noconcurrency_forms:		  			T_NOCONCURRENCY
{
	// This one's easy, it's just a pass-through.
	mainTrans.output("noconcurrency.", Context::BASE, true);
	$$ = PARSERULE_NOT_USED;
}
							| T_STRONG_NOCONCURRENCY
{
	// This one is also very easy.
	mainTrans.output("strong_noconcurrency.", Context::BASE, true);
	$$ = PARSERULE_NOT_USED;
}
							;

cl_increment_forms: 		  			cl_body_formula T_INCREMENTS cl_head_formula T_BY extended_math_expression cl_if_clause cl_when_clause cl_where_clause
{
	bool transResult = handleIncrementLaw($1, $3, $5, $6, $7, $8, true);
	deallocateItem($1);
	deallocateItem($3);
	deallocateItem($5);
	deallocateItem($6);
	deallocateItem($7);
	deallocateItem($8);
	$$ = PARSERULE_NOT_USED;
	
	if(!transResult)
	{
		YYERROR;
	}
}
							|  cl_body_formula T_DECREMENTS cl_head_formula T_BY extended_math_expression cl_if_clause cl_when_clause cl_where_clause
{
	bool transResult = handleIncrementLaw($1, $3, $5, $6, $7, $8, false);
	deallocateItem($1);
	deallocateItem($3);
	deallocateItem($5);
	deallocateItem($6);
	deallocateItem($7);
	deallocateItem($8);
	$$ = PARSERULE_NOT_USED;
	
	if(!transResult)
	{
		YYERROR;
	}
}
							;

cl_trivial_forms:					cl_body_formula
{
	// This is a law of the form c=v.
	// Which is really just a lazy shortcut for
	// caused c=v.

	mainTrans.translateCausalLaw($1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	deallocateItem($1);
	$$ = PARSERULE_NOT_USED;
}
							;

causal_law_basic_forms:		  T_CAUSED cl_head_formula cl_if_clause cl_assuming_clause cl_after_clause cl_unless_clause cl_when_clause cl_following_clause cl_where_clause
{
	mainTrans.translateCausalLaw($2, $3, $4, $5, $6, $7, $8, $9);
	deallocateItem($2);
	deallocateItem($3);
	deallocateItem($4);
	deallocateItem($5);
	deallocateItem($6);
	deallocateItem($7);
	deallocateItem($8);
	deallocateItem($9);
	$$ = PARSERULE_NOT_USED;
}
							;

cl_head_formula:			  		literal_assign_conj
{
	$$ = $1;
}
							| T_TRUE
{
	ObjectLikeElement* tempPE = new ObjectLikeElement();
	tempPE->baseName = "true";
	tempPE->objRef = mainTrans.getObjectLike(tempPE->baseName, 0);
	$$ = tempPE;
}
							| T_FALSE
{
	ObjectLikeElement* tempPE = new ObjectLikeElement();
	tempPE->baseName = "false";
	tempPE->objRef = mainTrans.getObjectLike(tempPE->baseName, 0);
	$$ = tempPE;
}
							;

cl_body_formula:			  		cl_body_formula_inner
{
	$$ = $1;
}
							| T_PAREN_L cl_body_formula_inner T_PAREN_R
{
	if($2 != NULL)
	{
		$2->setParens(true);
	}
	$$ = $2;
}
							;

cl_body_formula_inner:		  cl_body_term
{
	$$ = $1;
}
							| NOT cl_body_formula %prec T_UMINUS
{
	SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
	tempPE->opType = SimpleUnaryOperator::UOP_NOT;
	tempPE->postOp = $2;
	$$ = tempPE;
}
							| cl_body_formula AND cl_body_formula
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_AND;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| cl_body_formula OR cl_body_formula
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_OR;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| cl_body_formula T_EQUIV cl_body_formula
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQUIV;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| cl_body_formula T_IMPL cl_body_formula
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_IMPL;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							;

cl_body_term:				  cl_body_term_inner
{
	$$ = $1;
}
							| T_PAREN_L cl_body_term_inner T_PAREN_R
{
	if($2 != NULL)
	{
		$2->setParens(true);
	}
	$$ = $2;
}
							;

cl_body_term_inner:			  extended_value_expression
{
	// This is really only allowed to be a constant/variable/object expression, verify that.
	if($1 != NULL)
	{
		if($1->getType() != ParseElement::PELEM_BASELIKE && $1->getType() != ParseElement::PELEM_CONSTLIKE && $1->getType() != ParseElement::PELEM_OBJLIKE && $1->getType() != ParseElement::PELEM_VARLIKE)
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Bare expression \"" << $1->fullName() << "\" not allowed there, did you forget an equality or comparison sign?";
			ltsyyreportError();
			deallocateItem($1);
		}
	}
	$$ = $1;
	if($$ == NULL)
	{
		YYERROR;
	}
}
							| extended_value_expression EQUALS extended_value_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQ;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| extended_value_expression NOT_EQUALS extended_value_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_NEQ;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| extended_value_expression COMPARISON extended_value_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	// A bunch of possible operators bundle into COMPARISON. Find out which one.
	switch($2)
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
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| expr_big_expression
{
	$$ = $1;
}
							;

cl_where_expr:				  cl_body_formula
{
	$$ = $1;
}
							;

cl_when_expr:				  cl_body_formula_bool
{
	$$ = $1;
}
							;

cl_following_expr:			  cl_body_formula_bool
{
	$$ = $1;
}							
							;

cl_body_formula_bool:			  cl_body_formula_bool_inner
{
	$$ = $1;
}
							| T_PAREN_L cl_body_formula_bool_inner T_PAREN_R
{
	if($2 != NULL)
	{
		$2->setParens(true);
	}
	$$ = $2;
}
							;

cl_body_formula_bool_inner:	  cl_body_term_bool
{
	$$ = $1;
}
							| NOT cl_body_formula_bool %prec T_UMINUS
{
	SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
	tempPE->opType = SimpleUnaryOperator::UOP_NOT;
	tempPE->postOp = $2;
	$$ = tempPE;
}
							| cl_body_formula_bool AND cl_body_formula_bool
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_AND;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| cl_body_formula_bool OR cl_body_formula_bool
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_OR;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| cl_body_formula_bool T_EQUIV cl_body_formula_bool
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQUIV;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| cl_body_formula_bool T_IMPL cl_body_formula_bool
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_IMPL;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							;

cl_body_term_bool:		 			cl_body_term_bool_inner
{
	$$ = $1;
}
							| T_PAREN_L cl_body_term_bool_inner T_PAREN_R
{
	if($2 != NULL)
	{
		$2->setParens(true);
	}
	$$ = $2;
}
							;

cl_body_term_bool_inner:	  			constant_expr
{
	$$ = $1;
	if($$ == NULL)
	{
		YYERROR;
	}
}
							| expr_big_expression_bool
{
	$$ = $1;
}
							;

literal_assign_conj:		  			literal_assign_conj_inner
{
	$$ = $1;
}
							| T_PAREN_L literal_assign_conj_inner T_PAREN_R
{
	if($2 != NULL)
	{
		$2->setParens(true);
	}
	$$ = $2;
}
							;

literal_assign_conj_inner:	  			literal_assign_expr
{
	$$ = $1;
}
							| literal_assign_conj AND literal_assign_conj
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_AND;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							;

literal_assign_expr:		  			constant_expr
{
	$$ = $1;
}
							| NOT constant_expr %prec T_UMINUS
{
	SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
	tempPE->opType = SimpleUnaryOperator::UOP_NOT;
	tempPE->postOp = $2;
	$$ = tempPE;
}
							| constant_expr T_EQ extended_value_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQ;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							;						;

expr_big_expression:		  			T_BRACKET_L expr_big_quantifiers T_PIPE cl_body_formula T_BRACKET_R
{
	$$ = NULL;
	if($2 != NULL && $4 != NULL)
	{
		BigQuantifiers* tempPE = new BigQuantifiers();
		tempPE->quants = *$2;
		tempPE->postOp = $4;
		deallocateList($2);
		$$ = tempPE;
	}
}
							;

expr_big_expression_bool:	 			T_BRACKET_L expr_big_quantifiers T_PIPE cl_body_formula_bool T_BRACKET_R
{
	$$ = NULL;
	if($2 != NULL && $4 != NULL)
	{
		BigQuantifiers* tempPE = new BigQuantifiers();
		tempPE->quants = *$2;
		tempPE->postOp = $4;
		deallocateList($2);
		$$ = tempPE;
	}
}
							;

expr_big_quantifiers:		  			expr_big_conj
{
	$$ = NULL;
	if($1 != NULL)
	{
		$$ = new std::list<std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>* >();
		$$->push_back($1);
	}
}
							| expr_big_disj
{
	$$ = NULL;
	if($1 != NULL)
	{
		$$ = new std::list<std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>* >();
		$$->push_back($1);
	}
}
							| expr_big_quantifiers expr_big_conj
{
	if($1 != NULL && $2 != NULL)
	{
		$$ = $1;
		$$->push_back($2);
	}
	else
	{
		if($1 != NULL)
		{
			for(std::list<std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>* >::iterator lIter = $1->begin(); lIter != $1->end(); ++lIter)
			{
				if((*lIter)->second != NULL)
				{
					deallocateItem((*lIter)->second);
				}
				deallocateItem(*lIter);
			}
			deallocateList($1);
		}
		if($2 != NULL)
		{
			if($2->second != NULL)
			{
				deallocateItem($2->second);
			}
			deallocateItem($2);
		}
		$$ = NULL;
	}
}
							| expr_big_quantifiers expr_big_disj
{
	if($1 != NULL && $2 != NULL)
	{
		$$ = $1;
		$$->push_back($2);
	}
	else
	{
		if($1 != NULL)
		{
			for(std::list<std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>* >::iterator lIter = $1->begin(); lIter != $1->end(); ++lIter)
			{
				if((*lIter)->second != NULL)
				{
					deallocateItem((*lIter)->second);
				}
				deallocateItem(*lIter);
			}
			deallocateList($1);
		}
		if($2 != NULL)
		{
			if($2->second != NULL)
			{
				deallocateItem($2->second);
			}
			deallocateItem($2);
		}
		$$ = NULL;
	}
}
							;

expr_big_conj:				  T_BIG_CONJ T_IDENTIFIER
{
	$$ = new std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>();
	$$->first = BigQuantifiers::QUANT_CONJ;
	// That identifier better be a variable...
	Variable* varRef = mainTrans.getVariableLike(*$2);
	if(varRef == NULL)
	{
		// It's not. We should tell them.
		// First. Let's figure out exactly what kind of error it is...
		if (mainTrans.getConstantLike(*$2,0) || mainTrans.getObjectLike(*$2,0)) {
			// They've given us something that clearly isn't a variable.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Unexpected token \"" << *$2 << "\" in quantifier. Expected a variable.";
			ltsyyreportError();
		} else {
			// They've given us an undeclared identifier.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << *$2 << "\" is undeclared.";
			ltsyyreportError();
		}
		
		// For the sake of system stability, we'll return a new variable.
		varRef = new Variable();
		varRef->name = *$2;
		varRef->transName = Translator::sanitizeVariableName(*$2);
		
		VariableLikeElement* tempPE = new VariableLikeElement();
		tempPE->baseName = *$2;
		tempPE->varRef = varRef;
		$$->second = tempPE;
		
		
	}
	else
	{
		VariableLikeElement* tempPE = new VariableLikeElement();
		tempPE->baseName = *$2;
		tempPE->varRef = varRef;
		$$->second = tempPE;
	}
	deallocateItem($2);
}
							;

expr_big_disj:				  T_BIG_DISJ T_IDENTIFIER
{
	$$ = new std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>();
	$$->first = BigQuantifiers::QUANT_DISJ;
	// Guess that the identifier is a variable, otherwise just default to object.
	Variable* varRef = mainTrans.getVariableLike(*$2);
	if(varRef == NULL)
	{
		// It's not. We should tell them.
		// First. Let's figure out exactly what kind of error it is...
		if (mainTrans.getConstantLike(*$2,0) || mainTrans.getObjectLike(*$2,0)) {
			// They've given us something that clearly isn't a variable.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Unexpected token \"" << *$2 << "\" in quantifier. Expected a variable.";
			ltsyyreportError();
		} else {
			// They've given us an undeclared identifier.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << *$2 << "\" is undeclared.";
			ltsyyreportError();
		}
		
		// For the sake of system stability, we'll return a new variable.
		varRef = new Variable();
		varRef->name = *$2;
		varRef->transName = Translator::sanitizeVariableName(*$2);
		
		VariableLikeElement* tempPE = new VariableLikeElement();
		tempPE->baseName = *$2;
		tempPE->varRef = varRef;
		$$->second = tempPE;
		
	}
	else
	{
		VariableLikeElement* tempPE = new VariableLikeElement();
		tempPE->baseName = *$2;
		tempPE->varRef = varRef;
		$$->second = tempPE;
	}
	deallocateItem($2);
}
							;

/* ***QUERIES*** */

query_statement:			  		T_COLON_DASH T_QUERY query_expression_tuple T_PERIOD
{
	$$ = PARSERULE_NOT_USED;
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
							;

query_expression_tuple:		  			query_expression
{
	$$ = PARSERULE_NOT_USED;
}
							| query_expression_tuple T_SEMICOLON query_expression_tuple
{
	$$ = PARSERULE_NOT_USED;
}
							;

query_expression:			  		T_LABEL T_DBL_COLON T_INTEGER
{
	$$ = PARSERULE_NOT_USED;
	if(mainTrans.tempQuery->label == "")
	{
		mainTrans.tempQuery->label = utils::to_string($3);
	}
	else
	{
		ltsyystartParseError(ltsyylloc);
		ltsyyossErr << "label already defined as \"" << mainTrans.tempQuery->maxstep << "\" in this query, can only define it once per query.";
		ltsyyreportError();
		YYERROR;
	}
}
							| T_MAXSTEP T_DBL_COLON T_INTEGER
{
	$$ = PARSERULE_NOT_USED;
	if(mainTrans.tempQuery->maxstep == "")
	{
		mainTrans.tempQuery->maxstep = utils::to_string($3);
	}
	else
	{
		ltsyystartParseError(ltsyylloc);
		ltsyyossErr << "maxstep already defined as \"" << mainTrans.tempQuery->maxstep << "\" in this query, can only define it once per query.";
		ltsyyreportError();
		YYERROR;
	}
}
							| T_MAXSTEP T_DBL_COLON T_INTEGER T_DBL_PERIOD T_INTEGER
{
	$$ = PARSERULE_NOT_USED;
	// Explicit declaration of a limited form of a number range that only supports (positive) integers as its bounds.
	if(mainTrans.tempQuery->maxstep == "")
	{
		mainTrans.tempQuery->maxstep = utils::to_string($3);
		mainTrans.tempQuery->maxstep += "..";
		mainTrans.tempQuery->maxstep += utils::to_string($5);
	}
	else
	{
		ltsyystartParseError(ltsyylloc);
		ltsyyossErr << "maxstep already defined as \"" << mainTrans.tempQuery->maxstep << "\" in this query, can only define it once per query.";
		ltsyyreportError();
		YYERROR;
	}
}
							| query_body_formula
{
	$$ = PARSERULE_NOT_USED;
	if($1 != NULL)
	{
		// Add this new condition to the temp query.
		mainTrans.tempQuery->queryConditions.push_back($1);
	}
	else
	{
		ltsyystartWarning(ltsyylloc);
		ltsyyossErr << "Query body formula is NULL!";
		ltsyyreportWarning();
	}
}
							;

// This is like cl_body_formula, but allows "EXPR:formula" in addition to just "formula".
query_body_formula:			 		 query_body_formula_inner
{
	$$ = $1;
}
							| T_PAREN_L query_body_formula T_PAREN_R
{
	if($2 != NULL)
	{
		$2->setParens(true);
	}
	$$ = $2;
}
							| extended_math_expr_inner T_COLON query_body_formula
{
	// Turn the time stamp into a plain, translated string representation, then propogate it through the body formula.
	std::string tempTimeStamp = "UNKNOWN";
	if($1 != NULL)
	{
		ClauseList throwaway;
		tempTimeStamp =  Translator::sanitizeObjectName(((ObjectLikeElement*)$1)->baseName);
		deallocateItem($1);
	}
	if($3 != NULL)
	{
		$3->setQueryTimeStamp(tempTimeStamp);
	}
	else
	{
		ltsyystartWarning(ltsyylloc);
		ltsyyossErr << "Query body formula with time stamp \"" << tempTimeStamp << "\" is NULL!";
		ltsyyreportWarning();
	}
	$$ = $3;
}
							;

query_body_formula_inner:	  			query_body_term
{
	$$ = $1;
}
							| NOT query_body_formula %prec T_UMINUS
{
	SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
	tempPE->opType = SimpleUnaryOperator::UOP_NOT;
	tempPE->postOp = $2;
	$$ = tempPE;
}
							| query_body_formula AND query_body_formula
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_AND;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| query_body_formula OR query_body_formula
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_OR;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| query_body_formula T_EQUIV query_body_formula
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQUIV;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| query_body_formula T_IMPL query_body_formula
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_IMPL;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							;

query_body_term:			  		query_body_term_inner
{
	$$ = $1;
}
							| T_PAREN_L query_body_term_inner T_PAREN_R
{
	if($2 != NULL)
	{
		$2->setParens(true);
	}
	$$ = $2;
}
							;

query_body_term_inner:		  			extended_value_expression
{
	// This is really only allowed to be a constant/variable/object expression, verify that.
	if($1 != NULL)
	{
		if($1->getType() != ParseElement::PELEM_BASELIKE && $1->getType() != ParseElement::PELEM_CONSTLIKE && $1->getType() != ParseElement::PELEM_OBJLIKE && $1->getType() != ParseElement::PELEM_VARLIKE)
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Bare expression \"" << $1->fullName() << "\" not allowed there, did you forget an equality or comparison sign?";
			ltsyyreportError();
			deallocateItem($1);
		}
	}
	$$ = $1;
	if($$ == NULL)
	{
		YYERROR;
	}
}
							| extended_value_expression EQUALS extended_value_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_EQ;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| extended_value_expression NOT_EQUALS extended_value_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_NEQ;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| extended_value_expression COMPARISON extended_value_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	// A bunch of possible operators bundle into COMPARISON. Find out which one.
	switch($2)
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
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| expr_big_query_expression
{
	$$ = $1;
}
							;

expr_big_query_expression:		  		T_BRACKET_L expr_big_quantifiers T_PIPE query_body_formula T_BRACKET_R
{
	$$ = NULL;
	if($2 != NULL && $4 != NULL)
	{
		BigQuantifiers* tempPE = new BigQuantifiers();
		tempPE->quants = *$2;
		tempPE->postOp = $4;
		deallocateList($2);
		$$ = tempPE;
	}
}
							;

/* ***MISC*** */

constant_expr:				  		lua_indicator T_IDENTIFIER
{
	// Guess what kind of instance this might be, go with the best match.
	// Guess variable, then constant, then try object.
	Variable* varRef = mainTrans.getVariableLike(*$2);
	if(varRef == NULL)
	{
		Constant* constRef = mainTrans.getConstantLike(*$2,0);
		if(constRef == NULL || $1 != NULL)
		{
			Object* objRef = mainTrans.getObjectLike(*$2,0, $1 != NULL);
			
			if (objRef == NULL) {
				// This doesn't appear to be a declared identifier.
				// Bitch.
				
				ltsyystartParseError(ltsyylloc);
				ltsyyossErr << "\"" << *$2 << "\" appears to be undeclared.";
				ltsyyreportError();
				$$ = NULL;
				
				// For the sake of system stability, we'll return an object.z
				ObjectLikeElement* tempPE = new ObjectLikeElement();
				tempPE->baseName = *$2;
				tempPE->objRef = objRef;
				$$ = tempPE;
			
			}
			ObjectLikeElement* tempPE = new ObjectLikeElement();
			tempPE->baseName = *$2;
			tempPE->objRef = objRef;
			$$ = tempPE;
		}
		else
		{
			ConstantLikeElement* tempPE = new ConstantLikeElement();
			tempPE->baseName = *$2;
			tempPE->constRef = constRef;
			$$ = tempPE;
		}
	}
	else
	{
		VariableLikeElement* tempPE = new VariableLikeElement();
		tempPE->baseName = *$2;
		tempPE->varRef = varRef;
		$$ = tempPE;
	}
	deallocateItem($1);
	deallocateItem($2);
}
							| lua_indicator T_IDENTIFIER T_PAREN_L parameter_list T_PAREN_R
{
	// Guess what kind of instance this might be, go with the best match.
	// Guess constant, then try object.
	Constant* constRef = mainTrans.getConstantLike(*$2,$4->size());
	if(constRef == NULL || $1 != NULL)
	{
		Object* objRef = mainTrans.getObjectLike(*$2,$4->size(), $1 != NULL);
		
		if (objRef == NULL) {
			// This doesn't appear to be a declared identifier.
			// Bitch.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << *$2 << "\" appears to be undeclared.";
			ltsyyreportError();
			$$ = NULL;
			
			// For the sake of system stability, we'll return an object.
			ObjectLikeElement* tempPE = new ObjectLikeElement();
			tempPE->baseName = *$2;
			tempPE->objRef = objRef;
			tempPE->params = *$4;
			$$ = tempPE;
				
		
		}
		
		ObjectLikeElement* tempPE = new ObjectLikeElement();
		tempPE->baseName = *$2;
		tempPE->objRef = objRef;
		$$ = tempPE;
	}
	else
	{
		ConstantLikeElement* tempPE = new ConstantLikeElement();
		tempPE->baseName = *$2;
		tempPE->constRef = constRef;
		$$ = tempPE;
	}
	// Add the parameters.
	if($4 != NULL)
	{
		for(std::vector<ParseElement*>::iterator vIter = $4->begin(); vIter != $4->end(); ++vIter)
		{
			((BaseLikeElement*)$$)->params.push_back(*vIter);
		}
	}
	deallocateItem($1);
	deallocateItem($2);
	deallocateList($4);
}
							;
							
							
lua_indicator:				/* empty */				{ $$ = NULL; }
							| T_AT					{ $$ = new std::string("@"); }

parameter_list:				  		parameter_general
{
	$$ = NULL;
	if($1 != NULL)
	{
		$$ = new std::vector<ParseElement*>();
		$$->push_back($1);
	}
}
							| parameter_list T_COMMA parameter_general
{
	$$ = NULL;
	if($1 != NULL && $3 != NULL)
	{
		$$ = $1;
		$$->push_back($3);
	}
}
							;

parameter_general:			 		extended_math_expression
{
	$$ = $1;
}
							;

sort_identifier_list:		  			sort_identifier
{
	Sort* tempSort = mainTrans.getSort(*$1);
	$$ = NULL;
	if(tempSort != NULL)
	{
		$$ = new std::list<Sort*>;
		$$->push_back(tempSort);
	}
	else
	{
		ltsyystartParseError(ltsyylloc);
		ltsyyossErr << "Sort \"" << *$1 << "\" not declared, can't use as part of another declaration.";
		ltsyyreportError();
	}
	deallocateItem($1);
	if($$ == NULL)
	{	// If $$ is NULL, something went wrong.
		YYERROR;
	}
}
							| sort_identifier_list T_COMMA sort_identifier
{
	$$ = NULL;
	if($1 != NULL)
	{
		$$ = $1;
		Sort* tempSort = mainTrans.getSort(*$3);
		if(tempSort != NULL)
		{
			$$->push_back(tempSort);
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << *$3 << "\" not declared, can't use as part of another declaration.";
			ltsyyreportError();
			deallocateList($$);
		}
	}
	deallocateItem($3);
	if($$ == NULL)
	{	// If $$ is NULL, something went wrong.
		YYERROR;
	}
}
							;

extended_value_expression:	 			T_TRUE
{
	ObjectLikeElement* tempPE = new ObjectLikeElement();
	tempPE->baseName = "true";
	tempPE->objRef = mainTrans.getObjectLike(tempPE->baseName, 0);
	$$ = tempPE;
}
							| T_FALSE
{
	ObjectLikeElement* tempPE = new ObjectLikeElement();
	tempPE->baseName = "false";
	tempPE->objRef = mainTrans.getObjectLike(tempPE->baseName, 0);
	$$ = tempPE;
}
							| T_NONE
{
	ObjectLikeElement* tempPE = new ObjectLikeElement();
	tempPE->baseName = "none";
	tempPE->objRef = mainTrans.getObjectLike(tempPE->baseName, 0);
	$$ = tempPE;
}
							| extended_math_expression
{
	$$ = $1;
}
							;

extended_math_expression:	  			extended_math_expr_inner
{
	$$ = $1;
}
							| T_PAREN_L extended_math_expr_inner T_PAREN_R
{
	$$ = NULL;
	if($2 != NULL)
	{
		$$ = $2;
		$$->setParens(true);
	}
}
							;

extended_math_expr_inner:	  			extended_math_term
{
	$$ = $1;
}
							| extended_math_expression T_PLUS extended_math_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_PLUS;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| extended_math_expression T_DASH extended_math_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_MINUS;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| extended_math_expression T_STAR extended_math_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_TIMES;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| extended_math_expression T_INT_DIV extended_math_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_DIVIDE;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| extended_math_expression T_MOD extended_math_expression
{
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_MOD;
	tempPE->preOp = $1;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							| T_ABS extended_math_expression
{
	SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
	tempPE->opType = SimpleUnaryOperator::UOP_ABS;
	tempPE->postOp = $2;
	$$ = tempPE;
}
							| T_ABS T_PAREN_L extended_math_expression T_PAREN_R
{
	// Not necessary to flag parenBefore and parenAfter, translation of abs
	// automatically adds parentheses around the expression.
	SimpleUnaryOperator* tempPE = new SimpleUnaryOperator();
	tempPE->opType = SimpleUnaryOperator::UOP_ABS;
	tempPE->postOp = $3;
	$$ = tempPE;
}
							;

extended_math_term:			  		extended_integer
{
	ObjectLikeElement* tempPE = new ObjectLikeElement();
	tempPE->baseName = *$1;
	tempPE->objRef = mainTrans.getObjectLike(tempPE->baseName, 0);
	$$ = tempPE;
	deallocateItem($1);
}
							| constant_expr
{
	$$ = $1;
}
							;

num_range:					  	extended_integer_outer_expression T_DBL_PERIOD extended_integer_outer_expression
{
	$$ = new NumberRange();
	std::string tempStr = (*$1);
	tempStr += "..";
	tempStr += (*$3);
	$$->name = tempStr;
	$$->transName = Translator::sanitizeObjectName(tempStr);
	$$->min = (*$1);
	$$->max = (*$3);
	deallocateItem($1);
	deallocateItem($3);
}
							;

extended_integer:			  		T_INTEGER
{
	$$ = new std::string();
	(*$$) = utils::to_string($1);
}
							| T_MAXADDITIVE
{
	$$ = new std::string;
	(*$$) = "maxAdditive";
}
							| T_MAXSTEP
{
	$$ = new std::string;
	(*$$) = "maxstep";
}
							| T_DASH extended_integer %prec T_UMINUS
{
	$$ = new std::string();
	(*$$) = "-";
	(*$$) += (*$2);
	deallocateItem($2);
}
							;

extended_integer_outer_expression: 			extended_integer_expression
{
	$$ = $1;
}
							| T_PAREN_L extended_integer_expression T_PAREN_R
{
	$$ = new std::string();
	(*$$) += "(";
	(*$$) += (*$2);
	(*$$) += ")";
	deallocateItem($2);
}
							;

extended_integer_expression:  				extended_integer
{
	$$ = $1;
}
							| extended_integer_outer_expression T_PLUS extended_integer_outer_expression
{
	$$ = new std::string();
	(*$$) += (*$1);
	(*$$) += " + ";
	(*$$) += (*$3);
	deallocateItem($1);
	deallocateItem($3);
}
							| extended_integer_outer_expression T_DASH extended_integer_outer_expression
{
	$$ = new std::string();
	(*$$) += (*$1);
	(*$$) += " - ";
	(*$$) += (*$3);
	deallocateItem($1);
	deallocateItem($3);
}
							| extended_integer_outer_expression T_STAR extended_integer_outer_expression
{
	$$ = new std::string();
	(*$$) += (*$1);
	(*$$) += " * ";
	(*$$) += (*$3);
	deallocateItem($1);
	deallocateItem($3);
}
							| extended_integer_outer_expression T_INT_DIV extended_integer_outer_expression
{
	$$ = new std::string();
	(*$$) += (*$1);
	(*$$) += " // ";
	(*$$) += (*$3);
	deallocateItem($1);
	deallocateItem($3);
}
							| extended_integer_outer_expression T_MOD extended_integer_outer_expression
{
	$$ = new std::string();
	(*$$) += (*$1);
	(*$$) += " mod ";
	(*$$) += (*$3);
	deallocateItem($1);
	deallocateItem($3);
}
							;

/* Collections of symbols that stand for idential or grouped operations */
AND:						  	T_AMP
{
	$$ = $1;
}
							| T_DBL_AMP
{
	$$ = $1;
}
							| T_COMMA
{
	$$ = $1;
}
							;

OR:							  T_DBL_PLUS
{
	$$ = $1;
}
							;

NOT:						  T_DASH %prec T_UMINUS
{
	$$ = T_UMINUS;
}
							| T_NOT
{
	$$ = $1;
}
							;

EQUALS:						  T_EQ
{
	$$ = $1;
}
							;

NOT_EQUALS:					  T_NOT_EQ
{
	$$ = $1;
}
							| T_AT T_LTHAN
{
	// This means "less than in sorted order", which can be safely approximated with !=.
	$$ = $2;
}
							| T_AT T_GTHAN
{
	// This means "greater than in sorted order", which can be safely approximated with !=.
	$$ = $2;
}
							;

COMPARISON:					  T_DBL_EQ
{
	$$ = $1;
}
							| LESS_THAN
{
	$$ = $1;
}
							| GREATER_THAN
{
	$$ = $1;
}
							| LESS_THAN_EQ
{
	$$ = $1;
}
							| GREATER_THAN_EQ
{
	$$ = $1;
}
							;

LESS_THAN:					  T_LTHAN
{
	$$ = $1;
}
							;

GREATER_THAN:				  T_GTHAN
{
	$$ = $1;
}
							;

LESS_THAN_EQ:				  T_EQ_LTHAN
{
	$$ = $1;
}
							| T_AT T_EQ_LTHAN
{
	// This means "less than or equal to in sorted order", which has no good approximation except for <=.
	$$ = $2;
}
							;

GREATER_THAN_EQ:			  T_GTHAN_EQ
{
	$$ = $1;
}
							| T_AT T_GTHAN_EQ
{
	// This means "greater than or equal to in sorted order", which has no good approximation except for >=.
	$$ = $2;
}
							;

%%

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
