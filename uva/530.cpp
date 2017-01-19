#include <bits/stdc++.h>
using namespace std;

long long n, k, ans;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> n >> k) {
    if (n == 0 && k == 0)
      break;
    if (k > n/2)
      k = n-k;
    ans = 1;
    for (int i = 1, j = n; i <= k; ++i, --j)
      ans = ans*j/i;
    cout << ans << '\n';
  }
return 0;}

