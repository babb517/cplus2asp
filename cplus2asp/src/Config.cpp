/* Generated by re2c 0.13.5 on Mon Feb 18 12:58:10 2013 */
#line 1 "Config.re2c"
/*
 * Config.cpp
 *
 *  Created on: Jan 23, 2013
 *      Author: Joseph Babb
 */

#include <cstring>
#include <string>
#include <sstream>
#include <stdexcept>
#include <climits>

#include "Config.h"
#include "utils.h"


/***************************************************************/
/* Constants */
/***************************************************************/
unsigned int const Config::UNDEFINED = UINT_MAX;
unsigned int const Config::SAT_QUERY = UINT_MAX - 1;
unsigned int const Config::NO_QUERY = UINT_MAX - 2;

/***************************************************************/
/* Methods */
/***************************************************************/

// Default Constructor
Config::Config() {
	mRunningMode = DEF_RUNNING_MODE;
	mCustomRunningMode = false;

	mConfigOpts[OPT_INCL_STD] = DEF_INCL_STD;
	mConfigOpts[OPT_INCL_ADDITIVE] = DEF_INCL_ADDITIVE;
	mConfigOpts[OPT_DISCARD_INTERMEDIATE] = DEF_DISCARD_INT;
	mConfigOpts[OPT_DISCARD_F2LP] = DEF_DISCARD_F2LP;
	mConfigOpts[OPT_SUPPRESS_INTERACTION] = DEF_SUPPRESS_INTERACTION;
	mConfigOpts[OPT_MINSTEP] = UNDEFINED;
	mConfigOpts[OPT_MAXSTEP] = UNDEFINED;
	mConfigOpts[OPT_QUERY] = UNDEFINED;
	mConfigOpts[OPT_MAXADDITIVE] = UNDEFINED;
	mConfigOpts[OPT_NUM_SOLN] = DEF_NUM_SOLN;
	mConfigOpts[OPT_EXT_PORT] = UNDEFINED;
	mConfigOpts[OPT_INT_PORT] = DEF_INTERNAL_PORT;
	mConfigOpts[OPT_NONE_HACK] = DEF_NONE_HACK;
	mConfigOpts[OPT_SHIFT] = DEF_SHIFT;

	memset(mCustomConfig,0,OPT_LENGTH);

	mCommands[TC_TRANSLATOR] = DEF_TRANS_CMD;
	mCommands[TC_PREPROC] = DEF_PREPROC_CMD;
	mCommands[TC_GROUNDER] = DEF_GRD_CMD;
	mCommands[TC_SOLVER] = DEF_SO_CMD;
	mCommands[TC_POSTPROC] = DEF_POSTPROC_CMD;
	mCommands[TC_REACTIVE_BRIDGE] = DEF_REACTIVE_BRIDGE_CMD;


	memset(mCustomCmd,0,TC_LENGTH);

	memset(mRun,1,TC_LENGTH);
	mRun[TC_GROUNDER] = false;

	memset(mCustomRun,0,TC_LENGTH);

	mOpts[TC_TRANSLATOR] = DEF_TRANS_OPTS;
	mOpts[TC_PREPROC] = DEF_PREPROC_OPTS;
	mOpts[TC_GROUNDER] = DEF_GRD_OPTS;
	mOpts[TC_SOLVER] = DEF_SO_OPTS;
	mOpts[TC_POSTPROC] = DEF_POSTPROC_OPTS;
	mOpts[TC_REACTIVE_BRIDGE] = DEF_REACTIVE_BRIDGE_OPTS;

	memset(mCustomOpts,0,TC_LENGTH);

	// Default queries which should always be made available...
	mQueries[Config::NO_QUERY] = Query(Config::NO_QUERY, "No Query", CONST_QUERY_NONE, UNDEFINED, UNDEFINED);
	mQueries[Config::SAT_QUERY] = Query(Config::SAT_QUERY, "Satisfiability Check", CONST_QUERY_SAT, UNDEFINED, 0);
}

// Gets the definition of a constant or NULL
std::string const* Config::def(std::string const& constant) const {
	try {
		return &mConstDefs.at(constant);
	}
	catch (std::out_of_range& e)
	{
		return NULL;
	}
	return NULL;
}


// Gets the query specified by the ID, or null if it doesn't exist.
Config::Query const* Config::query(unsigned int queryID) const {
	if (hasQuery(queryID)) return &(mQueries.at(queryID));
	else return NULL;
}

// Convenience method to get the name of a query.
std::string const* Config::queryName(unsigned int queryID) const {
	Query const* q;
	if ((q = query(queryID)) != NULL) return &(q->name);
	else return NULL;
}

