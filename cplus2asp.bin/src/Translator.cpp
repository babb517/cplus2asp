#include <list>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

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
std::string Translator::sanitizeConstantName(std::string& originalName)
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
std::string Translator::sanitizeObjectName(std::string& originalName)
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
std::string Translator::sanitizeSortName(std::string& originalName)
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
std::string Translator::sanitizeVariableName(std::string& originalName)
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
std::string Translator::sanitizeString(std::string& originalString)
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
std::string Translator::translateVariableDeclToString(Variable* transVar)
{
	std::ostringstream retStream;
	// Sanity check: make sure the variable isn't NULL and neither is its sort.
	if(transVar && transVar->sortRef)
	{
		// Variable declarations are just domain variable declarations.
		retStream << "#domain " << transVar->sortRef->fullTransName() << "(";
		retStream << transVar->fullTransName() << ").";
	}
	return retStream.str();
}

// Returns a standardized sort name representing a range of numbers.
std::string Translator::numRangeToSortName(std::string& min, std::string& max)
{
	std::string tempStr = NUMRANGE_TO_SORT_PREFIX;
	tempStr += Context::ANON_STR;
	tempStr += Translator::sanitizeString(min);
	tempStr += Context::ANON_STR;
	tempStr += Translator::sanitizeString(max);
	return tempStr;
}

// Turns a sort name into a variable version of itself.
std::string Translator::sortNameToVariable(std::string& sortName, bool sanitizeFirst)
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
	SimpleBinaryOperator* tempPE = new SimpleBinaryOperator();
	tempPE->opType = SimpleBinaryOperator::BOP_AND;
	tempPE->preOp = first;
	tempPE->postOp = second;
	return tempPE;
}

/* Normal class methods */

// Default constructor. Initializes attributes to blank/empty.
Translator::Translator()
{
	// Open a null file output and set ostNull to it.
	fNull.open("/dev/null");
	ostNullPtr = new std::ostream(fNull.rdbuf());
	// Start ostOutPtr and ostErrPtr using fNull as well.
	ostOutPtr = new std::ostream(ostNullPtr->rdbuf());
	ostErrPtr = new std::ostream(ostNullPtr->rdbuf());
	// Allocate an initial tempQuery.
	tempQuery = new Query();
	// Set up default internal sorts & their objects.
	Sort* newSort = NULL;
	std::list<Sort*> internalSortList; // Used when some kind of parameter list is required.
	std::string tempName;
	// Create the boolean* (and, by extension, the boolean) domains.
	newSort = this->createInternalSort("boolean*", internalSortList);
	tempName = "boolean";
	newSort = this->getSort(tempName);
	// Create "true" and "false" members of the boolean sort.
	this->createInternalObject("true", internalSortList, newSort);
	this->createInternalObject("false", internalSortList, newSort);
	// Create astep, the action time sort.
	newSort = this->createInternalSort("astep", internalSortList);
	// Attach "0..maxstep-1" range to astep.
	this->createInternalNumRange("0..maxstep-1", "0", "maxstep-1", newSort);
	// Create step, the fluent time sort (supersort of astep).
	internalSortList.push_back(newSort);
	newSort = this->createInternalSort("step", internalSortList);
	internalSortList.clear();
	// Add "maxstep" object to step's domain.
	this->createInternalObject("maxstep", internalSortList, newSort);
	// Create additiveInteger, the integer sort for additive constants.
	newSort = this->createInternalSort("additiveInteger", internalSortList);
	// Attach "-maxAdditive..maxAdditive" range to additiveInteger.
	this->createInternalNumRange("-maxAdditive..maxAdditive", "-maxAdditive", "maxAdditive", newSort);
	// Create nnAdditiveInteger, the positive integer sort for additive constants.
	newSort = this->createInternalSort("nnAdditiveInteger", internalSortList);
	// Attach "0..maxAdditive" range to nnAdditiveInteger.
	this->createInternalNumRange("0..maxAdditive", "0", "maxAdditive", newSort);
	// Set up internal constant sorts.
	internalSortList.clear();
	std::list<Sort*> subsortList;
	// Action sorts.
	newSort = this->createInternalSort("abAction", internalSortList);
	subsortList.push_back(newSort);
	newSort = this->createInternalSort("attribute", internalSortList);
	subsortList.push_back(newSort);
	newSort = this->createInternalSort("exogenousAction", internalSortList);
	subsortList.push_back(newSort);
	newSort = this->createInternalSort("additiveAction", internalSortList);
	subsortList.push_back(newSort);
	// The "action" grouped meta-sort.
	newSort = this->createInternalSort("action", subsortList);
	subsortList.clear();
	// Fluent sorts.
	newSort = this->createInternalSort("inertialFluent", internalSortList);
	subsortList.push_back(newSort);
	newSort = this->createInternalSort("additiveFluent", internalSortList);
	subsortList.push_back(newSort);
	// simpleFluent has inertialFluent and additiveFluent as its subsorts.
	newSort = this->createInternalSort("simpleFluent", subsortList);
	subsortList.clear();
	subsortList.push_back(newSort);
	newSort = this->createInternalSort("sdFluent", internalSortList);
	subsortList.push_back(newSort);
	// Rigids aren't technically "fluents" after translation, but in CCalc they still are.
	newSort = this->createInternalSort("rigid", internalSortList);
	subsortList.push_back(newSort);
	// The "fluent" grouped meta-sort.
	newSort = this->createInternalSort("fluent", subsortList);
	subsortList.clear();
	
	// Add the contribution constant for additive actions.
	std::string contrib_string("contribution");
	Constant* contribution = new Constant(contrib_string,Translator::sanitizeConstantName(contrib_string));
	std::string action("action");
	contribution->params.push_back(getSort(action));
	std::string additiveAction("additiveAction");
	contribution->params.push_back(getSort(additiveAction));
	contribution->constType = Constant::CONST_ACTION;
	tempName = "additiveInteger";
	contribution->domain = getSort(tempName);
	addConstant(contribution);

	// Add the contribution constant for additive fluents.
	contribution = new Constant(contrib_string,Translator::sanitizeConstantName(contrib_string));
	contribution->params.push_back(getSort(action));
	std::string additiveFluent("additiveFluent");
	contribution->params.push_back(getSort(additiveFluent));
	contribution->constType = Constant::CONST_ACTION;
	contribution->domain = getSort(tempName);
	addConstant(contribution);
	
	// we want to use a dynamic translation.
	setStaticTranslation(false);

	blnFoundAbnormalities = false;
	blnFoundAdditive = false;

	// Initialize the incremental part
	mCurrentPart = Context::NONE;


}

