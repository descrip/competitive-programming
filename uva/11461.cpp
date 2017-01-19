#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  double a, b;
  while (cin >> a >> b) {
    if (a == 0 && b == 0)
      break;
    cout << (int)(floor(sqrt(b)) - ceil(sqrt(a))+1) << '\n';
  }
return 0;}

