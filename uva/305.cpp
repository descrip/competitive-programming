#include <bits/stdc++.h>
using namespace std;

int ans[14], x;

int dead(int k, int m) {
    int ret = 0, sz = 2*k, pos = 0;
    for (; ret <= k; ++ret) {
        pos = (pos+m-1) % sz;
        sz--;
        if (pos < k) break;
    }
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    for (int k = 1; k < 14; ++k)
        for (int m = 1; ; ++m)
            if (dead(k, m) == k) {
                ans[k] = m; break;
            }
    while (cin >> x) {
        if (x == 0) break;
        cout << ans[x] << '\n';
    }
	return 0;
}

