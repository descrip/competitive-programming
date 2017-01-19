#include <bits/stdc++.h>
using namespace std;

int dp[21][21], N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int t = 1; ; ++t) {
        fill_n(dp[0], 21*21, 0xfffffff);
        for (int i = 1; i <= 19; ++i) {
            int x; 
            if (!(cin >> x))
                return 0;
            for (int j = 0; j < x; ++j) {
                int b; cin >> b;
                dp[i][b] = dp[b][i] = 1;
            }
        }
        for (int k = 1; k <= 20; ++k)
            for (int i = 1; i <= 20; ++i)
                for (int j = 1; j <= 20; ++j)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        cin >> N;
        cout << "Test Set #" << t << '\n';
        for (int i = 0; i < N; ++i) {
            int a, b; cin >> a >> b;
            cout << setw(2) << a << " to " << setw(2) << b << ": " << dp[a][b] << '\n';
        }
        cout << '\n';
    }
    return 0;
}

