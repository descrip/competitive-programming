#include <bits/stdc++.h>
using namespace std;

int n, dp[101][101], a[101][101];

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x){
			cin >> a[y][x];
			dp[y][x] += a[y][x];
			if (y > 0) dp[y][x] += dp[y-1][x];
			if (x > 0) dp[y][x] += dp[y][x-1];
			if (y > 0 && x > 0) dp[y][x] -= dp[y-1][x-1];
		}
	int ans = -127*100*100;
	for (int y1 = 0; y1 < n; ++y1) for (int x1 = 0; x1 < n; ++x1)
		for (int y2 = y1+1; y2 < n; ++y2) for (int x2 = x1+1; x2 < n; ++x2){
			int sub = dp[y2][x2];
			if (y1 > 0) sub -= dp[y1-1][x2];
			if (x1 > 0) sub -= dp[y2][x1-1];
			if (y1 > 0 && x1 > 0) sub += dp[y1-1][x1-1];
			ans = max(ans,sub);
		}
	cout << ans << '\n';
return 0;}
