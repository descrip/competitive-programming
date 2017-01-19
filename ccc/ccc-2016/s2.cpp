#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Q; cin >> Q;
	int N; cin >> N;
	vector<int> D (N), W (N);
	for (int i = 0; i < N; ++i)
		cin >> D[i];
	for (int i = 0; i < N; ++i)
		cin >> W[i];
	if (Q == 1){
		sort(D.begin(), D.end());
		sort(W.begin(), W.end());
	}
	else if (Q == 2){
		sort(D.begin(), D.end());
		sort(W.begin(), W.end());
		reverse(W.begin(), W.end());
	}
	int ans = 0;
	for (int i = 0; i < N; ++i)
		ans += max(D[i], W[i]);
	cout << ans << '\n';
return 0;}

