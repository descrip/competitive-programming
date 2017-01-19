#include <bits/stdc++.h>
using namespace std;

int n, a, b;
string c;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> a >> b >> c;
    --a; --b;
    cout << (c[a] == c[b] ? 0 : 1) << '\n';
	return 0;
}

