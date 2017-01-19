#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, m; cin >> n >> m;
    int l = 0xfffffff;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        l = min(l, y-x+1);
    }
    cout << l << '\n';
    for (int i = 0; i < n; ++i)
        cout << i % l << " \n"[i==n-1];
	return 0;
}

