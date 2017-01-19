#include <bits/stdc++.h>
using namespace std;

int N, ans[2];
bool C[200005], vis[200005];
vector<int> adj[200005];

void bfs(int u) {
    vis[u] = true;
    for (int v : adj[u])
        if (C[u] == C[v] && !vis[v])
            bfs(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> C[i];
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < N; ++i)
        if (!vis[i]) {
            bfs(i);
            ++ans[C[i]];
        }
    //cout << ans[0] << ' ' << ans[1] << '\n';
    cout << min(ans[0], ans[1]) << '\n';
	return 0;
}

