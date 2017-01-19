#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int A[3][3];
  while (cin >> A[0][0]) {
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        if (!(i == 0 && j == 0))
          cin >> A[i][j];
    vector<int> v = {'B', 'C', 'G'};
    vector<int> ans = {'E', 'E', 'E'};
    int best = 0x7fffffff;
    map<char, int> M;
    M['B'] = 0;
    M['G'] = 1;
    M['C'] = 2;
    do {
      int cnt = 0;
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
          if (j != M[v[i]])
            cnt += A[i][j];
      /*
      if (v[0] == 'C' && v[1] == 'B' && v[2] == 'G')
        cout << cnt << '\n';
        */
      if (cnt < best) {
        ans = v;
        best = cnt;
      }
    } while (next_permutation(v.begin(), v.end()));
    for (char c : ans)
      cout << c;
    cout << ' ' << best << '\n';
  }
return 0;}

