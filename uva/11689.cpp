#include <bits/stdc++.h>
using namespace std;

int N, E, F, C;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int t = 0; t < N; ++t) {
        cin >> E >> F >> C;
        E += F;
        int ans = 0;
        while (E >= C) {
            ans += E/C;
            E = E/C + E%C;
        }
        cout << ans << '\n';
    }
    return 0;
}

