#ifndef _MERGE_SORT_
#define _MERGE_SORT_

#include <vector>

// with sentinel
void merge_sort( std::vector< int> &v, std::size_t p, std::size_t r, bool less( int, int), bool print = false);

// without sentinel
void merge_sort2( std::vector< int> &v, std::size_t p, std::size_t r, bool less( int, int), bool print = false);


#endif
