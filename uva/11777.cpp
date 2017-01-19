#include <bits/stdc++.h>
using namespace std;

// im dumb

int T, sum, C[3];
pair<int, char> P[5] = {{-1, 'F'}, {60, 'D'}, {70, 'C'}, {80, 'B'}, {90, 'A'}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        sum = 0;
        for (int i = 0; i < 4; ++i) {
            int x; cin >> x;
            sum += x;
        }
        for (int i = 0; i < 3; ++i)
            cin >> C[i];
        sort(C, C+3);
        sum += (C[1]+C[2])/2;
        auto it = upper_bound(P, P+5, make_pair(sum, '~'));
        --it;
        cout << "Case " << t << ": "  << it->second << '\n';
        //cout << sum << '\n';
    }
    return 0;
}

