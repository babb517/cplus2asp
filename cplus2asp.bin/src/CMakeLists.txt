CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
SET(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -Wall -O0 -DDEBUG")
set(CMAKE_C_FLAGS_DEBUG "-g3 -Wall -O0 -DDEBUG")


# General variables.
set(MAIN_SOURCE_DIR "${CMAKE_HOME_DIRECTORY}")
set(DATASTRUCTS_DIR "${MAIN_SOURCE_DIR}/DataStructs")

include_directories("${MAIN_SOURCE_DIR}" "${DATASTRUCTS_DIR}")

set(HEADERS "${DATASTRUCTS_DIR}/Attribute.h" "${DATASTRUCTS_DIR}/ASPCode.h" "${DATASTRUCTS_DIR}/Comment.h" "${DATASTRUCTS_DIR}/Constant.h" "${DATASTRUCTS_DIR}/Element.h" "${DATASTRUCTS_DIR}/ElementCounter.h" "${DATASTRUCTS_DIR}/NumberRange.h" "${DATASTRUCTS_DIR}/Object.h" "${DATASTRUCTS_DIR}/Sort.h" "${DATASTRUCTS_DIR}/Query.h" "${DATASTRUCTS_DIR}/Variable.h" "${DATASTRUCTS_DIR}/Macro.h" "${DATASTRUCTS_DIR}/Token.h" "${DATASTRUCTS_DIR}/TokenStream.h" "${DATASTRUCTS_DIR}/SymbolTable.h" "${MAIN_SOURCE_DIR}/flexer.h" "${MAIN_SOURCE_DIR}/flexertypes.h" "${MAIN_SOURCE_DIR}/lexerTokenStream.h" "${MAIN_SOURCE_DIR}/ltsglobals.h" "${MAIN_SOURCE_DIR}/MacroParser.h" "${MAIN_SOURCE_DIR}/IncludeHandler.h" "${MAIN_SOURCE_DIR}/parser.h" "${MAIN_SOURCE_DIR}/parser_types.h" "${MAIN_SOURCE_DIR}/Translator.h" "${MAIN_SOURCE_DIR}/utilities.h" "${DATASTRUCTS_DIR}/Context.h")

set(ELEMENT_SOURCES "${DATASTRUCTS_DIR}/Attribute.cpp" "${DATASTRUCTS_DIR}/ASPCode.cpp" "${DATASTRUCTS_DIR}/Comment.cpp" "${DATASTRUCTS_DIR}/Constant.cpp" "${DATASTRUCTS_DIR}/Element.cpp" "${DATASTRUCTS_DIR}/ElementCounter.cpp" "${DATASTRUCTS_DIR}/NumberRange.cpp" "${DATASTRUCTS_DIR}/Object.cpp" "${DATASTRUCTS_DIR}/Sort.cpp" "${DATASTRUCTS_DIR}/Query.cpp" "${DATASTRUCTS_DIR}/Variable.cpp")
set(DATASTRUCT_SOURCES "${DATASTRUCTS_DIR}/Macro.cpp" "${DATASTRUCTS_DIR}/Token.cpp" "${DATASTRUCTS_DIR}/TokenStream.cpp" "${DATASTRUCTS_DIR}/SymbolTable.cpp" "${DATASTRUCTS_DIR}/Context.cpp")
set(CORE_SOURCES "${MAIN_SOURCE_DIR}/flexer.cpp" "${MAIN_SOURCE_DIR}/lexerTokenStream.cpp" "${MAIN_SOURCE_DIR}/ltsglobals.cpp" "${MAIN_SOURCE_DIR}/MacroParser.cpp" "${MAIN_SOURCE_DIR}/IncludeHandler.cpp" "${MAIN_SOURCE_DIR}/parser.cpp" "${MAIN_SOURCE_DIR}/parser_types.cpp" "${MAIN_SOURCE_DIR}/Translator.cpp" "${MAIN_SOURCE_DIR}/utilities.cpp")

# Main translator application.
project (MainTrans)

set(MainTrans_MAIN_SOURCE "main.cpp")
set(MainTrans_SOURCES ${ELEMENT_SOURCES} ${DATASTRUCT_SOURCES} ${CORE_SOURCES} ${HEADERS} ${MainTrans_MAIN_SOURCE})

add_executable("cplus2asp.bin" ${MainTrans_SOURCES})

install(TARGETS cplus2asp.bin DESTINATION bin)
