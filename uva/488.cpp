#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  for (int n = 0; n < N; ++n) {
    int A, F; cin >> A >> F;
    string S;
    for (int i = 1; i <= A; ++i) {
      for (int j = 0; j < i; ++j)
        S += '0' + i;
      S += '\n';
    }
    for (int i = A-1; i >= 1; --i) {
      for (int j = 0; j < i; ++j)
        S += '0' + i;
      S += '\n';
    }
    for (int i = 0; i < F; ++i)
      cout << S << (!(n == N-1 && i == F-1) ? "\n" : "");
  }
return 0;}

