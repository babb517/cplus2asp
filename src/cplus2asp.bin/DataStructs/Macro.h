#ifndef MACRO_H
#define MACRO_H

#include <list>
class Token;

/**
 * A container class designed to store information about a macro definition, 
 */
class Macro
{
public:
	std::list<Token*> pattern; ///< The list of tokens that form the matching pattern for a macro.
	std::list<Token*> result; ///< What to put in pattern's place when it's matched with something.
	std::list<Token*> where; ///< The (optional) where clause of a macro, should be evaluated each time we're about to use the macro in an expansion.
	
	/**
	 * Default constructor. Initializes members to 0/blank/etc.
	 */
	Macro();
	
	/**
	 * Reconstructs a human-readable version of the original macro definition.
	 * @return A string consisting of "[pattern] -> [result]", with " where [where]" appended if the where token stream is not empty.
	 */
	std::string stringValue();
	
	/**
	 * Destructor. Deallocates all Tokens in each list and clears out the lists' contents.
	 */
	virtual ~Macro();
};

#endif
