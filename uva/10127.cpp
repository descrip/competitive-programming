#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int N;
  while (cin >> N) {
    int cnt = 1, tmp = 1;
    while (tmp % N != 0) {
      ++cnt;
      tmp = (10*tmp + 1) % N;
    }
    cout << cnt << '\n';
  }
return 0;}

