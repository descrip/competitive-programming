#include <bits/stdc++.h>
using namespace std;

int numDiv(int n){
	int cnt = 0;
	for (int i = 1; i*i <= n; ++i)
		if (n % i == 0){
			cnt += 2;
			if (n/i == i)
				--cnt;
		}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a = 28, next = 8;
	while (numDiv(a) <= 500)
		a += next++;
	cout << a << '\n';
return 0;}

