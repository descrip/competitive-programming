#include <bits/stdc++.h>
using namespace std;

int R, C;
char A[35][50];
bool vis[35][50];

bool recur(int x, int y){
	if (!(0 <= y && y < R) || !(0 <= x && x < C) || vis[y][x] || A[y][x] == '#')
		return false;
	vis[y][x] = true;
	bool a = recur(x-1, y);
	bool b = recur(x+1, y);
	bool c = recur(x, y-1);
	bool d = recur(x, y+1);
	return a || b || c || d || (A[y][x] == 'M');
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C;
	int ans = 0;
	for (int y = 0; y < R; ++y)
		for (int x = 0; x < C; ++x)
			cin >> A[y][x];
	for (int y = 0; y < R; ++y)
		for (int x = 0; x < C; ++x)
			if (!vis[y][x] && A[y][x] != '#')
				ans += recur(x, y);
	cout << ans << '\n';
return 0;}

