#include <vector>
#include <set>
#include <iostream>
using namespace std;

const int MAXN = 1000001;
int N, M, S, E, low[MAXN], num[MAXN], fun[MAXN], scc[MAXN],
	dfscnt = 1, scccnt = 1;
long long val[MAXN], dist[MAXN];
vector<int> adj[MAXN], stack, ord;
set<int> adj2[MAXN], radj2[MAXN];
bool vis[MAXN];

void tarjan(int u){
	low[u] = num[u] = dfscnt++;
	stack.push_back(u);
	vis[u] = true;
	for (int v : adj[u]){
		if (num[v] == 0)
			tarjan(v);
		if (vis[v])
			low[u] = min(low[u],low[v]);
	}
	if (low[u] == num[u]){
		int sum = 0;
		while (true){
			int v = stack.back();
			sum += fun[v];
			stack.pop_back();
			vis[v] = false;
			scc[v] = scccnt;
			if (u == v) break;
		}
		val[scccnt++] = sum;
	}
}

void topsort(int u){
	vis[u] = true;
	for (int v : adj2[u])
		if (!vis[v])
			topsort(v);
	ord.push_back(u);
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> S >> E;
	for (int i = 1; i <= N; ++i)
		cin >> fun[i];
	for (int i = 1; i <= M; ++i){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= N; ++i)
		if (num[i] == 0)
			tarjan(i);
	for (int i = 1; i <= N; ++i)
		for (int j : adj[i])
			if (scc[i] != scc[j]){
				adj2[scc[i]].insert(scc[j]);
				radj2[scc[j]].insert(scc[i]);
			}
	fill(vis,vis+MAXN,false);
	for (int i = 1; i <= N; ++i)
		if (!vis[scc[i]])
			topsort(scc[i]);
	while (ord.back() != scc[S]) ord.pop_back();
	ord.pop_back();
	fill(dist,dist+MAXN,-0xFFFFFFF);
	dist[scc[S]] = val[scc[S]];
	for (int i = ord.size()-1; i >= 0; --i)
		for (int j : radj2[ord[i]])
			dist[ord[i]] = max(dist[ord[i]],dist[j]+val[ord[i]]);
	cout << dist[scc[E]] << '\n';
return 0;}
