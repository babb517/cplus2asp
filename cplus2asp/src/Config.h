/*
 * Config.h
 *
 *  Created on: Jan 23, 2013
 *      Author: Joseph Babb
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>
#include <vector>
#include <map>


/*********************************************************************************************/
/* Configuration Defaults */
/*********************************************************************************************/


#define DEF_RUNNING_MODE					MODE_INCREMENTAL					///< The default running mode.
#define DEF_INCL_STD						true								///< Whether to include standard files by default.
#define DEF_INCL_ADDITIVE					false								///< Whether to include additive files by default.
#define DEF_DISCARD_INT						true								///< Whether to discard intermediate files by default.
#define DEF_DISCARD_F2LP					true								///< Whether to discard intermediate F2LP files by default.
#define DEF_SUPPRESS_INTERACTION			false								///< Whether to suppress user interaction by default.
#define DEF_SQUELCH_SOLVER					true								///< Whether we should suppress warnings from the solver by default.
#define DEF_NONE_HACK						true								///< Whether we should simulate none being an integral type by default.
#define DEF_SHIFT							false								///< Whether we should assert the --shift flag, which shifts disjunction into the body of the rules.

#define DEF_NUM_SOLN						1									///< Default # of solutions to find.
#define DEF_INTERNAL_PORT					35981								///< Default port # to use to communicate w/ oClingo.

// Default commands
#define DEF_TRANS_CMD						"cplus2asp.bin"						///< Default translator command.
#define DEF_PREPROC_CMD						"f2lp -i"							///< Default preprocessor command.
#define DEF_GRD_CMD							""									///< Default grounder command.
#define DEF_SO_CMD							"iclingo"							///< Default solver command.
#define DEF_POSTPROC_CMD					"as2transition"						///< Default postprocessor command.
#define DEF_REACTIVE_BRIDGE_CMD				"cplus2asp_rclient"					///< Default reactive client command. TODO

#define DEF_GRD_REACTIVE_CMD				""									///< The default grounder to use in reactive mode.
#define DEF_SO_REACTIVE_CMD					"oclingo"							///< The default solver to use in reactive mode.

#define DEF_GRD_STATIC_CMD 					""									///< The default grounder to use in static mode.
#define DEF_SO_STATIC_CMD 					"clingo"							///< The default solver to use in static mode.

#define DEF_SO_INCREMENTAL_CMD				"iclingo"							///< The default solver to use in incremental mode.
#define DEF_GRD_INCREMENTAL_CMD				""									///< The default grounder to use in incremental mode.

// Default command options
#define DEF_TRANS_OPTS						""									///< Default translator options.
#define DEF_PREPROC_OPTS					""									///< Default preprocessor options.
#define DEF_GRD_OPTS						""									///< Default grounder options.
#define DEF_SO_OPTS							""									///< Default solver options.
#define DEF_GRSO_OPTS						""									///< Default grounder/solver options.
#define DEF_POSTPROC_OPTS					""									///< Default postprocessor options.
#define DEF_REACTIVE_BRIDGE_OPTS			""									///< Default reactive client

// files
#define CCALC2_ASP_STD_FILE  				"cplus2asp_std.f2lp"				///< The "standard" CCalc to ASP translation support file.
#define CCALC2_ASP_ADDITIVE_FILE			"cplus2asp_additive.f2lp" 			///< The CCalc to ASP translation support file for additive fluents/actions.
#define CCALC2_ASP_STD_DYNAMIC_FILE  		"cplus2asp_std.of2lp"				///< The "standard" CCalc to ASP translation support file (dynamic translation).
#define CCALC2_ASP_ADDITIVE_DYNAMIC_FILE	"cplus2asp_additive.of2lp" 			///< The CCalc to ASP translation support file for additive fluents/actions (dynamic translation).

// f2lp files
#define F2LP_INPUT_FILE						".f2lp_input.fof"
#define F2LP_OUTPUT_FILE					".solver_input.lp"

