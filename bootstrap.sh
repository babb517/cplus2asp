#! /bin/bash

# recursive bootstrapping
echo "Bootstrapping as2transition"

cd externals/as2transition
./bootstrap.sh noconf
cd ../..

echo "Bootstrapping cplus2asp"

# perform the bootstrap passing arguments to autoconf

if [ "$1" == "noconf" ]
then

	mkdir -p build-scripts && \
		aclocal && \
		autoheader && \
		automake --add-missing && \
		autoconf
else

	mkdir -p build-scripts && \
		aclocal && \
		autoheader && \
		automake --add-missing && \
		autoconf && \
		./configure "$@"
fi


