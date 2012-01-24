#include <algorithm>
#include <cassert>
#include "inversion.hh"


static void merge( std::vector< int> &v, const std::size_t p, const std::size_t q, const std::size_t r, std::size_t &inv_count) {
	assert( p <= q);
	assert( q < r);
	std::vector< int> L( v.begin() + p, v.begin() + q + 1);
	std::vector< int> R( v.begin() + q + 1, v.begin() + r + 1);

	std::vector< int>::const_iterator L_it = L.begin();
	std::vector< int>::const_iterator R_it = R.begin();
	const std::vector< int>::const_iterator L_end = L.end();
	const std::vector< int>::const_iterator R_end = R.end();
	for ( std::size_t v_idx = p; v_idx <=r; ++v_idx) {
		if ( L_it == L.end()) {
			// L drained
			std::copy( R_it, R_end, v.begin() + v_idx);
			break;
		}
		if ( R_it == R.end()) {
			// R drained
			std::copy( L_it, L_end, v.begin() + v_idx);
			break;
		}
		if ( *L_it > *R_it) {
			v[ v_idx] = *L_it;
			++L_it;
			inv_count += std::distance( R_it, R_end);
		}
		else {
			assert( *L_it <= *R_it);
			v[ v_idx] = *R_it;
			++R_it;
		}
	}
}


static void merge_sort( std::vector< int> &v, const std::size_t p, const std::size_t r, std::size_t &inv_count) {
	assert( p <= r);
	if ( p == r) {
		return;
	}

	const std::size_t q = ( p + r) / 2;
	assert( q < r);
	merge_sort( v, p, q, inv_count);
	merge_sort( v, q + 1, r, inv_count);
	merge( v, p, q, r, inv_count);
}


std::size_t count_inversion( const std::vector< int> &v) {
	std::vector< int> vec = v;
	std::size_t inv_count = 0;
	merge_sort( vec, 0, vec.size() - 1, inv_count);
	return inv_count;
}
