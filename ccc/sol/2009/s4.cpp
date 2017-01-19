#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, t; scan(n); scan(t);
	/*
	static vector<pair<int,int>> adj[5001];
	for (int i = 0; i < t; ++i){
		int a, b, c; scan(a); scan(b); scan(c);
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	*/
	static int adj[5001][5001];
	for (int i = 0; i < t; ++i){
		int a, b, c; scan(a); scan(b); scan(c);
		adj[a][b] = adj[b][a] = c;
	}
	int cnt = 0;
	long long ans = (1<<30);
	static int p[5001];
	fill_n(p, 5001, -1);
	int k; scan(k);
	for (int i = 0; i < k; ++i){
		int a, b; scan(a); scan(b);
		p[a] = b;
	}
	static bool vis[5001];
	int d; scan(d);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({0LL, d});
	while (!pq.empty()){
		int x = pq.top().second;
		long long y = pq.top().first;
		pq.pop();
		if (vis[x])
			continue;
		vis[x] = true;
		if (p[x] != -1){
			ans = min(ans, y+p[x]);
			++cnt;
			if (cnt == k)
				break;
		}
		/*
		for (auto p : adj[x])
			if (!vis[p.first])
				pq.push(make_pair(y + p.second, p.first));
		*/
		for (int i = 1; i <= n; ++i)
			if (!vis[i] && adj[x][i] != 0)
				pq.push({y + adj[x][i], i});
	}
	cout << ans << '\n';
return 0;}
