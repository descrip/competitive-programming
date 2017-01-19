#include <bits/stdc++.h>
using namespace std;

char A[101][101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  string S;
  int pos = 0, len = 0;
  fill_n(A[0], 101*101, ' ');
  while (getline(cin, S)) {
    for (int i = 0; i < S.size(); ++i)
      A[pos][i] = S[i];
    len = max(len, (int)S.size());
    ++pos;
  }
  for (int x = 0; x < len; ++x) {
    for (int y = pos-1; y >= 0; --y)
      cout << A[y][x];
    cout << '\n';
  }
return 0;}

