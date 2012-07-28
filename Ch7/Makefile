.PHONY: clean

INCLUDES=..
CXXFLAGS+=-I$(INCLUDES) -g

all: test

test: qsort.cc test.cc ../Utility/random.cc
	g++ $(CXXFLAGS) $^ -o $@

clean:
	rm test
