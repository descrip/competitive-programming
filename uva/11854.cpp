#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  static int A[3];
  while (cin >> A[0]) {
    cin >> A[1] >> A[2];
    if (A[0] == 0 && A[1] == 0 && A[2] == 0)
      break;
    sort(A, A+3);
    cout << (A[0]*A[0] + A[1]*A[1] == A[2]*A[2] ? "right" : "wrong") << '\n';
  }
return 0;}

