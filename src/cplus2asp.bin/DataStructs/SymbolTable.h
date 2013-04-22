/* 
 * Copyright (c) 2010-2013 <Joseph Babb, Michael Cassollary, Joohyung Lee>
 *
 * For information on how to contact the authors, please visit
 *	http://reasoning.eas.asu.edu/cplus2asp
 *
 * This file is part of the cplus2asp system.
 *
 * cplus2asp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cplus2asp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <list>
#include <string>
#include <vector>
#include <unordered_map>

#include "DataStructs/Element.h"
#include "utilities.h"

/**
 * Uses encapsulated data structures of SymbolNode objects to create a symbol
 * table. Provides methods to add/remove symbols to/from the symbol table
 * and check for existence of symbols.
 */
class SymbolTable
{
public:

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
	enum SymTblResult { 
		ADDSYM_OK = 0, 
		DELSYM_OK = 0, 
		ADDSYM_DUP, 
		ADDSYM_BAD, 
		ADDSYM_ERR, 
		DELSYM_DNE, 
		DELSYM_ERR 
	};

	typedef std::list<Element*>::iterator iterator;
	typedef std::list<Element*>::const_iterator const_iterator;


private:
	std::unordered_map<std::string, Element*> mTable;		///< Data structure to hold defined symbols.
	std::list<Element*> mList;								///< List of all constants

	std::list<Element*> mSubTables[Element::_ELEM_TYPE_COUNT];	//< Tables maintained for specific types.


public:
	/**
	 * Default Constructor. Nothing to initialize/allocate, just here
	 * for completeness's sake.
	 */
	inline SymbolTable() { /* Intentionally left blank */ }
	
	/**
	 * Empties the internal symbol data structure, deallocating all memory
	 * associated with the symbols.
	 */
	inline ~SymbolTable() { clearTable(); }

	/**
	 * Empties the internal symbol data structure, deallocating all memory
	 * associated with the symbols.
	 */
	void clearTable();
	
	
	/**
	 * Attempts to add a new symbol to the symbol table.
	 * @param elem - The element to attempt to add.
	 * @return A value from SymTblResult indicating the success/failure of the operation.
	 */
	SymTblResult addSymbol(Element* elem);

	/**
	 * Attempts to remove a defined symbol from the symbol table.
	 * Also frees memory associated with the symbol.
	 * @param name The base name of the symbol.
	 * @param arity The arity of the symbol.
	 */
	SymTblResult delSymbol(std::string const& name, size_t arity);
	
	/**
	 * Finds the requested symbol's SymbolNode object in the symbol table if
	 * the symbol has been defined.
	 * @param name The base name of the symbol.
	 * @param arity The arity of the symbol.
	 * @return The element (if found) or NULL otherwise.
	 */
	Element* findSymbol(std::string const& name, size_t arity);

	/// Gets an iterator to the beginning of all symbols.
	inline iterator begin() { return mList.begin(); }
	inline const_iterator begin() const { return mList.begin(); }
	/// Gets an iterator to the end of all symbols.
	inline iterator end() { return mList.end(); }
	inline const_iterator end() const { return mList.end(); }

	/// Gets an iterator the beginning of the specified symbol type.
	inline iterator begin(Element::ElementType type) { return mSubTables[type].begin(); }
	inline const_iterator begin(Element::ElementType type) const { return mSubTables[type].begin(); }
	/// Gets an iterator to the end of the specified symbol type.
	inline iterator end(Element::ElementType type) { return mSubTables[type].end(); }
	inline const_iterator end(Element::ElementType type) const { return mSubTables[type].end(); }


private:

	/// Generates the key corresponding to the provided name and arity
	inline std::string key(std::string const& name, size_t arity) {
		return name + std::string("/") + utils::to_string(arity);
	}

};


#endif // SYMBOLTABLE_H
