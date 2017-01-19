#include <bits/stdc++.h>
using namespace std;

int T, N, ans;
long long tot, C;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> N;
        ans = tot = 0;
        for (int i = 0; i < N; ++i) {
            cin >> C;
            if (tot < C) {
                ++ans;
                tot += C;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

