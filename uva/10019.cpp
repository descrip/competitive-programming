#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int N, M;
  cin >> N;
  for (int n = 0; n < N; ++n) {
    cin >> M;
    int hex = 0, dec = M, cnt = 1;
    while (M) {
      hex += (M%10) * cnt;
      cnt *= 16;
      M /= 10;
    }
    cout << __builtin_popcount(dec) << ' ' << __builtin_popcount(hex) << '\n';
  }
return 0;}

