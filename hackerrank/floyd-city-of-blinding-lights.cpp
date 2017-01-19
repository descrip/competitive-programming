#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<pair<int,int>>> adj (n+1);
	for (int i = 0; i < m; ++i){
		int a, b, r; cin >> a >> b >> r;
		bool ok = false;
		for (int j = 0; j < adj[a].size(); ++j){
			if (adj[a][j].first == b){
				adj[a][j].second = r;
				ok = true;
				break;
			}
		}
		if (!ok)
			adj[a].push_back({b,r});
	}
	int q; cin >> q;
	set<pair<pair<int,int>,int>> quer;
	for (int i = 0; i < q; ++i){
		int a, b; cin >> a >> b;
		quer.insert({{a,b},i});
	}
	vector<int> ans (q,-1);
	vector<bool> vis (n+1);
	for (int i = 1; i <= n; ++i){
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		pq.push({0,i});
		fill(vis.begin(),vis.end(),false);
		while (!pq.empty()){
			int d = pq.top().first, x = pq.top().second;
			pq.pop();
			if (vis[x]) continue;
			vis[x] = true;
			while (true){
				auto it = quer.lower_bound(make_pair(make_pair(i,x),-1));
				if (it != quer.end() && it->first == make_pair(i,x)){
					ans[it->second] = d;
					quer.erase(it);
				}
				else break;
			}
			for (auto p : adj[x])
				pq.push({d + p.second, p.first});
		}
	}
	for (int i = 0; i < q; ++i)
		cout << ans[i] << '\n';
return 0;}
