#include <bits/stdc++.h>
using namespace std;

const int LIM = 10000000;
int prime[LIM];

int cnt(int n, int d){
	int ret = 0;
	while (n > 0){
		if (n % 10 == d)
			++ret;
		n /= 10;
	}
	return ret;
}

int repl(int n, int d1, int d2){
	int ret = 0, div = pow(10, (int)floor(log10(n)));
	while (n > 0){
		//cout << n << ' ' << ret << ' ' << div << '\n';
		if (n / div == d1)
			ret = ret * 10 + d2;
		else
			ret = ret * 10 + n / div;
		n %= div;
		div /= 10;
	}
	return ret;
}

bool bash(int n, int d){
	int cnt = 0;
	for (int i = 0; i <= 9; ++i)
		if ((int)floor(log10(repl(n,d,i))+1) == (int)floor(log10(n)+1))
			cnt += prime[repl(n,d,i)];
	return (cnt == 8);
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	fill_n(prime, LIM, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i < LIM; ++i)
		if (prime[i])
			for (int j = 2; i * j < LIM; ++j)
				prime[i * j] = false;
	for (int i = 2; i <= LIM; ++i)
		if (i % 3 != 0)
			for (int j = 0; j <= 2; ++j)
				if (cnt(i, j) == 3 && bash(i, j)){
					cout << i << '\n';
					return 0;
				}
return 0;}

