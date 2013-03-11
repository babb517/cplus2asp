#include <string>

#include "Comment.h"
#include "ltsglobals.h"

#include "ASPCode.h"

// Default constructor.
ASPCode::ASPCode() : Comment()
{
	// ASP code isn't a "real" comment, it's just raw text.
	isRealComment = false;
}

// Assignment operator overload.
ASPCode& ASPCode::operator=(const ASPCode &rhs)
{
	// Skip self-assignment.
	if(this != &rhs)
	{
		this->contents = rhs.contents;
		this->fileName = rhs.fileName;
		if(rhs.loc != NULL)
		{
			if(this->loc == NULL)
			{
				this->loc = new YYLTYPE;
			}
			this->loc->first_line = rhs.loc->first_line;
			this->loc->last_line = rhs.loc->last_line;
			this->loc->first_column = rhs.loc->first_column;
			this->loc->last_column = rhs.loc->last_column;
		}
		else
		{
			if(this->loc != NULL)
			{
				delete this->loc;
			}
			this->loc = NULL;
		}
		this->isRealComment = rhs.isRealComment;
	}
	return *this;
}

// Destructor.
ASPCode::~ASPCode()
{
	// Nothing to do, intentionally empty.
}
