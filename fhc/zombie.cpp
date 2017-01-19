#include <bits/stdc++.h>
using namespace std;

int T, H, S, dice[] = {4, 6, 8, 10, 12, 20};
double A[21][21][21*21];

int main() {
    cin >> T;
    for (int d : dice) {
        A[d][0][0] = 1.0;
        for (int x = 1; x <= 20; ++x)
            for (int i = 0; i <= 400; ++i)
                for (int j = i+1; j <= i+d && j <= 400; ++j)
                    A[d][x][j] += A[d][x-1][i] / d;
        for (int x = 1; x <= 20; ++x)
            for (int i = 21*21-2; i >= 0; --i)
                A[d][x][i] += A[d][x][i+1];
    }
    //cout << A[4][2][2] << '\n';
    for (int t = 1; t <= T; ++t) {
        cin >> H >> S;
        double ans = 0.0;
        for (int i = 0; i < S; ++i) {
            char c; int x, y, z = 0;
            cin >> x >> c >> y;
            assert(c == 'd');
            c = cin.peek();
            if (!isspace(c)) cin >> z;
            if (H-z > 400) continue;
            else if (H-z <= 0) ans = 1.0;
            else ans = max(ans, A[y][x][H-z]);
        }
        cout << "Case #" << t << ": " << fixed << setprecision(7) << ans << '\n';
    }
    return 0;
}

