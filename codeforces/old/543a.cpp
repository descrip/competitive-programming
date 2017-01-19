#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m, b, mod; cin >> n >> m >> b >> mod;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	static int dp[501][501][501];
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			for (int k = 0; k <= b; ++k)
				dp[i][j][k] = (dp[i][j-1][k-a[i]] + dp[i-1][j][k]) % mod;
	int ans = 0;
	for (int i = 0; i <= b; ++i)
		ans = (ans + dp[n][m][i]) % mod;
	cout << ans << '\n';
return 0;}
