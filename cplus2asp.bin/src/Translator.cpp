#include <list>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

#include "types.h"

#include "Context.h"
#include "parser_types.h"
#include "Attribute.h"
#include "Constant.h"
#include "Element.h"
#include "Object.h"
#include "NumberRange.h"
#include "Sort.h"
#include "Variable.h"
#include "Query.h"
#include "parser.h"
#include "ElementCounter.h"
#include "Constant.h"

#include "utilities.h"

#include "parser_types.h"
#include "parser.h"

#include "Translator.h"

/// When converting a number range to a sort name, this is the prefix that will be attached.
#define NUMRANGE_TO_SORT_PREFIX "numRange"
/// The prefix to stick on constant names when they need to be sanitized.
#define SANITIZE_CONST_PREFIX "saniConst_"
/// The prefix to stick on object names when they need to be sanitized.
#define SANITIZE_OBJ_PREFIX "saniObj_"
/// The prefix to stick on sort names when they need to be sanitized.
#define SANITIZE_SORT_PREFIX "saniSort_"
/// The prefix to stick on variable names when they need to be sanitized.
#define SANITIZE_VAR_PREFIX "SaniVar_"
/// The prefix used to variable-ify sort names.
#define SORT_TO_VAR_PREFIX "V_"
/// What to use to replace "bad" characters in a string that needs to be sanitized.
#define SANITIZE_STR_REPLACE "x"

/* Static class methods */

// Santitizes a constant name so it's compatible with ASP naming conventions.
std::string Translator::sanitizeConstantName(std::string const& originalName)
{
	std::string tempStr = "";
	// If the name starts with an underscore, number, or upper-case letter,
	// prepend a sanitizing prefix, otherwise just use the original name.
	// Does not check originalName for "invalid" characters.
	if(originalName.length() > 0)
	{
		if(originalName[0] == '_' || utils::isDigit(originalName[0]) || utils::isUppercase(originalName[0]))
		{
			tempStr += SANITIZE_CONST_PREFIX;
			tempStr += originalName;
		}
		else
		{
			tempStr += originalName;
		}
	}
	return tempStr;
}

// Santitizes an object name so it's compatible with ASP naming conventions.
std::string Translator::sanitizeObjectName(std::string const& originalName)
{
	std::string tempStr = "";
	// If the name starts with an underscore or upper-case letter,
	// prepend a sanitizing prefix, otherwise just use the original name.
	// Checks for math symbols that need transforming.
	if(originalName.length() > 0)
	{
		if(originalName[0] == '_' || utils::isUppercase(originalName[0]))
		{
			tempStr += SANITIZE_OBJ_PREFIX;
			tempStr += originalName;
		}
		else
		{
			tempStr += originalName;
		}
		// Turn CCalc integer division into ASP integer division.
		size_t transPos = tempStr.find("//");
		while(transPos != std::string::npos)
		{
			tempStr.replace(transPos, 2, "/");
			transPos = tempStr.find("//");
		}
		// Turn CCalc "mod" into ASP modulus.
		transPos = tempStr.find("mod");
		while(transPos != std::string::npos)
		{
			tempStr.replace(transPos, 3, "\\");
			transPos = tempStr.find("mod");
		}
	}
	return tempStr;
}

// Santitizes a sort name so it's compatible with ASP naming conventions.
std::string Translator::sanitizeSortName(std::string const& originalName)
{
	std::string tempStr = "";
	// If the name starts with an underscore, number, or upper-case letter,
	// prepend a sanitizing prefix, otherwise just use the original name.
	// Checks original name for "*" and turns it into "_star".
	if(originalName.length() > 0)
	{
		if(originalName[0] == '_' || utils::isDigit(originalName[0]) || utils::isUppercase(originalName[0]))
		{
			tempStr += SANITIZE_SORT_PREFIX;
		}
		for(size_t i = 0; i < originalName.length(); i++)
		{
			if(originalName[i] == '*')
			{
				tempStr += "_star";
			}
			else
			{
				tempStr += originalName[i];
			}
		}
	}
	return tempStr;
}

// Santitizes a variable name so it's compatible with ASP naming conventions.
std::string Translator::sanitizeVariableName(std::string const& originalName)
{
	std::string tempStr = "";
	// If the name starts with an underscore, number, or lower-case letter,
	// prepend a sanitizing prefix, otherwise just use the original name.
	// Does not check originalName for "invalid" characters.
	if(originalName.length() > 0)
	{
		if(originalName[0] == '_' || utils::isDigit(originalName[0]) || utils::isLowercase(originalName[0]))
		{
			tempStr += SANITIZE_VAR_PREFIX;
			tempStr += originalName;
		}
		else
		{
			tempStr += originalName;
		}
	}
	return tempStr;
}

// Sanitizes an arbitrary string so it's compatible with ASP syntax for predicates.
std::string Translator::sanitizeString(std::string const& originalString)
{
	std::string tempStr = "";
	if(originalString.length() > 0)
	{
		// If the string starts with an underscore or upper-case letter,
		// prepend a sanitizing prefix.
		if(originalString[0] == '_' || utils::isUppercase(originalString[0]))
		{
			tempStr += SANITIZE_STR_REPLACE;
		}
		// If any characters in the string are not alphanumeric or underscores,
		// replace them with a sanitized character.
		for(size_t i = 0; i < originalString.length(); i++)
		{
			if(originalString[i] != '_' && !utils::isLetter(originalString[i]) && !utils::isDigit(originalString[i]))
			{
				tempStr += SANITIZE_STR_REPLACE;
			}
			else
			{
				tempStr += originalString[i];
			}
		}
	}
	return tempStr;
}

// Static version of translateVariableDecl that returns the result as a string instead of sending the result to an output stream.
std::string Translator::translateVariableDeclToString(Variable const* transVar)
{
	std::ostringstream retStream;
	// Sanity check: make sure the variable isn't NULL and neither is its sort.
	if(transVar && transVar->domain())
	{
		// Variable declarations are just domain variable declarations.
		retStream << "#domain " << transVar->domain()->fullTransName() << "(";
		retStream << transVar->fullTransName() << ").";
	}
	return retStream.str();
}

// Returns a standardized sort name representing a range of numbers.
std::string Translator::numRangeToSortName(std::string const& min, std::string const& max)
{
	std::string tempStr = NUMRANGE_TO_SORT_PREFIX;
	tempStr += Context::ANON_STR;
	tempStr += Translator::sanitizeString(min);
	tempStr += Context::ANON_STR;
	tempStr += Translator::sanitizeString(max);
	return tempStr;
}

// Turns a sort name into a variable version of itself.
std::string Translator::sortNameToVariable(std::string const& sortName, bool sanitizeFirst)
{
	std::string tempStr = "";
	std::string baseName = "";
	if(sanitizeFirst)
	{
		baseName = Translator::sanitizeSortName(sortName);
	}
	else
	{
		baseName = sortName;
	}
	// Prepend a variable-compatible prefix to the sort name, then call
	// the variable name sanitizer on the result to ensure it's a good name.
	if(baseName.length() > 0)
	{
		tempStr += SORT_TO_VAR_PREFIX;
		tempStr += baseName;
		tempStr = Translator::sanitizeVariableName(tempStr);
	}
	return tempStr;
}

// Merges two sub-formulas together into one formula.
ParseElement* Translator::mergeSubFormulas(ParseElement* first, ParseElement* second)
{
	return new SimpleBinaryOperator(first, SimpleBinaryOperator::BOP_AND, second);
}

/* Normal class methods */

// Default constructor. Initializes attributes to blank/empty.
Translator::Translator()
{
	Sort *newSort, *additiveConstantSort, *actionSort;
	SortList tmpList;

	/**************************************** Initialize IO ********************************************/
	// Open a null file output and set ostNull to it.
	fNull.open("/dev/null");
	ostNullPtr = new std::ostream(fNull.rdbuf());

	// Start ostOutPtr and ostErrPtr using fNull as well.
	ostOutPtr = new std::ostream(ostNullPtr->rdbuf());
	ostErrPtr = new std::ostream(ostNullPtr->rdbuf());

	// Allocate an initial tempQuery.
	tempQuery = new Query();

	/**************************************** Initialize Sorts ********************************************/

	// Create boolean / boolean* domains
	newSort = this->createInternalSort("boolean*", NULL);
	newSort = this->getSort("boolean");
	this->createInternalObject("true", NULL, newSort);
	this->createInternalObject("false", NULL, newSort);

	// Create step/astep domains, the action time sort.
	newSort = this->createInternalSort("astep", NULL);
	this->createInternalNumRange("0..maxstep-1", newSort);
	tmpList.push_back(newSort);
	newSort = this->createInternalSort("step", &tmpList);
	tmpList.clear();
	this->createInternalObject("maxstep", NULL, newSort);

	// The additiveConstant sort is a supersort for both additiveFluent and additiveAction.
	additiveConstantSort = this->createInternalSort("additiveConstant", NULL);


	// Action sorts.
	tmpList.push_back(this->createInternalSort("abAction", NULL));
	tmpList.push_back(this->createInternalSort("attribute", NULL));
	tmpList.push_back(this->createInternalSort("exogenousAction", NULL));
	newSort = this->createInternalSort("additiveAction", NULL);
	additiveConstantSort->addSubsort(newSort);
	tmpList.push_back(newSort);
	actionSort = this->createInternalSort("action", &tmpList);
	tmpList.clear();

	// Fluent sorts.
	tmpList.push_back(this->createInternalSort("inertialFluent", NULL));
	newSort = this->createInternalSort("additiveFluent", NULL);
	additiveConstantSort->addSubsort(newSort);
	tmpList.push_back(newSort);
	newSort = this->createInternalSort("simpleFluent", &tmpList); 			// inertialFluent and additiveFluent are both simpleFluents
	tmpList.clear();
	tmpList.push_back(newSort);
	tmpList.push_back(this->createInternalSort("sdFluent", NULL));
	tmpList.push_back(this->createInternalSort("rigid", NULL));				// Rigids aren't technically "fluents" after translation, but in CCalc they still are.
	this->createInternalSort("fluent", &tmpList);
	tmpList.clear();

	// Additive range sorts
	newSort = this->createInternalSort("nnAdditiveInteger", NULL);				// positive integer sort.
	this->createInternalNumRange("0..maxAdditive", newSort);
	newSort = this->createInternalSort("additiveInteger", NULL);				// positive + negative integer sort.
	this->createInternalNumRange("-maxAdditive..maxAdditive", newSort);

	
	// Add the contribution constant for additive constants.
	tmpList.push_back(actionSort);
	tmpList.push_back(additiveConstantSort);
	Constant* contribution = new Constant("contribution", newSort, Constant::CONST_ACTION, (ConstSortList*)&tmpList);
	tmpList.clear();
	addConstant(contribution);
	
	// we want to use a dynamic translation.
	setStaticTranslation(false);

	blnFoundAbnormalities = false;
	blnFoundAdditive = false;

	// Initialize the incremental part
	mCurrentPart = IPART_NONE;


}

