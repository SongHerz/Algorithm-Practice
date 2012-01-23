#include <vector>
#include <iterator>
#include <iostream>
#include "merge_sort.hh"

bool less( int a, int b) {
	return a < b;
}

int main() {
	int v[] = { 5, 2, 4, 7, 1, 3, 2, 6};
	std::vector< int> vec( &v[0], &v[ sizeof(v)/sizeof(v[0])]);

	std::cout << "Sequence: ";
	std::ostream_iterator<int> out_it( std::cout, ", ");
	copy( vec.begin(), vec.end(), out_it);
	std::cout << std::endl << std::endl;

	merge_sort( vec, 0, vec.size() - 1, less, true);

	return 0;
}

