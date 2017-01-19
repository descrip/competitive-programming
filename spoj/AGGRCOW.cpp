#include <bits/stdc++.h>
using namespace std;

int T, N, C;
vector<int> S;

bool ok(int dist){
	int last = S[0], cnt = 1;
	for (int i = 1; i < N; ++i)
		if (S[i] - last >= dist){
			last = S[i];
			++cnt;
		}
	return cnt >= C;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; ++t){
		cin >> N >> C;
		S.clear();
		for (int i = 0; i < N; ++i){
			int a; cin >> a;
			S.push_back(a);
		}
		sort(S.begin(), S.end());
		int lo = 1, hi = 1e9, mid;
		while (lo + 1 < hi){
			mid = lo + (hi - lo)/2;
			if (ok(mid))
				lo = mid;
			else
				hi = mid;
		}
		cout << lo << '\n';
	}
return 0;}

