#include <string>

#include "Translator.h"
#include "datastruct_externs.h"
#include "Sort.h"
#include "Variable.h"


// Full constructor.
Variable::Variable(std::string const& name, Sort const* sort)
	: Element(name, Translator::sanitizeVariableName(name), Element::ELEM_VAR)
{
	mSortRef = sort;
}

// Standard toString function.
std::string Variable::toString() const
{
	std::string tempStr;
	tempStr += "[Variable]";
	tempStr += "\n  sortRef = ";
	// If we don't have a sortRef yet, just say NULL.
	if(mSortRef == NULL)
	{
		tempStr += "NULL";
	}
	else
	{
		tempStr += "\"";
		tempStr += mSortRef->fullName();
		tempStr += "\"";
	}
	return tempStr;
}
