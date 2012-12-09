#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	double a;
	vector< double> results;

	while( cin >> a) {
		results.push_back( ::sqrt( a));
	}

	for ( vector<double>::const_reverse_iterator rit = results.rbegin();
			rit != results.rend(); ++rit) {
		cout << setiosflags(ios::fixed) 
			<< setprecision(4) 
			<< ( *rit)
		       	<< endl;

	}

	return 0;
}
