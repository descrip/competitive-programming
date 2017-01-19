#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int cnt = 0;
  long long x = 1;
  while (cnt < 10) {
    ++x;
    long long r = 2*x*x;
    if (floor(sqrt(r)) * ceil(sqrt(r)) == r && sqrt(r) != floor(sqrt(r))) {
      cout << setw(10) << x << setw(10) << (int)floor(sqrt(r)) << '\n';
      ++cnt;
    }
  }
return 0;}

