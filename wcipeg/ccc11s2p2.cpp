#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int S, N, E; cin >> S >> N >> E;
	static vector<pair<int, pair<int, bool>>> adj[1605];
	for (int i = 0; i < E; ++i){
		int s, t, d, u; cin >> s >> t >> d >> u;
		adj[s].push_back({t, {d, u == 1}});
		adj[t].push_back({s, {d, u == 1}});
	}
	//dist expos pos
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({0, {S, 0}});
	static bool vis[1605][3605];
	while (!pq.empty()){
		int pos = pq.top().second.second,
			expos = pq.top().second.first,
			dist = pq.top().first;
		pq.pop();
		if (pos == N-1){
			cout << dist << '\n';
			return 0;
		}
		if (vis[pos][expos])
			continue;
		vis[pos][expos] = true;
		for (auto p : adj[pos])
			if ((!p.second.second || expos >= p.second.first) && !vis[p.first][expos - p.second.first * p.second.second])
				pq.push({dist + p.second.first, {expos - p.second.first * p.second.second, p.first}});
	}
	cout << -1 << '\n';
return 0;}

