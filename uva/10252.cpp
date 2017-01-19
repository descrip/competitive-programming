#include <bits/stdc++.h>
using namespace std;

// there are blank lines in the input...

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s, t, ans;
  multiset<char> a, b;
  while (getline(cin, s)) {
    getline(cin, t);
    a.clear(); b.clear(); ans = "";
    for (char c : s)
      a.insert(c);
    for (char c : t)
      b.insert(c);
    for (char c = 'a'; c <= 'z'; ++c)
      ans += string(min(a.count(c), b.count(c)) , c);
    cout << ans << '\n';
  }
return 0;}

