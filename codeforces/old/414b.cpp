#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	static long long dp[2000][2001];
	for (int i = 1; i <= n; ++i)
		dp[0][i] = 1;
	for (int i = 0; i < k-1; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = j; k <= n; k += j)
				dp[i+1][k] = (dp[i+1][k] + dp[i][j]) % MOD;
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = (ans + dp[k-1][i]) % MOD;
	cout << ans << '\n';
return 0;}
