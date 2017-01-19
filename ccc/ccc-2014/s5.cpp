#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int sqdist(const pair<int, int> &a, const pair<int, int> &b){
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<pair<int, int>> V (N);
	for (int i = 0; i < N; ++i)
		cin >> V[i].fi >> V[i].se;
	vector<pair<int, pair<int, int>>> E;
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
			E.push_back({sqdist(V[i], V[j]), {i, j}});
	sort(E.begin(), E.end());
	reverse(E.begin(), E.end());
	static pair<int, int> dp[2005];
	for (int i = 0; i < N; ++i)
		dp[i] = {1, sqdist(V[i], make_pair(0, 0))};
	for (pair<int, pair<int, int>> p : E){
		pair<int, int> tmpfi = dp[p.se.fi], tmpse = dp[p.se.se];
		if (tmpse.se > p.fi && tmpfi.fi < tmpse.fi+1)
			dp[p.se.fi] = {tmpse.fi+1, p.fi};
		if (tmpfi.se > p.fi && tmpse.fi < tmpfi.fi+1)
			dp[p.se.se] = {tmpfi.fi+1, p.fi};
		//cout << p.fi << ' ' << dp[p.se.fi].fi << ' ' << dp[p.se.se].fi << '\n';
	}
	int ans = 0;
	for (int i = 0; i < N; ++i)
		ans = max(ans, dp[i].fi);
	cout << ans << '\n';
return 0;}

