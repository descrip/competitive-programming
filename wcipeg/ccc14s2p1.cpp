#include <iostream>
using namespace std;

int n;
long long a[2005][2005], ans = 0;

int main(){
	cin >> n;
	for (int y = 0; y < n; ++y) for (int x = 0; x < n; ++x){
		char c; cin >> c;
		a[y][x] = (c == '#' ? 1 : 0);
	}
	for (int y = n-1; y >= 0; --y) for (int x = 0; x < n; ++x){
		if (a[y][x] > 0 && a[y+1][x] > 0 && a[y+1][x-1] > 0 && a[y+1][x+1] > 0)
			a[y][x] += min(a[y+1][x], min(a[y+1][x-1], a[y+1][x+1]));
		ans += a[y][x];
	}
	cout << ans << '\n';
}
