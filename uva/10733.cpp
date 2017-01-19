#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (true){
		int x; cin >> x;
		if (x == 0) break;
		long long ans = 1;
		for (int i = x; i >= x-6; --i)
			ans = (ans * i) / (x-i+1);
		cout << ans * (ans - 1) / 2 << '\n';
	}
return 0;}

