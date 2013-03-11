#include <list>

#include "Token.h"

#include "Macro.h"

// Default constructor.
Macro::Macro()
{
	// Nothing to do, intentionally empty.
}

// Returns a human-readable reconstruction of the original macro.
std::string Macro::stringValue()
{
	std::string retVal = "";
	for(std::list<Token*>::iterator lIter = pattern.begin(); lIter != pattern.end(); ++lIter)
	{
		if(*lIter != NULL)
		{
			retVal += (*lIter)->stringValue;
		}
	}
	retVal += " -> ";
	for(std::list<Token*>::iterator lIter = result.begin(); lIter != result.end(); ++lIter)
	{
		if(*lIter != NULL)
		{
			retVal += (*lIter)->stringValue;
		}
	}
	if(!where.empty())
	{
		retVal += " where ";
		for(std::list<Token*>::iterator lIter = where.begin(); lIter != where.end(); ++lIter)
		{
			if(*lIter != NULL)
			{
				retVal += (*lIter)->stringValue;
			}
		}
	}
	return retVal;
}

// Destructor.
Macro::~Macro()
{
	// Delete all Tokens in the lists.
	for(std::list<Token*>::iterator lIter = pattern.begin(); lIter != pattern.end(); ++lIter)
	{
		if(*lIter != NULL)
		{
			delete *lIter;
		}
	}
	pattern.clear();
	for(std::list<Token*>::iterator lIter = result.begin(); lIter != result.end(); ++lIter)
	{
		if(*lIter != NULL)
		{
			delete *lIter;
		}
	}
	result.clear();
	for(std::list<Token*>::iterator lIter = where.begin(); lIter != where.end(); ++lIter)
	{
		if(*lIter != NULL)
		{
			delete *lIter;
		}
	}
	where.clear();
}
