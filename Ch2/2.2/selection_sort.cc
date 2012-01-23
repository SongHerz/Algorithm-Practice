#include <iterator>
#include <iostream>
#include <algorithm>
#include "selection_sort.hh"

void selection_sort( std::vector< int> &v, bool less( int, int), bool print) {
	if ( print) {
		std::ostream_iterator<int> out_it( std::cout, ", ");
		std::copy( v.begin(), v.end(), out_it);
		std::cout << std::endl;
	}

	for ( std::size_t i = 0; i < v.size() - 1; ++i) {
		// find the minimum value index
		int min_val_idx = i;
		for ( std::size_t j = i + 1; j < v.size(); ++j) {
			if ( less( v[j], v[ min_val_idx])) {
				min_val_idx = j;
			}
		}
		std::swap( v[ i], v[ min_val_idx]);

		if ( print) {
			std::ostream_iterator<int> out_it( std::cout, ", ");
			std::copy( v.begin(), v.end(), out_it);
			std::cout << std::endl;
		}
	}
}

			

