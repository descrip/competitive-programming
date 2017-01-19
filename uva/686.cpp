#include <bits/stdc++.h>
using namespace std;

bool isPrime[(1<<15)];
vector<int> primes;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill_n(isPrime, (1<<15), true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i*i < (1<<15); ++i)
    if (isPrime[i])
      for (int j = 2; i*j < (1<<15); ++j)
        isPrime[i*j] = false;
  for (int i = 2; i < (1<<15); ++i)
    if (isPrime[i])
      primes.push_back(i);
  int x;
  while (cin >> x) {
    if (x == 0)
      break;
    int ans = 0;
    for (int i = 0; primes[i] <= x/2; ++i)
      if (isPrime[x - primes[i]])
        ++ans;
    cout << ans << '\n';
  }
return 0;}