// Searches for a Constant object matching the given name and parameters.
Constant* Translator::getConstant(std::string const& symName, std::vector<std::string> const& symParams)
{
	Constant* retVal = NULL;
	std::list<Constant*>::iterator cIter = constants.begin();
	while(cIter != constants.end())
	{
		if((*cIter)->name == symName && (*cIter)->params.size() == symParams.size())
		{
			bool paramsMatch = true;
			for(size_t i = 0; i < (*cIter)->params.size() && i < symParams.size(); i++)
			{
				if((*cIter)->params[i]->name != symParams[i])
				{
					paramsMatch = false;
					break;
				}
			}
			if(paramsMatch)
			{
				retVal = *cIter;
				break;
			}
		}
		++cIter;
	}
	return retVal;
}

// Searches for a Object object matching the given name and parameters.
Object* Translator::getObject(std::string const& symName, std::vector<std::string> const& symParams)
{
	Object* retVal = NULL;
	std::list<Object*>::iterator oIter = objects.begin();
	while(oIter != objects.end())
	{
		if((*oIter)->name == symName && (*oIter)->params.size() == symParams.size())
		{
			bool paramsMatch = true;
			for(size_t i = 0; i < (*oIter)->params.size() && i < symParams.size(); i++)
			{
				if((*oIter)->params[i]->name != symParams[i])
				{
					paramsMatch = false;
					break;
				}
			}
			if(paramsMatch)
			{
				retVal = *oIter;
				break;
			}
		}
		++oIter;
	}
	return retVal;
}

// Searches for a Sort object matching the given name.
Sort* Translator::getSort(std::string const& symName)
{
	Sort* retVal = NULL;
	std::list<Sort*>::iterator sIter = sorts.begin();
	while(sIter != sorts.end())
	{
		if((*sIter)->name == symName)
		{
			retVal = *sIter;
			break;
		}
		++sIter;
	}
	return retVal;
}

// Searches for a Variable object matching the given name.
Variable* Translator::getVariable(std::string const& symName)
{
	Variable* retVal = NULL;
	std::list<Variable*>::iterator vIter = variables.begin();
	while(vIter != variables.end())
	{
		if((*vIter)->name == symName)
		{
			retVal = *vIter;
			break;
		}
		++vIter;
	}
	return retVal;
}

// Searches for a Query object with the given label
Query* Translator::getQuery(std::string const& testLabel)
{
	Query* retVal = NULL;
	std::list<Query*>::iterator qIter = queries.begin();
	while(qIter != queries.end())
	{
		if((*qIter)->label == testLabel)
		{
			retVal = *qIter;
			break;
		}
		++qIter;
	}
	return retVal;
}

// Searches for a Constant object matching the given name and number of parameters.
Constant* Translator::getConstantLike(std::string const& symName, size_t numParams)
{
	Constant* retVal = NULL;
	std::list<Constant*>::iterator cIter = constants.begin();
	while(cIter != constants.end())
	{
		if((*cIter)->name == symName && (*cIter)->params.size() == numParams)
		{
			retVal = *cIter;
			break;
		}
		++cIter;
	}
	return retVal;
}

