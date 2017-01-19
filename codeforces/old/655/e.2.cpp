#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;
int N, K, M, last['a'+30];
string S;
long long dp[2000005];

long long zmod(const long long &a, const long long &b) {
  return ((a%b) + b) % b;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K >> S;
  M = S.size();
  fill_n(last, 'a'+26, -1);
  for (int i = 0; i < N+M; ++i) {
    dp[i] = zmod((i == 0 ? 1LL : dp[i-1]) * 2LL, MOD);
    //cout << dp[i] << '\n';
    char curr = 'a';
    if (i >= M) {
      for (char c = 'b'; c < 'a'+K; ++c)
        if (last[c] < last[curr])
          curr = c;
    }
    else
      curr = S[i];
    if (last[curr] != -1)
      dp[i] = zmod(dp[i] - (last[curr]-1 < 0 ? 1LL : dp[last[curr] - 1]), MOD);
    //cout << i << ' ' << curr << ' ' << dp[i] << '\n';
    last[curr] = i;
  }
  cout << dp[N+M-1] << '\n';
return 0;}

