#include <bits/stdc++.h>
using namespace std;

double a, b, c, s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> a >> b >> c) {
        if (a == 0 && b == 0 && c == 0)
            cout << "The radius of the round table is: 0.000\n";
        else {
            s = (a+b+c)/2;
            cout << "The radius of the round table is: " << fixed << setprecision(3) << sqrt((s-a)*(s-b)*(s-c)) / sqrt(s) << '\n';
        }
    }
	return 0;
}

