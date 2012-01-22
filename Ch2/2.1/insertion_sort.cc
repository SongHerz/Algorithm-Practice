#include "insertion_sort.hh"

void insertion_sort( std::vector< int> &v, bool less( int, int)) {
	for ( std::size_t i = 1; i < v.size(); ++i) {
		int key = v[i];
		
			
		std::size_t j = i - 1;
		while( j >= 0 && less( key, v[j])) {
			v[ j + 1] = v[ j];
			--j;
		}
		v[ j + 1] = key;
	}
}
