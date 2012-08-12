#ifndef _COUNTING_SORT_HH_
#define _COUNTING_SORT_HH_

#include <stddef.h>
#include <vector>

typedef int SORT_TYPE;

// A is input
// B is output
// k is the value of max element(s) in A
void countingSort( const std::vector<SORT_TYPE> &A, std::vector<SORT_TYPE> &B, const size_t k);



#endif
