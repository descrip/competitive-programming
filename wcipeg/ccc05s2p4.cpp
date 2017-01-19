#include <bits/stdc++.h>
using namespace std;

const int MAXP = 100000001;
bool isPrime[MAXP];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill_n(isPrime, MAXP, true);
	isPrime[0] = isPrime[1] = false;
	int cnt = 0;
	for (int i = 2; i*i <= MAXP; ++i)
		if (isPrime[i])
			for (int j = 2; i*j < MAXP; ++j)
				isPrime[i*j] = false;
	for (int i = 0; i < MAXP; ++i)
		if (isPrime[i])
			++cnt;
	cout << cnt << '\n';
return 0;}

