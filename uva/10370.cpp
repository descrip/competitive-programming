#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  //Let me become a frosh first ):
  int C; cin >> C;
  vector<int> V;
  for (int c = 0; c < C; ++c) {
    int N; cin >> N;
    V.assign(N, 0);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
      cin >> V[i];
      sum += V[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i)
      if (V[i] * N > sum)
        ++cnt;
    cout << fixed << setprecision(3) << round(100000.0 * cnt / N) / 1000.0 << "%\n";
  }
return 0;}

