#include <bits/stdc++.h>
using namespace std;

const int MAXN = (2e5)+5, MOD = (1e9)+7;
vector<pair<int, bool>> E;
int N, K, last, curr = 0;
long long ans = 0, F[MAXN], IF[MAXN];

long long modpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % MOD;
    a = (a*a) % MOD;
    b /= 2;
  }
  return ans;
}

long long ncr(int n, int r) {
  if (n < r) return 0;
  else return ((F[n] * IF[r]) % MOD * IF[n-r]) % MOD;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;

  F[0] = IF[0] = 1;
  for (int i = 1; i < MAXN; ++i)
    F[i] = (F[i-1] * i) % MOD,
    IF[i] = modpow(F[i], MOD-2);

  for (int i = 0; i < N; ++i) {
    int a, b; cin >> a >> b;
    E.push_back({a, 0});
    E.push_back({b+1, 1});
  }

  sort(E.begin(), E.end(), greater<pair<int, bool>>());
  bool tick = true;
  while (!E.empty()) {
    int x = E.back().first;
    if (!tick)
      ans = (ans + ncr(curr, K) * (x - last)) % MOD;
    tick = false; last = x;
    //cout << x << ' ' << curr << ' ' << ans << '\n';
    while (!E.empty() && E.back().first == x) {
      curr += (!E.back().second ? 1 : -1);
      E.pop_back();
    }
  }
  cout << (ans + ncr(curr, K)) % MOD << '\n';
return 0;}

