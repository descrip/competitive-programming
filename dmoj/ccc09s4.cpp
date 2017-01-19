#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, T; cin >> N >> T;
	vector<pair<int, int>> stores;
	static int adj[5001][5001];
	fill_n(adj[0], 5001*5001, 0xfffffff);
	for (int i = 0; i < T; ++i){
		int x, y, z; cin >> x >> y >> z;
		adj[x][y] = min(adj[x][y], z);
		adj[y][x] = min(adj[y][x], z);
	}
	int K; cin >> K; 
	for (int i = 0; i < K; ++i){
		int x, y; cin >> x >> y;
		stores.push_back({x, y});
	}
	int D; cin >> D;
	static int dist[5001];
	fill_n(dist, 5001, 0xfffffff);
	bool done[5001];
	dist[D] = 0;
	while (true){
		int u = -1, bestDist = 0xfffffff;
		for (int i = 1; i <= N; ++i)
			if (!done[i] && dist[i] < bestDist){
				u = i;
				bestDist = dist[i];
			}
		//cout << u << ' ' << bestDist << '\n';
		if (bestDist == 0xfffffff)
			break;
		for (int v = 1; v <= N; ++v)
			dist[v] = min(dist[v], dist[u] + adj[u][v]);
		done[u] = true;
	}
	int ans = 0xfffffff;
	for (auto i : stores)
		ans = min(ans, dist[i.first] + i.second);
	cout << ans << '\n';
return 0;}

