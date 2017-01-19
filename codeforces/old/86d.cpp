#include <bits/stdc++.h>
using namespace std;

int N, T, A[200005], C[1000005];
long long ans = 0;

bool comp(pair<int, int

void add(int pos){
	ans -= (long long) A[pos] * C[A[pos]] * C[A[pos]];
	++C[A[pos]];
	ans += (long long) A[pos] * C[A[pos]] * C[A[pos]];
}

void rm(int pos){
	ans -= (long long) A[pos] * C[A[pos]] * C[A[pos]];
	--C[A[pos]];
	ans += (long long) A[pos] * C[A[pos]] * C[A[pos]];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> T;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	int cL = 0, cR = 0;
	for (int t = 0; t < T; ++t){
		int L, R; cin >> L >> R;
		while (cL < L){
			rm(cL);
			++cL;
		}
		while (cL > L){
			add(cL);
			--cL;
		}
		while (cR < R){
			add(cR);
			++cR;
		}
		while (cR > R){
			rm(cR);
			--cR;
		}
		cout << ans << '\n';
	}
return 0;}

