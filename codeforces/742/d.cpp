#include <bits/stdc++.h>
using namespace std;

int N, M, W, hw[1005], hb[1005], gw[1005], gb[1005], gN = 0, dp[1005], newdp[1005];
vector<int> adj[100005], gh[1005];
bool vis[1005];

pair<int, int> bfs(int u, int k) {
    if (vis[u])
        return make_pair(0, 0);
    vis[u] = true;
    gh[k].push_back(u);
    int b = 0, w = 0;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        auto p = bfs(v, k);
        w += p.first;
        b += p.second;
    }
    return make_pair(w + hw[u], b + hb[u]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> N >> M >> W;
    for (int i = 0; i < N; ++i)
        cin >> hw[i];
    for (int i = 0; i < N; ++i)
        cin >> hb[i];
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for (int i = 0; i < N; ++i)
        if (!vis[i]) {
            auto p = bfs(i, gN);
            gw[gN] = p.first;
            gb[gN] = p.second;
            gN++;
        }
    /*
    cout << gN << '\n';
    for (int i = 0; i < gN; ++i)
        cout << gw[i] << " \n"[i == gN-1];
    for (int i = 0; i < gN; ++i)
        cout << gb[i] << " \n"[i == gN-1];
        */
    fill_n(dp, 1005, -0xfffffff);
    dp[0] = 0;
    for (int i = 0; i < gN; ++i) {
        for (int i = 0; i < 1005; ++i)
            newdp[i] = dp[i];
        for (int j = 0; j <= W-gw[i]; ++j)
            newdp[j+gw[i]] = max(newdp[j+gw[i]], dp[j]+gb[i]);
        for (int h : gh[i])
            for (int j = 0; j <= W-hw[h]; ++j)
                newdp[j+hw[h]] = max(newdp[j+hw[h]], dp[j]+hb[h]);
        for (int i = 0; i < 1005; ++i)
            dp[i] = newdp[i];
    }
    int ans = 0;
    for (int i = 0; i <= W; ++i)
        ans = max(ans, dp[i]);
    /*
        cout << dp[i] << " \n"[i == W];
    cout << dp[W] << '\n';
    */
    cout << ans << '\n';
	return 0;
}

