#!/bin/sh
# Cleans out any existing CMake cache and calls CMake to generate a new Makefile.
rm -rf CMakeFiles
rm -f CMakeCache.txt
rm -f cmake_install.cmake
rm -f Makefile
cmake -C BuildSetup.cmake ..
