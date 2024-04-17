#define NDEBUG

#include <bits/stdc++.h>
using namespace std;

#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int x = 10;  // pretend this variable is important

int main() {
	//
	dbg(x);  // Line(10) -> x = 10
	x = 5000;
	dbg(x);  // Line(12) -> x = 5000

	assert(false);
	cout << "OK" << endl;

}