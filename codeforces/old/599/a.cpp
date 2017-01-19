#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long d1, d2, d3; cin >> d1 >> d2 >> d3;
	cout << min(2*d1+2*d3, min(2*d2+2*d3, min(d1+d2+d3, 2*d1+2*d2))) << '\n';
return 0;}

