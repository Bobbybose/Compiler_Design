BINARIES = numbers

CXXFLAGS = -std=c++17 -Wall
FLEXFLAGS = # You might want -8 and -F

all: $(BINARIES)

.PRECIOUS: %.cc

clean:
	-rm $(BINARIES) $(BINARIES:=.cc)

%: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $< -lfl

%.cc: %.l
	flex $(FLEXFLAGS) -o $@ $<
