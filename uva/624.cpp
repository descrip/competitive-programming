#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N, M;
  vector<int> V;
  while (cin >> N >> M) {
    V.assign(M, 0);
    for (int i = 0; i < M; ++i)
      cin >> V[i];
    int ans = 0, best = 0;
    for (int i = 0; i < (1<<M); ++i) {
      int len = 0;
      for (int j = 0; j < M; ++j)
        if (i & (1<<j))
          len += V[j];
      if (len <= N && len > best)
        best = len, ans = i;
    }
    for (int j = 0; j < M; ++j)
      if (ans & (1<<j))
        cout << V[j] << ' ';
    cout << "sum:" << best << '\n';
  }
return 0;}

