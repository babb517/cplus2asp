#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <list>
#include <string>
#include <vector>

class Element;

/**
 * Representation of a node for use in a symbol table. Essentially a container
 * class for storing data.
 */
class SymbolNode
{
public:
	/// The possible types of recognized symbols.
	enum SymbolType { SYM_UNKNOWN, SYM_CONST, SYM_OBJ, SYM_SORT, SYM_VAR };
	enum SymbolType symbolType; ///< The type of a particular symbol.
	std::string name; ///< The base name of a symbol.
	std::vector<std::string> paramNames; ///< The base names of each parameter of a symbol (if any).
	Element* symbolElement; ///< A pointer to a symbol's corresponding Element (or subclass) object, if any.
	
	/**
	 * Default constructor. Initializes attributes to 0, NULL, empty, or equivalent.
	 */
	SymbolNode();
	
	/**
	 * Destructor. No dynamic memory is allocated for SymbolNode objects, 
	 * so this is just here for completeness's sake.
	 */
	virtual ~SymbolNode();
};

/**
 * Uses encapsulated data structures of SymbolNode objects to create a symbol
 * table. Provides methods to add/remove symbols to/from the symbol table
 * and check for existence of symbols.
 */
class SymbolTable
{
private:
	std::list<SymbolNode*> symbolList; ///< Data structure to hold defined symbols.
	/**
	 * An internal version of findSymbol that returns an iterator instead of a pointer to the symbol (if it's found).
	 * @param symName - The base name of the symbol.
	 * @param symParams - Parameters of the symbol, if any.
	 * @param symType - The type of the symbol.
	 * @return An iterator at the found symbol's position, or the end of the list if the symbol was not found.
	 */
	std::list<SymbolNode*>::iterator findSymbolIter(std::string& symName, std::vector<std::string>& symParams, SymbolNode::SymbolType symType);
public:
	/**
	 * Default Constructor. Nothing to initialize/allocate, just here
	 * for completeness's sake.
	 */
	SymbolTable();
	
	/**
	 * Empties the internal symbol data structure, deallocating all memory
	 * associated with the symbols.
	 */
	void clearTable();
	
	/**
	 * Enum of the possible return values for methods that manipulate the symbol table:
	 * ADDSYM_OK - Everything went fine, symbol added.
	 * ADDSYM_DUP - Symbol not added, it was already defined.
	 * ADDSYM_BAD - Symbol not added, it was a bad symbol definition.
	 * ADDSYM_ERR - An error occurred while adding the symbol.
	 * DELSYM_OK - No errors, symbol removed from table.
	 * DELSYM_DNE - Symbol did not exist in the table, nothing to remove.
	 * DELSYM_ERR - An error occurred while removing the symbol.
	 */
	enum SymTblResult { ADDSYM_OK = 0, DELSYM_OK = 0, ADDSYM_DUP, ADDSYM_BAD, ADDSYM_ERR, DELSYM_DNE, DELSYM_ERR };
	
	/**
	 * Attempts to add a new symbol to the symbol table.
	 * @param symName - The base name of the symbol.
	 * @param symParams - Parameters of the symbol, if any.
	 * @param symType - The type of the symbol.
	 * @return A value from SymTblResult indicating the success/failure of the operation.
	 */
	int addSymbol(std::string& symName, std::vector<std::string>& symParams, SymbolNode::SymbolType symType);
	
	/**
	 * Attempts to remove a defined symbol from the symbol table.
	 * @param symName - The base name of the symbol.
	 * @param symParams - Parameters of the symbol, if any.
	 * @param symType - The type of the symbol.
	 * @return A value from SymTblResult indicating the success/failure of the operation.
	 */
	int delSymbol(std::string& symName, std::vector<std::string>& symParams, SymbolNode::SymbolType symType);
	
	/**
	 * Finds the requested symbol's SymbolNode object in the symbol table if
	 * the symbol has been defined.
	 * @param symName - The base name of the symbol.
	 * @param symParams - Parameters of the symbol, if any.
	 * @param symType - The type of the symbol.
	 * @return A pointer to the symbol's SymbolNode object, or NULL if the symbol isn't in the table.
	 */
	SymbolNode* findSymbol(std::string& symName, std::vector<std::string>& symParams, SymbolNode::SymbolType symType);
	
	/**
	 * Grabs the last symbol added to the table (if any have been added).
	 * @return A pointer to the last symbol in added to the table, or NULL if
	 * the table is empty or "last symbol" has no meaning in context.
	 */
	SymbolNode* getLastSymbol();
	
	/**
	 * Destructor. Deallocates and clears out the internal symbol data structure.
	 */
	virtual ~SymbolTable();
};

#endif // SYMBOLTABLE_H
