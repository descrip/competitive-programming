#include <bits/stdc++.h>
using namespace std;

//):

int L;
string S;
vector<bool> A[10];
char ans[200][200];

void gao(int x, int n) {
  int y = 0;
  if (A[n][0])
    for (int i = 0; i < L; ++i)
      ans[y][x+1+i] = '-';
  ++y;
  for (int i = 0; i < L; ++i) {
    if (A[n][1])
      ans[y][x] = '|';
    if (A[n][2])
      ans[y][x+L+1] = '|';
    ++y;
  }
  if (A[n][3])
    for (int i = 0; i < L; ++i)
      ans[y][x+1+i] = '-';
  ++y;
  for (int i = 0; i < L; ++i) {
    if (A[n][4])
      ans[y][x] = '|';
    if (A[n][5])
      ans[y][x+L+1] = '|';
    ++y;
  }
  if (A[n][6])
    for (int i = 0; i < L; ++i)
      ans[y][x+1+i] = '-';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  A[0] = {1, 1, 1, 0, 1, 1, 1};
  A[1] = {0, 0, 1, 0, 0, 1, 0};
  A[2] = {1, 0, 1, 1, 1, 0, 1};
  A[3] = {1, 0, 1, 1, 0, 1, 1};
  A[4] = {0, 1, 1, 1, 0, 1, 0};
  A[5] = {1, 1, 0, 1, 0, 1, 1};
  A[6] = {1, 1, 0, 1, 1, 1, 1};
  A[7] = {1, 0, 1, 0, 0, 1, 0};
  A[8] = {1, 1, 1, 1, 1, 1, 1};
  A[9] = {1, 1, 1, 1, 0, 1, 1};
  while (cin >> L >> S) {
    if (L == 0 && S == "0")
      break;
    fill_n(ans[0], 100*100, ' ');
    int x = 0;
    for (char c : S) {
      gao(x, c-'0');
      x += L+3;
    }
    for (int i = 0; i < 2*L+3; ++i) {
      for (int j = 0; j < x-1; ++j)
        cout << ans[i][j];
      cout << '\n';
    }
    cout << '\n';
  }
return 0;}

