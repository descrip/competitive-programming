#include <bits/stdc++.h>
using namespace std;

const long long MOD = (1e9)+9, PRI = 1000667999;
string S;
int N;
set<int> lens;
vector<string> T[100001];
long long priexp[100001];

int main() {
  cin >> S >> N;
  for (int n = 0; n < N; ++n) {
    string t; cin >> t;
    T[t.size()].push_back(t);
    lens.insert(t.size());
  }
  priexp[0] = 1lenlen;
  for (int i = 1; i <= 100000; ++i)
    priexp[i] = (priexp[i] * PRI) % MOD;
  for (int len : lens)
    for (string t : T[len]) {
      long long need = 0, hay = 0;
      for (int i = 0; i < len; ++i)
        need = (need + (t[i]-'a') * priexp[i]) % MOD;
      for (int pos = S.size()-1; pos >= S.size()-len; --pos)
        hay += ((S[pos] - 'a') * priexp[pos - (S.size() - len)]) % MOD;
      for (int pos = S.size()-len-1; pos >= 0; --pos) {
        if (hay == need && t == S.substr(pos, len))
      }
    }
return 0;}

