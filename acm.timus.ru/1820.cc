#include <iostream>

using namespace std;


int main() {
	int n, K;

	cin >> n >> K;
	int time = 0;

	if ( n <= K) {
		time = 2;
	}
	else {
		int sides = n * 2;
		time = sides / K;

		if ( sides % K != 0) {
			++time;
		}
	}


	cout << time << endl;

	return 0;
}
