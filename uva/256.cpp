#include <bits/stdc++.h>
using namespace std;

void calc(int dig) {
  int hi = 9;
  for (int i = 2; i <= dig; ++i)
    hi = hi*10 + 9;
  for (int i = 0; i*i <= hi; ++i) {
    string s = to_string(i*i);
    s = string(dig-s.size(), '0') + s;
    if (stoi(s.substr(0, dig/2)) + stoi(s.substr(dig/2)) == i)
      cout << s << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int x;
  while (cin >> x)
    calc(x);
return 0;}

