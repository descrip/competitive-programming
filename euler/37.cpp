#include <bits/stdc++.h>
using namespace std;

/*
void recur(int a){
	if (a > 1000000)
		return;
	int n = a;
	while (n > 0){
		n %= (int)pow(10, floor(log10(n)));
		cout << a << ' ' << n << '\n';
		if (n == 0)
			break;
		else if (!primes[n])
			return;
	}
	ans += a;
	//cout << a << ' ' << ans << '\n';
	for (int i = 1; i <= 9; ++i)
		recur(a * 10 + i);
}
*/

bool primes[1000000];

bool yes(int n){
	int a = n;
	while (a > 0){
		if (!primes[a])
			return false;
		a /= 10;
	}
	a = n;
	while (a > 0){
		a %= (int)pow(10, floor(log10(a)));
		if (a == 0)
			break;
		else if (!primes[a])
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> v = {2, 3, 5, 7};
	fill_n(primes, 1000000, true);
	primes[0] = primes[1] = false;
	for (int i = 2; i < 1000000; ++i)
		for (int j = 2; i*j < 1000000; ++j)
			primes[i*j] = false;
	int ans = 0;
	for (int i = 10; i <= 1000000; ++i)
		if (yes(i))
			ans += i;
	cout << ans << '\n';
return 0;}