// Convenience method to get the maxstep of a query
unsigned int Config::queryMaxStep(unsigned int queryID) const {
	Query const* q;
	if ((q = query(queryID)) != NULL) return q->maxstep;
	else return UNDEFINED;
}

// Convenience method to get the minstep of a query.
unsigned int Config::queryMinStep(unsigned int queryID) const {
	Query const* q;
	if ((q = query(queryID)) != NULL) return q->minstep;
	else return UNDEFINED;
}



// Set the running mode for the program
bool Config::mode(Mode newMode) {
	mCustomRunningMode++;
	if (mRunningMode == newMode) return false;
	mRunningMode = newMode;


	switch (newMode) {
	case MODE_STATIC_AUTO:
	case MODE_STATIC_MANUAL:
		if (!customCmd(TC_GROUNDER)) mCommands[TC_GROUNDER] = DEF_GRD_STATIC_CMD;
		if (!customCmd(TC_SOLVER)) mCommands[TC_SOLVER] = DEF_SO_STATIC_CMD;
		break;
	case MODE_INCREMENTAL:
		if (!customCmd(TC_GROUNDER)) mCommands[TC_GROUNDER] = DEF_GRD_INCREMENTAL_CMD;
		if (!customCmd(TC_SOLVER)) mCommands[TC_SOLVER] = DEF_SO_INCREMENTAL_CMD;
		break;
	case MODE_REACTIVE:
		if (!customCmd(TC_GROUNDER)) mCommands[TC_GROUNDER] = DEF_GRD_REACTIVE_CMD;
		if (!customCmd(TC_SOLVER)) mCommands[TC_SOLVER] = DEF_SO_REACTIVE_CMD;
		break;
	case MODE_UNKNOWN:
		break;
	}

	return (bool)(mCustomRunningMode - 1);
 }

// Checks if a constant is defined
inline bool Config::isDefined(std::string const& constant) const {
	std::string constant_trimmed = trimWhitespace(constant);

	if (constant_trimmed == CONST_MAXSTEP) {
		return customConfigOpt(OPT_MAXSTEP);
	} else if (constant_trimmed == CONST_MINSTEP) {
		return customConfigOpt(OPT_MINSTEP);
	} else if (constant_trimmed == CONST_QUERY) {
		return customConfigOpt(OPT_QUERY);
	} else if (constant_trimmed == CONST_MAXADDITIVE) {
		return customConfigOpt(OPT_MAXADDITIVE);
	} else {
		return (bool)mConstDefs.count(constant_trimmed);
	}
}

// Sets a config options to a boolean value.
bool Config::boolConfigOpt(ConfigOption opt, bool val) {
	mCustomConfig[opt]++;
	if (((bool)mConfigOpts[opt]) == val) return false;
	mConfigOpts[opt] = (unsigned int)val;
	return (bool)(mCustomConfig[opt] - 1);
}

// Sets a config option to an integral value.
bool Config::intConfigOpt(ConfigOption opt, unsigned int val) {
	mCustomConfig[opt]++;
	if (mConfigOpts[opt] == val) return false;
	mConfigOpts[opt] = val;
	return (bool)(mCustomConfig[opt] - 1);
}

// Sets a command option to the provided value.
bool Config::command(Toolchain tool, std::string const& val) {
	bool ret = mCustomCmd[tool]++;
	if (mCommands[tool] == val) return run(tool, val != "");
	ret |= run(tool, val != "");
	mCommands[tool] = val;
	return ret;
}

/// @return If the run status has been previously changed.
bool Config::run(Toolchain tool, bool val) {
	mCustomRun[tool]++;
	if(mRun[tool] == val) return false;
	mRun[tool] = val;
	return (bool)(mCustomRun[tool] - 1);
}

bool Config::opts(Toolchain tool, std::string const& val) {
	mCustomOpts[tool]++;
	if (mOpts[tool] == val) return false;
	mOpts[tool] = val;
	return (bool)(mCustomOpts[tool] - 1);
}

