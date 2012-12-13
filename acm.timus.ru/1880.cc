#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

typedef vector<int> IntVec;

// Given two vectors, output common eigen value of v0 and v1
void eigenValues( const IntVec &v0, const IntVec &v1, IntVec &v) {
	IntVec::const_iterator it0 = v0.begin();
	IntVec::const_iterator it1 = v1.begin();

	while ( it0 != v0.end() && it1 != v1.end()) {
		int i0 = *it0;
		int i1 = *it1;

		if ( i0 == i1) {
			v.push_back( i0);
			++it0;
			++it1;
		}
		else if ( i0 < i1) {
			++it0;
		}
		else {
			assert( i0 > i1);
			++it1;
		}
	}
}

static bool cmp( const IntVec* pv0, const IntVec *pv1) {
	return pv0->size() < pv1->size();
}

int main() {
	IntVec v0;
	IntVec v1;
	IntVec v2;

	IntVec* intVecs[] = { &v0, &v1, &v2};

	for ( size_t i = 0; i < 3; ++i) {
		int n;

		cin >> n;
		for ( ; n > 0; --n) {
			int m;
			cin >> m;
			intVecs[ i]->push_back( m);
		}
	}

	sort( intVecs, intVecs + sizeof( intVecs) / sizeof( intVecs[0]), cmp);

	IntVec v;
	eigenValues( *intVecs[0], *intVecs[1], v);
	IntVec vv;
	eigenValues( *intVecs[2], v, vv);

	cout << vv.size() << endl;

	return 0;
}
	
