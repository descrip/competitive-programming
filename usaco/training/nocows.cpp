/*
ID: jezhao11
LANG: C++11
TASK: nocows
*/
#include <bits/stdc++.h>
using namespace std;

int N, K, dp[201][101];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen("nocows.in", "r", stdin);
  freopen("nocows.out", "w", stdout);
  cin >> N >> K;
  for (int k = 1; k <= K; ++k)
    dp[1][k] = 1;
  for (int k = 2; k <= K; ++k)
    for (int n = 3; n <= N; n+=2) {
      for (int m = 1; m < (n+1)/2; m+=2)
        dp[n][k] += (dp[m][k-1] - dp[m][k-2]) * dp[n-m-1][k-1];
      dp[n][k] = (dp[n][k] + dp[n][k-1]) % 9901;
    }
  /*
  for (int k = 1; k <= K; ++k) {
    for (int n = 1; n <= N; ++n)
      cout << dp[n][k] << ' ';
    cout << '\n';
  }
  */
  cout << dp[N][K] - dp[N][K-1] << '\n';
return 0;}

