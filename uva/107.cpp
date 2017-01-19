#include <bits/stdc++.h>
using namespace std;

long long H, W, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> H >> W) {
        if (H == 0 && W == 0) break;
        else if (H == 1 && W == 1) {
            cout << "0 1\n";
            continue;
        }
        for (long long z = 1; (1LL<<z) <= H; ++z) {
            N = round(pow((double)W, 1.0/z));
            if (pow(N, z) != W)
                continue;
            if (pow(N+1, z) == H) {
                long long h = H, c = 1, nwc = 0, nwh = 0;
                while (h > 1) {
                    //cout << h << ' ' << c << '\n';
                    nwc += c;
                    nwh += h * c;
                    h /= N+1;
                    c *= N;
                }
                cout << nwc << ' ' << nwh+W << '\n';
                break;
            }
        }
    }
	return 0;
}

