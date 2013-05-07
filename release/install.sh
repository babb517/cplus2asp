#!/bin/bash

DEF_BIN_PATH_ROOT="/usr/local/bin"
DEF_LIB_PATH_ROOT="/usr/local/lib"
DEF_BIN_PATH_NONROOT="$HOME/bin"
DEF_LIB_PATH_NONROOT="$HOME/lib"

LIB_PATH=""
BIN_PATH=""
IS_ROOT=0

INSTALL_F2LP="Y"
INSTALL_ICLINGO="Y"
INSTALL_CLINGO="Y"

CONTINUE="n"

if [[ $EUID -ne 0 ]]; then

	echo "This script has NOT been run as root."
	echo "Selecting user-specific install location..."
	IS_ROOT=0
	LIB_PATH=$DEF_LIB_PATH_NONROOT
	BIN_PATH=$DEF_BIN_PATH_NONROOT

else

	echo "This script has been run as root."
	echo "Selecting system-wide install location..."
	IS_ROOT=1
	LIB_PATH=$DEF_LIB_PATH_ROOT
	BIN_PATH=$DEF_BIN_PATH_ROOT
fi


# Confirm the location with the user

read -p "Select a location to install program binaries [$BIN_PATH]: " SEL
[ ! -z "$SEL" ] && BIN_PATH=$SEL;
read -p "Select a location to install program library files [$LIB_PATH]: " SEL
[ ! -z "$SEL" ] && LIB_PATH=$SEL;

while true; do
    read -p "Do you wish to install F2LP (Y/n) [$INSTALL_F2LP]? " yn
    [ -z "$yn" ] && break;
    case $yn in
        [Yy]* ) INSTALL_F2LP="Y"; break;;
        [Nn]* ) INSTALL_F2LP="n"; break;;
        * ) echo "Please answer yes (Y) or no (n).";;
    esac
done


while true; do
    read -p "Do you wish to install iClingo (Y/n) [$INSTALL_ICLINGO]? " yn
    [ -z "$yn" ] && break;
    case $yn in
        [Yy]* ) INSTALL_ICLINGO="Y"; break;;
        [Nn]* ) INSTALL_ICLINGO="n"; break;;
        * ) echo "Please answer yes (Y) or no (n).";;
    esac
done

while true; do
    read -p "Do you wish to install Clingo (Y/n) [$INSTALL_CLINGO]? " yn
    [ -z "$yn" ] && break;
    case $yn in
        [Yy]* ) INSTALL_CLINGO="Y"; break;;
        [Nn]* ) INSTALL_CLINGO="n"; break;;
        * ) echo "Please answer yes (Y) or no (n).";;
    esac
done


# Confirm Options to the user...

echo ""
echo -e "Binary install path:  \t\t$BIN_PATH"
echo -e "Library install path: \t\t$LIB_PATH"

echo ""
echo "Applications: "

echo -e "  cplus2asp\t\t\tinstall."
echo -e "  cplus2asp.bin\t\t\tinstall."
echo -e "  as2transition\t\t\tinstall."


echo ""

if [ "$INSTALL_F2LP" = "Y" ]; then 
	echo -e "  f2lp\t\t\t\tinstall."
else
	echo -e "  f2lp\t\t\t\tskip."
fi

if [ "$INSTALL_ICLINGO" = "Y" ]; then 
	echo -e "  iclingo\t\t\tinstall."
else
	echo -e "  iclingo\t\t\tskip."
fi

if [ "$INSTALL_CLINGO" = "Y" ]; then 
	echo -e "  clingo\t\t\tinstall."
else
	echo -e "  clingo\t\t\tskip."
fi

echo ""

while true; do
    read -p "Do you wish to continue (Y/n) [$CONTINUE]? " yn
    [ -z "$yn" ] && break;
    case $yn in
        [Yy]* ) CONTINUE="Y"; break;;
        [Nn]* ) CONTINUE="n"; break;;
        * ) echo "Please answer yes (Y) or no (n).";;
    esac
done


if [ "$CONTINUE" != "Y" ] ; then
	echo "Installation canceled. Exiting with no changes."
	exit;
fi


# The actual installation...

mkdir -p $LIB_PATH
mkdir -p $BIN_PATH

cp -r lib/cplus2asp $LIB_PATH/
cp bin/cplus2asp.bin $BIN_PATH/
cp bin/as2transition $BIN_PATH/
rm -f $BIN_PATH/cplus2asp > /dev/null
ln -s $LIB_PATH/cplus2asp/cplus2asp $BIN_PATH/cplus2asp 

# Fix permissions

if [ $IS_ROOT -eq 1 ] ; then
	chown -R root:root $LIB_PATH/cplus2asp
	chmod -R a+r $LIB_PATH/cplus2asp
	chmod a+x $LIB_PATH/cplus2asp/cplus2asp
	
	chown -R root:root $BIN_PATH/cplus2asp.bin
	chmod a+rx $BIN_PATH/cplus2asp.bin

	chown -R root:root $BIN_PATH/as2transition
	chmod a+rx $BIN_PATH/as2transition
else
	chmod -R ug+r $LIB_PATH/cplus2asp
	chmod ug+x $LIB_PATH/cplus2asp/cplus2asp
	chmod ug+rx $BIN_PATH/cplus2asp.bin
	chmod ug+rx $BIN_PATH/as2transition
fi
