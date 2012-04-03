
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
	
	maxHeapify( heap, 1);
	os << "After max heapify" << std::endl;
	printHeap( os, heap);
}

int main() {
	test_maxHeapify( std::cout);
	return 0;
}
