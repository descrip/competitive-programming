#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc; cin >> tc;
	for (int ts = 1; ts <= tc; ++ts){
		double d, v, u; cin >> d >> v >> u;
		cout << "Case " << ts << ": ";
		if (v >= u || u == 0 || v == 0)
			cout << "can't determine\n";
		else
			cout << fixed << setprecision(3) << abs(round((d / u - d / sqrt(u*u - v*v)) * 1000) / 1000.0) << '\n';
	}
return 0;}

