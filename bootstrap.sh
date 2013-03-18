

if [ "$1" == "debug" ]
then
	#! /bin/sh
	mkdir -p build-scripts && \
	aclocal && \
	autoheader && \
	automake --add-missing && \
	autoconf && \
	./configure --enable-debug 
else

	#! /bin/sh
	mkdir -p build-scripts && \
	aclocal && \
	autoheader && \
	automake --add-missing && \
	autoconf && \
	./configure 
fi
