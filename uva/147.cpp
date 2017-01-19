#include <bits/stdc++.h>
using namespace std;

long long dp[30001];
vector<int> coi = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  dp[0] = 1;
  for (int c : coi)
    for (int i = c; i <= 30000; ++i)
      dp[i] += dp[i-c];
  int a, b, r; char dot;
  while (cin >> a >> dot >> b) {
    if (a == 0 && b == 0)
      break;
    r = a*100 + b;
    cout << setw(6) << fixed << setprecision(2) << r/100.0 << setw(17) << dp[r] << '\n';
  }
return 0;}