#define INT_TRANS_SYMTAB_FILE				".cplus2asp_trans.symtab"			///< The file to store the symbol table at.
#define INT_TRANS_FILE						".cplus2asp_trans.out"				///< Name of the intermediate output from the translator.
#define INT_PREPROC_FILE					".cplus2asp_pre.out"				///< Name of our intermediate output from the pre-processor.
#define INT_GRD_FILE 						".cplus2asp_gr.out"					///< Name of our intermediate output from the grounder.
#define INT_SO_FILE							".cplus2asp_so.out"					///< Name of our intermediate output from the solver.
#define INT_SO_ERR_FILE						".cplus2asp_so.err"					///< Name of our intermediate file for solver warnings.

// Known constant names
#define CONST_MAXSTEP						"maxstep"							///< Specifies the maximum step to use.
#define CONST_MINSTEP						"minstep"							///< Specifies the minimum step to use.
#define CONST_QUERY							"query"								///< Specifies the query to run.
#define CONST_MAXADDITIVE					"maxAdditive"						///< Specifies the maximum additive value to use.

// special query values
#define CONST_QUERY_NONE					"none"								///< The value to provide to the query to indicate that no query should be applied.
#define CONST_QUERY_STATES					"states"							///< The value to provide to the query to indicate that we should find the system's states.
#define CONST_QUERY_TRANSITIONS				"transitions"						///< The value to provide to the query to indicate that we should find the system's transitions.


// etc
#define HACKED_NONE_VALUE					"50000"								///< The value to treat none as if we're performing the gringo none hack.

/**
 * A basic structure to hold and manage various configuration options for the cplus2asp system.
 */
class Config {
public:
	/***************************************************************/
	/* Types */
	/***************************************************************/
	/// A list of each component of the toolchain.
	enum Toolchain
	{
		TC_BEGIN = 0x00,						///< An alias for the beginning of the toolchain.

		TC_TRANSLATOR = 0x00,					///< translator
		TC_PREPROC = 0x01,						///< pre-processor
		TC_GROUNDER = 0x02,						///< grounder
		TC_SOLVER = 0x03,						///< solver
		TC_POSTPROC = 0x04,						///< post-processor. Ignored in reactive mode.
		TC_REACTIVE_BRIDGE = 0x05,				///< The process to launch which interacts with a reactive solver.

		TC_END = 0x06,							///< Dummy constant to provide the end of the toolchain command list.
		TC_LENGTH = 0x06						///< (Not a tool) Provides the total length of the toolchain command.
	};

	/// The various operating modes that we can use.
	enum Mode
	{
		MODE_UNKNOWN = 0x00,					///< Unknown running mode. This should _only_ be used when specifying multiple modes.
		MODE_STATIC_AUTO = 0x01,				///< Automatically advancing static translation.
		MODE_STATIC_MANUAL = 0x02,				///< Manually advancing static translation.
		MODE_INCREMENTAL = 0x04,				///< Incremental translation.
		MODE_REACTIVE = 0x08					///< Reactive controller mode.
	};

	/// The various extra configurations that can be set.
	enum ConfigOption
	{
		OPT_BEGIN = 0x00,				///< Dummy constant to mark the beginning of the configuration list.

		// boolean
		OPT_INCL_STD = OPT_BEGIN,		///< Whether we should include the standard files.
		OPT_INCL_ADDITIVE,				///< Whether we should include the standard additive files.
		OPT_DISCARD_INTERMEDIATE,		///< Whether we should discard all intermediate files when we're done.
		OPT_DISCARD_F2LP,				///< Whether we should discard all F2LP intermediate files when we're done.
		OPT_SUPPRESS_INTERACTION,		///< Whether we should operate in silent mode.
		OPT_SQUELCH_SOLVER,				///< Whether we should silence the solver's warnings
		OPT_NONE_HACK,					///< Whether we should simulate none as an integral type to circumvent a gringo bug that prevents grounding otherwise.
		OPT_SHIFT,						///< Whether we should assert the '--shift' flag, which tells gringo to shift disjunction into the body of the rules.

		// integer
		OPT_MINSTEP,					///< The currently configured minimum step, or UNDEFINED.
		OPT_MAXSTEP,					///< The currently configured maximum step, or UNDEFINED.
		OPT_QUERY,						///< The currently configured query, or UNDEFINED.
		OPT_MAXADDITIVE,				///< The currently configured maximum additive, or UNDEFINED.
		OPT_NUM_SOLN,					///< The currently configured # of solutions to find.
		OPT_EXT_PORT,					///< The port that we should make available for the user.
		OPT_INT_PORT,					///< The port which we should use internally to communicate with oClingo.

