#include <cassert>
#include "binary_search.hh"

bool binary_search( const std::vector< int> &v, const std::size_t p, const std::size_t r, const int val, std::size_t &idx) {
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


bool less_eq_bound( const std::vector< int> &v, const std::size_t p, const std::size_t r, const int bound, std::size_t &idx) {
	assert( v.size() <= INVALID_IDX);
	assert( p <= r);

	std::size_t q = ( p + r) / 2;

	if ( p == r) {
	       	if( v[q] <= bound) {
			idx = p;
			return true;
		}
		else {
			idx = INVALID_IDX;
			return false;
		}
	}
	assert( p < r);

	if ( v[q] <= bound) {
		assert( q < r);
		std::size_t idx1;
		bool found1 = less_eq_bound( v, q + 1, r, bound, idx1);
		if ( found1) {
			idx = idx1;
		}
		else {
			idx = q;
		}
		return true;
	}
	else {
		assert( v[q] > bound);
		if ( p == q) {
			idx = INVALID_IDX;
			return false;
		}
		return less_eq_bound( v, p, q - 1, bound, idx);
	}
}
