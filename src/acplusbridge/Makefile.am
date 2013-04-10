include $(top_srcdir)/src/Makefile.shared

bin_PROGRAMS = acplusbridge

acplusbridge_CPPFLAGS = $(BOOST_CPPFLAGS)

if HAVE_BOOST_TIMER
acplusbridge_CPPFLAGS += -DBOOST_TIMER
endif

acplusbridge_SOURCES = \
	main.cpp \
	Driver.cpp \
	NetworkClient.cpp 

acplusbridge_LDFLAGS = $(BOOST_THREAD_LDFLAGS) $(BOOST_TIMER_LDFLAGS)
#acplusbridge_LDADD = externals/as2transition/src/libas2transition.a $(BOOST_THREAD_LIBS) 
acplusbridge_LDADD = as2transition/libas2transition.a $(BOOST_THREAD_LIBS) $(BOOST_TIMER_LIBS)

