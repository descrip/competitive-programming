#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  static long long dp[1501];
  dp[0] = 1;
  int a = 0, b = 0, c = 0;
  for (int i = 1; i <= 1500; ++i) {
    dp[i] = min(min(dp[a] * 2, dp[b] * 3), dp[c] * 5);
    if (dp[a] * 2 == dp[i])
      ++a;
    if (dp[b] * 3 == dp[i])
      ++b;
    if (dp[c] * 5 == dp[i])
      ++c;
  }
  cout << "The 1500'th ugly number is " << dp[1499] << ".\n";
return 0;}

