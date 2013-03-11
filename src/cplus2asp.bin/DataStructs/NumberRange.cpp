
#include "NumberRange.h"
#include "utilities.h"

NumberRange::NumberRange(std::string const& name)
			: Object(name, Object::OBJ_RANGE, NULL) {
	// Figure out the proper range based on the name.

	size_t pos;
	if ((pos = name.find("..")) != std::string::npos) {
		mMin = utils::trimWhitespace(name.substr(0, pos));
		mMax = utils::trimWhitespace(name.substr(pos+2));
	} else {
		// TODO: Throw a warning.
		mMin = "UNKNOWN";
		mMax = "UNKNOWN";
	}
}

// Standard toString function.
std::string NumberRange::toString() const
{
	// Start with Object info, then add on NumberRange-specific stuff.
	std::string tempStr = Object::toString();
	tempStr += "\n    [NumberRange]";
	tempStr += "\n    min = ";
	tempStr += min();
	tempStr += "\n    max = ";
	tempStr += max();
	return tempStr;
}
