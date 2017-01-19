#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  for (int t = 0; t < T; ++t) {
    int N; cin >> N;
    N *= 567;
    N /= 9;
    N += 7492;
    N *= 235;
    N /= 47;
    N -= 498;
    cout << abs((N/10))%10 << '\n';
  }
return 0;}