// Defines a constant
bool Config::def(std::string const& constant, std::string const& value) {
	std::string constant_trimmed = trimWhitespace(constant);
	std::string value_trimmed = trimWhitespace(value);
	unsigned int tmpVal;
	bool redef = false;
	bool bad = false;

	// Check this against several known constants and update their values if necessary...
	if (constant_trimmed == CONST_MAXSTEP) {
		std::pair<unsigned int,unsigned int> stepvals = parseMaxstep(value_trimmed);

		if (stepvals.first == UNDEFINED) {
			bad = true;
		} else {
			redef = intConfigOpt(OPT_MAXSTEP, stepvals.first);
			if (stepvals.second != UNDEFINED) intConfigOpt(OPT_MINSTEP, stepvals.second);
		}

	} else if (constant_trimmed == CONST_MINSTEP) {
		if (from_string(tmpVal,value_trimmed)) {
			redef = intConfigOpt(OPT_MINSTEP, tmpVal);
		} else {
			// Oops... Throw a warning, ignore it, and continue.
			bad = true;
		}
	} else if (constant_trimmed == CONST_QUERY) {

		// The query allows for some special options...
		if (value_trimmed == CONST_QUERY_NONE) {
			// The user has requested we use no query.
			redef = intConfigOpt(OPT_QUERY, NO_QUERY);
		} else if (value_trimmed == CONST_QUERY_SAT) {
			// The user has requested that we perform a satisfiability check.
			redef = intConfigOpt(OPT_QUERY, SAT_QUERY);
		} else if (from_string(tmpVal,value_trimmed)) {
			// The user has provided us with a query to perform.
			redef = intConfigOpt(OPT_QUERY,tmpVal);
		} else {
			// Oops... Throw a warning, ignore it, and continue.
			bad = true;
		}
	} else if (constant_trimmed == CONST_MAXADDITIVE) {
		if (from_string(tmpVal,value_trimmed)) {
			redef = intConfigOpt(OPT_MAXADDITIVE,tmpVal);
		} else {
			// Oops... Throw a warning, ignore it, and continue.
			bad = true;
		}
	} else {
		// It's a normal constant...
		redef = (bool)mConstDefs.count(constant_trimmed);
		mConstDefs[constant_trimmed] = value_trimmed;

	}

	if (bad) {
		// If the value was bad then go ahead and warn the user.
		warning("The value '%s' is not valid for the reserved constant '%s'. It will be ignored.",true, value_trimmed.c_str() ,constant_trimmed.c_str());
	}

	return redef;
}

// Calculates the number of input files for a specific tool
size_t Config::cumulativeInputCount(Toolchain tool) const {

	size_t count = 0;

	// Let's count all the input files
	// which belong to
	// a) The current tool,
	// b) The tools immediately preceeding the tool which we aren't running.

	for (Toolchain i = tool; i >= TC_BEGIN; i = (Toolchain)((int)i + 1)) {
		// Only include files which haven't been included by a previous tool.
		if (i != tool && run(i)) break;

		for (InputList::const_iterator it = beginInput(tool); it != endInput(tool); it++) {
			count++;
		}
	}

	// Compile the input files from previous step's outputs.
	switch (tool) {
	case TC_END:
	case TC_REACTIVE_BRIDGE:
		// Reactive bridge is different.
		if (run(TC_TRANSLATOR)) {
			count++;
		}
		break;

	case TC_POSTPROC:
		if (run(TC_SOLVER)) {
			count++;
			break;
		}
		/* no break */

	case TC_SOLVER:
		if (run(TC_GROUNDER)) {
			count++;
			break;
		}
		/* no break */

	case TC_GROUNDER:
		if (run(TC_PREPROC)) {
			count++;
			break;
		}
		/* no break */

	case TC_PREPROC:
		if (run(TC_TRANSLATOR)) {
			count++;
			break;
		}
		/* no break */

	case TC_TRANSLATOR:
		// none
		break;

	}

	return count;
}

