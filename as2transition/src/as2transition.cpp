/** @file as2transition.cpp
 *  @brief Transforms answer sets from answer set solvers into CCalc-style models.
 *  @author Joseph Babb (v1.8: Michael Casolary)
 *  @date 01/2013
 */

/* History:
 * v2.0 - Extended to allow for abnormality constants (staticAbnormality / dynamicAbnormality).
 * 		- Now uses four different top-level predicates to classify constant types.
 * 			- h/2 		- fluents
 * 			- occ/2 	- actions
 * 			- ab_h/2 	- static abnormalities
 * 			- ab_occ/2 	- dynamic abnormalities
 * 		- No longer requires fluent/1, actions/1, and rigid/1 predicates within the answer set.
 * v1.8 - Now exits with code 100 if no solutions are found, 101 if solutions are found, 1 if an error occurs, or 0 if there's nothing to do.
 * v1.7.3 - Fixed a bug where an unknown solver's output would be (erroneously) flagged as not having solutions due to bad text processing.
 * v1.7.2 - Optimized solution display routine, fixed extra space in solutions with no "timeless" predicates output, fixed bug where a solution with only actions wouldn't display properly.
 * v1.7.1 - Fixed a bug where bad time stamps could appear with "timeless" predicates.
 * v1.7 - Overhauled predicate detection, enabled support for new rigid and h-style predicate constructs, added option to show negated predicates.
 * v1.6.1 - Fixed bug where a time step with all false predicates would not be displayed.
 * v1.6 - Changed name to as2transition, added auto-hiding of "contribution" predicates  (and option to show them anyway).
 * v1.5 - Added capability to read output from cmodels and smodels in addition to clasp (& family), along with rudimentary ability to try to read an unknown/unidentified solver's output. Reduced memory usage and optimized handling of multiple solutions.
 * v1.4.1 - Fixed a bug with the program failing to recognize predicates beginning with "x_" inside of eq-style predicates.
 * v1.4 - Handling of eq-style predicates implemented, boolean predicates simplified, actions separated from fluents, option to print out solutions one predicate per line added.
 * v1.3.5 - (Internal) Split TimeStepInfo class off to its own file, created Predicate, Constant, and StringUtils classes, switched to using makefile to build program.
 * v1.3.1 - Program now outputs solutions as soon as they are ready to output instead of waiting until all solutions have been processed.
 * v1.3 - Added check for "x_" h-style predicates, and hide them by default. Added option to show these predicates anyway.
 * v1.2 - Added option controlling whether h-style predicates are added to solutions as a whole element or if their inner predicate is extracted and added alone.
 * v1.1 - Added support for newer clasp versions outputting "[UN]SATISFIABLE" at the end of the answer section, changed program version to explicitly store major, minor, revision.
 * v1.01 - Added version info.
 * v1.00 - First working version.
 */

#include <fstream>
#include <iostream>
#include <istream> // This and ostream are explicitly here to allow input and output regardless of source.
#include <list>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits> // for PATH_MAX, INT_MIN
#include <cstdlib> // for exit()
#include <cstring>
#include <unistd.h> // for realpath()

#include "TimeStepInfo.h"
#include "Predicate.h"
#include "StringUtils.h"

using namespace std;

// Program version.
#define VERSION_MAJOR 2
#define VERSION_MINOR 0
#define VERSION_REV 0

// Prototypes.
void nice_exit(int, const char*);
TimeStepInfo* getSolutionTimeStep(vector<TimeStepInfo*>&, int);
TimeStepInfo* makeSolutionTimeStep(vector<TimeStepInfo*>&, int);
bool addNewElement(vector<string>&, string&);
void processAndOutputAnswerSet(ostream&, size_t, vector<TimeStepInfo*>&, Config const& config);

/**
 * A wrapper for exit() that can output an optional custom message before leaving.
 * Outputs message to stdout if exitCode is 0, stderr otherwise. Doesn't output anything if message is NULL.
 * @param exitCode - The exit code to pass to exit.
 * @param message - A message to output to standard out before exiting (terminating newline automatically added).
 */
