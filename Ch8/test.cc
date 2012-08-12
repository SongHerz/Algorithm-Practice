#include <iostream>
#include <iterator>
#include <algorithm>
#include "countingSort.hh"


using namespace std;

void test_countingSort( const std::vector< SORT_TYPE> &in) {
	std::vector< SORT_TYPE> B( in.size(), 0);
	const SORT_TYPE k = *max_element( in.begin(), in.end());

	countingSort( in, B, k);

	ostream_iterator<SORT_TYPE> oitIn( cout, ", ");
	ostream_iterator<SORT_TYPE> oitB( cout, ", ");

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << "Input vector:" << std::endl;
	std::copy( in.begin(), in.end(), oitIn);
	std::cout << std::endl;
	std::cout << "Max element:" << std::endl;
	std::cout << k << std::endl;
	std::cout << "Output vector:" << std::endl;
	std::copy( B.begin(), B.end(), oitB);
	std::cout << std::endl;
}


int main() {
	SORT_TYPE in0[] = {2, 5, 3, 0, 2, 3, 0, 3};
	SORT_TYPE in1[] = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};

	test_countingSort( std::vector<SORT_TYPE>( in0, in0 + sizeof( in0) / sizeof( in0[0])));
	test_countingSort( std::vector<SORT_TYPE>( in1, in1 + sizeof( in1) / sizeof( in1[0])));

	return 0;
}
