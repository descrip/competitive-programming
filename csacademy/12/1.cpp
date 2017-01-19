#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B; cin >> A >> B;
	int ans = 0;
	for (int i = A; i <= B; ++i) {
		double x = sqrt(i);
		if (x == (int)x)
			ans++;
	}
	cout << ans << '\n';
}

