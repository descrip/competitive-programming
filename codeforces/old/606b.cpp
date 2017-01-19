#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int r, c, y, x; cin >> r >> c >> y >> x;
	string s; cin >> s;
	static int a[500][500];
	fill_n(a, 500*500, -1);
	for (int i = 0; i < n; ++i){
		int lx = x, ly = y;
		if (s[i] == 'U')
			++y;
		else if (s[i] == 'D')
			--y;
		else if (s[i] == 'L')
			--x;
		else if (s[i] == 'R')
			++x;
		if (!(0 <= x < c) && !(0 <= y < r)){
			x = lx;
			y = ly;
		}
		if (a[y][x] == -1)
			a[y][x] = i;
	}
return 0;}

