#include <bits/stdc++.h>
using namespace std;

int N;
long long dp[100];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  dp[0] = dp[1] = 1;
  for (int i = 2; i < 100; ++i)
    dp[i] = i * dp[i-1];
  /*
  for (int i = 0; i < 50; ++i)
    cout << i << ' ' << dp[i] << '\n';
    */
  while (cin >> N) {
    if (8 <= N && N <= 13)
      cout << dp[N] << '\n';
    else if ((0 <= N && N <= 7) || (N < 0 && (-N) % 2 == 0))
      cout << "Underflow!\n";
    else if (N > 13 || (N < 0 && (-N) % 2 == 1))
      cout << "Overflow!\n";
  }
return 0;}

