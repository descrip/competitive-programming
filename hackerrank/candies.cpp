#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> r (n), dp (n,1);
	for (int i = 0; i < n; ++i)
		cin >> r[i];
	for (int i = 1; i < n; ++i)
		if (r[i] > r[i-1])
			dp[i] = dp[i-1]+1;
	for (int i = n-2; i >= 0; --i)
		if (r[i] > r[i+1])
			dp[i] = max(dp[i],dp[i+1]+1);
	long long ans = 0;
	for (int i : dp)
		ans += i;
	cout << ans << '\n';
return 0;}
