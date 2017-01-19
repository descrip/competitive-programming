#include <bits/stdc++.h>
using namespace std;

// TODO: Fix -1

const long long INF = (1LL << 50);
int T, N, M, K, S[5001], D[5001];
long long adj[101][101], dp[5001][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> M >> K;
        fill_n(adj[0], 101*101, INF);
        for (int i = 1; i <= M; ++i) {
            int a, b, g; cin >> a >> b >> g;
            adj[a][b] = adj[b][a] = g;
        }
        for (int i = 1; i <= N; ++i)
            adj[i][i] = 0;
        for (int i = 1; i <= K; ++i)
            cin >> S[i] >> D[i];
        for (int k = 1; k <= N; ++k)
            for (int i = 1; i <= N; ++i)
                for (int j = 1; j <= N; ++j)
                    adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
        fill_n(dp[0], 5001*2, INF);
        dp[1][0] = min(dp[1][0], adj[1][S[1]] + adj[S[1]][D[1]]);
        dp[1][1] = min(dp[1][1], adj[1][S[1]] + adj[S[1]][S[2]] + adj[S[2]][D[1]]);
        for (int i = 2; i < K; ++i) {
            dp[i][0] = min(
                dp[i][0],
                min(
                    dp[i-1][0] + adj[D[i-1]][S[i]] + adj[S[i]][D[i]],
                    dp[i-1][1] + adj[D[i-1]][D[i]]
                )
            );
            dp[i][1] = min(
                dp[i][1],
                min(
                    dp[i-1][0] + adj[D[i-1]][S[i]] + adj[S[i]][S[i+1]] + adj[S[i+1]][D[i]],
                    dp[i-1][1] + adj[D[i-1]][S[i+1]] + adj[S[i+1]][D[i]]
                    )
            );
        }
        long long ans = min(
            dp[K-1][0] + adj[D[K-1]][S[K]] + adj[S[K]][D[K]],
            dp[K-1][1] + adj[D[K-1]][D[K]]
        );
        cout << "Case #" << t << ": " << (ans >= INF ? -1LL : ans) << '\n';
    }
    return 0;
}

