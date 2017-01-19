#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, a, b, c; cin >> n >> a >> b >> c;
	static int dp[4001];
	fill(dp,dp+4001,-0xfffffff);
	dp[a] = dp[b] = dp[c] = 1;
	for (int i = 1; i <= n; ++i)
		dp[i] = max(dp[i],
				max(dp[max(i-a,0)]+1,
				max(dp[max(i-b,0)]+1,
					dp[max(i-c,0)]+1)));
	cout << dp[n] << '\n';
return 0;}
