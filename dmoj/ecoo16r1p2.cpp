#include <bits/stdc++.h>
using namespace std;

#define NUM_TESTS 10
int N, S[5005];
bool vis[5][1000005];

void recur(int n, int c) {
  if (n > 1000001 || vis[c][n] || c == 3)
    return;
  vis[c][n] = true;
  for (int i = 0; i < N; ++i) {
    recur(n+S[i], c+1);
    recur(n*S[i], c+1);
  }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  for (int ts = 0; ts < NUM_TESTS; ++ts) {
    cin >> N;
    for (int i = 0; i < N; ++i)
      cin >> S[i];
    fill_n(vis[0], 4*1000005, false);
    for (int i = 0; i < N; ++i)
      recur(S[i], 1);
    for (int i = 0; i < 5; ++i) {
      int t; cin >> t;
      bool ok = false;
      for (int j = 0; j < N; ++j) {
        if (t > S[j])
          ok = vis[2][t - S[j]];
        if (t % S[j] == 0)
          ok = vis[2][t / S[j]];
      }
      cout << (ok ? 'T' : 'F');
    }
    cout << '\n';
  }
  //cout << vis[1][23] << '\n';
return 0;}

