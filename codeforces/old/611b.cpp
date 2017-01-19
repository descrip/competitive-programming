#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long a, b; cin >> a >> b;
	long long ans = 0;
	for (long long i = 1; i <= 60; ++i)
		for (long long j = 0; j < i-1; ++j){
			long long tmp = (1LL<<i) - (1LL<<j) - 1;
			if (a <= tmp && tmp <= b){
				++ans;
				//cout << i << ' ' << j << ' ' << tmp << '\n';
			}
		}
	cout << ans << '\n';
return 0;}