// Searches for a Constant object matching the given name and parameters.
Constant* Translator::getConstant(std::string const& symName, NameList const& symParams)
{
	Constant* retVal = NULL;
	size_t paramSize;

	paramSize = symParams.size();

	for (std::list<Constant*>::iterator cIter = constants.begin(); cIter != constants.end(); cIter++) {
		if((*cIter)->baseName() == symName && (*cIter)->arity() == paramSize) {
			bool paramsMatch = true;
			for(size_t i = 0; i < paramSize; i++) {
				// We consider NULL a wild card.
				if (!((*cIter)->param(i))) continue;

				if((*cIter)->param(i)->baseName() != symParams[i]) {
					paramsMatch = false;
					break;
				}
			}

			if(paramsMatch) {
				retVal = *cIter;
				break;
			}
		}
	}

	return retVal;
}

// Searches for a Constant object matching the given name and parameters.
Constant* Translator::getConstant(std::string const& symName, SortList const* symParams)
{
	Constant* retVal = NULL;
	size_t paramSize;

	if (!symParams) paramSize = 0;
	else paramSize = symParams->size();

	for (std::list<Constant*>::iterator cIter = constants.begin(); cIter != constants.end(); cIter++) {
		if((*cIter)->baseName() == symName && (*cIter)->arity() == paramSize) {
			bool paramsMatch = true;
			for(size_t i = 0; i < paramSize; i++) {
				// We consider NULL a wild card.
				if (!(*cIter)->param(i) || !(*symParams)[i]) continue;

				// pointer-wise comparison.
				if((*cIter)->param(i) != (*symParams)[i]) {
					paramsMatch = false;
					break;
				}
			}

			if(paramsMatch) {
				retVal = *cIter;
				break;
			}
		}
	}

	return retVal;
}


// Searches for a Object object matching the given name and parameters.
Object* Translator::getObject(std::string const& symName, NameList const* symParams)
{
	Object* retVal = NULL;
	size_t paramSize;

	if (!symParams) paramSize = 0;
	else paramSize = symParams->size();

	for (std::list<Object*>::iterator oIter = objects.begin(); oIter != objects.end(); oIter++) {
		if((*oIter)->baseName() == symName && (*oIter)->arity() == paramSize) {
			bool paramsMatch = true;
			for(size_t i = 0; i < paramSize; i++) {
				if((*oIter)->param(i)->baseName() != (*symParams)[i]) {
					paramsMatch = false;
					break;
				}
			}

			if(paramsMatch) {
				retVal = *oIter;
				break;
			}
		}
	}
	return retVal;
}

// Searches for a Sort object matching the given name.
Sort* Translator::getSort(std::string const& symName)
{
	Sort* retVal = NULL;
	for (std::list<Sort*>::iterator sIter = sorts.begin(); sIter != sorts.end(); sIter++)
	{
		if((*sIter)->baseName() == symName)
		{
			retVal = *sIter;
			break;
		}
	}
	return retVal;
}

// Searches for a Variable object matching the given name.
Variable* Translator::getVariable(std::string const& symName)
{
	Variable* retVal = NULL;
	for(std::list<Variable*>::iterator vIter = variables.begin(); vIter != variables.end(); vIter++)
	{
		if((*vIter)->baseName() == symName)
		{
			retVal = *vIter;
			break;
		}
	}
	return retVal;
}

// Searches for a Query object with the given label
Query* Translator::getQuery(std::string const& testLabel)
{
	Query* retVal = NULL;
	for(std::list<Query*>::iterator qIter = queries.begin(); qIter != queries.end(); qIter++)
	{
		if((*qIter)->label == testLabel)
		{
			retVal = *qIter;
			break;
		}
	}
	return retVal;
}

// Searches for a Constant object matching the given name and number of parameters.
Constant* Translator::getConstantLike(std::string const& symName, size_t numParams)
{
	Constant* retVal = NULL;
	for (std::list<Constant*>::iterator cIter = constants.begin(); cIter != constants.end(); cIter++)
	{
		if((*cIter)->baseName() == symName && (*cIter)->arity() == numParams)
		{
			retVal = *cIter;
			break;
		}
	}
	return retVal;
}

// Searches for a Object object matching the given name and number of parameters.
Object* Translator::getObjectLike(std::string const& symName, size_t numParams, bool isLua)
{
	Object* retVal = NULL;
	for (std::list<Object*>::iterator oIter = objects.begin(); oIter != objects.end(); oIter++)
	{
		if((*oIter)->baseName() == symName && (*oIter)->arity() == numParams && (*oIter)->isLua() == isLua)
		{
			retVal = *oIter;
			break;
		}
	}

	// Allow lua objects to be dynamically declared.
	if (retVal == NULL && isLua) {
		// Ensure that we preserve the name of the object and append the LUA symbol.
		retVal = new Object(symName, numParams);
		addObject(retVal);
	}

	return retVal;
}

Object* Translator::getOrCreateSimpleObjectLike(std::string const& symName, Object::ObjectType type) {
	Object* ret = getObjectLike(symName, 0, false);

	if (!ret) {
		ret = new Object(symName, type, NULL);
		addObject(ret);
	}

	return ret;
}


// Searches for a Sort object like one matching the given name.
// No difference between this and getSort, just call that.
Sort* Translator::getSortLike(std::string const& symName)
{
	Sort* retVal = this->getSort(symName);
	return retVal;
}

// Searches for a Variable object like one matching the given name.
// No difference between this and getVariable, just call that.
Variable* Translator::getVariableLike(std::string const& symName)
{
	Variable* retVal = this->getVariable(symName);
	return retVal;
}

// Attempts to add a new Constant object to the translator's data structures and the symbol table.
int Translator::addConstant(Constant* newConst)
{
	int retVal = SymbolTable::ADDSYM_ERR; // Start pessimistic.
	NameList paramNames;

	if(newConst)
	{
		// Try adding it into the symbol table, and then into local data structures if successful.
		newConst->getParamFullNames(paramNames);
		retVal = symbols.addSymbol(newConst->baseName(), &paramNames, SymbolNode::SYM_CONST);
		if(retVal == SymbolTable::ADDSYM_OK)
		{
			// Connect the symbol definition to the actual Element instance, then save the Element.
			SymbolNode* tempSym = symbols.getLastSymbol();
			tempSym->symbolElement = newConst;
			constants.push_back(newConst);
		}
	}

	return retVal;
}

// Adds a new Object instance to the translator's data structures.
int Translator::addObject(Object* newObj)
{
	int retVal = SymbolTable::ADDSYM_ERR; // Start pessimistic.
	if(newObj)
	{
		// Duplicate objects can exist, so forego adding it to the symbol table
		// and just add it naively to the translator's data structures.
		objects.push_back(newObj);
		retVal = SymbolTable::ADDSYM_OK;
	}
	return retVal;
}

// Attempts to add a new Sort object to the translator's data structures and the symbol table.
int Translator::addSort(Sort* newSort)
{
	int retVal = SymbolTable::ADDSYM_ERR; // Start pessimistic.
	if(newSort)
	{
		// Try adding it into the symbol table, and then into local data structures if successful.
		retVal = symbols.addSymbol(newSort->baseName(), NULL, SymbolNode::SYM_SORT);
		if(retVal == SymbolTable::ADDSYM_OK)
		{
			// Connect the symbol definition to the actual Element instance, then save the Element.
			SymbolNode* tempSym = symbols.getLastSymbol();
			tempSym->symbolElement = newSort;
			sorts.push_back(newSort);
		}
	}
	return retVal;
}

