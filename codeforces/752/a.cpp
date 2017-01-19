#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> m >> k;
    --k;
    cout << k / (2*m) + 1 << ' ';
    k %= 2*m;
    cout << k / 2 + 1 << ' ' << (k % 2 == 1 ? 'R' : 'L') << '\n';
	return 0;
}

