#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N, M;
  while (cin >> N >> M) {
    if (N == 0 && M == 0)
      break;
    list<int> L;
    for (int i = N-M; i >= 1; --i)
      L.push_back(i);
    for (int i = M; i >= 1; --i)
      L.push_back(i);
    long long ans = 1;
    for (int i = N; i >= 1; --i) {
      ans *= i;
      auto it = L.begin();
      while (it != L.end()) {
        if (ans % *it == 0) {
          ans /= *it;
          it = L.erase(it);
        }
        else
          ++it;
      }
      //cout << ans << ' ' << L.size() << '\n';
    }
    cout << N << " things taken " << M << " at a time is " << ans << " exactly.\n";
  }
return 0;}

