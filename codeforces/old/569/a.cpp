#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, s, q; cin >> t >> s >> q;
	double z = s;
	long long ans = 0;
	int pos = 0;
	while (pos != t){
		if (pos >= z){
			pos = 0;
			ans++;
		}
		z += (double)(q-1)/q;
		++pos;
	}
	cout << ans+1 << '\n';
return 0;}
