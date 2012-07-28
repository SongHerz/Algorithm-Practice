#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "random.hh"

using namespace std;

void Random::srand() {
	srand( time(NULL));
}

void Random::srand( unsigned int seed) {
	::srand( seed);
}

size_t Random::random( const size_t a, const size_t b) {
	size_t min = a;
	size_t max = b;
	if ( max < min) {
		swap( min, max);
	}
	// generate a random number in [0, max - min]
	const size_t r = ::rand() % ( max - min + 1);
	return min + r;
}
