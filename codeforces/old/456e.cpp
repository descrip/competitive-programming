#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
int n, m, q, par[MAXN], diam[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];

pair<int,int> farthest(int a, int p){
	pair<int,int> ret = {0, a};
	for (int i = 0; i < adj[a].size(); ++i)
		if (adj[a][i] != p){
			pair<int,int> tmp = farthest(adj[a][i], a);
			++tmp.first;
			ret = max(ret, tmp);
			if (par[adj[a][i]] == 0)
				par[adj[a][i]] = a;
		}
	return ret;
}

int findSet(int a){
	return (par[a] == a ? a : par[a] = findSet(par[a]));
}

void unionSet(int a, int b){
	int x = findSet(a), y = findSet(b);
	//cout << a << ' ' << b << ' ' << x << ' ' << y << ' ' << diam[x] << ' ' << diam[y] << ' ' << ceil(diam[x]/2.0) << ' ' << ceil(diam[y]/2.0) << '\n';
	if (x == y)
		return;
	else if (diam[x] > diam[y]){
		par[y] = x;
		diam[x] = max(diam[x], (int)(ceil(diam[x]/2.0)+ceil(diam[y]/2.0)+1));
	}
	else{
		par[x] = y;
		diam[y] = max(diam[y], (int)(ceil(diam[x]/2.0)+ceil(diam[y]/2.0)+1));
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
		if (par[i] == 0){
			par[i] = i;
			diam[i] = farthest(farthest(i, -1).second, -1).first;
		}
	for (int i = 0; i < q; ++i){
		int t; cin >> t;
		if (t == 1){
			int x; cin >> x;
			cout << diam[findSet(x)] << '\n';
		}
		else if (t == 2){
			int x, y; cin >> x >> y;
			unionSet(x, y);
		}
	}
return 0;}
