#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; long long K; cin >> N >> M >> K;
	static long long A[200005];
	for (int i = 0; i < M; ++i){
		int a, b; cin >> a >> b;
		--A[b+1];
		++A[a];
	}
	for (int i = 1; i <= N; ++i)
		A[i] += A[i-1];
	for (int i = 1; i <= N; ++i){
		A[i] = M - A[i];
		//cout << A[i] << ' ';
	}
	//cout << '\n';
	for (int i = 1; i <= N; ++i){
		A[i] += A[i-1];
		//cout << A[i] << ' ';
	}
	//cout << '\n';
	long long W = 0xfffffffLL;
	for (int i = 1; i <= N; ++i){
		if (A[i]-K < 0)
			continue;
		int ind = (upper_bound(A, A+i+1, A[i]-K) - A) - 1;
		//cout << i << ' ' << ind << ' ' << A[i]-K << '\n';
		W = min(W, (long long)i-ind);
	}
	cout << (W == 0xfffffffLL ? -1LL : W) << '\n';
return 0;}

