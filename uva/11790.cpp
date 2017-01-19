#include <bits/stdc++.h>
using namespace std;

int n, w[3000], h[3000], dp[3000];

int lis(){
	dp[0] = w[0];
	for (int i = 1; i < n; ++i){
		dp[i] = w[i];
		for (int j = 0; j < i; ++j)
			if (h[i] > h[j])
				dp[i] = max(dp[i], w[i]+dp[j]);
	}
	return *max_element(dp,dp+n);
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int ts; cin >> ts;
	for (int tc = 1; tc <= ts; ++tc){
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> h[i];
		for (int i = 0; i < n; ++i) cin >> w[i];
		int a = lis();
		reverse(w,w+n);
		reverse(h,h+n);
		int b = lis();
		if (a >= b)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n",tc,a,b);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n",tc,b,a);
	}
return 0;}
