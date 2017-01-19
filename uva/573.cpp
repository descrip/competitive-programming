#include <bits/stdc++.h>
using namespace std;

int H, U, D, F;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> H >> U >> D >> F) {
    if (H == 0)
      break;
    H *= 100; U *= 100; D *= 100;
    int r = U * F / 100, d = 0, cnt = 0;
    while (true) {
      //cout << d << '\n';
      ++cnt;
      d += U;
      if (d > H) {
        cout << "success on day " << cnt << '\n';
        break;
      }
      d -= D;
      if (d < 0) {
        cout << "failure on day " << cnt << '\n';
        break;
      }
      U = max(0, U-r);
    }
  }
return 0;}

