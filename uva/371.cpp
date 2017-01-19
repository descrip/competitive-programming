#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int X, Y;
  while (cin >> X >> Y) {
    if (X == 0 && Y == 0)
      break;
    int x = X, y = Y;
    if (x > y)
      swap(x, y);
    int ans = 0, best;
    while (x <= y) {
      long long r = x;
      int cnt = 0;
      if (r == 1) {
        r = 3*r+1;
        ++cnt;
      }
      while (r != 1) {
        if (r % 2)
          r = 3*r+1;
        else
          r /= 2;
        ++cnt;
      }
      if (cnt > ans) {
        ans = cnt;
        best = x;
      }
      ++x;
    }
    cout << "Between " << min(X, Y) << " and " << max(X, Y) << ", " << best << " generates the longest sequence of " << ans << " values.\n";
  }
return 0;}


