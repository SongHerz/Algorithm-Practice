#include <algorithm>
#include "heap.hh"

using namespace std;

void printHeap( ostream &os, const Heap &heap) {
	for ( Heap::const_iterator it = heap.begin(); it != heap.end(); ++it) {
		int node = *it;
		os << node << " ";
	}
	os << std::endl;
}
		
void maxHeapify( Heap &heap, size_t idx) {
	while ( 1) {
		int largestIdx;

		// Check left sub-tree
		size_t left = leftIdx( idx);
		if ( !isValidIdx( left, heap)) {
			break;
		}
		if ( heap[ left] > heap[ idx]) {
			largestIdx = left;
		}
		else {
			largestIdx = idx;
		}

		// Check right sub-tree
		size_t right = rightIdx( idx);
		if ( !isValidIdx( right, heap)) {
			break;
		}
		if ( heap[ right] > heap[ largestIdx]) {
			largestIdx = right;
		}
		if ( largestIdx != idx) {
			std::swap( heap[ largestIdx], heap[ idx]);
			idx = largestIdx;
		}
	}
}

