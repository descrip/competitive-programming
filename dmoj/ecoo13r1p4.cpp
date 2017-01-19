#include <bits/stdc++.h>
using namespace std;

#define NUMTESTS 5
#define INF 1000000000.0
enum Coupon {
  NOTHING,
  FLAT5,
  FLAT10,
  FLAT50,
  PERCENT10,
  PERCENT20,
  TAX,
  BOGO
};

int N, M;
double I[15];
Coupon C[15];

double cost() {
  double ret = 0;
  int pos = 0;
  for (int i = 0; i < M; ++i) {
    if (pos >= N)
      break;
    if (C[i] == FLAT5)
      ret += round(100 * 1.13 * max(I[pos] - 5.0, 0.0)) / 100.0;
    else if (C[i] == FLAT10)
      ret += round(100 * 1.13 * max(I[pos] - 10.0, 0.0)) / 100.0;
    else if (C[i] == FLAT50)
      ret += round(100 * 1.13 * max(I[pos] - 50.0, 0.0)) / 100.0;
    else if (C[i] == PERCENT10)
      ret += round(100 * 1.13 * 0.9 * I[pos]) / 100.0;
    else if (C[i] == PERCENT20)
      ret += round(100 * 1.13 * 0.8 * I[pos]) / 100.0;
    else if (C[i] == TAX)
      ret += I[pos];
    else if (C[i] == BOGO) {
      ret += round(100 * 1.13 * I[pos]) / 100.0;
      ++pos;
    }
    ++pos;
  }
  if (M < N)
    for (int i = pos; i < N; ++i)
      ret += round(100 * 1.13 * I[i]) / 100.0;
  return ret;
}

int main() {
  for (int t = 0; t < NUMTESTS; ++t) {
    fill_n(I, 15, NOTHING);
    fill_n(C, 15, NOTHING);
    cin >> N;
    for (int i = 0; i < N; ++i)
      cin >> I[i];
    cin >> M;
    bool bogod = false;
    for (int i = 0; i < M; ++i) {
      string tmp; cin >> tmp;
      if (tmp == "BOGO") {
        if (bogod) {
          --i;
          --M;
          continue;
        }
        C[i] = BOGO;
        bogod = true;
      }
      else if (tmp == "$5")
        C[i] = FLAT5;
      else if (tmp == "$10")
        C[i] = FLAT10;
      else if (tmp == "$50")
        C[i] = FLAT50;
      else if (tmp == "10%")
        C[i] = PERCENT10;
      else if (tmp == "20%")
        C[i] = PERCENT20;
      else if (tmp == "TAX")
        C[i] = TAX;
    }
    double ans = INF;
    sort(I, I+N, greater<double>());
    sort(C, C+M);
    do {
      ans = min(ans, cost());
    } while (next_permutation(C, C+M));
    cout << "The best price is $" << fixed << setprecision(2) << ans << '\n';
  }
  return 0;
}
