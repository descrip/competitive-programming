#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, a = 0, d = 0; cin >> n;
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        if (c == 'A') ++a;
        else ++d;
    }
    if (a == d)
        cout << "Friendship\n";
    else
        cout << (a < d ? "Danik" : "Anton") << '\n';
	return 0;
}

