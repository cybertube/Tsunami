################################################################################
# TsunamiExample Makefile
################################################################################
UNAME       = $(shell uname)
MACHINE     = $(shell uname -m)
GCCVER      = $(shell gcc -dumpversion | cut -d '.' -f 1)
CC          = cc
LD          = g++
BINNAME     = TsunamiExample
TOP         = $(shell pwd)

################################################################################
# Include paths
################################################################################
INCLUDE_FLAGS = 

################################################################################
# Main Object files
################################################################################
OBJECTS = ./Example.o \
		  ./Tsunami.o

################################################################################
# Compiler flags
################################################################################
FLAGS  = -Wall ${INCLUDE_FLAGS} ${CFLAGS}
ifeq (${DEBUG}, 1)
	FLAGS += -g -D__DEBUG__
endif
ifeq (${RELEASE}, 1)
	FLAGS += -O3
endif

################################################################################
# Build targets
################################################################################
all: message

message:
	@echo "[01;32mTsunamiExample          Build Targets Menu[00m"
	@echo "[01;32m==========================================[00m"
	@echo          "   make debug    - Debug build"
	@echo          "   make release  - Release build"
	@echo
	@echo          "   make archive  - Produce a dated archive"
	@echo
	@echo          "   make clean    - Clean"

release:
	@echo "[01;32mBuilding Release:[00m"
	+(make $(BINNAME) "RELEASE = 1";)

debug:
	@echo "[01;32mBuilding Debug:[00m"
	+(make $(BINNAME) "DEBUG = 1";)	

$(BINNAME): $(OBJECTS)
	${LD} $(FLAGS) -o $(BINNAME) $(OBJECTS) $(LINKFLAGS)

%.o: %.c
	$(CC) $(FLAGS) -o $*.o -c $*.c

%.o: %.cpp
	$(CC) $(FLAGS) -o $*.o -c $*.cpp

clean:
	rm -rf ${OBJECTS} *~ *.vcd $(BINNAME) core 

archive: clean
	tar cfz - * > $(BINNAME)-`date +%d%m%Y-%H%M`.tar.gz
