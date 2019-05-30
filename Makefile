C=gcc
CXX=g++
CXXFLAGS=-std=c++11 -MMD -g

SRCDIR=source
OBJDIR=built/obj
BINDIR=built/bin

INCLUDEDIR=-I/usr/local/include/ -I/usr/local/Cellar/sfml/2.5.1/include/
LIBDIR=-L/usr/local/lib/ -L/usr/local/Cellar/sfml/2.5.1/lib/

LIBS=
FRAMEWORKS=-lsfml-window -lsfml-system -lsfml-graphics

CSRCFILES:=$(wildcard $(SRCDIR)/*.c)
COBJFILES:=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CSRCFILES))
CPPSRCFILES:=$(shell find . -name "*.cpp")
CPPOBJFILES:=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(CPPSRCFILES))

all: gameai

gameai: $(COBJFILES) $(CPPOBJFILES)
	$(CXX) $(CXXFLAGS) $(INCLUDEDIR) $(LIBDIR) $(LIBS) $(FRAMEWORKS) -o $(BINDIR)/$@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDEDIR) -c -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(C) $(INCLUDEDIR) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(BINDIR)

-include $(OBJFILES:.o=.d)

# Make the output directories
$(shell mkdir -p $(OBJDIR) $(BINDIR))
$(shell mkdir -p $(dir $(CPPOBJFILES)))