void nice_exit(int exitCode, const char* message)
{
	if(exitCode != 0 && message != NULL)
	{
		cerr << message << endl;
	}
	if(exitCode == 0 && message != NULL)
	{
		cout << message << endl;
	}
	exit(exitCode);
}

/**
 * Finds the correct TimeStepInfo object that is part of the current solution
 * and holds information about the predicates at timeStep.
 * @param predicates - A vector of all TimeStepInfo objects in the current solution.
 * @param timeStep - The desired time stamp to retrieve.
 * @return A pointer to the desired TimeStepInfo object, or NULL if no such object is found.
 */
TimeStepInfo* getSolutionTimeStep(vector<TimeStepInfo*>& predicates, int timeStep)
{
	TimeStepInfo *retVal = NULL;
	for(size_t i = 0; i < predicates.size(); i++)
	{
		if(predicates[i]->getTimeStep() == timeStep)
		{
			retVal = predicates[i];
		}
	}
	return retVal;
}

/**
 * Finds and returns the correct TimeStepInfo object for the given timeStep, or creates one if it doesn't already exist.
 * @param predicates - A vector of all TimeStepInfo objects the current solution.
 * @param timeStep - The desired time stamp to retrieve/create.
 * @return A pointer to the desired TimeStepInfo object. Exits if memory can't be allocated.
 */
TimeStepInfo* makeSolutionTimeStep(vector<TimeStepInfo*>& predicates, int timeStep)
{
	// Try to grab the time step from the existing data structure.
	TimeStepInfo *retVal = getSolutionTimeStep(predicates, timeStep);
	// If we don't have any info on that time step yet, make one and add it.
	if(retVal == NULL)
	{
		retVal = new TimeStepInfo();
		if(retVal == NULL)
		{
			nice_exit(1, "Error: Out of memory.");
		}
		retVal->setTimeStep(timeStep);
		// Put the new info in the right place so the predicates stay sorted by time step.
		vector<TimeStepInfo*>::iterator vIter = predicates.begin();
		while(vIter != predicates.end())
		{
			if((*vIter)->getTimeStep() < retVal->getTimeStep())
			{
				++vIter;
			}
			else
			{
				// We found where this time stamp belongs, break out of the loop.
				break;
			}
		}
		// We know where to put the new time stamp info now, do so.
		predicates.insert(vIter, retVal);
	}
	return retVal;
}

/**
 * Checks the contents of vec for value, and adds it alphabetically if it isn't found.
 * @param vec - A reference to the vector to manipulate.
 * @param value - The string to try to add to vec.
 * @return True if value got added, false if it was already there.
 */
bool addNewElement(vector<string> &vec, string &value)
{
	bool retVal = false; // Start pessimistic.
	int compareVal = 0;
	vector<string>::iterator vIter = vec.begin();
	vector<string>::iterator vIterEnd = vec.end();
	while(vIter != vIterEnd)
	{
		compareVal = (*vIter).compare(value);
		if(compareVal < 0)
		{	// Too early in the vector, move to next element.
			++vIter;
		}
		else if(compareVal == 0)
		{	// There's already a match in the vector, pop out.
			break;
		}
		else
		{	// Just arrived at the right spot to insert.
			vec.insert(vIter, value);
			retVal = true;
			break;
		}
	}
	if(vIter == vIterEnd)
	{	// We made it through the whole vector without finding a place to add the element, tack it on the end.
		vec.push_back(value);
		retVal = true;
	}
	return retVal;
}

/**
 * Given data structures containing information about a partially-processed answer set, performs final transformations and processing and outputs the result as a CCalc-style solution.
 * @param ostOut - The ostream used for outputting information, be that to stdout, a file, or elsewhere.
 * @param sztSolutionNum - Which solution this is (starts at #1).
 * @param vecPredicates - A vector of the predicates found in this answer set, arranged by time step.
 * @param config - The configuration details of the system.
 */
