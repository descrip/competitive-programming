#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    if (n == 1) {
        cout << "-1\n";
        return 0;
    }
    cout << n << ' ' << n+1 << ' ' << n*(n+1) << '\n';
	return 0;
}