// Tries to create a Sort out of an identifier and (possibly empty) subsort list.
Sort* Translator::addSort(std::string const& sortName, SortList* subsorts, bool translateDeclaration, bool warnOnDup)
{
	std::string trimmedName = utils::trimWhitespace(sortName);

	Sort* retVal = NULL;
	bool needTrans = false;

	if ((retVal = getSort(trimmedName)) && warnOnDup) {
		// Duplicate.
		warn("Found duplicate sort declaration: \"" + trimmedName + "\".", true);

	} else {
		// It doesn't exist already. Add it.
		needTrans = true;


		// Select a unique variable.
		std::string baseName = sortNameToVariable(trimmedName, true);
		std::string varName = baseName;
		size_t i = 0;

		while (symbols.addSymbol(varName, NULL, SymbolNode::SYM_VAR) == SymbolTable::ADDSYM_DUP) {
			varName = varName + utils::to_string(++i);
		}

		Variable* sortVar = new Variable(varName, NULL);

		// Connect the symbol definition to the actual Element instance, then save the Element.
		SymbolNode* tempSym = symbols.getLastSymbol();
		tempSym->symbolElement = sortVar;
		variables.push_back(sortVar);

		retVal = new Sort(trimmedName, sortVar);
		addSort(retVal);
	}


	// If the sort is "something*" we should ensure that its parent exists and that
	// the appropriate subsorts are present.
	if (trimmedName.at(trimmedName.length()-1) == '*') {
		Sort* parentSort = addSort(trimmedName.substr(0, trimmedName.length()-1), subsorts, translateDeclaration, false);
		needTrans |= retVal->addSubsort(parentSort, true);

		// In addition, we should add the 'none' object.
		Object* none = getOrCreateSimpleObjectLike("none", Object::OBJ_NAME);
		bool needObjTrans = retVal->addObject(none, true);

		// Translate it, if necessary.
		if (translateDeclaration && needObjTrans) {
			translateObjectDecl(none, retVal);
		}

	} else {
		if (subsorts) {
			for (SortList::iterator it = subsorts->begin(); it != subsorts->end(); it++)
				needTrans |= retVal->addSubsort(*it, true);
		}
	}

	// Translate the declaration if anything has changed or the sort is new.
	if (translateDeclaration && needTrans) {
		translateSortDecl(retVal);
	}

	return retVal;
}


// Attempts to add a new Variable object to the translator's data structures and the symbol table.
int Translator::addVariable(Variable* newVar)
{
	int retVal = SymbolTable::ADDSYM_ERR; // Start pessimistic.
	if(newVar)
	{
		// Try adding it into the symbol table, and then into local data structures if successful.
		retVal = symbols.addSymbol(newVar->baseName(), NULL, SymbolNode::SYM_VAR);
		if(retVal == SymbolTable::ADDSYM_OK)
		{
			// Connect the symbol definition to the actual Element instance, then save the Element.
			SymbolNode* tempSym = symbols.getLastSymbol();
			tempSym->symbolElement = newVar;
			variables.push_back(newVar);
		}
	}
	return retVal;
}

// Attempts to add a new Query object to the translator's data structures.
int Translator::addQuery(Query* newQuery)
{
	int retVal = SymbolTable::ADDSYM_ERR; // Start pessimistic.
	if(newQuery)
	{
		// Do some basic sanity checks, then try adding it into local data structures.
		if(newQuery->label == "")
		{
			newQuery->label = "0"; // An unlabeled query defaults to being query 0.
		}
		// Note: We no longer require queries to specify a maximum step.
		// If it turns out we do need a max step (ie static translation)
		// the wrapper will take care of it.
		if(this->getQuery(newQuery->label) == NULL)
		{
			queries.push_back(newQuery);
			retVal = SymbolTable::ADDSYM_OK;
		}
		else
		{	// A query with this label already exists, flag the dupe.
			retVal = SymbolTable::ADDSYM_DUP;
		}
	}
	return retVal;
}

// Translates a Constant element into an ASP-compatible constant declaration.
void Translator::translateConstantDecl(Constant const* transConst)
{
	// Sanity check: make sure the element isn't NULL.
	if(transConst)
	{
		// Detect if it's an abnormality constant and set the appropriate flag.
		if (transConst->isAbnormal()) {
			blnFoundAbnormalities = true;
		}

		// Detect if it's an additive constant and set the appropriate flag.
		if (transConst->isAdditive()) {
			blnFoundAdditive = true;
		}

		ElementCounter eCount; 											// Used to track occurrences of identical parameters (to avoid name clashes).
		std::vector<std::pair<Sort const*,std::string> > parameterMap;	// An ordered mapping from variables to parameters.

		std::string translatedConst;
		ClauseList localClauses;

		std::ostringstream stmtBuilder;									// Used to build each individual statement required for this declaration.
		StmtList stmts;													// Used to aggregate the statements we need and output them all simultaneously.

		// Translate the constant and save it for later..
		transConst->translate(stmtBuilder, localClauses, &eCount, NULL, &parameterMap);
		translatedConst = stmtBuilder.str();
		stmtBuilder.str("");
		
		// Ouput the class of constant, then its translated name.
		stmtBuilder << transConst->constTypeStr() << "(" << translatedConst << ")";

		if (localClauses.size() > 0) {
			stmtBuilder << " <- ";
			outputClauses(stmtBuilder, localClauses, false);
		}
		stmtBuilder << ".";

		// Add the first statement to the list.
		stmts.push_back(Statement(stmtBuilder.str(),IPART_BASE));
		stmtBuilder.str("");
		

		// We intentionally don't clear the clause list.

		// Output the line connecting a constant to its domain.
		if(transConst->domain())
		{
			stmtBuilder << "constant_sort(" << translatedConst << ",";
			stmtBuilder << transConst->domain()->fullTransName() << ")";

			if (localClauses.size() > 0) {
				stmtBuilder << " <- ";
				outputClauses(stmtBuilder, localClauses, false);
			}

			stmtBuilder << ".";

			stmts.push_back(Statement(stmtBuilder.str(), IPART_BASE));
			stmtBuilder.str("");
		}

		// If the constant is an attribute, connect the attribute to its action.
		if(transConst->constType() == Constant::CONST_ATTRIBUTE && ((Attribute const*)transConst)->parent())
		{
			stmtBuilder << "action_attribute(";
			bool matched = ((Attribute const*)transConst)->parent()->translate(stmtBuilder, localClauses, &eCount, &parameterMap, NULL);
			stmtBuilder << ", " << translatedConst << ")";

			if (localClauses.size() > 0) {
				stmtBuilder << " <- ";
				outputClauses(stmtBuilder, localClauses, false);
			}
			stmtBuilder << ".";

			if (!matched) {
				// The parameter prefixes don't match. Warn the user.
				warn(std::string("The attribute \"")
						+ transConst->fullName()
						+ std::string("\" does not contain all arguments within its parent action \"")
						+ ((Attribute const*)transConst)->parent()->fullName()
						+ std::string("\". This will likely cause unintended results."),
						true,
						true);
			}

			stmts.push_back(Statement(stmtBuilder.str(), IPART_BASE));
			stmtBuilder.str("");
		}

		// Output all of the statements...
		outputStmts(stmts);
	}
}

// Translates an Object element into an ASP-compatible declaration of an
// object as a member of a sort's domain.
void Translator::translateObjectDecl(Object const* transObj, Sort const* sortObj)
{
	// Sanity check: make sure the object isn't NULL, and neither is its sort.
	if(transObj && sortObj)
	{
		// An object delcaration is the sort's name, and then the object
		// name in parentheses.
		std::stringstream stmtBuilder;					// Used to build each individual statement required for this declaration.
		ClauseList localClauses;


		stmtBuilder << sortObj->fullTransName() << "(";
		transObj->translate(stmtBuilder, localClauses);
		stmtBuilder << ")";

		if (localClauses.size()) {
			stmtBuilder << " <- ";
			outputClauses(stmtBuilder, localClauses, false);
		}


		stmtBuilder << ".";

		// Output the statement
		output(stmtBuilder.str(), IPART_BASE, true);
	}
}

// Translates a Sort element into an ASP-compatible sort declaration.
void Translator::translateSortDecl(Sort const* transSort)
{
	// Sanity check: make sure the sort isn't NULL.
	if(transSort)
	{
		StmtList stmts;									// Used to aggregate the statements we need and output them all simultaneously.

		// A translated sort declaration involves three things:
		// Declare the sort name.
		stmts.push_back(Statement("sort(" + transSort->fullTransName() + ").",IPART_BASE));

		// The sort's default variable and the line connecting the sort 
		// to its objects (if the variable reference isn't NULL).
		if(transSort->var())
		{
			stmts.push_back(
				Statement(
						"#domain " + transSort->fullTransName()
						+ "(" + transSort->var()->fullTransName() + ").", IPART_BASE
						)
				);

			stmts.push_back(
				Statement(
						"sort_object(" + transSort->fullTransName() + ","
						+ transSort->var()->fullTransName() + ").", IPART_BASE
						)
				);
		}
		else
		{
			/// @todo Error if sortVar == NULL.
		}

		// If the sort has subsorts, add lines indicating that all members of
		// the subsorts are also members of the sort.
		if(transSort->numSubsorts())
		{
			for (SortList::const_iterator it = transSort->beginSubsorts(); it != transSort->endSubsorts(); it++) {
				Translator::translateSubsortDecl(transSort, *it);
			}
		}

		// Additionally, we're going to hide the sort from view to prevent clutter
		stmts.push_back(
			Statement(
					"#hide " + transSort->fullTransName() + "("
					+ transSort->var()->fullTransName() + ").\n", IPART_BASE
					)
			);

		// Output all the statements!
		outputStmts(stmts);
	}
}

