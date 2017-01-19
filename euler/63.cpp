#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n = 1, ans = 0;
	double m;
	while (m < 10){
		cout << n << ' ' << m << '\n';
		m = ceil(pow(10, (double)(n-1) / n));
		ans += 10 - m;
		++n;
	}
	cout << ans << '\n';
return 0;}

