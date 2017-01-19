#include <bits/stdc++.h>
using namespace std;

bool vis[5][5], A[5][5] = {
    {0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 1, 1, 0}
};

void recur(int u, string sf) {
    if (sf.size() == 9) {
        cout << sf << '\n';
        return;
    }
    for (int v = 0; v < 5; ++v)
        if (A[u][v] && !vis[u][v]) {
            vis[u][v] = vis[v][u] = true;
            recur(v, sf + to_string(v+1));
            vis[u][v] = vis[v][u] = false;
        }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    recur(0, "1");
	return 0;
}

