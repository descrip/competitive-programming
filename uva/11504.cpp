#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 100001;
int N, M;
vector<int> adj[MAXN], ord;
bool vis[MAXN];

void dfs(int u){
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
	ord.push_back(u);
}

void dfs2(int u){
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int ts; cin >> ts;
	for (int tc = 1; tc <= ts; ++tc){
		cin >> N >> M;
		fill(adj,adj+MAXN,vector<int>());
		fill(vis,vis+MAXN,false);
		ord.assign(0,0);
		for (int i = 0; i < M; ++i){
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
		}
		for (int i = 1; i <= N; ++i)
			if (!vis[i])
				dfs(i);
		fill(vis,vis+MAXN,false);
		int ans = 0;
		for (int i = ord.size()-1; i >= 0; --i)
			if (!vis[ord[i]]){
				dfs(ord[i]);
				++ans;
			}
		cout << ans << '\n';
	}
return 0;}
