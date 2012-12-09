#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int groups;

	cin >> groups;

	int *votersInGroups = new int[ groups];

	for ( size_t i = 0; i < groups; ++i) {
		int voters;
		cin >> voters;
		votersInGroups[ i] = voters;
	}
	std::sort( votersInGroups, votersInGroups + groups);


	int min = 0;

	for ( size_t i = 0; i <= groups/2; ++i) {
		min += votersInGroups[ i]/2 + 1;
	}

	cout << min;

	delete [] votersInGroups;

	return 0;
}

