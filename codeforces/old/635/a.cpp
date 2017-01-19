#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int R, C, N, K; cin >> R >> C >> N >> K;
	static int A[20][20];
	for (int i = 0; i < N; ++i){
		int x, y; cin >> y >> x;
		A[y][x] = 1;
	}
	/*
	for (int y = 1; y <= R; ++y){
		for (int x = 1; x <= C; ++x)
			cout << A[y][x] << ' ';
		cout << '\n';
	}
	*/
	for (int y = 1; y <= R; ++y)
		for (int x = 1; x <= C; ++x)
			A[y][x] = A[y][x] + A[y-1][x] + A[y][x-1] - A[y-1][x-1];
	int ans = 0;
	for (int y = 1; y <= R; ++y)
		for (int x = 1; x <= C; ++x)
			for (int y2 = 1; y2 <= y; ++y2)
				for (int x2 = 1; x2 <= x; ++x2)
					if (A[y][x] - A[y2-1][x] - A[y][x2-1] + A[y2-1][x2-1] >= K)
						++ans;
	cout << ans << '\n';
return 0;}