// Searches for a Object object matching the given name and number of parameters.
Object* Translator::getObjectLike(std::string const& symName, size_t numParams, bool isLua)
{
	Object* retVal = NULL;
	std::list<Object*>::iterator oIter = objects.begin();
	while(oIter != objects.end())
	{
		if((*oIter)->name == symName && (*oIter)->params.size() == numParams && (*oIter)->isLua == isLua)
		{
			retVal = *oIter;
			break;
		}
		++oIter;
	}

	// Allow lua objects to be dynamically declared.
	if (retVal == NULL && isLua) {
		// Ensure that we preserve the name of the object and append the LUA symbol.
		retVal = new Object(symName, symName, true);
		addObject(retVal);
	}

	return retVal;
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
	if(newConst)
	{
		// Try adding it into the symbol table, and then into local data structures if successful.
		std::vector<std::string> paramNames = utils::elementVectorToNameVector(newConst->params);
		retVal = symbols.addSymbol(newConst->name, paramNames, SymbolNode::SYM_CONST);
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
		std::vector<std::string> paramNames; // Sorts don't have parameters, pass an empty vector.
		retVal = symbols.addSymbol(newSort->name, paramNames, SymbolNode::SYM_SORT);
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

// Attempts to add a new Variable object to the translator's data structures and the symbol table.
int Translator::addVariable(Variable* newVar)
{
	int retVal = SymbolTable::ADDSYM_ERR; // Start pessimistic.
	if(newVar)
	{
		// Try adding it into the symbol table, and then into local data structures if successful.
		std::vector<std::string> paramNames; // Variables don't have parameters, pass an empty vector.
		retVal = symbols.addSymbol(newVar->name, paramNames, SymbolNode::SYM_VAR);
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
void Translator::translateConstantDecl(Constant* transConst)
{
	// Sanity check: make sure the element isn't NULL.
	if(transConst)
	{
		// Detect if it's an abnormality constant and set the appropriate flag.
		if (Constant::isAbnormalityType(transConst->constType)) {
			blnFoundAbnormalities = true;
		}

		// Detect if it's an additive constant and set the appropriate flag.
		if (transConst->constType == Constant::CONST_ADDITIVEACTION
				|| transConst->constType == Constant::CONST_ADDITIVEFLUENT) {
			blnFoundAdditive = true;
		}

		bool needDynamicParams = false; 								// Set to true if two or more of the constant's parameters (if any) are the same.
		ElementCounter eCount; 											// Used to track occurrences of identical parameters (to avoid name clashes).
		std::vector<std::string> paramVarNames;							// Holds unique parameter variable names for translation.
		std::string fullDeclConstName = ""; 							// Holds the results of transforming the constant's name and parameters.

		std::stringstream stmtBuilder;									// Used to build each individual statement required for this declaration.
		StmtList stmts;													// Used to aggregate the statements we need and output them all simultaneously.

		// Transform the type of the constant into a string representation.
		std::string constTypeName = Constant::constTypeToString(transConst->constType);


		// Ouput the class of constant, then its translated name.
		stmtBuilder << constTypeName << "(";
		fullDeclConstName += transConst->transName;
		// Transform any parameters into sort variables.
		if(!transConst->params.empty())
		{
			fullDeclConstName += "(";
			std::string tempVarName;
			// Use an occurrence counter to get guaranteed unique variable
			// names representing the sorts that comprise the parameters
			// of this constant.
			for(size_t i = 0; i < transConst->params.size(); i++)
			{
				eCount.push_back(transConst->params[i]);
				if(((Sort*)eCount.elementsBack())->sortVar)
				{
					tempVarName = ((Sort*)eCount.elementsBack())->sortVar->fullTransName();
				}
				else
				{
					tempVarName = "NULL";
				}
				paramVarNames.push_back(tempVarName);
				// Add the occurrence count to the variable name if we've
				// seen this sort before.
				if(eCount.countsBack() > 0)
				{
					paramVarNames.back() += Context::ANON_STR;
					paramVarNames.back() += utils::to_string(eCount.countsBack());
					needDynamicParams = true;
				}
				if(i > 0)
				{	// Separate parameter names if there's more than one.
					fullDeclConstName += ",";
				}
				fullDeclConstName += paramVarNames.back();
			}
			fullDeclConstName += ")";
		}
		// Now that we've created the full declarable constant name, use that.
		stmtBuilder << fullDeclConstName << ")";
		
		// If we had to dynamically use "extra" variables to avoid name clashes, bind them locally now.
		if(needDynamicParams)
		{
			stmtBuilder << " <- ";
			size_t j = 0;
			for(size_t i = 0; i < eCount.size(); i++)
			{
				if(eCount.countAt(i) > 0)
				{
					if(j > 0)
					{	// Separate multiple local variable bindings.
						stmtBuilder << " & ";
					}
					stmtBuilder << transConst->params[i]->fullTransName();
					stmtBuilder << "(" << paramVarNames[i] << ")";
					j++;
				}
			}
		}
		stmtBuilder << ".";

		// Add the first statement to the list.
		stmts.push_back(Statement(stmtBuilder.str(),Context::BASE));
		stmtBuilder.str("");
		
		// Output the line connecting a constant to its domain.
		if(transConst->domain)
		{
			stmtBuilder << "constant_sort(" << fullDeclConstName << ",";
			stmtBuilder << transConst->domain->fullTransName() << ")";
			// If we had to dynamically use "extra" variables to avoid name clashes, bind them locally now.
			if(needDynamicParams)
			{
				stmtBuilder << " <- ";
				size_t j = 0;
				for(size_t i = 0; i < eCount.size(); i++)
				{
					if(eCount.countAt(i) > 0)
					{
						if(j > 0)
						{	// Separate multiple local variable bindings.
							stmtBuilder << " & ";
						}
						stmtBuilder << transConst->params[i]->fullTransName();
						stmtBuilder << "(" << paramVarNames[i] << ")";
						j++;
					}
				}
			}
			stmtBuilder << ".";

			// Add the next statement to the list...
			stmts.push_back(Statement(stmtBuilder.str(),Context::BASE));
			stmtBuilder.str("");
		}

		// If the constant is an attribute, connect the attribute to its action.
		if(transConst->constType == Constant::CONST_ATTRIBUTE)
		{
			// Sanity check: attributeOf can't be NULL.
			if(((Attribute*)transConst)->attributeOf)
			{
				stmtBuilder << "action_attribute(";
				// Perform the same variable replacement magic on the attribute's action.
				Constant *aConst = ((Attribute*)transConst)->attributeOf;
				std::string aFullDeclConstName = aConst->transName;
				bool aNeedDynamicParams = false;
				ElementCounter aCount;
				std::vector<std::string> aParamVarNames;
				if(!aConst->params.empty())
				{
					aFullDeclConstName += "(";
					std::string aTempVarName;
					// Use an occurrence counter to get guaranteed unique variable
					// names representing the sorts that comprise the parameters
					// of this constant.
					for(size_t i = 0; i < aConst->params.size(); i++)
					{
						aCount.push_back(aConst->params[i]);
						if(((Sort*)aCount.elementsBack())->sortVar)
						{
							aTempVarName = ((Sort*)aCount.elementsBack())->sortVar->fullTransName();
						}
						else
						{
							aTempVarName = "NULL";
						}
						aParamVarNames.push_back(aTempVarName);
						// Add the occurrence count to the variable name if we've
						// seen this sort before.
						if(aCount.countsBack() > 0)
						{
							aParamVarNames.back() += Context::ANON_STR;
							aParamVarNames.back() += utils::to_string(aCount.countsBack());
							aNeedDynamicParams = true;
						}
						if(i > 0)
						{	// Separate parameter names if there's more than one.
							aFullDeclConstName += ",";
						}
						aFullDeclConstName += aParamVarNames.back();
					}
					aFullDeclConstName += ")";
				}
				stmtBuilder << aFullDeclConstName;
				stmtBuilder << ",";
				stmtBuilder << fullDeclConstName;
				stmtBuilder << ")";
				// If we had to dynamically use "extra" variables to avoid name clashes, bind them locally now.
				size_t j = 0;
				if(needDynamicParams)
				{
					stmtBuilder << " <- ";
					for(size_t i = 0; i < eCount.size(); i++)
					{
						if(eCount.countAt(i) > 0)
						{
							if(j > 0)
							{	// Separate multiple local variable bindings.
								stmtBuilder << " & ";
							}
							stmtBuilder << transConst->params[i]->fullTransName();
							stmtBuilder << "(" << paramVarNames[i] << ")";
							j++;
						}
					}
				}
				if(aNeedDynamicParams)
				{
					if(!needDynamicParams)
					{
						stmtBuilder << " <- ";
					}
					for(size_t i = 0; i < aCount.size(); i++)
					{
						if(aCount.countAt(i) > 0)
						{
							if(j > 0)
							{	// Separate multiple local variable bindings.
								stmtBuilder << " & ";
							}
							stmtBuilder << aConst->params[i]->fullTransName();
							stmtBuilder << "(" << aParamVarNames[i] << ")";
							j++;
						}
					}
				}
				stmtBuilder << "." << std::endl;

				// Add the next statement to the list...
				stmts.push_back(Statement(stmtBuilder.str(),Context::BASE));
				stmtBuilder.str("");
			}
		}

		// Output all of the statements...
		outputStmts(stmts);
	}
}

// Translates an Object element into an ASP-compatible declaration of an
// object as a member of a sort's domain.
void Translator::translateObjectDecl(Object* transObj, Sort* sortObj)
{
	// Sanity check: make sure the object isn't NULL, and neither is its sort.
	if(transObj && sortObj)
	{
		// An object delcaration is the sort's name, and then the object
		// name in parentheses.
		bool needDynamicParams = false; 				// Set to true if two or more of the object's parameters (if any) are the same.
		ElementCounter eCount; 							// Used to track occurrences of identical parameters (to avoid name clashes).
		std::vector<std::string> paramVarNames; 		// Holds unique parameter variable names for translation.

		std::stringstream stmtBuilder;					// Used to build each individual statement required for this declaration.


		stmtBuilder << sortObj->fullTransName() << "(";
		if(transObj->objType == Object::OBJ_RANGE)
		{	// Number range, ensure we get its translated name.
			stmtBuilder << ((NumberRange*)transObj)->fullTransName();
		}
		else
		{	// Just a plain object. Use its name and transform its parameters
			// into sort variables.
			stmtBuilder << transObj->transName;
			if(!transObj->params.empty())
			{
				stmtBuilder << "(";
				std::string tempVarName;
				// Use an occurrence counter to get guaranteed unique
				// variable names representing the sorts that comprise
				// the parameters of this object.
				for(size_t i = 0; i < transObj->params.size(); i++)
				{
					eCount.push_back(transObj->params[i]);
					if(((Sort*)eCount.elementsBack())->sortVar)
					{
						tempVarName = ((Sort*)eCount.elementsBack())->sortVar->fullTransName();
					}
					else
					{
						tempVarName = "NULL";
					}
					paramVarNames.push_back(tempVarName);
					// Add the occurrence count to the variable name if we've
					// seen this sort before.
					if(eCount.countsBack() > 0)
					{
						paramVarNames.back() += Context::ANON_STR;
						paramVarNames.back() += utils::to_string(eCount.countsBack());
						needDynamicParams = true;
					}
					if(i > 0)
					{	// Separate parameter names if there's more than one.
						stmtBuilder << ",";
					}
					stmtBuilder << paramVarNames.back();
				}
				stmtBuilder << ")";
			}
		}

		stmtBuilder << ")";

		// If we had to dynamically use "extra" variables to avoid name clashes, bind them locally now.
		if(needDynamicParams)
		{
			stmtBuilder << " <- ";
			size_t j = 0;
			for(size_t i = 0; i < eCount.size(); i++)
			{
				if(eCount.countAt(i) > 0)
				{
					if(j > 0)
					{	// Separate multiple local variable bindings.
						stmtBuilder << " & ";
					}
					stmtBuilder << transObj->params[i]->fullTransName();
					stmtBuilder << "(" << paramVarNames[i] << ")";
					j++;
				}
			}
		}
		stmtBuilder << ".";

		// Output the statement
		output(stmtBuilder.str(), Context::BASE, true);
	}
}

// Translates a Sort element into an ASP-compatible sort declaration.
void Translator::translateSortDecl(Sort* transSort)
{
	// Sanity check: make sure the sort isn't NULL.
	if(transSort)
	{
		StmtList stmts;									// Used to aggregate the statements we need and output them all simultaneously.

		// A translated sort declaration involves three things:
		// Declare the sort name.
		stmts.push_back(Statement("sort(" + transSort->fullTransName() + ").",Context::BASE));

		// The sort's default variable and the line connecting the sort 
		// to its objects (if the variable reference isn't NULL).
		if(transSort->sortVar)
		{
			stmts.push_back(
				Statement(
						"#domain " + transSort->fullTransName()
						+ "(" + transSort->sortVar->fullTransName() + ").", Context::BASE
						)
				);

			stmts.push_back(
				Statement(
						"sort_object(" + transSort->fullTransName() + ","
						+ transSort->sortVar->fullTransName() + ").", Context::BASE
						)
				);
		}
		else
		{
			/// @todo Error if sortVar == NULL.
		}

		// If the sort has subsorts, add lines indicating that all members of
		// the subsorts are also members of the sort.
		if(!transSort->subsorts.empty())
		{
			for(size_t i = 0; i < transSort->subsorts.size(); i++)
			{
				Translator::translateSubsortDecl(transSort, transSort->subsorts[i]);
			}
		}

		// Additionally, we're going to hide the sort from view to prevent clutter
		stmts.push_back(
			Statement(
					"#hide " + transSort->fullTransName() + "("
					+ transSort->sortVar->fullTransName() + ").\n", Context::BASE
					)
			);

		// Output all the statements!
		outputStmts(stmts);
	}
}

// Translates a declaration of a super/sub-sort relationship between two sorts.
void Translator::translateSubsortDecl(Sort* transSupersort, Sort* transSubsort)
{
	if(transSupersort && transSubsort)
	{

		if(transSubsort->sortVar)
		{
			output(
					transSupersort->fullTransName() + "(" + transSubsort->sortVar->fullTransName() + ")."
					, Context::BASE, true
					);
		}
		else
		{
			/// @todo Error if transSubsort's sortVar == NULL.
		}
	}
}

// Translates a Variable element into an ASP-compatible variable declaration.
void Translator::translateVariableDecl(Variable* transVar)
{
	// We've got a version that already creates a string of the declaration,
	// just use that and send it to output.
	output(Translator::translateVariableDeclToString(transVar), Context::BASE, true);
}


// Translates a Query into an ASP-compatible query declaration.
void Translator::translateQuery(Query* transQuery)
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
					Context::NONE
					)
			);

		// For each item in queryConditions, output an ASP-style constraint for it.
		for(std::list<ParseElement*>::iterator lIter = transQuery->queryConditions.begin(); lIter != transQuery->queryConditions.end(); ++lIter)
		{
			bool isDynamic = false;
			int tmpLoc;
			std::string tmpQueryTimeStamp;

			// set up everything for our use
			ossOutputBuffer.str("");

			// Transform 'maxstep' to the appropriate timestamp
			if (!blnStaticTrans) {
				tmpQueryTimeStamp = (*lIter)->getQueryTimeStamp();
				while ((tmpLoc = tmpQueryTimeStamp.find("maxstep")) != std::string::npos) {
					// we have a 'maxstep' occurrence in the string
					isDynamic = true;
					tmpQueryTimeStamp.replace(tmpLoc, 7, dynamicTimeStamp);
				}
				if (isDynamic) (*lIter)->setQueryTimeStamp(tmpQueryTimeStamp);
			}

			ossOutputBuffer << "false <- query_label(" << transQuery->label << ") & not (";
			(*lIter)->translateQuery(ossOutputBuffer);

			// end the statement.
			ossOutputBuffer << ").";

			// output all the resulting statements...
			if (isDynamic)
				stmts.push_back(Statement(ossOutputBuffer.str(),Context::VOLATILE));
			else
				stmts.push_back(Statement(ossOutputBuffer.str(),Context::BASE));
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
	ParseElement* whenBody,
	ParseElement* followingBody,
	ParseElement* whereBody
	)
{
	// The initialized values default to "static law" (i.e., fluents only, no "after").
	RuleType type = RULE_STATIC;	// The type of the rule we're currently working with.

	bool needsNotNot = false;		// true if the only constants within the head of the rule are "true" and "false" amd we're only using 1 timestep.
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
			|| (whenBody && whenBody->hasLuaCalls())
			|| (followingBody && followingBody->hasLuaCalls()))
	{
		// They have at least one call to lua outside the where clause.
		// Throw an error.
		error("External function calls are only permitted within the where clause of a causal law.\n");
		malformed = true;
	}



	// step 3: Ensure that abnormalities are where they are supposed to be...
	if ( head->hasAbnormalities()
			|| (ifBody && ifBody->hasAbnormalities())
			|| (assumingBody && assumingBody->hasAbnormalities())
			|| (afterBody && afterBody->hasAbnormalities())
			|| (whereBody && whereBody->hasAbnormalities()))
	{
		// The law has abnormalities outside of the when / following clauses...
		error("Abnormality constants cannot occur outside of 'when' and 'following' clauses of a law.\n");
		malformed = true;
	}

	// ensure that the when and following bodies have _only_ abnormalities.
	if ((whenBody && ( whenBody->hasActions() || whenBody->hasFluents()))
			|| (followingBody && (followingBody->hasActions() || followingBody->hasFluents())))
	{
		// The law has abnormalities outside of the when / following clauses...
		error("Fluent and Action constants cannot occur within the 'when' and 'following' clauses of a law.\n");
		malformed = true;
	}

	// Step 4a: Determine if the law is a 'rigid' law, which contains a rigid fluent in the head (Alternatively, if it contains 'exogenous' or 'inertial').
	if (head->hasRigidElements()) {
		type = RULE_RIGID;

		// Verification: We don't allow any non-rigid fluents in the rule.
		if (head->hasNonRigidConstants()
				|| (ifBody && ifBody->hasNonRigidConstants())
				|| (assumingBody && assumingBody->hasNonRigidConstants())
				|| (afterBody && afterBody->hasNonRigidConstants())
				|| (whenBody && whenBody->hasNonRigidConstants())
				|| (followingBody && followingBody->hasNonRigidConstants())
			)
		{
			error("A causal law w/ rigid fluents in the head and non-rigid fluents in the body is (currently) unsupported.\n");
			malformed = true;
		}
	}
	// Step 4b: Determine whether the law is a static law, an action dynamic law, or a fluent dynamic law...
	// Static laws...
	else if (head->hasFluents() && !head->hasActions()
			&& (!ifBody || !ifBody->hasActions())
			&& (!assumingBody || !assumingBody->hasActions())
			&& (!whenBody || !whenBody->hasDynamicAbnormalities())
			&& !afterBody
			&& !followingBody)
	{
		type = RULE_STATIC;
		baseTimeStamp = staticTimeStamp;
	}
	// fluent dynamic laws...
	else if (head->hasFluents() && !head->hasActions()
			&& (!ifBody || !ifBody->hasActions())
			&& (!assumingBody || !assumingBody->hasActions())
			&& (!whenBody || !whenBody->hasDynamicAbnormalities()))
	{
		type = RULE_FLUENTDYNAMIC;
		baseTimeStamp = dynamicTimeStamp;
	}
	// action dynamic laws...
	else if (head->hasActions() && !head->hasFluents()
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
	if (!head->isTrivial() && (type == RULE_STATIC || type == RULE_ACTIONDYNAMIC || type == RULE_RIGID)) {
		needsNotNot = true;
	}

	// catch malformed rules and don't translate them.
	if (malformed) return;

	// Let's do the translation!

	// We may need a 'static' copy for the base module
	if (!blnStaticTrans && (type == RULE_STATIC || type == RULE_RIGID)) {
		makeCausalTranslation(
			ossOutputBuffer,
			stmts,
			Context::BASE,
			needsNotNot,
			"0",
			head,
			ifBody,
			assumingBody,
			afterBody,
			whenBody,
			followingBody,
			whereBody
		);
		stmts.push_back(Statement(ossOutputBuffer.str(),Context::BASE));
		ossOutputBuffer.str("");
	}

	// We also are going to need a dynamic version of the rule, unless the rule is rigid.
	if (blnStaticTrans || type != RULE_RIGID) {
		makeCausalTranslation(
			ossOutputBuffer,
			stmts,
			Context::CUMULATIVE,
			needsNotNot,
			baseTimeStamp,
			head,
			ifBody,
			assumingBody,
			afterBody,
			whenBody,
			followingBody,
			whereBody
		);
		stmts.push_back(Statement(ossOutputBuffer.str(),Context::CUMULATIVE));
		ossOutputBuffer.str("");
	}

	// write the resulting statements to the output
	outputStmts(stmts);

}

// Helper method for the translation.
std::ostream& Translator::makeCausalTranslation(
	std::ostream& output,
	StmtList& extraStmts,
	Context::IPart ipart,
	bool needsNotNot,
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
	ParseElement::extraClauseCount = 0; // Reset the extra clause counter.

	// The head
	/// @todo If head and ifBody are: not NULL, both const-like or both UOP_NOT(const-like), make a choice rule out of head and translate that.

	localContext = Context(Context::POS_HEAD, ipart, baseTimeStamp, &localClauses, NULL, false, true);
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
			if(needsNotNot) {
				output << "not not (";
				localContext = Context(Context::POS_BODY, ipart, baseTimeStamp, NULL, NULL, true, false);
				bindAndTranslate(output, ifBody, localContext, false);
				output << ")";
			}
			else {
				localContext = Context(Context::POS_BODY, ipart, baseTimeStamp, &localClauses, NULL, false, false);
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
			localContext = Context(Context::POS_BODY, ipart, baseTimeStamp, NULL, NULL, false, false);
			assumingBody->translate(output, localContext);
		}

		// "after" part of body, if there is one.
		if(afterBody)
		{
			// add a connective if necessary.
			if(bodyContent)	output << " & ";
			else bodyContent = true;

			// If we're translating a law that needs a "not not (...)" body wrapper to break cycles, add it.
			if(needsNotNot) {
				output << "not not (";
				localContext = Context(Context::POS_BODY, ipart, actionTimeStamp, NULL, NULL, true, false);
				bindAndTranslate(output, afterBody, localContext, false);
				output << ")";
			}
			else {
				localContext = Context(Context::POS_BODY, ipart, actionTimeStamp, &localClauses, NULL, false, false);
				afterBody->translate(output, localContext);
			}

		}
		
		// "when" part of the body, if there is one.
		if (whenBody)
		{
			// add a connective if necessary
			if(bodyContent)	output << " & ";
			else bodyContent = true;
			localContext = Context(Context::POS_BODY, ipart, baseTimeStamp, &localClauses, NULL, false, false);
			whenBody->translate(output, localContext);
		}

		// "following" part of the body, if there is one
		if (followingBody)
		{

			// add a connective if necessary
			if(bodyContent)	output << " & ";
			else bodyContent = true;
			localContext = Context(Context::POS_BODY, ipart, actionTimeStamp, &localClauses, NULL, false, false);
			followingBody->translate(output, localContext);
		}

		// "where" part of body, if there is one.
		if(whereBody)
		{
			// add a connective if necessary
			if(bodyContent)	output << " & ";
			else bodyContent = true;
			localContext = Context(Context::POS_BODY, ipart, baseTimeStamp, &localClauses, NULL, false, false);
			whereBody->translate(output, localContext);
		}
		
		// handle extra clauses
		outputClauses(output, localClauses, bodyContent);
	}
	output << ".";

	return output;
}

// Convenience method that handles unlessBody and then merges afterBody and "not unlessBody", calling the next wrapper down.
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
	// Create "not unlessBody" if unlessBody exists.
	bool unlessCreationFailed = false; // Set to true if something goes wrong during the preparation of the unless clause.
	SimpleUnaryOperator* tempUOP = NULL;
	SimpleBinaryOperator* tempPE = NULL;
	ConstantLikeElement* unlessConstLike = NULL;

	if(unlessBody)
	{
		// The unlessBody needs to be a constant (or a constant miscategorized as an object) or this whole thing doesn't make sense.
		if(unlessBody->getType() == ParseElement::PELEM_CONSTLIKE || unlessBody->getType() == ParseElement::PELEM_OBJLIKE)
		{
			unlessConstLike = new ConstantLikeElement();
			if(unlessBody->getType() == ParseElement::PELEM_CONSTLIKE)
			{
				unlessConstLike->baseName = ((ConstantLikeElement*)unlessBody)->baseName;
				unlessConstLike->params = ((ConstantLikeElement*)unlessBody)->params;
				unlessConstLike->constRef = ((ConstantLikeElement*)unlessBody)->constRef;
			}
			else
			{
				unlessConstLike->baseName = ((ObjectLikeElement*)unlessBody)->baseName;
				unlessConstLike->params = ((ObjectLikeElement*)unlessBody)->params;
				unlessConstLike->constRef = NULL;
			}
			// If the constant in unlessBody doesn't even exist yet, make that first.
			if(unlessBody->getType() == ParseElement::PELEM_OBJLIKE || unlessConstLike->constRef == NULL)
			{
				// Take a best guess at what the parameters, if any, of the constant should be.
				std::string tempStr = "";
				Constant* unlessConst = new Constant();
				unlessConst->name = unlessConstLike->baseName;
				unlessConst->transName = Translator::sanitizeConstantName(unlessConstLike->baseName);
				tempStr = "boolean";
				unlessConst->domain = this->getSort(tempStr);
				// For each parameter, try to figure out what sort it came from.
				std::vector<Sort*> tempSortParams;
				for(std::vector<ParseElement*>::iterator vIter = unlessConstLike->params.begin(); vIter != unlessConstLike->params.end(); ++vIter)
				{
					if((*vIter)->getType() == ParseElement::PELEM_VARLIKE)
					{
						if(((VariableLikeElement*)(*vIter))->varRef && ((VariableLikeElement*)(*vIter))->varRef->sortRef)
						{
							tempSortParams.push_back(((VariableLikeElement*)(*vIter))->varRef->sortRef);
						}
						else
						{	// varRef didn't pan out, try finding the Variable that goes with this VariableLikeElement.
							tempStr = ((VariableLikeElement*)(*vIter))->baseName;
							Variable* varResult = this->getVariableLike(tempStr);
							if(varResult && varResult->sortRef)
							{
								tempSortParams.push_back(varResult->sortRef);
							}
							else
							{	// Couldn't find the sort for the variable, give up.
								this->error("Could not dynamically declare constant \"" + unlessConstLike->fullName() + "\", could not figure out the sort(s) of its parameter(s). Declaring the constant yourself will fix this problem.", true);
								unlessCreationFailed = true;
							}
						}
					}
					else
					{	// Anything but a variable and we probably can't guess the sort.
						this->error("Could not dynamically declare constant \"" + unlessConstLike->fullName() + "\", could not figure out the sort(s) of its parameter(s). Declaring the constant yourself will fix this problem.", true);
						unlessCreationFailed = true;
					}
				}
				if(!unlessCreationFailed)
				{	// We found sorts for all the parameters, assign the vector to our new Constant.
					unlessConst->params = tempSortParams;
					// What kind of constant unlessBody should be is based on what kind of law it's seen in.
					// It's an abAction unless it's first seen in a static law, then it's an sdFluent.
					unlessConst->constType = Constant::CONST_ABACTION;
					if(!head->hasActions() && head->hasFluents())
					{
						if(ifBody == NULL && afterBody == NULL)
						{	// Static law, this is an sdFluent.
							unlessConst->constType = Constant::CONST_SDFLUENT;
						}
						else if(ifBody && afterBody == NULL && (!ifBody->hasActions() && ifBody->hasFluents()))
						{	// Another form of static law, this is an sdFluent.
							unlessConst->constType = Constant::CONST_SDFLUENT;
						}
					}
					int addResult = this->addConstant(unlessConst);
					if(addResult != SymbolTable::ADDSYM_OK)
					{	// Throw an error about the ab constant being a bad symbol.
						if(addResult == SymbolTable::ADDSYM_BAD)
						{
							this->error("Could not dynamically declare abnormality constant \"" + unlessConstLike->fullName() + "\", it appears to be a bad constant.", true);
							unlessCreationFailed = true;
						}
					}
					else
					{	// Successful add, translate the new constant.
						this->translateConstantDecl(unlessConst);
						unlessConstLike->constRef = unlessConst;
						// Also, if it was an sdFluent, add "default -ab" as a law.
						if(unlessConst->constType == Constant::CONST_SDFLUENT)
						{
							SimpleUnaryOperator* tempNotUnless = new SimpleUnaryOperator();
							tempNotUnless->opType = SimpleUnaryOperator::UOP_NOT;
							tempNotUnless->postOp = unlessConstLike;
							this->translateCausalLaw(tempNotUnless, tempNotUnless, NULL, NULL, NULL, NULL, NULL);
							// Carefully deallocate tempNotUnless.
							tempNotUnless->postOp = NULL;
							delete tempNotUnless;
						}
					}
				}
			}
			// Create the "-unlessBody" part to merge with 
			tempUOP = new SimpleUnaryOperator();
			tempUOP->opType = SimpleUnaryOperator::UOP_NOT;
			tempUOP->postOp = unlessConstLike;
		}
	}
	
	// Finish translating this causal law even if something went wrong above.
	// If something went wrong, the law might translate funny, but at least they'll have something to look at.
	if(afterBody == NULL && unlessBody == NULL)
	{	// They're both NULL, pass NULL through.
		this->translateCausalLaw(head, ifBody, assumingBody, NULL, whenBody, followingBody, whereBody);
	}
	else if(afterBody == NULL)
	{	// Only unlessBody exists, just pass it along.
		this->translateCausalLaw(head, ifBody, assumingBody, tempUOP, whenBody, followingBody, whereBody);
	}
	else if(unlessBody == NULL)
	{	// unlessBody was NULL, just pass the rest along.
		this->translateCausalLaw(head, ifBody, assumingBody, afterBody, whenBody, followingBody, whereBody);
	}
	else
	{	// They both exist, merge them and pass that along.
		afterBody->setParens(true);
		tempPE = (SimpleBinaryOperator*)Translator::mergeSubFormulas(afterBody, tempUOP);
		this->translateCausalLaw(head, ifBody, assumingBody, tempPE, whenBody, followingBody, whereBody);
	}
	
	if(unlessBody)
	{
		// Carefully deallocate the temporary "not unlessBody" construct,
		// avoiding deallocating the original unlessBody.
		// Do this first to avoid cascading deallocation from possible tempPE.
		tempUOP->postOp = NULL;
		delete tempUOP;
	}
	if(tempPE)
	{
		// Now (carefully) deallocate the temporary ParseElement.
		// Don't deallocate preOp or postOp, they get deallocated elsewhere.
		tempPE->preOp = NULL;
		tempPE->postOp = NULL;
		delete tempPE;
	}
	if(unlessConstLike)
	{	// Carefully deallocate unlessConstLike.
		unlessConstLike->params.clear();
		delete unlessConstLike;
	}
}

