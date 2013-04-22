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
 * @file main.cpp
 * @brief Contains main program logic for the CPlus2ASP translator.
 * @author Joseph Babb (V1: Michael Casolary)
 * @date 1/2013
 */

/* History:
 *   3.0 - Full support for symbol table.
 *       - Full support for the language BC.
 *   2.0 - Incremental translation for C+ programs.
 *       - Support for the language aC+.
 *       - Partial implementation of symbol table output.
 *       - Better options for controlling return values for scripting.
 *       - Major changes to translation routines to fix numerous bugs.
 *       - Enhanced support for CCalc input language.
 *       - Some experimental BC features.
 * <v2.0 - Release
 *       - Fixed a number of bugs in the existing translation.
 *       - Added support for abnormal C+ constructs ('staticAbnormality', 'dynamicAbnormality', 'when', 'following').
 *       - Simplified standard file.
 *       - Added support for the 'assuming' clause.
 *       - Added support for the 'strong_noconcurrency' statement.
 *       - Now returns a status with bit 0x80 set if abnormality constants were encountered.
 *       - Now returns a status with bit 0x40 set if additive constants were encountered.
 * <v1.0 - Beta development.
 * <v0.8 - Alpha development.
 */

#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>
#include "IncludeHandler.h"
#include "lexerTokenStream.h"
#include "MacroParser.h"
#include "parser.h"
#include "Translator.h"
#include "ltsglobals.h"
#include "flexer.h"

#define VERSION_MAJOR 3
#define VERSION_MINOR 0
#define VERSION_REV 0


#define STATUS_FOUND_ABS_MASK 0x80		///< Return code indicating that the translation was successful and abnormality constants were found.
#define STATUS_FOUND_ADD_MASK 0x40		///< Return code indicating that the translation was successful and additive constants were found.
#define STATUS_OK			  0x00		///< Return code indicating that the translation was successful.
#define STATUS_BAD			  0x01		///< Return code indicating that something went wrong during translation.


#ifndef PATH_MAX
  #define PATH_MAX 4096
#endif

extern Translator mainTrans; ///< The core translating module for the program, declared in the parser.

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
		std::cerr << message << std::endl;
	}
	if(exitCode == 0 && message != NULL)
	{
		std::cout << message << std::endl;
	}
	exit(exitCode);
}

/**
 * Main program function.
 * Collects and processes command-line arguments, invokes lexer & parser
 * on given input file(s), outputs translated results.
 * @param argc - The number of arguments (incl. program name) passed to the program.
 * @param argv - The command-line arguments passed to the program.
 * @return 0 if all translation was successful, 1 if at least part of the translation failed.
 */
