#ifndef TIMESTEPINFO_DOT_H
#define TIMESTEPINFO_DOT_H

#include <climits> // For INT_MIN
#include <cstdlib> // For exit()
#include <iostream>
#include <list>
#include <string>

#include "Config.h"
#include "Predicate.h"

/**
 * Holds information about the predicates that are true at a given time step.
 */
class TimeStepInfo 
{
public:
	/// Constructor.  Initializes timeStep to INT_MIN and predicates to NULL.
	TimeStepInfo();
	
	/// Destructor.  Frees predicates and everything in it if it was pointing to valid data.
	virtual ~TimeStepInfo();
	
	/** 
	 * Accessor for timeStep.
	 * @return The value of timeStep.
	 */
	int getTimeStep();

	/**
	 * Mutator for timeStep.
	 * @param newTimeStep - The new value for timeStep.
	 */
	void setTimeStep(int newTimeStep);
	
	/** 
	 * Adds a predicate to our list of predicates, creating a new Predicate object to hold the appropriate data.
	 * Automatically keeps the predicates sorted.
	 * @param newPredicate - The predicate object to add.
	 */
	void addPredicate(Predicate* newPredicate);
	
	/** 
	 * Retrieves a constant iterator to the beginning of the predicates list.
	 * Ensures predicates has been allocated.
	 * @return An iterator pointing at the beginning of the predicates list.
	 */
	std::list<Predicate*>::const_iterator getPredicatesBegin();
	
	/**
	 * Retrieves a constant iterator to the end of the predicates list.
	 * Ensures predicates has been allocated.
	 * @return An iterator pointing at the end of the predicates list.
	 */
	std::list<Predicate*>::const_iterator getPredicatesEnd();
	
	/**
	 * Outputs the contents of this timestep to one or more output streams.
	 * This is done in such a way that multiple streams could in fact be the same.
	 * @param config - The configuration options for the system.
	 * @param outStream - The stream to output to.
	 * @return The number of predicates output in this timestep.
	 */
	int outputTimeStep( Config const& config, std::ostream& outStream );

protected:
	int timeStep; ///< The time step this structure represents in the solution.
	std::list<Predicate*>* predicates; ///< The predicates that are true at this time step.
	
	/// Allocates memory for predicates if that hasn't already been done. Exits on allocation error.
	void allocatePredicates();
};

#endif // TIMESTEPINFO_DOT_H
