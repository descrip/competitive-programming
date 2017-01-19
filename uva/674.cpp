#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  static long long dp[7490];
  dp[0] = 1;
  vector<int> coins = {1, 5, 10, 25, 50};
  for (int j : coins)
    for (int i = 0; i <= 7489; ++i)
      if (i >= j)
        dp[i] += dp[i-j];
  int N;
  while (cin >> N)
    cout << dp[N] << '\n';
return 0;}

