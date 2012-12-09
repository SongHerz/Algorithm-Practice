#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	int k;
	string marks;

	cin >> n;
	cin >> marks;

	k = marks.size();

	int result = 1;

	for ( int i = n; i > 0; i -= k) {
		result *= i;
	}

	cout << result;

	return 0;
}
