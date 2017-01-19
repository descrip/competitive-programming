#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v (n+1);
	vector<vector<int>> dp (n+10, vector<int> (2));
	//dp[0][1] = -0x7fffffff;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	v[0] = -0x7fffffff;
	int ans = 1;
	for (int i = 1; i <= n; ++i){
		if (v[i-1] < v[i]){
			dp[i][0] = dp[i-1][0]+1;
			if (dp[i][1] == 0)
				dp[i][1] = dp[i-1][1]+1;
		}
		else{
			dp[i][1] = dp[i-1][0]+1;
			if (v[i-1]+1 < v[i+1] || (v[i] < v[i+1] && v[i-2] < v[i]-1))
				dp[i+1][1] = dp[i][1]+1;
			else
				dp[i+1][1] = -0x7fffffff;
			dp[i][0] = 1;
		}
		ans = max(ans,max(dp[i][0],dp[i][1]));
	}
	cout << ans << '\n';
return 0;}
