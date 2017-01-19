#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<int> adj[26];
bool vis[26], first = true;

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        if (!first)
            cout << '\n';
        first = false;
        char c; cin >> c;
        N = c-'A';
        string S;
        getline(cin, S);
        for (int i = 0; i < 26; ++i)
            adj[i].clear();
        while (getline(cin, S)) {
            if (S.empty())
                break;
            int c = S[0] - 'A',
                d = S[1] - 'A';
            adj[c].push_back(d);
            adj[d].push_back(c);
        }
        int ans = 0;
        fill_n(vis, 26, false);
        for (int i = 0; i <= N; ++i)
            if (!vis[i]) {
                ++ans;
                dfs(i);
            }
        cout << ans << '\n';
    }
	return 0;
}

