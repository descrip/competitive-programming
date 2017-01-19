#include <bits/stdc++.h>
using namespace std;

int N, M, p = 0, e = 0, u = 0;
set<string> P, E;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        P.insert(s);
        ++p;
    }
    for (int i = 0; i < M; ++i) {
        string s; cin >> s;
        if (P.count(s) == 1) {
            P.erase(s);
            ++u;
            --p;
        }
        else {
            E.insert(s);
            ++e;
        }
    }
    if (p > e) cout << "YES\n";
    else if (e > p) cout << "NO\n";
    else if (p == e) cout << (u % 2 == 0 ? "NO\n" : "YES\n");
    return 0;
}

