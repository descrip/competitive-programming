#include <bits/stdc++.h>
using namespace std;

int M, N, A[11][101], dp[11][101];
vector<int> prev;

int zmod(int a, int b) {
    return ((a%b)+b)%b;
}

string dig(int x, int y) {
    //cout << x << ' ' << y << '\n';
    if (x == N-1)
        return to_string(y+1);
    string s = to_string(y+1) + " ";
    int m = min(dp[y][x+1], min(dp[zmod(y-1, M)][x+1], dp[zmod(y+1, M)][x+1])),
        n = 0xffff;
    for (int i = y-1; i <= y+1; ++i) {
        int ii = zmod(i, M);
        if (dp[ii][x+1] == m)
            n = min(n, ii);
    }
    return s + dig(x+1, n);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    while (cin >> M >> N) {
        for (int y = 0; y < M; ++y)
            for (int x = 0; x < N; ++x)
                cin >> A[y][x];
        for (int y = 0; y < M; ++y)
            dp[y][N-1] = A[y][N-1];
        for (int x = N-2; x >= 0; --x)
            for (int y = 0; y < M; ++y)
                dp[y][x] = min(min(dp[y][x+1], dp[zmod(y-1, M)][x+1]), dp[zmod(y+1, M)][x+1]) + A[y][x];
        int ans = 0xfffffff;
        string path = "~";
        for (int y = 0; y < M; ++y)
            ans = min(ans, dp[y][0]);
        for (int y = 0; y < M; ++y)
            if (dp[y][0] == ans) {
                path = min(path, dig(0, y));
                break;
            }
        cout << path << '\n' << ans << '\n';
    }
	return 0;
}