void processAndOutputAnswerSet(
		ostream &ostOut,
		size_t sztSolutionNum,
		vector<TimeStepInfo*> &vecPredicates,
		Config const& config
		)
{

	TimeStepInfo *tsiTempInfo;

	bool output;									// Whether our last operation actually output something...

	// Output the solution, formatted close to how CCalc might do it.
	// Everything has been sorted as we go, so we can just mow through our data structure.
	
	// Output solution number.
	ostOut << "Solution " << sztSolutionNum << ":" << endl << endl;

	// If it exists, find the "timeless" step and list its elements first:
	tsiTempInfo = getSolutionTimeStep(vecPredicates, Predicate::RIGID_TIME);

	if(tsiTempInfo != NULL)
	{
		output = tsiTempInfo->outputTimeStep(
				config,
				ostOut
		);

		if (output) ostOut << std::endl << std::endl;

	}

	// Go through the other time steps, outputting them in order.
	for(size_t j = 0; j < vecPredicates.size(); j++)
	{	// Make sure we don't accidentally output the "misc" time step yet, and that we don't accidentally output the "timeless" step again.
		if(vecPredicates[j]->getTimeStep() != Predicate::UNKNOWN_TIME && vecPredicates[j]->getTimeStep() != Predicate::RIGID_TIME)
		{
			output = vecPredicates[j]->outputTimeStep(
							config,
							ostOut
					);

			if (output) ostOut << std::endl << std::endl;
		}
	}

	// output the "misc" step if it's called for
	tsiTempInfo = getSolutionTimeStep(vecPredicates, Predicate::UNKNOWN_TIME);
	if (config.showUnformattedPredicates && tsiTempInfo) {
		std::cerr << "outputing misc step... \n";
		output = tsiTempInfo->outputTimeStep(
						config,
						ostOut
				);


	}

	// Done with this solution, add an extra separating end line.
	ostOut << endl << endl;
}

