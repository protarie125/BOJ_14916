#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

vi countAns;

int solve(int n) {
	if (n < 0) {
		return -1;
	}

	if (-1 == countAns[n]) {
		return -1;
	}

	if (-2 == countAns[n]) {
		auto ans1 = int{ -1 };
		auto v1 = solve(n - 2);
		if (-1 != v1) {
			ans1 = v1 + 1;
		}

		auto ans2 = int{ -1 };
		auto v2 = solve(n - 5);
		if (-1 != v2) {
			ans2 = v2 + 1;
		}

		if (-1 == ans1 && -1 == ans2) {
			countAns[n] = -1;
		}
		else if (-1 == ans1) {
			countAns[n] = ans2;
		}
		else if (-1 == ans2) {
			countAns[n] = ans1;
		}
		else {
			countAns[n] = ans1 < ans2 ? ans1 : ans2;
		}
	}

	return countAns[n];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	countAns = vi(n + 1, -2);

	countAns[0] = 0;
	countAns[1] = -1;

	cout << solve(n);

	return 0;
}