#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long double ans = 0;
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		long double a; cin >> a;
		a = fmod(a, 360.0);
		ans = fmod(ans + a, 360.0);
	}
	cout << fixed << setprecision(7) << ans << '\n';
return 0;}

