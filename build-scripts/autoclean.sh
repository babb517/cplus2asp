# Simple Script file for cleaning up autoconf files
echo "Cleaning up autoconf files..."
rm -rf aclocal.m4 autom4te.cache config.h config.h.in config.log config.status stamp-h1 configure 
rm -f build-scripts/depcomp  build-scripts/install-sh  build-scripts/missing  build-scripts/ylwrap 
find . -name 'Makefile.in' -exec rm -f {} \;
find . -name '.deps' -exec rm -rf {} \;

if [ "$1" == "all" ]
then
	echo "Cleaning up the make files..."
	find . -name 'Makefile' -exec rm -f {} \; 
fi
