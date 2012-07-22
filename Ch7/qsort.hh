#ifndef _QSORT_HH_
#define _QSORT_HH_

#include <stddef.h>
#include <vector>

typedef int SORT_TYPE;
size_t partation( std::vector< SORT_TYPE> &vec, size_t p, size_t r, bool printStep = false);

#endif