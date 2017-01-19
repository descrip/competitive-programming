#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  long long A, L;
  int T = 0;
  while (++T) {
    scanf("%lld %lld", &A, &L);
    if (A == -1 && L == -1)
      break;
    long long curr = A;
    int cnt = 0;
    while (true) {
      if (curr == 1)
        ++cnt;
      if (curr == 1 || curr > L)
        break;
      if (curr % 2 == 0)
        curr /= 2;
      else
        curr = curr*3 + 1;
      ++cnt;
    }
    printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n", T, A, L, cnt);
  }
return 0;}

