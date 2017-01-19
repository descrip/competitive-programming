#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 2001;
int N, M;
vector<int> adj[MAXN], radj[MAXN];
bool vis[MAXN];

void dfs(int u){
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

void rdfs(int u){
	vis[u] = true;
	for (int v : radj[u])
		if (!vis[v])
			rdfs(v);
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	while (true){
		cin >> N >> M;
		if (N == 0) break;
		fill(adj,adj+MAXN,vector<int>());
		fill(radj,radj+MAXN,vector<int>());
		fill(vis,vis+MAXN,false);
		bool ok = true;
		for (int i = 0; i < M; ++i){
			int a, b, c; cin >> a >> b >> c;
			adj[a].push_back(b);
			radj[b].push_back(a);
			if (c == 2){
				adj[b].push_back(a);
				radj[a].push_back(b);
			}
		}
		dfs(1);
		for (int i = 1; i <= N; ++i)
			if (!vis[i])
				ok = false;
		fill(vis,vis+MAXN,false);
		rdfs(1);
		for (int i = 1; i <= N; ++i)
			if (!vis[i])
				ok = false;
		cout << ok << '\n';
	}
return 0;}
