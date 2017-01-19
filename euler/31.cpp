#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
	static int dp [201];
	dp[0] = 1;
	for (int i = 0; i < coins.size(); ++i)
		for (int j = coins[i]; j <= 200; ++j)
			dp[j] += dp[j - coins[i]];
	cout << dp[200] << '\n';
return 0;}

