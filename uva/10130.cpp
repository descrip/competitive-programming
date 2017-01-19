#include <bits/stdc++.h>
using namespace std;

int T, N, P[1001], W[1001], G, M[1001], dp[31], ans = 0;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> N;
    for (int i = 0; i < N; ++i)
      cin >> P[i] >> W[i];
    cin >> G;
    ans = 0;
    for (int g = 0; g < G; ++g) {
      cin >> M[g];

      fill_n(dp, 31, -0xfffffff);
      dp[0] = 0;

      int curr = 0;
      for (int i = 0; i < N; ++i)
        for (int j = M[g]; j >= W[i]; --j) {
          dp[j] = max(dp[j], dp[j-W[i]] + P[i]);
          curr = max(curr, dp[j]);
        }
      ans += curr;
    }
    cout << ans << '\n';
  }
return 0;}

