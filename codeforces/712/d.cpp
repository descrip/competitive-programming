#include <bits/stdc++.h>
using namespace std;

const long long MOD = (1e9)+7;
int A, B, K, T;
long long dp[2][105*2010], ps[2][105*2010];

long long zmod(long long a) {
	return ((a % MOD)+MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> K >> T;
	dp[1][0+105525] = ps[1][0+105525] = 1;
	for (int i = 1; i < 105*2010; ++i)
		ps[1][i] += ps[1][i-1];
	//cout << ps[1][1004] << ps[1][105525] << ps[1][2001] << '\n';
	for (int t = 0; t < T; ++t) {
		for (int i = 0; i < 105*2010; ++i)
			dp[t%2][i] = ps[t%2][i] = 0;
		for (int i = -K*T+105525; i <= K*T+105525; ++i) {
			//cout << i << ' ' << ps[!(t%2)][i+K] << ' ' << ps[!(t%2)][i-K-1] << '\n';
			dp[t%2][i] = zmod(ps[!(t%2)][i+K] - ps[!(t%2)][i-K-1]);
			ps[t%2][i] = zmod(ps[t%2][i-1] + dp[t%2][i]);
		}
		for (int i = K*T+105525+1; i < 105*2010; ++i)
			ps[t%2][i] = zmod(ps[t%2][i] + ps[t%2][i-1]);
	}
	int X = !(T%2);
	long long ans = 0;
	//for (int i = -K*T; i <= K*T; ++i)
	//	cout << i << ' ' << dp[X][i+105525] << ' ' << ps[X][i+105525] << '\n';
	for (int i = -K*T; i <= K*T; ++i) {
		if (A+i-B-1+105525 >= 0) {
			ans = zmod(ans + dp[X][i+105525] * ps[X][min(A+i-B-1+105525, 105*2010-1)]);
			// TODO: Put upper limit
		}
	}
	cout << ans << '\n';
}

