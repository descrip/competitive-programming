#include <bits/stdc++.h>
using namespace std;

int N, Q, T = 0;
vector<int> V;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> N >> Q) {
    if (N == 0 && Q == 0)
      break;
    ++T;
    cout << "CASE# " << T << ":\n";
    V.assign(N, 0);
    for (int i = 0; i < N; ++i)
      cin >> V[i];
    sort(V.begin(), V.end());
    for (int q = 0; q < Q; ++q) {
      int x; cin >> x;
      auto it = lower_bound(V.begin(), V.end(), x);
      if (*it != x)
        cout << x << " not found\n";
      else
        cout << x << " found at " << it - V.begin() + 1 << '\n';
    }
  }
return 0;}

