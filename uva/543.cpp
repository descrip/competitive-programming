#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  static bool isPrime[1000000];
  fill_n(isPrime, 1000000, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i*i < 1000000; ++i)
    if (isPrime[i])
      for (int j = 2; i*j < 1000000; ++j)
        isPrime[i*j] = false;
  int N;
  while (cin >> N) {
    for (int i = 2; i < N; ++i)
      if (isPrime[i] && isPrime[N-i]) {
        cout << N << " = " << i << " + " << N-i << '\n';
        break;
      }
  }
return 0;}

