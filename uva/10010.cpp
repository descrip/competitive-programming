#include <bits/stdc++.h>
using namespace std;

//TODO: Separate case output
int T, M, N, Q;
char A[51][51];

char toLower(char what) {
  if ('A' <= what && what <= 'Z')
    return 'a'+(what-'A');
  else return what;
}

pair<int, int> search(string s) {
  for (int y = 0; y < N; ++y)
    for (int x = 0; x < M; ++x)
      if (A[y][x] == s[0]) {

        for (int cy = y+1; cy < N; ++cy)
          if (s[cy-y] != A[cy][x])
            break;
          else if (cy-y == s.size()-1)
            return {x, y};
        for (int cy = y-1; cy >= 0; --cy)
          if (s[y-cy] != A[cy][x])
            break;
          else if (y-cy == s.size()-1)
            return {x, y};
        for (int cx = x+1; cx < M; ++cx)
          if (s[cx-x] != A[y][cx])
            break;
          else if (cx-x == s.size()-1)
            return {x, y};
        for (int cx = x-1; cx >= 0; --cx)
          if (s[x-cx] != A[y][cx])
            break;
          else if (x-cx == s.size()-1)
            return {x, y};
        for (int i = 1; i < s.size(); ++i)
          if (y+i >= N || x+i >= M || A[y+i][x+i] != s[i])
            break;
          else if (i == s.size()-1)
            return {x, y};
        for (int i = 1; i < s.size(); ++i)
          if (y-i < 0 || x-i < 0 || A[y-i][x-i] != s[i])
            break;
          else if (i == s.size()-1)
            return {x, y};
      }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> N >> M;
    for (int y = 0; y < N; ++y)
      for (int x = 0; x < M; ++x) {
        cin >> A[y][x];
        A[y][x] = toLower(A[y][x]);
      }
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
      string s; cin >> s;
      for (int i = 0; i < s.size(); ++i)
        s[i] = toLower(s[i]);
      pair<int, int> ans = search(s);
      cout << ans.second+1 << ' ' << ans.first+1 << '\n';
    }
    if (t != T-1)
      cout << '\n';
  }
return 0;}

