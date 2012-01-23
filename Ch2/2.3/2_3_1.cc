#include <vector>
#include <iterator>
#include <iostream>
#include "merge_sort.hh"

bool less( int a, int b) {
	return a < b;
}

bool check_same_vec( std::vector< int> &vec0, std::vector< int> &vec1) {
	if ( vec0.size() != vec1.size()) {
		return false;
	}

	for ( std::size_t i = 0; i < vec0.size(); ++i) {
		if ( vec0[ i] != vec1[ i]) {
			return false;
		}
	}
	return true;
}


int main() {
	int v[] = { 3, 41, 52, 26, 38,57, 9, 49};
	std::vector< int> vec( &v[0], &v[ sizeof(v)/sizeof(v[0])]);

	std::cout << "Sequence: ";
	std::ostream_iterator<int> out_it( std::cout, ", ");
	copy( vec.begin(), vec.end(), out_it);
	std::cout << std::endl << std::endl;

	merge_sort( vec, 0, vec.size() - 1, less, true);

	std::cout << "========" << std::endl;
	std::cout << "Check merge_sort2 ..." << std::endl;
	std::vector< int> vec1( &v[0], &v[ sizeof(v)/sizeof(v[0])]);
	merge_sort2( vec1, 0, vec1.size() - 1, less, false);

	if ( check_same_vec( vec, vec1)) {
		std::cout << "merge_sort2 success" << std::endl;
	}
	else {
		std::cout << "merge_sort2 fail" << std::endl;
	}


	return 0;
}

