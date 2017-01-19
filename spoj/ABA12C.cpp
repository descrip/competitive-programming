#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static int dp[105][105];
	vector<pair<int, int>> V;
	int C, N, K; cin >> C;
	for (int c = 0; c < C; ++c){
		cin >> N >> K;
		V.clear();
		for (int i = 1; i <= K; ++i){
			int a; cin >> a;
			if (a != -1)
				V.push_back({i, a});
		}
		fill_n(dp[0], 105*105, 0xfffffff);
		dp[0][0] = 0;
		for (int i = 1; i <= K; ++i)
			for (int j = 0; j < V.size(); ++j)
				if (V[j].first > i)
					break;
				else 
					for (int k = 0; k <= N; ++k)
						dp[i][k+1] = min(dp[i][k+1], dp[i-V[j].first][k] + V[j].second);
		int ans = 0xfffffff;
		for (int i = 0; i <= N; ++i)
			ans = min(ans, dp[K][i]);
		if (ans == 0xfffffff)
			cout << -1 << '\n';
		else
			cout << ans << '\n';
	}
return 0;}

