#include <bits/stdc++.h>
using namespace std;

const int LEN = (1e7)+5;
int A[LEN], B[LEN];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  A[1] = B[1] = 1;
  for (int i = 2; i <= 1e7; ++i) {
    if (B[i-1] == 1 && A[i-1] % 2 == 0) {
      A[i] = A[i-1]+1;
      B[i] = 1;
    }
    else if (A[i-1] == 1 && B[i-1] % 2 == 1) {
      A[i] = 1;
      B[i] = B[i-1]+1;
    }
    else if ((A[i-1] + B[i-1]) % 2 == 0) {
      A[i] = A[i-1]-1;
      B[i] = B[i-1]+1;
    }
    else if ((A[i-1] + B[i-1]) % 2 == 1) {
      A[i] = A[i-1]+1;
      B[i] = B[i-1]-1;
    }
  }
  int N;
  while (cin >> N)
    cout << "TERM " << N << " IS " << A[N] << '/' << B[N] << '\n';
return 0;}

