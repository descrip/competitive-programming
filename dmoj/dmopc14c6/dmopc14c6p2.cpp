#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int b = 0, w = 0, bt = 0, wt = 0;
	cin >> b >> bt;
	w = b;
	for (int i = 1; i < n-1; ++i){
		int x, y; cin >> x >> y;
		if (y > bt)
			b -= (y - bt);
		bt = max(bt - y, 0);
		if (y > w)
			wt -= (y - w);
		w = max(0, w - y);
		bt += x;
		wt += x;
	}
	cout << max(w,0) << '\n' << max(b,0) << '\n';
return 0;}
