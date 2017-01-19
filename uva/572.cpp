#include <bits/stdc++.h>
using namespace std;

int M, N, cnt;
char A[101][101];

void recur(int x, int y) {
  if (!(0 <= y && y < N) || !(0 <= x && x < M) || A[y][x] != '@')
    return;
  A[y][x] = '*';
  for (int cy = y-1; cy <= y+1; ++cy)
    for (int cx = x-1; cx <= x+1; ++cx)
      recur(cx, cy);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> N >> M) {
    if (M == 0)
      break;
    cnt = 0;
    for (int y = 0; y < N; ++y)
      for (int x = 0; x < M; ++x)
        cin >> A[y][x];
    for (int y = 0; y < N; ++y)
      for (int x = 0; x < M; ++x)
        if (A[y][x] == '@') {
          recur(x, y);
          ++cnt;
        }
    cout << cnt << '\n';
  }
return 0;}

