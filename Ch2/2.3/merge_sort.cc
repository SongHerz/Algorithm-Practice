#include <iterator>
#include <iostream>
#include <limits>
#include <cassert>
#include "merge_sort.hh"


void merge( std::vector< int> &v, std::size_t p, std::size_t q, std::size_t r, bool less( int, int), bool print = false);

void merge2( std::vector< int> &v, std::size_t p, std::size_t q, std::size_t r, bool less( int, int), bool print = false);


// FIXME: No value in v should be SIZE_T_MAX, or the merge won't work correctly.
void merge( std::vector< int> &v, std::size_t p, std::size_t q, std::size_t r, bool less( int, int),  bool print) {
	assert( p <= q);
	assert( q <= r);

	std::vector< int> L( v.begin() + p, v.begin() + q + 1);
	L.push_back( std::numeric_limits< int>::max());
	std::vector< int> R( v.begin() + q + 1, v.begin() +r + 1);
	R.push_back( std::numeric_limits< int>::max());

	std::size_t L_idx = 0;
	std::size_t R_idx = 0;
	for ( std::size_t v_idx = p; v_idx <= r; ++v_idx) {
		if ( less( L[ L_idx], R[ R_idx])) {
			v[ v_idx] = L[ L_idx];
			++L_idx;
		}
		else {
			v[ v_idx] = R[ R_idx];
			++R_idx;
		}
	}

	if ( print) {
		std::ostream_iterator<int> out_it( std::cout, ", ");
		copy( L.begin(), L.end(), out_it);
		std::cout << std::endl;
		std::cout << " +" << std::endl;
		copy( R.begin(), R.end(), out_it);
		std::cout << std::endl;
		std::cout << " ==>" << std::endl;
		copy( v.begin() + p, v.begin() + r + 1, out_it);
		std::cout << std::endl;
		std::cout << std::endl;
	}
}



void merge_sort( std::vector< int> &v, std::size_t p, std::size_t r, bool less( int, int), bool print) {
	assert( p <= r);
	if ( p == r) {
		return;
	}
	std::size_t q = ( p + r) / 2;
	merge_sort( v, p, q, less, print);
	merge_sort( v, q + 1, r, less, print);
	merge( v, p, q, r, less, print);
}



void merge2( std::vector< int> &v, std::size_t p, std::size_t q, std::size_t r, bool less( int, int),  bool print) {
	assert( p <= q);
	assert( q <= r);

	std::vector< int> L( v.begin() + p, v.begin() + q + 1);
	std::vector< int> R( v.begin() + q + 1, v.begin() +r + 1);

	std::size_t L_idx = 0;
	std::size_t R_idx = 0;
	for ( std::size_t v_idx = p; v_idx <= r; ++v_idx) {
		if ( L_idx == L.size()) {
			copy( R.begin() + R_idx, R.end(), v.begin() + v_idx);
			break;
		}
		if ( R_idx == R.size()) {
			copy( L.begin() + L_idx, L.end(), v.begin() + v_idx);
			break;
		}

		if ( less( L[ L_idx], R[ R_idx])) {
			v[ v_idx] = L[ L_idx];
			++L_idx;
		}
		else {
			v[ v_idx] = R[ R_idx];
			++R_idx;
		}
	}

	if ( print) {
		std::ostream_iterator<int> out_it( std::cout, ", ");
		copy( L.begin(), L.end(), out_it);
		std::cout << std::endl;
		std::cout << " +" << std::endl;
		copy( R.begin(), R.end(), out_it);
		std::cout << std::endl;
		std::cout << " ==>" << std::endl;
		copy( v.begin() + p, v.begin() + r + 1, out_it);
		std::cout << std::endl;
		std::cout << std::endl;
	}
}


void merge_sort2( std::vector< int> &v, std::size_t p, std::size_t r, bool less( int, int), bool print) {
	assert( p <= r);
	if ( p == r) {
		return;
	}
	std::size_t q = ( p + r) / 2;
	merge_sort2( v, p, q, less, print);
	merge_sort2( v, q + 1, r, less, print);
	merge2( v, p, q, r, less, print);
}
