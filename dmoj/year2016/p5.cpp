#include <bits/stdc++.h>
using namespace std;

int recur(int n, int x){
	//cout << n << ' ' << x << '\n';
	if (n <= x+1)
		return 1;
	else if (x == 1)
		return n-1;
	else
		return 1+recur(n/x, x-1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin >> q;
	for (int qq = 0; qq < q; ++qq){
		int t, n, x; cin >> t >> n >> x;
		cout << t << ' ' << n << ' ' << x << ": ";
		if (t == 1)
			cout << recur(n, x) << '\n';
		else{
			if (x == 1)
				cout << n-1 << '\n';
			else{
				double tmp = (1.0/x)*log2((double)n);
				cout << tmp << '\n';
				cout << ceil(pow(2.0, tmp)) << '\n';
			}
		}
	}
return 0;}

