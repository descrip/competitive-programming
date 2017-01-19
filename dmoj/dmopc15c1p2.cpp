#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, l, r; cin >> n >> l >> r;
	int ans = 0;
	vector<int> v (n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < n; ++i){
		//cout << r-1 << ' ' << (i%l) << '\n';
		if (i % l == r-1)
			ans += v[i];
	}
	cout << ans << '\n';
return 0;}
