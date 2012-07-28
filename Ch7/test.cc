#include <iostream>
#include <iterator>
#include <algorithm>
#include "qsort.hh"

#define ARY_SIZE( ary)	( sizeof( ary) / sizeof( ary[0]))

static void do_test_partation( const SORT_TYPE *elems, const size_t size) {
	std::cout << std::endl;
	std::cout << "Partation one array:" << std::endl;
	std::vector< SORT_TYPE> vec( elems, elems + size);
	size_t pivot_pos = partation( vec, 0, vec.size() - 1, true, true);
	std::cout << "pivot pos = " << pivot_pos << std::endl;
}

static void do_test_qsort( const SORT_TYPE *elems, const size_t size) {
	std::cout << std::endl;
	std::vector< SORT_TYPE> vec( elems, elems + size);
	std::cout << "Original array: " << std::endl;
	copy( vec.begin(), vec.end(), std::ostream_iterator< SORT_TYPE>( std::cout, ", "));
	std::cout << std::endl;

	qsort( vec, 0, vec.size() - 1);
	std::cout << "Qsorted array:  " << std::endl;
	copy( vec.begin(), vec.end(), std::ostream_iterator< SORT_TYPE>( std::cout, ", "));
	std::cout << std::endl;
}

static void test_partation() {
	SORT_TYPE elems0[] = { 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
	SORT_TYPE elems1[] = { 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11};
	SORT_TYPE elems2[] = { 4, 5, 6, 1, 2, 3, 7, 8, 9, 10, 11, 12};

	do_test_partation( elems0, ARY_SIZE( elems0));
	do_test_partation( elems1, ARY_SIZE( elems1));
	do_test_partation( elems2, ARY_SIZE( elems2));

	do_test_qsort( elems0, ARY_SIZE( elems0));
	do_test_qsort( elems1, ARY_SIZE( elems1));
	do_test_qsort( elems2, ARY_SIZE( elems2));
}


int main() {
	test_partation();
	return 0;
}
