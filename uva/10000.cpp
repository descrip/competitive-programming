#include <bits/stdc++.h>
using namespace std;

int N, S, dp[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int t = 1; ; ++t) {
        cin >> N;
        if (N == 0) break;
        cin >> S; --S;
        int p, q;
        fill_n(dp[0], 101*101, -0xfffffff);
        while (cin >> p >> q) {
            if (p == 0 && q == 0) break;
            --p; --q;
            dp[p][q] = 1;
        }
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
        int best = S;
        for (int i = 0; i < N; ++i)
            if (dp[S][i] > dp[S][best])
                best = i;
        cout << "Case " << t << ": The longest path from " << S+1 << " has length " << dp[S][best] << ", finishing at " << best+1 << ".\n\n";
    }
    return 0;
}

