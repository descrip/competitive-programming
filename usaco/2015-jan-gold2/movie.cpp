#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("movie.in", "r", stdin);
	freopen("movie.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, l; cin >> n >> l;
	static int len[20];
	static vector<int> times[20];
	for (int i = 0; i < n; ++i){
		int c; cin >> len[i] >> c;
		while (c--){
			int a; cin >> a;
			times[i].push_back(a);
		}
	}
	static int dp[1<<20];
	fill_n(dp, 1<<20, -1);
	dp[0] = 0;
	int ans = 0xfffffff;
	for (int i = 1; i <= (1<<20); ++i)
		for (int j = 0; j < n; ++j)
			if (((1<<j) & i) != 0){
				auto it = upper_bound(times[j].begin(), times[j].end(), dp[i ^ (1<<j)]);
				if (it == times[j].begin()) continue;
				--it;
				dp[i] = max(dp[i], (*it)+len[j]);
				if (dp[i] >= l)
					ans = min(ans, __builtin_popcount(i));
			}
	cout << (ans == 0xfffffff ? -1 : ans) << '\n';
return 0;}
