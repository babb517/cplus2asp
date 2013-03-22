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


/**
 * Config.h
 *
 *  Created on: Jan 14, 2013
 *      Author: Joseph Babb
 */


#ifndef CONFIG_H_
#define CONFIG_H_

/**
 * @file Config.h
 * @author Joseph Babb
 * @brief A simple structure-like class which provides convenient storage for configuration options.
 */
class Config {
public:
	/// An enum for output formatting options
	enum Format {
		FMT_ORIGINAL,				/// <prefix>(eq(<name>,<value>),<timestamp>)
		FMT_STRIP_PREFIX, 			/// eq(<name>,<value>)
		FMT_ATOMIC_FORMULA, 		/// <name>=<value>
		FMT_AF_COMPRESSED_BOOL 		/// Same as ATOMIC_FORMULA, except boolean values are represented as <name> and -<name>
	};

	bool onePredPerLine; 			///< If true, each predicate will appear on its own line.

	bool separateActions; 			///< If false, will stop actions from being displayed separately from fluents.
	bool separateAbnormalities;		///< If false, we will stop abnormalities from being displayed separately.

	bool showContribPredicates; 	///< If true, we'll display formatted predicates whose inner predicate is "contribution" (usually hidden as an "internal" thing).
	bool showNegPredicates; 		///< If true, predicates of the form something=false or something=none will be shown.
	bool showXPredicates; 			///< If true, we'll display formatted predicates whose inner predicate starts with "x_" (e.g., "<prefix>(x_contrib(...),0)").
	bool showUnformattedPredicates;	///< If true, we'll display predicates which aren't formatted in the expected manner.

	Format predFormat;

	/// Basic Constructor
	inline Config()
		: onePredPerLine(false),
		  separateActions(true),
		  separateAbnormalities(true),
		  showContribPredicates(false),
		  showNegPredicates(false),
		  showXPredicates(false),
		  showUnformattedPredicates(true),
		  predFormat(FMT_AF_COMPRESSED_BOOL)
		{ /* Intentionally Left Blank */ }

};



#endif /* CONFIG_H_ */
