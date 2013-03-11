#include <string>
#include <vector>

#include "Translator.h"
#include "Element.h"
#include "Object.h"
#include "Variable.h"
#include "utilities.h"

#include "Sort.h"


std::string const Sort::VAR_NULL_NAME = "NULL_VAR";


// Full constructor.
Sort::Sort(std::string name, Variable* sortVar)
	: Element(name, Translator::sanitizeSortName(name), ELEM_SORT)
{
	mSortVar = sortVar;
	mSortVar->setDomain(this);
	mIsNumeric = true;
	mIsStarred = false;
}

// Gets the name of the variable associated with this sort.
std::string const& Sort::varName() const	{
	return (var()) ? var()->fullName() : VAR_NULL_NAME;
}

// Gets the ASP safe name of the variable associated with this sort.
std::string const& Sort::varTransName() const	{
	return (var()) ? var()->fullTransName() : VAR_NULL_NAME;
}

// Standard toString function.
std::string Sort::toString() const
{
	// Start with the basic Element info, then add on Sort-specific stuff.
	std::string tempStr;
	tempStr += "[Sort]";
	tempStr += "\n  domainObjs = ";
	tempStr += utils::elementVectorToFullNameString<Object*>(mObjs, ", ", true);
	tempStr += "\n  subsorts = ";
	tempStr += utils::elementVectorToFullNameString<Sort*>(mSubsorts, ", ", true);
	tempStr += "\n  sortvar = \"";
	tempStr += mSortVar->fullName();
	tempStr += "\"";
	return tempStr;
}


bool Sort::addObject(Object* obj, bool checkDuplicate) {
	bool found = !checkDuplicate;



	if (checkDuplicate) {
		for (ObjectList::iterator it = mObjs.begin(); it != mObjs.end(); it++) {
				if (*it == obj) found = true;
		}
	}

	if (!found) {
		mObjs.push_back(obj);
		updateNumeric(obj->isNumeric());
		updateStarred(obj->isStarred());
	}

	return !found;
}

/// Adds a subsort to this sort
bool Sort::addSubsort(Sort* subsort, bool checkDuplicate) {
	bool found = !checkDuplicate;

	if (checkDuplicate) {
		for (SortList::iterator it = mSubsorts.begin(); it != mSubsorts.end(); it++) {
			if (*it == subsort) found = true;
		}
	}

	if (!found) {
		mSubsorts.push_back(subsort);
		updateNumeric(subsort->isNumeric());
		updateStarred(subsort->isStarred());
		subsort->registerSupersort(this);
	}

	return !found;
}

/// Updates the running numeric calculation and notifies supersorts with the results
void Sort::updateNumeric(bool numericComponent) {
	if (!mIsNumeric) return;
	mIsNumeric = mIsNumeric && numericComponent;
	if (!mIsNumeric) {
		// The numeric property has changed. Propagate the changes to the super sorts.
		for (SortList::iterator it = mSupersorts.begin(); it != mSupersorts.end(); it++) {
			(*it)->updateNumeric(false);
		}
	}
}

/// Updates the running starred calcuation and notifiers supersorts of the results.
void Sort::updateStarred(bool starredComponent) {
	if (mIsStarred) return;
	mIsStarred = mIsStarred || starredComponent;
	if (mIsStarred) {
		// The numeric property has changed. Propagate the changes to the super sorts.
		for (SortList::iterator it = mSupersorts.begin(); it != mSupersorts.end(); it++) {
			(*it)->updateStarred(true);
		}
	}
}

