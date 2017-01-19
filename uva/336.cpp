#include <bits/stdc++.h>
using namespace std;

int N, cnt, cas = 1;
bool A[31][31], vis[31];
map<int, int> M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (scanf(" %d", &N)) {
        if (N == 0) break;
        fill_n(A[0], 31*31, false);
        M.clear();
        cnt = 0;
        for (int i = 0; i < N; ++i) {
            int a, b; scanf("%d %d", &a, &b);
            if (M.count(a) == 0)
                M[a] = cnt++;
            if (M.count(b) == 0)
                M[b] = cnt++;
            A[M[a]][M[b]] = A[M[b]][M[a]] = true;
        }
        int X, T;
        while (scanf("%d %d", &X, &T)) {
            if (X == 0 && T == 0) break;
            fill_n(vis, 31, false);
            queue<pair<int, int>> Q;
            Q.push({M[X], T});
            while (!Q.empty()) {
                int u = Q.front().first, t = Q.front().second;
                Q.pop();
                vis[u] = true;
                if (t == 0)
                    continue;
                for (int v = 0; v < cnt; ++v)
                    if (!vis[v] && A[u][v])
                        Q.push({v, t-1});
            }
            int ans = 0;
            for (int i = 0; i < cnt; ++i)
                ans += !vis[i];
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cas++, ans, X, T);
        }
    }
	return 0;
}

