#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  while (cin >> n) {
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
      ans *= i;
      while (ans % 10 == 0)
        ans /= 10;
      ans %= 100000;
      //cout << i << ' ' << ans << '\n';
    }
    cout << setw(5) << n << " -> " << ans%10 << '\n';
  }
return 0;}

