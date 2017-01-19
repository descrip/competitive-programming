#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  for (int t = 0; t < N; ++t) {
    int F; cin >> F;
    long long ans = 0;
    for (int i = 0; i < F; ++i) {
      long long a, b, c;
      cin >> a >> b >> c;
      ans += a*c;
    }
    cout << ans << '\n';
  }
return 0;}

