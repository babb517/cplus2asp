# Builds the complete as2transition application.
# Variable DEBUG can be set to true via command line to turn on debugging options.

DEBUG=true
CC=g++
CFLAGS=-c
LDFLAGS=
DEBUGFLAGS=-Wall -O0 -g3
RELEASEFLAGS=-Wall -O3
INSTALLPATH=/usr/local/bin

OBJECTS=StringUtils.o Predicate.o TimeStepInfo.o
MAINSOURCE=as2transition.cpp
EXECUTABLE=as2transition
INSTALLLOC=$(INSTALLPATH)/

.PHONY : all
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(MAINSOURCE)
ifeq ($(DEBUG),true)
	$(CC) $(LDFLAGS) $(DEBUGFLAGS) $(OBJECTS) $(MAINSOURCE) -o $@
else
	$(CC) $(LDFLAGS) $(RELEASEFLAGS) $(OBJECTS) $(MAINSOURCE) -o $@
endif

$(OBJECTS): $(OTHEROBJS:.o=.cpp) $(OTHEROBJS:.o=.h)

.PHONY : remake
remake: clean all

.PHONY : clean
clean:
	rm -f *.o

.PHONY : install
install:
	cp $(EXECUTABLE) $(INSTALLLOC)

.cpp.o:
ifeq ($(DEBUG),true)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $< -o $@
else
	$(CC) $(CFLAGS) $(RELEASEFLAGS) $< -o $@
endif
