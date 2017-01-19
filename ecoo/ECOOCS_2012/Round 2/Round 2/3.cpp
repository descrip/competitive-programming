#include <bits/stdc++.h>
using namespace std;

#define NUM_TESTS 5
int D, L, N, H, K, R;
//TODO" Handle vertical line
double m, a, b, c, x1, x2, d;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int t = 0; t < NUM_TESTS; ++t) {
    cin >> D >> L >> N;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      cin >> H >> K >> R;
      m = tan(D * M_PI / 180.0);
      d = L * cos(D * M_PI / 180.0);
      a = m*m+1; b = -(2*H + 2*m*K); c = H*H + K*K - R*R;
      x1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
      x2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
      int old = ans;
      ans += (min(0.0, d) <= x1 && x1 <= max(0.0, d)) || (min(0.0, d) <= x2 && x2 <= max(0.0, d));
      //cout << a << ' ' << b << ' ' << c << ' ' << x1 << ' ' << x2 << ' ' << ans-old << '\n';
    }
    cout << ans+1 << '\n';
  }
return 0;}

