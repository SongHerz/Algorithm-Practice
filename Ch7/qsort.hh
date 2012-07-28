#ifndef _QSORT_HH_
#define _QSORT_HH_

#include <stddef.h>
#include <vector>

typedef int SORT_TYPE;
size_t partation( std::vector< SORT_TYPE> &vec, size_t p, size_t r,
		bool printChangeStep = false, bool printEachStep = false);

void qsort( std::vector< SORT_TYPE> &vec, size_t p, size_t r);


size_t randomizedPartation( std::vector< SORT_TYPE> &vec, size_t p, size_t r,
		bool printChangeStep = false, bool printEachStep = false);

void randomizedQsort( std::vector< SORT_TYPE> &vec, size_t p, size_t r);

#endif
