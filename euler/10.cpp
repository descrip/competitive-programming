#include <bits/stdc++.h>
using namespace std;

const int LIM = 2000000;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	bool p[LIM];
	fill_n(p, LIM, true);
	p[0] = p[1] = false;
	long long ans = 0;
	for (int i = 2; i < LIM; ++i)
		if (p[i]){
			for (int j = 2; i*j < LIM; ++j)
				p[i*j] = false;
			ans += i;
		}
	cout << ans << '\n';
return 0;}

