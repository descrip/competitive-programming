#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<int> A(N), B, C;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	C = A;
	sort(C.begin(), C.end());
	for (int i = 1; i <= 2*N; ++i)
		if (*lower_bound(C.begin(), C.end(), i) != i)
			B.push_back(i);
	int pos = 0, ans = 0;
	sort(A.begin(), A.begin()+N/2);
	sort(A.begin()+N/2, A.end(), greater<int>());
	reverse(B.begin(), B.end());
	sort(B.begin(), B.begin() + N/2);
	for (int i = 0; i < N/2; ++i){
		while (pos < N){
			if (B[pos] > A[i]){
				B[pos] = 0xfffffff;
				++ans;
				++pos;
				break;
			}
			++pos;
		}
	}
	sort(B.begin(), B.end(), greater<int>());
	pos = 0;
	for (int i = N/2; i < N; ++i){
		while (pos < N){
			if (B[pos] < A[i]){
				//cout << pos << ' ' << i << ' ' << '\n';
				++ans;
				++pos;
				break;
			}
			++pos;
		}
	}
	cout << ans << '\n';
return 0;}

