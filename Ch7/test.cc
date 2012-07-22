#include <iostream>
#include "qsort.hh"

static void test_partation() {
	SORT_TYPE elems[] = { 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};

	std::vector< SORT_TYPE> vec( elems, elems + sizeof( elems) / sizeof( elems[0]));
	size_t pivot_pos = partation( vec, 0, vec.size() - 1, true, true);
	std::cout << "pivot pos = " << pivot_pos << std::endl;
}


int main() {
	test_partation();
	return 0;
}
