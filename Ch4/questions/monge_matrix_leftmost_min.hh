#ifndef _MONGE_MATRIX_LEFTMOST_MIN_HH_
#define _MONGE_MATRIX_LEFTMOST_MIN_HH_

#include <vector>

typedef std::vector< std::vector< int> *> Matrix;

const Matrix *create_matrix( const int * const v, const std::size_t m, const std::size_t n);

void free_matrix( const Matrix *m);

bool is_monge_matrix( const Matrix &m);

void monge_matrix_leftmost_min( const Matrix &m, std::vector< std::size_t> &min_col_idcs);


#endif
