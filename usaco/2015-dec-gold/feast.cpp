#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T, A, B; cin >> T >> A >> B;
	static bool dp[5000005][2];
	dp[0][0] = dp[0][1] = true;
	int ans = 0;
	for (int z = 0; z < 2; ++z)
		for (int i = 1; i <= T; ++i)
			for (int j = 0; j <= 1; ++j){
				if ((i-A >= 0 && dp[i-A][j]) || (i-B >= 0 && dp[i-B][j]))
					dp[i][j] = true;
				if (dp[i][j]){
					//cout << z << ' ' << i << '\n';
					ans = max(ans, i);
					if (j == 0)
						dp[i/2][1] = true;
				}
			}
	cout << ans << '\n';
return 0;}
