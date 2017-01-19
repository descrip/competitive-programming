#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string a = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`1234567890-=[]\\;',./",
         b = "  czaqsdfyghjbvui w etx  r  czaqsdfyghjbvui w etx  r   `1234567890op[klnm,";
  string S;
  getline(cin, S);
  for (int i = 0; i < S.size(); ++i)
    S[i] = b[a.find(S[i])];
  cout << S << '\n';
return 0;}

