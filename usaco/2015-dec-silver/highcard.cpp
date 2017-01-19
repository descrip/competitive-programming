#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<int> A(N), B;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	sort(A.begin(), A.end());
	for (int i = 1; i <= 2*N; ++i)
		if (*lower_bound(A.begin(), A.end(), i) != i)
			B.push_back(i);
	/*
	for (int i = 0; i < N; ++i)
		cout << A[i] << '\n';
	for (int i = 0; i < N; ++i)
		cout << B[i] << '\n';
		*/
	int ans = 0, pos = 0;
	for (int i = 0; i < N; ++i)
		while (pos < N){
			if (B[pos] > A[i]){
				++ans;
				++pos;
				break;
			}
			++pos;
		}
	cout << ans << '\n';
return 0;}

