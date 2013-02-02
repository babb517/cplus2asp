# Builds the complete cplus2asp application.
# Variable DEBUG can be set to true via command line to turn on debugging options.

INSTALLPATH=/usr/local
BINPATH=$(INSTALLPATH)/bin
LIBPATH=$(INSTALLPATH)/lib


OBJECTS=Config.o cplus2asp.o utils.o
EXECUTABLE=cplus2asp
STD_ASP_FILE=cplus2asp_std.f2lp
ADDITIVE_ASP_FILE=cplus2asp_additive.f2lp
STD_ASP_DYNAMIC_FILE=cplus2asp_std.of2lp
ADDITIVE_ASP_DYNAMIC_FILE=cplus2asp_additive.of2lp
EXEC_SCRIPT=cplus2asp_base.sh
INSTALL_EXEC_SCRIPT_NAME=cplus2asp
INSTALL_BINLOC=$(BINPATH)/
INSTALL_LIBLOC=$(LIBPATH)/cplus2asp/

RE2C=re2c
RE2CFLAGS=

DEBUG=
CC=g++
CFLAGS=-c -DINSTALL_DIR="\"$(INSTALL_LIBLOC)\"" -std=c++0x
DEBUGFLAGS=-Wall -O0 -g3 -DDEBUG
RELEASEFLAGS=-Wall -O3

.SUFFIXES : .cpp .o .re2c

.PHONY : all
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
ifeq ($(DEBUG),true)
	$(CC) $(LDFLAGS) $(DEBUGFLAGS) $(OBJECTS) -o $@
else
	$(CC) $(LDFLAGS) $(RELEASEFLAGS) $(OBJECTS) -o $@
endif

$(OBJECTS): $(OTHEROBJS:.o=.cpp) $(OTHEROBJS:.o=.h)

.PHONY : remake
remake: realclean all

.PHONY : clean
clean:
	-rm -f *.o

.PHONY : realclean
realclean:
	-rm -f *.o
	-rm -f $(EXECUTABLE)

.PHONY : install
install:
	@cd $(INSTALL_LIBLOC) 2>/dev/null || mkdir $(INSTALL_LIBLOC)
	@-rm $(INSTALL_LIBLOC)$(EXECUTABLE) 2>/dev/null || true
	cp $(EXECUTABLE) $(INSTALL_LIBLOC)
	@-rm $(INSTALL_LIBLOC)$(STD_ASP_FILE) 2>/dev/null || true
	cp $(STD_ASP_FILE) $(INSTALL_LIBLOC)
	@-rm $(INSTALL_LIBLOC)$(ADDITIVE_ASP_FILE) 2>/dev/null || true
	cp $(ADDITIVE_ASP_FILE) $(INSTALL_LIBLOC)
	@-rm $(INSTALL_LIBLOC)$(STD_ASP_DYNAMIC_FILE) 2>/dev/null || true
	cp $(STD_ASP_DYNAMIC_FILE) $(INSTALL_LIBLOC)
	@-rm $(INSTALL_LIBLOC)$(ADDITIVE_ASP_DYNAMIC_FILE) 2>/dev/null || true
	cp $(ADDITIVE_ASP_DYNAMIC_FILE) $(INSTALL_LIBLOC)
	cp $(EXEC_SCRIPT) $(INSTALL_BINLOC)$(INSTALL_EXEC_SCRIPT_NAME)
	@echo "$(INSTALL_LIBLOC)$(EXECUTABLE) \"\$$@\"" >> $(INSTALL_BINLOC)$(INSTALL_EXEC_SCRIPT_NAME)

.cpp.o:
ifeq ($(DEBUG),true)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $< -o $@
else
	$(CC) $(CFLAGS) $(RELEASEFLAGS) $< -o $@
endif

.re2c.cpp:
	$(RE2C) $(RE2CFLAGS) $< > $@

