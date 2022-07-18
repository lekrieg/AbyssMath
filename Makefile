TARGET = libabyssmath.a

CXX = g++
CXXFLAGS = -Wall -IC:\Users\danie\Documents\projects\git\AbyssMath\header

COMMON := -g

CXXFLAGS += $(COMMON) 

ARCHIVER = ar

AFLAGS = rcs

SRCDIR = src
HDIR = header
OBJDIR = obj
BINDIR = bin

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(HDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DIRS := $(OBJDIR) $(BINDIR)
rm = rm -f

# It works on Windows and Linux
# ranlib is used to generate the table of contents on the .a

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(ARCHIVER) $(AFLAGS) $@ $(OBJECTS) ranlib
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

$(DIRS):
	mkdir $@

.PHONY: clean
clean:
	$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"