#pragma once
#include <string>
#include <list>
#include <vector>

#include <boost/filesystem.hpp>

#include "pointers.h"
#include "Referenced.h"

/// A base wrapper class for creating reference counted classes from non-reference counted ones.
template <typename T>
class ReferencedWrapper : public Referenced, public T
{
public:
	ReferencedWrapper();

	virtual ~ReferencedWrapper();


	ReferencedWrapper<T>& operator=(ReferencedWrapper<T> const& other);
	ReferencedWrapper<T>& operator=(T const& other);


};

template <typename T>
ReferencedWrapper<T>::ReferencedWrapper() {
	// Intentionally left blank
}


template <typename T>
ReferencedWrapper<T>::~ReferencedWrapper() {
	// Intentionally left blank
}

template <typename T>
ReferencedWrapper<T>& ReferencedWrapper<T>::operator=(ReferencedWrapper<T> const& other) {
	*((T*)(this)) = *((T const*)(&other));
	return *this;
}

template <typename T>
ReferencedWrapper<T>& ReferencedWrapper<T>::operator=(T const& other) {
	*((T*)(this)) = other;
	return *this;
}


/// Reference counted string
typedef ReferencedWrapper<std::string> ReferencedString;

/// Referenced counted path
typedef ReferencedWrapper<boost::filesystem::path> ReferencedPath;