		OPT_LENGTH,						///< Dummy constant to provide the number configuration options.
		OPT_END = OPT_LENGTH			///< Dummy constant to mark the end of the configuration list.
	};

	/// A flag-type used to specify multiple modes simultaneously
	typedef unsigned char Modes;

	/// A basic structure used to identify the tool and running mode associated with a file.
	struct FileType
	{
		bool known;				///< Whether the file type is known.
		Toolchain tool;			///< The tool the file is associated with.
		Modes runningMode;		///< The running mode the file is associated with.

		inline FileType()
			: known(false), tool(TC_BEGIN), runningMode(MODE_UNKNOWN)
			{ /* Intentionally Left Blank */ }

		inline FileType(bool _known, Toolchain _tool, Modes _runningMode)
			: known(_known), tool(_tool), runningMode(_runningMode)
			{ /* Intentionally Left Blank */ }

		inline virtual ~FileType() { /* Intentionally Left Blank */ }
	};

	/// A structure which is used to describe a query.
	struct Query
	{
		unsigned int id;		///< ID # for the query.
		std::string name;		///< The human-readable name of the query.
		std::string cmd;		///< The short name or command used for query selection.
		unsigned int minstep;	/// Minimum step for the query (if specified, UNDEFINED otherwise).
		unsigned int maxstep;	/// Maximum step for the query (if specified, UNDEFINED otherwise).

		inline Query()
			: id(UNDEFINED), name(""), cmd(""), minstep(UNDEFINED), maxstep(UNDEFINED)
			{ /* Intentionally Lef Blank */ }

		inline Query(unsigned int _id, std::string const& _name, std::string const& _cmd, unsigned int _minstep, unsigned int _maxstep)
			: id(_id), name(_name), cmd(_cmd), minstep(_minstep), maxstep(_maxstep)
			{ /* Intentionally Left Blank */ }

		inline virtual ~Query() { /* Intentionally Left Blank */ }

	};

	/// A structure used to describe the current runtime subconfiguration (used for iterative runs where the configuration can change).
	struct RunConfig
	{
		unsigned int queryId;					///< The query that should be run.
		unsigned int minstep;					///< The minimum step that should be solved for.
		unsigned int maxstep;					///< The maximum step that should be solved for.
		unsigned int numSoln;					///< The number of solutions to display.

	};

	typedef std::map<unsigned int, Query> QueryMap;						///< A map of queries indexed by their ID and their max steps.
	typedef std::map<std::string,std::string> ConstantMap;				///< A map between constant names and their definitions.
	typedef std::vector<std::string> InputList;							///< A list of input files.

private:

	/***************************************************************/
	/* Constants */
	/***************************************************************/
public:
	/// Indicates an undefined configuration setting.
	static unsigned int const UNDEFINED;

	/// Indicates that the user wishes to perform a satisfiability check to find system states.
	static unsigned int const STATES_QUERY;

	/// Indicates that the user wishes to find system transitions
	static unsigned int const TRANSITIONS_QUERY;


	/// Indicates that the user wishes to run without a query.
	static unsigned int const NO_QUERY;

	/***************************************************************/
	/* Members */
	/***************************************************************/
private:

	Mode mRunningMode;								///< The currently configured running mode.
	unsigned char mCustomRunningMode;				///< Whether the running mode has been manually set.

	// Misc Configurations
	unsigned int	mConfigOpts   [OPT_LENGTH];		///< The available configuration options.
	unsigned char	mCustomConfig [OPT_LENGTH];		///< Whether each configuration option has been set previously.

	QueryMap mQueries;								///< The set of all known queries.

