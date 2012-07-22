#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "qsort.hh"

using namespace std;

static void printSortVec( const std::vector< SORT_TYPE> &vec, size_t p, size_t r, size_t i, size_t j, size_t pivot) {
	const char LESS_THAN_PIVOT_MARK = '*';
	const char NOT_LESS_THAN_PIVOT_MARK = '#';
	const char UNSCANED_MARK = '=';
	const char PIVOT_MARK = 'v';

	ostringstream ossNums;
	ostringstream ossMarks;

	size_t oldNumSize = 0;

	for ( size_t idx = p; idx <= r; ++idx) {
		ossNums << vec[ idx] << " ";

		char mark;
		if ( idx == pivot) {
			// The number is the pivot
			mark = PIVOT_MARK;
		}
		else if ( i != p - 1 && idx <= i) {
			// The number is less than the pivot
			mark = LESS_THAN_PIVOT_MARK;
		}
		else if ( idx <= j) {
			// The number is not less than the pivot
			mark = NOT_LESS_THAN_PIVOT_MARK;
		}
		else if ( idx <= r) {
			// The number has not been scaned yet
			mark = UNSCANED_MARK;
		}
		else {
			assert( 0 && "Never be here");
			mark = 'X';
		}

		for ( size_t tmp = oldNumSize; tmp < ossNums.str().size(); ++tmp) {
			ossMarks << mark;
		}
		oldNumSize = ossNums.str().size();
	}

	cout << endl;
	cout << ossMarks.str() << endl;
	cout << ossNums.str() << endl;
}


size_t partation( std::vector< SORT_TYPE> &vec, size_t p, size_t r, bool printChangeStep, bool printEachStep) {
	assert( p >= 0 && p < vec.size());
	assert( r >= 0 && r < vec.size());	

	const SORT_TYPE &pivot = vec[ r];
	size_t i = p - 1;
	size_t j = p;

	// print initial status
	if ( printChangeStep || printEachStep) {
		cout << "Initial step: " << endl;
		printSortVec( vec, p, r, i, j, r);

		cout << endl;
		if ( printChangeStep && !printEachStep) {
			cout << "Change step only:" << endl;
		}
		else {
			assert( printEachStep);
			cout << "Each step:" << endl;
		}
	}

	for ( ; j < r; ++j) {
		if ( vec[ j] < pivot) {
			i += 1;
			swap( vec[ j], vec[ i]);
			if ( printChangeStep && !printEachStep) {
				printSortVec( vec, p, r, i, j, r);
			}
		}
		if ( printEachStep) {
			printSortVec( vec, p, r, i, j, r);
		}
	}
	assert( i <= j - 1);
	swap( vec[ i + 1], vec[ r]);
	if ( printChangeStep || printEachStep) {
		cout << endl;
		cout << "Move pivot:" << endl;
		printSortVec( vec, p, r, i, j, r);
	}

	return i + 1;
}
