#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, y, z, t;
    node(int a, int b, int c, int d) : x(a), y(b), z(c), t(d) {}
};

int L, R, C, Sx, Sy, Sz, Ex, Ey, Ez;
bool A[31][31][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> L >> R >> C) {
        if (L == 0 && R == 0 && C == 0) break;
        fill_n(A[0][0], 31*31*31, false);
        for (int z = 0; z < L; ++z)
            for (int y = 0; y < R; ++y)
                for (int x = 0; x < C; ++x) {
                    char c; cin >> c;
                    if (c == '#') A[z][y][x] = true;
                    else if (c == 'S') {
                        Sx = x; Sy = y; Sz = z;
                    }
                    else if (c == 'E') {
                        Ex = x; Ey = y; Ez = z;
                    }
                }
        queue<node> q;
        q.push(node(Sx, Sy, Sz, 0));
        int ans = -1;
        while (!q.empty()) {
            int x = q.front().x, y = q.front().y, z = q.front().z, t = q.front().t;
            q.pop();
            if (x == Ex && y == Ey && z == Ez) {
                ans = t;
                break;
            }
            for (int cz = z-1; cz <= z+1; cz+=2)
                if (0 <= cz && cz < L && !A[cz][y][x]) {
                    A[cz][y][x] = true;
                    q.push(node(x, y, cz, t+1));
                }
            for (int cy = y-1; cy <= y+1; cy+=2)
                if (0 <= cy && cy < R && !A[z][cy][x]) {
                    A[z][cy][x] = true;
                    q.push(node(x, cy, z, t+1));
                }
            for (int cx = x-1; cx <= x+1; cx+=2)
                if (0 <= cx && cx < C && !A[z][y][cx]) {
                    A[z][y][cx] = true;
                    q.push(node(cx, y, z, t+1));
                }
        }
        if (ans == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s).\n";
    }
    return 0;
}

