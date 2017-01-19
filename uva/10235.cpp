#include <bits/stdc++.h>
using namespace std;

//Nottingham or Nanyan Technological?

bool isp[1000000];

int rev(int n) {
  int ans = 0;
  while (n > 0) {
    ans = ans*10 + n%10;
    n /= 10;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill_n(isp, 1000000, true);
  isp[0] = isp[1] = false;
  for (int i = 2; i*i < 1000000; ++i)
    if (isp[i])
      for (int j = 2; i*j < 1000000; ++j)
        isp[i*j] = false;
  int n;
  while (cin >> n) {
    if (!isp[n])
      cout << n << " is not prime.\n";
    else if (isp[n] && isp[rev(n)] && rev(n) != n)
      cout << n << " is emirp.\n";
    else
      cout << n << " is prime.\n";
  }
return 0;}

