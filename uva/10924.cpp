#include <bits/stdc++.h>
using namespace std;

bool isPrime[1041];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill_n(isPrime, 1041, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i*i <= 1040; ++i)
    if (isPrime[i])
      for (int j = 2; i*j <= 1040; ++j)
        isPrime[i*j] = false;
  string S;
  while (cin >> S) {
    int num = 0;
    for (char c : S)
      if ('a' <= c && c <= 'z')
        num += (c-'a')+1;
      else
        num += (c-'A')+27;
    cout << "It is ";
    if (!isPrime[num] && num != 1)
      //Why the hell is one considered prime? I thought we cleared that up 100 years ago.
      cout << "not ";
    cout << "a prime word.\n";
  }
return 0;}

