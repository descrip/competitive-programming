#include <bits/stdc++.h>
using namespace std;

int N, R, dp[105][105], C = 1, S, D, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N >> R) {
        if (N == 0 && R == 0) break;
        fill_n(dp[0], 105*105, 0);
        for (int i = 0; i < R; ++i) {
            int a, b, c; cin >> a >> b >> c;
            --a; --b;
            dp[a][b] = dp[b][a] = c;
        }
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    dp[i][j] = max(dp[i][j], min(dp[i][k], dp[k][j]));
        cin >> S >> D >> T;
        --S; --D;
        cout << "Scenario #" << C++ << 
            "\nMinimum Number of Trips = " << (int)ceil((double)T/(dp[S][D]-1)) << "\n\n";
    }
    return 0;
}

