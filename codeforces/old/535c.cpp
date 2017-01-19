#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long a, b, n; cin >> a >> b >> n;
	for (int q = 0; q < n; ++q){
		long long l, t, m; cin >> l >> t >> m;
		long long lo = l, hi = 100000000, mid;
		while (lo + 1 < hi){
			mid = lo + (hi-lo)/2;
			//cout << mid << ' ' <<b*(l+mid)*(mid-l+1)/2 + a*(mid-l+1) << '\n';
			if (b*mid + a <= m*t)
				lo = mid;
			else
				hi = mid;
		}
		cout << lo << ' ' << hi << '\n';
		if (mid == 0)
			cout << "-1\n";
		else
			cout << lo << '\n';
	}
return 0;}
