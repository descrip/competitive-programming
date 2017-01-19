#include <cmath>
#include <iostream>
using namespace std;

int digits(int n){
	return log10(n)+1;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	long long ans = 0;
	long long n, a = 10; cin >> n;
	if (n < 10){
		cout << n << '\n'; return 0;
	}
	while (a <= n){
		ans += (a - a/10.0) * digits(a/10.0);
		a *= 10;
	}
	ans += (n - a/10.0 + 1) * digits(a/10.0);
	cout << ans << '\n';
return 0;}
