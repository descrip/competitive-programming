#include <iostream>
#include <algorithm>
using namespace std;

int T, N, A[21], X;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> N;
    for (int i = 0; i < N; ++i)
      cin >> A[i];
    sort(A, A+N);
    cout << 2*(A[N-1]-A[0]) << '\n';
  }
return 0;}

