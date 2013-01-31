#ifndef ELEMENTCOUNTER_H
#define ELEMENTCOUNTER_H

#include <vector>

class Element;

/**
 * Wraps a list of Element objects together with an occurrence counter
 * to facilitate elimination of duplicate entries and names during translation.
 * The index of each element starts at 0, and duplicate elements get increasing
 * incdices.
 */
class ElementCounter
{
private:
	/// Linear container for Element pointers.
	std::vector<Element*> elements;
	/// Corresponding counters for given Elements. Unique elements start at 0, subsequent duplicates get incremented counts.
	std::vector<int> counts;
public:
	/**
	 * Default constructor.
	 */
	ElementCounter();
	
	/**
	 * Enhanced wrapper for container's clear.
	 * Clears all internal data structures of their contents.
	 */
	void clear();
	
	/**
	 * Enhanced wrapper for container's pop_back.
	 * Pops both containers' back items.
	 */
	void pop_back();
	
	/**
	 * Enhanced wrapper for container's push_back.
	 * Adds the element, and creates an appropriate count for it.
	 * @param elem - The element to add.
	 */
	void push_back(Element* elem);
	
	/**
	 * Wrapper for container's size.
	 * @return The number of elements in the internal list.
	 */
	size_t size();
	
	/**
	 * Retrieves the element at the specified index.
	 * @param index - The (0-based) index of the desired element.
	 * @return A pointer to the element at index in the internal list, or NULL if index is invalid.
	 */
	Element* elementAt(size_t index);
	
	/**
	 * Retrieves the occurrence counter for the element at the specified index.
	 * @param index - The (0-based) index of the desired element.
	 * @return The value of the element at index's occurrence counter, or -1 if index is invalid.
	 */
	int countAt(size_t index);
	
	/**
	 * Retrieves the element at the back of elements.
	 * @return A pointer to the back Element of elements, or NULL if elements is empty.
	 */
	Element* elementsBack();
	
	/**
	 * Retrieves the count at the back of counts.
	 * @return The occurrence counter at the back of counts, or -1 if counts is empty.
	 */
	int countsBack();
	
	/**
	 * Wraps the elements list's begin function.
	 * @return A constant iterator at the begnning of elements.
	 */
	std::vector<Element*>::iterator elementsBegin();
	
	/**
	 * Wraps the elements list's end function.
	 * @return A constant iterator at the end of elements.
	 */
	std::vector<Element*>::iterator elementsEnd();
	
	/**
	 * Wraps the counts list's begin function.
	 * @return A constant iterator at the begnning of counts.
	 */
	std::vector<int>::iterator countsBegin();
	
	/**
	 * Wraps the counts list's end function.
	 * @return A constant iterator at the end of counts.
	 */
	std::vector<int>::iterator countsEnd();
	
	/**
	 * Destructor.
	 */
	virtual ~ElementCounter();
};

#endif // ELEMENTCOUNTER_H
