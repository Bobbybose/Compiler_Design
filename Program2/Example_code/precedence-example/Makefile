BINARIES = calculate

CXXFLAGS = -std=c++17 -Wall
FLEXFLAGS = # You might want -8 and -F
BISONFLAGS = 

all: $(BINARIES)

.PRECIOUS: %.cc %.hh

clean:
	-rm $(BINARIES) parser.cc parser.hh lexer.cc parser.o lexer.o

calculate: parser.o lexer.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lfl

# Make sure we build parser.hh before compiling the lexer
lexer.o: lexer.cc parser.hh globals.h

# parser.hh comes from building parser.cc
parser.hh: parser.cc

# Rebuild parser if globals.h changes.
parser.o: parser.cc globals.h

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

%.cc: %.l
	flex $(FLEXFLAGS) -o $@ $<

# -d to also create a header file (.hh/.h instead of .cc/.c)
%.cc: %.y
	bison $(BISONFLAGS) -d -o $@ $<
