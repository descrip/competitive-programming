#include <bits/stdc++.h>
using namespace std;

// loowater = waterloo
// rellau creek = laurel creek
// mir park = rim park

int N, M, D[20005], K[20005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;
        for (int i = 0; i < N; ++i)
            cin >> D[i];
        for (int i = 0; i < M; ++i)
            cin >> K[i];
        sort(D, D+N);
        sort(K, K+M);
        int pos = 0;
        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            while (pos < M && K[pos] < D[i])
                ++pos;
            if (pos == M) {
                cout << "Loowater is doomed!\n";
                break;
            }
            ans += K[pos];
            if (i == N-1) {
                cout << ans << '\n';
                break;
            }
            ++pos;
        }
    }
	return 0;
}

