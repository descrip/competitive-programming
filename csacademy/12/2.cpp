// TODO negative ints
#include <bits/stdc++.h>
using namespace std;

int N, A[100005];
long long dp[100005][2];

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	int x = 1;
	while (A[x] == 0)
		++x;
	if (A[x] < 0)
		dp[x][0] = 1;
	else 
		dp[x][1] = 1;
	for (int i = x+1; i <= N; ++i) {
		if (A[i] == 0)
			continue;
		else if (A[i] < 0) {
			dp[i][0] += dp[i-1][1] + 1;
			dp[i][1] += dp[i-1][1];
		}
		else if (A[i] > 0) {
			dp[i][0] += dp[i-1][0];
			dp[i][1] += dp[i-1][1] + 1;
		}
		//cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
	}
	long long ans = 0;
	for (int i = 1; i <= N; ++i)
		ans += dp[i][1];
	cout << ans << '\n';
	//cout << dp[N][1]-1 << '\n';
}

