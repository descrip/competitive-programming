#include <bits/stdc++.h>
using namespace std;

int V, E, vis[201];
vector<int> adj[201];
bool ok = true;

void recur(int u, bool coin) {
  vis[u] = coin+1;
  for (int v : adj[u])
    if (vis[v] && coin+1 == vis[v])
      ok = false;
    else if (!vis[v])
      recur(v, !coin);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> V >> E) {
    fill_n(adj, 201, vector<int>());
    fill_n(vis, 201, 0);
    ok = true;
    for (int i = 0; i < E; ++i) {
      int x, y; cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    recur(0, true);
    cout << (!ok ? "NOT " : "") << "BICOLORABLE.\n";
  }
return 0;}

