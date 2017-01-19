#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    int l, r; cin >> l >> r;
    if (l == r) {
      cout << (l % 2 == 0 ? 0 : r) << '\n';
      continue;
    }
    if (l % 2 == 0) ++l;
    if (r % 2 == 0) --r;
    cout << "Case " << t << ": " << ((r-l)/2+1) * (l+r)/2 << '\n';
  }
return 0;}