// Compiles a command line call for the given toolchain element
std::string Config::compileCommandLine(Toolchain tool, unsigned int curMaxStep) const {
	std::ostringstream out;

	// General command
	out << command(tool) << " " << compileInputCommand(tool) << " " << opts(tool);

	// Add step specific instructions
	switch (tool) {
	case TC_END:
	case TC_TRANSLATOR:

		// The translator should be told to output the symbol table
		//TODO
		out << " --symbol-table \"" << intTransSymTabFile() << "\"";

		// We also should have it tell us what special constants it finds.
		out << " --expressive-return";

		// The translator should be told the translation mode.
		switch (mode()) {
		case MODE_STATIC_AUTO:
		case MODE_STATIC_MANUAL:
			out << " --static";
			break;
		case MODE_INCREMENTAL:
		case MODE_REACTIVE:
		default:
			break;
		}

		// The translator should be directed to temp output location if we are
		// sending it the pre-processor...

		if (run(TC_PREPROC)) out << " > \"" << intTransFile() << "\"";
		break;

	case TC_PREPROC:

		// The preprocessor should include the standard files in addition to the 'normal' include files.
		if (boolConfigOpt(OPT_INCL_STD))
			out << " " << stdFile();
		if (boolConfigOpt(OPT_INCL_ADDITIVE))
			out << " " << additiveFile();

		// The preprocessor should be directed to the temp output location if we
		// are going to be sending it to the grounder (or solver).
		if (run(TC_GROUNDER)|| run(TC_SOLVER))
			out << " > \"" << intPreprocFile() << "\"";



		break;

	case TC_SOLVER:
		// Solvers need:
		// * Number of solutions to find.
		// * Query information.
		// * Minimum step information
		// * Maximum step information.

		// # solutions
		out << " " << intConfigOpt(OPT_NUM_SOLN);

		// special constants (if we're running what looks like a grounder/solver)
		if (!run(TC_GROUNDER)) {
			if (intConfigOpt(OPT_QUERY) != UNDEFINED) out << " -c query=" << intConfigOpt(OPT_QUERY);
			if (intConfigOpt(OPT_MAXSTEP) != UNDEFINED) out << " -c maxstep=" << intConfigOpt(OPT_MAXSTEP);
			if (intConfigOpt(OPT_MINSTEP) != UNDEFINED) out << " -c minstep=" << intConfigOpt(OPT_MINSTEP);
			if (intConfigOpt(OPT_MAXADDITIVE) != UNDEFINED) out << " -c maxAdditive=" << intConfigOpt(OPT_MAXADDITIVE);
			if (boolConfigOpt(OPT_NONE_HACK)) out << " -c none=" << HACKED_NONE_VALUE;

			// The '--shift' flag signals that gringo should shift disjunction into the body of a rule.
			if (boolConfigOpt(OPT_SHIFT)) out << " --shift";


			for (ConstantMap::const_iterator it = beginConstants(); it != endConstants(); it++) {
				out << " -c " << it->first << "=" << it->second;
			}
		}

		// min/max step
		if (mode() == MODE_INCREMENTAL || mode() == MODE_REACTIVE) {
			if (intConfigOpt(OPT_MINSTEP) != UNDEFINED) out << " --imin=" << intConfigOpt(OPT_MINSTEP);
			if (intConfigOpt(OPT_MAXSTEP) != UNDEFINED){
				if (intConfigOpt(OPT_MAXSTEP) > 0)
					out << " --imax=" << intConfigOpt(OPT_MAXSTEP);
				else
					out << " --ibase";
			}
		}


		// The solver should be directed to the temp solver location if:
		// We are running in reactive mode, or
		// We are going to run the post-processor
		if (run(TC_POSTPROC) || mode() == MODE_REACTIVE)
			out << " > \"" << intSoFile() << "\"";

		// Silence the solver warnings by default
		if (boolConfigOpt(OPT_SQUELCH_SOLVER)) {
			out << " 2> /dev/null";
		}

		// If we're running in reactive mode and are set to run the reactive bridge then we should run the solver in the background
		if (mode() == MODE_REACTIVE && run(TC_REACTIVE_BRIDGE)) out << " &";

		break;
	case TC_GROUNDER:

		// Include special constant definitions
		if (intConfigOpt(OPT_QUERY) != UNDEFINED) out << " -c query=" << intConfigOpt(OPT_QUERY);
		if (intConfigOpt(OPT_MAXSTEP) != UNDEFINED) out << " -c maxstep=" << intConfigOpt(OPT_MAXSTEP);
		if (intConfigOpt(OPT_MINSTEP) != UNDEFINED) out << " -c minstep=" << intConfigOpt(OPT_MINSTEP);
		if (intConfigOpt(OPT_MAXADDITIVE) != UNDEFINED) out << " -c maxAdditive=" << intConfigOpt(OPT_MAXADDITIVE);
		if (boolConfigOpt(OPT_NONE_HACK)) out << " -c none=" << HACKED_NONE_VALUE;

		// The '--shift' flag signals that gringo should shift disjunction into the body of a rule.
		if (boolConfigOpt(OPT_SHIFT)) out << " --shift";
		
		for (ConstantMap::const_iterator it = beginConstants(); it != endConstants(); it++) {
			out << " -c " << it->first << "=" << it->second;
		}

		// The grounder should be directed to the temp output location if we
		// are going to be sending it to the solver.
		if (run(TC_SOLVER))
			out << " >\"" << intGrdFile() << "\"";

		break;

	case TC_REACTIVE_BRIDGE:
		// The reactive client doesn't need to know much.
		// Just the ports to use and where to find the symbol table.

		// Note: Symbol table file provided through stdin.
		out << " --oclingo-port " << intConfigOpt(OPT_INT_PORT);
		out << " --client-port " << intConfigOpt(OPT_EXT_PORT);
		if (boolConfigOpt(OPT_NONE_HACK)) out << " --none-alias " << HACKED_NONE_VALUE;
		break;

	case TC_POSTPROC:
		if (boolConfigOpt(OPT_NONE_HACK)) out << " --none-alias " << HACKED_NONE_VALUE;
		break;
	}

	return out.str();
}