// Handles a ':- show' declaration, adding the corresponding #show statements to the translation footer.
void Translator::handleShowStmt(std::vector<ParseElement*> atomicFormulas) {
	StmtList stmts;
	Context localContext;
	std::ostringstream tmp;

	// By default, user defined atoms are shown in the answer set.
	// The presence of a show statement overrides this and makes them all
	// default to hidden.
	if (!blnEncounteredShowStmt) {
		blnEncounteredShowStmt = true;
		stmts.push_back(Statement("#hide.", Context::BASE));
	}


	// Iterate through each element and add the appropriate show statements.
	for (std::vector<ParseElement*>::const_iterator it = atomicFormulas.begin(); it != atomicFormulas.end(); it++) {

		// Sanity check: Non-null parse elements.
		if (!(*it)) continue;

		if ((*it)->getType() == ParseElement::PELEM_CONSTLIKE) {
			// It's a bare constant. Take this to be a shortcut for 'c=v' where V is a variable ranging of the constant's domain
			ConstantLikeElement* constlike = ((ConstantLikeElement*)(*it));
			if (constlike->constRef
					&& constlike->constRef->domain
					&& constlike->constRef->domain->sortVar)
			{
				std::string tmpname = constlike->constRef->domain->sortVar->fullTransName();
				localContext = Context(Context::POS_BODY, Context::BASE, Context::ANON_STR, tmpname);
				tmp << "#show ";
				(*it)->translate(tmp, localContext);
				tmp << ".";

				stmts.push_back(Statement(tmp.str(), Context::BASE));

			} else {
				// This appears to be missing one or more references...
				// Just try a normal translation and hope for the best.
				localContext = Context(Context::POS_BODY, Context::BASE, Context::ANON_STR);
				tmp << "#show ";
				(*it)->translate(tmp, localContext);
				tmp << ".";
				stmts.push_back(Statement(tmp.str(), Context::BASE));
			}
			tmp.str("");
		} else {
			// It's must be 'c=v'. We can translate this without any further ado
			localContext = Context(Context::POS_BODY, Context::BASE, Context::ANON_STR);
			tmp << "#show ";
			(*it)->translate(tmp, localContext);
			tmp << ".";
			stmts.push_back(Statement(tmp.str(), Context::BASE));
		}
	}

	// Add the statements to the footer.
	addToFooter(stmts);
}


