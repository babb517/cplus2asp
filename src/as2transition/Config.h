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
		  showUnformattedPredicates(false),
		  predFormat(FMT_AF_COMPRESSED_BOOL)
		{ /* Intentionally Left Blank */ }

};



#endif /* CONFIG_H_ */
