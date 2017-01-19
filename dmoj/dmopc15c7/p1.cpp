#include <bits/stdc++.h>
using namespace std;

int N, C[5], I[11], P[11], S[11], T[11];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < 4; ++i)
    cin >> C[i];
  int Z = 0;
  for (int i = 0; i < N; ++i) {
    cin >> I[i] >> P[i] >> S[i] >> T[i];
    Z = max(Z, S[i]);
  }
  for (int i = 0; i < N; ++i) {
    //cout << C[I[i]-1] * T[i] << '\n';
    if (P[i] == 10)
      cout << "0\n";
    else if (3*60 - Z < C[I[i]-1] * T[i])
      cout << "The kemonomimi are too cute!\n";
    else
      cout << 10-P[i] << '\n';
  }
return 0;}

