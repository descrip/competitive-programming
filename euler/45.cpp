#include <bits/stdc++.h>
using namespace std;

const int LIM = 10000000;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n = 40755;
	while (++n){
		double t = (-1 + sqrt(8.0 * n + 1)) / 2.0,
			   p = (1 + sqrt(24.0 * n + 1)) / 6.0,
			   h = (1 + sqrt(8.0 * n + 1)) / 4.0;
		if (t == floor(t) && p == floor(p) && h == floor(h)){
			cout << n << '\n';
			return 0;
		}
	}
return 0;}

