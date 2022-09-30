#
# usage:
#
# 		make           -> build all files
# 		make target(s) -> build specific file(s)
# 		make clean     -> clean all files
#
.RECIPEPREFIX = >

# should be match with BINDIR and SRCDIR
# if they are specified different from current directory
VPATH = . src bin

CCSTD    = # -std=c99
CPPFLAGS = # -I"include"
CFLAGS   = $(CCSTD) $(CPPFLAGS) -Wall $(RELEASE)
LDFLAGS  = # -L"/libs"
LDLIBS   = # -lm
AR       = ar
BINDIR   = # bin/
SRCDIR   = # src/
DEBUG    = -O0 -g
RELEASE  = -O2 -DNDEBUG

.SUFFIXES: .c .o

# Create a list of source files.
SOURCES  = $(shell ls $(SRCDIR)*.c)
# Create a list of object files from the source file lists.
OBJECTS = ${SOURCES:.c=.o}
# Create a list of targets.
TARGETS = $(addprefix $(BINDIR), $(notdir $(patsubst %.c, %, $(SOURCES))))
#                                              change this ^ with %.exe for build exe files

.PHONY: all
# Build all targets by default
all: $(TARGETS)

# A rule to build file out of a .o file
# change % with %.exe for exe files
$(BINDIR)%: %.o
> $(CC) $< -o $@ $(LDFLAGS) $(LDLIBS)
> @echo

# A rule to build .o file out of a .c file
%.o: %.c
> $(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
# A rule to clean all the intermediates and targets
clean:
> rm -rf $(TARGETS) $(OBJECTS) *.out
