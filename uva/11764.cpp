#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  static int A[51];
  for (int t = 0; t < T; ++t) {
    int N; cin >> N;
    fill_n(A, 51, 0);
    for (int i = 0; i < N; ++i)
      cin >> A[i];
    int a = 0, b = 0;
    for (int i = 0; i < N-1; ++i)
      if (A[i] < A[i+1])
        ++b;
      else if (A[i] > A[i+1])
        ++a;
    cout << "Case " << t+1 << ": " << b << ' ' << a << '\n';
  }
return 0;}

