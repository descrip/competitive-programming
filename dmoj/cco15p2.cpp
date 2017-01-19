#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	vector<int> dist (18, 0xfffffff);
	dist[0] = 0;
	vector<pair<pair<int, int>, int>> adj;
	for (int i = 0; i < M; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		adj.push_back({{x, y}, -z});
	}
	for (int i = 0; i < M-1; ++i)
		for (int e = 0; e < M; ++e){
			int u = adj[e].first.first, v = adj[e].first.second, w = adj[e].second;
			dist[v] = min(dist[v], dist[u] + w);
		}
	cout << -dist[N-1] << '\n';
return 0;}

