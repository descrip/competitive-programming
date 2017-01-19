#include <bits/stdc++.h>
using namespace std;

int K, D, Sa, Sb, Pa, Pb;

inline double dist(double a, double b) {
  return min(abs(a-b), K-abs(a-b));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> K >> D >> Sa >> Sb >> Pa >> Pb;
  static bool isPrime[2005];
  fill_n(isPrime, 2005, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i*i < 2005; ++i)
    if (isPrime[i])
      for (int j = 2; i*j < 2005; ++j)
        isPrime[i*j] = false;
  set<pair<int, int>> hist;
  long long X = Pa, Y = Pb;
  for (int zz = 0; zz < (1e9); ++zz) {
    if (X < Y) {
      X += Sa;
      Y = max(X + D, Y + Sb);
    }
    else {
      X += Sa;
      Y = min(X - D, Y + Sb);
    }
    if (isPrime[(X % K + Y%K) % K]) {
      cout << "Alice\n";
      return 0;
    }
    pair<int, int> p = {X % K, Y % K};
    if (hist.count(p))
      break;
    hist.insert(p);
  }
  cout << "Bob\n";
return 0;}

