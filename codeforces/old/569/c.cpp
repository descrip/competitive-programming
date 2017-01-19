#include <iostream>
#include <cmath>
using namespace std;

bool isPalin(int num){
	int n = num;
	int rev = 0;
	while (num > 0){
		int dig = num % 10;
		rev = rev * 10 + dig;
		num = num / 10;
	}
	if (n == rev) return true;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int p, q; cin >> p >> q;
	long long palins = 0, primes = 0;
	static bool prime[5000000];
	fill(prime,prime+5000000,true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(5000000); ++i)
		if (prime[i])
			for (int j = 2; i*j <= 5000000; ++j)
				prime[i*j] = false;
	double A = (double)p/q;
	int ans = 0;
	for (int i = 1; i < 5000000; ++i){
		if (prime[i]) ++primes;
		if (isPalin(i)) ++palins;
		if (primes <= A*palins)
			ans = i;
	}
	cout << ans << '\n';
return 0;}
