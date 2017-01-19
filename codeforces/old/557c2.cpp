#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;

int main(){
	//cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int,int>> a (n);
	multiset<pair<int,int>> b;
	for (int i = 0; i < n; ++i)
		cin >> a[i].fi;
	for (int i = 0; i < n; ++i)
		cin >> a[i].se;
	sort(a.begin(),a.end(),greater<pair<int,int>>());
	for (int i = 0; i < n; ++i)
		b.insert({a[i].se,a[i].fi});
	int more = 0;
	auto it = b.begin();
	for (; it != b.end(); ++it)
		more += it->fi;
	--it;
	int beh = 0, ans = 0x7FFFFFFF;
	for (int i = 0; i < n; ++i){
		int len = 1, tot = a[i].se;
		more -= a[i].se;
		b.erase(b.find(make_pair(a[i].se,a[i].fi)));
		while (a[i+len].fi == a[i].fi){
			tot += a[i+len].se;
			b.erase(b.find(make_pair(a[i+len].se,a[i+len].fi)));
			more -= a[i+len].se;
			++len;
		}
		int nn = 2*len-1-len-i;
		while (nn-- > 0){
			//cout << nn << ' ' << b.size() << '\n';
			auto it2 = b.end();
			--it2;
			more -= it2->fi;
			b.erase(it2);
		}
		//cout << a[i].fi << ' ' << len << ' ' << nn << ' ' << more << ' ' << beh << ' ' << tot << '\n';
		ans = min(ans,more+beh);
		beh += tot;
		i += len-1;
		if (beh > ans) break;
	}
	cout << ans << '\n';
return 0;}