	// Toolchain configuration
	std::string 	mCommands	[TC_LENGTH];		///< The command to use for each step in the toolchain.
	unsigned char 	mCustomCmd 	[TC_LENGTH];		///< Whether each toolchain command has been custom set.
	bool 			mRun	 	[TC_LENGTH];		///< Whether we should run each part of the toolchain.
	unsigned char	mCustomRun	[TC_LENGTH];		///< Whether each toolchain component has been custom set to run or not.
	std::string 	mOpts	 	[TC_LENGTH];		///< The options to use for each part of the toolchain.
	unsigned char	mCustomOpts [TC_LENGTH];		///< Whether each toolchain component's options have been changed or not.
	InputList		mInputs 	[TC_LENGTH];		///< The files which are designated dynamically as input for each of the toolchain components.
	ConstantMap		mConstDefs;								///< The constants which have been defined and should be passed to the grounder.

public:
	/***************************************************************/
	/* Constructors / Destructors */
	/***************************************************************/
	/**
	 * Default Constructor
	 * Initializes the configuration to defaults.
	 */
	Config();

	/**
	 * Destructor
	 * Does nothing.
	 */
	inline virtual ~Config() { /* Intentionally Left Blank */ }

	/***************************************************************/
	/* Psuedo Accessors */
	/***************************************************************/

	/// Install directory
	std::string installDir() const;

	/// standard file
	inline std::string stdFile() const
		{ return (mode() == MODE_INCREMENTAL || mode() == MODE_REACTIVE) ?
				installDir() + "/" + CCALC2_ASP_STD_DYNAMIC_FILE
				: installDir() + "/" + CCALC2_ASP_STD_FILE;
		}

	/// Additive file
	inline std::string additiveFile() const
		{ return (mode() == MODE_INCREMENTAL || mode() == MODE_REACTIVE) ?
				installDir() + "/" + CCALC2_ASP_ADDITIVE_DYNAMIC_FILE
				: installDir() + "/" + CCALC2_ASP_ADDITIVE_FILE;
		}

	/// Intermediate translator file
	inline std::string intTransFile() const 				{ return INT_TRANS_FILE; }

	/// Intermediate symbol table file from the translator.
	inline std::string intTransSymTabFile() const			{ return INT_TRANS_SYMTAB_FILE; }

	/// Intermediate preprocessor file
	inline std::string intPreprocFile() const				{ return INT_PREPROC_FILE; }

	/// Intermediate grounder file
	inline std::string intGrdFile() const					{ return INT_GRD_FILE; }

	/// Intermediate solver file
	inline std::string intSoFile() const					{ return INT_SO_FILE; }

	/// Intermediate file to store solver errors.
	inline std::string intSoErrFile() const					{ return INT_SO_ERR_FILE; }

	/***************************************************************/
	/* Basic accessors / mutators */
	/***************************************************************/

	/// Basic Accessor. Does what's on the box.

	// mode
	///@return The currently configured running mode
	inline Mode mode() const										{ return mRunningMode; }
	///@return Whether the running mode has been manually modified.
	inline bool customMode() const									{ return (bool)mCustomRunningMode; }

	// config options
	///@return The boolean value of the specified option.
	inline bool boolConfigOpt(ConfigOption opt) const				{ return (bool)mConfigOpts[opt]; }
	///@return The integral value of the specified option.
	inline unsigned int intConfigOpt(ConfigOption opt) const		{ return mConfigOpts[opt]; }
	///@return Whether the specified option has been manually modified.
	inline bool customConfigOpt(ConfigOption opt) const				{ return (bool)mCustomConfig[opt]; }

	// command options
	///@return The base command for the specifed tool.
	inline std::string const& command(Toolchain tool) const			{ return mCommands[tool]; }
	///@return Whether the base command for the tool has been manually modififed.
	inline bool customCmd(Toolchain tool) const						{ return (bool)mCustomCmd[tool]; }
	///@return Whether the tool is configured to run.
	inline bool run(Toolchain tool) const							{ return mRun[tool]; }
	///@return Whether the run status of the tool has been manually modified.
	inline bool customRun(Toolchain tool) const						{ return (bool)mCustomRun[tool]; }
	///@return The user-defined command options for the specified tool.
	inline std::string const& opts(Toolchain tool) const			{ return mOpts[tool]; }
	///@return Whether the command options have been manually modififed.
	inline bool customOpts(Toolchain tool) const					{ return (bool)mCustomOpts[tool]; }

	// constants
	inline bool isDefined(std::string const& constant) const;
	std::string const* def(std::string const& constant) const;

