#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int,int>> v (n);
	static int dp[100010][2];
	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(),v.end());
	dp[n-1][1] = 1;
	for (int i = n-2; i >= 0; --i){
		auto it = upper_bound(v.begin(),v.end(),make_pair(v[i].first+v[i].second,0x7fffffff));
		cout << i << ' ' << it-v.begin() << '\n';
		dp[i][1] = max(dp[it-v.begin()][1],dp[it-v.begin()][0]) + 1;
		dp[i][0] = max(dp[i+1][0],dp[i+1][1]);
	}
	cout << max(dp[0][0],dp[0][1]) << '\n';
return 0;}
