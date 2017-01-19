#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int ans = 0;
	static int fact[10];
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 9; ++i)
		fact[i] = fact[i-1] * i;
	for (int i = 10; i <= 10000000; ++i){
		int curr = 0, n = i;
		while (n > 0){
			curr += fact[n % 10];
			n /= 10;
		}
		if (curr == i)
			ans += i;
	}
	cout << ans << '\n';
return 0;}

