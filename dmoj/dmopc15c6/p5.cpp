#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, K; cin >> N >> K;
	vector<int> V (N);
	for (int i = 0; i < N; ++i)
		cin >> V[i];
	int l = 0;
	long long ans = 0;
	multiset<int> S;
	for (int r = 0; r < N; ++r){
		S.insert(V[r]);
		while (l < r && *S.rbegin() - *S.begin() > K)
			S.erase(S.find(V[l++]));
		ans += r-l+1;
	}
	cout << ans << '\n';
return 0;}
