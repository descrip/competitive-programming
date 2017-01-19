#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	static long long dp[500010], a[500010];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	long long ans = -1;
	for (int i = 1; i <= n; ++i){
		dp[i] = dp[i-1] + a[i];
		if (i >= k && (ans == -1 || dp[ans]-dp[ans-k] > dp[i]-dp[i-k]))
			ans = i;
	}
	cout << ans-k+1 << '\n';
return 0;}
