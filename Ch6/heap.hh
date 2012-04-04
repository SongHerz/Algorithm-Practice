#ifndef _HEAP_HH_
#define _HEAP_HH_

#include <iostream>
#include <vector>
#include <cassert>

typedef std::vector< int> Heap;

void printHeap( std::ostream &os, const Heap &heap);

static inline size_t leftIdx( const size_t idx) { return idx * 2 + 1; }
static inline size_t rightIdx( const size_t idx) { return idx * 2 + 2; }
static inline size_t firstLeafIdx( const size_t heapSize) { return heapSize / 2; }
static inline size_t lastNonLeafIdx( const size_t heapSize) {
	assert( heapSize > 1);
	return firstLeafIdx( heapSize) - 1;
}

static inline bool isValidIdx( const size_t idx, const size_t heapSize) { return idx < heapSize; }

void maxHeapify( Heap &heap, size_t heapSize, size_t idx);
void buildMaxHeap( Heap &heap, size_t heapSize);

void heapSort( Heap &heap);

#endif
