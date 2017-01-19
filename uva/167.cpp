#include <bits/stdc++.h>
using namespace std;

int K, A[8][8];
bool vis[8][8];

bool isOk(int ax, int ay) {
    for (int y = 0; y < 8; ++y)
        if (vis[y][ax])
            return false;
    for (int x = 0; x < 8; ++x)
        if (vis[ay][x])
            return false;
    for (int c = -7; c <= 7; ++c)
        if (0 <= ax+c && ax+c < 8 && 0 <= ay+c && ay+c < 8 && vis[ay+c][ax+c])
            return false;
    for (int c = -7; c <= 7; ++c)
        if (0 <= ax-c && ax-c < 8 && 0 <= ay+c && ay+c < 8 && vis[ay+c][ax-c])
            return false;
    return true;
}

int recur(int x) {
    if (x == 8)
        return 0;
    int ret = 0;
    for (int y = 0; y < 8; ++y)
        if (isOk(x, y)) {
            vis[y][x] = true;
            ret = max(ret, A[y][x] + recur(x+1));
            vis[y][x] = false;
        }
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> K;
    for (int k = 0; k < K; ++k) {
        for (int y = 0; y < 8; ++y)
            for (int x = 0; x < 8; ++x)
                cin >> A[y][x];
        cout.width(5);
        cout << right << recur(0) << '\n';
    }
	return 0;
}

