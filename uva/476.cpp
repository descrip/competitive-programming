#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pdd;

pair<pdd, pdd> rect[10];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  char c; int rcnt = 0, pcnt = 0;
  while (true) {
    cin >> c;
    if (c == '*')
      break;
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    rect[rcnt++] = {{x1, y1}, {x2, y2}};
  }
  pdd p;
  while (cin >> p.first >> p.second) {
    if (p.first == 9999.9 && p.second == 9999.9)
      break;
    bool ok = false; ++pcnt;
    for (int i = 0; i < rcnt; ++i)
      if (rect[i].first.first < p.first &&
          p.first < rect[i].second.first &&
          rect[i].first.second > p.second &&
          p.second > rect[i].second.second) {
        cout << "Point " << pcnt << " is contained in figure " << i+1 << '\n';
        ok = true;
      }
    if (!ok)
        cout << "Point " << pcnt << " is not contained in any figure\n";
  }
return 0;}

