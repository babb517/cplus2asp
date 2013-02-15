#include <list>
#include <string>
#include <vector>

#include "Element.h"

#include "SymbolTable.h"

/* SymbolNode methods */

// Default constructor for SymbolNode objects, initializes everything to 0 (or equivalent).
SymbolNode::SymbolNode()
{
	symbolType = SYM_UNKNOWN;
	name = "";
	symbolElement = NULL;
}

// SymbolNode destructor. No dynamic memory to deallocate, here for completeness's sake.
SymbolNode::~SymbolNode()
{
	// Intentionally empty.
}

/* SymbolTable methods */

// Default constructor for SymbolTable, does nothing.
SymbolTable::SymbolTable()
{
	// Intentionally empty.
}

// Empties out the internal symbol data structure and deallocates the symbols' memory.
void SymbolTable::clearTable()
{
	std::list<SymbolNode*>::iterator sIter = symbolList.begin();
	while(sIter != symbolList.end())
	{
		delete *sIter;
		++sIter;
	}
	symbolList.clear();
}

// Attempts to add a new symbol to the symbol table.
int SymbolTable::addSymbol(std::string const& symName, std::vector<std::string> const* symParams, SymbolNode::SymbolType symType)
{
	int retVal = ADDSYM_ERR; // Start pessimistic.

	size_t numParams = (symParams) ? symParams->size() : 0;

	if(findSymbol(symName, symParams, symType) == NULL)
	{
		if(symName != "")
		{
			for(size_t i = 0; i < numParams; i++)
			{	// Check that none of the parameters have bad names.
				if(symParams->at(i) == "")
				{
					retVal = ADDSYM_BAD;
					break;
				}
			}
			if(retVal != ADDSYM_BAD)
			{	// Nothing's bad about the symbol, add it.
				SymbolNode *tempNode = new SymbolNode;
				tempNode->name = symName;
				if (symParams) tempNode->paramNames = *symParams;
				tempNode->symbolType = symType;
				symbolList.push_back(tempNode);
				retVal = ADDSYM_OK;
			}
		}
		else
		{	// Bad symbol name.
			retVal = ADDSYM_BAD;
		}
	}
	else
	{	// The symbol already exists, let the caller know.
		retVal = ADDSYM_DUP;
	}
	return retVal;
}

// Attempts to remove a defined symbol from the symbol table.
int SymbolTable::delSymbol(std::string const& symName, NameList const* symParams, SymbolNode::SymbolType symType)
{
	int retVal = DELSYM_ERR; // Start pessimistic.
	std::list<SymbolNode*>::iterator sIter = findSymbolIter(symName, symParams, symType);
	if(sIter != symbolList.end())
	{
		delete *sIter;
		symbolList.erase(sIter);
		retVal = DELSYM_OK;
	}
	else
	{	// The symbol wasn't there in the first place.
		retVal = DELSYM_DNE;
	}
	return retVal;
}

// Finds the requested symbol's SymbolNode object in the symbol table if the symbol has been defined.
SymbolNode* SymbolTable::findSymbol(std::string const& symName, NameList const* symParams, SymbolNode::SymbolType symType)
{
	SymbolNode* retVal = NULL; // Start pessimistic.
	std::list<SymbolNode*>::iterator sIter = findSymbolIter(symName, symParams, symType);
	if(sIter != symbolList.end())
	{
		retVal = *sIter;
	}
	return retVal;
}

// Grabs the last symbol added to the table and returns it (if any have been added).
SymbolNode* SymbolTable::getLastSymbol()
{
	SymbolNode* retVal = NULL; // Start pessimistic.
	if(!symbolList.empty())
	{
		retVal = symbolList.back();
	}
	return retVal;
}

// Internal version of findSymbol that returns an iterator instead of a pointer to the symbol (if it's found).
std::list<SymbolNode*>::iterator SymbolTable::findSymbolIter(std::string const& symName, NameList const* symParams, SymbolNode::SymbolType symType)
{
	size_t paramSize;

	if (symParams) paramSize = symParams->size();
	else paramSize = 0;

	std::list<SymbolNode*>::iterator sIter;

	for(sIter = symbolList.begin(); sIter != symbolList.end(); sIter++) {
		if((*sIter)->name == symName
				&& (*sIter)->symbolType == symType
				&& (*sIter)->paramNames.size() == paramSize)
		{
			// Name, type, & # of params match, check the parameter names.
			for(size_t i = 0; i < (*sIter)->paramNames.size() && i < (*sIter)->paramNames.size(); i++)
			{
				if((*sIter)->paramNames[i] == symParams->at(i))
				{	// One of the parameter names didn't match.
					break;
				}
			}
		}
	}
	return sIter;
}

// SymbolTable destructor. Deallocates and clears out the internal symbol data structure.
SymbolTable::~SymbolTable()
{
	clearTable();
}

