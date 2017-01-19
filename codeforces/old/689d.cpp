#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005, INF = (1e9)+1;
int N, A[18][MAXN], B[18][MAXN], lg2[MAXN];
long long ans = 0;

int qmax(int l, int r) {
  int x = log2(r-l+1);
  return max(A[x][l], A[x][r-(1<<x)+1]);
}

int qmin(int l, int r) {
  int x = log2(r-l+1);
  return min(B[x][l], B[x][r-(1<<x)+1]);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill_n(A[0], 18*MAXN, -INF);
  fill_n(B[0], 18*MAXN, INF);

  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> A[0][i];
  for (int i = 0; i < N; ++i)
    cin >> B[0][i];

  for (int i = 1; (1<<i) <= N; ++i)
    for (int j = 0; j+(1<<i) <= N; ++j)
      A[i][j] = max(A[i-1][j], A[i-1][j+(1<<(i-1))]),
      B[i][j] = min(B[i-1][j], B[i-1][j+(1<<(i-1))]);

  for (int i = 0; i < N; ++i)
    if (qmax(i, i) <= qmin(i, i)) {
      int l = i-1, r = i;
      for (int x = (1<<(int)log2(N-i+1)); x; x>>=1) {
        if (l+x < N && qmax(i, l+x) < qmin(i, l+x)) l += x;
        if (r+x < N && qmax(i, r+x) <= qmin(i, r+x)) r += x;
      }
      //cout << i << ' ' << l << ' ' << r << '\n';
      ans += r-l;
    }
  cout << ans << '\n';
return 0;}

