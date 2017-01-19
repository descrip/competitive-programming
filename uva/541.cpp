#include <bits/stdc++.h>
using namespace std;

int N;
bool A[101][101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> N) {
    if (N == 0)
      break;
    for (int y = 0; y < N; ++y)
      for (int x = 0; x < N; ++x)
        cin >> A[y][x];
    int row = -1, col = -1;
    bool ok = true;
    for (int y = 0; y < N; ++y) {
      int sum = 0;
      for (int x = 0; x < N; ++x)
        sum += A[y][x];
      if (sum % 2 == 1) {
        if (row != -1)
          ok = false;
        else
          row = y; 
      }
    }
    for (int x = 0; x < N; ++x) {
      int sum = 0;
      for (int y = 0; y < N; ++y)
        sum += A[y][x];
      if (sum % 2 == 1) {
        if (col != -1)
          ok = false;
        else
          col = x;
      }
    }
    if (!ok)
      cout << "Corrupt\n";
    else if (row == -1 && col == -1)
      cout << "OK\n";
    else if (row != -1 && col != -1)
      cout << "Change bit (" << row+1 << ',' << col+1 << ")\n";
    else
      cout << "Corrupt\n";
  }
return 0;}

