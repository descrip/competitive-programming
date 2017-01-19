#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m, h; cin >> n >> m >> h;
	vector<int> v (n);
	for (int i = 0; i < n; ++i) 
		cin >> v[i];
	int ans = 0;
	for (int i = n - 2; i >= 0; --i){
		int d = v[i+1] - v[i] - h;
		if (d <= 0) continue;
		ans += ceil((double) d / m);
		v[i] += ceil((double) d / m) * m;
		if (v[i] > v[i+1])
			swap(v[i+1], v[i]);
	}
	cout << ans << '\n';
return 0;}
