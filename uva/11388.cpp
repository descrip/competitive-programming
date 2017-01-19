#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; ++i) {
		int a, b; cin >> a >> b;
		if (b % a != 0)
			cout << "-1\n";
		else cout << a << ' ' << b << '\n';
	}
}
