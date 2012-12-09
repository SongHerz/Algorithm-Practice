#include <iostream>

using namespace std;


int main() {
	int a;
	
	while( cin >> a) {
		if ( a <= 4) {
			cout << "few" << endl;
		}
	       	else if ( a <= 9) {
			cout << "several" << endl;
		}
		else if ( a <= 19) {
			cout << "pack" << endl;
		}
		else if ( a <= 49) {
			cout << "lots" << endl;
		}
		else if ( a <= 99) {
			cout << "horde" << endl;
		}
		else if ( a<= 249) {
			cout << "throng" << endl;
		}
		else if ( a <= 499) {
			cout << "swarm" << endl;
		}
		else if ( a <= 999) {
			cout << "zounds" << endl;
		}
		else {
			cout << "legion" << endl;
		}
	}

	return 0;
}
					
