#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long double l, r, k; cin >> l >> r >> k;
	long double a = pow(k, ceil(log(l)/log(k)));
	int cnt = 0;
	while (a <= r){
		cout << (long long)a << ' ';
		++cnt;
		a *= k;
	}
	if (cnt == 0)
		cout << "-1\n";
	else
		cout << '\n';
return 0;}

