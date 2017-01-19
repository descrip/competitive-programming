#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  string S;
  while (cin >> S) {
    if (S == "#")
      break;
    bool ok = next_permutation(S.begin(), S.end());
    cout << (!ok ? "No Successor" : S) << '\n';
  }
return 0;}

