#include "TimeStepInfo.h"

#include <list>
#include "Predicate.h"

// Constructor.
TimeStepInfo::TimeStepInfo()
{
	timeStep = Predicate::UNKNOWN_TIME;
	predicates = NULL;
}

// Destructor.
TimeStepInfo::~TimeStepInfo()
{
	if(predicates != NULL)
	{
		for(std::list<Predicate*>::iterator lIter = predicates->begin(); lIter != predicates->end(); lIter++)
		{
			delete (*lIter);
		}
		delete predicates;
	}
}

// Accessor for timeStep.
int TimeStepInfo::getTimeStep()
{
	return timeStep;
}

// Mutator for timeStep.
void TimeStepInfo::setTimeStep(int newTimeStep)
{
	timeStep = newTimeStep;
}

// Adds a predicate to our list of predicates
void TimeStepInfo::addPredicate(Predicate* newPredicate)
{
	if(predicates == NULL) 
	{
		allocatePredicates();
	}

	// Insert the new predicate in the appropriate place.
	if(predicates->empty())
	{	// If we don't have predicates yet, make this the first.
		predicates->push_back(newPredicate);
	}
	else
	{	// If we already have predicates, find this new one's proper place and stick it there.
		std::list<Predicate*>::iterator lIter = predicates->begin();
		int compareResult = 0;
		while(lIter != predicates->end())
		{
			compareResult = (*lIter)->getName().compare(newPredicate->getName());
			if(compareResult < 0 || compareResult == 0)
			{
				// If the current element comes before the newcomer (or is the same as the newcomer), move on.
				++lIter;
			}
			else
			{
				// The current element should go after the newcomer, break and insert here.
				break;
			}
		}
		predicates->insert(lIter, newPredicate);
	}
}

// Returns a constant iterator to the beginning of the predicates list.
std::list<Predicate*>::const_iterator TimeStepInfo::getPredicatesBegin() 
{
	if(predicates == NULL)
	{
		allocatePredicates();
	}
	return predicates->begin();
}

// Returns a constant iterator to the end of the predicates list.
std::list<Predicate*>::const_iterator TimeStepInfo::getPredicatesEnd()
{
	if(predicates == NULL)
	{
		allocatePredicates();
	}
	return predicates->end();
}
	
// Allocates memory for predicates if that hasn't already been done. Exits on allocation error.
void TimeStepInfo::allocatePredicates()
{
	if(predicates == NULL)
	{
		predicates = new std::list<Predicate*>();
		if(predicates == NULL)
		{
			std::cout << "Error: Out of memory." << std::endl;
			exit(1);
		}
	}
}

int TimeStepInfo::outputTimeStep( Config const& config, std::ostream& outStream )
{
	bool hasActions = false;
	std::stringstream actionStream;

	bool hasStaticAbs  = false;
	std::stringstream staticAbStream;

	bool hasDynamicAbs = false;
	std::stringstream dynamicAbStream;

	int counter = 0;

	if (timeStep == Predicate::RIGID_TIME) {
		outStream << "\tRIGID CONSTANTS: ";
	} else if (timeStep == Predicate::UNKNOWN_TIME) {
		outStream << "\tMISC CONSTANTS: ";
	} else {
		// Output time step header and appropriate trailing whitespace.
		outStream << "\tSTEP " << timeStep << ": ";
	}

	// Output each predicate that was true at this time step.
	for (std::list<Predicate*>::const_iterator lIter = getPredicatesBegin(); lIter != getPredicatesEnd(); lIter++)
	{
		// just skip over XPreds and/or negative predicates if we aren't outputting them.
		if ((*lIter)->isXPred() && !config.showXPredicates) continue;
		if ((*lIter)->isNegative() && !config.showNegPredicates) continue;

		switch ((*lIter)->getType()) {

		case Predicate::T_STATIC_AB:
			if (config.separateAbnormalities) {
				staticAbStream
					<< ((config.onePredPerLine) ? "\n\t\t" : " ")
					<< (*lIter)->toPredicateString(config.predFormat) ;
				hasStaticAbs = true;
				counter++;
			} else {
				outStream
					<< ((config.onePredPerLine) ? "\n\t\t" : " ")
					<< (*lIter)->toPredicateString(config.predFormat) ;
				counter++;
			}
			break;

		case Predicate::T_RIGID:
		case Predicate::T_FLUENT:
			outStream
				<< ((config.onePredPerLine) ? "\n\t\t" : " ")
				<< (*lIter)->toPredicateString(config.predFormat) ;
			counter++;
			break;



		case Predicate::T_DYNAMIC_AB:
			if (config.separateAbnormalities && config.separateActions) {
				dynamicAbStream
					<< ((config.onePredPerLine) ? "\n\t\t" : " ")
					<< (*lIter)->toPredicateString(config.predFormat) ;
				counter++;
				hasDynamicAbs = true;
			} else if (config.separateActions) {
				actionStream
					<< ((config.onePredPerLine) ? "\n\t\t" : " ")
					<< (*lIter)->toPredicateString(config.predFormat) ;
				counter++;
				hasActions = true;
			} else {
				outStream
						<< ((config.onePredPerLine) ? "\n\t\t" : " ")
						<< (*lIter)->toPredicateString(config.predFormat) ;
				counter++;
			}
			break;

		case Predicate::T_CONTRIB:
			if (!config.showContribPredicates) break;
			/* no break */

		case Predicate::T_ACTION:
			if (config.separateActions) {
				actionStream
						<< ((config.onePredPerLine) ? "\n\t\t" : " ")
						<< (*lIter)->toPredicateString(config.predFormat) ;
				counter++;
				hasActions = true;
			} else {
				outStream
						<< ((config.onePredPerLine) ? "\n\t\t" : " ")
						<< (*lIter)->toPredicateString(config.predFormat) ;
				counter++;
			}
			break;


		case Predicate::T_UNKNOWN:
		default:
			if (config.showUnformattedPredicates) {
				outStream
					<< ((config.onePredPerLine) ? "\n\t\t" : " ")
					<< (*lIter)->toPredicateString(config.predFormat) ;
				counter++;
			}
			break;
		}
	}

	// make sure we output all the other sections

	if (hasStaticAbs) {
		outStream << "\n\n\tSTATIC ABNORMALITIES: ";
		outStream << staticAbStream.str();
	}

	if (hasActions) {
		outStream << "\n\n\tACTIONS: ";
		outStream << actionStream.str();
	}

	if (hasDynamicAbs) {
		outStream << "\n\n\tDYNAMIC ABNORMALITIES: ";
		outStream << dynamicAbStream.str();
	}

	outStream << std::endl;

	return counter;
}
