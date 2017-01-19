#include <bits/stdc++.h>
using namespace std;

int L, N, dp[53][53];
vector<int> V;

int gao(int l, int r) {
  if (l > r)
    return 0;
  if (dp[l][r] != -1)
    return dp[l][r];
  int ret = 0xfffffff;
  for (int k = l; k <= r; ++k)
    ret = min(ret, gao(l,k-1) + gao(k+1,r));
  return (dp[l][r] = ret + V[r+1]-V[l-1]);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> L) {
    if (L == 0)
      break;
    cin >> N;
    V.assign(N+2, 0);
    for (int i = 1; i <= N; ++i)
      cin >> V[i];
    V[N+1] = L;
    fill_n(dp[0], 53*53, -1);
    cout << "The minimum cutting is " << gao(1, N) << ".\n";
  }
return 0;}

