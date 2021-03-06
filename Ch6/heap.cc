#include <algorithm>
#include "heap.hh"

using namespace std;

void printHeap( ostream &os, const Heap &heap) {
	os << "HEAP: ";
	for ( Heap::const_iterator it = heap.begin(); it != heap.end(); ++it) {
		int node = *it;
		os << node << " ";
	}
	os << std::endl;
}
		
void maxHeapify( Heap &heap, size_t heapSize, size_t idx) {
	assert( idx < heapSize);
	while ( 1) {
		int largestIdx;

		// Check left sub-tree
		size_t left = leftIdx( idx);
		if ( !isValidIdx( left, heapSize)) {
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
		if ( isValidIdx( right, heapSize) && heap[ right] > heap[ largestIdx]) {
			largestIdx = right;
		}
		if ( largestIdx != idx) {
			std::swap( heap[ largestIdx], heap[ idx]);
			idx = largestIdx;
		}
		else {
			break;
		}
	}
}

void buildMaxHeap( Heap &heap, size_t heapSize) {
	if ( heapSize <= 1) {
		return;
	}
	size_t i = lastNonLeafIdx( heapSize);
	do {
		maxHeapify( heap, heapSize, i);
	} while( i-- != 0);
}

void heapSort( Heap &heap) {
	size_t heapSize = heap.size();
	buildMaxHeap( heap, heapSize);
	for ( size_t i = heap.size() - 1; i > 0; --i) {
		std::swap( heap[ 0], heap[ i]);
		--heapSize;
		maxHeapify( heap, heapSize, 0);
	}
}
