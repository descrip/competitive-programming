#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int N; scanf("%d", &N);
  for (int n = 0; n < N; ++n) {
    int l, r; scanf("%d %d", &l, &r);
    int best = 0, ans;
    for (int i = l; i <= r; ++i) {
      int cnt = 1, x = i;
      for (int j = 2; j*j <= x; ++j) {
        int curr = 0;
        while (x % j == 0) {
          x /= j;
          ++curr;
        }
        cnt *= curr+1;
      }
      if (x > 1)
        cnt *= 2;
      if (cnt > best) {
        best = cnt;
        ans = i;
      }
    }
    printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, r, ans, best);
  }
return 0;}

