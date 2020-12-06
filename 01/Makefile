CC := g++
SRCDIR := src
OBJDIR := build
BINDIR := bin
CFLAGS := -g -Wall -O3 -std=c++11
INC := -I include/
MAIN := program/main.cpp
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TOP := $(shell pwd)

# Path for lib chilkat
export LD_LIBRARY_PATH:=${TOP}/lib:$LD_LIBRARY_PATH

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

all: main

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^  -Llib -lchilkat-9.5.0 -o $(BINDIR)/main

run: main
	$(BINDIR)/main

valgrind: main
	valgrind -v --leak-check=full  $(BINDIR)/main

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/*