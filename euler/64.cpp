#include <bits/stdc++.h>
using namespace std;

int findPeriod(int n){
	double m = 0, d = 1, a = floor(sqrt(n));
	int cnt = 0;
	while (a != 2*floor(sqrt(n))){
		m = d*a - m;
		d = (n - m*m) / d;
		a = floor((sqrt(n) + m) / d);
		++cnt;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans = 0;
	for (int i = 1; i <= 10000; ++i)
		if (sqrt(i) != floor(sqrt(i)) && findPeriod(i) % 2 == 1)
			++ans;
	cout << ans << '\n';
return 0;}

