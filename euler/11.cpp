#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static int a[20][20];
	for (int y = 0; y < 20; ++y)
		for (int x = 0; x < 20; ++x)
			cin >> a[y][x];
	long long ans = 0;
	for (int y = 0; y < 20-3; ++y)
		for (int x = 0; x < 20-3; ++x){
			long long curr = 1;
			for (int i = 0; i < 4; ++i)
				curr *= a[y+i][x+i];
			ans = max(ans, curr);
		}
	for (int y = 0; y < 20; ++y)
		for (int x = 0; x < 20-3; ++x){
			long long curr = 1;
			for (int i = 0; i < 4; ++i)
				curr *= a[y][x+i];
			ans = max(ans, curr);
		}
	for (int y = 0; y < 20-3; ++y)
		for (int x = 0; x < 20; ++x){
			long long curr = 1;
			for (int i = 0; i < 4; ++i)
				curr *= a[y+i][x];
			ans = max(ans, curr);
		}
	for (int y = 3; y < 20; ++y)
		for (int x = 0; x < 20-3; ++x){
			long long curr = 1;
			for (int i = 0; i < 4; ++i)
				curr *= a[y-i][x+i];
			ans = max(ans, curr);
		}
	cout << ans << '\n';
return 0;}

