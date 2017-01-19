#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	static vector<pair<int, int>> adj[18];
	for (int i = 0; i < M; ++i){
		int x, y, z; cin >> x >> y >> z;
		adj[x].push_back({y, z});
	}
	static int dp[18][(1<<18)];
	fill_n(dp[0], 18*(1<<18), -0xfffffff);
	dp[0][1<<0] = 0;
	int ans = 0;
	for (int m = 0; m < (1<<18); ++m)
		for (int i = 0; i < N; ++i)
			if (((1<<i) & m) != 0)
				for (auto p : adj[i])
					if (((1<<p.first) & m) == 0){
						int tmp = m | (1<<p.first);
						dp[p.first][tmp] = max(dp[p.first][tmp], dp[i][m] + p.second);
						if (p.first == N-1)
							ans = max(ans, dp[p.first][tmp]);
					}
	cout << ans << '\n';
return 0;}

