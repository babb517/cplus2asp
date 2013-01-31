#include <vector>

#include "Element.h"

#include "ElementCounter.h"

// Default constructor. Empty.
ElementCounter::ElementCounter()
{
	// Intentionally empty.
}

// Enhanced wrapper for container's clear.
void ElementCounter::clear()
{
	elements.clear();
	counts.clear();
}

// Enhanced wrapper for container's pop_back.
void ElementCounter::pop_back()
{
	elements.pop_back();
	counts.pop_back();
}

// Enhanced wrapper for container's push_back.
void ElementCounter::push_back(Element* elem)
{
	if(elem != NULL)
	{
		int count = 0; // Start at 0, increment every time this element has already been seen.
		std::vector<Element*>::iterator eIter;
		std::vector<int>::iterator cIter;
		for(eIter = elements.begin(), cIter = counts.begin(); eIter != elements.end() && cIter != counts.end(); ++eIter, ++cIter)
		{
			if((*eIter)->fullName() == elem->fullName() && (*eIter)->elemType == elem->elemType)
			{
				count++;
			}
		}
		elements.push_back(elem);
		counts.push_back(count);
	}
}

// Wrapper for container's size.
size_t ElementCounter::size()
{
	return elements.size();
}

// Retrieves the element at the specified index.
Element* ElementCounter::elementAt(size_t index)
{
	Element* retVal = NULL;
	if(index < elements.size())
	{
		retVal = elements[index];
	}
	return retVal;
}

// Retrieves the occurrence counter for the element at the specified index.
int ElementCounter::countAt(size_t index)
{
	int retVal = -1;
	if(index < counts.size())
	{
		retVal = counts[index];
	}
	return retVal;
}

// Retrieves the element at the back of elements.
Element* ElementCounter::elementsBack()
{
	Element* retVal = NULL;
	if(!elements.empty())
	{
		retVal = elements.back();
	}
	return retVal;
}

// Retrieves the count at the back of counts.
int ElementCounter::countsBack()
{
	int retVal = -1;
	if(!counts.empty())
	{
		retVal = counts.back();
	}
	return retVal;
}

// Wraps the elements list's begin function.
std::vector<Element*>::iterator ElementCounter::elementsBegin()
{
	return elements.begin();
}

// Wraps the elements list's end function.
std::vector<Element*>::iterator ElementCounter::elementsEnd()
{
	return elements.end();
}

// Wraps the counts list's begin function.
std::vector<int>::iterator ElementCounter::countsBegin()
{
	return counts.begin();
}

// Wraps the counts list's end function.
std::vector<int>::iterator ElementCounter::countsEnd()
{
	return counts.end();
}

// Destructor. Clears list contents.
ElementCounter::~ElementCounter()
{
	this->clear();
}
