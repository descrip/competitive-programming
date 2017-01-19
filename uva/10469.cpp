#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  unsigned int N, M;
  while (cin >> N >> M) {
    int pos = 0;
    unsigned int ans = 0;
    while ((1<<pos) <= max(N, M)) {
      bool a = N & (1<<pos),
           b = M & (1<<pos);
      if (a != b)
        ans |= (1<<pos);
      ++pos;
    }
    cout << ans << '\n';
  }
return 0;}

