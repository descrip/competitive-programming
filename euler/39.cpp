#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int best = 0, ans = 0;
	for (int p = 12; p <= 1000; ++p){
		int curr = 0;
		for (int a = 1; a <= p; ++a)
			for (int b = a; b <= p; ++b)
				if (sqrt(a*a+b*b) == (double)p-a-b)
					++curr;
		if (curr > best){
			best = curr;
			ans = p;
		}
	}
	cout << ans << '\n';
return 0;}

