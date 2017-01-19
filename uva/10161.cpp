#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    double a = (1+sqrt(4.0*n-3))/2;
    long long b = a, c = 1 + (b-1)*b;
    //cout << a << ' ' << b << ' ' << c << '\n';
    if (a == b)
      cout << b << ' ' << b << '\n';
    else if (b % 2 == 0) {
      int y1 = b-(n-c), y2 = n-(c+b-1);
      if (y1 >= 1)
        cout << b << ' ' << y1 << '\n';
      else
        cout << b+1 << ' ' << y2 << '\n';
    }
    else {
      int x1 = b-(n-c), x2 = n-(c+b-1);
      if (x1 >= 1)
        cout << x1 << ' ' << b << '\n';
      else
        cout << x2 << ' ' << b+1 << '\n';
    }
  }
return 0;}