// Translates a declaration of a super/sub-sort relationship between two sorts.
void Translator::translateSubsortDecl(Sort const* transSupersort, Sort const* transSubsort)
{
	if(transSupersort && transSubsort)
	{

		if(transSubsort->var())
		{
			output(
					transSupersort->fullTransName() + "(" + transSubsort->var()->fullTransName() + ")."
					, IPART_BASE, true
					);
		}
		else
		{
			/// @todo Error if transSubsort's sortVar == NULL.
		}
	}
}

// Translates a Variable element into an ASP-compatible variable declaration.
void Translator::translateVariableDecl(Variable const* transVar)
{
	// We've got a version that already creates a string of the declaration,
	// just use that and send it to output.
	output(Translator::translateVariableDeclToString(transVar), IPART_BASE, true);
}


// Translates a Query into an ASP-compatible query declaration.
void Translator::translateQuery(Query const* transQuery)
{
	ClauseList localClauses;
	StmtList stmts;

	// TODO: These aren't behaving correctly...

	if(transQuery && transQuery->label != ""
			&& (!blnStaticTrans || transQuery->maxstep != ""))
	{
		std::ostringstream ossOutputBuffer; // Holds translated output so things can be easily added on before or after the normal output.

		// Output special "hint" flags/comments for this query.
		std::string hintMaxstep = transQuery->maxstep;

		// f2lp does weird things with periods in comments, so replace the dots in a ranged maxstep with something else.
		if(hintMaxstep.find("..") != std::string::npos)
		{
			hintMaxstep.replace(hintMaxstep.find(".."), 2, "::");
		}
		stmts.push_back(
			Statement(
					"% [Query: Label:" + transQuery->label + ((hintMaxstep != "") ? ", Maxstep:" + hintMaxstep : "" ) + "]",
					IPART_NONE
					)
			);

		// For each item in queryConditions, output an ASP-style constraint for it.
		for(ParseElementList::const_iterator lIter = transQuery->queryConditions.begin(); lIter != transQuery->queryConditions.end(); ++lIter)
		{
			bool isDynamic = false, alteredTimestamp = false;
			bool malformed = false;
			int tmpLoc;
			std::string tmpQueryTimeStamp;

			// set up everything for our use
			ossOutputBuffer.str("");

			// Transform 'maxstep' to the appropriate timestamp
			if (!blnStaticTrans) {
				tmpQueryTimeStamp = utils::trimWhitespace((*lIter)->getQueryTimeStamp());
				// A query statement is dynamic if it's not regarding t=0 or contains actions.
				if (tmpQueryTimeStamp != "0" || (*lIter)->hasConstants(ParseElement::MASK_ACTION)){
					isDynamic = true;
				}
				while ((tmpLoc = tmpQueryTimeStamp.find("maxstep")) != std::string::npos) {
					// we have a 'maxstep' occurrence in the string
					alteredTimestamp = true;
					tmpQueryTimeStamp.replace(tmpLoc, 7, dynamicTimeStamp);
				}
				if (alteredTimestamp) (*lIter)->setQueryTimeStamp(tmpQueryTimeStamp);
			}

			// Quick checking for undeclared identifiers....
			BaseElementList undefined;
			(*lIter)->aggregateUndefined(undefined);

			if (undefined.size()) {
				// One or more undefined elements.
				// Throw an error
				std::ostringstream tmpErr;
				tmpErr << "Undeclared identifiers were encountered. The follow identifiers are undeclared: ";
				for (BaseElementList::const_iterator it = undefined.begin(); it != undefined.end(); ) {
					tmpErr << "\"";
					(*it)->fullName(tmpErr);
					tmpErr << "\"";
					if (++it != undefined.end()) tmpErr << ", ";
				}
				tmpErr << ".";
				error(tmpErr.str(),true);
				malformed = true;
			}


			// Don't translate malformed queries
			if (malformed) continue;


			(*lIter)->translateQuery(stmts, transQuery->label, (isDynamic) ? IPART_VOLATILE : IPART_BASE);
		}

		// output all the resulting statements.
		outputStmts(stmts);
	}
}

// Translates a causal law into ASP-compatible rule(s).
void Translator::translateCausalLaw(
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

	// The initialized values default to "static law" (i.e., fluents only, no "after").
	RuleType type = RULE_STATIC;	// The type of the rule we're currently working with.

	bool afterNotNot = false;		// Whether the after body should be encased in double negation.
	bool ifNotNot = false;			// Whether the if body should be encased in double negation.
	bool malformed = false; 		// true if one or more problems with the law have been detected.

	std::ostringstream ossOutputBuffer; // Holds translated output so things can be easily added on before or after the normal output.

	std::string baseTimeStamp;	// The timestamp used to index this rule with.

	// lists used to capture additional clauses and statments.
	StmtList stmts;

	// Do some basic checking on the structure of the law. This includes determining the type of law we're working with
	// and performing some basic sanity checking on each of the components...


	// step 1: ensure the head is non-null and in the correct form
	if (!head || !head->isSingleAtom()) {
		error("Definite causal laws must have exactly one constant in the head.\n");
		malformed = true;
		return;
	}

	// step 2: Ensure that LUA calls only occur in the law's where clause (if it exists).
	if ( head->hasLuaCalls()
			|| (ifBody && ifBody->hasLuaCalls())
			|| (assumingBody && assumingBody->hasLuaCalls())
			|| (afterBody && afterBody->hasLuaCalls())
			|| (unlessBody && unlessBody->hasLuaCalls())
			|| (whenBody && whenBody->hasLuaCalls())
			|| (followingBody && followingBody->hasLuaCalls()))
	{
		// They have at least one call to lua outside the where clause.
		// Throw an error.
		error("External function calls are only permitted within the where clause of a causal law.\n");
		malformed = true;
	}



	// step 3: Ensure that abnormalities are where they are supposed to be...
	if ( head->hasConstants(ParseElement::MASK_AB)
			|| (ifBody && ifBody->hasConstants(ParseElement::MASK_AB))
			|| (assumingBody && assumingBody->hasConstants(ParseElement::MASK_AB))
			|| (afterBody && afterBody->hasConstants(ParseElement::MASK_AB))
			|| (unlessBody && unlessBody->hasConstants(ParseElement::MASK_AB))
			|| (whereBody && whereBody->hasConstants(ParseElement::MASK_AB)))
	{
		// The law has abnormalities outside of the when / following clauses...
		error("Abnormality constants cannot occur outside of 'when' and 'following' clauses of a law.\n");
		malformed = true;
	}

	// ensure that the when and following bodies have _only_ abnormalities.
	if ((whenBody && ( whenBody->hasConstants(ParseElement::MASK_ACTION | ParseElement::MASK_FLUENT)))
			|| (followingBody && (followingBody->hasConstants(ParseElement::MASK_ACTION | ParseElement::MASK_FLUENT))))
	{
		// The law has abnormalities outside of the when / following clauses...
		error("Fluent and Action constants cannot occur within the 'when' and 'following' clauses of a law.\n");
		malformed = true;
	}

	// Step 4a: Determine if the law is a 'rigid' law, which contains a rigid fluent in the head (Alternatively, if it contains 'exogenous' or 'inertial').
	if (head->hasConstants(ParseElement::MASK_RIGID)) {
		type = RULE_RIGID;

		// Verification: We don't allow any non-rigid fluents in the rule.
		if (head->hasConstants(ParseElement::MASK_NON_RIGID)
				|| (ifBody && ifBody->hasConstants(ParseElement::MASK_NON_RIGID))
				|| (assumingBody && assumingBody->hasConstants(ParseElement::MASK_NON_RIGID))
				|| (afterBody && afterBody->hasConstants(ParseElement::MASK_NON_RIGID))
				|| (unlessBody && unlessBody->hasConstants(ParseElement::MASK_NON_RIGID))
				|| (whenBody && whenBody->hasConstants(ParseElement::MASK_NON_RIGID))
				|| (followingBody && followingBody->hasConstants(ParseElement::MASK_NON_RIGID))
			)
		{
			error("A causal law w/ rigid fluents in the head and non-rigid fluents in the body is (currently) unsupported.\n");
			malformed = true;
		}
	}

	// Step 4b: Determine whether the law is a static law, an action dynamic law, or a fluent dynamic law...
	// Static laws...
	else if (head->hasConstants(ParseElement::MASK_FLUENT | ParseElement::MASK_TRUE_FALSE) && !head->hasConstants(ParseElement::MASK_ACTION)
			&& (!ifBody || !ifBody->hasConstants(ParseElement::MASK_ACTION))
			&& (!assumingBody || !assumingBody->hasConstants(ParseElement::MASK_ACTION))
			&& (!whenBody || !whenBody->hasConstants(ParseElement::MASK_DYNAMIC_AB))
			&& !afterBody
			&& !followingBody)
	{
		type = RULE_STATIC;
		baseTimeStamp = staticTimeStamp;
	}
	// fluent dynamic laws...
	else if (head->hasConstants(ParseElement::MASK_FLUENT | ParseElement::MASK_TRUE_FALSE) && !head->hasConstants(ParseElement::MASK_ACTION)
			&& (!ifBody || !ifBody->hasConstants(ParseElement::MASK_ACTION))
			&& (!assumingBody || !assumingBody->hasConstants(ParseElement::MASK_ACTION))
			&& (!whenBody || !whenBody->hasConstants(ParseElement::MASK_DYNAMIC_AB)))
	{
		type = RULE_FLUENTDYNAMIC;
		baseTimeStamp = dynamicTimeStamp;
	}
	// action dynamic laws...
	else if (head->hasConstants(ParseElement::MASK_ACTION) && !head->hasConstants(ParseElement::MASK_FLUENT)
			&& !afterBody && !followingBody)
	{
		type = RULE_ACTIONDYNAMIC;
		baseTimeStamp = dynamicTimeStamp + "-1";
	}
	// Malformed laws...
	else
	{
		error("A malformed causal law was encountered. Please ensure that all laws are either static, action dynamic, or fluent dynamic laws.\n");
		malformed = true;
	}

	// Now check if we actually need "not not (...)" encasing the law's body (if it has one).
	if (!head->isTrivial()) {
		if (type == RULE_ACTIONDYNAMIC && afterBody && !afterBody->isTrivial())
			afterNotNot = true;
		else if ( (type == RULE_FLUENTDYNAMIC || type == RULE_STATIC || type == RULE_RIGID) && ifBody && !ifBody->isTrivial() )
			ifNotNot = true;
	}

	// Step 5, check to ensure that there are no undefined identifiers (outside the unless clause).
	BaseElementList undefined;
	head->aggregateUndefined(undefined);
	if (ifBody) ifBody->aggregateUndefined(undefined);
	if (assumingBody) assumingBody->aggregateUndefined(undefined);
	if (afterBody) afterBody->aggregateUndefined(undefined);
	if (whenBody) whenBody->aggregateUndefined(undefined);
	if (followingBody) followingBody->aggregateUndefined(undefined);
	if (whereBody) whereBody->aggregateUndefined(undefined);

	if (undefined.size()) {
		// One or more undefined elements.
		// Throw an error
		std::ostringstream tmpErr;
		tmpErr << "Undeclared identifiers were encountered. The follow identifiers are undeclared: ";
		for (BaseElementList::const_iterator it = undefined.begin(); it != undefined.end(); ) {
			tmpErr << "\"";
			(*it)->fullName(tmpErr);
			tmpErr << "\"";
			if (++it != undefined.end()) tmpErr << ", ";
		}
		tmpErr << ".";
		error(tmpErr.str(),true);
		malformed = true;
	}
	undefined.clear();

	// Step 5b, declare undefined identifiers in the unless clause.
	if (unlessBody) {
		unlessBody->aggregateUndefined(undefined);

		ConstSortList tmpParamSorts;
		for (BaseElementList::const_iterator it = undefined.begin(); it != undefined.end(); ) {
			tmpParamSorts.clear();
			bool success = (*it)->guessParamSorts(tmpParamSorts);

			if (success) {
				// We successfully guessed every sort that was required. Finish the declaration.
				Constant* newConst = new Constant(
						(*it)->baseName(),
						getSort("boolean"),
						(type == RULE_STATIC || type == RULE_RIGID) ? Constant::CONST_ABFLUENT : Constant::CONST_ABACTION,
						&tmpParamSorts
				);

				translateConstantDecl(newConst);
				addConstant(newConst);

				// Make sure we update the declaration.
				(*it)->ref(newConst);

			} else {
				// Unable to dynamically declare the constant.
				// Tell the user.
				error("Unable to dynamically declare \"" + ((ParseElement*)(*it))->fullName() + "\" as the constant's parameter sorts could not be determined. Declaring the constant beforehand will fix this issue.",true);
				malformed = true;
			}
		}
	}

	// catch malformed rules and don't translate them.
	if (malformed) return;

	// Let's do the translation!

	// We may need a 'static' copy for the base module
	if (!blnStaticTrans && (type == RULE_STATIC || type == RULE_RIGID)) {
		makeCausalTranslation(
			ossOutputBuffer,
			stmts,
			IPART_BASE,
			ifNotNot,
			afterNotNot,
			"0",
			head,
			ifBody,
			assumingBody,
			afterBody,
			whenBody,
			followingBody,
			whereBody
		);
		stmts.push_back(Statement(ossOutputBuffer.str(),IPART_BASE));
		ossOutputBuffer.str("");
	}

	// We also are going to need a dynamic version of the rule, unless the rule is rigid.
	if (blnStaticTrans || type != RULE_RIGID) {
		makeCausalTranslation(
			ossOutputBuffer,
			stmts,
			IPART_CUMULATIVE,
			ifNotNot,
			afterNotNot,
			baseTimeStamp,
			head,
			ifBody,
			assumingBody,
			afterBody,
			whenBody,
			followingBody,
			whereBody
		);
		stmts.push_back(Statement(ossOutputBuffer.str(),IPART_CUMULATIVE));
		ossOutputBuffer.str("");
	}

	// write the resulting statements to the output
	outputStmts(stmts);

}

