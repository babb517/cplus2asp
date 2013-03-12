#! /bin/sh
mkdir -p build-scripts && 
aclocal &&
autoheader &&
automake --add-missing &&
autoconf
