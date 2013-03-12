include $(top_srcdir)/src/Makefile.shared

locdir = $(datadir)/cplus2asp

loc_PROGRAMS = cplus2asp

loc_DATA = \
	cplus2asp_additive.f2lp \
	cplus2asp_std.f2lp

cplus2asp_SOURCES = \
	Config.h \
	Config.cpp \
	utils.h \
	utils.cpp \
	cplus2asp.re2c


# Linking to the binary...

install-exec-hook:
	ln -s $(locdir)/cplus2asp \
	      $(bindir)/cplus2asp

uninstall-hook:
	@- rm -f $(bindir)/cplus2asp


