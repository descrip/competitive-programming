#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long N, Q; cin >> N >> Q;
	vector<long long> V;
	for (int i = 1; i <= N; ++i)
		V.push_back(i);
	static long long F[20];
	F[0] = F[1] = 1;
	for (int i = 2; i < 20; ++i)
		F[i] = F[i-1] * i;
	for (int i = 0; i < Q; ++i){
		long long x; cin >> x;
		vector<int> W (V.begin(), V.end());
		for (int j = N; j >= 1; --j){
			int t = x / F[j-1];
			x -= F[j-1] * t;
			cout << W[t] << ' ';
			W.erase(W.begin() + t);
		}
		cout << '\n';
	}
return 0;}

