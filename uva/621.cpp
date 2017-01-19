#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    if (s == "1" || s == "4" || s == "78")
      cout << "+\n";
    else if (s[s.size()-2] == '3' && s[s.size()-1] == '5')
      cout << "-\n";
    else if (s[0] == '9' && s[s.size()-1] == '4')
      cout << "*\n";
    else
      cout << "?\n";
  }
return 0;}

