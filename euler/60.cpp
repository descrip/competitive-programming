#include <bits/stdc++.h>
using namespace std;

const int LIM1 = 10000, LIM2 = 100000000;
bool prime[LIM2];

bool ok(int a, int b){
	return prime[a * (int)pow(10, floor(log10(b)+1)) + b] &&
		   prime[b * (int)pow(10, floor(log10(a)+1)) + a];
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	fill_n(prime, LIM2, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i < LIM2; ++i)
		for (int j = 2; i * j < LIM2; ++j)
			prime[i * j] = false;
	for (int i = 0; i < LIM1; ++i) if (prime[i])
	for (int j = i+1; j < LIM1; ++j) if (prime[j] && ok(j,i))
	for (int k = j+1; k < LIM1; ++k) if (prime[k] && ok(k,j) && ok(k,i))
	for (int l = k+1; l < LIM1; ++l) if (prime[l] && ok(l,k) && ok (l,j) && ok (l,i))
	for (int m = l+1; m < LIM1; ++m) if (prime[m] && ok(m,l) && ok (m,k) && ok(m,j) && ok(m,i)){
		cout << i+j+k+l+m << '\n';
		return 0;
	}
return 0;}

