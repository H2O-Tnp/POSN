#include <bits/stdc++.h>
using namespace std;

namespace Solution1 {

int solve(int x) { return x < 100; }

}  // namespace Solution1

namespace Solution2 {

int solve(int x) { return x < 110; }

}  // namespace Solution2

int main() {
	mt19937 rng(time(nullptr));
    // rng.seed(45218965);
	while (true) {
		int x = rng() % 1000;
		// int x = rng();

		int out1 = Solution1::solve(x);
		int out2 = Solution2::solve(x);
		if (out1 != out2) {
			cout << x << " " << out1 << " " << out2 << endl;
			exit(0);
		}
	}
}