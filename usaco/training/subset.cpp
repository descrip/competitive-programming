/*
ID: descrip
LANG: C++11
TASK: subset
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static long long dp[1000];
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = n*(n+1)/2-i; j >= 0; --j)
			dp[j+i] += dp[j];
	cout << (n*(n+1) % 4 == 0 ? dp[n*(n+1)/4]/2 : 0) << '\n';
return 0;}