int main(int argc, char *argv[])
{
	std::string strEXEName = "";
	std::vector<std::string> inFiles;
	std::string outFile = ""; // If not black, specifies a file to send translated output to.
	bool errorToOutput = false; // If true, will also output error messages wherever normal output is going.
	bool staticTrans = false;	// If true, this will set the translator to output a static translation, rather than an incremental/dynamic one.
	bool expressiveReturn = false;	// If true, will enable flags in the return value to indicate what (if any) special constants were found.
	std::string symbolTableFile = "";
	char chrarrFullPath[PATH_MAX+1]; // Used to temporarily hold paths to input files.
	char *chrptrPath = NULL; // Used to capture the results from realpath.
	std::ofstream ofsFileOut; // Used if output is being sent to a file.
	std::ofstream ofsSymTabOut; // Used if the symbol table is being sent to a file.
	std::ostream ostOut(std::cout.rdbuf());
	
	IncludeHandler includeHandler; //parser for handling include statements, called before the macro parser.
	MacroParser macroParser; // Specialized parser for handling macros, called before the main parser.
	
	std::string strTempString = "";
	
	bool ltsAddResult;
	std::ostringstream ossStatus;
	int returnStatus = 0; // Start optimistic.
	

	// Get the name this executable was called by (w/o the path, just the file name).
	if(argc > 0)
	{
		size_t tempPos;
		strEXEName = argv[0];
		tempPos = strEXEName.find_last_of('/');
		if(tempPos != std::string::npos)
		{
			strEXEName = strEXEName.substr(tempPos + 1); // Strip off any path to this executable.
		}
	}
	
	// Process command-line arguments.
	bool blnBadArgs = false; // Set to true if we get an unexpected or malformed command line argument.
	bool blnShowHelp = false; // Set to true if the user passes "--help" to the program as an argument.
	if(argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			if(strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output-file") == 0)
			{	// An output file has (hopefully) been specified, remember it.
				if(i + 1 < argc)
				{
					i++;
					outFile = argv[i];
				}
				else
				{
					blnBadArgs = true; // Set up for receiving an argument but none given, bad command line.
				}
			}
			else if(strcmp(argv[i], "-O") == 0 || strcmp(argv[i], "--output-all") == 0)
			{	// An output file has (hopefully) been specified, remember it.
				if(i + 1 < argc)
				{
					i++;
					outFile = argv[i];
					errorToOutput = true; // Also redirect error output there.
				}
				else
				{
					blnBadArgs = true; // Set up for receiving an argument but none given, bad command line.
				}
			}
			else if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0)
			{	// Show version information and quit.
				std::cout << strEXEName << " version " << VERSION_MAJOR;
				std::cout << "." << VERSION_MINOR;
				if(VERSION_REV > 0) { std::cout << "." << VERSION_REV; }
				std::cout << std::endl;
				nice_exit(0, NULL);
			}
			else if(strcmp(argv[i], "-?") == 0 || strcmp(argv[i], "--help") == 0)
			{	// They need help, give them help.
				blnShowHelp = true;
			}
			else if(strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--static") == 0)
			{	// They want to use the static translation (sadly). We should give it to them.
				staticTrans = true;
			}
			else if (!strcmp(argv[i], "-e") || !strcmp(argv[i], "--expressive-return"))
			{	// They want us to return flags to them indicating the presence of special constants.
				expressiveReturn = true;
			}
			else if (!strcmp(argv[i], "-t") || !strcmp(argv[i], "--symbol-table"))
			{	// They want us to output our symbol table after we're done with it.
				// An output file has (hopefully) been specified, remember it.
				if(i + 1 < argc)
				{
					i++;
					symbolTableFile = argv[i];
				}
				else
				{
					blnBadArgs = true; // Set up for receiving an argument but none given, bad command line.
				}
			}
			else if (!strcmp(argv[i], "-l")) 
			{
				if(i + 1 < argc)
				{
					i++;
					Translator::Language l;
					if (Translator::strToLanguage(argv[i], l))
						mainTrans.lang(l);
					else
						blnBadArgs = true;
				}
				else
				{
					blnBadArgs = true; // Set up for receiving an argument but none given, bad command line.
				}

			}
			else if (!strncmp(argv[i], "--language=", strlen("--language="))) 
			{
				Translator::Language l;
				if (Translator::strToLanguage(argv[i] + strlen("--language="), l))
					mainTrans.lang(l);
				else
					blnBadArgs = true;

			}
			else
			{	// If there's no "header", it's probably an input file.
				// If it's not a number, it's probably an input file. Make sure it exists, and then save it to the list.
				chrptrPath = realpath(argv[i], chrarrFullPath);
				if(chrptrPath == NULL)
				{
					// If realpath didn't give us a result, it might be a bad arg. Check if it starts with a dash (-).
					if(argv[i][0] == '-')
					{   // Starts with a dash, probably a bad argument.
						blnBadArgs = true;
					}
					else
					{   // Didn't start with a dash, so it's probably just a bad input file.
						strTempString = "Error: Could not locate input file \"";
						strTempString += argv[i];
						strTempString += "\".";
						nice_exit(1, strTempString.c_str());
					}
				}
				else
				{
					std::string tempStr = std::string(chrarrFullPath);
					inFiles.push_back(tempStr);
					chrptrPath = NULL; // We don't need it, null it back out.
				}
			}
			// If the user needs help, provide basic usage info and then exit.
			if(blnShowHelp || blnBadArgs)
			{
				if (blnBadArgs) std::cerr << "Error parsing command options.\n";
				std::cout << "Usage: " << strEXEName << " [OPTIONS] INPUT_FILES" << std::endl
						<< "Translates CCalc files into f2lp input and outputs the resuts." << std::endl
						<< "  OPTIONS are optional arguments that change the program's behavior." << std::endl
						<< "  INPUT_FILES is a series of one or more CCalc source files." << std::endl
						<< std::endl
						<< "Normal Program Options:" << std::endl
						<< "  -s" << std::endl
						<< "  --static ------------ Outputs a static translation of the CCalc source file," << std::endl
						<< "                        rather than an incremental translation suitable " << std::endl
						<< "                        for i/oClingo." << std::endl
						<< std::endl
						<< "  -o PATH" << std::endl
						<< "  --output-file PATH -- Outputs the translated f2lp code to the file at PATH " << std::endl
						<< "                        instead of the default (standard out)." << std::endl
						<< "  -O PATH" << std::endl
						<< "  --output-all PATH --- Outputs both the translated f2lp code and any" << std::endl
						<< "                        translation error messages to the file at PATH." << std::endl
						<< std::endl
						<< "  -e" << std::endl
						<< "  --expressive-return - Enables the use of flag bits in the return value to" << std::endl
						<< "                        indicate the presence of special constants. Bit 0x80" << std::endl
						<< "                        will be set to indicate that abnormality constants are" << std::endl
						<< "                        present. Similarly, bit 0x40 will be set for additive" << std::endl
						<< "                        constants." << std::endl
						<< std::endl
						<< "  -t PATH" << std::endl
						<< "  --symbol-table PATH - Causes the translator to output its symbol table to PATH" << std::endl
						<< "                        after execution has finished." << std::endl
						<< std::endl
						<< "  -l <LANG>" << std::endl
						<< "  --language=<LANG>  -- Sets the input language accepted by the translator to <LANG>." << std::endl
						<< "                        <LANG>: c+, bc" << std::endl
						<< std::endl
						<< "  --help shows this usage information." << std::endl
						<< "  -v" << std::endl
						<< "  --version outputs the program's version information." << std::endl;
				if (blnBadArgs) nice_exit(1, NULL);
				else nice_exit(0, NULL);
			}
		}
	}
	
	// Initialize the translator.
	if(outFile != "")
	{
		ofsFileOut.open(outFile.c_str());
		if(ofsFileOut.fail())
		{
			strTempString = "Error: Could not create output file \"";
			strTempString += outFile;
			strTempString += "\".";
			nice_exit(1, strTempString.c_str());
		}
		else
		{
			ostOut.rdbuf(ofsFileOut.rdbuf());
		}
	}
	else
	{
		ostOut.rdbuf(std::cout.rdbuf());
	}
	mainTrans.setOutput(ostOut);
	if(errorToOutput)
	{
		mainTrans.setErrorOutput(ostOut);
	}
	else
	{
		mainTrans.setErrorOutput(std::cerr);
	}
	mainTrans.setStaticTranslation(staticTrans);

	ltsyyLexer::initLexer(); // Initialize the lexer emulator.
	
	// For each file:
	// - Set up the real flexer, but then have the lexer emulator load the tokens into its own data structures.
	// Once all files are loaded:
	// - Call the macro parser on the aggregate input.
	// - Call the real parser on the results.
	for(unsigned int i = 0; i < inFiles.size(); i++)
	{
		flexerReset();
		flexin = fopen(inFiles[i].c_str(), "r");
		if(flexin != NULL)
		{
			ossStatus.str("");
			flexerFileName = inFiles[i];
			// Add a comment to the beginning of the file indicating where it starts.
			Comment* fileCom = new Comment();
			fileCom->contents = "";
			fileCom->contents += " File \"";
			fileCom->contents += inFiles[i];
			fileCom->contents += "\".";
			fileCom->fileName = inFiles[i];
			fileCom->loc->first_line = 0;
			fileCom->loc->first_column = 0;
			fileCom->loc->last_line = 0;
			fileCom->loc->last_column = 0;
			std::list<Comment*>* tempComments = ltsyyLexer::getFileComments(inFiles[i]);
			tempComments->push_front(fileCom);
			// Call static method that automatically invokes yylex() and adds a file's tokens into the emulator's token stream.
			ltsAddResult = ltsyyLexer::lexAppendToTokenStream(flexlex, flextext, flexleng, yyxlval, yyxlloc, flexeryylvalType, flexerFileName);
			fclose(flexin);
			if(!ltsAddResult)
			{
				ossStatus << "% Error loading file \"" << inFiles[i] << "\".";
				mainTrans.error(ossStatus.str(), true);
				ossStatus.str("");
				returnStatus = 1; // Return that we failed to load everything.
			}
		}
		else
		{
			ossStatus << "% Error: Could not open file \"" << inFiles[i] << "\".";
			mainTrans.error(ossStatus.str(), true);
			ossStatus.str("");
			returnStatus = 1; // Return that we failed to load everything.
		}
	}
	/// @todo Add ":- include ..." parser call here.
	// If all the files loaded successfully, call the macro parser and the real parser.
	if(returnStatus == 0)
	{

		// First, handle the include statements
		includeHandler.includeNumErrors = 0;//reset include handler's error counter.

		returnStatus = includeHandler.handleInclude(flexlex, flextext, flexleng, yyxlval, yyxlloc, flexeryylvalType);
		//intParseResult = includeHandler.handleInclude();
		if(returnStatus != 0)
		{
			ossStatus << "% Failed to parse file \"" << includeHandler.includeFileName << "\", " << includeHandler.includeNumErrors << (includeHandler.includeNumErrors == 1 ? " error" : " errors") << " encountered before failure.";
			mainTrans.error(ossStatus.str(), true);
			ossStatus.str("");
		}
		else
		{
			// The include handler finished successfully, call the macro parser now
			// First, grab any macros and try using any macros found so far.
			//ltsyyLexer::restartLexer();
			//ltsyynerrs = 0;
			macroParser.macroNumErrors = 0; // Reset macro parser's error counter.
			returnStatus = macroParser.parseMacros();
			if(returnStatus != 0)
			{
				ossStatus << "% Failed to parse file \"" << macroParser.macroFileName << "\", " << macroParser.macroNumErrors << (macroParser.macroNumErrors == 1 ? " error" : " errors") << " encountered before failure.";
				mainTrans.error(ossStatus.str(), true);
				ossStatus.str("");
			}
			else
			{
				// The macro parser finished successfully, call the real parser (even if the macro parser had errors).
				ltsyyLexer::restartLexer();
				ltsyynerrs = 0;
				mainTrans.translatorNumErrors = 0;
				mainTrans.translatorNumWarnings = 0;

				returnStatus = ltsyyparse();
				int totalNumErrors = ltsyynerrs + macroParser.macroNumErrors + mainTrans.translatorNumErrors; // Add together the number of errors everything has encountered.
				int totalNumWarnings = mainTrans.translatorNumWarnings;

				if(returnStatus != 0)
				{
					ossStatus << "% Failed to parse file \"" << ltsyyFileName << "\", " << totalNumErrors << (totalNumErrors == 1 ? " error" : " errors") << " encountered before failure.";
					mainTrans.error(ossStatus.str(), true);
					ossStatus.str("");
				}
				else
				{

					if(totalNumWarnings > 0)
					{
						ossStatus << "Encountered " << totalNumWarnings << (totalNumWarnings == 1 ? " warning" : " warnings") << " parsing input.";
						mainTrans.pragma(ossStatus.str(), true, false);
						ossStatus.str("");
					}

					// If either parser had a nonzero error count, report that something went wrong during translation.
					if(totalNumErrors > 0)
					{
						ossStatus << "Encountered " << totalNumErrors << (totalNumErrors == 1 ? " error" : " errors") << " parsing input.";
						mainTrans.pragma(ossStatus.str(), true, false);
						ossStatus.str("");
					}

					returnStatus = (totalNumErrors > 0) ? STATUS_BAD : STATUS_OK;
					if (mainTrans.hasFoundAbnormalities() && expressiveReturn) returnStatus |= STATUS_FOUND_ABS_MASK;
					if (mainTrans.hasFoundAdditiveConstants() && expressiveReturn) returnStatus |= STATUS_FOUND_ADD_MASK;

					if (symbolTableFile != "") {
						// Dump the symbol table to the file...
						ofsSymTabOut.open(symbolTableFile.c_str(), std::ios_base::trunc | std::ios_base::out);

						if (ofsSymTabOut.fail()) {
							// opening the file failed. Throw a warning
							ossStatus << "Unable to output the symbol table. Failed to open the output file '" << symbolTableFile << "'.";
							mainTrans.error(ossStatus.str(), true);
							ossStatus.str("");

						} else {
							mainTrans.outputSymbolTable(ofsSymTabOut);
							ofsSymTabOut.close();
						}
					}

				}
			}
		}
	}
	
	ltsyyLexer::initLexer(); // "Initialize" the lexer to clear out the last set of tokens etc. from memory.
	
	inFiles.clear(); // Clear out the contents of inFiles, it's not needed anymore.
	
	if(outFile != "")
	{
		ofsFileOut.close();
	}
	
	return returnStatus;
}
