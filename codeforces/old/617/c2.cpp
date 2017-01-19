#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dist(const pair<ll, ll> &a, const pair<ll, ll> &b){
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	pair<ll, ll> p1, p2;
	cin >> p1.first >> p1.second >> p2.first >> p2.second;
	vector<pair<ll, ll>> v (n);
	for (int i = 0; i < n; ++i){
		pair<ll, ll> tmp; cin >> tmp.first >> tmp.second;
		v[i] = {dist(p1, tmp), dist(p2, tmp)};
	}
	ll ans = (1LL<<62);
	v.push_back({0, 0});
	for (int i = 0; i < v.size(); ++i){
		ll r2 = 0;
		for (int j = 0; j < v.size(); ++j){
			if (i == j || v[j].first <= v[i].first) continue;
			else r2 = max(r2, v[j].second);
		}
		ans = min(ans, v[i].first + r2);
	}
	if (n == 1)
		ans = min(ans, v[0].second);
	cout << ans << '\n';
return 0;}

