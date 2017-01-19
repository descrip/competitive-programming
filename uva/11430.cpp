#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8;
int N;
long long ncr[1001][1001], ans;

long long zmod(long long x) {
    return ((x % MOD) + MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ncr[0][0] = 1;
    for (int i = 0; i <= 1000; ++i) {
        ncr[i][0] = ncr[i][i] = 1;
        for (int j = 1; j < i; ++j)
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % MOD;
    }
    while (cin >> N) {
        if (N == 0) break;
        ans = 0LL;
        for (int i = 1; i <= N; ++i)
            for (int j = i; j <= N; ++j)
                if ((i*j) % N == 0) {
                    int x = i*j/N;
                    //cout << i << ' ' << j << ' ' << (i != j ? 2 : 1) * zmod(ncr[N][x] * ncr[N-x][i-x]) * ncr[N-x][j-i] << '\n';
                    ans = zmod(ans + (i != j ? 2 : 1) * zmod(ncr[N][x] * ncr[N-x][i-x]) * ncr[N-i][j-x]);
                }
        cout << ans << '\n';
    }
	return 0;
}

