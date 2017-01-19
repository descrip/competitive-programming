#include <bits/stdc++.h>
using namespace std;

int T, N, K, P;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> N >> K >> P;
    cout << "Case " << t << ": " << ((K+P)%N == 0 ? N : (K+P)%N) << '\n';
  }
return 0;}

