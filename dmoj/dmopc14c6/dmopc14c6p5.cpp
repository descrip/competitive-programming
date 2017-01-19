#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	unsigned long long last = 2, mult = 1;
	for (int i = 2; i <= n; ++i){
		last = (4*last * mult) % MOD;
		mult = (mult * 2) % MOD;
	}
	cout << last << '\n';
return 0;}
