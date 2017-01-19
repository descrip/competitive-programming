#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int a = 1, c = 1, b = 1;
	while (a <= n){
		b += ++c;
		a += b;
	}
	cout << c-1 << '\n';
return 0;}
