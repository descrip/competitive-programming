#include <bits/stdc++.h>
using namespace std;

int n, p[10001], ran[10001], par[10001], cnt;

int findSet(int i) {
    return (par[i] == i) ? i : (par[i] = findSet(par[i]));
}

bool isSameSet(int i, int j) {
    return (findSet(i) == findSet(j));
}

void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
        --cnt;
        int x = findSet(i), y = findSet(j);
        if (ran[x] > ran[y])
            par[y] = x;
        else {
            par[x] = y;
            if (ran[x] == ran[y])
                ++ran[y];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cnt = n;
    for (int i = 1; i <= n; ++i)
        par[i] = i;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        unionSet(i+1, p[i]);
        /*
        for (int i = 1; i <= n; ++i)
            cout << par[i] << " \n"[i == n];
            */
    }
    cout << cnt << '\n';
    return 0;
}

