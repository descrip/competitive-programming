#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, m; cin >> n >> m;
    int a[105], ps[105], ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ps[i] = ps[i-1]+a[i];
    }
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        ans += max(ps[y] - ps[x-1], 0);
    }
    cout << ans << '\n';
	return 0;
}

