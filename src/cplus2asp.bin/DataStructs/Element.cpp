#include "Element.h"

// Full constructor.
Element::Element(std::string const& baseName, std::string const& baseTransName, ElementType type)
{
	mBaseName = baseName;
	mBaseTransName = baseTransName;
	mElemType = type;
}

// Destructor.
Element::~Element()
{
	// Intentionally empty.
}