/* Class instance methods for general setup, etc. */

// Creates and adds a new sort to the translator's data structures without translating or outputting it.
Sort* Translator::createInternalSort(const char *newSortName, std::list<Sort*> subsorts)
{
	Sort* retVal = NULL;
	if(newSortName)
	{
		bool alreadyDeclared = true;
		std::string newSortStr = newSortName;
		// Add the sort if it isn't already in the symbol table.
		retVal = this->getSort(newSortStr);
		if(retVal == NULL)
		{
			alreadyDeclared = false;
			retVal = new Sort(newSortStr, Translator::sanitizeSortName(newSortStr));
			int addSymResult = this->addSort(retVal);
			if(addSymResult != SymbolTable::ADDSYM_OK)
			{
				if(addSymResult == SymbolTable::ADDSYM_DUP)
				{	// Just grab the already-declared sort.
					delete retVal;
					retVal = NULL;
					retVal = this->getSort(newSortStr);
					alreadyDeclared = true;
				}
				else
				{	// An error happened, null out the return value.
					delete retVal;
					retVal = NULL;
				}
			}
			else
			{
				// Try to create (or get) a default variable for the sort, connect the two if nothing goes wrong.
				std::string tempName = retVal->fullName();
				std::string tempTransName = retVal->fullTransName();
				std::string tempVarName = Translator::sortNameToVariable(tempName);
				Variable* tempVar = mainTrans.getVariable(tempVarName);
				if(tempVar == NULL)
				{
					std::string tempTransVarName = Translator::sortNameToVariable(tempTransName);
					tempVar = new Variable(tempVarName, tempTransVarName);
					if(mainTrans.addVariable(tempVar) != SymbolTable::ADDSYM_OK)
					{
						delete tempVar;
						tempVar = NULL;
						retVal = NULL; // Won't affect the translator's storage of the (incomplete) sort.
					}
					else
					{
						tempVar->sortRef = retVal;
					}
				}
				if(tempVar)
				{
					retVal->sortVar = tempVar;
				}
			}
		}
		// Add subsorts to the sort's list.
		if(retVal && !subsorts.empty())
		{
			for(std::list<Sort*>::iterator lIter = subsorts.begin(); lIter != subsorts.end(); ++lIter)
			{
				if((*lIter))
				{
					retVal->subsorts.push_back(*lIter);
				}
			}
		}
		// If the sort is new and is a "something*" sort, make sure its child ("something")
		// is declared too, and link them together.
		if(!alreadyDeclared && newSortStr.length() > 0 && newSortStr[newSortStr.length()-1] == '*')
		{
			// Now find/create the child "something" sort.
			std::string nonStarIdent;
			nonStarIdent = newSortStr.substr(0, newSortStr.length()-1);
			
			// Check if the child already exists before proceeding with declaration etc.
			Sort *nonStarSort = mainTrans.getSort(nonStarIdent);
			if(nonStarSort == NULL)
			{	// Declare "something" so it can be added as the child of "something*".
				std::list<Sort*> nonStarSubsorts; // Empty on purpose.
				nonStarSort = this->createInternalSort(nonStarIdent.c_str(), nonStarSubsorts);
			}
			if(nonStarSort)
			{
				// Add "something" to subsorts.
				retVal->subsorts.push_back(nonStarSort);
			}
			
			// Create an object "none" and associate it with the "something*" sort.
			std::string noneName = "none";
			Object* noneObj = new Object(noneName, Translator::sanitizeObjectName(noneName));
			int noneAddResult = mainTrans.addObject(noneObj);
			if(noneAddResult == SymbolTable::ADDSYM_OK)
			{
				retVal->domainObjs.push_back(noneObj);
			}
		}
	}
	return retVal;
}

