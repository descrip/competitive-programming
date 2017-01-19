#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 400000;
int N;
long long dist[MAXN+1], leaves[MAXN+1], ans, num;
vector<int> adj[MAXN+1];
bool vis[MAXN+1];

void dfs(int n){
	vis[n] = true;
	for(int i : adj[n]){
		if (vis[i]) continue;
		dfs(i);
		if (dist[i]+dist[n]+1 > ans){
			ans = dist[i]+dist[n]+1;
			num = leaves[i] * leaves[n];
		}
		else if (dist[i]+dist[n]+1 == ans)
			num += leaves[i] * leaves[n];
		if (dist[i]+1 > dist[n]){
			dist[n] = dist[i]+1;
			leaves[n] = leaves[i];
		}
		else if (dist[i]+1 == dist[n])
			leaves[n] += leaves[i];
	}
}

int main(){
	cin >> N;
	for (int i = 0; i < N-1; ++i){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill(leaves,leaves+MAXN+1,1);
	dfs(1);
	cout << ans+1 << ' ' << num << '\n';
}
