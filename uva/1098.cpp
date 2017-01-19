#include <bits/stdc++.h>
using namespace std;

int r, c, cx1, cx2, cx3, cy1, cy2, cy3;
bool vis[8][8], canvis[8][8];

inline bool obo(int x, int y){
	return x < 0 || x >= c || y < 0 || y >= r;
}

inline int manhat(int x1, int y1, int x2, int y2){
	return abs(x1-x2) + abs(y1-y2);
}

inline bool invalid(int x, int y){
	return (x == 1 && y == 0) ? false : (obo(x,y) || vis[y][x]);
}

void dfs(int x, int y){
	if (obo(x,y) || canvis[y][x] || vis[y][x]) return;
	canvis[y][x] = true;
	dfs(x+1,y); dfs(x-1,y); dfs(x,y-1); dfs(x,y+1);
}

bool disconn(){
	fill_n(canvis[0],64,false);
	dfs(1,0);
	for (int y = 0; y < r; ++y) for (int x = 0; x < c; ++x)
		if (!canvis[y][x] && !vis[y][x]) return true;
	return false;
}

bool reach(int x, int y, int z){
	if (z <= r*c/4) return manhat(x,y,cx1,cy1) <= r*c/4;
	else if (z <= r*c/2) return manhat(x,y,cx2,cy2) <= r*c/2;
	else if (z <= 3*r*c/4) return manhat(x,y,cx3,cy3) <= 3*r*c/4;
	else return manhat(x,y,1,0) <= r*c-z;
}

bool roomy(int px, int py){
	for (int y = 0; y < r; ++y) for (int x = 0; x < c; ++x){
		if ((x == px && y == py) || (x == 1 && y == 0) || vis[y][x]) continue;
		else if (!invalid(x-1,y) + !invalid(x+1,y) + !invalid(x,y-1) + !invalid(x,y+1) < 2) return false;
	}
	return true;
}

int recur(int x, int y, int z){
	if (z == r*c) return x == 1 && y == 0;
	else if (obo(x,y) || vis[y][x] || (x == 1 && y == 0) ||
			(z == r*c/4 && (x != cx1 || y != cy1)) ||
			(z == r*c/2 && (x != cx2 || y != cy2)) ||
			(z == 3*r*c/4 && (x != cx3 || y != cy3)) ||
			(x == cx1 && y == cy1 && z != r*c/4) ||
			(x == cx2 && y == cy2 && z != r*c/2) ||
			(x == cx3 && y == cy3 && z != 3*r*c/4) ||
			!reach(x,y,z) || !roomy(x,y) || disconn())
		return false;
	else{
		vis[y][x] = true;
		int ret = recur(x+1,y,z+1) + recur(x-1,y,z+1) + recur(x,y-1,z+1) + recur(x,y+1,z+1);
		vis[y][x] = false;
		return ret;
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int tc = 1;
	while (true){
		cin >> r >> c;
		if (r == 0) break;
		cin >> cy1 >> cx1 >> cy2 >> cx2 >> cy3 >> cx3;
		fill_n(vis[0],64,false);
		cout << "Case " << tc++ << ": " << recur(0,0,1) << '\n';
	}
return 0;}
