#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	if (m < n-1){
		cout << "No\n"; return 0;
	}
	ll lil, lir; cin >> lil >> lir;
	vector<pair<pair<ll,ll>,int>> v;
	for (int i = 1; i < n; ++i){
		ll il, ir; cin >> il >> ir;
		v.push_back({{ir-lil,il-lir},i});
		lil = il; lir = ir;
	}
	set<pair<ll,ll>> bri;
	for (int i = 0; i < m; ++i){
		ll a; cin >> a;
		bri.insert({a,i+1});
	}
	sort(v.begin(),v.end());
	vector<int> ans (n);
	for (auto p : v){
		ll l = p.fi.fi, r = p.fi.se, x = p.se;
		auto it = bri.lower_bound(make_pair(r,-1));
		if (it == bri.end() || it->fi > l){
			cout << "No\n"; return 0;
		}
		ans[x] = it->se;
		bri.erase(it);
	}
	cout << "Yes\n";
	for (int i = 1; i < n; ++i)
		cout << ans[i] << ' ';
return 0;}
