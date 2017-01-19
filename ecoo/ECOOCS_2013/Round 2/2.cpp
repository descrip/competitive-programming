#include <bits/stdc++.h>
using namespace std;

#define NUM_TESTS 5

double dist(double x1, double y1, double x2, double y2) {
  double a = x1-x2, b = y1-y2;
  return sqrt(a*a + b*b);
}

double zmod(double a, double m) {
  return fmod(fmod(a, m) + m, m);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int t = 0; t < NUM_TESTS; ++t) {
    double Bx, By, R;
    int T, N, ans = 0;
    cin >> Bx >> By >> R >> T >> N;
    for (int n = 0; n < N; ++n) {
      double X, Y, Cy, Cx, S;
      S *= -1;
      cin >> X >> Y >> Cx >> Cy >> S;

      double r = dist(X, Y, Cx, Cy),
             theta = asin((Y - Cy) / r);
      if (fabs(Cx + r*cos(theta) - X) > 1e-9)
        theta = zmod(M_PI-theta, 2*M_PI);

      /*
      if (fabs(Cx + r*cos(theta) - X) > 1e-9)
        cout << X << ' ' << Cx+r*cos(theta) << ' ' <<
                Y << ' ' << Cy+r*sin(theta) << '\n';
      if (fabs(Cy + r*sin(theta) - Y) > 1e-9)
        cout << X << ' ' << Cx+r*cos(theta) << ' ' <<
                Y << ' ' << Cy+r*sin(theta) << '\n';
      */

      double phi = zmod(theta + S*T/r, 2*M_PI),
             Zx = Cx + r*cos(phi), Zy = Cy + r*sin(phi);
      //cout << Zx << ' ' << Zy << ' ';
      Zx = round(Zx*100)/100.0;
      Zy = round(Zy*100)/100.0;
      //cout << Zx << ' ' << Zy << '\n';
      //cout << dist(Zx, Zy, Cx, Cy) << ' ' << r << '\n';
      if (dist(Zx, Zy, Cx, Cy) <= R)
        ++ans;
    }
    cout << ans << '\n';
  }
return 0;}

