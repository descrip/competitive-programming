#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc = 1;
	while (true){
		int n, r; cin >> n >> r;
		if (n == 0 && r == 0)
			break;
		cout << "Case " << tc++ << ": ";
		if ((n-1) / r > 26)
			cout << "impossible\n";
		else
			cout << (n-1)/r << '\n';
	}
return 0;}

