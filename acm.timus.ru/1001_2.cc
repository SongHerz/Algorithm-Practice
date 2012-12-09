#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double results[65536 * 2];

int main() {
	double a;
	size_t i = 0;

	while ( cin >> a) {
		results[ i++] = ::sqrt( a);
	}

	while ( i != 0) {
		cout << setiosflags(ios::fixed) 
			<< setprecision(4) 
			<< results[ --i]
		       	<< endl;

	}

	return 0;
}
