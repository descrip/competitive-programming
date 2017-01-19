#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  long long n;
  while (cin >> n) {
    long long x = (n+1)*(n+1)/2 - 1;
    cout << 3*x-6 << '\n';
  }
return 0;}

