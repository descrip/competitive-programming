#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll ncrmax = 200;
ll k, t, ncr[ncrmax][ncrmax], l, fact[11], ofl[11];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    ncr[0][0] = 1;
    for (int i = 1; i < ncrmax; ++i) {
        ncr[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
    }
    fact[0] = 1;
    for (int i = 1; i <= 10; ++i)
        fact[i] = i * fact[i-1];
    cin >> k >> t;
    ofl[1] = 15;
    for (l = 2; l <= 10; ++l)
        ofl[l] = ncr[16*t][l] * fact[l];
    for (l = 2; l <= 10; ++l)
        ofl[l] -= ofl[l-1];
    for (l = 1; l <= 10; ++l)
        if (ofl[l] > k) break;
        else k -= ofl[l];
    cout << k << ' ' << l << '\n';
	return 0;
}

