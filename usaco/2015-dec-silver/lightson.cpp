#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	static vector<pair<int,int>> dict[101][101];
	for (int i = 0; i < M; ++i){
		int x, y, a, b; cin >> x >> y >> a >> b;
		dict[x][y].push_back({a, b});
	}
	queue<pair<int, int>> q;
	q.push({1, 1});
	static bool vis[101][101], on[101][101];
	on[1][1] = true;
	while (!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (vis[y][x])
			continue;
		//cout << x << ' ' << y << '\n';
		vis[y][x] = true;
		for (pair<int, int> p : dict[x][y]){
			on[p.second][p.first] = true;
			for (int c = -1; c <= 1; c+=2)
				if (vis[p.second][p.first+c] || vis[p.second+c][p.first]){
					q.push(p);
					//cout << p.first << ' ' << p.second << '\n';
				}
		}
		for (int c = -1; c <= 1; c+=2)
			if (on[y][x+c])
				q.push({x+c, y});
		for (int c = -1; c <= 1; c+=2)
			if (on[y+c][x])
				q.push({x, y+c});
	}
	int ans = 0;
	for (int y = 1; y <= 100; ++y)
		for (int x = 1; x <= 100; ++x)
			if (on[y][x])
				++ans;
	cout << ans << '\n';
return 0;}

