#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int N; long long ans;
  while (cin >> N) {
    if (N == 0)
      break;
    ans = 0;
    for (int i = 1; i < N; ++i)
      for (int j = i+1; j <= N; ++j)
        ans += __gcd(i, j);
    cout << ans << '\n';
  }
return 0;}

