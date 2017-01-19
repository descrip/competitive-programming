#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<int> chi;
vector<vector<int>> adj;

int dfs(int n){
	if (vis[n]) return 0;
	vis[n] = true;
	int ret = 0;
	for (int j : adj[n]){
		ret += dfs(j);
	}
	chi[n] = ret + 1;
	return chi[n];
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	adj.assign(n+1,vector<int>());
	chi.assign(n+1,0);
	vis.assign(n+1,false);
	for (int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	int ans = 0;
	for (int i = 2; i <= n; ++i)
		if (chi[i] != 0 && chi[i] % 2 == 0)
			++ans;
	cout << ans << '\n';
return 0;}
