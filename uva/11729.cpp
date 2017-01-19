#include <bits/stdc++.h>
using namespace std;

int N, T = 1;
pair<int, int> A[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N) {
        if (N == 0) break;
        for (int i = 0; i < N; ++i) {
            int b, j; cin >> b >> j;
            A[i] = {j, b};
        }
        sort(A, A+N, greater<pair<int, int>>());
        int sum = 0, ans = 0;
        for (int i = 0; i < N; ++i) {
            sum += A[i].second;
            ans = max(ans, sum + A[i].first);
        }
        cout << "Case " << T++ << ": " << ans << '\n';
    }
    return 0;
}

