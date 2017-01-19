#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int K, N, M; cin >> K >> N >> M;
	static vector<pair<int, pair<int, int>>> adj[2001];
	for (int i = 0; i < M; ++i){
		int a, b, t, h; cin >> a >> b >> t >> h;
		adj[a].push_back({b, {t, h}});
		adj[b].push_back({a, {t, h}});
	}
	int A, B; cin >> A >> B;
	//time hull pos
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({0, {K, A}});
	static bool vis[2001][201];
	while (!pq.empty()){
		int time = pq.top().first,
			hull = pq.top().second.first,
			pos = pq.top().second.second;
		pq.pop();
		if (pos == B){
			cout << time << '\n';
			return 0;
		}
		if (vis[pos][hull])
			continue;
		vis[pos][hull] = true;
		for (auto p : adj[pos])
			if (p.second.second < hull && !vis[p.first][hull-p.second.second])
				pq.push({time + p.second.first, {hull - p.second.second, p.first}});
	}
	cout << "-1\n";
return 0;}

