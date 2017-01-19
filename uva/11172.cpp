#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  for (int tc = 0; tc < t; ++tc) {
    int a, b; cin >> a >> b;
    if (a > b)
      cout << ">\n";
    else if (a < b)
      cout << "<\n";
    else
      cout << "=\n";
  }
return 0;}

