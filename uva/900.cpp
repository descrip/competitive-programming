#include <bits/stdc++.h>
using namespace std;

int dp[51];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= 50; ++i)
    dp[i] += dp[i-1] + dp[i-2];
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    cout << dp[n] << '\n';
  }
return 0;}

