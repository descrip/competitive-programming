#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int ts = 0; ts < t; ++ts){
		int n, m; cin >> n >> m;
		vector<vector<int>> adj (n+1);
		for (int i = 0; i < m; ++i){
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int s; cin >> s;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
		vector<bool> vis (n+1);
		q.push({0,s});
		vector<int> ans (n+1,-1);
		while (!q.empty()){
			int d = q.top().first, x = q.top().second;
			q.pop();
			if (vis[x]) continue;
			vis[x] = true;
			ans[x] = d;
			for (int i : adj[x])
				q.push({d+6,i});
		}
		for (int i = 1; i <= n; ++i)
			if (i != s)
				cout << ans[i] << ' ';
		cout << '\n';
	}
return 0;}
