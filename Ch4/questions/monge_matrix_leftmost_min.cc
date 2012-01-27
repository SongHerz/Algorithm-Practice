#include <limits>
#include <algorithm>
#include <cassert>
#include "monge_matrix_leftmost_min.hh"

using namespace std;

static const size_t INVALID_IDX = numeric_limits< size_t>::max();

const Matrix *create_matrix( const int * const v, const size_t m, const size_t n) {
	Matrix *matrix = new Matrix;

	for ( size_t i = 0; i < m; ++i) {
		vector<int> *row = new vector<int>;
		for ( size_t j = 0; j < n; ++j) {
			row->push_back( *(v + i * n + j));
		}
		matrix->push_back( row);
	}

	return matrix;
}

void free_matrix( const Matrix *m) {
	for ( size_t i = 0; i < m->size(); ++i) {
		delete m->at( i);
	}
	delete m;
}

bool is_monge_matrix( const Matrix &m) {
	size_t rows = m.size();
	size_t cols = m[0]->size();

	if ( rows < 2 || cols < 2) {
		// a monge matrix at lease has 2 rows and 2 cols
		return false;
	}

	bool is_mm = true;

	for ( size_t i = 0; i < rows - 1; ++i) {
		const vector<int> &cur_row = *m[ i];
		const vector<int> &cur_row_p1 = *m[ i + 1];

		assert( cols == cur_row.size());
		assert( cols == cur_row_p1.size());

		for ( size_t j = 0; j < cols - 1; ++j) {
			if ( !( cur_row[j] + cur_row_p1[j + 1] <= cur_row[j + 1] + cur_row_p1[ j])) {
				is_mm = false;
				break;
			}
		}
		if ( !is_mm) {
			break;
		}
	}
			

	return is_mm;
}


void __monge_matrix_leftmost_min( const Matrix &m, const vector< size_t> &row_idcs, vector< size_t> &min_col_idcs) {
	assert(row_idcs.size() <= m.size());

	if ( row_idcs.size() == 1) {
		size_t cur_row_idx = row_idcs[0];
		const vector< int> &row = *m[ cur_row_idx];
		vector< int>::const_iterator min_col_it = min_element( row.begin(), row.end());
		size_t min_col_idx = min_col_it - row.begin();
		assert( min_col_idx < row.size());
		assert( min_col_idcs[ cur_row_idx] == INVALID_IDX);
		min_col_idcs[ cur_row_idx] = min_col_idx;
		return;
	}
	else {
		// prepare even rows
		vector< size_t> even_row_idcs;
		for ( unsigned i = 0; i < row_idcs.size(); i += 2) {
			even_row_idcs.push_back( row_idcs[ i]);
		}

		// get mininum idx for even rows
		__monge_matrix_leftmost_min( m, even_row_idcs, min_col_idcs);

		// calculate odd rows
		for ( unsigned i = 1; i < row_idcs.size(); i += 2) {
			assert( i - 1 >= 0 && i - 1 < row_idcs.size());
			const size_t cur_row_idx = row_idcs[ i];
			const vector< int> &cur_row = *m[ cur_row_idx];

			const size_t may_min_col_left_idx = min_col_idcs[ row_idcs[i - 1]];
			assert( may_min_col_left_idx != INVALID_IDX);
			const size_t may_min_col_right_idx = i + 1 < row_idcs.size() ? min_col_idcs[ row_idcs[ i + 1]] : m[ 0]->size() - 1;
			assert( may_min_col_right_idx != INVALID_IDX);

			const vector< int>::const_iterator min_col_it = min_element( cur_row.begin() + may_min_col_left_idx, cur_row.begin() + may_min_col_right_idx + 1);
			const size_t min_col_idx = min_col_it - cur_row.begin();

			assert( min_col_idcs[ cur_row_idx] == INVALID_IDX);
			min_col_idcs[ cur_row_idx] = min_col_idx;
		}
		return;
	}
}


void monge_matrix_leftmost_min( const Matrix &m, vector< size_t> &min_col_idcs) {
	assert( m.size() > 0);
	assert( m.size() == min_col_idcs.size());

	for ( size_t i = 0; i < min_col_idcs.size(); ++i) {
		min_col_idcs[ i] = INVALID_IDX;
	}

	vector< size_t> row_idcs;
	for( size_t i = 0; i < m.size(); ++i) {
		row_idcs.push_back( i);
	}

	__monge_matrix_leftmost_min( m, row_idcs, min_col_idcs);
}