// Sets the configuration to run up to (and including) the provided tool.
bool Config::setRunTo(Toolchain tool) {
	bool conflict = false;

	for (int i = (int)TC_BEGIN; i < (int)tool+1; i++) {
		conflict |= run((Toolchain)i, true);
	}
	for (int i = ((int)tool)+1; i < (int)TC_END; i++) {
		conflict |= run((Toolchain)i, false);
	}
	return conflict;
}

// Sets the configuration to run from the provided tool.
bool Config::setRunFrom(Toolchain tool) {
	bool conflict = false;

	for (int i = (int)TC_BEGIN; i < (int)tool; i++) {
		conflict |= run((Toolchain)i, false);
	}
	for (int i = (int)tool; i < (int)TC_END; i++) {
		conflict |= run((Toolchain)i, true);
	}
	return conflict;
}

// Sets the configuration to run only the provided tool.
bool Config::setOnlyRun(Toolchain tool) {
	bool conflict = false;

	for (int i = (int)TC_BEGIN; i < (int)tool; i++) {
		conflict |= run((Toolchain)i, false);
	}
	conflict |= run(tool,true);
	for (int i = ((int)tool)+1; i < (int)TC_END; i++) {
		conflict |= run((Toolchain)i, false);
	}
	return conflict;
}

// Attempts to add a query to the list of known queries.
bool Config::addQuery(unsigned int queryID, std::string const& name, std::string const& cmd, unsigned int maxstep, unsigned int minstep) {
	bool unique = true;

	// ensure that the query is not already present...
	if (hasQuery(queryID)) unique = false;

	if (unique) {
		mQueries[queryID] = Query(queryID,name,cmd,minstep,maxstep);
	}

	return unique;
}

// Attempts to add a query to the list of known queries.
bool Config::addQuery(Query const& query) {
	bool unique = true;

	// ensure that the query is not already present...
	if (hasQuery(query.id)) unique = false;

	if (unique) {
		mQueries[query.id] = query;
	}

	return unique;
}



Config::FileType Config::addInput(std::string const& input) {

	char const* input_cstr = input.c_str();
	FileType type(false,TC_BEGIN, MODE_UNKNOWN);

	debug("Adding input file '%s'.", true, input.c_str());

	// Try to find the extension the file extension.
	size_t pos = input.find_last_of('.');
	if (pos == std::string::npos) {
		// No file extension to speak of, default to the beginning of the toolchain.
		mInputs[TC_BEGIN].push_back(input);
		return type;
	}

	// We found an extension, let's test it against known extensions
	checkExtension(&input_cstr[pos], type);

	if (type.known) {
		debug("Found the extension. It belongs to toolchain component '%d'", true, type.tool);
		mInputs[type.tool].push_back(input);
	} else {
		debug("Unknown extension.", true);
		// Default to the beginning of the toolchain if we don't know what it is.
		mInputs[TC_BEGIN].push_back(input);
	}


	return type;
}

/// Parses a maxstep specification.
std::pair<unsigned int, unsigned int> Config::parseMaxstep(std::string const& maxstep) {
	size_t pos;
	std::pair<unsigned int, unsigned int> ret(UNDEFINED, UNDEFINED);

	if ((pos = maxstep.find("..")) != std::string::npos) {
		// They've provided a range. Interpret it as a minstep and maxstep.
		if (!from_string(ret.first,maxstep.substr(pos+2))
				|| !from_string(ret.second,maxstep.substr(0,pos))) {
			ret.first = UNDEFINED;
			ret.second = UNDEFINED;
		}
	} else if (!from_string(ret.first,maxstep)) {
		ret.first = UNDEFINED;
	}

	return ret;
}

