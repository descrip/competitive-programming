#include <bits/stdc++.h>
using namespace std;

int f(int n) {
  if (n < 10)
    return n;
  int ret = 0;
  while (n > 0) {
    ret += n%10;
    n /= 10;
  }
  return f(ret);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int N;
  while (cin >> N) {
    if (N == 0)
      break;
    cout << f(N) << '\n';
  }
return 0;}

