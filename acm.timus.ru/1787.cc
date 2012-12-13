#include <iostream>

using namespace std;


int main() {
	int k, n;
	
	cin >> k >> n;

	int jam = 0;
	for ( int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		jam += m;	// m cars coming
		jam -= k;	// k cars turned
		if ( jam < 0) {
			jam = 0;
		}
	}

	cout << jam << endl;

	return 0;
}
