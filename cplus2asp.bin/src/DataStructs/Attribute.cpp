#include <string>

#include "Attribute.h"

// Default constructor. Calls Constant constructor, sets constType and attributeOf appropriately.
Attribute::Attribute() : Constant()
{
	constType = CONST_ATTRIBUTE;
	attributeOf = NULL;
}

// Full constructor. Calls full Constant constructor, sets constType and attributeOf appropriately.
Attribute::Attribute(std::string _name, std::string _transName) : Constant(_name, _transName)
{
	constType = CONST_ATTRIBUTE;
	attributeOf = NULL;
}

// Generates the original full name of this element.
// Does not append the "of ..." part, so it can safely call Constant's
// (its parent's) fullName().
std::string Attribute::fullName()
{
	return Constant::fullName();
}

// Generates the translated full name of this element.
// Does not append the "of ..." part, so it can safely call Constant's
// (its parent's) fullTransName().
std::string Attribute::fullTransName()
{
	return Constant::fullTransName();
}

// Standard toString function.
std::string Attribute::toString()
{
	// Start with Constant info, then add on Attribute-specific stuff.
	std::string tempStr = Constant::toString();
	tempStr += "\n    [Attribute]";
	tempStr += "\n    attributeOf = ";
	// If we don't have connected action yet, just say NULL.
	if(attributeOf == NULL)
	{
		tempStr += "NULL";
	}
	else
	{
		tempStr += "\"";
		tempStr += attributeOf->fullName();
		tempStr += "\"";
	}
	return tempStr;
}

// Destructor. Nothing to deallocate, just sets attributeOf to NULL.
Attribute::~Attribute()
{
	attributeOf = NULL;
}
