#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int best = 0, ans = 0;
	for (int i = 1; i < 1000000; ++i){
		long long curr = i;
		int cnt = 0;
		while (curr != 1){
			if (curr % 2 == 0)
				curr /= 2;
			else
				curr = 3 * curr + 1;
			++cnt;
		}
		if (cnt > best){
			best = cnt;
			ans = i;
		}
	}
	cout << ans << ' ' << best << '\n';
return 0;}

