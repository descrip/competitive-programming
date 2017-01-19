#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> V;
  for (int t = 0; t < N; ++t) {
    int L; cin >> L;
    V.assign(L, 0);
    for (int i = 0; i < L; ++i)
      cin >> V[i];
    int ans = 0;
    for (int j = 0; j < L; ++j) {
      for (int i = 0; i < L-1; ++i)
        if (V[i] > V[i+1]) {
          swap(V[i], V[i+1]);
          ++ans;
        }
    }
    cout << "Optimal train swapping takes " << ans << " swaps.\n";
  }
return 0;}

