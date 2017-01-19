#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  long long N;
  while (cin >> N) {
    if (N < 0)
      break;
    cout << (1 + N) * N / 2 + 1 << '\n';
  }
return 0;}

