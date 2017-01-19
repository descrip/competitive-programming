#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	static<pair<int, int>> edges[500];
	for (int i = 0; i < N; ++i){
		int x, y; cin >> x >> y;
		--x; --y;
		edges[i] = {x, y};
	}
	static int val[500];
	fill_n(val, 500, -1);
	val[0] = 10000;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (val[j] != -1)
return 0;}

