#include <bits/stdc++.h>
using namespace std;

//USA x USSR OTP
//Pakistan x India is second
//Aso, USSR?? I wonder how old this problem is

string S, T;

int sum(int what) {
  if (what < 10)
    return what;
  int ret = 0;
  while (what > 0) {
    ret += what%10;
    what /= 10;
  }
  return sum(ret);
}

int val(string s) {
  int ret = 0;
  for (char c : s)
    if ('a' <= c && c <= 'z')
      ret += c-'a'+1;
    else if ('A' <= c && c <= 'Z')
      ret += c-'A'+1;
  return sum(ret);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (getline(cin, S)) {
    getline(cin, T);
    int a = val(S), b = val(T);
    cout << fixed << setprecision(2) << 100.0 * min(a, b) / max(a, b) << " %\n";
  }
return 0;}

