#include <iostream>
#include <iomanip>
#include "monge_matrix_leftmost_min.hh"

using namespace std;

void print_matrix( ostream &os, const Matrix &m) {
	for ( size_t i = 0; i < m.size(); ++i) {
		vector< int> &cur_row = *m[ i];
		os << "    ";
		for ( size_t j = 0; j < cur_row.size(); ++j) {
			os << setw(3) << cur_row[ j];
			if ( j == cur_row.size() - 1) {
				os << std::endl;
			}
			else {
				os << ", ";
			}
		}
	}
}


void print_matrix( ostream &os, const Matrix &m, const vector< size_t> min_col_idcs) {
	for ( size_t i = 0; i < m.size(); ++i) {
		vector< int> &cur_row = *m[ i];
		os << "    ";
		for ( size_t j = 0; j < cur_row.size(); ++j) {
			if ( j == min_col_idcs[ i]) {
				os << "(" << setw(2) << cur_row[ j] << ")";
			}
			else {
				os << setw(4) << cur_row[ j];
			}
			if ( j == cur_row.size() - 1) {
				os << std::endl;
			}
			else {
				os << ", ";
			}
		}
	}
}

void test_monge_matrix( const int *v, const size_t m, const size_t n) {
	const Matrix *pm = create_matrix( v, m, n);
	std::cout << "The matrix is:" << std::endl;
	print_matrix( std::cout, *pm);

	std::cout << "Is Monge Matrix ?" << std::endl;
	std::cout << "    " << ( is_monge_matrix( *pm) ? "True" : "False") << std::endl;

	vector< size_t> min_col_idcs( 7, 0);
	monge_matrix_leftmost_min( *pm, min_col_idcs);

	std::cout << "Mininum value index for each row are: " << std::endl;
	std::cout << "    ";
	for ( size_t i = 0; i < min_col_idcs.size(); ++i) {
		std::cout << min_col_idcs[i] << ", ";
	}
	std::cout << std::endl;

	std::cout << "Circle the mininums:" << std::endl;
	print_matrix( std::cout, *pm, min_col_idcs);

	free_matrix( pm);
}

int main() {
	int v0[ 7][ 5] = {
		{10, 17, 13, 28, 23},
		{17, 22, 16, 29, 23},
		{24, 28, 22, 34, 24},
		{11, 13,  6, 17,  7},
		{45, 44, 32, 37, 23},
		{36, 33, 19, 21,  6},
		{75, 66, 51, 53, 34}
	};

	test_monge_matrix( reinterpret_cast< const int * const>( v0), 7, 5);

	return 0;
}
