#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	string s, t; cin >> s >> t;
	if (M > N){
		int xd = N;
		N = M;
		M = xd;
		string tmp = t;
		t = s;
		s = tmp;
	}
	static int dp[1010][1010];
	fill_n(dp[0], 1010*1010, 0xfffffff);
	dp[0][0] = 0;
	for (int j = 0; j <= M; ++j)
		for (int i = 0; i <= N; ++i){
			if (dp[i][j] != 0xfffffff)
				continue;
			int ret = max(i, j);
			for (int k = 1; k <= 3; ++k)
				if (i >= k)
					ret = min(ret, dp[i-k][j]+1);
			for (int k = 1; k <= 2; ++k)
				if (i >= k)
					ret = min(ret, dp[i][j-k]+1);
			if (i >= 1 && j >= 1)
				ret = min(ret, dp[i-1][j-1] + (s[i-1] != t[i-1]));
			dp[i][j] = ret;
		}
	for (int j = 0; j <= M; ++j){
		for (int i = 0; i <= N; ++i)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}
	cout << dp[N][M] << '\n';
return 0;}

