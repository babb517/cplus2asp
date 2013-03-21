#! /bin/bash

# perform the bootstrap passing arguments to autoconf
mkdir -p build-scripts && \
aclocal && \
autoheader && \
automake --add-missing && \
autoconf && \
./configure "$@"
