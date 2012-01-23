#include <iostream>
#include <cassert>
#include "binary_search.hh"

// Test binary search
bool test_binary_search() {
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
}


bool test_less_eq_bound() {
	std::vector< int> v;

	// prepare an orered vector
	for ( int i = 0; i < 100; i++) {
		v.push_back( i);
	}

	for ( int i = 0; i < 100; i++) {
		std::size_t idx;
		bool found = less_eq_bound( v, 0, v.size() - 1, i, idx);
		if ( !(found && idx == i)) {
			std::cout << "Error: i = " << i << std::endl;
			return 1;
		}
	}

	for ( int i = 101; i < 200; i++) {
		std::size_t idx;
		bool found = less_eq_bound( v, 0, v.size() - 1, i, idx);
		assert( found && idx == v.size() - 1);
	}

	for ( int i = -101; i < 0; i++) {
		std::size_t idx;
		bool found = less_eq_bound( v, 0, v.size() - 1, i, idx);
		assert( !found && idx == INVALID_IDX);
	}
}

int main() {

	if ( test_binary_search()) {
		std::cout << "Testing binary search success" << std::endl;
	}
	else {
		std::cout << "Testing binary search fail" << std::endl;
	}

	if ( test_less_eq_bound()) {
		std::cout << "Testing less_eq bound success" << std::endl;
	}
	else {
		std::cout << "Testing less_eq bound fail" << std::endl;
	}

	return 0;
}

