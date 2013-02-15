#include <vector>

#include "Element.h"

#include "ElementCounter.h"

/// Adds an element to the list, incrementing the cardinality and returning the results.
size_t ElementCounter::add(Element const* elem) {
	bool in = (bool)mElemCount.count(elem);
	size_t count;

	if (!in) {
		count = 1;
		mElemCount[elem] = 1;
	} else {
		count = ++mElemCount[elem];
	}
	return count;
}