std::string Config::compileInputCommand(Toolchain tool) const {
	std::ostringstream out;

	// Otherwise, we need to aggregate all the input files
	// which belong to
	// a) The current tool,
	// b) The tools immediately preceeding the tool which we aren't running.

	for (int i = (int)tool; i >= (int)TC_BEGIN; i++) {
		// Only include files which haven't been included by a previous tool.
		if (i != (int)tool && run((Toolchain)i)) break;

		for (InputList::const_iterator it = beginInput(tool); it != endInput(tool); it++) {
			out << " " << *it;
		}
	}


	// Compile the input files from previous step's outputs.
	switch (tool) {
	case TC_END:
	case TC_REACTIVE_BRIDGE:
		// Reactive bridge is different.
		if (run(TC_TRANSLATOR)) {
			out << " " << intTransSymTabFile();
		}
		break;

	case TC_POSTPROC:
		if (run(TC_SOLVER)) {
			out << " " << intSoFile();
			break;
		}
		/* no break */

	case TC_SOLVER:
		if (run(TC_GROUNDER)) {
			out << " " << intGrdFile();
			break;
		}
		/* no break */

	case TC_GROUNDER:
		if (run(TC_PREPROC)) {
			out << " " << intPreprocFile();
			break;
		}
		/* no break */

	case TC_PREPROC:
		if (run(TC_TRANSLATOR)) {
			out << " " << intTransFile();
			break;
		}
		/* no break */

	case TC_TRANSLATOR:
		// none
		break;

	}


	return out.str();
}


