#include <bits/stdc++.h>
using namespace std;

int C, S, P, N, Ci[25], Si[25], Pi[25];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> C >> S >> P >> N;
  for (int i = 0; i < N; ++i)
    cin >> Ci[i] >> Si[i] >> Pi[i];
  double ans = 0.0;
  for (int i = 0; i < (1<<N); ++i) {
    double c = 0, s = 0, p = 0;
    if (__builtin_popcount(i) > 5)
      continue;
    for (int j = 0; j < N; ++j)
      if (i & (1<<j)) {
        c += Ci[j];
        s += Si[j];
        p += Pi[j];
      }
    /*
    cout << c << ' ' << s << ' ' << p << '\n';
    cout << c/C << ' ' << s/S << ' ' << p/P << '\n';
    cout << min(min(c/C, s/S), p/P) << '\n';
    */
    ans = max(ans, min(min(c/C, s/S), p/P));
  }
  cout << fixed << setprecision(1) << min(100*ans, 100.0) << '\n';
return 0;}

