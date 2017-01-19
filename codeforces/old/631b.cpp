#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M, K; cin >> N >> M >> K;
	static int A[2][5005], C[100005];
	for (int i = 1; i <= K; ++i){
		int t, x, y; cin >> t >> x >> y;
		A[t-1][x] = i;
		C[i] = y;
	}
	for (int y = 1; y <= N; ++y){
		for (int x = 1; x <= M; ++x){
			int c = max(A[0][y], A[1][x]);
			cout << C[c] << ' ';
		}
		cout << '\n';
	}
return 0;}