	// queries
	inline size_t queryCount() const								{ return mQueries.size(); }
	inline bool hasQuery(unsigned int queryID) const				{ return (bool)mQueries.count(queryID); }
	inline Query const* activeQuery() const							{ return query(intConfigOpt(OPT_QUERY));  }
	Query const* query(unsigned int queryID) const;
	std::string const* queryName(unsigned int queryID) const;
	unsigned int queryMaxStep(unsigned int queryID) const;
	unsigned int queryMinStep(unsigned int queryID) const;



	/// Basic Mutators.

	/// @return If the running mode has been previously set.
	bool mode(Mode newMode);


	/// @return If the option was previously set.
	bool boolConfigOpt(ConfigOption opt, bool val);

	/// @return If the option was previously set.
	bool intConfigOpt(ConfigOption opt, unsigned int val);

	/// @return If the constant was previously defined.
	bool def(std::string const& constant, std::string const& value);

	/// Sets the base command for a tool.
	/// An empty value will disable the tool.
	/// A non-empty value will enable the tool.
	/// @return If the command has previously been changed.
	bool command(Toolchain tool, std::string const& val);

	/// @return If the run status has been previously changed.
	bool run(Toolchain tool, bool val);

	/// @return Whether the option has been previously set.
	bool opts(Toolchain tool, std::string const& val);

	/**
	 * Attempts to add a query to the list of known queries.
	 * @param queryID The ID of the query.
	 * @param name The human readable name of the query.
	 * @param cmd The command used to select this query.
	 * @param maxstep The maxstep of the query (or UNDEFINED).
	 * @param minstep The minstep of the query (or UNDEFINED).
	 * @return true if the add operation was a success. False if it failed (duplicate ID).
	 */
	bool addQuery(unsigned int queryID, std::string const& name, std::string const& cmd, unsigned int maxstep = UNDEFINED, unsigned int minstep = UNDEFINED);

	/**
	 * Attempts to add a query to the list of known queries.
	 * @param query The query to add.
	 * @return true if the add operation was a success. False if it failed (duplicate ID).
	 */
	bool addQuery(Query const& query);

	/***************************************************************/
	/* Advanced functionality / Helpers */
	/***************************************************************/


	/**
	 * Adds an input file to the list, determining which toolchain component it appears to belong to based on its extension.
	 * @param input The name of the input file.
	 * @return Flags indicating the input's associated tool and running mode.
	 */
	FileType addInput(std::string const& input);

	/**
	 * Adds an input file the given tool's list.
	 * @param tool The tool to add the input file to.
	 * @param input The name of the input file.
	 */
	inline void addInput(Toolchain tool, std::string const& input)
															{ mInputs[tool].push_back(input); }


	/**
	 * Tallies the number of user inputs that will be added to the provided too.
	 * This tally includes intermediate files from the previous step that will be
	 * ran, as well as input files from all steps between the specified tool and
	 * the previous step that was ran.
	 * @param tool The tool to get an input tally of.
	 * @return The number of user input files that will be passed to that tool.
	 */
	size_t cumulativeInputCount(Toolchain tool) const;


	/**
	 * Gets an iterator pointing to the beginning of the list of input files for a tool.
	 * Note: Be aware that these are user-specified files and do not include the files belonging to previous unran tools or their intermediate output.
	 * @param tool The tool to get the iterator for.
	 * @return An iterator pointing the beginning of the input list.
	 */
	inline InputList::const_iterator
	beginInput(Toolchain tool) const						{ return mInputs[tool].begin(); }

	/**
	 * Gets an iterator pointing to the end of the list of input files for a tool.
	 * @param tool The tool to get the iterator for.
	 * @return An iterator pointing the end of the input list.
	 */
	inline InputList::const_iterator
	endInput(Toolchain tool) const							{ return mInputs[tool].end(); }

	/**
	 * Gets an iterator pointing to the beginning of the list of constant definitions.
	 * @return An iterator pointing the beginning of the constant definitions.
	 */
	inline ConstantMap::const_iterator
	beginConstants() const									{ return mConstDefs.begin(); }

	/**
	 * Gets an iterator pointing to the end of the list of constant definitions.
	 * @return An iterator pointing the end of the constant definitions.
	 */
	inline ConstantMap::const_iterator
	endConstants() const									{ return mConstDefs.end(); }

