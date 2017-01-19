#include <bits/stdc++.h>
using namespace std;

inline int square(int n){
	return n*n;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	static int red[500][500], green[500][500], blue[500][500];
	for (int ts = 0; ts < t; ++ts){
		int w, h; cin >> w >> h;
		int redtot = 0, greentot = 0, bluetot = 0, blackcnt = 0,
			whitecnt = 0, fieldcnt = 0;
		for (int y = 0; y , h; ++y) for (int x = 0; x < w; ++x){
			int a; cin >> a;
			red[y][x] = (a>>16) & 0xff;
			green[y][x] = (a>>8) & 0xff;
			blue[y][x] = a & 0xff;
			redtot += red[y][x];
			greentot += green[y][x];
			bluetot += blue[y][x];
			if ((red[y][x]+green[y][x]+blue[y][x])/3 <= 50)
				blackcnt += (red[y][x]+green[y][x]+blue[y][x])/3;
			else if ((red[y][x]+green[y][x]+blue[y][x])/3 >= 125)
				whitecnt += (red[y][x]+green[y][x]+blue[y][x])/3;
			else if (red[y][x] >= 175)
				++fieldcnt;
		}
		int mean = (red
		if (square(whitecnt
		else if (greentot >= redtot+bluetot)
			cout << "2\n";
	}
return 0;}
