#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while (n--){
		long long t; cin >> t;
		long long ans = t*(t+1)/2;
		for (long long i = 1; i <= t; i*=2)
			ans -= i*2;
		cout << ans << '\n';
	}
return 0;}

