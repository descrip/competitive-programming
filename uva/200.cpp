#include <bits/stdc++.h>
using namespace std;

vector<string> V;
string ans = "";
set<int> adj[257];
bool vis[257];

void toposort(int u) {
	vis[u] = true;
	for (int v : adj[u]) {
		if (!vis[v])
			toposort(v);
	}
	ans += (char)u;
}

int main() {
	while (true) {
		string S; cin >> S;
		if (S == "#")
			break;
		V.push_back(S);
	}
	for (int i = 0; i < V.size()-1; ++i)
		for (int j = 0; j < min(V[i].size(), V[i+1].size()); ++j)
			if (V[i][j] != V[i+1][j]) {
				adj[V[i][j]].insert(V[i+1][j]);
				break;
			}
	toposort(V[0][0]);
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}
