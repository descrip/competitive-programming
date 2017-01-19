#include <bits/stdc++.h>
using namespace std;

int n, c[105], d[105][105];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    fill_n(d[0], 105*105, 0xfffffff);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        --c[i];
        d[i][c[i]] = 1;
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    /*
    cout << d[0][c[0]] << '\n';
    int ans = 0xfffffff;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (d[i][j] == d[j][i])
                ans = min(ans, d[i][j]);
    cout << ans << '\n';
    */
    for (int t = 1; t <= 100; ++t) {
        bool ok = true;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (d[i][j] != 0xfffffff && (t - d[i][j]) % d[j][j] == 0) {
                    if (d[j][i] == 0xfffffff || t < d[j][i] || (t - d[j][i]) % d[i][i] != 0) {
                        ok = false;
                    }
                }
        if (ok) {
            cout << t << '\n';
            return 0;
        }
    }
    cout << "-1\n";
	return 0;
}

