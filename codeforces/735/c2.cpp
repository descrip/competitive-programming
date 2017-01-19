#include <bits/stdc++.h>
using namespace std;

long long n;
map<long long, long long> dp;

long long recur(long long x) {
	if (dp.count(x) > 0)
		return dp[x];
	else if (x % 2 == 0) {
		long long a = recur(x/2-1), b = recur(x/2+1);
		//cout << a << ' ' << b << '\n';
		return dp[x] = max(a, b) + (abs(a-b) <= 1);
	}
	else {
		long long a = recur(x/2), b = recur(x/2+1);
		return dp[x] = max(a, b) + (abs(a-b) <= 1);
	}
}

int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	cin >> n;
	dp[0] = dp[1] = 0;
	dp[2] = 1;
	cout << recur(n) << '\n';
	for (int i = 0; i <= 15; ++i)
		cout << i << ' ' << recur(i) << '\n';
	return 0;
}

// 1000000000000000000
