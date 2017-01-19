#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, y, c, z;
    node(int a, int b, int r, int d) : x(a), y(b), c(r), z(d) {}
};

struct nodeSort{
    bool operator() (const node &a, const node &b) const {
        return a.z > b.z;
    }
};

int N, M, maze[105][105], code[105][105], X, Y, C;
bool vis[105][105][2048];

int main() {
    cin >> N >> M;
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x) {
            cin >> maze[y][x];
            if (maze[y][x] == 2)
                code[y][x] = C++;
        }
    cin >> Y >> X;

    /*
    if (maze[Y][X] == 1 || maze[0][0] == 1) {
        cout << "-1\n";
        return 0;
    }
    */

    priority_queue<node, vector<node>, nodeSort> pq;
    pq.push(node(0,0,0,0));

    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();

        //cout << curr.x << ' ' << curr.y << ' ' << curr.c << ' ' << curr.z << '\n';

        if (curr.c == (1<<C)-1 && curr.x == X && curr.y == Y) {
            cout << curr.z << '\n';
            return 0;
        }

        if (vis[curr.x][curr.y][curr.c])
            continue;
        vis[curr.x][curr.y][curr.c] = true;

        for (int cy = curr.y-1; cy <= curr.y+1; cy+=2)
            if (0 <= cy && cy < N) {
                auto temp = node(curr.x, cy, curr.c, curr.z+1);
                if (maze[cy][curr.x] == 1)
                    continue;
                if (maze[cy][curr.x] == 2)
                    temp.c |= (1<<code[cy][curr.x]);
                if (!vis[temp.x][temp.y][temp.c])
                    pq.push(temp);
            }

        for (int cx = curr.x-1; cx <= curr.x+1; cx+=2)
            if (0 <= cx && cx < M) {
                auto temp = node(cx, curr.y, curr.c, curr.z+1);
                if (maze[curr.y][cx] == 1)
                    continue;
                if (maze[curr.y][cx] == 2)
                    temp.c |= (1<<code[curr.y][cx]);
                if (!vis[temp.x][temp.y][temp.c])
                    pq.push(temp);
            }
    }

    cout << "-1\n";
    return 0;
}
