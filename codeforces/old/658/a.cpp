#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N, C; cin >> N >> C;
  static int A[55], B[55];
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  for (int i = 0; i < N; ++i)
    cin >> B[i];
  int L = 0, R = 0, T = 0;
  for (int i = 0; i < N; ++i) {
    T += B[i];
    L += max(0, A[i] - T*C);
  }
  T = 0;
  for (int i = N-1; i >= 0; --i) {
    T += B[i];
    R += max(0, A[i] - T*C);
  }
  if (L > R)
    cout << "Limak\n";
  else if (L == R)
    cout << "Tie\n";
  else
    cout << "Radewoosh\n";
return 0;}

