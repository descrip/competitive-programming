#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<vector<int>> v (n, vector<int> (n));
	for (int y = 0; y < n; ++y) for (int x = 0; x < n; ++x){
		cin >> v[y][x];
		if (x > 0) v[y][x] += v[y][x-1];
	}
	int ans = -1270000;
	for (int l = 0; l < n; ++l) for (int r = l; r < n; ++r){
		int sub = 0;
		for (int i = 0; i < n; ++i){
			sub += v[i][r] - (l > 0 ? v[i][l-1] : 0);
			sub = max(sub,0);
			ans = max(ans,sub);
		}
	}
	cout << ans << '\n';
return 0;}
