#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  string S;
  set<int> A;
  for (char c = 'a'; c <= 'z'; ++c)
    A.insert(c);
  for (char c = 'A'; c <= 'Z'; ++c)
    A.insert(c);
  while (getline(cin, S)) {
    int ans = 0;
    for (int i = 0; i < S.size(); ++i)
      if (A.count(S[i]) && !A.count(S[i-1]))
        ++ans;
    cout << ans << '\n';
  }
return 0;}

