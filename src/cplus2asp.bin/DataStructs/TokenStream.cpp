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
#include "DataStructs/Token.h"
#include "DataStructs/TokenStream.h"

// Constructor. Here for completeness's sake.
TokenStream::TokenStream()
{
	// Intentionally empty.
}

// Wrapper for tokenList.empty().
bool TokenStream::empty() const
{
	return tokenList.empty();
}

// Wrapper for tokenList.size().
bool TokenStream::size() const
{
	return tokenList.size();
}

// Wrapper for tokenList.front().
Token* TokenStream::front()
{
	return tokenList.front();
}

// Wrapper for tokenList.back().
Token* TokenStream::back()
{
	return tokenList.back();
}

// Wrapper for tokenList.begin().
std::list<Token*>::iterator TokenStream::begin()
{
	return tokenList.begin();
}

// Wrapper for tokenList.end().
std::list<Token*>::iterator TokenStream::end()
{
	return tokenList.end();
}

// Wrapper for tokenList.insert(...).
std::list<Token*>::iterator TokenStream::insert(std::list<Token*>::iterator iter, Token* tok)
{
	return tokenList.insert(iter, tok);
}
// Wrapper for tokenList.insert(...).
void TokenStream::insert(std::list<Token*>::iterator position, std::list<Token*>::iterator first, std::list<Token*>::iterator last)
{
	tokenList.insert(position, first, last);
}

// Enhanced wrapper for tokenList.erase(...) that performs deallocation.
std::list<Token*>::iterator TokenStream::erase(std::list<Token*>::iterator iter)
{
	delete *iter;
	return tokenList.erase(iter);
}

// Wrapper for tokenList.erase(...).
std::list<Token*>::iterator TokenStream::pop(std::list<Token*>::iterator iter)
{
	return tokenList.erase(iter);
}

// Enhanced wrapper for tokenList.clear().
void TokenStream::clear()
{
	std::list<Token*>::iterator tlIter = tokenList.begin();
	while(tlIter != tokenList.end())
	{
		delete *tlIter;
		tlIter++;
	}
	tokenList.clear();
}

// Wrapper for tokenList.push_front().
void TokenStream::push_front(Token* tok)
{
	tokenList.push_front(tok);
}

// Wrapper for tokenList.pop_front().
void TokenStream::pop_front()
{
	tokenList.pop_front();
}

// Wrapper for tokenList.push_back().
void TokenStream::push_back(Token* tok)
{
	tokenList.push_back(tok);
}

// Wrapper for tokenList.pop_back().
void TokenStream::pop_back()
{
	tokenList.pop_back();
}

// Destructor. Frees the memory for all allocated tokens in tokenList.
TokenStream::~TokenStream()
{
	std::list<Token*>::iterator tlIter = tokenList.begin();
	while(tlIter != tokenList.end())
	{
		delete *tlIter;
		tlIter++;
	}
	tokenList.clear();
}