Config::FileType& Config::checkExtension(char const* ext, FileType& out) const {
	char const* marker;

	out.known = true;
	out.runningMode = MODE_UNKNOWN;
	out.tool = TC_BEGIN;



	// Skip the period if they included it.
	if (ext[0] == '.') ext++;

	debug("Checking extension '%s'.", true, ext);

	
#line 691 "<stdout>"
	{
		char yych;
		unsigned int yyaccept = 0;

		yych = *ext;
		switch (yych) {
		case '\n':	goto yy2;
		case 'a':	goto yy5;
		case 'c':	goto yy3;
		case 'f':	goto yy8;
		case 'g':	goto yy10;
		case 'i':	goto yy7;
		case 'l':	goto yy9;
		case 'o':	goto yy6;
		case 's':	goto yy11;
		default:	goto yy12;
		}
yy2:
		ext = marker;
		switch (yyaccept) {
		case 0: 	goto yy4;
		case 1: 	goto yy34;
		case 2: 	goto yy59;
		case 3: 	goto yy85;
		}
yy3:
		++ext;
		switch ((yych = *ext)) {
		case '+':	goto yy82;
		case 'p':	goto yy84;
		default:	goto yy4;
		}
yy4:
#line 724 "Config.re2c"
		{ out.known = false; return out;}
#line 727 "<stdout>"
yy5:
		yyaccept = 0;
		yych = *(marker = ++ext);
		switch (yych) {
		case 'a':	goto yy54;
		case 'c':	goto yy57;
		case 'f':	goto yy56;
		case 'g':	goto yy53;
		case 'l':	goto yy55;
		case 's':	goto yy78;
		default:	goto yy4;
		}
yy6:
		yyaccept = 0;
		yych = *(marker = ++ext);
		switch (yych) {
		case 'a':	goto yy54;
		case 'c':	goto yy57;
		case 'f':	goto yy56;
		case 'g':	goto yy53;
		case 'l':	goto yy55;
		default:	goto yy4;
		}
yy7:
		yyaccept = 0;
		yych = *(marker = ++ext);
		switch (yych) {
		case 'a':	goto yy29;
		case 'c':	goto yy32;
		case 'f':	goto yy31;
		case 'g':	goto yy28;
		case 'l':	goto yy30;
		default:	goto yy4;
		}
yy8:
		yyaccept = 0;
		yych = *(marker = ++ext);
		switch (yych) {
		case '2':	goto yy24;
		default:	goto yy4;
		}
yy9:
		yych = *++ext;
		switch (yych) {
		case 'p':	goto yy22;
		default:	goto yy4;
		}
yy10:
		yyaccept = 0;
		yych = *(marker = ++ext);
		switch (yych) {
		case 'r':	goto yy19;
		default:	goto yy4;
		}
yy11:
		yyaccept = 0;
		yych = *(marker = ++ext);
		switch (yych) {
		case 'y':	goto yy13;
		default:	goto yy4;
		}
yy12:
		yych = *++ext;
		goto yy4;
yy13:
		yych = *++ext;
		switch (yych) {
		case 'm':	goto yy14;
		default:	goto yy2;
		}
yy14:
		yych = *++ext;
		switch (yych) {
		case 't':	goto yy15;
		default:	goto yy2;
		}
yy15:
		yych = *++ext;
		switch (yych) {
		case 'a':	goto yy16;
		default:	goto yy2;
		}
yy16:
		yych = *++ext;
		switch (yych) {
		case 'b':	goto yy17;
		default:	goto yy2;
		}
yy17:
		++ext;
#line 722 "Config.re2c"
		{ out.tool = TC_REACTIVE_BRIDGE; out.runningMode = MODE_REACTIVE; return out;}
#line 820 "<stdout>"
yy19:
		yych = *++ext;
		switch (yych) {
		case 'd':	goto yy20;
		default:	goto yy2;
		}
yy20:
		++ext;
#line 716 "Config.re2c"
		{ out.tool = TC_SOLVER; out.runningMode = MODE_STATIC_AUTO | MODE_STATIC_MANUAL; return out;}
#line 831 "<stdout>"
yy22:
		++ext;
#line 708 "Config.re2c"
		{ out.tool = TC_GROUNDER; out.runningMode = MODE_STATIC_AUTO | MODE_STATIC_MANUAL; return out;}
#line 836 "<stdout>"
yy24:
		yych = *++ext;
		switch (yych) {
		case 'l':	goto yy25;
		default:	goto yy2;
		}
yy25:
		yych = *++ext;
		switch (yych) {
		case 'p':	goto yy26;
		default:	goto yy2;
		}
yy26:
		++ext;
#line 704 "Config.re2c"
		{ out.tool = TC_PREPROC; out.runningMode = MODE_STATIC_AUTO | MODE_STATIC_MANUAL; return out; }
#line 853 "<stdout>"
yy28:
		yych = *++ext;
		switch (yych) {
		case 'r':	goto yy50;
		default:	goto yy2;
		}
yy29:
		yych = *++ext;
		switch (yych) {
		case 's':	goto yy47;
		default:	goto yy2;
		}
yy30:
		yych = *++ext;
		switch (yych) {
		case 'p':	goto yy45;
		default:	goto yy2;
		}
yy31:
		yych = *++ext;
		switch (yych) {
		case '2':	goto yy41;
		default:	goto yy2;
		}
yy32:
		yych = *++ext;
		switch (yych) {
		case '+':	goto yy35;
		case 'p':	goto yy33;
		default:	goto yy2;
		}
yy33:
		yyaccept = 1;
		yych = *(marker = ++ext);
		switch (yych) {
		case 'l':	goto yy37;
		default:	goto yy34;
		}
yy34:
#line 700 "Config.re2c"
		{ out.tool = TC_TRANSLATOR; out.runningMode = MODE_INCREMENTAL; return out;}
#line 895 "<stdout>"
yy35:
		++ext;
#line 702 "Config.re2c"
		{ out.tool = TC_TRANSLATOR; out.runningMode = MODE_INCREMENTAL; return out;}
#line 900 "<stdout>"
yy37:
		yych = *++ext;
		switch (yych) {
		case 'u':	goto yy38;
		default:	goto yy2;
		}
yy38:
		yych = *++ext;
		switch (yych) {
		case 's':	goto yy39;
		default:	goto yy2;
		}
yy39:
		++ext;
#line 701 "Config.re2c"
		{ out.tool = TC_TRANSLATOR; out.runningMode = MODE_INCREMENTAL; return out;}
#line 917 "<stdout>"
yy41:
		yych = *++ext;
		switch (yych) {
		case 'l':	goto yy42;
		default:	goto yy2;
		}
yy42:
		yych = *++ext;
		switch (yych) {
		case 'p':	goto yy43;
		default:	goto yy2;
		}
yy43:
		++ext;
#line 706 "Config.re2c"
		{ out.tool = TC_PREPROC; out.runningMode = MODE_INCREMENTAL; return out;}
#line 934 "<stdout>"
yy45:
		++ext;
#line 710 "Config.re2c"
		{ out.tool = TC_GROUNDER; out.runningMode = MODE_INCREMENTAL; return out;}
#line 939 "<stdout>"
yy47:
		yych = *++ext;
		switch (yych) {
		case 'p':	goto yy48;
		default:	goto yy2;
		}
yy48:
		++ext;
#line 714 "Config.re2c"
		{ out.tool = TC_GROUNDER; out.runningMode = MODE_INCREMENTAL; return out;}
#line 950 "<stdout>"
yy50:
		yych = *++ext;
		switch (yych) {
		case 'd':	goto yy51;
		default:	goto yy2;
		}
yy51:
		++ext;
#line 718 "Config.re2c"
		{ out.tool = TC_SOLVER; out.runningMode = MODE_INCREMENTAL; return out;}
#line 961 "<stdout>"
yy53:
		yych = *++ext;
		switch (yych) {
		case 'r':	goto yy75;
		default:	goto yy2;
		}
yy54:
		yych = *++ext;
		switch (yych) {
		case 's':	goto yy72;
		default:	goto yy2;
		}
yy55:
		yych = *++ext;
		switch (yych) {
		case 'p':	goto yy70;
		default:	goto yy2;
		}
yy56:
		yych = *++ext;
		switch (yych) {
		case '2':	goto yy66;
		default:	goto yy2;
		}
yy57:
		yych = *++ext;
		switch (yych) {
		case '+':	goto yy60;
		case 'p':	goto yy58;
		default:	goto yy2;
		}
yy58:
		yyaccept = 2;
		yych = *(marker = ++ext);
		switch (yych) {
		case 'l':	goto yy62;
		default:	goto yy59;
		}
yy59:
#line 697 "Config.re2c"
		{ out.tool = TC_TRANSLATOR; out.runningMode = MODE_REACTIVE; return out;}
#line 1003 "<stdout>"
yy60:
		++ext;
#line 699 "Config.re2c"
		{ out.tool = TC_TRANSLATOR; out.runningMode = MODE_REACTIVE; return out;}
#line 1008 "<stdout>"
yy62:
		yych = *++ext;
		switch (yych) {
		case 'u':	goto yy63;
		default:	goto yy2;
		}
yy63:
		yych = *++ext;
		switch (yych) {
		case 's':	goto yy64;
		default:	goto yy2;
		}
yy64:
		++ext;
#line 698 "Config.re2c"
		{ out.tool = TC_TRANSLATOR; out.runningMode = MODE_REACTIVE; return out;}
#line 1025 "<stdout>"
yy66:
		yych = *++ext;
		switch (yych) {
		case 'l':	goto yy67;
		default:	goto yy2;
		}
yy67:
		yych = *++ext;
		switch (yych) {
		case 'p':	goto yy68;
		default:	goto yy2;
		}
yy68:
		++ext;
#line 705 "Config.re2c"
		{ out.tool = TC_PREPROC; out.runningMode = MODE_REACTIVE; return out;}
#line 1042 "<stdout>"
yy70:
		++ext;
#line 709 "Config.re2c"
		{ out.tool = TC_GROUNDER; out.runningMode = MODE_REACTIVE; return out;}
#line 1047 "<stdout>"
yy72:
		yych = *++ext;
		switch (yych) {
		case 'p':	goto yy73;
		default:	goto yy2;
		}
yy73:
		++ext;
#line 713 "Config.re2c"
		{ out.tool = TC_GROUNDER; out.runningMode = MODE_REACTIVE; return out;}
#line 1058 "<stdout>"
yy75:
		yych = *++ext;
		switch (yych) {
		case 'd':	goto yy76;
		default:	goto yy2;
		}
yy76:
		++ext;
#line 717 "Config.re2c"
		{ out.tool = TC_SOLVER; out.runningMode = MODE_REACTIVE; return out;}
#line 1069 "<stdout>"
yy78:
		++ext;
		switch ((yych = *ext)) {
		case 'p':	goto yy80;
		default:	goto yy79;
		}
yy79:
#line 720 "Config.re2c"
		{ out.tool = TC_POSTPROC; out.runningMode = MODE_STATIC_AUTO | MODE_STATIC_MANUAL | MODE_INCREMENTAL; return out;}
#line 1079 "<stdout>"
yy80:
		++ext;
#line 712 "Config.re2c"
		{ out.tool = TC_GROUNDER; out.runningMode = MODE_STATIC_AUTO | MODE_STATIC_MANUAL; return out;}
#line 1084 "<stdout>"
yy82:
		++ext;
#line 696 "Config.re2c"
		{ out.tool = TC_TRANSLATOR; out.runningMode = MODE_STATIC_AUTO | MODE_STATIC_MANUAL | MODE_INCREMENTAL; return out;}
#line 1089 "<stdout>"
yy84:
		yyaccept = 3;
		yych = *(marker = ++ext);
		switch (yych) {
		case 'l':	goto yy86;
		default:	goto yy85;
		}
yy85:
#line 694 "Config.re2c"
		{ out.tool = TC_TRANSLATOR; out.runningMode = MODE_STATIC_AUTO | MODE_STATIC_MANUAL | MODE_INCREMENTAL; return out;}
#line 1100 "<stdout>"
yy86:
		yych = *++ext;
		switch (yych) {
		case 'u':	goto yy87;
		default:	goto yy2;
		}
yy87:
		yych = *++ext;
		switch (yych) {
		case 's':	goto yy88;
		default:	goto yy2;
		}
yy88:
		++ext;
#line 695 "Config.re2c"
		{ out.tool = TC_TRANSLATOR; out.runningMode = MODE_STATIC_AUTO | MODE_STATIC_MANUAL | MODE_INCREMENTAL; return out;}
#line 1117 "<stdout>"
	}
#line 725 "Config.re2c"


	return out;
}
