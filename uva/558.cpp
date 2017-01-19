#include <bits/stdc++.h>
using namespace std;

int T, N, M, D[2005], A[2005], B[2005], C[2005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> M;
        for (int i = 0; i < M; ++i)
            cin >> A[i] >> B[i] >> C[i];
        fill_n(D, 2005, 0xfffffff);
        D[0] = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                D[B[j]] = min(D[B[j]], D[A[j]] + C[j]);
        bool yes = false;
        for (int i = 0; i < M; ++i)
            if (D[A[i]] + C[i] < D[B[i]])
                yes = true;
        cout << (yes ? "possible" : "not possible") << '\n';
    }
    return 0;
}

