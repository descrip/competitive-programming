#include <bits/stdc++.h>
using namespace std;

string S;

bool gao() {
  int wow = 0;
  for (int i = 0; i < S.size(); ++i)
    wow = (wow*10 + (S[i] - '0')) % 11;
  return (wow == 0);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> S) {
    if (S == "0")
      break;
    cout << S << " is ";
    if (!gao())
      cout << "not ";
    cout << "a multiple of 11.\n";
  }
return 0;}

