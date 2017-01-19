#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static long double a[6];
	for (int i = 0; i < 6; ++i)
		cin >> a[i];
	static pair<long double,long double> b[7];
	b[0] = b[6] = {0,0};
	b[1] = {0,a[1]};
	b[2] = {a[2]*sqrt(3),b[1].second+a[2]/2};
	b[3] = {b[2].first+a[3]*sqrt(3),b[2].second-a[3]/2};
	b[4] = {b[3].first,b[3].second-a[4]};
	b[5] = {b[4].first-a[5]*sqrt(3),b[4].second-a[5]/2};
	long double ans = 0;
	for (int i = 0; i < 6; ++i){
		ans += b[i].first * b[i+1].second;
		ans -= b[i].second * b[i+1].first;
	}
	cout << (int)round(abs(ans) / sqrt(3)) << '\n';
return 0;}
