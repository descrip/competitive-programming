#include <bits/stdc++.h>
using namespace std;

long long dp[30001];
vector<int> C = {1, 5, 10, 25, 50};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  dp[0] = 1;
  for (int c : C)
    for (int i = c; i <= 30000; ++i)
      dp[i] += dp[i-c];
  int N;
  while (cin >> N) {
    if (dp[N] == 1)
      cout << "There is only 1 way to produce " << N << " cents change.\n";
    else
      cout << "There are " << dp[N] << " ways to produce " << N << " cents change.\n";
  }
return 0;}

