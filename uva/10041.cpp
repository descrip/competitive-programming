#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int T, N; cin >> T;
  static int A[501];
  for (int t = 0; t < T; ++t) {
    cin >> N;
    for (int i = 0; i < N; ++i)
      cin >> A[i];
    sort(A, A+N);
    int ans = 0;
    for (int i = 0; i < N; ++i)
      ans += abs(A[i] - A[N/2]);
    cout << ans << '\n';
  }
return 0;}

