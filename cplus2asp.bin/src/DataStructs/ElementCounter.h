#ifndef ELEMENTCOUNTER_H
#define ELEMENTCOUNTER_H

#include <map>

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
	/// Mapping between elements and counts.
	std::map<Element const*, size_t> mElemCount;
public:
	/**
	 * Default constructor.
	 */
	inline ElementCounter() { /* Intentionally Left Blank */ }
	
	/**
	 * Clears all counts.
	 */
	inline void clear()												{ mElemCount.clear(); }
	
	/**
	 * Adds an element to the counter and returns the running count.
	 * @param elem The element to add.
	 * @return The number of times this element has been added.
	 */
	size_t add(Element const* elem);
	
	/**
	 * Gets the number of times the element has been added to counter.
	 * @param elem The element to get the cardinality of.
	 * @return The cardinality of the element.
	 */
	inline size_t getCount(Element const* elem) const				{ return mElemCount.count(elem); }
	
	/**
	 * Wraps the elements list's begin function.
	 * @return A constant iterator at the begnning of elements.
	 */
	std::map<Element const*,size_t>::const_iterator begin() const 	{ return mElemCount.begin(); }
	
	/**
	 * Wraps the elements list's end function.
	 * @return A constant iterator at the end of elements.
	 */
	std::map<Element const*,size_t>::const_iterator end() const { return mElemCount.end(); }
	
	
	/**
	 * Destructor.
	 */
	inline virtual ~ElementCounter() { /* Intentionally Left Blank */ }
};

#endif // ELEMENTCOUNTER_H
