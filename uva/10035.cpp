#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  long long A, B;
  while (true) {
    cin >> A >> B;
    if (A == 0 && B == 0)
      break;
    int ans = 0, carry = 0;
    while (true) {
      int a = A % 10, b = B % 10, c = a+b+carry;
      //cout << a << ' ' << b << ' ' << c << '\n';
      if (c >= 10) {
        ++ans;
        carry = c / 10;
      }
      else 
        carry = 0;
      A /= 10; B /= 10;
      if (A == 0 && B == 0)
        break;
    }
    if (ans == 0)
      cout << "No carry operation.\n";
    else if (ans == 1)
      cout << "1 carry operation.\n";
    else
      cout << ans << " carry operations.\n";
  }
return 0;}

