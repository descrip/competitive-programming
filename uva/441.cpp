#include <bits/stdc++.h>
using namespace std;

int K;
vector<int> S;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  bool wow = true;
  while (cin >> K) {
    if (K == 0)
      break;
    if (!wow)
      cout << '\n';
    wow = false;
    S.assign(K, 0);
    for (int i = 0; i < K; ++i)
      cin >> S[i];
    reverse(S.begin(), S.end());
    for (int i = (1<<K)-1; i >= 0; --i)
      if (__builtin_popcount(i) == 6) {
        bool first = true;
        for (int j = K-1; j >= 0; --j)
          if (i & (1<<j)) {
            if (!first)
              cout << ' ';
            first = false;
            cout << S[j];
          }
        cout << '\n';
      }
  }
return 0;}

