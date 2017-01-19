#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n; cin >> n;
    for (int a = sqrt(n); a >= 1; --a)
        if (n % a == 0) {
            cout << a << ' ' << n/a << '\n';
            return 0;
        }
	return 0;
}

