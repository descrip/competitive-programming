#include <iostream>
using namespace std;

int b[2001][2001];

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	unsigned long cnt = 0;
	for (int y = 0; y < n; ++y){
		for (int x = 0; x < n; ++x){
			char c; cin >> c;
			if (c == '#'){
				b[y][x] = 1;
				++cnt;
			}
		}
	}

	for (int y = n-1; y >= 0; --y){
		for (int x = 0; x < n; ++x){
			if (b[y][x] == 1){
				int l = min(b[y+1][x], min(b[y+1][x-1], b[y+1][x+1]));
				if (l > 0 && b[y][x] < l+1){
					cnt += l;
					b[y][x] = max(b[y][x], l+1);
				}
				//cout << x << ' ' << y << ' ' << b[y][x] << ' ' << l << '\n';
			}
		}
	}
	
	cout << cnt << '\n';
return 0;}
