#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, l; cin >> n >> l;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(),a.end());
	double ans = max(a[0],l-a[a.size()-1]);
	for (int i = 0; i < a.size()-1; ++i)
		ans = max(ans,(a[i+1]-a[i])/2.0);
	cout << fixed << setprecision(11) << ans << '\n';
return 0;}
