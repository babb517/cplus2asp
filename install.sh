#! /bin/sh
mkdir -p build-scripts && \
aclocal && \
autoheader && \
automake --add-missing && \
autoconf && \
./configure && \
make && \
make install
