#include <bits/stdc++.h>
using namespace std;

int v[76*2][76], n;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int ts; cin >> ts;
	for (int tc = 0; tc < ts; ++tc){
		cin >> n;
		for (int y = 0; y < n; ++y) for (int x = 0; x < n; ++x){
			cin >> v[y][x];
			if (x > 0) v[y][x] += v[y][x-1];
			v[y+n][x] = v[y][x];
		}
		int ans = -100*75*75;
		for (int l = 0; l < n; ++l) for (int r = l; r < n; ++r){
			int sub = 0, subw = 0, last = 0, lastw = 0;
			for (int i = 0; i < 2*n; ++i)
		}
	}
return 0;}
