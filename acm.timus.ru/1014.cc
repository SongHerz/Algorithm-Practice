#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// divide N by dividend,
// and put each divident into ary
int decomposeN( int N, int dividend, std::vector<int> &ary) {
	assert( N > 0);

	while ( N != 1) {
		if ( N % dividend == 0) {
			ary.push_back( dividend);
			N /= dividend;
		}
		else {
			break;
		}
	}
	return N;
}

int main() {
	int N;
	cin >> N;

	std::vector<int> factors;

	int newN = decomposeN( N, 7, factors);
	newN = decomposeN( newN, 5, factors);
	newN = decomposeN( newN, 3, factors);
	newN = decomposeN( newN, 2, factors);

	if ( newN > 9) {
		return -1;
	}

	// Now factors contains factors that less than 10,
	// from 7 downto 2. We should combine them to get the minimum number.
	std::vector<int> shrinkedFactors;

	for ( size_t i = 0; i < factors.size(); ) {
		int m = factors[ i];
		while ( m * factors[ i + 1] < 10 && i + 1 < factors.size()) {
			m *= factors[ i];
			++i;
		}
		shrinkedFactors.push_back( m);
		++i;
	}

	for ( std::vector<int>::const_reverse_iterator rit = shrinkedFactors.rbegin(); rit != shrinkedFactors.rend(); ++rit) {
		int m = *rit;
		assert( m < 10);
			
		cout << m;
	}
	cout << endl;

	return 0;
}


