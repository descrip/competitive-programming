#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N, M, T = 0;
  static char A[105][105];
  while (++T) {
    cin >> N >> M;
    if (N == 0 && M == 0)
      break;
    if (T != 1)
      cout << '\n';
    for (int y = 0; y < N; ++y)
      for (int x = 0; x < M; ++x)
        cin >> A[y][x];
    cout << "Field #" << T << ":\n";
    for (int y = 0; y < N; ++y) {
      for (int x = 0; x < M; ++x) {
        if (A[y][x] == '*') {
          cout << '*';
          continue;
        }
        int cnt = 0;
        for (int cy = y-1; cy <= y+1; ++cy)
          for (int cx = x-1; cx <= x+1; ++cx)
            if (!(cx == x && cy == y) &&
                (0 <= cy && cy < N) && (0 <= cx && cx < M) &&
                A[cy][cx] == '*')
              ++cnt;
        cout << cnt;
      }
      cout << '\n';
    }
  }
return 0;}

