#include <bits/stdc++.h>
using namespace std;

int Z, I, M, L, T = 0;
set<pair<int, int>> hist;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> Z >> I >> M >> L) {
    ++T;
    if (Z == 0 && I == 0 && M == 0 && L == 0)
      break;
    hist.clear();
    while (true) {
      auto it = hist.lower_bound(make_pair(L, -1));
      if (it->first == L) {
        cout << "Case " << T << ": " << hist.size()-(it->second) << '\n';
        break;
      }
      hist.insert({L, hist.size()});
      L = (Z*L+I) % M;
    }
  }
return 0;}

