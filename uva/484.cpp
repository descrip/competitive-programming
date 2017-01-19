#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  vector<int> v;
  int x;
  while (cin >> x)
    v.push_back(x);
  multiset<int> r (v.begin(), v.end());
  set<int> t (v.begin(), v.end());
  for (int i : v) {
    if (t.count(i)) {
      cout << i << ' ' << r.count(i) << '\n';
      t.erase(i);
    }
  }
return 0;}

