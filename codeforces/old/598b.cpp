#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int m; cin >> m;
	for (int i = 0; i < m; ++i){
		int l, r, k; cin >> l >> r >> k;
		--l; --r;
		k %= r-l+1;
		s = s.substr(0, l) + s.substr(r-k+1, k) + s.substr(l, r-l-k+1) + s.substr(r+1);
	}
	cout << s << '\n';
return 0;}

