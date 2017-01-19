#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  string N;
  while (cin >> N) {
    if (N == "0")
      break;
    int ans = 0;
    for (int i = 0; i < N.size(); ++i) {
      ans += (N[i] - '0') * ((1<<(N.size()-i))-1);
      //cout << i << ' ' << ans << '\n';
    }
    cout << ans << '\n';
  }
return 0;}

