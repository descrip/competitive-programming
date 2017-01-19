#include <bits/stdc++.h>
using namespace std;

const unsigned long long MOD = 10000000000;

unsigned long long modpow(unsigned long long a, unsigned long long b){
	a %= MOD;
	unsigned long long ret = 1;
	while (b > 0){
		if (b & 1)
			ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	unsigned long long ans = 0, ans2 = 0;
	for (unsigned long long i = 1; i <= 1000; ++i){
		unsigned long long a = 1;
		for (unsigned long long j = 0; j < i; ++j)
			a = (a * i) % MOD;
		ans = (ans + a) % MOD;
		ans2 = (ans2 + modpow(i, i)) % MOD;
	}
	cout << ans << ' ' << ans2 << '\n';
return 0;}

