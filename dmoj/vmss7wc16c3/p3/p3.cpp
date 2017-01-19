#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M, B, Q; cin >> N >> M >> B >> Q;
	static vector<pair<int, int>> adj[100000];
	--B;
	for (int i = 0; i < M; ++i){
		int x, y, z; cin >> x >> y >> z;
		adj[x-1].push_back({y-1, z});
		adj[y-1].push_back({x-1, z});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push({0, B});
	static int dist[100000];
	fill_n(dist, 100000, -1);
	while (!pq.empty()){
		int pos = pq.top().second, cost = pq.top().first;
		pq.pop();
		if (dist[pos] != -1)
			continue;
		dist[pos] = cost;
		for (pair<int, int> p : adj[pos])
			if (dist[p.first] == -1)
				pq.push({cost + p.second, p.first});
	}
	for (int i = 0; i < Q; ++i){
		int a; cin >> a;
		cout << dist[a-1] << '\n';
	}
return 0;}