// Helper method for the translation.
std::ostream& Translator::makeCausalTranslation(
	std::ostream& output,
	StmtList& extraStmts,
	IPart ipart,
	bool ifNotNot,
	bool afterNotNot,
	std::string const& baseTimeStamp,
	ParseElement* head,
	ParseElement* ifBody,
	ParseElement* assumingBody,
	ParseElement* afterBody,
	ParseElement* whenBody,
	ParseElement* followingBody,
	ParseElement* whereBody
	)
{
	ClauseList localClauses;
	Context localContext;
	bool bodyContent = false; 		// true if the law's body has any content to-date.

	std::string actionTimeStamp = baseTimeStamp + "-1";

	// Translate!

	// The head
	/// @todo If head and ifBody are: not NULL, both const-like or both UOP_NOT(const-like), make a choice rule out of head and translate that.

	localContext = Context(Context::POS_HEAD, ipart, baseTimeStamp, &localClauses, NULL, false, true, &extraStmts);
	bindAndTranslate(output, head, localContext, true);

	// The body, if there is one.
	if(ifBody
			|| assumingBody
			|| afterBody
			|| whenBody
			|| followingBody
			|| whereBody
			|| localClauses.size() > 0)
	{
		output << " <- ";

		// "if" part of body, if there is one.
		if(ifBody)
		{
			// we have something
			bodyContent = true;

			// If we're translating a law that needs a "not not (...)" body wrapper to break cycles, add it.
			if(ifNotNot) {
				output << "not not (";
				localContext = Context(Context::POS_BODY, ipart, baseTimeStamp, NULL, NULL, true, false, &extraStmts);
				bindAndTranslate(output, ifBody, localContext, false, true);
				output << ")";
			}
			else {
				localContext = Context(Context::POS_BODY, ipart, baseTimeStamp, &localClauses, NULL, false, false, &extraStmts);
				ifBody->translate(output, localContext);
			}

		}

		// "assuming" part of body, if there is one.
		if(assumingBody)
		{
			// add a connective if necessary.
			if(bodyContent)	output << " & ";
			else bodyContent = true;

			// Translate the "assuming" body exactly as the if body, except that it doesn't have "not not" in front.
			localContext = Context(Context::POS_BODY, ipart, baseTimeStamp, NULL, NULL, false, false, &extraStmts);
			assumingBody->translate(output, localContext);
		}

		// "after" part of body, if there is one.
		if(afterBody)
		{
			// add a connective if necessary.
			if(bodyContent)	output << " & ";
			else bodyContent = true;

			// If we're translating a law that needs a "not not (...)" body wrapper to break cycles, add it.
			if(afterNotNot) {
				output << "not not (";
				localContext = Context(Context::POS_BODY, ipart, actionTimeStamp, NULL, NULL, true, false, &extraStmts);
				bindAndTranslate(output, afterBody, localContext, false, true);
				output << ")";
			}
			else {
				localContext = Context(Context::POS_BODY, ipart, actionTimeStamp, &localClauses, NULL, false, false, &extraStmts);
				afterBody->translate(output, localContext);
			}

		}
		
		// "when" part of the body, if there is one.
		if (whenBody)
		{
			// add a connective if necessary
			if(bodyContent)	output << " & ";
			else bodyContent = true;
			localContext = Context(Context::POS_BODY, ipart, baseTimeStamp, &localClauses, NULL, false, false, &extraStmts);
			whenBody->translate(output, localContext);
		}

		// "following" part of the body, if there is one
		if (followingBody)
		{

			// add a connective if necessary
			if(bodyContent)	output << " & ";
			else bodyContent = true;
			localContext = Context(Context::POS_BODY, ipart, actionTimeStamp, &localClauses, NULL, false, false, &extraStmts);
			followingBody->translate(output, localContext);
		}

		// "where" part of body, if there is one.
		if(whereBody)
		{
			// add a connective if necessary
			if(bodyContent)	output << " & ";
			else bodyContent = true;
			localContext = Context(Context::POS_BODY, ipart, baseTimeStamp, &localClauses, NULL, false, false, &extraStmts);
			whereBody->translate(output, localContext);
		}
		
		// handle extra clauses
		outputClauses(output, localClauses, bodyContent);
	}
	output << ".";

	return output;
}

