#include <bits/stdc++.h>
using namespace std;

const string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ10-",
             B = "2223334445556667777888999910-";

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string S;
  while (cin >> S) {
   for (int i = 0; i < S.size(); ++i)
     S[i] = B[A.find(S[i])];
   cout << S << '\n';
  }
return 0;}

