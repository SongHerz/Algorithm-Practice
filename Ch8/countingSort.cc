#include <cassert>
#include "countingSort.hh"

using namespace std;

void countingSort( const std::vector<SORT_TYPE> &A, std::vector<SORT_TYPE> &B, const size_t k) {
	assert( A.size() == B.size());
	std::vector<SORT_TYPE> C( k + 1, 0);

	for ( size_t j = 0; j < A.size(); ++j) {
		C[ A[j]] += 1;
	}
	// Now, value of C[i] is the count of i in A
	
	for ( size_t i = 1; i < C.size(); ++i) {
		C[ i] = C[ i - 1] + C[ i];
	}

	for ( size_t j = A.size() - 1; j != (size_t)(-1); --j) {
		// Index from 0, so we should use C[ A[ j]] - 1
		const size_t finalPos = C[ A[ j]] - 1;
		B[ finalPos] = A[ j];
		C[ A[ j]] -= 1;
	}
}
