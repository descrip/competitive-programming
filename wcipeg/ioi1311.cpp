#include <bits/stdc++.h>
using namespace std;

int n, m, l, kcnt = 1;
vector<pair<int,int>> adj[100000];
long long rad[100000], dist[100000];
int vis[100000];

long long dmin, dmax, ans = 0;
int which, col = 0;

void dfs1(int n, long long d){
	if (d > dmax){
		dmax = d;
		which = n;
	}
	vis[n] = col;
	for (int i = 0; i < adj[n].size(); ++i)
		if (vis[adj[n][i].first] != col)
			dfs1(adj[n][i].first, d+adj[n][i].second);
}

void dfs2(int n, long long d, bool sec){
	if (sec){
		dist[n] = max(d, dist[n]);
		dmax = max(dmax, dist[n]);
		dmin = (dmin == -1 || dist[n] < dmin) ? dist[n] : dmin;
	}
	else
		dist[n] = d;
	vis[n] = col;
	for (int i = 0; i < adj[n].size(); ++i)
		if (vis[adj[n][i].first] != col)
			dfs2(adj[n][i].first, d+adj[n][i].second, sec);
}

long long handleTree(int n){
	int a, b;
	dmin = dmax = -1;
	++col;
	dfs1(n, 0);
	a = which;
	dmin = dmax = -1;
	++col;
	dfs1(a, 0);
	b = which;
	dmin = dmax = -1;
	++col;
	dfs2(a, 0, false);
	++col;
	dfs2(b, 0, true);
	ans = max(ans, dmax);
	return dmin;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> l;
	for (int i = 0; i < m; ++i){
		int x, y, z; cin >> x >> y >> z;
		adj[x].push_back({y,z});
		adj[y].push_back({x,z});
	}
	vector<long long> v;
	for (int i = 0; i < n; ++i)
		if (vis[i] == 0)
			v.push_back(handleTree(i));
	sort(v.begin(), v.end(), greater<long long>());
	if (v.size() > 1){
		ans = max(ans, v[0]+v[1]+l);
		if (v.size() > 2)
			ans = max(ans, v[1]+v[2]+2*l);
	}
	cout << ans << '\n';
return 0;}

