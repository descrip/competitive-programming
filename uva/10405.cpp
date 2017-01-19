#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  //Wow that's like three million in CAD right there
  string S, T;
  static int dp[1001][1001];
  while (getline(cin, S)) {
    getline(cin, T);
    fill_n(dp[0], 1001*1001, 0);
    for (int i = 1; i <= S.size(); ++i)
      for (int j = 1; j <= T.size(); ++j) {
        if (S[i-1] == T[j-1])
          dp[i][j] = max(dp[i][j], dp[i-1][j-1])+1;
        dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-1][j]));
      }
    cout << dp[S.size()][T.size()] << '\n';
  }
return 0;}

