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
 * @brief Contains the primary driver for the acplusbridge which provides a CCalc like interface to oClingo's online progression.
 * @author Joseph Babb
 * @date 3/2013
 */

/* History:
 * <v0.1 - Alpha development.
 */

#include <iostream>
#include <string>

#include "NetworkClient.h"
#include "boost/bind.hpp"

#define VERSION_MAJOR 0
#define VERSION_MINOR 1
#define VERSION_REV 0


/**
 * @brief Displays the help dialog/
 * @param out The output stream to write the help dialog to.
 */
void showHelp(std::ostream& out);

/**
 * Processes a packet received by oclingo.
 * @param msg The packet that was received.
 */
void processOclingoPacket(char const* msg); 

int main(int argc, char const* argv[])
{
  try
  {
	// TODO: Command line options
    if (argc != 3)
    {
     	std::cerr << "Usage: '" << argv[0] << "' <host> <port>\n";
      	return 1;
    }


    NetworkClient client(argv[1], argv[2], boost::function<void(char const*)>(&processOclingoPacket));


    std::string input;
    while (std::getline(std::cin, input))
    {
		// Just send it straight to oClingo
		// TODO
		client.write(input + "\0");
    }

    client.close();
  }
  catch (std::exception& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}

// Displays the help dialog/
void showHelp(std::ostream& out) {
	// TODO
}

// Processes a packet received by oclingo.
void processOclingoPacket(char const* msg) {
	// Pipe it straight to the user for now
	// TODO
	std::cout << msg;
} 
