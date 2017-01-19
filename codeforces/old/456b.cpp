#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	vector<int> a[5];
	int ans = 0;
	for (int i = 1; i <= 4; ++i){
		a[i].push_back(1);
		while (a[i].size() == 1 || a[i][0] != a[i].back())
			a[i].push_back((a[i][a[i].size()-1] * i) % 5);
		a[i].pop_back();

		long long n = 0;
		for (char j : s)
			n = (n*10 + j-'0') % a[i].size();
		ans += a[i][n];
	}
	cout << ans % 5 << '\n';
return 0;}
