#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a, b, c; cin >> a >> b >> c;
    int m = min(min(a, b/2), c/4);
    cout << (1+2+4) * m << '\n';
	return 0;
}

