#include <iostream>
#include <cassert>


using namespace std;

// 
// For n digits, its valid number are calculated by
// P(n, K) = P( n - 1, K)*( K - 1) + P( n - 2, K)*(K - 1)
// Consider we only add one more digit to the most signaficient position.
// We add:
// 1. One non-zero digit based on P( n - 1, K)
// 2. One non-zero digit and a zero based on P( n - 2, K)
int amount( int N, int K) {
	int pre;	// P( n - 1, K)
	int prepre;	// P( n - 2, K)

	assert( N >= 2);
	// calculate pre and prepre
	prepre = 1;	// P( 0, K), No digit is a valid number
	pre = K - 1;	// P( 1, K)

	for ( int n = 2; n <=N ; ++n) {
		int result = (pre + prepre) * ( K - 1);
		prepre = pre;
		pre = result;
	}

	return pre;
}

int main() {
	int N, K;

	cin >> N;
	cin >> K;

	cout << amount( N, K) << endl;
	return 0;
}
