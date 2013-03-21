#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT(cplus2asp, 2.0, jbabb1@asu.edu)
AC_CONFIG_SRCDIR([src/cplus2asp/utils.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-scripts])


# Setup Automake
AM_INIT_AUTOMAKE
AC_CONFIG_FILES([Makefile
	src/as2transition/Makefile
	src/cplus2asp.bin/Makefile
	src/cplus2asp/Makefile])


#TODO: Disable this in release
# Allows LEX, YACC, and RE2C to rebuild their files.
#AM_MAINTAINER_MODE([enable])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_LN_S
AM_PROG_LEX
AM_CONDITIONAL([HAVE_FLEX],[test "x$LEX" == x"flex"])
AC_PROG_YACC
AC_PATH_PROG([RE2C],[re2c],[false])
AC_SUBST(RE2C)
AM_CONDITIONAL([HAVE_RE2C],[test "x$RE2C" != x"false"])

AC_PATH_PROG([ICLINGO],[iclingo],[false])
AC_PATH_PROG([OCLINGO],[oclingo],[false])
AC_PATH_PROG([CLINGO], [clingo], [false])
AC_PATH_PROG([F2LP],   [f2lp], 	 [false])

if test x"$ICLINGO" == x"false"
then
	AC_MSG_WARN([Could not find iclingo which is required for the normal operation of cplus2asp. Please install iclingo from http://potassco.sourceforge.net before continuing.])
fi

if test x"$OCLINGO" == x"false"
then
	AC_MSG_WARN([Could not find oclingo which is required for using the reactive features of cplus2asp. Please install oclingo from http://potassco.sourceforge.net before attempting to use these features.])
fi

if test x"$CLINGO" == x"false"
then
	AC_MSG_WARN([Could not find clingo which is required for the static running modes of cplus2asp. Please install clingo from http://potassco.sourceforge.net before attempting to use these features.])
fi

if test x"$F2LP" == x"false"
then
	AC_MSG_WARN([Could not find f2lp which is required for the normal operation of cplus2asp. Please install f2lp from http://reasoning.eas.asu.edu/f2lp before continuing.])
fi


# Checks for libraries.

# Checks for header files.
AC_FUNC_ALLOCA
AC_CHECK_HEADERS([inttypes.h libintl.h malloc.h stddef.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset realpath strchr strdup])

# Allow Debugging
AC_ARG_ENABLE(debug,
AS_HELP_STRING([--enable-debug],
               [enable debugging, default: no]),
[case "${enableval}" in
             yes) debug=true ;;
             no)  debug=false ;;
             *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
esac],
[debug=false])
AM_CONDITIONAL(DEBUG, test x"$debug" = x"true")

AC_OUTPUT
