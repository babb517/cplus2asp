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
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

#ifdef BOOST_TIMER
#include <boost/timer/timer.hpp>
#endif

#include <as2transition/TransitionFormatter.h>
#include <as2transition/TransitionPath.h>
#include <as2transition/Timestep.h>
#include <as2transition/Predicate.h>

#include "Driver.h"
#include "NetworkClient.h"

// The default port to attempt to connect to oClingo with.
std::string const Driver::DEF_OCLINGO_PORT("25277");

// The default host to attempt to connect to oClingo at.
std::string const Driver::DEF_OCLINGO_HOST("localhost");

// Main driver function.
int Driver::run() {

  try
  {

	std::cout 	<< "Entering user-interactive mode. " 																<< std::endl
				<< "NOTICE: The reactive bridge is in alpha and is not yet complete." 								<< std::endl
				<< "It's currently required that the user provide input directly in the input language of oClingo." << std::endl
				<< "Valid oClingo input consists of four components:" 												<< std::endl
				<< "    - A step declaration '#step t.' where t is a positive integer. "							<< std::endl
				<< "      This specifies the current step."															<< std::endl
				<< "    - A number of facts specifying the abnormality constants that have occurred."				<< std::endl
				<< "      This should be of one of the forms:"														<< std::endl
				<< "              'ab_h(<static-abnormality>, t).' OR"												<< std::endl
				<< "              'ab_occ(<dynamic-abnormality>,t-1).'"												<< std::endl
				<< "      where t is the step provided in the step declaration."									<< std::endl
				<< "    - A line containing only '#endstep.' specifying the end of input. "							<< std::endl
				<< "When you're finished, you should input 'exit' on a line by itself."								<< std::endl;

    mClient = new NetworkClient(
		mHost, 
		mPort, 
		boost::bind(&Driver::processOclingoPacket, this, _1, _2, _3));

	boost::this_thread::sleep( boost::posix_time::milliseconds(200));

	if (!mClient->open()) {
		std::cerr << "Error: Could not connect to oClingo at '" << mHost << ":" << mPort << "'.\n";
		close(1);
	}

    std::string line;
	std::stringstream cmd, tmp;

//  Providied by initial oClingo prompt.
//	std::cout << "?- ";

	size_t step = 0, pos;
	bool validStep = false;

    while (!mClosing && mClient->open() && std::getline(std::cin, line))
    {
		if ((pos = line.find("#step") != std::string::npos)) {

			if (validStep) {
				std::cerr << "Warning: Ignoring duplicate step declaration.\n";
			} else {

				tmp.str("");
				tmp << line.substr(pos + strlen("#step"), line.find('\n', pos));
				tmp >> step;
	
				if (tmp.good()) {
					validStep = true;
				} else {
					std::cerr << "Warning: Ignoring invalid step declaration.\n";
					tmp.str("");
					tmp.clear();
				}
			}

			std::cout << "?- ";

		} else {

			if (line == "#endstep.") {
				send(cmd.str(), step);
				step = 0;
				validStep = false; 
				cmd.str("");
			} else if (line == "#stop." || line == "exit") {
				mClosing = true;
				send(cmd.str(), step, true);
				step = 0;
				validStep = false;
				cmd.str("");
				close(0);
			} else {
				if (!validStep) {
					std::cerr << "Error: Input must begin with a '#step' declaration.\n"; 
					std::cerr << "Warning: Ignoring invalid input.\n";
				} else {
					cmd << line << std::endl;
				}
				std::cout << "?- ";
			}
		}

		// mClient->write(line, false); // line == "#endstep.");
    }

	close(0);
  }
  catch (std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
	return 1;
  }
	return 0;
}

// Processes a packet received by oclingo.
void Driver::processOclingoPacket(boost::system::error_code const& error, char const* msg, size_t length) { 
	std::string strmsg(msg, length), tmp;
	size_t pos;

	if (!error) {

		if (((pos = strmsg.find("Step:")) != std::string::npos) 
				|| ((pos = strmsg.find("Input:")) != std::string::npos)) {
			if (( pos = strmsg.find('\n', pos)) != std::string::npos && pos < strmsg.size())
				strmsg = strmsg.substr(pos+1);
			else
				strmsg = "";
			mOclingoOut << std::endl;
			displayTransition(mOclingoOut, std::cout);
			mOclingoOut.str("");
		}
		

		if ((pos = strmsg.find("End of Step.")) == std::string::npos)
			mOclingoOut << strmsg;
		else {
			tmp = strmsg.substr(0,pos);
			mOclingoOut << tmp << std::endl;
			displayTransition(mOclingoOut, std::cout);

			// Start collecting the next answer set.
			mOclingoOut.str("");
			pos += strlen("End of Step.");
			if (pos <= strmsg.size())
				mOclingoOut << strmsg.substr(pos);
		}
	

	} else if (!mClosing) {
		std::cerr << "The connection to oClingo has been closed remotely.\n";
		close(1);
	}

	if (mClosing) {
		std::cout << "Finished." << std::endl;
		close(0);
	}
//	int stat = system(tmpCmd.c_str());

} 

// Closes the active connections and exits.
void Driver::close(int code) {
	mClosing = true;	
	mClient->close();
	exit(code);
}
// Sends a message to oClingo.
void Driver::send(std::string const& msg, size_t step, bool stop) {
	as2transition::Timestep *st;
	std::stringstream tmp;


	if (msg.size() || step) {
		tmp << "#step " << step << ".\n";
	}

	if (mPlan && mEnforceHistory) {
		for (; mLastStep < step && mLastStep < mPlan->length(); mLastStep++) {
//			tmp << "#step " << mLastStep + 1 << ".\n";
			if ((st = mPlan->step(mLastStep))) {
				for (as2transition::Timestep::const_iterator it = st->beginActions(); it != st->endActions(); it++) {
				//	if ((*it)->type() != T_CONTRIB)
						tmp << ":- not " << **it << ".\n";
				}
			
			}
//			if (++mLastStep < step && mLastStep < mPlan->length())
//				tmp << "#endstep.\n";
		}
	}
	

	tmp << msg << std::endl;

	if (stop) {
		tmp << "#stop.\n";
	} else {
		tmp << "#endstep.\n";
	}

	std::cout << "Sending: '" << tmp.str() << "'." << std::endl;

	mClient->write(tmp.str(), true);
#ifdef BOOST_TIMER
	mTimer = boost::timer::cpu_timer();
	mTimer.start();
#endif


}

// Displays a transition to the user.
void Driver::displayTransition(std::istream& in, std::ostream& out) {


#ifdef BOOST_TIMER
	boost::timer::cpu_times time = mTimer.elapsed();
#endif

	if (mPlan) delete mPlan;
	mPlan = mFormatter.format(in);

	if (mPlan->length()) {
		mPlan->output(out);

#ifdef BOOST_TIMER
		if (mShowTime) {
			out << boost::timer::format(time, 4, "Elapsed time: %w") << "\n";
		}
#endif

		out << "?- ";
		out.flush();
	}


}
