include $(top_srcdir)/src/Makefile.shared


bin_PROGRAMS = cplus2asp.bin

BUILT_SOURCES = \
	flexer.h \
	parser.h 


cplus2asp_bin_SOURCES = \
	main.cpp \
	flexer.ll \
	IncludeHandler.cpp \
	lexerTokenStream.cpp \
	ltsglobals.cpp \
	MacroParser.cpp \
	parser.yy \
	parser_types.cpp \
	Translator.cpp \
	utilities.cpp \
	DataStructs/ASPCode.cpp \
	DataStructs/Attribute.cpp \
	DataStructs/Comment.cpp \
	DataStructs/Constant.cpp \
	DataStructs/Context.cpp \
	DataStructs/ElementCounter.cpp \
	DataStructs/Element.cpp \
	DataStructs/Macro.cpp \
	DataStructs/NumberRange.cpp \
	DataStructs/Object.cpp \
	DataStructs/Query.cpp \
	DataStructs/Sort.cpp \
	DataStructs/SymbolTable.cpp \
	DataStructs/Token.cpp \
	DataStructs/TokenStream.cpp \
	DataStructs/Variable.cpp 

#cplus2asp_bin_CPPFLAGS = $(BOOST_CPPFLAGS)
#cplus2asp_bin_LDFLAGS = $(BOOST_THREAD_LDFLAGS)
cplus2asp_bin_LDADD = $(BOOST_THREAD_LIBS) 
