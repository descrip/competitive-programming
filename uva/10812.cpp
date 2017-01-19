#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  for (int n = 0; n < N; ++n) {
    int A, B; cin >> A >> B;
    int X = (A+B)/2, Y = A-X;
    if ((A+B)%2 != 0 || X < 0 || Y < 0)
      cout << "impossible\n";
    else
      cout << X << ' ' << Y << '\n';
  }
return 0;}

