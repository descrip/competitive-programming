#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  static int H[101];
  for (int t = 0; t < T; ++t) {
    int N, P; cin >> N >> P;
    for (int i = 0; i < P; ++i)
      cin >> H[i];
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
      if (i % 7 != 6 && i % 7 != 0)
          for (int j = 0; j < P; ++j) {
            if (i % H[j] == 0) {
              ++cnt;
              break;
            }
          }
    cout << cnt << '\n';
  }
return 0;}

