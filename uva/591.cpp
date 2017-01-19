#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N, T = 0;
  vector<int> V;
  while (++T) {
    cin >> N;
    if (N == 0)
      break;
    V.assign(N, 0);
    int S = 0;
    for (int i = 0; i < N; ++i) {
      cin >> V[i];
      S += V[i];
    }
    int H = S/N, ans = 0;
    for (int i = 0; i < N; ++i)
      ans += max(V[i] - H, 0);
    cout << "Set #" << T <<
      "\nThe minimum number of moves is " << ans << ".\n\n";
  }
return 0;}

