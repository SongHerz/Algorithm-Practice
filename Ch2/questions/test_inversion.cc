#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "inversion.hh"

const int ELEMENTS = 100;

int main() {
	std::vector< int> v;
	for ( int i = ELEMENTS; i > 0; --i) {
		v.push_back( i);
	}

	std::ostream_iterator< int> out_it( std::cout, ", ");
	std::cout << "Vector: ";
	std::copy( v.begin(), v.end(), out_it);
	std::cout << std::endl;


	std::size_t inversions = count_inversion( v);
	std::cout << "Inversions: " << inversions << std::endl;

	// There should be ( ELEMENTS - 1)*((ELEMENTS - 1) + 1)/2 inversions.
	// ( ELEMENTS - 1) * ELEMENTS / 2
	std::size_t expected_inversions = ( ELEMENTS - 1) * ELEMENTS / 2;
	if ( inversions == expected_inversions) {
		std::cout << "success" << std::endl;
	}
	else {
		std::cout << "fail" << std::endl;
	}

	return 0;
}


