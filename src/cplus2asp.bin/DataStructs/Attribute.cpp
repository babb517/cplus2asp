#include <string>

#include "Attribute.h"

// Standard toString function.
std::string Attribute::toString() const {
	// Start with Constant info, then add on Attribute-specific stuff.
	std::string tempStr = Constant::toString();
	tempStr += "\n    [Attribute]";
	tempStr += "\n    parent = ";
	// If we don't have connected action yet, just say NULL.
	if(parent() == NULL)
	{
		tempStr += "NULL";
	}
	else
	{
		tempStr += "\"";
		tempStr += parent()->fullName();
		tempStr += "\"";
	}
	return tempStr;
}
