#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  static long long F[5001];
  F[1] = F[2] = 1;
  for (int i = 3; i <= 5000; ++i)
    F[i] = F[i-1] + F[i-2];
  int N;
  while (cin >> N)
    cout << "The Fibonacci number for " << N << " is " << F[N] << '\n';
return 0;}

