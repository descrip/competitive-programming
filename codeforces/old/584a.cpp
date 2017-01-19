#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, t; cin >> n >> t;
	if (floor(log10(t))+1 > n)
		cout << -1 << '\n';
	else
		cout << t << string(n-floor(log10(t))-1, '0') << '\n';
return 0;}
