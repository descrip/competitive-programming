#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long Ei, Ef, Eb, B, C; cin >> Ei >> Ef >> Eb >> B >> C;
	long long ans = 0;
	while (Ei < Ef){
		Ei += B*2 + min(B, Eb);
		Eb -= min(B, Eb);
		ans += C;
	}
	cout << ans/C << '\n' << ans << '\n';
return 0;}

