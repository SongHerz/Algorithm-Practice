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

	if ( N == 0) {
		cout << 10 << endl;
		return 0;
	}
	else if ( N == 1) {
		cout << 1 << endl;
		return 0;
	}
	else {

		for ( int i = 9; i > 1; --i) {
			N = decomposeN( N, i, factors);
		}

		if ( N != 1 ) {
			assert( N > 9);
			cout << -1 << endl;
			return 0;
		}

		for ( std::vector<int>::const_reverse_iterator rit = factors.rbegin(); rit != factors.rend(); ++rit) {
			int m = *rit;
			assert( m < 10);
			cout << m;
		}
		cout << endl;
		return 0;
	}

	return 0;
}