// Creates and adds a new object to the translator's data structures without translating or outputting it.
Object* Translator::createInternalObject(const char *newObjName, std::list<Sort*> params, Sort* ofSort)
{
	Object* retVal = NULL;
	if(newObjName && ofSort)
	{
		std::string newObjStr = newObjName;
		retVal = new Object(newObjStr, Translator::sanitizeObjectName(newObjStr));
		for(std::list<Sort*>::iterator lIter = params.begin(); lIter != params.end(); ++lIter)
		{
			if((*lIter))
			{
				retVal->params.push_back(*lIter);
			}
		}
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
			ofSort->domainObjs.push_back(retVal);
		}
	}
	return retVal;
}

// Creates and adds a new number range (child of Object) to the translator's data structures without translating or outputting it.
NumberRange* Translator::createInternalNumRange(const char *newObjName, const char *newMin, const char *newMax, Sort* ofSort)
{
	NumberRange* retVal = NULL;
	if(newObjName && newMin && newMax && ofSort)
	{
		std::string newObjStr = newObjName;
		retVal = new NumberRange();
		retVal->name = newObjStr;
		retVal->transName = Translator::sanitizeObjectName(newObjStr);
		retVal->min = newMin;
		retVal->max = newMax;
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
			ofSort->domainObjs.push_back(retVal);
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
		staticTimeStamp = getSort("step")->sortVar->transName;
		dynamicTimeStamp = getSort("astep")->sortVar->transName;
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
std::ostream& Translator::bindAndTranslate(std::ostream& out, ParseElement* expr, Context& context, bool upwardMobileClauses) {

	if (!expr) return out;

	ClauseList localClauses, localVariables;
	Context localContext = context.mkBindClauses(&localClauses).mkBindVars(&localVariables);
	std::ostringstream tmp;

	expr->translate(tmp, localContext);

	// Existential quantification (if needed).
	if (!localVariables.empty()) {
		out << "?[";

		for (std::list<std::string>::const_iterator it = localVariables.begin(); it != localVariables.end(); ) {
				out << *it;
				if (++it != localVariables.end()) out << ", ";
		}
		out << "]:";
	}

	if (!localVariables.empty()
			|| (upwardMobileClauses && !localClauses.empty()))
	{
		out << "(";
	}

	out << tmp.str();

	if (!localVariables.empty()
			|| (upwardMobileClauses && !localClauses.empty()))
	{
		Translator::outputClauses(out, localClauses, true);
		out << ")";
	} else {
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

bool Translator::setIncrementalPart(Context::IPart newIncPart) {
	if (!ostOutPtr) return false;
	if (newIncPart == mCurrentPart) return true;

	if (!blnStaticTrans) {
		switch (newIncPart) {
		case Context::BASE:
			output("#base.",true);
			break;
		case Context::CUMULATIVE:
			output("#cumulative " + dynamicTimeStamp + ".",true);
			break;
		case Context::VOLATILE:
			output("#volatile " + dynamicTimeStamp + ".",true);
			break;
		case Context::NONE:
			return true;
		default:
			return false;
		}
	}

	mCurrentPart = newIncPart;
	return true;

}

void Translator::output(std::string const& str, Context::IPart ipart, bool endWithNewline) {
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
