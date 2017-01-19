#include <bits/stdc++.h>
using namespace std;

int f91(int N) {
  if (N <= 100)
    return f91(f91(N+11));
  else
    return N-10;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N;
  while (true) {
    cin >> N;
    if (N == 0)
      break;
    cout << "f91(" << N << ") = " << f91(N) << '\n';
  }
return 0;}

