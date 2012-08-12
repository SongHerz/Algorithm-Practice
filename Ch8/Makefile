.PHONY: clean

INCLUDES=..
CXXFLAGS+=-I$(INCLUDES) -g

all: test

test: countingSort.cc test.cc
	g++ $(CXXFLAGS) $^ -o $@

clean:
	rm test
