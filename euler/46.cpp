#include <bits/stdc++.h>
using namespace std;

const int LIM = 10000000;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static bool prime[LIM];
	fill_n(prime, LIM, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i < LIM; ++i)
		if (prime[i])
			for (int j = 2; i * j < LIM; ++j)
				prime[i * j] = false;
	for (int i = 35; i < LIM; i += 2){
		if (prime[i])
			continue;
		bool ok = false;
		for (int j = 2; j < i; ++j)
			if (prime[j] && sqrt((i - j) / 2) == floor(sqrt((i - j) / 2)))
				ok = true;
		if (!ok){
			cout << i << '\n';
			return 0;
		}
	}
return 0;}

