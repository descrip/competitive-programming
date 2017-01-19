#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  long double N, P;
  while (cin >> N >> P)
    cout << fixed << setprecision(0) << pow(P, 1/N) << '\n';
return 0;}

