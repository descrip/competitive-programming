#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  long long n;
  while (cin >> n) {
    if (n < 0)
      break;
    string s = "";
    while (n >= 3) {
      s += (char)('0' + n%3);
      n /= 3;
    }
    s += (char)('0' + n);
    reverse(s.begin(), s.end());
    cout << s << '\n';
  }
return 0;}

