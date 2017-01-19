#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n, k, x; cin >> n >> k >> x;
	static long long dp[200000], rdp[200000];
	static int a[200000];
	cin >> a[0];
	dp[0] = a[0];
	for (int i = 1; i < n; ++i){
		cin >> a[i];
		dp[i] = dp[i-1] | a[i];
	}
	rdp[n-1] = a[n-1];
	for (int i = n-2; i >= 0; --i)
		rdp[i] = rdp[i+1] | a[i];
	long long ans = 0, r = 1;
	for (int i = 0; i < k; ++i)
		r *= x;
	for (int i = 1; i < n-1; ++i)
		ans = max(ans, ((a[i] * r) | dp[i-1]) | rdp[i+1]);
	ans = max(ans, (a[0] * r) | rdp[1]);
	ans = max(ans, (a[n-1] * r) | dp[n-2]);
	cout << ans << '\n';
return 0;}
