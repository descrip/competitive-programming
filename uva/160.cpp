#include <bits/stdc++.h>
using namespace std;

int N, ans[25];
bool isPrime[101];
vector<int> primes;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  fill_n(isPrime, 101, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i*i <= 100; ++i)
    if (isPrime[i]) {
      for (int j = 2; i*j <= 100; ++j)
        isPrime[i*j] = false;
    }
  for (int i = 0; i < 100; ++i)
    if (isPrime[i])
      primes.push_back(i);
  while (cin >> N) {
    if (N == 0)
      break;
    fill_n(ans, 25, 0);
    int len = 0;
    for (int i = 2; i <= N; ++i) {
      int n = i;
      for (int j = 2; j*j <= n; ++j) {
        int pos = lower_bound(primes.begin(), primes.end(), j) - primes.begin();
        while (n % j == 0) {
          n /= j;
          ++ans[pos];
          len = max(len, pos);
        }
      }
      if (n > 1) {
        int pos = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
        ++ans[pos];
        len = max(len, pos);
      }
    }
    cout << setw(3) << setfill(' ') << N << "! =";
    for (int i = 0; i <= len; ++i) {
      if (i == 15)
        cout << "\n      ";
      cout << setw(3) << ans[i];
    }
    cout << '\n';
  }
return 0;}

