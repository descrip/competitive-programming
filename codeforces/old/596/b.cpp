#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> b (n);
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	long long ans = abs(b[0]);
	for (int i = 1; i < n; ++i)
		ans += abs(b[i-1] - b[i]);
	cout << ans << '\n';
return 0;}

