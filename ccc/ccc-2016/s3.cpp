#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> pho, adj[100005];
bool vis[100005], isPho[100005];

pair<pair<int, int>, bool> dfs1(int pos){
	if (vis[pos])
		return {{-1, -1}, false};
	vis[pos] = true;
	pair<pair<int, int>, bool> ret = {{0, pos}, isPho[pos]};
	for (int i : adj[pos]){
		pair<pair<int, int>, bool> p = dfs1(i);
		++p.first.first;
		if (p.second && p.first.first > ret.first.first)
			ret = p;
	}
	return ret;
}

pair<int, bool> dfs2(int pos){
	if (vis[pos])
		return {0, false};
	vis[pos] = true;
	pair<int, bool> ret = {0, isPho[pos]};
	for (int i : adj[pos]){
		pair<int, bool> p = dfs2(i);
		++p.first;
		if (p.second){
			ret.second = true;
			ret.first += p.first;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i){
		int a; cin >> a;
		pho.push_back(a);
		isPho[a] = true;
	}
	for (int i = 0; i < N-1; ++i){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int start = dfs1(0).first.second;
	fill_n(vis, 100005, false);
	int dist1 = dfs1(start).first.first;
	fill_n(vis, 100005, false);
	int dist2 = dfs2(start).first;
	//cout << dist1 << ' ' << dist2 << '\n';
	//cout << start << ' ' << dist << '\n';
	cout << dist2*2 - dist1 << '\n';
return 0;}