	/**
	 * Gets an iterator pointing to the beginning of the list of query definitions.
	 * @return An iterator pointing the beginning of the query definitions.
	 */
	inline QueryMap::const_iterator
	beginQueries() const									{ return mQueries.begin(); }


	/**
	 * Gets an iterator pointing to the beginning of the list of query definitions.
	 * @return An iterator pointing the beginning of the query definitions.
	 */
	inline QueryMap::const_iterator
	endQueries() const										{ return mQueries.end(); }

	/**
	 * Gets an iterator pointing to the end of the list of input files for a tool.
	 * @param tool The tool to get the iterator for.
	 * @return An iterator pointing the end of the input list.
	 */
	inline InputList::iterator
	beginInput(Toolchain tool)								{ return mInputs[tool].begin(); }

	/**
	 * Gets an iterator pointing to the beginning of the list of input files for a tool.
	 * @param tool The tool to get the iterator for.
	 * @return An iterator pointing the beginning of the input list.
	 */
	inline InputList::iterator
	endInput(Toolchain tool)								{ return mInputs[tool].begin(); }

	/**
	 * Gets an iterator pointing to the beginning of the list of constant definitions.
	 * @return An iterator pointing the beginning of the constant definitions.
	 */
	inline ConstantMap::iterator
	beginConstants()										{ return mConstDefs.begin(); }

	/**
	 * Gets an iterator pointing to the end of the list of constant definitions.
	 * @return An iterator pointing the end of the constant definitions.
	 */
	inline ConstantMap::iterator
	endConstants()											{ return mConstDefs.end(); }

	/**
	 * Gets an iterator pointing to the beginning of the list of query definitions.
	 * @return An iterator pointing the beginning of the query definitions.
	 */
	inline QueryMap::iterator
	beginQueries()										{ return mQueries.begin(); }


	/**
	 * Gets an iterator pointing to the beginning of the list of query definitions.
	 * @return An iterator pointing the beginning of the query definitions.
	 */
	inline QueryMap::iterator
	endQueries()										{ return mQueries.end(); }

	/**
	 * Compiles the command line call for a specific element in the toolchain.
	 * @param tool The toolchain element we want to compile the call for.
	 * @param subconfig The subconfiguration used to override settings for this specific run.
	 * @return A command to send to the system to call the element.
	 */
	std::string compileCommandLine(Toolchain tool, RunConfig const* subconfig = NULL) const;

	/**
	 * Sets the toolchain to run everything up to the desired tool and nothing else.
	 * @param tool The toolchain tool to run to.
	 * @return True if this command has overidden one or more previous configuration options.
	 */
	bool setRunTo(Toolchain tool);

	/**
	 * Sets the toolchain to run everything from the desired tool (including the tool) and nothing else.
	 * @param tool The toolchain tool to run from.
	 * @return True if this command has overriden one or more previous configuration options.
	 */
	bool setRunFrom(Toolchain tool);

	/**
	 * Sets the toolchain to run only the specified tool and nothing else.
	 * @param tool The toolchain tool to run.
	 * @return True if this command has overriden one or more previous configuration options.
	 */
	bool setOnlyRun(Toolchain tool);

	/**
	 * Parses a maxstep specification in the form a single unsigned integer or an integer range %d..%d.
	 * @param maxstep The maxstep specification.
	 * @return A pair (maxstep,minstep) corresponding to the specification.
	 * If the specification is malformed both will be UNDEFINED.
	 * If it's a single integer, minstep will be UNDEFINED.
	 */
	static std::pair<unsigned int, unsigned int> parseMaxstep(std::string const& maxstep);


protected:

	/**
	 * Compiles a command which aggregates all the appropriate input files for a toolchain tool into stdout.
	 * @param tool The tool to compile the inputs for.
	 * @return A command which results in all the tool's input files being sent to stdout.
	 */
	std::string compileInputCommand(Toolchain tool) const;


	/**
	 * Attempts to identify the provided extension, providing information about which tool and running
	 * mode it's associated with.
	 * @param ext The extension to attempt to identify.
	 * @param[out] out Flags indicating the associated tool and running mode.
	 * @return out.
	 */
	FileType& checkExtension(char const* ext, FileType& out) const;


};



#endif /* CONFIG_H_ */
