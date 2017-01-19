#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	long long n, a = 1, x = 1; cin >> n;
	while (a < n) a += ++x;
	cout << (2*a-x+1)*x/2 << '\n';
return 0;}
