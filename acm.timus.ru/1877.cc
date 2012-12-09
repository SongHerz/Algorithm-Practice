#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main() {
	// consider scenarios
	// first second
	//  even   odd   yes
	//  even   even  yes
	//  odd    odd   yes
	//  odd    even  no
	string first;
	string second;

	cin >> first;
	cin >> second;


	const char last0 = *first.rbegin();
	const char last1 = *second.rbegin();

	if ( ( last0 - '0') % 2 == 1 && ( last1 - '0') % 2 == 0) {
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
	}

	return 0;
}


