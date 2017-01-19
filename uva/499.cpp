#include <bits/stdc++.h>
using namespace std;

string S;
int A[3000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  //A couple of days later, God realised that emacs was actually an operating system and decided to make vim.
  while (getline(cin, S)) {
    fill_n(A, 3000, 0);
    int best = 0;
    for (char c : S)
      if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
        ++A[c];
        best = max(best, A[c]);
      }
    for (char c = 'A'; c <= 'Z'; ++c)
      if (A[c] == best)
        cout << c;
    for (char c = 'a'; c <= 'z'; ++c)
      if (A[c] == best)
        cout << c;
    cout << ' ' << best << '\n';
  }
return 0;}

