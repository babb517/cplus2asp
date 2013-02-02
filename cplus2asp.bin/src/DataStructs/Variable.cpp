#include <string>

#include "datastruct_externs.h"
#include "Sort.h"
#include "Variable.h"

// Default constructor.
Variable::Variable() : Element()
{
	elemType = ELEM_VAR;
	sortRef = NULL;
}

// Full constructor.
Variable::Variable(std::string const& _name, std::string const& _transName) : Element(_name, _transName)
{
	elemType = ELEM_VAR;
	sortRef = NULL;
}

// Standard toString function.
std::string Variable::toString()
{
	// Start with Element info, then add on Variable-specific stuff.
	std::string tempStr = Element::toString();
	tempStr += "\n  [Variable]";
	tempStr += "\n  sortRef = ";
	// If we don't have a sortRef yet, just say NULL.
	if(sortRef == NULL)
	{
		tempStr += "NULL";
	}
	else
	{
		tempStr += "\"";
		tempStr += sortRef->name;
		tempStr += "\"";
	}
	return tempStr;
}

// Destructor.
Variable::~Variable()
{
	sortRef = NULL;
}
