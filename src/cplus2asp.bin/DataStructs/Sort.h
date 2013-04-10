/* 
 * Copyright (c) 2010-2013 <Joseph Babb, Michael Cassollary, Joohyung Lee>
 *
 * For information on how to contact the authors, please visit
 *	http://reasoning.eas.asu.edu/cplus2asp
 *
 * This file is part of the cplus2asp system.
 *
 * cplus2asp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cplus2asp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef SORT_H
#define SORT_H

#include <string>
#include <vector>

#include "DataStructs/Element.h"
#include "DataStructs/Constant.h"
#include "DataStructs/Object.h"
#include "DataStructs/Sort.h"

#include "types.h"



/**
 * The Sort class defines a C+ sort (i.e., domain of objects used as arguments and values).
 * Each Sort is set up to be aware of its objects and any subsorts it has.
 */
class Sort : public Element
{
public:
	static std::string const VAR_NULL_NAME;		///< Concrete string to return in the event a variable is NULL.

private:
	ObjectList mObjs; 					///< Dynamic array to keep track of the objects specific to this sort.
	SortList mSubsorts; 				///< Dynamic array to track any subsorts of this sort.
	SortList mSupersorts;				///< A list of sorts which have registered this sort as a subsort.
	Variable* mSortVar; 				///< The default Variable associated with this sort.

	bool mIsNumeric;					///< Running calculation determining whether or not this sort is numeric.
	bool mIsStarred;					///< Running calculation determining if the value 'none' appears in the sort's domain.

public:
	
	/**
	 * Full constructor. Calls Element's full constructor, saves the given varName, and initializes the domainObjs and subsorts vectors.
	 * @param name - The C+ name of the sort.
	 * @param sortVar - The variable to use as the default internal variable for this sort. This variable will be automatically attached to the sort.
	 */
	Sort(std::string name, Variable* sortVar);

	inline virtual std::string const& fullName() const 				{ return baseName(); }
	inline virtual std::string const& fullTransName() const 		{ return baseTransName(); }
	virtual std::string toString() const;
	inline virtual bool isNumeric() const 							{ return mIsNumeric; }
	virtual bool isBoolean() const 									{ return isBooleanSort(); }
	virtual bool isStarred() const 									{ return mIsStarred; }

	/// Gets the variable associated with this sort.
	inline Variable const* var() const								{ return mSortVar; }

	/// Gets the name of the variable associated with this sort.
	std::string const& varName() const;

	/// Gets the ASP safe name of the variable associated with this sort.
	std::string const& varTransName() const;


	/**
	 * Examines its own name and determines if it is any of the special
	 * "internal" sorts for tracking action constants.
	 * @return True if it is an action sort, false otherwise.
	 */
	inline bool isActionSort() const 								{ return Constant::isActionType(getConstantType()); }
	
	/**
	 * Examines its own name and determines if it is any of the special
	 * "internal" sorts for tracking fluent constants.
	 * @return True if it is a fluent sort, false otherwise.
	 */
	inline bool isFluentSort() const 								{ return Constant::isFluentType(getConstantType()); }

	/**
	 * Examines its own name and determines if it's the special
	 * "internal" sort for tracking rigid constants.
	 * @return True if it is the rigid sort, false otherwise.
	 */
	inline bool isRigidSort() const 								{ return getConstantType() == Constant::CONST_RIGID; }


	/**
	 * Examines its own name and determines if it is the special internal
	 * sort used to track static abnormalities.
	 * @return True if it is the static abnormality sort.
	 */
	inline bool isStaticAbnormalitySort() const 					{ return Constant::constTypeToString(Constant::CONST_STATICAB) == baseName(); }

	/**
	 * Examines its own name and determines if it is the special internal
	 * sort used to track dynamic abnormalities.
	 * @return True if it is the dynamic abnormality sort.
	 */
	inline bool isDynamicAbnormalitySort() const 					{ return Constant::constTypeToString(Constant::CONST_DYNAMICAB) == baseName(); }

	/**
	 * Examines its own name and determines if it is the special sort used to
	 * denote boolean values.
	 * @return True if it is the special boolean sort.
	 */
	inline bool isBooleanSort() const 								{ return baseName() == "boolean"; }

	/**
	 * Examines its own name and determines if it is a special internal
	 * sort used to track a type of constant.
	 * @return True if it is a special internal constant sort.
	 */
	inline bool isConstantSort() const 								{ return getConstantType() != Constant::CONST_UNKNOWN; }

	/**
	 * Determines the type of constant that this sort tracks.
	 * Returns Constant::CONST_UNKNOWN if this sort isn't an internal sort
	 * used to track constants.
	 * @return The type of constant the sort tracks or CONST_UNKNOWN.
	 */
	inline Constant::ConstantType getConstantType() const 			{ return Constant::stringToConstType(baseName().c_str()); }
	
	/**
	 * Adds an object to the sort.
	 * @param obj The object to add.
	 * @param checkExistence whether we should check if the object has already been added or not prior to adding it.
	 * @return True if the object was added, false otherwise.
	 */
	bool addObject(Object* obj, bool checkDuplicate = false);

	/// Gets an iterator for the beginning of the objects list.
	/// Does not include objects in subsorts.
	inline ObjectList::const_iterator begin() const					{ return mObjs.begin(); }

	/// Gets an iterator for the end of the objects list.
	/// Does not include objects in subsorts.
	inline ObjectList::const_iterator end() const					{ return mObjs.end(); }
	/**
	 * Adds a subsort to the sort.
	 * @param subsort The subsort to add.
	 * @param checkDuplicate whether we should check if the subsort has already been added or not prior to adding it.
	 * @return True if the subsort was added, false if it was a duplicate.
	 */
	bool addSubsort(Sort* subsort, bool checkDuplicate = false);

	/// Determines the number of subsorts associated with this sort.
	inline size_t numSubsorts() const								{ return mSubsorts.size(); }


	/// Gets an iterate for the beginning of the subsort list.
	inline SortList::const_iterator beginSubsorts() const			{ return mSubsorts.begin(); }

	/// Gets an iterator for the end of the subsort list.
	inline SortList::const_iterator endSubsorts() const				{ return mSubsorts.end(); }

	/// Determines the number of supersorts associated with this sort.
	inline size_t numSupersorts() const								{ return mSupersorts.size(); }

	/// Gets an iterate for the beginning of the subsort list.
	inline SortList::const_iterator beginSupersorts() const			{ return mSupersorts.begin(); }

	/// Gets an iterator for the end of the subsort list.
	inline SortList::const_iterator endSupersorts() const			{ return mSupersorts.end(); }

	/**
	 * Destructor. Does nothing.
	 */
	inline virtual ~Sort() { /* Intentionally Left Blank */ }

protected:
	/**
	 * Internal helper used to update whether the sort is numeric or not and notify supersorts.
	 * @param numericComponent whether the newly added component is numeric.
	 */
	void updateNumeric(bool numericComponent);

	/**
	 * Internal helper used to update whether the sort is starred or not and notify supersorts.
	 * @param numericComponent whether the newly added component contains 'none'.
	 */
	void updateStarred(bool starredComponent);


	/**
	 * Helper method called by supersorts to register themselves as such to this sort.
	 * @param supersort The supersort registering itself.
	 */
	inline void registerSupersort(Sort* supersort)	{ mSupersorts.push_back(supersort); }


};

#endif // SORT_H
