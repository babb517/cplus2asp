#ifndef FLEXERTYPES_DOT_H
#define FLEXERTYPES_DOT_H

// Extra includes and types the flexer depends on, separated so dependent code can also include them.

#include <string>

/// Used to flag what kind of yylval a token has.
enum FlexerValueType { VT_INT, VT_STR, VT_COMMENT, VT_ASP};
typedef enum FlexerValueType flexerValueType;

#endif
