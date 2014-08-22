include $(top_srcdir)/src/Makefile.shared

bin_PROGRAMS = bcbridge

bcbridge_CPPFLAGS = $(BOOST_CPPFLAGS)

if HAVE_BOOST_TIMER
bcbridge_CPPFLAGS += -DBOOST_TIMER
endif

bcbridge_SOURCES = \
	main.cpp \
	Driver.cpp \
	NetworkClient.cpp 

bcbridge_LDFLAGS = $(BOOST_THREAD_LDFLAGS) $(BOOST_TIMER_LDFLAGS)
#bcbridge_LDADD = externals/as2transition/src/libas2transition.a $(BOOST_THREAD_LIBS) 
bcbridge_LDADD = -las2transition $(BOOST_THREAD_LIBS) $(BOOST_TIMER_LIBS)

