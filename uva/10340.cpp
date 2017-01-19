#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  string S, T;
  while (cin >> S >> T) {
    int Spos = 0, Tpos = 0;
    bool ok = true;
    for (; Spos < S.size() && ok; ++Spos) {
      while (T[Tpos] != S[Spos]) {
        ++Tpos;
        if (Tpos == T.size()) {
          ok = false;
          break;
        }
      }
      ++Tpos;
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
return 0;}

