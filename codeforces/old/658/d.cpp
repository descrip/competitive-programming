#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200003, MAXK = (1e9)+3;
const long long INF = 1e18;
int N, K, A[MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  for (int i = 0; i <= N; ++i)
    cin >> A[i];
  long long curr = 0; int lsb = 0;
  for (; lsb <= N; ++lsb) {
    curr += A[lsb];
    if (curr & 1)
      break;
    curr >>= 1;
  }
  for (int i = lsb+1; i <= N; ++i) {
    curr += A[i] * (1<<(i-lsb));
    if (!(-INF <= curr && curr <= INF)) {
      cout << "0\n";
      return 0;
    }
  }
  int ans = 0;
  for (int i = lsb; i >= 0; --i) {
    long long tmp = curr - A[i];
    cout << curr << '\n';
    if (-K <= tmp && tmp <= K && !(i == N && tmp == 0)) {
      ++ans;
      cout << i << ' ' << tmp << '\n';
    }
    if (!(-INF <= curr && curr <= INF))
      break;
  }
  cout << ans << '\n';
return 0;}

