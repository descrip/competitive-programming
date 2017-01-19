/*
ID: jezhao11
LANG: C++11
TASK: frac1
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<double,pair<int,int>>> v;
	for (int d = 1; d <= n; ++d)
		for (int t = 0; t <= d; ++t)
			v.push_back({(double)t/d, {t,d}});
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		if (i == 0 || v[i].first != v[i-1].first)
			cout << v[i].second.first << '/' << v[i].second.second << '\n';
return 0;}
