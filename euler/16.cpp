#include <bits/stdc++.h>
using namespace std;

const int POW = 10;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static int dig[POW];
	dig[POW-1] = 1;
	int carry = 0;
	for (int i = 1; i <= POW; ++i)
		for (int j = POW-1; j >= 0; --j){
			dig[j] = dig[j] * 2 + carry;
			carry = dig[j] / 10;
			dig[j] %= 10;
		}
	int ans = 0;
	for (int i = 0; i < POW; ++i)
		ans += dig[i];
	cout << ans << '\n';
return 0;}

