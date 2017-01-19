#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
  //WHY DIDN'T YOU SAY THERE WERE SPACES
  //YOU SPECIFICALLY SAID "STRING CONSISTING OF () and []"
  //WHY ARE YOU DOING THIS
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N; cin.ignore();
  vector<char> A;
  for (int n = 0; n < N; ++n) {
    string S; getline(cin, S);
    A.clear();
    bool ok = true;
    for (char c : S)
      if (c == ' ')
        continue;
      else if (c == '(' || c == '[')
        A.push_back(c);
      else {
        if (A.empty()) {
          ok = false;
          break;
        }
        else if (c == ')' && A.back() == '(')
          A.pop_back();
        else if (c == ']' && A.back() == '[')
          A.pop_back();
        else {
          ok = false;
          break;
        }
      }
    cout << (ok && A.empty() ? "Yes" : "No") << '\n';
  }
return 0;}

