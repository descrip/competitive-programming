#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int I;
  while (cin >> I) {
    if (I == 0)
      break;
    cout << "The parity of ";
    int cnt = 0;
    string s = "";
    for (int i = log2(I); i >= 0; --i)
      if (I & (1<<i)) {
        ++cnt;
        cout << '1';
      }
      else
        cout << '0';
    cout << " is " << cnt << " (mod 2).\n";
  }
return 0;}

