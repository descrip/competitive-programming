#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("fortmoo.in", "r", stdin);
	freopen("fortmoo.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	static char A[200][200];
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> A[y][x];
	static int H1[200][200], H2[200][200], W1[200][200], W2[200][200];
	fill_n(H1[0], 200*200, -1);
	fill_n(H2[0], 200*200, -1);
	fill_n(W1[0], 200*200, -1);
	fill_n(W2[0], 200*200, -1);
	H1[0][0] = W1[0][0] = (A[0][0] == '.');
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x){
			if ((x == 0 && y == 0) || A[y][x] == 'X')
				continue;
			W1[y][x] = H1[y][x] = 1;
			if (y-1 >= 0 && H1[y-1][x] != -1)
				H1[y][x] = H1[y-1][x] + 1;
			if (x-1 >= 0 && W1[y][x-1] != -1)
				W1[y][x] = W1[y][x-1] + 1;
		}
	W2[N-1][M-1] = H2[N-1][M-1] = (A[N-1][M-1] == '.');
	for (int y = N-1; y >= 0; --y)
		for (int x = M-1; x >= 0; --x){
			if ((x == M-1 && y == N-1) || A[y][x] == 'X')
				continue;
			W2[y][x] = H2[y][x] = 1;
			if (y+1 < N && H2[y+1][x] != -1)
				H2[y][x] = H2[y+1][x] + 1;
			if (x+1 < M && W2[y][x+1] != -1)
				W2[y][x] = W2[y][x+1] + 1;
		}
	int ans = 0;
	for (int y2 = 0; y2 < N; ++y2)
		for (int x2 = 0; x2 < M; ++x2)
			for (int x1 = 0; x1 <= x2; ++x1)
				for (int y1 = 0; y1 <= y2; ++y1){
					if (y2-H1[y2][x2]+1 <= y1 && x2-W1[y2][x2]+1 <= x1 && y1+H2[y1][x1]-1 >= y2 && x1+W2[y1][x1]-1 >= x2){
						//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << ans << '\n';
						ans = max(ans, (y2-y1+1)*(x2-x1+1));
					}
				}
	//cout << H1[2][2] << ' ' << W1[2][2] << '\n';
	cout << ans << '\n';
return 0;}

