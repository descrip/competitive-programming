#include <bits/stdc++.h>
using namespace std;

const int MAXNM = 100000;
int n, m, cntscc = 0, scc[MAXNM], val[MAXNM], dp[MAXNM], rdp[MAXNM];
vector<int> adj[MAXNM], radj[MAXNM], adj2[MAXNM], radj2[MAXNM], ord;
bool vis[MAXNM];

void topsort(int u, vector<int> a[]){
	vis[u] = true;
	for (int v : a[u])
		if (!vis[v])
			topsort(v,a);
	ord.push_back(u);
}

void rdfs(int u, vector<int> a[]){
	vis[u] = true;
	scc[u] = cntscc;
	++val[scc[u]];
	for (int v : a[u])
		if (!vis[v])
			rdfs(v,a);
}

int recur(int u, int d[], vector<int> a[]){
	if (d[u] != -0xfffffff)
		return d[u];
	if (u == scc[0])
		return d[u] = val[scc[0]];
	for (int v : a[u])
		d[u] = max(d[u], recur(v,d,a)+val[u]);
	return d[u];
}

int main(){
	ifstream fin ("grass.in");
	ofstream fout ("grass.out");
	fin >> n >> m;
	for (int i = 0; i < m; ++i){
		int a, b; fin >> a >> b;
		adj[a-1].push_back(b-1);
		radj[b-1].push_back(a-1);
	}
	for (int i = 0; i < n; ++i)
		if (!vis[i])
			topsort(i,adj);
	fill(vis,vis+MAXNM,false);
	while (!ord.empty()){
		if (!vis[ord.back()]){
			rdfs(ord.back(),radj);
			cntscc++;
		}
		ord.pop_back();
	}
	for (int i = 0; i < n; ++i)
		for (int j : adj[i])
			if (scc[i] != scc[j]){
				adj2[scc[i]].push_back(scc[j]);
				radj2[scc[j]].push_back(scc[i]);
			}
	fill(dp,dp+MAXNM,-0xfffffff);
	fill(rdp,rdp+MAXNM,-0xfffffff);
	for (int i = 0; i < cntscc; ++i){
		recur(i,dp,adj2);
		recur(i,rdp,radj2);
	}
	int ans = -0xfffffff;
	for (int i = 0; i < cntscc; ++i)
		for (int j : adj2[i])
			ans = max(ans, dp[i]+rdp[j]-val[scc[0]]);
	fout << ans << '\n';
	fin.close(); fout.close();
return 0;}
