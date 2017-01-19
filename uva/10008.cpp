#include <bits/stdc++.h>
using namespace std;

int N;
map<char, int> M;
vector<pair<int, char>> V;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  string S;
  while (cin >> S) {
    for (char c : S)
      if ('a' <= c && c <= 'z')
        ++M['A' + (c-'a')];
      else if ('A' <= c && c <= 'Z')
        ++M[c];
  }
  for (char c = 'A'; c <= 'Z'; ++c)
    V.push_back({-M[c], c});
  sort(V.begin(), V.end());
  for (auto p : V)
    if (p.first != 0)
      cout << p.second << ' ' << -p.first << '\n';
return 0;}

