#include <bits/stdc++.h>
using namespace std;

long long rev(long long x) {
  long long ret = 0;
  while (x > 0) {
    ret = ret*10 + x%10;
    x /= 10;
  }
  return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  for (int n = 0; n < N; ++n) {
    long long X, Y; cin >> X;
    Y = rev(X);
    int ans = 0;
    while (X != Y) {
      ++ans;
      X += Y;
      Y = rev(X);
    }
    cout << ans << ' ' << X << '\n';
  }
return 0;}

