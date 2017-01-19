#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, s, q, ans = 0;
	cin >> t >> s >> q;
	while (s < t){
		++ans;
		s += (q-1)*s;
	}
	cout << ans << '\n';
return 0;}
