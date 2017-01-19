#include <bits/stdc++.h>
using namespace std;

int T, N, W[101];
deque<int> D;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        int ans = 0;
        for (int i = 0; i < N; ++i)
            cin >> W[i];
        D.clear();
        sort(W, W+N);
        for (int i = 0; i < N; ++i)
            D.push_back(W[i]);
        while (!D.empty()) {
            int x = D.back(), y = ceil(50.0/x) - 1;
            D.pop_back();
            bool ok = true;
            for (int i = 0; i < y; ++i) {
                if (D.empty()) {
                    ok = false;
                    break;
                }
                D.pop_front();
            }
            if (ok) ++ans;
            else break;
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}

