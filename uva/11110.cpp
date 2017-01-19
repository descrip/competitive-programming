#include <bits/stdc++.h>
using namespace std;

int n, a[101][101], v[101];

int flood(int x, int y, int z){
	if (x < 0 || x >= n || y < 0 || y >= n || a[y][x] != z) return 0;
	else{
		a[y][x] = -1;
		return 1 + flood(x-1,y,z) + flood(x+1,y,z) + flood(x,y-1,z) + flood(x,y+1,z);
	}
}

bool ok(){
	for (int y = 0; y < n; ++y) for (int x = 0; x < n; ++x){
		if (a[y][x] != -1){
			if (v[a[y][x]] != 0) return false;
			else v[a[y][x]] = flood(x,y,a[y][x]);
		}
	}
	for (int i = 1; i < n; ++i)
		if (v[i] != v[i-1]) return false;
	return true;
}

int main(){
	//cin.sync_with_stdio(0); cin.tie(0);
	while (true){
		cin >> n;
		if (n == 0) break;
		fill(v,v+101,0);
		fill_n(a[0],101*101,0);
		for (int i = 1; i < n; ++i){
			int x, y; string s;
			cin >> ws;
			getline(cin,s);
			istringstream iss (s);
			while (iss >> x >> y) a[y-1][x-1] = i;
		}
		cout << (ok() ? "good\n" : "wrong\n");
	}
return 0;}
