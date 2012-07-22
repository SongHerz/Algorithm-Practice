#include <cassert>
#include <algorithm>
#include <iostream>
#include "qsort.hh"

using namespace std;

static void printSortVec( const std::vector< SORT_TYPE> &vec) {
	for ( size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[ i] << ", ";
	}
	std::cout << std::endl;
}

size_t partation( std::vector< SORT_TYPE> &vec, size_t p, size_t r, bool printStep) {
	assert( p >= 0 && p < vec.size());
	assert( r >= 0 && r < vec.size());	

	const SORT_TYPE &pivot = vec[ r];
	size_t i = p - 1;
	size_t j = p;

	for ( ; j < r; ++j) {
		if ( vec[ j] < pivot) {
			i += 1;
			swap( vec[ j], vec[ i]);
			if ( printStep) {
				printSortVec( vec);
			}
		}
	}
	assert( i <= j - 1);
	swap( vec[ i + 1], vec[ r]);
	if ( printStep) {
		printSortVec( vec);
	}

	return i + 1;
}
