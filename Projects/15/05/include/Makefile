#
# usage:
#
# 		make           -> build all files
# 		make target(s) -> build specific file(s)
# 		make clean     -> clean all files
#
.RECIPEPREFIX = >

CCSTD    = # -std=c99
CPPFLAGS = # -I"include"
CFLAGS   = $(CCSTD) $(CPPFLAGS) -Wall $(RELEASE)
LDFLAGS  =
LDLIBS   =
AR       = ar
DEBUG    = -O0 -g
RELEASE  = -O2 -DNDEBUG

.SUFFIXES: .c .o

# Create a list of source files.
SOURCES  = $(shell ls *.c)
# Create a list of object files from the source file lists.
OBJECTS = ${SOURCES:.c=.o}
# Create a list of targets.
TARGETS = libcommon.a

.PHONY: all
# Build all targets by default
all: $(TARGETS)

# A rule to build the common library
%.a: $(OBJECTS)
> $(AR) rcs $@ $(OBJECTS)
> @echo
> @echo -e "\033[33;1m Done building $* \033[0m"
> @echo ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# A rule to build .o file out of a .c file
%.o: %.c
> $(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
# A rule to clean all the intermediates and targets
clean:
> rm -rf $(TARGETS) $(OBJECTS) *.out
