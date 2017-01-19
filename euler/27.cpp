#include <bits/stdc++.h>
using namespace std;

const int MAXP = 1000000;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	static bool prime[MAXP];
	fill_n(prime, MAXP, true);
	prime[0] = prime[1] = false;
	set<int> pser;
	for (int i = 2; i < MAXP; ++i)
		if (prime[i]){
			for (int j = 2; i*j < MAXP; ++j)
				prime[i*j] = false;
			pser.insert(i);
		}
	int best = 0, ans;
	for (int b2 : pser){
		if (b2 >= 1000) break;
		for (int b = b2; b >= -b2; b -= 2*b2)
			for (int a = -999; a < 1000; ++a){
				int curr = 0, n = 0;
				while (pser.count(n*n + a*n + b) || pser.count(-(n*n + a*n + b))){
					++curr;
					++n;
				}
				if (curr == 80)
					cout << a << ' ' << b << '\n';
				if (curr > best){
					best = curr;
					ans = a*b;
				}
			}
	}
	cout << ans << '\n';
return 0;}

