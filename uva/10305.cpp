#include <bits/stdc++.h>
using namespace std;

int n, m, cnt[101];
vector<int> adj[101];

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	while (true){
		cin >> n >> m;
		if (n == 0) break;
		fill(cnt,cnt+101,0);
		fill(adj,adj+101,vector<int>());
		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x-1].push_back(y-1);
			++cnt[y-1];
		}
		queue<int> q;
		for (int i = 0; i < n; ++i)
			if (cnt[i] == 0)
				q.push(i);
		while (!q.empty()){
			cout << q.front()+1 << ' ';
			for (int i : adj[q.front()]){
				--cnt[i];
				if (cnt[i] == 0) q.push(i);
			}
			q.pop();
		}
		cout << '\n';
	}
return 0;}
