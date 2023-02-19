BINARIES = calc-tree

CXXFLAGS = -std=c++17 -Wall
FLEXFLAGS = # You might want -8 and -F
BISONFLAGS = 

all: $(BINARIES)

.PRECIOUS: %.cc %.hh

clean:
	-rm $(BINARIES) parser.cc parser.hh lexical_analyzer.cc parser.o lexical_analyzer.o tree_node.o

calc-tree: parser.o lexical_analyzer.o tree_node.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lfl

# Make sure we build parser.hh before compiling the lexer
lexical_analyzer.o: lexical_analyzer.cc parser.hh globals.h tree_node.h

# parser.hh comes from building parser.cc
parser.hh: parser.cc

# Rebuild parser if globals.h changes.
parser.o: parser.cc globals.h tree_node.h

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

%.cc: %.l
	flex $(FLEXFLAGS) -o $@ $<

# -d to also create a header file (.hh/.h instead of .cc/.c)
%.cc: %.y
	bison $(BISONFLAGS) -d -o $@ $<
