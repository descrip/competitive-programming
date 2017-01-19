#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	static int A[30];
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	sort(A, A+N, greater<int>());
	int most = A[0]; long long ans = 0;
	for (int i = 0; i < N; ++i){
		ans += min(A[i], most);
		most = max(min(A[i], most)-1, 0);
	}
	cout << ans << '\n';
return 0;}