// Handles a ':- show' declaration, adding the corresponding #show statements to the translation footer.
void Translator::translateShowStmt(ParseElementList const& atomicFormulas) {
	StmtList stmts;
	Context localContext;
	std::ostringstream tmp;

	// By default, user defined atoms are shown in the answer set.
	// The presence of a show statement overrides this and makes them all
	// default to hidden.
	if (!blnEncounteredShowStmt) {
		blnEncounteredShowStmt = true;
		stmts.push_back(Statement("#hide.", IPART_BASE));
	}


	// Iterate through each element and add the appropriate show statements.
	for (ParseElementList::const_iterator it = atomicFormulas.begin(); it != atomicFormulas.end(); it++) {

		// Sanity check: Non-null parse elements.
		if (!(*it)) continue;

		if ((*it)->getType() == ParseElement::PELEM_CONSTLIKE) {
			// It's a bare constant. Take this to be a shortcut for 'c=v' where V is a variable ranging of the constant's domain
			ConstantLikeElement* constlike = ((ConstantLikeElement*)(*it));
			if (constlike->domain() && constlike->domain()->var())
			{
				std::string tmpname = constlike->domain()->var()->fullTransName();
				localContext = Context(Context::POS_BODY, IPART_BASE, Context::ANON_STR, tmpname, NULL, NULL, false, false, &stmts);
				tmp << "#show ";
				(*it)->translate(tmp, localContext);
				tmp << ".";

				stmts.push_back(Statement(tmp.str(), IPART_BASE));

			} else {
				// This appears to be missing one or more references...
				// Just try a normal translation and hope for the best.
				localContext = Context(Context::POS_BODY, IPART_BASE, Context::ANON_STR,  NULL, NULL, false, false, &stmts);
				tmp << "#show ";
				(*it)->translate(tmp, localContext);
				tmp << ".";
				stmts.push_back(Statement(tmp.str(), IPART_BASE));
			}
		} else {
			// It's must be 'c=v'. We can translate this without any further ado
			localContext = Context(Context::POS_BODY, IPART_BASE, Context::ANON_STR,  NULL, NULL, false, false, &stmts);
			tmp << "#show ";
			(*it)->translate(tmp, localContext);
			tmp << ".";
			stmts.push_back(Statement(tmp.str(), IPART_BASE));
		}
		tmp.str("");
	}

	// Add the statements to the footer.
	addToFooter(stmts);
}

// Transforms declarative laws ("inertial p", "exogenous a(X)", "rigid q", etc.) to basic form and calls the translator for them.
bool Translator::translateDeclarativeLaw(
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
		SimpleUnaryOperator* tempPE = new SimpleUnaryOperator(opType, head);

		// This law becomes "delaration(F) [if G] [after H] [unless J] [when K] [following L] [where M]."
		translateCausalLaw(tempPE, ifBody, assumingBody, afterBody, unlessBody, whenBody, followingBody, whereBody);
		retVal = true;

		tempPE->detachPostOp();
		delete tempPE;
	}
	return retVal;
}

// Transforms a causal law of the form "always F [when H] [where G]." to basic form, then calls the translator for it.
bool Translator::translateAlwaysLaw(
	ParseElement* constraint,
	ParseElement* whenBody,
	ParseElement* whereBody
	)
{
	bool retVal = false; // Start pessimistic.
	if(constraint != NULL)
	{
		// "not constraint" is the afterBody.
		SimpleUnaryOperator* tempPE = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, constraint);

		// The head is "false".
		ObjectLikeElement* tempObj = new ObjectLikeElement("false", getOrCreateSimpleObjectLike("false"));

		// The law becomes "caused false after -F when H where G."
		translateCausalLaw(tempObj, NULL, NULL, tempPE, NULL, whenBody, NULL, whereBody);
		delete tempObj;
		tempPE->detachPostOp();
		delete tempPE;
		retVal = true;
	}
	return retVal;
}

// Transforms a causal law of the form "constraint F [after H] [when J] [following K] [where L]." to basic form, then calls the translator for it.
bool Translator::translateConstraintLaw(
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
		if(!constraint->hasConstants(ParseElement::MASK_ACTION))
		{
			if(!constraint->hasConstants(ParseElement::MASK_FLUENT|ParseElement::MASK_RIGID))
			{
				warn("Cannot determine if \"" + constraint->fullName() + "\" is a fluent formula or not, it might not work as F in a \"constraint F\" style law.", true, true);
			}

			// "not constraint" is the ifBody.
			ParseElement* tempPE = NULL; // Points at whatever ends up becoming the head of the rule.
			SimpleUnaryOperator* tempUOP = NULL;

			if (positive) {
				// If the constraint is "not something", then we can just drop the not (we'd end up with "not not something", which is equivalent to "something" since "false" is the head).
				if(constraint->getType() == ParseElement::PELEM_UOP
						&& ((SimpleUnaryOperator*)constraint)->opType() == SimpleUnaryOperator::UOP_NOT)
				{
					tempPE = ((SimpleUnaryOperator*)constraint)->detachPostOp();
				}
				else
				{	// It's not an optimizable case, just tack "not" onto the constraint.
					tempPE = tempUOP = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, constraint);
				}
			}
			else {
				// We are working with the negative version of the constraint, we don't have to negate the body.
				tempPE = constraint;
			}

			// The head is "false".
			ObjectLikeElement* tempObj = new ObjectLikeElement("false", getOrCreateSimpleObjectLike("false"));

			// The law becomes "caused false if -F after H when J following K where L."
			translateCausalLaw(tempObj, tempPE, NULL, afterBody, unlessBody, whenBody, followingBody, whereBody);
			delete tempObj;
			if (tempUOP) {
				tempUOP->detachPostOp();
				delete tempUOP;
			} else {
				// Put the constraint's postop back, just in case.
				((SimpleUnaryOperator*)constraint)->postOp(tempPE);
			}
			retVal = true;
		}
		else
		{
			error("\"" + constraint->fullName() + "\" is not a fluent formula, can't use it as F in a \"constraint F\" style law.", true, true);
		}
	}
	return retVal;
}

// Transforms a causal law of the form "default F [if G] [assuming H] [after J] [when K] [following L] [where M]." to basic form, then calls the translator on it.
bool Translator::translateDefaultLaw(
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
		if (head) head->parens(true);
		if (ifBody) ifBody->parens(true);
		SimpleBinaryOperator* tempPE = new SimpleBinaryOperator(head, SimpleBinaryOperator::BOP_AND, ifBody);

		// This law becomes "caused F if F [& G] [assuming H] [after J] [when K] [following L] [where M]."
		translateCausalLaw(head, tempPE, assumingBody, afterBody, unlessBody, whenBody, followingBody, whereBody);
		retVal = true;

		tempPE->detachPostOp();
		tempPE->detachPreOp();
		delete tempPE;

	}
	return retVal;
}

// Transforms a causal law of the form "nonexecutable F [if G] [when H] [where K]." to basic form, then calls the translator for it.
bool Translator::translateNonexecutableLaw(
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
		if(!nonEx->hasConstants(ParseElement::MASK_FLUENT))
		{
			if(!nonEx->hasConstants(ParseElement::MASK_ACTION))
			{
				warn("Cannot determine if \"" + nonEx->fullName() + "\" is an action formula or not, it might not work as F in a \"nonexecutable F\" style law.", true, true);
			}

			// nonEx and ifBody are going to end up together no matter what.
			if (ifBody) ifBody->parens(true);
			if (nonEx) nonEx->parens(true);
			SimpleBinaryOperator* tempPE = new SimpleBinaryOperator(nonEx, SimpleBinaryOperator::BOP_AND, ifBody);

			// Create a head of "false".
			ObjectLikeElement* tempObj = new ObjectLikeElement("false", getOrCreateSimpleObjectLike("false"));

			// becomes caused false after F [& G] following H where K.
			translateCausalLaw(tempObj, NULL, NULL, tempPE, NULL, NULL, whenBody, whereBody);

			delete tempObj;
			tempPE->detachPostOp();
			tempPE->detachPreOp();
			delete tempPE;

			retVal = true;
		}
		else
		{
			error("\"" + nonEx->fullName() + "\" is not an action formula, can't use it as F in a \"nonexecutable F\" style law.", true, true);
		}
	}
	return retVal;
}

// Transforms a causal law of the form "possibly caused F [if G] [assuming H] [after J] [unless K] [when L] [following M] [where N]." to basic form, then calls the translator on it.
bool Translator::translatePossiblyCausedLaw(
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
		if (ifBody) ifBody->parens(true);
		if (head) head->parens(true);
		SimpleBinaryOperator* tempPE = new SimpleBinaryOperator(head, SimpleBinaryOperator::BOP_AND, ifBody);

		// This law becomes "caused F if F [& G] [assuming H] [after J] [unless K] [when L] [following M] [where N]."
		translateCausalLaw(head, tempPE, assumingBody, afterBody, unlessBody, whenBody, followingBody, whereBody);

		retVal = true;
		tempPE->detachPostOp();
		tempPE->detachPreOp();
		delete tempPE;
	}
	return retVal;
}

