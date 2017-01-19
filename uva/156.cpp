#include <bits/stdc++.h>
using namespace std;

//TODO: Check single character is relative ananagram

string S;
vector<string> V;
multiset<string> R;

char toLower(char c) {
  if ('A' <= c && c <= 'Z')
    return 'a'+(c-'A');
  else return c;
}

string prep(string s) {
  for (int i = 0; i < s.size(); ++i)
    s[i] = toLower(s[i]);
  sort(s.begin(), s.end());
  return s;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> S) {
    if (S == "#")
      break;
    V.push_back(S);
    R.insert(prep(S));
  }
  sort(V.begin(), V.end());
  for (string s : V)
    if (s.size() == 1 || R.count(prep(s)) == 1)
      cout << s << '\n';
return 0;}

