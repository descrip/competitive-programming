#include <bits/stdc++.h>
using namespace std;

vector<int> a, dp (2000);

int lis(int n){
	fill(dp.begin(),dp.end(),-0xFFFFFFF);
	int pos = 1, len = 1;
	dp[0] = a[n];
	for (int i = n+1; i < a.size(); ++i){
		pos = lower_bound(dp.begin()+1,dp.begin()+len,a[i]) - dp.begin();
		if (dp[pos-1] > a[i]) continue;
		if (pos == len) ++len;
		dp[pos] = a[i];
	}
	return len;
}

int lds(int n){
	fill(dp.begin(),dp.end(),-0xFFFFFFF);
	int pos = 1, len = 1;
	dp[0] = a[n];
	for (int i = n+1; i < a.size(); ++i){
		pos = lower_bound(dp.begin()+1,dp.begin()+len,a[i],greater<int>()) - dp.begin();
		if (dp[pos-1] < a[i]) continue;
		if (pos == len) ++len;
		dp[pos] = a[i];
	}
	return len;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int tc = 0; tc < t; ++tc){
		int n; cin >> n;
		a.assign(n,0);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		int ans = 0;
		for (int i = 0; i < a.size(); ++i)
			ans = max(ans, lis(i)+lds(i)-1);
		cout << ans << '\n';
	}
return 0;}
