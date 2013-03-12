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


#ifndef NUMBERRANGE_H
#define NUMBERRANGE_H

#include <string>

#include "Object.h"

/**
 * Subclass of Object, represents a range of integers as objects.
 */
class NumberRange : public Object
{
private:
	std::string mMin; 		///< The lower bound of the range.
	std::string mMax; 		///< The upper bound of the range.

public:

	/**
	 * Full constructor.
	 * @param name - The C+ raw name of the range.
	 */
	NumberRange(std::string const& name);
	
	/**
	 * Full constructor.
	 * @param min - The minimum value of the number range.
	 * @param max - The maximum value of the number range.
	 */
	inline NumberRange(std::string const& min, std::string const& max)
			: Object(min + ".." + max, Object::OBJ_RANGE, NULL), mMin(min), mMax(max)
	{ /* Intentionally Left Blank */ }

	virtual std::string toString() const;
	
	/// Gets the lower bound of the range.
	inline std::string const& min() const { return mMin; }
	
	/// Gets the upper bound of the range
	inline std::string const& max() const { return mMax; }

	/// Sets the lower bound of the range.
	inline void min(std::string const& min) { mMin = min; }

	/// Sets the upper bond of the rnage
	inline void max(std::string const& max) { mMax = max; }

	
	/**
	 * Destructor. Left empty, as there's nothing to do.
	 */
	inline virtual ~NumberRange() { /* Intentionally Left Blank */ }
};

#endif /* NUMBERRANGE_H */
