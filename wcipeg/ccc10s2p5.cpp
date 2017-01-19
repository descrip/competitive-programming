#include <bits/stdc++.h>
using namespace std;

struct planet{
	int x, y, z, v, r;
} P[1005];

int M, N, D, A[1005][3], ans = 0;
bool vis[1005];

int sqmagn(int x, int y, int z){
	return x*x + y*y + z*z;
}

int cprod(int x1, int y1, int z1, int x2, int y2, int z2){
	return sqmagn(y1*z2-y2*z1, z1*x2-z2*x1, x1*y2-x2*y1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> M;
	for (int i = 0; i < M; ++i)
		cin >> P[i].x >> P[i].y >> P[i].z >> P[i].v >> P[i].r;
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> A[i][j];
	cin >> D;
	for (int i = 0; i < M; ++i)
		P[i].r += D;
	for (int i = 1; i < N; ++i){
		for (int j = 0; j < M; ++j) if (!vis[j]){
			int x1 = A[i-1][0], y1 = A[i-1][1], z1 = A[i-1][2],
				x2 = A[i][0], y2 = A[i][1], z2 = A[i][2],
				a = P[j].x, b = P[j].y, c = P[j].z,
				d = x2-x1, e = y2-y1, f = z2-z1,
				top1 = (a-x1)*d + (b-y1)*e + (c-z1)*f,
				bot1 = sqmagn(d, e, f),
				top2 = cprod(a-x1, b-y1, c-z1, a-x2, b-y2, c-z2),
				bot2 = bot1;	//HALF!
				cout << i << ' ' << j << ' ' << top1 << ' ' << bot1 << ' '<< top2 << '\n';
				//TODO: Check t=0 edge case
				if (top1 * bot1 >= 0 && top1 <= bot1 && top2 <= 4*bot2*P[i].r*P[i].r){
					vis[j] = true;
					ans += P[j].v;
				}
		}
	}
	cout << ans << '\n';
return 0;}

