#pragma once
#include <list>

#include <boost/utility.hpp>

#include "pointers.h"

/// Simple baseclass which stores a reference counter for the object and automatically deallocates it.
/// Inspired by OpenSceneGraph
class Referenced : public boost::noncopyable {

	template <typename T>
	friend class ref_ptr;

	template <typename T>
	friend class weak_ptr;

private:
	/***********************************************************/
	/* Private Members */
	/***********************************************************/

	/// A master-list of validity flags
	/// Note: Not threadsafe
	static std::list<bool> _validList;


	/// The validity flag for this reference
	bool* _valid;

	/// Reference count.
	mutable size_t _refs;

public:
	/***********************************************************/
	/* Constructors */
	/***********************************************************/
	inline Referenced()
		: _refs(0)
	{ 
		_validList.push_back(true);
		_valid = &_validList.back();
	}


protected:
	virtual ~Referenced();


private:
	/***********************************************************/
	/* Private Functions */
	/***********************************************************/

	inline size_t _ref() const { return ++_refs; }
	inline size_t _unref() const { return --_refs; }


};


