#include <bits/stdc++.h>
using namespace std;

#define NUM_TESTS 10

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  for (int t = 0; t < NUM_TESTS; ++t) {
    int wt, wa, wp, wq; cin >> wt >> wa >> wp >> wq;
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int t, a, p, q; cin >> t >> a >> p >> q;
      if (wt * t + wa * a + wp * p + wq * q >= 50*100)
        ++ans;
    }
    cout << ans << '\n';
  }
return 0;}

