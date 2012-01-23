#include <cassert>
#include <utility>
#include <iostream>
#include <vector>
#include "merge_sort.hh"
#include "binary_search.hh"

typedef std::pair< int, int> AddPair;

// v MUST be an ascending ordered vector
// This is O(nlgn)
void find_add_pair( const std::vector< int> &v, const int sum, std::vector< AddPair> &addPairs) {
	std::size_t bound;
	
	// lgn
	if ( !less_eq_bound( v, 0, v.size() - 1, sum, bound)) {
		return;
	}
	assert( bound < v.size());

	// nlgn
	for ( std::size_t i = 0; i < bound; ++i) {
		int b = sum - v[i];

		std::size_t dummy;
		if ( binary_search( v, i + 1, bound, b, dummy)) {
			addPairs.push_back( std::make_pair( v[i], b));
		}
	}
}


bool less( int a, int b) {
	return a < b;
}

int main() {
	int sum = 100;

	std::vector< int> v;
	for ( int i = 0; i < 20; ++i) {
		v.push_back( i);
		v.push_back( sum - i);
	}

	for ( int i = 200; i < 400; ++i) {
		v.push_back( i);
	}

	std::vector< AddPair> addPairs;
	// merge sort is O(nlgn)
	merge_sort2( v, 0, v.size() - 1, less, false);
	// find add pair is O(nlgn)
	find_add_pair( v, sum, addPairs);

	std::cout << "There are " << addPairs.size() << " additions:" << std::endl;
	for ( std::size_t i = 0; i < addPairs.size(); ++i) {
		int a = addPairs[i].first;
		int b = addPairs[i].second;
		std::cout << a << " + " << b << " = " << sum << std::endl;
	}

	return 0;
}
