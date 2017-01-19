#include <bits/stdc++.h>
using namespace std;

int dp[201][3][3];

int recur(int n, int k, int r) {
  //cout << n << ' ' << k << ' ' << r << '\n';
  if (dp[n][k][r] != -1)
    return dp[n][k][r];
  if (n < r-k)
    return (dp[n][k][r] = -0xfffffff);
  if (n+k < 3)
    return (dp[n][k][r] = 0);
  int ret = 0;
  for (int i = 0; i <= k; ++i) {
    if (n+i < 3)
      continue;
    ret = max(ret, recur((n+i)/3 + (n+i)%3, k-i, r) + (n+i)/3);
  }
  //cout << n << ' ' << k << ' ' << r << ' ' << ret << '\n';
  return (dp[n][k][r] = ret);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill_n(dp[0][0], 201*3*3, -1);
  int n; 
  while (cin >> n) {
    int ans = 0;
    for (int i = 0; i <= 2; ++i)
      ans = max(ans, recur(n, i, i));
    cout << ans+n << '\n';
  }
return 0;}

