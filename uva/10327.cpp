#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N;
  static int A[1001];
  while (cin >> N) {
    for (int i = 0; i < N; ++i)
      cin >> A[i];
    int ans = 0;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N-1; ++j)
        if (A[j] > A[j+1]) {
          swap(A[j], A[j+1]);
          ++ans;
        }
    cout << "Minimum exchange operations : " << ans << '\n';
  }
return 0;}

