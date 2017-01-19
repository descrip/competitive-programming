#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int d, L, v1, v2; cin >> d >> L >> v1 >> v2;
	v2 += v1;
	cout << fixed << setprecision(8) << (double)(L-d)/v2 << '\n';
return 0;}

