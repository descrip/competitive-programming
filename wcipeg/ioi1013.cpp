#include <iostream>
using namespace std;

int R, C, H, W, A[3001][3001], B[3001][3001];

bool gao(int M) {
  for (int y = 1; y <= R; ++y)
    for (int x = 1; x <= C; ++x) {
      if (M < A[y][x])
        B[y][x] = 1;
      else if (M > A[y][x])
        B[y][x] = -1;
      else
        B[y][x] = 0;
      B[y][x] += B[y-1][x];
    }
  for (int y = 1; y <= R; ++y)
    for (int x = 1; x <= C; ++x)
      B[y][x] += B[y][x-1];

  /*
  cout << M << '\n';
  for (int y = 1; y <= R; ++y) {
    for (int x = 1; x <= C; ++x)
      cout << B[y][x] << ' ';
    cout << '\n';
  }
  */

  for (int y = H; y <= R; ++y)
    for (int x = W; x <= C; ++x) {
      int tmp = B[y][x] - B[y-H][x] - B[y][x-W] + B[y-H][x-W];
      //cout << x << ' ' << y << ' ' << tmp << '\n';
      //cout << x << ' ' << y << ' ' << B[y][x] << ' ' << B[y-H][x] << ' ' << B[y][x-W] << ' ' << B[y-H][x-W] << '\n';
      if (tmp <= 0)
        return true;
    }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> R >> C >> H >> W;
  for (int y = 1; y <= R; ++y)
    for (int x = 1; x <= C; ++x)
      cin >> A[y][x];
  int lo = 1, hi = R*C, mid;
  while (lo < hi) {
    mid = lo + (hi-lo)/2;
    if (gao(mid))
      hi = mid;
    else
      lo = mid+1;
  }
  cout << lo << '\n';
return 0;}