// Transforms a causal law of the form "G may cause F [if H] [when J] [where K]." to basic form, then calls the translator on it.
bool Translator::translateMayCauseLaw(
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
		if(causer->hasConstants(ParseElement::MASK_ACTION) && !causer->hasConstants(ParseElement::MASK_FLUENT))
		{
			// Causer and ifBody are going to end up together no matter what.
			if (causer) causer->parens(true);
			if (ifBody) ifBody->parens(true);
			SimpleBinaryOperator* tempPE = new SimpleBinaryOperator(causer, SimpleBinaryOperator::BOP_AND, ifBody);

			// Where causer and ifBody end up in the basic form depend on what's in causee.
			if(causee->hasConstants(ParseElement::MASK_ACTION) && !causee->hasConstants(ParseElement::MASK_FLUENT))
			{	// Causee is an action formula, this is "caused F if F & G & H following J where K".
				// Merge F into G & H.
				if (causee) causee->parens(true);
				if (tempPE) tempPE->parens(true);
				SimpleBinaryOperator* tempPE2 = new SimpleBinaryOperator(causee, SimpleBinaryOperator::BOP_AND, tempPE);
				translateCausalLaw(causee, tempPE2, NULL, NULL, NULL, NULL, whenBody, whereBody);

				retVal = true;
				tempPE2->detachPostOp();
				tempPE2->detachPreOp();
				delete tempPE2;
			}
			else if(!causee->hasConstants(ParseElement::MASK_ACTION) && causee->hasConstants(ParseElement::MASK_FLUENT))
			{	// Causee is a fluent formula, this is "caused F if F after G & H following J where K".
				translateCausalLaw(causee, causee, NULL, tempPE, NULL, NULL, whenBody, whereBody);
				retVal = true;
			}
			else
			{	// Causee is mixed, that isn't allowed.
				warn("\"" + causee->fullName() + "\" must be a pure action formula or pure fluent formula in this law, it can't have both kinds of constants.", true, true);
			}

			tempPE->detachPostOp();
			tempPE->detachPreOp();
			deallocateTempBinaryOp(tempPE);
		}
		else
		{
			error("\"" + causer->fullName() + "\" is not an action formula, can't use it as G in a \"G may cause F\" style law.", true, true);
		}
	}
	return retVal;
}

// Transforms a causal law of the form "G causes F [if H] [where J]." to basic form, then calls the translator on it.
bool Translator::translateCausesLaw(
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
		if(causer->hasConstants(ParseElement::MASK_ACTION) && !causer->hasConstants(ParseElement::MASK_FLUENT))
		{
			// Causer and ifBody are going to end up together no matter what.
			if (causer) causer->parens(true);
			if (ifBody) ifBody->parens(true);
			SimpleBinaryOperator* tempPE = new SimpleBinaryOperator(causer, SimpleBinaryOperator::BOP_AND, ifBody);

			// Where causer and ifBody end up in the basic form depend on what's in causee.
			if((causee->hasConstants(ParseElement::MASK_ACTION) && !causee->hasConstants(ParseElement::MASK_FLUENT)) || causee->getType() == ParseElement::PELEM_OBJLIKE)
			{	// Causee is an action formula, this is "caused F if G".
				translateCausalLaw(causee, tempPE, NULL, NULL, NULL, NULL, whenBody, whereBody);
				retVal = true;
			}
			else if(!causee->hasConstants(ParseElement::MASK_ACTION) && causee->hasConstants(ParseElement::MASK_FLUENT))
			{	// Causee is a fluent formula, this is "caused F after G".
				translateCausalLaw(causee, NULL, NULL, tempPE, NULL, NULL, whenBody, whereBody);
				retVal = true;
			}
			else
			{	// Causee is mixed, that isn't allowed.
				error("\"" + causee->fullName() + "\" must be a pure action formula or pure fluent formula in this law, it can't have both kinds of constants.", true, true);
			}

			tempPE->detachPostOp();
			tempPE->detachPreOp();
			delete tempPE;
		}
		else
		{
			error("\"" + causer->fullName() + "\" is not an action formula, can't use it as G in a \"G causes F\" style law.", true, true);
		}
	}
	return retVal;
}

// Transforms an increment law of the form "A increments B by N [if H] [when J] [where K]." to basic form, then calls the translator on it.
bool Translator::translateIncrementLaw(
	ParseElement* causer,
	ParseElement* causee,
	ParseElement* increment,
	ParseElement* ifBody,
	ParseElement* whenBody,
	ParseElement* whereBody,
	bool isIncrement
	)
{
	ParseElement* inc_expr = NULL;
	ConstantLikeElement* contrib = NULL;
	ParseElement* head, *newIf = NULL;

	std::list<SimpleBinaryOperator*> tmpBinOps;
	std::list<BaseLikeElement*> tmpBaseElems;

	bool malformed = false;

	// Some checking...

	if(!causer || !causee || !increment ) {
		error("An error occurred while parsing the incremental law.", true, true);
		return false;
	}

	/*********************************************************/
	/* Check the causer */
	/*********************************************************/

	if (causer->hasConstants(ParseElement::MASK_FLUENT)
		|| !causer->hasConstants(ParseElement::MASK_ACTION)
		|| causer->getType() != ParseElement::PELEM_CONSTLIKE)
	{
		error("\"" + causer->fullName() + "\" is not a boolean action, can't use it as A in a \"A increments B by N\" style law.", true, true);

		malformed = true;
	}
	else if (!((ConstantLikeElement*)causer)->ref()
		|| !((Constant const*)((ConstantLikeElement*)causer)->ref())->domain())
	{
		error("\"" + causer->fullName() + "\" does not appear to be properly declared, can't use it as A in a \"A increments B by N\" style law.", true, true);
		malformed = true;
	}
	else if (!((ConstantLikeElement*)causer)->isBoolean())
	{
		error("\"" + causer->fullName() + "\" is not a boolean action, can't use it as A in a \"A increments B by N\" style law.", true, true);
		malformed = true;
	}

	/*********************************************************/
	/* Check the causee */
	/*********************************************************/

	bool isAction = causee->hasConstants(ParseElement::MASK_ACTION);
	bool isFluent = causee->hasConstants(ParseElement::MASK_FLUENT);

	if ((!isAction && !isFluent) || (isAction && isFluent)
		|| causee->getType() != ParseElement::PELEM_CONSTLIKE)
	{
		error("\"" + causee->fullName() + "\" is not an additive constant, can't use it as B in a \"A increments B by N\" style law.", true, true);
		malformed = true;
	}
	else if (!((ConstantLikeElement*)causee)->ref()
		|| !((Constant const*)((ConstantLikeElement*)causee)->ref())->domain())
	{
		error("\"" + causee->fullName() + "\" does not appear to be properly declared, can't use it as B in a \"A increments B by N\" style law.", true, true);
		malformed = true;
	}

	else if (!((Constant const*)((ConstantLikeElement*)causee)->ref())->isAdditive())
	{
		error("\"" + causee->fullName() + "\" is not an additive constant, can't use it as B in a \"A increments B by N\" style law.", true, true);
		malformed = true;
	}

	/*********************************************************/
	/* Check the Increment Clause */
	/*********************************************************/

	if (!increment->isArithExpr()) {
		error( "\"" + increment->fullName() + "\" does not appear to be a valid arithmetic expression, can't use it as N in a \"A increments B by N\" style law.", true, true);
		malformed = true;
	}

	/**************************************************************/
	/* Done Checking */
	/**************************************************************/

	if (malformed) {
		return false;
	}

	// At this point, we know that the critical portions of the law appear to be
	// correct. We can procede with the translation.

	// Step one is to step up the atomic formula that will be in the head of our law.


	// Craft the LHS of the atomic formula
	ParseElementList tmpParams;
	tmpParams.push_back(causer);
	tmpParams.push_back(causee);
	tmpBaseElems.push_back(contrib = new ConstantLikeElement("contribution", getConstantLike("contribution", 2), &tmpParams));

	// Determine the RHS of the atomic formula.
	if (isIncrement) {
		inc_expr = increment;
	} else {
		tmpBaseElems.push_back(new ObjectLikeElement("-1", getOrCreateSimpleObjectLike("-1")));
		if (increment) increment->parens(true);
		inc_expr = new SimpleBinaryOperator(tmpBaseElems.back(), SimpleBinaryOperator::BOP_TIMES, increment);
		tmpBinOps.push_back((SimpleBinaryOperator*) inc_expr);
	}

	// Craft the atomic formula

	//if (inc_expr) inc_expr->parens(true);
	head = new SimpleBinaryOperator(contrib, SimpleBinaryOperator::BOP_EQ, inc_expr);
	tmpBinOps.push_back((SimpleBinaryOperator*) head);

	// Step 2 is to craft the new if clause....
	// The new if body is the result of conjoining the old ifBody
	// with the boolean causer action.

	if (causer) causer->parens(true);
	tmpBaseElems.push_back(new ObjectLikeElement("true", getOrCreateSimpleObjectLike("true")));
	tmpBinOps.push_back(new SimpleBinaryOperator(causer, SimpleBinaryOperator::BOP_EQ, tmpBaseElems.back()));

	if (ifBody) {
		ifBody->parens(true);
		tmpBinOps.back()->parens(true);
		newIf = new SimpleBinaryOperator(tmpBinOps.back(), SimpleBinaryOperator::BOP_AND, ifBody);
		tmpBinOps.push_back((SimpleBinaryOperator*) newIf);
	} else {
		newIf = tmpBinOps.back();
	}

	// Finally, translate!
	translateCausalLaw(head, newIf, NULL, NULL, NULL, whenBody, whereBody);

	// Clean up!
	for (std::list<SimpleBinaryOperator*>::iterator it = tmpBinOps.begin(); it != tmpBinOps.end(); it++) {
		(*it)->detachPostOp();
		(*it)->detachPreOp();
		delete *it;
	}
	contrib->detachParams();

	for (std::list<BaseLikeElement*>::iterator it = tmpBaseElems.begin(); it != tmpBaseElems.end(); it++) {
		delete *it;
	}

	return true;
}



