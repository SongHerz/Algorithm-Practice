#include <iostream>
#include <iomanip>
#include "monge_matrix_leftmost_min.hh"

using namespace std;

void print_matrix( ostream &os, const Matrix &m) {
	for ( size_t i = 0; i < m.size(); ++i) {
		vector< int> &cur_row = *m[ i];
		for ( size_t j = 0; j < cur_row.size() - 1; ++j) {
			os << setw(3) << cur_row[ j] << ", ";
		}
		os << cur_row[ cur_row.size() - 1] << std::endl;
	}
}


int main() {
	int v[ 7][ 5] = {
		{10, 17, 13, 28, 23},
		{17, 22, 16, 29, 23},
		{24, 28, 22, 34, 24},
		{11, 13,  6, 17,  7},
		{45, 44, 32, 37, 23},
		{36, 33, 19, 21,  6},
		{75, 66, 51, 53, 34}
	};

	const Matrix *pm = create_matrix( reinterpret_cast<const int* const>(v), 7, 5);
	print_matrix( std::cout, *pm);

	std::cout << "Is Monge Matrix ? " << ( is_monge_matrix( *pm) ? "True" : "False") << std::endl;

	vector< size_t> min_col_idcs( 7, 0);
	monge_matrix_leftmost_min( *pm, min_col_idcs);

	for ( size_t i = 0; i < min_col_idcs.size(); ++i) {
		std::cout << min_col_idcs[i] << ", ";
	}
	std::cout << std::endl;

	return 0;
}
