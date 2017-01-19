#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int h, w; cin >> h >> w;
	static char a[501][501];
	for (int y = 1; y <= h; ++y)
		for (int x = 1; x <= w; ++x)
			cin >> a[y][x];
	static int hdp[501][501], vdp[501][501];
	for (int y = 1; y <= h; ++y)
		for (int x = 1; x <= w; ++x){
			hdp[y][x] = hdp[y-1][x] + hdp[y][x-1] - hdp[y-1][x-1];
			if (a[y][x] == '.')
				hdp[y][x] += (a[y][x-1] == '.');
			vdp[y][x] = vdp[y-1][x] + vdp[y][x-1] - vdp[y-1][x-1];
			if (a[y][x] == '.')
				vdp[y][x] += (a[y-1][x] == '.');
		}
	int q; cin >> q;
	for (int i = 0; i < q; ++i){
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << hdp[y2][x2] - hdp[y1-1][x2] - hdp[y2][x1] + hdp[y1-1][x1] +
				vdp[y2][x2] - vdp[y1][x2] - vdp[y2][x1-1] + vdp[y1][x1-1] << '\n';
	}
return 0;}