/* Class instance methods for general setup, etc. */

// Creates and adds a new object to the translator's data structures without translating or outputting it.
Object* Translator::createInternalObject(std::string const& newObjName, SortList* params, Sort* ofSort)
{
	Object* retVal = NULL;
	if(ofSort)
	{
		std::string newObjStr = newObjName;
		retVal = new Object(newObjStr, Object::OBJ_NAME, params);

		int addSymResult = this->addObject(retVal);
		if(addSymResult != SymbolTable::ADDSYM_OK)
		{	// Something went wrong adding the object, skip connecting & translating it.
			if(addSymResult == SymbolTable::ADDSYM_DUP)
			{	// Duplicate object. don't bother adding it.
				delete retVal;
				retVal = NULL;
			}
			else
			{	// A real object error. Skip adding it.
				delete retVal;
				retVal = NULL;
			}
		}
		else
		{	// Object add went okay, connect the sort to the object.
			ofSort->addObject(retVal);
		}
	}
	return retVal;
}

// Creates and adds a new number range (child of Object) to the translator's data structures without translating or outputting it.
NumberRange* Translator::createInternalNumRange(std::string const& newObjName, Sort* ofSort)
{
	NumberRange* retVal = NULL;
	if(ofSort)
	{
		retVal = new NumberRange(newObjName);
		int addSymResult = this->addObject(retVal);
		if(addSymResult != SymbolTable::ADDSYM_OK)
		{	// Something went wrong adding the object, skip connecting & translating it.
			if(addSymResult == SymbolTable::ADDSYM_DUP)
			{	// Duplicate object. don't bother adding it.
				delete retVal;
				retVal = NULL;
			}
			else
			{	// A real object error. Skip adding it.
				delete retVal;
				retVal = NULL;
			}
		}
		else
		{	// Object add went okay, connect the sort to the object.
			ofSort->addObject(retVal);
		}
	}
	return retVal;
}


// Allocates a new Query instance and assigns it to tempQuery.
void Translator::allocateNewTempQuery(bool deallocateFirst)
{
	if(deallocateFirst && tempQuery)
	{
		delete tempQuery;
		tempQuery = NULL;
	}
	tempQuery = new Query();
}

// Sets a translator instance's output stream to the passed stream.
void Translator::setOutput(std::ostream &newOst)
{
	if(ostOutPtr)
	{
		ostOutPtr->rdbuf(newOst.rdbuf());
	}
}

// Sets whether a static translation should be outputted
void Translator::setStaticTranslation(bool staticTrans) {
	blnStaticTrans = staticTrans;

	// Make sure we update the timestamps.
	if (staticTrans) {
		staticTimeStamp = getSort("step")->varTransName();
		dynamicTimeStamp = getSort("astep")->varTransName();
	} else {
		staticTimeStamp = "t";
		dynamicTimeStamp = "t";
	}

}

// Sets a translator instance's error output stream to the passed stream.
void Translator::setErrorOutput(std::ostream &newOst)
{
	if(ostErrPtr)
	{
		ostErrPtr->rdbuf(newOst.rdbuf());
	}
}


// Outputs the contents of str to wherever the translator's output stream is aimed.
void Translator::output(std::string const& str, bool endWithNewline)
{
	(*ostOutPtr) << str;
	if(endWithNewline)
	{
		(*ostOutPtr) << std::endl;
	}
}

// Outputs the contents of str to wherever the translator's error output stream is aimed.
void Translator::error(std::string const& str, bool endWithNewline, bool location)
{
	outputToErr("% Error",str,endWithNewline,location);
	this->translatorNumErrors++;
}

// Outputs the contents of str to wherever the translator's error output stream is aimed.
void Translator::warn(std::string const& str, bool endWithNewline, bool location)
{
	outputToErr("% Warning",str,endWithNewline,location);
	this->translatorNumWarnings++;
}

// Outputs the contents of str to wherever the translator's error output stream is aimed.
void Translator::caution(std::string const& str, bool endWithNewline, bool location)
{
	outputToErr("% Caution",str,endWithNewline,location);
}

// Outputs the contents of str to wherever the translator's error output stream is aimed.
void Translator::pragma(std::string const& str, bool endWithNewline, bool location)
{
	outputToErr("% Pragma",str,endWithNewline,location);
}

void Translator::outputToErr(std::string const& hdr, std::string const& str, bool endWithNewline, bool location) {
	(*ostErrPtr) << hdr;
	if (location) {
		(*ostErrPtr) << " at "
			<< ltsyyGetFileName() << ":"
			<< ltsyyGetLoc().first_line
			<< "."
			<< ltsyyGetLoc().first_column;
	}
	(*ostErrPtr) << ": " << str;

	if(endWithNewline)
		(*ostErrPtr) << std::endl;
}

// helper to output clauses to a stream
std::ostream& Translator::outputClauses(std::ostream& out, ClauseList const& clauses, bool initConj) {
	if (initConj && !clauses.empty()) out << " & ";
	for (std::list<std::string>::const_iterator it = clauses.begin(); it != clauses.end(); ) {
		out << *it;
		if (++it != clauses.end()) out << " & ";
	}
	return out;
}

// helper to output a translated expression with a bound context.
std::ostream& Translator::bindAndTranslate(std::ostream& out, ParseElement const* expr, Context& context, bool upwardMobileClauses, bool suppressQuantifier) {

	if (!expr) return out;

	ClauseList localClauses, localVariables;
	Context localContext = context.mkBindClauses(&localClauses).mkBindVars(&localVariables);
	std::ostringstream tmp;

	expr->translate(tmp, localContext);

	// Existential quantification (if needed).
	if (!localVariables.empty() && !suppressQuantifier) {
		out << "?[";

		for (std::list<std::string>::const_iterator it = localVariables.begin(); it != localVariables.end(); ) {
				out << *it;
				if (++it != localVariables.end()) out << ", ";
		}
		out << "]:";
	}

	if ((!localVariables.empty() && !suppressQuantifier)
			|| (!upwardMobileClauses && !localClauses.empty()))
	{
		out << "(";
	}

	out << tmp.str();

	if ((!localVariables.empty() && !suppressQuantifier) || (!localClauses.empty() && !upwardMobileClauses)) {
		Translator::outputClauses(out, localClauses, true);
		out << ")";
	} else if (!localClauses.empty()){
		context.transferExtraClauses(localClauses);
	}

	return out;
}


// Destructor. Deallocates all memory associated with the list attributes.
Translator::~Translator()
{
	if(this->tempQuery)
	{
		delete tempQuery;
		tempQuery = NULL;
	}
	std::list<Constant*>::iterator cIter = constants.begin();
	while(cIter != constants.end())
	{
		delete *cIter;
		++cIter;
	}
	constants.clear();
	std::list<Object*>::iterator oIter = objects.begin();
	while(oIter != objects.end())
	{
		delete *oIter;
		++oIter;
	}
	objects.clear();
	std::list<Sort*>::iterator sIter = sorts.begin();
	while(sIter != sorts.end())
	{
		delete *sIter;
		++sIter;
	}
	sorts.clear();
	std::list<Variable*>::iterator vIter = variables.begin();
	while(vIter != variables.end())
	{
		delete *vIter;
		++vIter;
	}
	variables.clear();
	std::list<Query*>::iterator qIter = queries.begin();
	while(qIter != queries.end())
	{
		delete *qIter;
		++qIter;
	}
	queries.clear();
	// Reset and deallocate the internal ostream pointers.
	if(ostNullPtr)
	{
		if(ostOutPtr)
		{
			ostOutPtr->rdbuf(ostNullPtr->rdbuf());
		}
		if(ostErrPtr)
		{
			ostErrPtr->rdbuf(ostNullPtr->rdbuf());
		}
	}
	delete ostOutPtr;
	delete ostErrPtr;
	delete ostNullPtr;
	// Close fNull so we don't leave an open file handle.
	fNull.close();
}

bool Translator::setIncrementalPart(IPart newIncPart) {
	if (!ostOutPtr) return false;
	if (newIncPart == mCurrentPart) return true;

	if (!blnStaticTrans) {
		switch (newIncPart) {
		case IPART_BASE:
			output("#base.",true);
			break;
		case IPART_CUMULATIVE:
			output("#cumulative " + dynamicTimeStamp + ".",true);
			break;
		case IPART_VOLATILE:
			output("#volatile " + dynamicTimeStamp + ".",true);
			break;
		case IPART_NONE:
			return true;
		default:
			return false;
		}
	}

	mCurrentPart = newIncPart;
	return true;

}

void Translator::output(std::string const& str, IPart ipart, bool endWithNewline) {
	if (mCurrentPart != ipart) setIncrementalPart(ipart);
	output(str, endWithNewline);
}

// helper to output statements to the output stream
void Translator::outputStmts(StmtList const& stmts) {
	for (StmtList::const_iterator it = stmts.begin(); it != stmts.end(); it++) {
		output(it->first, it->second, true);
	}
}

// Dumpts the symbol table to the output stream.
std::ostream& Translator::outputSymbolTable(std::ostream& out) {
	// TODO
	out << "<Not yet implemented>\n";
	return out;
}
