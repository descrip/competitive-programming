#include <bits/stdc++.h>

using namespace std;

int N, avg, wow, pos, neg;
vector<int> cost;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> N) {
    if (N == 0)
      break;
    avg = wow = pos = neg = 0;
    cost.clear();
    for (int i = 0; i < N; ++i) {
      int a, b; char c;
      cin >> a >> c >> b;
      cost.push_back(a*100 + b);
      avg += a*100 + b;
    }
    avg = round(1.0 * avg / N);
    for (int i = 0; i < N; ++i) {
      int diff = avg - cost[i];
      if (diff == 0)
        continue;
      else if (diff > 0)
        pos += diff;
      else
        neg += -diff;
    }
    //cout << pos << ' ' << neg << '\n';
    cout << '$' << fixed << setprecision(2) << min(pos, neg)/100.0 << '\n';
  }
return 0;}

