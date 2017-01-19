#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	static vector<pair<int, int>> adj[20005];
	for (int i = 0; i < M; ++i){
		int x, y, z; cin >> x >> y >> z;
		adj[x].push_back({y, z});
		adj[y].push_back({x, z});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	static int vis[20005], last[20005];
	pq.push({0, 1});
	while (!pq.empty()){
		int pos = pq.top().second, dist = pq.top().first;
		pq.pop();
		if (vis[pos] == 2 || (vis[pos] == 1 && last[pos] == dist))
			continue;
		++vis[pos];
		last[pos] = dist;
		if (vis[pos] == 2 && pos == N){
			cout << dist << '\n';
			return 0;
		}
		for (pair<int, int> p : adj[pos])
			if (vis[p.first] < 2)
				pq.push({dist + p.second, p.first});
	}
	cout << "-1\n";
return 0;}

