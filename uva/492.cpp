#include <bits/stdc++.h>
using namespace std;

string toPig(string s) {
  if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' ||
      s[0] == 'A' || s[0] == 'E' || s[0] == 'I' || s[0] == 'O' || s[0] == 'U')
    return s + "ay";
  else
    return s.substr(1) + s[0] + "ay";
}

bool isAlpha(char c) {
  return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  while (getline(cin, s)) {
    for (int i = 0; i < s.size(); ++i)
      if (isAlpha(s[i])) {
        int j;
        for (j = i+1; j < s.size(); ++j)
          if (!isAlpha(s[j]))
            break;
        string wow = toPig(s.substr(i, j-i));
        cout << wow;
        i = j-1;
      }
      else
        cout << s[i];
    cout << '\n';
  }
return 0;}

