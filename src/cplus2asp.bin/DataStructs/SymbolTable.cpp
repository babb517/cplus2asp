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


#include <list>
#include <string>
#include <vector>
#include <unordered_map>

#include "DataStructs/Element.h"
#include "DataStructs/SymbolTable.h"

// Empties the internal symbol data structure.
void SymbolTable::clearTable() {
	for (iterator it = begin(); it != end(); it++) delete *it;
	mTable.clear();
	mList.clear();
	for (int i = 0; i < (int)Element::_ELEM_TYPE_COUNT; i++)
		mSubTables[i].clear();

}
	
	
// Attempts to add a new symbol to the symbol table.
SymbolTable::SymTblResult SymbolTable::addSymbol(Element* elem) {
	if (findSymbol(elem->baseName(), elem->arity())) return ADDSYM_DUP;
	else {
		mTable[key(elem->baseName(), elem->arity())] = elem;
		mList.push_back(elem);
		mSubTables[elem->getElemType()].push_back(elem);
		return ADDSYM_OK;
	}
}
	

// Attempts to remove a defined symbol from the symbol table.
SymbolTable::SymTblResult SymbolTable::delSymbol(std::string const& name, size_t arity) {
	std::unordered_map<std::string, Element*>::iterator elem = mTable.find(key(name, arity));

	if (elem != mTable.end()) {
		// element found
		mSubTables[(elem->second)->getElemType()].remove(elem->second);
		mTable.erase(elem);
		mList.remove(elem->second);
		delete elem->second;
		return DELSYM_OK;
	} else return DELSYM_DNE;
}
	
// Finds the requested symbol's SymbolNode object in the symbol table.
Element* SymbolTable::findSymbol(std::string const& name, size_t arity) {
	std::unordered_map<std::string, Element*>::iterator elem = mTable.find(key(name, arity));
	if (elem == mTable.end()) return NULL;
	else return elem->second;
}


