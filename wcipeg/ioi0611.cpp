#include <bits/stdc++.h>
using namespace std;

int A, B, cnt[300], see[300], ans = 0;
string W, S;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> A >> B >> W >> S;
  for (char c : W)
    ++see[c];
  for (int i = 0; i < S.size(); ++i) {
    ++cnt[S[i]];
    if (i >= W.size()-1) {
      bool ok = true;
      for (char c = 'a'; c <= 'z'; ++c)
        if (see[c] != cnt[c])
          ok = false;
      for (char c = 'A'; c <= 'Z'; ++c)
        if (see[c] != cnt[c])
          ok = false;
      if (ok)
        ++ans;
      --cnt[S[i-W.size()+1]];
    }
  }
  cout << ans << '\n';
return 0;}

