#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans = 0;
	for (int i = 10; i <= 1000000; ++i){
		int curr = 0, n = i;
		while (n != 0){
			curr += pow(n % 10, 5);
			n /= 10;
		}
		if (curr == i)
			ans += i;
	}
	cout << ans << '\n';
return 0;}

