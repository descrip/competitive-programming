#include <bits/stdc++.h>
using namespace std;

/*
20
60
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<int> M (N), T (N);
	int t = 0, ans = 0;
	for (int i = 0; i < N; ++i){
		cin >> M[i] >> T[i];
		int a = min(M[i] - t, T[i]);
		ans += T[i] - a;
		t += a;
	}
	cout << ans << '\n';
return 0;}

