#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int v; cin >> v;
	static int a[25];
	for (int i = 0; i < v; ++i)
		cin >> a[i];
	int g; cin >> g;
	static int b[15][25];
	for (int i = 0; i < g; ++i)
		for (int j = 0; j < v; ++j)
			cin >> b[i][j];
	static int curr[25];
	int ans = 0xfffffff;
	for (int i = 1; i < (1<<g); ++i){
		fill_n(curr, 25, 0);
		for (int j = 0; j < g; ++j)
			if (i & (1<<j) != 0)
				for (int k = 0; k < v; ++k)
					curr[k] += b[j][k];
		for (int j = 0; j < v; ++j){
			cout << j << ' ' << curr[j] << '\n';
			if (curr[j] < a[j])
				break;
			else if (j == v-1 && __builtin_popcount(i) < __builtin_popcount(ans))
				ans = i;
		}
	}
	cout << __builtin_popcount(ans);
	for (int i = 0; i < g; ++i)
		if (ans & (1<<i) != 0)
			cout << ' ' << i;
	cout << '\n';
return 0;}
