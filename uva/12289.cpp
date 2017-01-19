#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    if (s.size() == 5) {
      cout << 3 << '\n';
      continue;
    }
    int cnt = (s[0] == 'o') + (s[1] == 'n') + (s[2] == 'e');
    if (cnt >= 2)
      cout << 1 << '\n';
    else
      cout << 2 << '\n';
  }
return 0;}

