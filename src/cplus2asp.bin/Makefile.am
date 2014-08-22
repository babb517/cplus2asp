include $(top_srcdir)/src/Makefile.shared


bin_PROGRAMS = cplus2asp3.bin

BUILT_SORCES =\
	Configuration.cpp

cplus2asp3_bin_SOURCES = \
	main.cpp \
	Configuration.cpp \
	Translator.cpp \
	SortData.cpp \
	ObjectData.cpp \
	RangeData.cpp \
	ConstantData.cpp \
	Context.cpp

cplus2asp3_bin_CPPFLAGS = $(BOOST_CPPFLAGS)
cplus2asp3_bin_LDFLAGS = $(BOOST_FILESYSTEM_LDFLAGS) $(BOOST_SYSTEM_LDFLAGS) $(BOOST_THREAD_LDFLAGS) 
cplus2asp3_bin_LDADD = -lbcplusparser $(BOOST_FILESYSTEM_LIBS) $(BOOST_SYSTEM_LIBS) $(BOOST_THREAD_LIBS)
