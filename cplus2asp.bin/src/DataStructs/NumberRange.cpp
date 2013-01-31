#include "NumberRange.h"

// Default constructor.
NumberRange::NumberRange() : Object()
{
	min = "";
	max = "";
	objType = OBJ_RANGE;
}

// Full constructor.
NumberRange::NumberRange(std::string _name, std::string _transName, std::string _min, std::string _max) : Object(_name, _transName)
{
	min = _min;
	max = _max;
	objType = OBJ_RANGE;
}

// Generates the original full name of this element.
// Not attempting to intelligently handle min & max, but the range's name 
// should be the range anyway, so we should be safe for now.
std::string NumberRange::fullName()
{
	std::string tempStr = name;
	return tempStr;
}

// Generates the translated full name of this element.
// Not attempting to intelligently handle min and max at this point, but
// the range's transName should contain a sanitized range for all but
// the silliest of cases, so we should be safe for now.
std::string NumberRange::fullTransName()
{
	std::string tempStr = transName;
	return tempStr;
}

// Standard toString function.
std::string NumberRange::toString()
{
	// Start with Object info, then add on NumberRange-specific stuff.
	std::string tempStr = Object::toString();
	tempStr += "\n    [NumberRange]";
	tempStr += "\n    min = ";
	tempStr += min;
	tempStr += "\n    max = ";
	tempStr += max;
	return tempStr;
}

// Destructor.
NumberRange::~NumberRange()
{
	// Intentionally empty.
}
