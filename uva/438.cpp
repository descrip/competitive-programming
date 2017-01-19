#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
const double PI = 3.141592653589793;
pair<double, double> poi[3];
double x[3], y[3];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  /*
  while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
    double xm1 = (x1+x2)/2, ym1 = (y1+y2)/2,
           xm2 = (x2+x3)/2, ym2 = (y2+y3)/2,
           m1 = (y2-y1)/(x2-x1), m2 = (y3-y2)/(x3-x2),
           a1 = 1, b1 = m1, a2 = 1, b2 = m2,
           c1 = a1*xm1 + b1*ym1, c2 = a2*xm2 + b2*ym2,
           xr = (c1*b2 - c2*b1)/(a1*b2 - a2*b1),
           yr = (c1 - a1*xr)/b1,
           r = sqrt((x1-xr)*(x1-xr) + (y1-yr)*(y1-yr));
  }
  */
  while (cin >> poi[0].fi >> poi[0].se) {
    for (int i = 1; i <= 2; ++i)
      cin >> poi[i].fi >> poi[i].se;
    sort(poi, poi+3);
    do {
      for (int i = 0; i < 3; ++i) {
        //cout << poi[i].fi << ' ' << poi[i].se << ' ';
        x[i] = poi[i].fi;
        y[i] = poi[i].se;
      }
      //cout << '\n';
      double xm0 = (x[0]+x[1])/2, ym0 = (y[0]+y[1])/2,
             xm1 = (x[2]+x[1])/2, ym1 = (y[2]+y[1])/2,
             m0 = (y[1]-y[0])/(x[1]-x[0]), m1 = (y[2]-y[1])/(x[2]-x[1]),
             a0 = 1, b0 = m0, a1 = 1, b1 = m1,
             c0 = a0*xm0 + b0*ym0, c1 = a1*xm1 + b1*ym1,
             xr = (c0*b1 - c1*b0)/(a0*b1 - a1*b0),
             yr = (c0 - a0*xr)/b0,
             r = sqrt((x[0]-xr)*(x[0]-xr) + (y[0]-yr)*(y[0]-yr)),
             ci = 2*PI*r;
      //cout << m0 << ' ' << m1 << ' ' << xr << ' ' << yr << '\n';
      if (ci == ci) {     //not nan
        cout << fixed << setprecision(2) << round(100*ci)/100.0 << '\n';
        break;
      }
    } while (next_permutation(poi, poi+3));
  }
return 0;}

