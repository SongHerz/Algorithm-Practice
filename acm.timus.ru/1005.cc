#include <iostream>
#include <vector>
#include <map>
#include <cassert>

// This problem can be bruteforce solved.
// But it is not that fun with that method.
//
// By referencing http://people.csail.mit.edu/bdean/6.046/dp/
// item 7 "Balence partition".
// This can be solved by DP.

using namespace std;

typedef std::pair< int, int> IJPair;

struct IJPairComp {
	bool operator() ( const IJPair &p0, const IJPair &p1) const {
		if ( p0.first != p1.first) {
			return p0.first < p1.first;
		}
		else if ( p0.second != p1.second) {
			return p0.second < p1.second;
		}
		else return false;
	}
};

typedef map< IJPair, bool, IJPairComp> IJTab;

// Store value of P( i, j)
IJTab ijTab;


int dp( const std::Vector< int> &stones, int j, IJTab &ijTab) {

	for ( int i = 0; i < stones.size(); ++i) {
		int w = stones[ i];

		if ( i == 0) {
			assert( ijTab.empty());

			IJPair ijPair( 0, w);
			IJTab[ ijPair] = true;
		}
		else {
			IJPair prev0( i - 1, j);
			IJPair prev1( i - 1, j - w);








}


int main() {
	int num;
	cin >> num;

	assert( num > 0);

	std::vector< int> stones( num, 0);

	for ( int i = 0; i < num; ++i) {
		int stone;
		cin >> stone;
		assert( stone > 0);
		stones[ i] = stone;
	}



	return 0;
}
