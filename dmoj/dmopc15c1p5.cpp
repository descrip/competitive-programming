#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int w, h, n; cin >> w >> h >> n;
	static int a[255][255];
	static long long dp[255][255];
	for (int y = 1; y <= h; ++y)
		for (int x = 1; x <= w; ++x)
			cin >> a[y][x];
	for (int y = 1; y <= h; ++y)
		for (int x = 1; x <= w; ++x)
			dp[y][x] += dp[y][x-1] + dp[y-1][x] - dp[y-1][x-1] + a[y][x];
	long long ans = 0;
	for (int y = 1; y <= h; ++y)
		for (int x = 1; x <= w; ++x)
			for (int i = 1; i <= min(n, x); ++i){
				int j = min(y, (n/i));
				//cout << x << ' ' << y << ' ' << i << ' ' << j << ' ' << dp[y][x] - dp[y-j][x] - dp[y][x-i] + dp[y-j][x-i] << '\n';
				ans = max(ans, dp[y][x] - dp[y-j][x] - dp[y][x-i] + dp[y-j][x-i]);
			}
	cout << ans << '\n';
return 0;}
