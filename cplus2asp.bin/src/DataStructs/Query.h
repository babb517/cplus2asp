#ifndef QUERY_H
#define QUERY_H

#include <list>
#include <string>

#include "types.h"

class ParseElement;


/**
 * Container class that holds information and logic expressions representing a query.
 */
class Query
{
public:
	std::string label; ///< The numeric label used to refer to the query, expressed as a string for maximal flexibility.
	std::string maxstep; ///< A (positive) integer or integer range (e.g., "2..4") describing the maximum time step value(s) to use when trying to find solutions for the query.
	ParseElementList queryConditions; ///< A collection of the expressions that form the query.
	
	/**
	 * Default constructor. Initializes everything to blank/zero/etc.
	 */
	Query();
	
	/**
	 * Destructor. Deallocates the contents of queryContents and clears the list.
	 */
	virtual ~Query();
};

#endif // QUERY_H

