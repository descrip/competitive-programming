#include <bits/stdc++.h>
using namespace std;

long long modpow(long long B, long long P, long long M) {
  B %= M;
  long long ret = 1;
  while (P > 0) {
    if (P & 1)
      ret = (ret * B) % M;
    B = (B * B) % M;
    P >>= 1;
  }
  return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  long long B, P, M;
  while (cin >> B >> P >> M)
    cout << modpow(B, P, M) << '\n';
return 0;}

