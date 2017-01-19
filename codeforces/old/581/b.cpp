#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v (n), ans (n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int m = 0;
	for (int i = n-1; i >= 0; --i){
		if (v[i] > m)
			ans[i] = 0;
		else
			ans[i] = m - v[i] + 1;
		m = max(m, v[i]);
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
return 0;}
