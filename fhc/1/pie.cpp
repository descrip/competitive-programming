#include <bits/stdc++.h>
using namespace std;

int T, N, M, D[305];
long long C[305][305], ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        fill_n(C[0], 305*305, 0LL);
        cin >> N >> M;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= M; ++j)
                cin >> C[i][j];
            sort(C[i]+1, C[i]+M+1);
            for (int j = 2; j <= M; ++j)
                C[i][j] += C[i][j-1];
            for (int j = 1; j <= M; ++j)
                C[i][j] += j*j;
        }
        /*
        cout << "C[0]: ";
        for (int i = 1; i <= M; ++i)
            cout << C[0][i] << " \n"[i==M];
            */
        ans = 0LL;
        fill_n(D, 305, 0);
        //cout << C[1][D[1]+1] - C[1][D[1]] << '\n';
        for (int i = 0; i < N; ++i) {
            int best = -1;
            for (int j = 0; j < N; ++j) {
                if (D[j] == M)
                    continue;
                else if (best == -1)
                    best = j;
                else if (C[j][D[j]+1] - C[j][D[j]] < C[best][D[best]+1] - C[best][D[best]])
                    best = j;
                //cout << "iter: " << j << ' ' << C[j][D[j]+1] - C[j][D[j]] << ' ' << C[best][D[best]+1] - C[best][D[best]] << '\n';
            }
            ans += C[best][D[best]+1] - C[best][D[best]];
            D[best]++;
            //cout << i << ' ' << best << ' ' << C[D[best]+1] - C[D[best]] << ' ' << ans << '\n';
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}

