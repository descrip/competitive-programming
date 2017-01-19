/*
ID: jezhao11
LANG: C++11
TASK: castle
*/

#include <bits/stdc++.h>
using namespace std;

int m, n, a[50][50], a2[50][50], cnt[2501], tick = 1;
bool side[4];

void interp(int r){
	for (int i = 3; i >= 0; --i){
		side[i] = false;
		if (r >= (1<<i)){
			side[i] = true;
			r -= (1<<i);
		}
	}
}

void dfs(int x, int y, int r){
	if (!(0 <= x && x < m && 0 <= y && y < n) || a2[y][x] != 0) return;
	a2[y][x] = r;
	++cnt[r];
	interp(a[y][x]);
	if (!side[3])
		dfs(x,y+1,r);
	interp(a[y][x]);
	if (!side[2])
		dfs(x+1,y,r);
	interp(a[y][x]);
	if (!side[1])
		dfs(x,y-1,r);
	interp(a[y][x]);
	if (!side[0])
		dfs(x-1,y,r);
}

int main(){
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
			cin >> a[y][x];
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
			if (a2[y][x] == 0)
				dfs(x,y,tick++);
	/*
	interp(10);
	for (int i = 0; i < 4; ++i)
		cout << side[i] << " \n"[i==3];
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
			cout << a2[y][x] << " \n"[x==m-1];
	*/
	int maxArea = 0;
	for (int i = 1; i < tick; ++i)
		maxArea = max(maxArea, cnt[i]);

	int combArea = 0, combx, comby; char combd;
	for (int x = 0; x < m; ++x){
		for (int y = n-1; y >= 0; --y){
			//cout << x << ' ' << y << ' ' << a2[y][x] << ' ' << a2[y][x+1] << '\n';
			interp(a[y][x]);
			if (side[1] && a2[y][x] != a2[y-1][x]){
				int tmp = cnt[a2[y][x]] + cnt[a2[y-1][x]];
				if (tmp > combArea){
					combArea = tmp;
					combx = x;
					comby = y;
					combd = 'N';
				}
			}
			if (side[2] && a2[y][x] != a2[y][x+1]){
				int tmp = cnt[a2[y][x]] + cnt[a2[y][x+1]];
				if (tmp > combArea){
					combArea = tmp;
					combx = x;
					comby = y;
					combd = 'E';
				}
			}
		}
	}
	cout << tick-1 << '\n'
		 << maxArea << '\n'
		 << combArea << '\n' 
		 << comby+1 << ' ' << combx+1 << ' ' << combd << '\n';
return 0;}
