#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	int ans = 0, t = n;
	while (t >= k){
		int a = t/k, b = t%k;
		ans += a*k;
		t = a+b;
	}
	cout << ans+t << '\n';
return 0;}

