#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	if (m < n-1){
		cout << "No\n";
		return 0;
	}
	vector<pair<pair<ll,char>,ll>> v;
	vector<pair<ll,ll>> is (n);
	for (int i = 0; i < n; ++i)
		cin >> is[i].fi >> is[i].se;
	sort(is.begin(),is.end());
	for (int i = 1; i < n; ++i){
		//cout << is[i].fi << ' ' << is[i].se << ' ' << is[i-1].fi << ' ' << is[i-1].se << ' ' << is[i].fi-is[i-1].se << '\n';
		v.push_back({{is[i].fi-is[i-1].se,'c'},i});
		v.push_back({{is[i].se-is[i-1].fi,'e'},is[i].fi-is[i-1].se});
	}
	for (int i = 0; i < m; ++i){
		ll a; cin >> a;
		v.push_back({{a,'b'},i+1});
	}
	sort(v.begin(),v.end());
	set<pair<ll,int>> sts;
	set<pair<ll,int>> br;
	vector<int> ans (n,-1);
	for (int i = 0; i < v.size(); ++i){
		char c = v[i].fi.se;
		ll a = v[i].fi.fi, b = v[i].se;
		//cout << i << ' ' << c << ' ' << a << ' ' << b << '\n';
		if (c == 'b')
			br.insert(make_pair(a,b));
		else if (c == 'c')
			sts.insert(make_pair(a,b));
		else{
			auto sit = sts.lower_bound(make_pair(b,-0x7FFFFFFF));
			if (sit == br.end()){
				cout << "No\n";
				return 0;
			}
			auto cho = br.lower_bound(make_pair(sit->fi,-0x7FFFFFFF));
			if (cho == br.end() || !(sit->fi <= cho->fi && cho->fi <= a)){
				cout << "No\n";
				return 0;
			}
			//cout << distance(sts.begin(),sit) << ' ' << sit->se << ' ' << cho->se << '\n';
			ans[sit->se] = cho->se;
			sts.erase(sit);
			br.erase(cho);
		}
	}
	cout << "Yes\n";
	for (int i = 1; i < n; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
return 0;}
