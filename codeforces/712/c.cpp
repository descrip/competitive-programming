#include <bits/stdc++.h>
using namespace std;

int main() {
	// TODO: Check TLE.
	int X, Y; cin >> Y >> X;
	int A[3]; A[0] = A[1] = A[2] = X;
	int ans = 0;
	while (true) {
		//cout << A[0] << ' ' << A[1] << ' ' << A[2] << '\n';
		++ans;
		A[0] = A[1] + A[2] - 1;
		if (A[0] >= Y) {
			cout << ans+2 << '\n';
			return 0;
		}
		sort(A, A+3);
	}
}