int main(int argc, char** argv)
{
	ifstream ifsFileIn;
	ofstream ofsFileOut;
	istream istIn(cin.rdbuf()); // Gets given a different buffer later.
	ostream ostOut(cout.rdbuf()); // Gets given a different buffer later.
	string strEXEName = "";
	string strInFile = "", strOutFile = "";
	ostringstream ossMetricsOut(""); // Records any metrics generated or found in input, to output after everything else.
	int intExitCode = 0; // What to exit with on successful program completion. 100 = No solutions, 101 = Solution(s) found.
	
	// The codes used to tell calling programs / the shell if we found solutions or not.
	enum ExitCodes { EXIT_NO_SOLUTIONS = 100, EXIT_SOLUTIONS = 101 };
	
	Predicate* predTemp = NULL;

	string strTempString = "", strTempInput = "", strTempPredicate = "";
	size_t sztTempPos = 0, sztFirstPos = 0;
	TimeStepInfo *tsiTempInfo = NULL; // Used to access & modify time step information.
	
	enum SolverType {SLVR_CLASP, SLVR_CMODELS, SLVR_SMODELS, SLVR_UNKNOWN}; // Tracks the best guess as to which solver's output is being processed.
	enum SolverType enmSolverType = SLVR_UNKNOWN; // Start assuming the solver is unknown.
	
	bool blnInAnswerSet = false; 				// Tracks if we're currently processing an answer set.
	bool blnEndOfAnswerSets = false; 			// If true, we believe there are no more answer sets to process (changes how remaining input is handled).

	Config config;								// Our current system configuration.

	char tmpPath[PATH_MAX];

	size_t sztSolutionNum = 0; // The number of the solution (answer set) currently being processed. 1-based (first solution is #1).
	
	// Vector of TimeStepInfo object pointers that will hold all the predicates true at given time points.
	vector<TimeStepInfo*> vecPredicates; 
	
	// Data structures to hold information about types of predicates.
	
	// Get the name this executable was called by (w/o the path, just the file name).
	if(argc > 0)
	{
		strEXEName = argv[0];
		sztTempPos = strEXEName.find_last_of('/');
		if(sztTempPos != string::npos)
		{
			strEXEName = strEXEName.substr(sztTempPos + 1); // Strip off any path to this executable.
		}
	}
	
	bool blnBadArgs = false; // Set to true if we get an unexpected or malformed command line argument.
	bool blnShowHelp = false; // Set to indicate that a request has been made to show the help dialog.
	if(argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			if(strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--all") == 0)
			{	// They want to see all positive predicates, let's show them all positive predicates.
				config.showContribPredicates = true;
				config.showUnformattedPredicates = true;
				config.showXPredicates = true;
			}
			else if(strcmp(argv[i], "-A") == 0 || strcmp(argv[i], "--ALL") == 0)
			{	// They want to see all predicates (positive and otherwise), unleash the hordes.
				config.showContribPredicates = true;
				config.showUnformattedPredicates = true;
				config.showXPredicates = true;
				config.showNegPredicates = true;
			}
			else if(strcmp(argv[i], "-contrib") == 0 || strcmp(argv[i], "--contrib-pred") == 0)
			{   // We're supposed to show the contribution predicates, do so.
				config.showContribPredicates = true;
			}
			else if(strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eq") == 0)
			{	// They want to stop us from auto-transforming eq predicates into CCalc-style representation.
				config.predFormat = Config::FMT_ORIGINAL;
			}
			else if(strcmp(argv[i], "-f") == 0)
			{	// Input file being specified.  Verify they actually gave us a file argument (and they haven't already given this option).
				if(i < argc-1 && strInFile == "") {
					i++;
					strInFile = argv[i];
				} else {
					blnBadArgs = true;
				}
			}
			else if(strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--line") == 0)
			{	// They want us to output each predicate on its own line.
				config.onePredPerLine = true;
			}
			else if(strcmp(argv[i], "-na") == 0 || strcmp(argv[i], "--no-actions") == 0)
			{	// They don't want actions grouped separately from fluents.
				config.separateActions = false;
			}
			else if(strcmp(argv[i], "-nab") == 0 || strcmp(argv[i], "--no-abnormalities") == 0)
			{	// They don't want abnormalities grouped separately from other constants.
				config.separateAbnormalities = false;
			}
			else if(strcmp(argv[i], "-neg") == 0 || strcmp(argv[i], "--negated") == 0)
			{	// They want to see negated predicates as well as normal ones.
				config.showNegPredicates = true;
			}
			else if(strcmp(argv[i], "-o") == 0)
			{	// Output file being specified.  Verify they actually gave us a file argument (and they haven't already given this option).
				if(i < argc-1 && strOutFile == "") {
					i++;
					strOutFile = argv[i];
				} else {
					blnBadArgs = true;
				}
			}
			else if(strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--strip") == 0)
			{	// They want to extract and display the inner predicates from h-style predicates.
				config.predFormat = Config::FMT_STRIP_PREFIX;
			}
			else if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0)
			{	// Show version information and quit.
				cout << strEXEName << " version " << VERSION_MAJOR;
				cout << "." << VERSION_MINOR;
				if(VERSION_REV > 0) { cout << "." << VERSION_REV; }
				cout << endl;
				nice_exit(0, NULL);
			}
			else if(strcmp(argv[i], "-x") == 0 || strcmp(argv[i], "--x-pred") == 0)
			{	// They want to see the intermediate "x_..." h-style predicates, so show them.
				config.showXPredicates = true;
			}
			else if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-?")) {
				// They've asked for help
				blnShowHelp = true;
			}
			else
			{
				// Unrecognized option. Hopefully this is a file.

				if (argv[i][0] != '-'
						&& strInFile == ""
						&& realpath(argv[i], tmpPath)) {
					// This is a file!
					strInFile = argv[i];

				} else {
					blnBadArgs = true;
				}
			}

			// If the user needs help, provide basic usage info and then exit.
			if(blnBadArgs || blnShowHelp)
			{
				if (blnBadArgs) std::cerr << "Error parsing command options.\n";
				cout << "Usage: " << strEXEName << " [OPTIONS] [-f IN_FILE] [IN_FILE] [-o OUT_FILE]" << endl
						  << "Transforms answer sets from answer set solvers into CCalc-style model lists." << endl
						  << "If given a value for IN_FILE, will parse that file, otherwise" << endl
						  << "will parse standard in (to support piping input)." << endl
						  << "If given a value for OUT_FILE, will output results to OUT_FILE," << endl
						  << "otherwise will output to standard out." << endl << endl
						  << "  -a  (or --all) causes " << strEXEName << " to display all positive" << endl
						  << "      predicates returned by the solver (vs. just the CCalc-equivalent ones)." << endl
						  << "  -A  (or --ALL) displays all predicates, positive and negative." << endl
						  << "  -e  (or --eq) stops " << strEXEName << " from transforming formatted" << endl
						  << "      eq or eql predicates (e.g., <prefix>(eq(p(x),v),t)) into CCalc-style " << endl
						  << "      representations (e.g., p(x)=v)." << endl
						  << "  -contrib (or --contrib-pred) will show formatted \"contribution\" and " << endl
						  << "      \"x_contrib\" predicates (usually these intermediate additive " << endl
						  << "      predicates are hidden)." << endl
						  << "  -l  (or --line) prints out each predicate on a separate line, with" << endl
						  << "      solution and time step headers also getting their own lines." << endl
						  << "  -na (or --no-actions) stops " << strEXEName << " from displaying" << endl
						  << "      action predicates separately." << endl
						  << "  -nab (or --no-abnormalities) stops " << strEXEName << " from displaying" << endl
						  << "      abnormality predicates separately." << endl
						  << "  -neg (or --negated) shows negated predicates (\"-x(y,z)\") alongside their" << endl
						  << "      normal counterparts (\"x(y,z)\")." << endl
						  << "  -s  (or --strip) will extract the inner predicate from formatted predicates," << endl
						  << "      displaying <prefix>(x(y,z),0) as x(y,z)." << endl
						  << "  -x  (or --x-pred) will show h-style predicates that begin with \"x_\"" << endl
						  << "      (these are usually additional intermediate predicates created during" << endl
						  << "      translation, and are hidden by default)." << endl
						  << "  --help shows this usage message." << endl
						  << "  -v  (or --version) outputs version information." << endl << endl
						  << "  Example: gringo some_asp_file.lp | clasp | " << strEXEName << endl
						  << "           would pass the answer sets generated by clasp directly" << endl
						  << "           to " << strEXEName << ", which would output the models to standard out." << endl
						  << "  Example: " << strEXEName << " -f answer_sets.txt -o models.txt" << endl
						  << "           would process the answer_sets.txt file and output the" << endl
						  << "           results to the file models.txt." << endl << endl << endl;
				if (blnBadArgs) nice_exit(1, NULL);
				else nice_exit(0, NULL);
			}
		}
	}
	
	// If an input or output file was given, make sure we have the full expanded path to it.
	char chrarrFullPath[PATH_MAX+1];
	char *chrptrPath = NULL;
	if(strInFile != "")
	{
		chrptrPath = realpath(strInFile.c_str(), chrarrFullPath);
		if(chrptrPath == NULL)
		{
			strTempString = "Error: Could not locate input file \"";
			strTempString += strInFile;
			strTempString += "\".";
			nice_exit(1, strTempString.c_str());
		}
		else
		{
			strInFile = chrarrFullPath;
		}
	}
	if(strOutFile != "")
	{
		// Since the output file may not exist yet, strip it and see if the rest of the location is good.
		sztTempPos = strOutFile.find_last_of('/');
		if(sztTempPos == string::npos)
		{ 
			strTempString = "."; // No slashes, so the directory of the output file is the current one.
		}
		else
		{
			strTempString = strOutFile.substr(0, sztTempPos); // There were slashes, so grab the directory path w/o the file name.
		}
		chrptrPath = realpath(strTempString.c_str(), chrarrFullPath);
		if(chrptrPath == NULL)
		{
			strTempString = "Error: Invalid location for output file \"";
			strTempString += strOutFile;
			strTempString += "\".";
			nice_exit(1, strTempString.c_str());
		}
		else
		{
			strTempString = chrarrFullPath;
			// Add the file name back on.
			if(strTempString.length() > 0 && strTempString[strTempString.length()-1] != '/')
			{	// Add back a forward slash if there isn't one already.
				strTempString += "/";
			}
			sztTempPos = strOutFile.find_last_of('/');
			if(sztTempPos == string::npos)
			{
				strTempString += strOutFile; // No slashes, just add on the file name.
			}
			else
			{
				strTempString += strOutFile.substr(sztTempPos+1); // Slashes, add on file name
			}
			strOutFile = strTempString;
		}
	}
	
	// Now we have the input & output files (if given), let's process the input!
	
	// Figure out which input source we'll be using.
	if(strInFile != "")
	{
		ifsFileIn.open(strInFile.c_str());
		if(!ifsFileIn)
		{
			strTempString = "Error: Unable to open input file \"";
			strTempString += strInFile;
			strTempString += "\".";
			nice_exit(1, strTempString.c_str());
		}
		istIn.rdbuf(ifsFileIn.rdbuf());
	}
	else
	{
		istIn.rdbuf(cin.rdbuf());
	}
	
	// Figure out which output source we'll be using.
	if(strOutFile != "")
	{
		ofsFileOut.open(strOutFile.c_str());
		if(!ofsFileOut)
		{
			strTempString = "Error: Unable to open output file \"";
			strTempString += strOutFile;
			strTempString += "\".";
			nice_exit(1, strTempString.c_str());
		}
		ostOut.rdbuf(ofsFileOut.rdbuf());
	}
	else
	{
		ostOut.rdbuf(cout.rdbuf());
	}
	
	// In a loop, go looking for an answer set from the input.
	while(getline(istIn, strTempInput))
	{
		// If we aren't sure which solver's output we're processing, check for hallmarks of certain specific answer set solvers.
		// If we can verify (or guess) which solver's output we're processing, remember that value for later reference.
		if(enmSolverType == SLVR_UNKNOWN)
		{
			if(strTempInput.find("clasp") != string::npos)
			{	// clasp identified itself, set that we're processing clasp output.
				enmSolverType = SLVR_CLASP;
			}
			else if(strTempInput.find("cmodels") != string::npos)
			{	// cmodels identified itself, set that we're processing cmodels output.
				enmSolverType = SLVR_CMODELS;
			}
			else if(strTempInput.find("smodels") != string::npos)
			{	// smodels identified itself, set that we're processing smodels output.
				enmSolverType = SLVR_SMODELS;
			}
		}
		// Based on which solver's output we think we're processing, try to find out if we've found an answer set or reached the end of the answer sets.
		// No need to go looking for answer sets if we already know there aren't any more.
		if(!blnEndOfAnswerSets)
		{
			if(enmSolverType == SLVR_CLASP)
			{	// clasp either outputs a line starting with "Models" or "[UN]SATISFIABLE" at the end of the answer sets.
				sztFirstPos = strTempInput.find("Models");
				if(sztFirstPos == string::npos)
				{	// Didn't find "Models", try finding "[UN]SATISFIABLE".
					sztFirstPos = strTempInput.find("SATISFIABLE");
				}
				if(sztFirstPos != string::npos)
				{	// End of answer sets
					blnEndOfAnswerSets = true;
				}
				// Don't start looking for answer sets if we've already established there are no more.
				if(!blnEndOfAnswerSets)
				{	// clasp needs no preprocessing for answer sets, answer sets are headered with "Answer: " followed by a number.
					sztFirstPos = strTempInput.find("Answer:");
					if(sztFirstPos != string::npos)
					{	// Found the header for an answer set, make sure that we have a line following this and start processing it.
						if(getline(istIn, strTempInput))
						{
							blnInAnswerSet = true;
						}
					}
				}
			}
			else if(enmSolverType == SLVR_CMODELS)
			{	// cmodels ends its section of answer sets with "No Answer Set", a "Number of loops" report, or just the end of input (which we can't check for here).
				sztFirstPos = strTempInput.find("No Answer Set");
				if(sztFirstPos != string::npos)
				{	// No solutions, by default we're at the end of the answer sets.
					blnEndOfAnswerSets = true;
				}
				sztFirstPos = strTempInput.find("Number of loops");
				if(sztFirstPos != string::npos)
				{	// cmodels just spat out what little info it gives, rewind that back into input and flag the end of answer sets.
					istIn.putback('\n'); // Put back implied newline.
					for(int i = (int)strTempInput.length() - 1; i >= 0; i--)
					{
						istIn.putback(strTempInput[i]);
					}
					blnEndOfAnswerSets = true;
				}
				// Don't start looking for answer sets if we've already established there are no more.
				if(!blnEndOfAnswerSets)
				{	// cmodels gives each answer set the header "Answer: " and a number, and prepends each answer set with "Answer set: "
					sztFirstPos = strTempInput.find("Answer:");
					if(sztFirstPos != string::npos)
					{	// Found the header for an answer set, make sure that we have a line following this and start processing it.
						if(getline(istIn, strTempInput))
						{
							sztFirstPos = strTempInput.find("Answer set:");
							if(sztFirstPos != string::npos)
							{
								strTempInput = strTempInput.substr(sztFirstPos + strlen("Answer set:")); // Remove the fluff header from the answer set line.
								blnInAnswerSet = true;
							}
						}
					}
				}
			}
			else if(enmSolverType == SLVR_SMODELS)
			{	// smodels ends its answer set section with either "True" or "False".
				sztFirstPos = strTempInput.find("True");
				if(sztFirstPos == string::npos)
				{	// Didn't find "True", try finding "False".
					sztFirstPos = strTempInput.find("False");
				}
				if(sztFirstPos != string::npos)
				{
					blnEndOfAnswerSets = true;
				}
				// Don't start looking for answer sets if we've already established there are no more.
				if(!blnEndOfAnswerSets)
				{	// smodels headers each answer set with "Answer: " and a number, and the answer set itself starts with "Stable Model:"
					sztFirstPos = strTempInput.find("Answer:");
					if(sztFirstPos != string::npos)
					{	// Found the header for an answer set, make sure that we have a line following this and start processing it.
						if(getline(istIn, strTempInput))
						{
							sztFirstPos = strTempInput.find("Stable Model:");
							if(sztFirstPos != string::npos)
							{
								strTempInput = strTempInput.substr(sztFirstPos + strlen("Stable Model:")); // Remove the fluff header from the answer set line.
								blnInAnswerSet = true;
							}
						}
					}
				}
			}
			else
			{	// Solver unknown, try to guess at when an answer set starts and when the answer sets are done.
				// Guessing approach for end of answer set section: any of the known ways the other solvers end their answer set sections, or end of input (which we don't check for here).
				// First, try finding "Models" (old clasp's way of ending the section).
				sztFirstPos = strTempInput.find("Models");
				if(sztFirstPos == string::npos)
				{	// Nothing yet, try finding "[UN]SATISFIABLE" (new clasp's method).
					sztFirstPos = strTempInput.find("SATISFIABLE");
				}
				if(sztFirstPos == string::npos)
				{	// Nothing yet, try finding "No Answer Set" (cmodels's method if there aren't any answer sets).
					sztFirstPos = strTempInput.find("No Answer Set");
				}
				if(sztFirstPos == string::npos)
				{	// Nothing yet, try finding "Number of loops" (one way cmodels ends its answer set section).
					sztFirstPos = strTempInput.find("Number of loops");
				}
				if(sztFirstPos == string::npos)
				{	// Nothing yet, try finding "True" (one possibility from smodels).
					sztFirstPos = strTempInput.find("True");
				}
				if(sztFirstPos == string::npos)
				{	// Nothing yet, try finding "False" (the other possibility from smodels).
					sztFirstPos = strTempInput.find("False");
				}
				if(sztFirstPos != string::npos)
				{	// Probably found the end of the answer sets one way or another, flag it.
					blnEndOfAnswerSets = true;
				}
				// Don't start looking for answer sets if we've already established there are no more.
				if(!blnEndOfAnswerSets)
				{
					// Answer set guessing approach: something like "Answer:" or containing "Model" as the header the line before the answer set, possibly with the answer set line beginning with some fluff that ends in a colon (:).
					sztFirstPos = strTempInput.find("Answer:");
					if(sztFirstPos == string::npos)
					{	// Didn't find "Answer:", try finding "Model" (but not "Models").
						sztFirstPos = strTempInput.find("Model");
						if(sztFirstPos != string::npos && sztFirstPos == strTempInput.find("Models"))
						{	// Found "Models" (probably some kind of statistics thing), most likely a false alarm.
							sztFirstPos = string::npos;
						}
					}
					if(sztFirstPos != string::npos)
					{	// Found a possible header for an answer set, make sure that we have a line following this and try processing it.
						if(getline(istIn, strTempInput))
						{	// Try to eliminate beginning fluff by eliminating anything that ends with a colon.
							sztFirstPos = strTempInput.find(":");
							if(sztFirstPos != string::npos)
							{
								strTempInput = strTempInput.substr(sztFirstPos + 1); // Try to remove any fluff header from the answer set line.
							}
							blnInAnswerSet = true;
						}
					}
				}
			}
		}
		// If an answer set was found, process it.
		if(blnInAnswerSet && !blnEndOfAnswerSets)
		{
			sztSolutionNum++; // Increment the solution count to the current number.

			// Now run through the answer set and grab all the predicates, putting them in their appropriate time stamp.
			strTempInput = StringUtils::trimWhitespace(strTempInput);
			do
			{
				// Get the next predicate, extract its info.
				sztFirstPos = StringUtils::findFirstWhitespace(strTempInput);
				strTempPredicate = strTempInput.substr(0, sztFirstPos);


				// extract the predicate
				predTemp = Predicate::makePredicate(strTempPredicate);

				// Add the predicate to the appropriate step
				tsiTempInfo = makeSolutionTimeStep(vecPredicates, predTemp->getTimeStamp());
				tsiTempInfo->addPredicate(predTemp);

				// Erase the predicate we just looked at, trim off any whitespace.
				if(sztFirstPos != string::npos)
					strTempInput = strTempInput.substr(sztFirstPos);
				else
					strTempInput = "";
				strTempInput = StringUtils::trimWhitespace(strTempInput);
			} while(strTempInput != "");

			// Send the gathered info on this answer set to the function that does some final processing and outputs the solution.
			processAndOutputAnswerSet(ostOut, sztSolutionNum, vecPredicates, config);
			blnInAnswerSet = false; 					// No longer processing an answer set, go back to base state.
			intExitCode = EXIT_SOLUTIONS; 				// We found at least one answer set, set our return code to "success".


			// clear out the old data to make room for (potential) new data.
			for(size_t i = 0; i < vecPredicates.size(); i++)
			{
				delete vecPredicates[i];
			}
			vecPredicates.clear();
		}

		// If we've reached the end of all answer sets, save any remaining lines of solver output as metrics/timing data to repeat verbatim.
		if(blnEndOfAnswerSets)
		{	// Trim whitespace, don't save blank lines.
			strTempInput = StringUtils::trimWhitespace(strTempInput);
			if(strTempInput.length() > 0)
			{
				ossMetricsOut << strTempInput << endl;
			}
		}


	}
	
	// If we were using a file as the input source, close it now that we're done with input.
	if(ifsFileIn)
	{
		ifsFileIn.close();
	}
	
	// Did we get any solutions? If not, output a message indicating so.
	if(intExitCode != EXIT_SOLUTIONS)
	{
		ostOut << "No solution." << endl << endl;
		intExitCode = EXIT_NO_SOLUTIONS; // We didn't find any answer sets, so return the "no solutions" exit code.
	}
	
	// Output any timing and model metrics we happened to find as the last bit of output.
	strTempString = ossMetricsOut.str();
	if(strTempString.length() > 0)
	{
		ostOut << strTempString << endl;
	}
	
	// If we were using a file as the output destination, close it now that we're done with output.
	if(ofsFileOut)
	{
		ofsFileOut.close();
	}
	
	return intExitCode;
}
