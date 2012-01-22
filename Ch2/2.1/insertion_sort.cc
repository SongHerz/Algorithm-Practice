#include <iterator>
#include <iostream>
#include "insertion_sort.hh"

void insertion_sort( std::vector< int> &v, bool less( int, int), bool print) {
	if ( print) {
		std::ostream_iterator<int> out_it( std::cout, ", ");
		std::copy( v.begin(), v.end(), out_it);
		std::cout << std::endl;
	}

	for ( std::size_t i = 1; i < v.size(); ++i) {
		int key = v[i];
		assert( i < v.size());


		std::size_t j = i;
		assert( j < v.size());
		while( j > 0 && less( key, v[j - 1])) {
			assert( j < v.size());
			assert( j - 1 >= 0);
			v[ j] = v[ j - 1];
			--j;
		}
		v[ j] = key;
		assert( j < v.size());

		if ( print) {
			std::ostream_iterator<int> out_it( std::cout, ", ");
			std::copy( v.begin(), v.end(), out_it);
			std::cout << std::endl;
		}
	}
}
