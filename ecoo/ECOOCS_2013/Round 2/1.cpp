#include <bits/stdc++.h>
using namespace std;

#define NUM_TESTS 5
int R, C, ans[21];
bool A[21][21];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int t = 0; t < NUM_TESTS; ++t) {
    string tmp; R = 0;
    fill_n(A[0], 21*21, false);

    while (getline(cin, tmp)) {
      ++R;
      if (tmp[tmp.size()-1] == '\r')
        tmp = tmp.substr(0, tmp.size()-1);
      tmp = tmp.substr(1, tmp.size()-2);
      C = tmp.size();
      if (tmp[0] == '=')
        break;
      else
        for (int i = 0; i < tmp.size(); ++i)
          A[R-1][i] = (tmp[i] == 'O');
    }

    for (int x = 0; x < C; ++x) {
      int cnt = 0;
      for (int y = 0; y < R; ++y)
        cnt += A[y][x];
      ans[x] = cnt;
    }

    int eat = 0xfffffff;
    for (int x = 0; x < C; ++x)
      eat = min(eat, ans[x]);
    for (int x = 0; x < C; ++x)
      ans[x] -= eat;

    for (int y = 0; y < R; ++y) {
      cout << '|';
      for (int x = C-1; x >= 0; --x)
        cout << (R-y <= ans[x] ? 'O' : ' ');
      cout << "|\n";
    }
    cout << '|' << string(C, '=') << "|\n";
  }
return 0;}

