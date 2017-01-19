// i need to slow the fuck down
#include <bits/stdc++.h>
using namespace std;

long long N, M, K, X, S, S1X[200005], S1C[200005], S2X[200005], S2C[200005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> N >> M >> K >> X >> S;
    for (int i = 1; i <= M; ++i)
        cin >> S1X[i];
    for (int i = 1; i <= M; ++i)
        cin >> S1C[i];
    for (int i = 1; i <= K; ++i)
        cin >> S2X[i];
    for (int i = 1; i <= K; ++i)
        cin >> S2C[i];
    S1X[0] = X;
    S2C[K+1] = (1LL << 62);
    long long ans = (1LL << 62);
    for (int i = 0; i <= M; ++i) {
        if (S1C[i] > S)
            continue;
        int ind = (upper_bound(S2C, S2C+K+1, S-S1C[i]) - S2C) - 1;
        //cout << i << ' ' << ind << '\n';
        long long tot = S1X[i] * (N - S2X[ind]);
        ans = min(ans, tot);
    }
    cout << ans << '\n';
	return 0;
}

