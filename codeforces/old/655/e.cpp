#include <bits/stdc++.h>
using namespace std;

const int MOD = (1e9) + 7;
int N, K;
string S, SAVE;

long long ans(string s) {
  static long long dp[2000005];
  static int last[26];
  fill_n(dp, 2000005, 0LL);
  fill_n(last, 26, -1);
  dp[0] = 1;
  for (int i = 1; i <= s.size(); ++i) {
    dp[i] = (dp[i-1] * 2LL) % MOD;
    if (last[s[i-1] - 'a'] != -1)
      dp[i] = dp[i] - dp[last[s[i-1] - 'a'] - 1];
    last[s[i-1] - 'a'] = i;
  }
  return dp[s.size()];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  cin >> S;
  int M = S.size();
  SAVE = S;
  /*
  for (int i = 0; i < N; ++i)
    S += (char)('a' + i%K);
  cout << S << '\n';
  */
  static bool has[26];
  for (char c : S)
    has[c - 'a'] = true;
  for (char c = 'a'; c <= 'z'; ++c) 
    if (!has[c - 'a'])
      S += c;
  if (S.size() > M+N) 
    cout << ans(S.substr(0, M+N)) << '\n';
  else {
    for (int i = S.size(); i < M+N; ++i)
      S += (char)('a' + i%K);
    cout << ans(S) << '\n';
  }
return 0;}

