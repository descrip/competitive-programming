#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, M; cin >> N >> M;
    N -= 2; M -= 2;
    cout << (int)(ceil(N/3.0)) * (int)(ceil(M/3.0)) << '\n';
  }
return 0;}

