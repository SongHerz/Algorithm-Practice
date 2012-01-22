#include <iostream>
#include "insertion_sort.hh"

bool less( int a, int b) {
	return a < b;
}


int main() {
	int v[] = { 31, 41, 59, 26, 41, 58};
	std::vector<int> vec( &v[0], &v[ sizeof(v) / sizeof(v[0])]);

	insertion_sort( vec, less, true);

	return 0;
}
