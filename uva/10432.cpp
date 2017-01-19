#include <bits/stdc++.h>
using namespace std;

// const long double PI = 3.14159;
long double R, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> R >> N) {
        long double deg = M_PI / N;
        cout << fixed << setprecision(3) << N*R*R*cos(deg)*sin(deg) << '\n';
    }
	return 0;
}

