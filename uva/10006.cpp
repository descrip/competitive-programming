#include <bits/stdc++.h>
using namespace std;

bool isp[65000];

long long modpow(long long a, long long b, long long m) {
  a %= m;
  long long ret = 1;
  while (b > 0) {
    if (b & 1)
      ret = (ret * a) % m;
    a = (a*a) % m;
    b >>= 1;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill_n(isp, 65000, true);
  isp[0] = isp[1] = false;
  for (int i = 2; i*i < 65000; ++i)
    if (isp[i])
      for (int j = 2; i*j < 65000; ++j)
        isp[i*j] = false;
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    bool ok = true;
    if (isp[n]) {
      cout << n << " is normal.\n";
      continue;
    }
    for (int a = 2; a < n; ++a)
      if (modpow(a, n, n) != a) {
        ok = false;
        break;
      }
    if (!isp[n] && ok)
      cout << "The number " << n << " is a Carmichael number.\n";
    else
      cout << n << " is normal.\n";
  }
return 0;}

