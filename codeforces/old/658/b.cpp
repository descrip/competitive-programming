#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N, K, Q; cin >> N >> K >> Q;
  static int T[150005];
  for (int i = 1; i <= N; ++i)
    cin >> T[i];
  set<int> S;
  for (int i = 0; i < Q; ++i) {
    int t, x; cin >> t >> x;
    if (t == 1) {
      S.insert(T[x]);
      if (S.size() > K)
        S.erase(S.begin());
    }
    else if (t == 2) {
      cout << (S.count(T[x]) == 1 ? "YES\n" : "NO\n");
    }
  }
return 0;}

