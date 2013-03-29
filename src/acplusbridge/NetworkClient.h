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


#pragma once

#include <cstdlib>
#include <string>
#include <list>
#include <mutex>

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/function.hpp>

/**
 * @brief A client wrapper in order to facilitate interaction with oClingo.
 * Based on the boost ASIO example provided here: 
 *          http://www.boost.org/doc/libs/1_39_0/doc/html/boost_asio/example/chat/chat_client.cpp
 */
class NetworkClient
{
public:

	/************************************************************************/
	/* Constants */
	/************************************************************************/

	static size_t const READ_BUFFER_SIZE;				///< The size of the read buffer.


private:
	/************************************************************************/
	/* Members */
	/************************************************************************/
	// io facilitators
  	boost::asio::io_service mIOService;						///< The service being used to communicate over the network.
  	boost::asio::ip::tcp::socket mSocket;					///< The socket being used to communicate over the network.
	boost::thread mIOThread;								///< The thread used ot drive the IO operations
    boost::asio::ip::tcp::resolver mResolver;				///< TODO
    boost::asio::ip::tcp::resolver::query mQuery;			///< TODO
    boost::asio::ip::tcp::resolver::iterator mEndpointIterator;		///< TODO

	// io buffers
  	std::list<std::string> mWriteBuf;						///< Buffer used to store messages that are waiting to be sent over the network.
	char* mReadBuf;											///< Buffer used to store the most recent message received.

	// io callback
	boost::function<void(char const* msg)> mCallback;		///< The method we're going to call to notify the superior code of a read.
	std::mutex mExternalMutex;								///< A mutex that is used to synchronize with the superior.

public:

	/************************************************************************/
	/* Constructors / Destructors */
	/************************************************************************/

	/**
	 * Initializes the client, binding it to the socket and prepping it to read/write.
	 * @param callback The function called whenever a message is received.
	 */
	inline NetworkClient(std::string const& hostname, std::string const& port, 
		boost::function<void(char const* msg)> callback)
    	: mIOService(), 
		  mSocket(mIOService),
		  mIOThread(boost::bind(&boost::asio::io_service::run, &mIOService)),
		  mResolver(mIOService),
		  mQuery(hostname.c_str(), port.c_str())
	{
		mEndpointIterator = mResolver.resolve(mQuery);
	  	mCallback = callback;

			// initialize buffers
		mReadBuf = new char[READ_BUFFER_SIZE];

		boost::asio::ip::tcp::endpoint endpoint = *mEndpointIterator;

		// Bind to port.
		mSocket.async_connect(endpoint,
			boost::bind(&NetworkClient::handler_connect, this,
			boost::asio::placeholders::error, ++mEndpointIterator));
	}
	
	/// Destructor. Closes the connection.
	inline ~NetworkClient() { close(); }

	/************************************************************************/
	/* Public Methods */
	/************************************************************************/
	
	/// Asynchronously writes a message to the socket.
	/// @param msg The message to write.
  	inline void write(std::string const& msg) {
  		mIOService.post(boost::bind(&NetworkClient::do_write, this, msg));
  	}

	/// Asynchronously closes the socket connection.
  	inline void close() {
    	mIOService.post(boost::bind(&NetworkClient::do_close, this));
    	mIOThread.join();
  	}

	/// Provides thread synchronization services by locking a mutex that must 
	/// be acquired by this object prior to calling the read callback.
	inline void lock() {
		mExternalMutex.lock();
	}

	/// Provides thread synchronization services by unlocking a mutex that must 
	/// be acquired by this object prior to calling the read callback.
	inline void unlock() {
		mExternalMutex.unlock();
	}

private:

	/************************************************************************/
	/* IO Handler Methods */
	/************************************************************************/

	/**
	 * @brief Handles an asynchronous request to connect to a server.
	 */
	void handler_connect(const boost::system::error_code& error,
      		boost::asio::ip::tcp::resolver::iterator endpoint_iterator);

	/**
	 * @brief Handles an asynchronous request to send a message over the network.
	 * @param msg The message to send.
	 */
  	void do_write(std::string const& msg);
  
	/**
	 * @brief Handles packets being received over the network asynchronously.
	 */
	void handler_read(const boost::system::error_code& error);

	/**
	 * @brief Handles writing out messages over the socket as it becomes available.
	 */
  	void handler_write(const boost::system::error_code& error);

	/**
	 * @brief Handles closing the socket and freeing associated resources asynchronously.
	 */
  	void do_close();

};


