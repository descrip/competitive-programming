#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, t = 0;
  while (++t) {
    cin >> n;
    if (n < 0)
      break;
    cout << "Case " << t << ": " << (int)ceil(log2(n)) << '\n';
  }
return 0;}

