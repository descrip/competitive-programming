#include <bits/stdc++.h>
using namespace std;

int Q, M, K, F[2001], S[2001], dp[150001], tot = 0;

//I hate off-by-one errors

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> Q >> M >> K;
  for (int i = 0; i < M; ++i) {
    cin >> F[i];
    tot += F[i];
  }
  for (int i = 0; i < K; ++i)
    cin >> S[i];

  fill_n(dp, 150001, 0);
  for (int i = 0; i < M; ++i)
    for (int j = Q; j >= F[i]; --j)
      dp[j] = max(dp[j], dp[j-F[i]] + F[i]);
  int ans = dp[Q];

  int q = Q;
  while (q >= 0 && dp[q] == dp[Q])
    --q;
  ++q;

  S[K] = tot-q;
  ++K;
  sort(S, S+K, greater<int>());

  q = Q-q;
  for (int i = 0; i < K; ++i) {
    ans += max(min(q-1, S[i]-1), 0);
    q -= S[i];
    if (q <= 0)
      break;
  }

  cout << ans << '\n';
return 0;}

