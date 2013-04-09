include $(top_srcdir)/src/Makefile.shared

# Compatibility hack
locdir = $(pkglibdir)

loc_PROGRAMS = cplus2asp

loc_DATA = \
	cplus2asp_additive.f2lp \
	cplus2asp_std.f2lp \
	cplus2asp_additive.of2lp \
	cplus2asp_std.of2lp

cplus2asp_CPPFLAGS = $(BOOST_CPPFLAGS)
cplus2asp_LDFLAGS = $(BOOST_THREAD_LDFLAGS) $(BOOST_FILESYSTEM_LDFLAGS)
cplus2asp_LDADD = $(BOOST_THREAD_LIBS) $(BOOST_FILESYSTEM_LIBS)


BUILT_SOURCES = cplus2asp.cpp

cplus2asp_SOURCES = \
	Config.h \
	Config.cpp \
	utils.h \
	utils.cpp \
	cplus2asp.re2c \
	Interpreter.re2c


# Linking to the binary...

install-data-hook:
	@- rm -f $(bindir)/cplus2asp
	$(LN_S) $(locdir)/cplus2asp \
	      $(bindir)/cplus2asp
	chmod -R a+r $(locdir)
	find $(locdir) -type d -exec chmod a+x {} \;
	chmod a+x $(locdir)/cplus2asp

uninstall-hook:
	@- rm -f $(bindir)/cplus2asp


