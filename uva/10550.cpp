#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    if (a == 0 && b == 0 && c == 0 && d == 0)
      break;
    int ans = 0;
    ans += 720;
    ans += (9*(a-b)%360 + 360) % 360;
    ans += 360;
    ans += (9*(c-b)%360 + 360) % 360;
    ans += (9*(c-d)%360 + 360) % 360;
    cout << ans << '\n';
  }
return 0;}

