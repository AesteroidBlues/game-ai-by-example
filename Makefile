C=gcc
CXX=g++
CXXFLAGS=-std=c++11 -MMD -g

INCLUDEDIR=-I/usr/local/include/ -Iinclude/
LIBDIR=-L/usr/local/lib/

LIBS=
FRAMEWORKS=

SRCDIR=source
OBJDIR=built/obj
BINDIR=built/bin

CSRCFILES:=$(wildcard $(SRCDIR)/*.c)
COBJFILES:=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CSRCFILES))
CPPSRCFILES:=$(wildcard $(SRCDIR)/*.cpp)
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
$(shell   mkdir -p $(OBJDIR) $(BINDIR))
