#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n = s.size();
	vector<int> dp (s.size());
	dp[0] = (s[0] == s[1]);
	for (int i = 1; i < n-1; ++i)
		dp[i] = dp[i-1] + (s[i] == s[i+1]);
	dp[n-1] = dp[n-2];
	dp.insert(dp.begin(),0);
	int m; cin >> m;
	for (int i = 0; i < m; ++i){
		int l, r; cin >> l >> r;
		cout << dp[r-1] - dp[l-1] << '\n';
	}
return 0;}
