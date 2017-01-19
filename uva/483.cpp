#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  string S;
  while (getline(cin, S)) {
    stringstream SS (S);
    string T;
    bool first = true;
    while (SS >> T) {
      reverse(T.begin(), T.end());
      cout << (first ? "" : " ") << T;
      first = false;
    }
    cout << '\n';
  }
return 0;}

