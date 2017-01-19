#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; ++i)
		cin >> a[i];
	sort(a.begin(),a.end());
	int ans = 0xfffffff;
	for (int i = 0; i < m-n+1; ++i)
		ans = min(ans,a[i+n-1]-a[i]);
	cout << ans << '\n';
return 0;}
