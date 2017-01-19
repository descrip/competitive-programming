#include <bits/stdc++.h>
using namespace std;

int n, m, tc=1, pr, cnt[101];
string bev[101];
vector<int> adj[101];
map<string,int> b2i;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	while (cin >> n){
		fill(cnt,cnt+101,0);
		b2i.clear();
		fill(adj,adj+101,vector<int>());
		pr = 0;
		for (int i = 0; i < n; ++i){
			cin >> bev[i];
			b2i[bev[i]] = i;
		}
		cin >> m;
		for (int i = 0; i < m; ++i){
			string s, t; cin >> s >> t;
			adj[b2i[s]].push_back(b2i[t]);
			++cnt[b2i[t]];
		}
		priority_queue<int,vector<int>,greater<int>> q;
		for (int i = 0; i < n; ++i)
			if (cnt[i] == 0)
				q.push(i);
		cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order: ";
		while (!q.empty()){
			int a = q.top(); q.pop(); ++pr;
			cout << bev[a] << (pr == n ? '.' : ' ');
			for (int i : adj[a]){
				--cnt[i];
				if (cnt[i] == 0) q.push(i);
			}
		}
		cout << "\n\n";
	}
return 0;}
