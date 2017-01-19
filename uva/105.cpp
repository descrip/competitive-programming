#include <bits/stdc++.h>
using namespace std;

int L, R, H;
multiset<int> curr;
vector<pair<int, int>> evt;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> L >> H >> R) {
    assert(H != 0);
    evt.push_back({L, H});
    evt.push_back({R, -H});
  }
  sort(evt.begin(), evt.end());
  curr.insert(0);
  int last = 0;
  for (int i = 0; i < evt.size(); ++i) {
    if (evt[i].second > 0)
      curr.insert(evt[i].second);
    else
      curr.erase(curr.find(-evt[i].second));
    if ((i == evt.size()-1 || evt[i+1].first != evt[i].first) && *curr.rbegin() != last) {
      cout << evt[i].first << ' ' << *curr.rbegin() << " \n"[i == evt.size()-1];
      last = *curr.rbegin();
    }
  }
return 0;}

