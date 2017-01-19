#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, K, Q; cin >> N >> K >> Q;
	static long long A[100005];
	static set<int> pos[2005];
	for (int i = 0; i < N; ++i){
		cin >> A[i];
		if (-1000 <= A[i] && A[i] <= 1000)
			pos[A[i]+1000].insert(i);
		if (i > 0)
			A[i] += A[i-1];
	}
	for (int q = 0; q < Q; ++q){
		int a, b, x, y; cin >> a >> b >> x >> y;
		--x; --y;
		bool ok = A[y] - (x == 0 ? 0 : A[x-1]) > K;

		auto it = pos[a+1000].lower_bound(x);
		ok &= (it != pos[a+1000].end()) && (*it <= y);
		//cout << A[y] - (x == 0 ? 0 : A[x-1]) << ' ' << *it << ' ';

		it = pos[b+1000].lower_bound(x);
		ok &= (it != pos[b+1000].end()) && (*it <= y);
		//cout << *it << '\n';

		cout << (ok ? "Yes\n" : "No\n");
	}
return 0;}

