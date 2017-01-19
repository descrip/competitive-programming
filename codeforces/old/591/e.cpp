#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1002][1002];

bool nota(int x, int y, char c){
	return (a[y][x] != c && a[y][x] != '9')
}

void dijk(char s, char t){
	queue<pair<int,int>> q;
	for (int y = 1; y <= n; ++y)
		for (int x = 1; x <= m; ++x)
			if (a[y][x] == s){
				bool tmp = false;
				for (int c = -1; c <= 1; c+=2){
					tmp &= nota(x, y+c, a[y][x]);
					tmp &= nota(x+c, y, a[y][x]);
				}
				if (tmp)
					q.push(make_pair(x, y));
			}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill_n(a[0], 1002*1002, '9');
	cin >> n >> m;
	for (int y = 1; y <= n; ++y)
		for (int x = 1; x <= m; ++x)
			cin >> a[y][x];
return 0;}
