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


#ifndef COMMENT_H
#define COMMENT_H

#include <string>

struct YYLTYPE;

/**
 * A class designed to encapsulate a raw comment pulled from input to be output later.
 */
class Comment
{
public:
	std::string contents; ///< The text of the comment, sans comment symbol.
	std::string fileName; ///< The file the comment came from.
	YYLTYPE* loc; ///< The original location of the comment in the file.
	bool isRealComment; ///< If false, the "comment" is just some raw text that needs passing through.
	
	/**
	 * Default constructor. Sets everything to blank or zero, starts isRealComment with the value true.
	 */
	Comment();
	
	/**
	 * Assignment operator overload.
	 * Copies all data from rhs to the lhs comment.
	 * @param rhs - The Comment to grab the data from.
	 * @return A reference to the lhs comment.
	 */
	Comment& operator=(const Comment &rhs);
	
	/**
	 * Checks if the comment came from the same file as the given parameter.
	 * @param otherFileName - The file name to check against the comment's file.
	 * @return True if the file names match, false otherwise.
	 */
	bool isInFile(std::string otherFileName);
	
	/**
	 * Checks if the comment's location is past the given location.
	 * A comment is past another location if the beginning
	 * of the comment is past the end of the other location.
	 * @param otherLoc - The location to compare against the comment's loc.
	 * @return True if the comment is completely past the given location, false otherwise.
	 */
	bool isAfterLoc(YYLTYPE otherLoc);
	
	/**
	 * Checks if the comment's location is before the given location.
	 * A comment is before another location if the end
	 * of the comment is before the beginning of the other location.
	 * @param otherLoc - The location to compare against the comment's loc.
	 * @return True if the comment is completely before the given location, false otherwise.
	 */
	bool isBeforeLoc(YYLTYPE otherLoc);
	
	/**
	 * Transforms the contents of the comment into a valid ASP-compatible comment.
	 * Handles multi-line comments by making them multiple single-line comments.
	 * If isRealComment is false, just returns contents.
	 * @return A string containing the contents of the comment correctly escaped with comment symbols.
	 */
	std::string output();
	
	/**
	 * Destructor.
	 */
	virtual ~Comment();
};

#endif
