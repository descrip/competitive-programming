#include <bits/stdc++.h>
using namespace std;

// it looks like there may be more than 2100 lines of input...

double p, q, r, s, t, u;

double f(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double df(double x) {
    return -p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> p >> q >> r >> s >> t >> u) {
        // the key to the problem is to realise that the function is increasing
        if (f(0.0) * f(1.0) > 0) {
            cout << "No solution\n";
            continue;
        }
        double x0 = 0.5;
        while (true) {
            if (fabs(df(x0)) < 1e-5)
                break;
            double x = x0 - f(x0) / df(x0);
            if (fabs(x0-x) < 1e-5) {
                x0 = x; break;
            }
            x0 = x;
        }
        if (f(0) == 0) cout << "0.0000\n";
        else cout << fixed << setprecision(4) << x0 << '\n';
    }
	return 0;
}


