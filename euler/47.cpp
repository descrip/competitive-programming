#include <bits/stdc++.h>
using namespace std;

const int LIM = 200000;

int numPrimes(int n){
	int ret = 0;
	for (int i = 2; i*i <= n; ++i)
		if (n % i == 0){
			while (n % i == 0)
				n /= i;
			++ret;
		}
	return ret + (n != 1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i <= LIM; ++i)
		if (numPrimes(i) == 4 && numPrimes(i+1) == 4 && numPrimes(i+2) == 4 && numPrimes(i+3) == 4){
			cout << i << '\n';
			return 0;
		}
return 0;}

