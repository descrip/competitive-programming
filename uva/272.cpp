#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  bool coin = true;
  while (getline(cin, s)) {
    for (char c : s) {
      if (c == '"') {
        cout << (coin ? "``" : "''");
        coin = !coin;
      }
      else
        cout << c;
    }
    cout << '\n';
  }
return 0;}

