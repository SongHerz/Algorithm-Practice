#ifndef _BINARY_SEARCH_HH_
#define _BINARY_SEARCH_HH_

#include <vector>
#include <limits>

// Invalid index for binary search
const std::size_t INVALID_IDX = std::numeric_limits< std::size_t>::max();

// Find val in vector v[p, r]
// And store index of the value to idx
// Return: true, if value found
//         false, value not found
bool binary_search( const std::vector< int> &v, const std::size_t p, const std::size_t r, const int val, std::size_t &idx);

// Find a value that <= val in vector v[p, r]
// And store index of the value to idx
// Return: true, if value found
//         false, value not found
bool less_eq_bound( const std::vector< int> &v, const std::size_t p, const std::size_t r, const int val, std::size_t &idx);

#endif
