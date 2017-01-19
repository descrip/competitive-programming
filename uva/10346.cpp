#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  long long N, K;
  while (cin >> N >> K) {
    long long ans = 0, B = 0;
    while (N > 0) {
      //cout << B << '\n';
      ans += N;
      B += N;
      N = B / K;
      B %= K;
    }
    cout << ans << '\n';
  }
return 0;}

