#include <bits/stdc++.h>
using namespace std;

// it looks like there may be more than 2100 lines of input...

double p, q, r, s, t, u;

inline double eval(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> p >> q >> r >> s >> t >> u) {
        double lo = 0, hi = 1, mid, zlo, zhi, zmid;
        for (int i = 0; i < 100; ++i) {
            mid = (lo+hi)/2;
            zlo = eval(lo); zhi = eval(hi); zmid = eval(mid);
            if (abs(zmid) <= 1e-8) break;
            else if (zlo <= zhi) {
                if (zmid < 0) lo = mid;
                else hi = mid;
            }
            else if (zlo > zhi) {
                if (zmid < 0) hi = mid;
                else lo = mid;
            }
        }
        //cout << mid << ' ' << eval(mid) << '\n';
        mid = (lo+hi)/2;
        if (abs(eval(mid)) <= 1e-8)
            cout << fixed << setprecision(4) << mid << '\n';
        else cout << "No solution\n";
    }
	return 0;
}

