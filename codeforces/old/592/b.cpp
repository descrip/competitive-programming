#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	long long ans = n-2+n-3+n-4;
	for (int i = 3; i < n; ++i)
		ans += n-4;
	cout << ans+1 << '\n';
return 0;}
