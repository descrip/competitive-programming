#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  double H, M; char trash;
  while (true) {
    cin >> H >> trash >> M;
    if (H == 0 && M == 0)
      break;
    double a = H * 360 / 12 + M * 360 / 12 / 60,
           b = M * 360 / 60,
           c = abs(a-b);
    cout << fixed << setprecision(3) << min(c, 360-c) << '\n';
  }
return 0;}

