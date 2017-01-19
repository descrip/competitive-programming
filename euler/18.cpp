#include <bits/stdc++.h>
using namespace std;

const int LEN = 100;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static long long dp[LEN][LEN];
	for (int y = 0; y < LEN; ++y)
		for (int x = 0; x <= y; ++x)
			cin >> dp[y][x];
	for (int y = LEN-2; y >= 0; --y)
		for (int x = 0; x <= y; ++x)
			dp[y][x] += max(dp[y+1][x], dp[y+1][x+1]);
	cout << dp[0][0] << '\n';
return 0;}

