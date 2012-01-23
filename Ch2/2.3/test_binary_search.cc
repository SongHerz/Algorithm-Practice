#include <iostream>
#include <cassert>
#include "binary_search.hh"

// Test binary search
int main() {
	std::vector< int> v;

	// prepare an orered vector
	for ( int i = 0; i < 100; i++) {
		v.push_back( i);
	}

	for ( int i = 0; i < 100; i++) {
		std::size_t idx;
		bool found = binary_search( v, 0, v.size() - 1, i, idx);
		if ( !(found && idx == i)) {
			std::cout << "Error: i = " << i << std::endl;
			return 1;
		}
	}

	for ( int i = 101; i < 200; i++) {
		std::size_t idx;
		bool found = binary_search( v, 0, v.size() - 1, i, idx);
		assert( !found && idx == INVALID_IDX);
	}

	for ( int i = -101; i < 0; i++) {
		std::size_t idx;
		bool found = binary_search( v, 0, v.size() - 1, i, idx);
		assert( !found && idx == INVALID_IDX);
	}

	std::cout << "Testing binary search success" << std::endl;

	return 0;
}

