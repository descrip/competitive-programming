#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  vector<int> V (3);
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < 3; ++i)
      cin >> V[i];
    sort(V.begin(), V.end());
    cout << "Case " << t+1 << ": " << V[1] << '\n';
  }
return 0;}

