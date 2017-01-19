#include <bits/stdc++.h>
using namespace std;

int T, N, M, C;
vector<int> adj[30001];
bool vis[30001];

void dfs(int u) {
    ++C;
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> M;
        for (int i = 0; i < N; ++i)
            adj[i].clear();
        for (int i = 0; i < M; ++i) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 0;
        fill_n(vis, 30001, false);
        for (int i = 1; i <= N; ++i)
            if (!vis[i]) {
                C = 0;
                dfs(i);
                ans = max(ans, C);
            }
        cout << ans << '\n';
    }
    return 0;
}

