#include <bits/stdc++.h>
using namespace std;

int N, X, Y;
vector<int> adj[200001];
bool vis[200001];
vector<int> used, curr;
vector<pair<int, int>> edges;

//dist pos
pair<int, int> dfs(int pos){
	if (vis[pos])
		return {0, pos};
	vis[pos] = true;
	pair<int, int> ret = {0, pos};
	for (int i : adj[pos])
		if (!vis[i])
			ret = max(ret, dfs(i));
	return {ret.first+1, ret.second};;
}

void dfs2(int pos){
	for (int i : adj[pos])
		if (!vis[i]){
			vis[i] = true;
			curr.push_back(i);
			dfs2(i);
			vis[i] = false;
			curr.pop_back();
		}
	if (curr.size() > used.size())
		used = curr;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> X >> Y;
	for (int i = 0; i < N-1; ++i){
		int x, y; cin >> x >> y;
		edges.push_back({x, y});
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	if (X >= Y){
		bool ok = false;
		for (int i = 1; i <= N; ++i)
			if (adj[i].size() == N-1)
				ok = true;
		if (!ok)
			cout << (N-1) * Y << '\n';
		else
			cout << (N-2) * Y + X << '\n';
		return 0;
	}
	pair<int, int> tmp = dfs(1);
	fill_n(vis, 200001, false);
	curr.push_back(tmp.second);
	vis[tmp.second] = true;
	dfs2(tmp.second);
	fill_n(vis, 200001, false);
	for (int i : used)
		vis[i] = true;
	int cnt = used.size()-1;
	for (pair<int, int> i : edges)
		if (!vis[i.first] && !vis[i.second])
			++cnt;
	cout << cnt * X + max(N-1-cnt, 0) * Y << '\n';
return 0;}

