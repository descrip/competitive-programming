#include <bits/stdc++.h>
using namespace std;

//why is one considered prime???
//this is like the second problem
//i know uva is old but it can't be 19th century old

bool isp[1001];
vector<int> pri;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill_n(isp, 1001, true);
  isp[0] = isp[1] = false;
  for (int i = 2; i*i <= 1000; ++i)
    if (isp[i])
      for (int j = 2; i*j <= 1000; ++j)
        isp[i*j] = false;
  pri = {1};
  for (int i = 2; i <= 1000; ++i)
    if (isp[i])
      pri.push_back(i);
  int n, c;
  while (cin >> n >> c) {
    int hi = upper_bound(pri.begin(), pri.end(), n) - pri.begin() - 1;
    /*
    for (int i = 0; i <= hi; ++i)
      cout << pri[i] << " \n"[i==hi];
      */
    cout << n << ' ' << c << ':';
    c -= 1;
    if ((hi+1) % 2 == 0) {
      for (int i = max(0, hi/2-c); i <= min(hi, max(0, hi/2-c)+c*2+1); ++i)
        cout << ' ' << pri[i];
    }
    else {
      for (int i = max(0, hi/2-c); i <= min(hi, max(0, hi/2-c)+c*2); ++i)
        cout << ' ' << pri[i];
    }
    cout << "\n\n";
  }
return 0;}

