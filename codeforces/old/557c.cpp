#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;

bool fsort(pair<int,int> a, pair<int,int> b){
	return a.se < b.se;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i].fi;
	for (int i = 0; i < n; ++i)
		cin >> a[i].se;
	sort(a.begin(),a.end(),greater<pair<int,int>>());
	int beh = 0, ans = 0x7FFFFFFF;
	/*
	for (int i = 0; i < n; ++i)
		cout << '(' << a[i].fi << ' ' << a[i].se << ") ";
	cout << '\n';
	*/
	for (int i = 0; i < n; ++i){
		int len = 1, tot = a[i].se;
		while (a[i+len].fi == a[i].fi){
			tot += a[i+len].se;
			++len;
		}
		int nn = len*2-1, more = 0;
		nn = n - nn - i;
		sort(a.begin()+i+len,a.end(),fsort);
		for (int j = i+len; j < i+len+nn; ++j)
			more += a[j].se;
		cout << a[i].fi << ' ' << len << ' ' << nn << ' ' << more << ' ' << beh << ' ' << tot << '\n';
		ans = min(ans,more+beh);
		beh += tot;
		i += len-1;
		if (beh > ans) break;
	}
	cout << ans << '\n';
return 0;}
