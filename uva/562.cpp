#include <bits/stdc++.h>
using namespace std;

int T, N, sum, V[100];
bool dp[25001];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> N;
    sum = 0;
    for (int i = 0; i < N; ++i) {
      cin >> V[i];
      sum += V[i];
    }
    fill_n(dp, 25001, false);
    dp[0] = true;
    for (int i = 0; i < N; ++i)
      for (int j = sum/2; j >= V[i]; --j)
        dp[j] |= dp[j-V[i]];
    for (int i = 0; i <= sum/2; ++i)
      if (dp[sum/2-i]) {
        cout << (sum - (sum/2-i)) - (sum/2-i) << '\n';
        break;
      }
  }
return 0;}

