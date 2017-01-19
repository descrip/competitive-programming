#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  unsigned int N;
  while (cin >> N) {
    if (N == 0)
      break;
    unsigned int n = sqrt(N);
    cout << (n*n == N ? "yes" : "no") << '\n';
  }
return 0;}

