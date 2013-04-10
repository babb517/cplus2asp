#! /bin/bash

SCRIPT_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
CALL_PATH="$PWD"


# Make sure as2transition is there or try to get it.
if [ ! -e "$SCRIPT_PATH/externals/as2transition/bootstrap.sh" ]
then
	echo "Warning: The as2transition submodule has not been initialized." 1>&2
	echo "Attempting to initialize as2transition"
	if hash git 2>/dev/null
	then
		cd "$SCRIPT_PATH"
		git submodule init
		git submodule update
		cd "$CALL_PATH"

	else
		echo "Error: Failed to initialize as2transition. Git not found." 1>&2
		echo "Error: Please install Git and try again." 1>&2
	
	fi
fi

# recursive bootstrapping
if [ -e "$SCRIPT_PATH/externals/as2transition/bootstrap.sh" ]
then
	echo "Bootstrapping as2transition"
	cd "$SCRIPT_PATH/externals/as2transition"
	./bootstrap.sh noconf
	cd "$CALL_PATH"
else
	echo "Error: as2transition is required to run the cplus2asp toolchain." 1>&2
	echo "Error: Please download and install as2transition from 'https://github.com/babb517/as2transition'." 1>&2
fi


# perform the bootstrap 
echo "Bootstrapping cplus2asp..."
cd "$SCRIPT_PATH"
if [ "$1" == "noconf" ]
then

	mkdir -p build-scripts && \
		libtoolize && \
		aclocal && \
		autoheader && \
		automake --add-missing && \
		autoconf
else

	mkdir -p build-scripts && \
		libtoolize && \
		aclocal && \
		autoheader && \
		automake --add-missing && \
		autoconf && \
		./configure "$@"
fi
cd "$CALL_PATH"

