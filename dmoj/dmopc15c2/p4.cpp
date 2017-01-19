#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<pair<long long, long long>> v;
	static long long hap[100001], dp[200002];
	for (int i = 1; i <= N; ++i){
		long long a, l, h; cin >> a >> l >> h;
		hap[i] = h;
		v.push_back(make_pair(a,i));
		v.push_back(make_pair(a+l,-i));
	}
	sort(v.begin(), v.end());
	long long best = 0;
	for (int i = 0; i < v.size(); ++i){
		//cout << i << ' ' << best << '\n';
		if (v[i].second > 0)
			dp[v[i].second] = best;
		else{
			dp[-v[i].second] += hap[-v[i].second];
			best = max(best, dp[-v[i].second]);
		}
	}
	cout << best << '\n';
return 0;}

