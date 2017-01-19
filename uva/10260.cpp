#include <bits/stdc++.h>
using namespace std;

// Originally, my "bad" character was \0
// But then I got like 4 WA
// But I learned that strings are created by looking at each character
// up to a \0

string s = "BFPVCGJKQSXZDTLMNRAEIOUHWY",
       t = "111122222222334556--------";

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string x;
  while (cin >> x) {
    char last = 'r';
    for (char c : x) {
      char y = t[s.find(c)];
      if (y != last && y != '-')
        cout << y;
      last = y;
    }
    cout << '\n';
  }
return 0;}

