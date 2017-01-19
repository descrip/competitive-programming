#include <bits/stdc++.h>
using namespace std;

int n, x, a[100005];
multiset<int> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i] ^ x);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += s.count(a[i]);
        if (a[i] == (a[i]^x))
            --ans;
    }
    cout << ans/2 << '\n';
	return 0;
}

