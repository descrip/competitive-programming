#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int N; string S;
  while (cin >> N) {
    if (N == 0)
      break;
    cin >> S;
    vector<int> V;
    for (int i = 0; i < N; ++i) {
      getline(cin, S);
      int cnt = 0;
      for (int j = 0; j < S.size(); ++j)
        if (S[j] == ' ')
          ++cnt;
      V.push_back(cnt);
    }
    sort(V.begin(), V.end());
    int ans = 0;
    for (int i = 0; i < V.size(); ++i)
      ans += V[i]-V[0];
    cout << ans << '\n';
  }
return 0;}

