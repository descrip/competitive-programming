#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e4+5;
int n, m, cntScc = 1, scc[NMAX], val[NMAX];
vector<int> adj[NMAX], radj[NMAX], adj2[NMAX], ord;
bool vis[NMAX];

void topsort(int u, vector<int> a[]){
	vis[u] = true;
	for (int v : a[u])
		if (!vis[v])
			topsort(v, a);
	ord.push_back(u);
}

void rdfs(int u, vector<int> a[]){
	vis[u] = true;
	scc[u] = cntScc;
	++val[cntScc];
	for (int v : a[u])
		if (!vis[v])
			rdfs(v, a);
}

int recur(int u, int d[], vector<int> a[]){
	for (int v : a[u])
		d[u] = max(d[u], recur(v, d, a) + val[v]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		radj[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			topsort(i, adj);
	fill_n(vis, NMAX, false);
	while (!ord.empty()){
		if (!vis[ord.back()]){
			rdfs(ord.back(), radj);
			++cntScc;
		}
		ord.pop_back();
	}
	for (int i = 1; i <= n; ++i)
		for (int j : adj[i])
			if (scc[i] != scc[j]){
				adj2[scc[i]].push_back(scc[j]);
				radj2[scc[j]].push_back(scc[i]);
			}
	fill_n(vis, NMAX, false);
return 0;}
