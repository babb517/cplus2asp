#include "Element.h"

// Default constructor.
Element::Element()
{
	name = "";
	transName = "";
	elemType = ELEM_ELEM;
}

// Full constructor.
Element::Element(std::string _name, std::string _transName)
{
	name = _name;
	transName = _transName;
	elemType = ELEM_ELEM;
}

// Generates the original full name of this element.
std::string Element::fullName()
{
	std::string tempStr = name;
	return tempStr;
}

// Generates the translated full name of this element.
std::string Element::fullTransName()
{
	std::string tempStr = transName;
	return tempStr;
}

// Standard toString function.
std::string Element::toString()
{
	std::string tempStr = "";
	tempStr += "[Element]";
	tempStr += "\nname = \"";
	tempStr += name;
	tempStr += "\"\ntransName = \"";
	tempStr += transName;
	tempStr += "\"";
	return tempStr;
}

// Destructor.
Element::~Element()
{
	// Intentionally empty.
}
