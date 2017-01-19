#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pii> a (n);
	vector<int> cnt (201);
	for (int i = 0; i < n; ++i)
		cin >> a[i].fi;
	for (int i = 0; i < n; ++i)
		cin >> a[i].se, ++cnt[a[i].se];
	sort(a.begin(),a.end(),greater<pair<int,int>>());
	int ans = 0x7FFFFFFF, beh = 0;
	for (int i = 0; i < n; ++i){
		int len = 0, tot = 0;
		while (a[i+len].fi == a[i].fi){
			--cnt[a[i+len].se];
			tot += a[i+len].se;
			++len;
		}
		int del = max(0, n-2*len+1-i), tmp = beh;
		for (int j = 1; j <= 200; ++j){
			tmp += min(cnt[j],del) * j;
			del -= min(cnt[j],del);
		}
		ans = min(ans,tmp);
		beh += tot;
		i += len-1;
	}
	cout << ans << '\n';
return 0;}
