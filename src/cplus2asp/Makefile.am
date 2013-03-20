include $(top_srcdir)/src/Makefile.shared

locdir = $(datadir)/cplus2asp

loc_PROGRAMS = cplus2asp

loc_DATA = \
	cplus2asp_additive.f2lp \
	cplus2asp_std.f2lp \
	cplus2asp_additive.of2lp \
	cplus2asp_std.of2lp

BUILT_SOURCES = cplus2asp.cpp

cplus2asp_SOURCES = \
	Config.h \
	Config.cpp \
	utils.h \
	utils.cpp \
	cplus2asp.re2c \
	Interpreter.re2c


# Linking to the binary...

install-exec-hook:
	@- rm -f $(bindir)/cplus2asp
	ln -s $(locdir)/cplus2asp \
	      $(bindir)/cplus2asp
	chmod -R a+r $(locdir)
	find $(locdir) -type d -exec chmod a+x {} \;
	chmod a+x $(locdir)/cplus2asp

uninstall-hook:
	@- rm -f $(bindir)/cplus2asp


