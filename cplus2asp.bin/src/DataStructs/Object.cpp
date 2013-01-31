#include <string>
#include <vector>

#include "datastruct_externs.h"

#include "Element.h"

#include "Sort.h"
#include "utilities.h"

#include "Object.h"

// Default constructor.
Object::Object() : Element()
{
	elemType = ELEM_OBJ;
	objType = OBJ_NAME;
	isLua = false;
}

// Full constructor.
Object::Object(std::string _name, std::string _transName, bool _isLua) : Element(_name, _transName)
{
	elemType = ELEM_OBJ;
	objType = OBJ_NAME;
	isLua = _isLua;
}

// Returns the full name (including parameters) of this object.
std::string Object::fullName()
{
	std::string tempStr = name;
	if(!params.empty())
	{
		tempStr += "(";
		tempStr += utils::elementVectorToFullNameString<Sort*>(params);
		tempStr += ")";
	}
	return tempStr;
}

// Returns the full translated name (including parameters) of this object.
std::string Object::fullTransName()
{
	std::string tempStr = transName;
	if(!params.empty())
	{
		tempStr += "(";
		tempStr += utils::elementVectorToFullTransNameString<Sort*>(params);
		tempStr += ")";
	}
	return tempStr;
}

// Standard toString function.
std::string Object::toString()
{
	std::string tempStr = "";
	tempStr += "  [Object]";
	tempStr += "\n  objType = ";
	// Print out the English version of the possible enum values of objType.
	if(objType == OBJ_NAME)
	{
		tempStr += "OBJ_NAME";
	}
	else if(objType == OBJ_RANGE)
	{
		tempStr += "OBJ_RANGE";
	}
	else
	{
		tempStr += "UNKNOWN";
	}
	// If this is a "normal" object with parameters, list them.
	if(objType == OBJ_NAME && !params.empty())
	{
		tempStr += "\n  params = (";
		tempStr += utils::elementVectorToFullNameString<Sort*>(params, ", ", true);
		tempStr += ")";
	}
	return tempStr;
}

// Destructor.
Object::~Object()
{
	// Intentionally empty.
}
