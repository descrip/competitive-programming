#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int a){
	if (vis[a]) return;
	vis[a] = true;
	for (int i : adj[a])
		dfs(i);
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int ts = 0; ts < t; ++ts){
		cin >> n;
		adj.assign(n+2,vector<int>());
		vis.assign(n+2,false);
		for (int i = 1; i <= n+1; ++i){
			int k; cin >> k;
			for (int j = 0; j < k; ++j){
				int a; cin >> a;
				adj[a].push_back(i);
			}
		}
		dfs(n+1);
		double ans = 0;
		for (int i = 1; i <= n; ++i){
			double a; cin >> a;
			if (vis[i])
				ans += a;
		}
		cout << (int)ans << '\n';
	}
return 0;}
