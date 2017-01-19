#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M, K; cin >> N >> M >> K;
	static vector<int> adj[1501];
	for (int i = 0; i < M; ++i){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bool vis[1501][1501];
	for (int root = 1; root <= N; ++root){
		queue<int> q;
		q.push(root);
		vis[root][root] = true;
		for (int k = 0; k < K; ++k){
			//cout << root << ' ' << q.size() << '\n';
			int stop = q.size();
			for (int cnt = 0; cnt < stop; ++cnt){
				int pos = q.front(); q.pop();
				for (int v : adj[pos])
					if (v >= root && !vis[root][v]){
						vis[root][v] = true;
						q.push(v);
					}
			}
		}
	}
	static int cnt[1501];
	for (int i = 1; i <= N; ++i)
		for (int j = i+1; j <= N; ++j)
			if (vis[i][j]){
				++cnt[i];
				++cnt[j];
			}
	for (int i = 1; i <= N; ++i)
		cout << cnt[i]+1 << '\n';
return 0;}

