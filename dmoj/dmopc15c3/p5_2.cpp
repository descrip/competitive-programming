#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	vector<long long> A (N+M);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < M; ++i){
		cin >> A[N+i];
		A[N+i] *= -1;
	}
	map<long long, long long> poss;
	int K = (N + M) / 2, L = N + M - K;
	for (int i = 0; i < (1 << K); ++i){
		long long curr = 0;
		for (int j = 0; j < K; ++j)
			if ((i & (1 << j)) != 0)
				curr += A[j];
		poss[curr] += 1;
	}
	long long ans = 0;
	for (int i = 0; i < (1 << L); ++i){
		long long curr = 0;
		for (int j = 0; j < L; ++j)
			if ((i & (1 << j)) != 0)
				curr += A[K + j];
		ans += poss[-curr];
	}
	cout << ans-1 << '\n';
return 0;}

