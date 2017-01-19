#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static long long a[100001], cnt[100001], dp[100001];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		++cnt[a[i]];
	}
	sort(a,a+n);
	for (int i = 1; i <= 100000; ++i)
		dp[i] = max(dp[i-1],dp[max(i-2,0)]+i*cnt[i]);
	cout << dp[a[n-1]] << '\n';
return 0;}
