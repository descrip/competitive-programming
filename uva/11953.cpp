#include <bits/stdc++.h>
using namespace std;

int ts, n, ans;
char a[101][101];

void flood(int x, int y){
	if (!(x < 0 || x >= n || y < 0 || y >= n || a[y][x] == '.')){
		a[y][x] = '.';
		flood(x+1,y);
		flood(x-1,y);
		flood(x,y-1);
		flood(x,y+1);
	}
}
		
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> ts;
	for (int tc = 1; tc <= ts; ++tc){
		cin >> n;
		for (int y = 0; y < n; ++y) for (int x = 0; x < n; ++x)
			cin >> a[y][x];
		ans = 0;
		for (int y = 0; y < n; ++y) for (int x = 0; x < n; ++x){
			if (a[y][x] != '.'){
				flood(x,y);
				++ans;
			}
		}
		cout << "Case " << tc << ": " << ans << '\n';
	}
return 0;}
