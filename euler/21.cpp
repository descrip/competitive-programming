#include <bits/stdc++.h>
using namespace std;

int sumDiv(int n){
	int ret = 0;
	for (int i = 1; i*i <= n; ++i)
		if (n % i == 0){
			ret += i + n / i;
			if (n / i == i)
				ret -= i;
		}
	return ret - n;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static int a[10000];
	for (int i = 1; i < 10000; ++i)
		a[i] = sumDiv(i);
	int ans = 0;
	for (int i = 1; i < 10000; ++i)
		if (a[i] < 10000 && a[a[i]] == i && a[i] != i)
			ans += i;
	cout << ans << '\n';
return 0;}

