#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a, b, x; cin >> a >> b >> x;
	ll lcm = a * b / __gcd(a, b);
	cout << x / lcm + (a != 1 && b != 1) << '\n';
return 0;}

