#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; ++i) {
		double C, F; cin >> C >> F;
		cout << "Case " << i+1 << ": " << fixed << setprecision(2) << C + 5*F/9 << '\n';
	}
}
