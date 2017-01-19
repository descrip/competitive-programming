#include <bits/stdc++.h>
using namespace std;

int N, T = 1;
bool vis[17], p[32];
vector<int> A;

void recur(int u) {
    if (A.size() == N) {
        if (p[u+1])
            for (int i = 0; i < A.size(); ++i)
                cout << A[i] << " \n"[i == A.size()-1];
        return;
    }
    for (int v = 2; v <= N; ++v)
        if (!vis[v] && p[u+v]) {
            vis[v] = true;
            A.push_back(v);
            recur(v);
            vis[v] = false;
            A.pop_back();
        }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    fill_n(p, 32, true);
    p[0] = p[1] = false;
    for (int i = 2; i*i < 32; ++i)
        if (p[i])
            for (int j = 2; i*j < 32; ++j)
                p[i*j] = false;
    while (cin >> N) {
        if (T != 1)
            cout << '\n';
        cout << "Case " << T++ << ":\n";
        A = {1};
        vis[1] = true;
        recur(1);
    }
	return 0;
}

