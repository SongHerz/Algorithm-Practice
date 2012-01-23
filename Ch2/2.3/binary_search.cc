#include <cassert>
#include "binary_search.hh"

bool binary_search( const std::vector< int> &v, std::size_t p, std::size_t r, int val, std::size_t &idx) {
	assert( v.size() <= INVALID_IDX);
	assert( p <= r);

	std::size_t q = ( p + r)/2;

	if ( v[q] == val) {
		idx = q;
		return true;
	}
	if ( v[q] < val) {
		assert( q <=r);
		if ( q == r) {
			idx = INVALID_IDX;
			return false;
		}
		return binary_search( v, q + 1, r, val, idx);
	}
	else {
		assert( v[q] > val);
		assert( p <= q);
		if ( p == q) {
			idx = INVALID_IDX;
			return false;
		}
		return binary_search( v, p, q - 1, val, idx);
	}
	assert(0 && "Should not be here");
}
