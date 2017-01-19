#include <bits/stdc++.h>
using namespace std;

int n, m, s, px, py, cx, cy, r;
char a[101][101];

inline bool badpos(){
	if (px < 0 || px >= m || py < 0 || py >= n || a[py][px] == '#') return true;
	else return false;
}

void go(){
	char c; cin >> c;
	if (c == 'D'){
		swap(cx,cy); cx *= -1;
	}
	else if (c == 'E'){
		swap(cx,cy); cy *= -1;
	}
	else{
		px += cx; py += cy;
		if (badpos()){
			px -= cx; py -= cy;
		}
		if (a[py][px] == '*'){
			++r;
			a[py][px] = '.';
		}
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	while (true){
		r = 0;
		cin >> n >> m >> s;
		if (n == 0) break;
		for (int y = 0; y < n; ++y){
			for (int x = 0; x < m; ++x){
				cin >> a[y][x];
				if (a[y][x] == 'N'){
					px = x; py = y; cx = 0; cy = -1;
				}
				else if (a[y][x] == 'S'){
					px = x; py = y; cx = 0; cy = 1;
				}
				else if (a[y][x] == 'L'){
					px = x; py = y; cx = 1; cy = 0;
				}
				else if (a[y][x] == 'O'){
					px = x; py = y; cx = -1; cy = 0;
				}
			}
		}
		cin >> ws;
		while (cin.peek() != '\n') go();
		cout << r << '\n';
	}
return 0;}
