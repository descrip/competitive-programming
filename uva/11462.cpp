#include <bits/stdc++.h>
using namespace std;

int N, A[101];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> N) {
    if (N == 0)
      break;
    int x; bool tick = true;
    for (int i = 0; i < N; ++i) {
      cin >> x;
      ++A[x];
    }
    for (int i = 1; i <= 100; ++i)
      while (A[i] > 0) {
        if (!tick)
          cout << ' ';
        tick = false;
        cout << i;
        --A[i];
      }
    cout << '\n';
  }
return 0;}

