#include <list>
#include <string>

#include "parser_types.h"

#include "Query.h"

// Default constructor.
Query::Query()
{
	label = "";
	maxstep = "";
}

// Destructor.
Query::~Query()
{
	for(std::list<ParseElement*>::iterator lIter = queryConditions.begin(); lIter != queryConditions.end(); ++lIter)
	{
		if((*lIter) != NULL)
		{
			delete *lIter;
		}
	}
	queryConditions.clear();
}
