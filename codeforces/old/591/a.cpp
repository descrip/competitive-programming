#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	double l, p, q; cin >> l >> p >> q;
	double t = l / (p + q);
	cout << setprecision(9) << fixed << p*t << '\n';
return 0;}
