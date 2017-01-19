#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  static long long A[3];
  for (int t = 1; t <= T; ++t) {
    for (int i = 0; i < 3; ++i)
      cin >> A[i];
    sort(A, A+3);
    cout << "Case " << t << ": ";
    if (A[0] + A[1] <= A[2])
      cout << "Invalid\n";
    else if (A[0] == A[1] && A[1] == A[2])
      cout << "Equilateral\n";
    else if (A[0] != A[1] && A[1] != A[2] && A[0] != A[2])
      cout << "Scalene\n";
    else
      cout << "Isosceles\n";
  }
return 0;}

