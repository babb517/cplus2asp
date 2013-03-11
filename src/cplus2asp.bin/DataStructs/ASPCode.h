#ifndef ASPCODE_H
#define ASPCODE_H

#include <string>
#include "Comment.h"

//#include "datastruct_externs.h"

/**
 * A child of Comment that has been tweaked to store raw ASP code to pass through
 * from input to output.
 */
class ASPCode : public Comment
{
public:
	/**
	 * Default constructor. Sets everything to blank or zero, forces isRealComment (from parent) to false.
	 */
	ASPCode();
	
	/**
	 * Assignment operator overload.
	 * Copies all data from rhs to the lhs code block.
	 * @param rhs - The ASPCode to grab the data from.
	 * @return A reference to the lhs code block.
	 */
	ASPCode& operator=(const ASPCode &rhs);
	
	/**
	 * Destructor.
	 */
	virtual ~ASPCode();
};

#endif
