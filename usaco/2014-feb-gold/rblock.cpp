#include <bits/stdc++.h>
using namespace std;

int n, m, pre[251], path[251];
vector<pair<int,int>> adj[251];

int djik(){
	fill(pre, pre+251, 0);
	priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> pq;
	pq.push({{0, 1}, -1});
	while (!pq.empty()){
		int x = pq.top().first.second, y = pq.top().first.first, z = pq.top().second;
		pq.pop();
		if (z != -1 && pre[x] != 0)
			continue;
		pre[x] = z;
		if (x == n)
			return y;
		for (auto p : adj[x])
			if (pre[p.first] == 0)
				pq.push({{y+p.second, p.first}, x});
	}
}

int main(){
	freopen("rblock.in", "r", stdin);
	freopen("rblock.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int a, b, l; cin >> a >> b >> l;
		adj[a].push_back({b, l});
		adj[b].push_back({a, l});
	}
	int init = djik(), ans = 0;
	int b = n;
	copy(pre, pre+251, path);
	while (b != 1){
		int a = path[b];
		int pos1 = 0, pos2 = 0;
		for (; pos1 < adj[a].size(); ++pos1)
			if (adj[a][pos1].first == b)
				break;
		for (; pos2 < adj[b].size(); ++pos2)
			if (adj[b][pos2].first == a)
				break;
		adj[a][pos1].second *= 2;
		adj[b][pos2].second *= 2;
		ans = max(ans, djik());
		adj[a][pos1].second /= 2;
		adj[b][pos2].second /= 2;
		b = a;
	}
	cout << ans-init << '\n';
return 0;}
