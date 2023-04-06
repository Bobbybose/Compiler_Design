TARGET = lexical_analyzer

CXXFLAGS = -std=c++17 -Wall

all: $(TARGET)

.PRECIOUS: %.cc

clean:
	-rm $(TARGET) $(TARGET:=.cc)

%: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $< -lfl

%.cc: %.l
	flex $(FLEXFLAGS) -o $@ $<