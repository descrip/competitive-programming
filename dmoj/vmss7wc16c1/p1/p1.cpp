#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x; cin >> x;
	for (int i = 2; i*i <= x; ++i)
		while (x % i == 0){
			cout << i << '\n';
			x /= i;
		}
	if (x != 1)
		cout << x << '\n';
return 0;}

