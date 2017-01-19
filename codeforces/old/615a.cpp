#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<bool> v (m, false);
	for (int i = 0; i < n; ++i){
		int a; cin >> a;
		for (int j = 0; j < a; ++j){
			int b; cin >> b;
			v[b-1] = true;
		}
	}
	sort(v.begin(), v.end());
	cout << (*v.begin() ? "YES" : "NO") << '\n';
return 0;}

