
#include <iostream>
#include <fstream>
#include "heap.hh"

using namespace std;

void test_maxHeapify( ostream &os) {
	Heap heap;
	ifstream data( "test_maxHeapify.in");
	int node;
	while ( data >> node) {
		heap.push_back( node);
	}
	data.close();

	os << "Before max heapify" << std::endl;
	printHeap( os, heap);
	
	maxHeapify( heap, heap.size(), 1);
	os << "After max heapify" << std::endl;
	printHeap( os, heap);
}

void test_buildMaxHeap( ostream &os) {
	Heap heap;
	ifstream data( "test_buildMaxHeap.in");
	int node;
	while ( data >> node) {
		heap.push_back( node);
	}
	data.close();

	os << "Before build max heap" << std::endl;
	printHeap( os, heap);
	
	buildMaxHeap( heap, heap.size());
	os << "After build max heap" << std::endl;
	printHeap( os, heap);
}

int main() {
	test_maxHeapify( std::cout);
	test_buildMaxHeap( std::cout);
	return 0;
}
