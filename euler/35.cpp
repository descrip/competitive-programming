#include <bits/stdc++.h>
using namespace std;

const int LIM = 1000000;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	static bool primes[LIM];
	fill_n(primes, LIM, true);
	primes[0] = primes[1] = false;
	for (int i = 2; i*i < LIM; ++i)
		if (primes[i])
			for (int j = 2; i*j < LIM; ++j)
				primes[i*j] = false;
	int ans = 0;
	for (int i = 2; i < LIM; ++i)
		if (primes[i]){
			int n = i, dig;
			while (true){
				dig = n / pow(10, (int)floor(log10(i)));
				n %= (int)pow(10, (int)floor(log10(i)));
				n = n * 10 + dig;
				if (dig == 0)
					break;
				//cout << i << ' ' << n << ' ' << dig << ' ' << (int)floor(log10(n) + 1) << '\n';
				if (!primes[n])
					break;
				else if (n == i){
					++ans;
					break;
				}
			}
		}
	cout << ans << '\n';
return 0;}

