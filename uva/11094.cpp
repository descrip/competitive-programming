#include <bits/stdc++.h>
using namespace std;

int m, n, x, y, ans;
char a[21][21], l;

int flood(int x, int y){
	if (x < 0 || x >= m) return 0;
	else if (y < 0) return flood(x,n-1);
	else if (y >= n) return flood(x,0);
	else if (a[x][y] == l){
		a[x][y] = '\t';
		return 1 + flood(x-1,y) + flood(x+1,y) + flood(x,y+1) + flood(x,y-1);
	}
	else return 0;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	while (cin >> m >> n){
		ans = 0;
		fill_n(a[0],21*21,'\t');
		for (int x = 0; x < m; ++x) for (int y = 0; y < n; ++y)
			cin >> a[x][y];
		cin >> x >> y;
		l = a[x][y];
		flood(x,y);
		for (int x = 0; x < m; ++x) for (int y = 0; y < n; ++y)
			if (a[x][y] == l) ans = max(ans,flood(x,y));
		cout << ans << '\n';
	}
return 0;}
