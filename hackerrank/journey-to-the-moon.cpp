#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100000];
bool vis[100000];

int dfs(int a){
	if (vis[a]) return 0;
	vis[a] = true;
	int ret = 0;
	for (int j : adj[a])
		ret += dfs(j);
	return ret+1;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> cnt;
	for (int i = 0; i < n; ++i)
		if (!vis[i])
			cnt.push_back(dfs(i));
	long long ans = 0, sum = 0;
	for (int i = 0; i < cnt.size(); ++i){
		ans += sum * cnt[i];
		sum += cnt[i];
	}
	cout << ans << '\n';
return 0;}
