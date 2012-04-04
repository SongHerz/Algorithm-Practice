#ifndef _HEAP_HH_
#define _HEAP_HH_

#include <iostream>
#include <vector>
#include <cassert>

typedef std::vector< int> Heap;

void printHeap( std::ostream &os, const Heap &heap);

static inline size_t leftIdx( const size_t idx) { return idx * 2 + 1; }
static inline size_t rightIdx( const size_t idx) { return idx * 2 + 2; }
static inline size_t firstLeafIdx( const Heap &heap) { return heap.size() / 2; }
static inline size_t lastNonLeafIdx( const Heap &heap) {
	assert( heap.size() > 1);
	return firstLeafIdx( heap) - 1;
}

static inline bool isValidIdx( size_t idx, const Heap &heap) { return idx < heap.size(); }

void maxHeapify( Heap &heap, size_t idx);
void buildMaxHeap( Heap &heap);

#endif
