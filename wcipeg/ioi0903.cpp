#include <bits/stdc++.h>
using namespace std;

int N, A[2005];

int rev(int x) {
  int ret = 0;
  for (int i = 0; i < 31; ++i) {
    ret = (ret<<1) | (x & 1);
    x >>= 1;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  /*
  for (int i = 0; i < 31; ++i)
    cout << ((N & (1<<i)) >> i);
  cout << '\n';
  cout << rev(N) << '\n';
  for (int i = 0; i < 31; ++i)
    cout << ((rev(N) & (1<<i)) >> i);
  cout << '\n';
  */
  for (int i = 0; i < N; ++i)
    A[i] = rev(i+1);
  sort(A, A+N);
  for (int i = 0; i < N; ++i)
    cout << rev(A[i]) << '\n';
return 0;}

