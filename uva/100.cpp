#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int X, Y;
  while (cin >> X >> Y) {
    int x = X, y = Y;
    if (x > y)
      swap(x, y);
    int ans = 0;
    while (x <= y) {
      long long r = x;
      int cnt = 0;
      while (r != 1) {
        if (r % 2)
          r = 3*r+1;
        else
          r /= 2;
        ++cnt;
      }
      ans = max(ans, cnt);
      ++x;
    }
    cout << X << ' ' << Y << ' ' << ans+1 << '\n';
  }
return 0;}

