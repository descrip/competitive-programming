#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long xh, yh, xs, ys, n; cin >> xh >> yh >> xs >> ys >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i){
		long long a, b, c; cin >> a >> b >> c;
		ans += ((a*xs + b*ys + c > 0) ^ (a*xh + b*yh + c > 0));
	}
	cout << ans << '\n';
return 0;}
