#include <cstdlib>
#include <iostream>


using namespace std;

int main() {
	int a;

	while( cin >> a) {
		int nums = ::abs( a - 1) + 1;
		int sum = (a + 1) * (nums / 2);
		if ( nums % 2 != 0) {
			sum += ( a + 1) / 2;
		}
		cout << sum << std::endl;
	}
	return 0;
}
