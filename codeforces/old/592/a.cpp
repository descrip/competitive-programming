#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static char a[8][8];
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			cin >> a[i][j];
	int minA = 0xfffffff, minB = 0xfffffff;
	for (int x = 0; x < 8; ++x){
		for (int y = 0; y < 8; ++y)
			if (a[y][x] == 'B'){
				for (int y2 = y+1; y2 < 8; ++y2)
					if (a[y2][x] != '.')
						break;
					else if (y2 == 7)
						minB = min(minB, 8-y);
			}
		for (int y = 0; y < 8; ++y)
			if (a[y][x] == 'W'){
				for (int y2 = y-1; y2 >= 0; --y2)
					if (a[y2][x] != '.')
						break;
					else if (y2 == 0)
						minA = min(minA, y);
			}
	}
	//cout << minA << ' ' << minB << '\n';
	if (minA < minB)
		cout << "A\n";
	else cout << "B\n";
return 0;}
