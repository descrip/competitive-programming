#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int M, N, K; cin >> N >> M >> K;
	static int A[30005][1005];
	for (int k = 0; k < K; ++k){
		int x, y, R, B; cin >> x >> y >> R >> B;
		A[max(y-R, 1)][x] += B;
		A[min(y+R+1, N+1)][x] -= B;
		for (int i = 1; i <= R; ++i){
			int H = sqrt(R*R - i*i);
			if (x+i <= M){
				A[max(y-H, 1)][x+i] += B;
				A[min(y+H+1, N+1)][x+i] -= B;
			}
			if (x-i >= 1){
				A[max(y-H, 1)][x-i] += B;
				A[min(y+H+1, N+1)][x-i] -= B;
			}
		}
		/*
		for (int y = 1; y <= N; ++y){
			for (int x = 1; x <= M; ++x)
				cout << setfill('.') << setw(3) << A[y][x] << ' ';
			cout << '\n';
		}
		cout << '\n';
		*/
	}
	int ans = 0, best = 0;
	for (int x = 1; x <= M; ++x)
		for (int y = 1; y <= N; ++y){
			A[y][x] += A[y-1][x];
			if (A[y][x] > best){
				best = A[y][x];
				ans = 1;
			}
			else if (A[y][x] == best)
				++ans;
		}
	/*
	for (int y = 1; y <= N; ++y){
		for (int x = 1; x <= M; ++x)
			cout << setfill('.') << setw(2) << A[y][x] << ' ';
		cout << '\n';
	}
	*/
	cout << best << '\n' << ans << '\n';
return 0;}

